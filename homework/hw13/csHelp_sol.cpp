#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


const int GARDENSIZE = 20;
const int INITIALANTS = 100;
const int INITALBUGS = 5;
const int DOODLEBUG = 1;
const int ANT = 2;
const int ANTBREED = 3;
const int DOODLEBREED = 8;
const int DOODLESTARVE = 3;
const char ANTCHAR = 'O';
const char BUGCHAR = 'X';

class Organism;
class Doodlebug;
class Ant;

class Garden{
public:
    Garden();
    ~Garden();

    Organism* getAt(int x, int y);
    void setAt(int x, int y, Organism *org);
    void Display();
    void SimulateOneStep();

    friend class Organism;
    friend class Doodlebug;
    friend class Ant;

private:
    Organism* grid[GARDENSIZE][GARDENSIZE]{};
};

class Organism{
public:
    Organism();
    Organism(Garden *grden, int x, int y);
    virtual ~Organism();

    virtual void breed() = 0;
    virtual void move() = 0;
    virtual int getType() = 0;
    virtual bool starve() = 0;

    friend class Garden;
protected:
    int x, y;
    bool moved;
    int breedTicks{};
    Garden *garden;
};

Garden::Garden(){
    int i, j;
    for (i=0; i < GARDENSIZE; i++){
        for (j=0; j < GARDENSIZE; j++){
            grid[i][j] = nullptr;
        }
    }
}

Garden::~Garden(){
    int i, j;
    for (i = 0; i < GARDENSIZE; i++){
        for(j = 0; j < GARDENSIZE; j++){
            if(grid[i][j] != nullptr)
                delete (grid[i][j]);
        }
    }
}

Organism* Garden::getAt(int x, int y){
    if((x >= 0) && (x < GARDENSIZE) && (y >= 0) && (y < GARDENSIZE)){
        return grid[x][y];
    }
    return nullptr;
}

void Garden::setAt(int x, int y, Organism *org){
    if((x >= 0) && (x < GARDENSIZE) && (y >= 0) && (y < GARDENSIZE)){
        grid[x][y] = org;
    }
}

void Garden::Display(){
    cout << endl << endl;
    for(int j=0; j < GARDENSIZE; j++){
        for(int i=0; i < GARDENSIZE; i++){
            if(grid[i][j] == nullptr){
                cout << "- ";
            }else if(grid[i][j]->getType() == ANT){
                cout << ANTCHAR <<" ";
            }else{
                cout << BUGCHAR <<" ";
            }
        }
        cout << endl;
    }
}

void Garden::SimulateOneStep(){
    for (int i=0; i<GARDENSIZE; i++){
        for(int j=0; j<GARDENSIZE; j++){
            if (grid[i][j] != nullptr){
                grid[i][j]->moved = false;
            }
        }
    }

    for(int i=0; i<GARDENSIZE; i++){
        for(int j=0; j<GARDENSIZE; j++){
            if((grid[i][j] != nullptr) && (grid[i][j]->getType() == DOODLEBUG)){
                if (grid[i][j]->moved == false){
                    grid[i][j]->moved = true;
                    grid[i][j]->move();
                }
            }
        }
    }

    for(int i=0; i<GARDENSIZE; i++){
        for(int j=0; j<GARDENSIZE; j++){
            if((grid[i][j] != nullptr) && (grid[i][j]->getType() == ANT)){
                if (grid[i][j]->moved == false){
                    grid[i][j]->moved = true;
                    grid[i][j]->move();
                }
            }
        }
    }

    for(int i=0; i<GARDENSIZE; i++){
        for(int j=0; j<GARDENSIZE; j++){
            if((grid[i][j] != nullptr) && (grid[i][j]->moved == true)){
                grid[i][j]->breed();
            }
        }
    }

    for(int i=0; i<GARDENSIZE; i++){
        for(int j=0; j<GARDENSIZE; j++){
            if((grid[i][j] != nullptr) && (grid[i][j]->getType() == DOODLEBUG)){
                if (grid[i][j]->starve()){
                    delete (grid[i][j]);
                    grid[i][j] = nullptr;
                }
            }
        }
    }


}

Organism::Organism(){
    garden = nullptr;
    moved = false;
    breedTicks = 0;
    x = 0;
    y = 0;
}

Organism::Organism(Garden *grden, int x, int y){
    this->garden = grden;
    moved = false;
    this->x = x;
    this->y = y;
    grden->setAt(x, y, this);
}

Organism::~Organism()= default;

//Ant class
class Ant: public Organism{

public:
    Ant();
    Ant(Garden *garden, int x, int y);

    virtual void breed();
    virtual void move();
    virtual int getType();
    virtual bool starve(){ return false; }

    friend class Garden;
};

Ant::Ant() : Organism() {}
Ant::Ant(Garden *garden, int x, int y): Organism(garden, x, y) {}
void Ant::move(){
    int direction = rand() % 4;

    if(direction == 0){
        if((y > 0) && (garden->getAt(x, y-1) == nullptr)){
            garden->setAt(x, y-1, garden->getAt(x, y));
            garden->setAt(x, y, nullptr);
            y--;
        }
    }else if (direction == 1){
        if((y < GARDENSIZE - 1) && (garden->getAt(x, y+1) == nullptr)){
            garden->setAt(x, y, garden->getAt(x, y));
            garden->setAt(x, y, nullptr);
            y++;
        }
    }else if(direction == 2){
        if ((x > 0) && (garden->getAt(x-1, y) == nullptr)){
            garden->setAt(x-1, y, garden->getAt(x, y));
            garden->setAt(x, y, nullptr);
            x--;
        }
    }else{
        if((x < GARDENSIZE-1) && (garden->getAt(x+1, y) == nullptr)){
            garden->setAt(x+1, y, garden->getAt(x, y));
            garden->setAt(x, y, nullptr);
            x++;
        }
    }
}

int Ant::getType() {return ANT; }
void Ant::breed(){
    breedTicks++;
    if(breedTicks == ANTBREED){
        breedTicks = 0;
        if((y>0) && (garden->getAt(x, y-1) == nullptr)){
            new Ant(garden, x, y-1);
        }else if ((y<GARDENSIZE-1) && (garden->getAt(x, y+1) == nullptr)){
            new Ant(garden, x, y+1);
        }else if((x>0) && (garden->getAt(x-1, y) == nullptr)){
            new Ant(garden, x-1, y);
        }else if((x<GARDENSIZE-1) && (garden->getAt(x+1, y) == nullptr)){
            new Ant(garden, x+1, y);
        }
    }
}

//Doodlebug class
class Doodlebug : public Organism{
public:
    Doodlebug();
    Doodlebug(Garden *garden, int x, int y);
    virtual void breed();
    virtual void move();
    virtual int getType();
    virtual bool starve();

    friend class Garden;
private:
    int starveTicks;
};

Doodlebug::Doodlebug(): Organism() { starveTicks = 0; }
Doodlebug::Doodlebug(Garden *garden, int x, int y): Organism(garden, x, y) { starveTicks = 0; }

void Doodlebug::move(){
    if((y>0) && (garden->getAt(x, y-1) != nullptr) && (garden->getAt(x, y-1)->getType() == ANT)){
        delete (garden->grid[x][y-1]);
        garden->grid[x][y-1] = this;
        garden->setAt(x, y, nullptr);
        starveTicks = 0;
        y--;
        return;
    }else if((y<GARDENSIZE-1) && (garden->getAt(x, y+1) != nullptr) && (garden->getAt(x, y+1)->getType() == ANT)){
        delete (garden->grid[x][y+1]);
        garden->grid[x][y+1] = this;
        garden->setAt(x, y, nullptr);
        starveTicks = 0;
        y++;
        return;
    }else if((x>0) && (garden->getAt(x-1, y) != nullptr) && (garden->getAt(x-1, y)->getType() == ANT)){
        delete (garden->grid[x-1][y]);
        garden->grid[x-1][y] = this;
        garden->setAt(x, y, nullptr);
        starveTicks = 0;
        x--;
        return;
    }else if((x<GARDENSIZE-1) && (garden->getAt(x+1, y) != nullptr) && (garden->getAt(x+1, y)->getType() == ANT )){
        delete (garden->grid[x+1][y]);
        garden->grid[x+1][y] = this;
        garden->setAt(x, y, nullptr);
        starveTicks = 0;
        x++;
        return;
    }

    int direction = rand() % 4;

    if(direction == 0){
        if((y>0) && (garden->getAt(x, y-1) == nullptr)){
            garden->setAt(x, y-1, garden->getAt(x, y));
            garden->setAt(x, y, nullptr);
            y--;
        }
    }else if(direction == 1){
        if((y<GARDENSIZE-1) && (garden->getAt(x, y+1) == nullptr)){
            garden->setAt(x, y+1, garden->getAt(x, y));
            garden->setAt(x, y, nullptr);
            y++;
        }
    }else if(direction == 2){
        if((x>0) && (garden->getAt(x-1, y) == nullptr)){
            garden->setAt(x-1, y, garden->getAt(x, y));
            garden->setAt(x, y, nullptr);
            x--;
        }
    }else{
        if((x<GARDENSIZE-1) && (garden->getAt(x+1, y) == nullptr)){
            garden->setAt(x+1, y, garden->getAt(x, y));
            garden->setAt(x, y, nullptr);
            x++;
        }
    }

    starveTicks++;
}

int Doodlebug::getType() { return DOODLEBUG; }

void Doodlebug::breed(){
    breedTicks++;
    if(breedTicks == DOODLEBREED){
        breedTicks = 0;
        if((y>0) && (garden->getAt(x, y-1) == nullptr)){
            new Doodlebug(garden, x, y-1);
        }else if ((y<GARDENSIZE -1) && (garden->getAt(x, y+1) == nullptr)){
            new Doodlebug(garden,x,y+1);
        }else if((x>0) && (garden->getAt(x-1, y) == nullptr)){
            new Doodlebug(garden,x-1,y);
        }else{
            new Doodlebug(garden, x+1, y);
        }
    }
}

bool Doodlebug::starve(){
    return (starveTicks > DOODLESTARVE);
}

int main() {
    string s;
    srand(time(nullptr));
    Garden g;

    int antCount = 0;
    int doodleCount = 0;

    while(antCount < INITIALANTS){
        int x = rand() % GARDENSIZE;
        int y = rand() % GARDENSIZE;

        if(g.getAt(x, y) == nullptr){
            antCount++;
            Organism *a1 = new Ant(&g, x, y);
        }
    }

    while(doodleCount < INITALBUGS){
        int x = rand() % GARDENSIZE;
        int y = rand() % GARDENSIZE;

        if(g.getAt(x, y) == nullptr){
            doodleCount++;
            Organism *d1 = new Doodlebug(&g, x, y);
        }
    }

    //run program
    while (true){
        g.Display();
        g.SimulateOneStep();
        cout << endl << "Press enter for next step" << endl;
        getline(cin, s);
    }

    return 0;
}
