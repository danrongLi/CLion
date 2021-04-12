//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <vector>
//#include <string>
//using namespace std;
//
//const int SIZE = 20;
//const int SMALL_IDX = 0;
//const int BIG_IDX = SIZE - 1;
//const int INITIAL_ANT = 100;
//const int INITIAL_DOODLE = 5;
//const char ANT_CHAR = 'O';
//const char DOODLE_CHAR = 'X';
//const char EMPTY_CHAR = '-';
//const int ANT_BREED = 3;
//const int DOODLE_BREED = 8;
//const int DOODLE_DIE = 3;
//
//class Organism;
//class Ant;
//class Doodlebug;
//
//class EcoSystem{
//public:
//    friend class Organism;
//    friend class Ant;
//    friend class Doodlebug;
//
//    EcoSystem();
//    ~EcoSystem();
//
//    Organism* getTheOrganism(int xLo, int yLo);
//    void setTheOrganism(int xLo, int yLo, Organism* theOrganism);
//
//    void display();
//    void simulateOneTimeStep();
//
//
//private:
//    Organism* gridBoard[SIZE][SIZE]{};
//};
//
//Organism* EcoSystem::getTheOrganism(int xLo, int yLo) {
//    bool ifValid = false;
//    if (xLo <= BIG_IDX && xLo >= SMALL_IDX && yLo <= BIG_IDX && yLo >= SMALL_IDX){
//        ifValid = true;
//    }
//    if (ifValid){
//        if(gridBoard[xLo][yLo] != nullptr){
//            return gridBoard[xLo][yLo];
//        }
//        else {
//            return nullptr;
//        }
//    }
//}
//void EcoSystem::setTheOrganism(int xLo, int yLo, Organism *theOrganism) {
//    if (xLo >= SMALL_IDX && xLo <= BIG_IDX && yLo >= SMALL_IDX && yLo <= BIG_IDX && gridBoard[xLo][yLo] == nullptr){
//        gridBoard[xLo][yLo] = theOrganism;
//    }
//}
//EcoSystem::EcoSystem() {
//    for (int i = 0; i < SIZE; i += 1){
//        for (int j = 0; j < SIZE; j += 1){
//            gridBoard[i][j] = nullptr;
//        }
//    }
//}
//EcoSystem::~EcoSystem() {
//    for (int i = 0; i < SIZE; i += 1){
//        for (int j = 0; j < SIZE; j += 1){
//            if (gridBoard[i][j] != nullptr){
//                delete gridBoard[i][j];
//                gridBoard[i][j] = nullptr;
//            }
//        }
//    }
//}
//void EcoSystem::display() {
//    for(int i = 0; i < SIZE; i += 1){
//        for (int j = 0; i < SIZE; j += 1){
//            if (gridBoard[i][j] == nullptr){
//                cout<<EMPTY_CHAR<<" ";
//            }
//            else {
//                cout<<gridBoard[i][j]->getType();
//            }
//
//        }
//    }
//}
//void EcoSystem::simulateOneTimeStep() {
//}
//
//class Organism{
//public:
//    friend class EcoSystem;
//
//    Organism();
//    virtual ~Organism()= default;
//
//    Organism(EcoSystem* inputSystem, int xLo, int yLo);
//
//    virtual void move() = 0;
//    virtual void breed() = 0;
//    virtual char getType() = 0;
//    virtual bool starve() = 0;
//
//protected:
//    int x;
//    int y;
//    bool alreadyMoved;
//    int daysSurvived;
//    int daysSinceLastBreed;
//    EcoSystem* mySystem;
//};
//Organism::Organism() {
//    x = 0;
//    y = 0;
//    alreadyMoved = false;
//    daysSurvived = 0;
//    daysSinceLastBreed = 0;
//    mySystem = nullptr;
//}
//Organism::Organism(EcoSystem* inputSystem, int xLo, int yLo) {
//    x = xLo;
//    y = yLo;
//    mySystem = inputSystem;
//    mySystem->setTheOrganism(x, y, this);
//    alreadyMoved = false;
//    daysSurvived = 0;
//    daysSinceLastBreed = 0;
//}
//
//class Ant: public Organism{
//public:
//    friend class EcoSystem;
//    Ant():Organism(){}
//    Ant(EcoSystem* inputSystem, int xLo, int yLo): Organism(inputSystem, xLo, yLo){}
//
//    virtual void move();
//    virtual void breed();
//    virtual char getType() {return ANT_CHAR;}
//    virtual bool starve() {return false;}
//private:
//
//};
//
//void Ant::move() {
//    int choice = rand()%4+1;
//    if (choice == 1 && mySystem->getTheOrganism(x,y+1) == nullptr && (y+1)<=BIG_IDX){
//        mySystem->setTheOrganism(x,y+1,mySystem->getTheOrganism(x,y));
//        mySystem->setTheOrganism(x,y, nullptr);
//        y += 1;
//    }
//    else if (choice == 2 && mySystem->getTheOrganism(x,y-1) == nullptr && (y-1)>=SMALL_IDX){
//        mySystem->setTheOrganism(x,y-1,mySystem->getTheOrganism(x,y));
//        mySystem->setTheOrganism(x,y, nullptr);
//        y -= 1;
//    }
//    else if (choice == 3 && mySystem->getTheOrganism(x-1, y) == nullptr && (x-1) >= SMALL_IDX){
//        mySystem->setTheOrganism(x-1,y,mySystem->getTheOrganism(x,y));
//        mySystem->setTheOrganism(x,y, nullptr);
//        x -= 1;
//    }
//    else if (choice == 4 && mySystem->getTheOrganism(x+1, y) == nullptr && (x+1) <= BIG_IDX){
//        mySystem->setTheOrganism(x+1,y,mySystem->getTheOrganism(x,y));
//        mySystem->setTheOrganism(x,y, nullptr);
//        x += 1;
//    }
//}
//
//void Ant::breed() {
//    daysSinceLastBreed += 1;
//    daysSurvived += 1;
//    if (daysSinceLastBreed == ANT_BREED){
//        daysSinceLastBreed = 0;
//        int choice =  rand()%4 + 1;
//        if (choice == 1 && mySystem->getTheOrganism(x,y+1) == nullptr && (y+1)<=BIG_IDX){
//            new Ant(mySystem, x, y+1);
//        }
//        else if (choice == 2 && mySystem->getTheOrganism(x,y-1) == nullptr && (y-1)>=SMALL_IDX){
//            new Ant(mySystem, x, y-1);
//        }
//        else if (choice == 3 && mySystem->getTheOrganism(x-1, y) == nullptr && (x-1) >= SMALL_IDX){
//            new Ant(mySystem, x-1, y);
//        }
//        else if (choice == 4 && mySystem->getTheOrganism(x+1, y) == nullptr && (x+1) <= BIG_IDX){
//            new Ant(mySystem, x+1, y);
//        }
//    }
//}
//
//class Doodlebug: public Organism{
//public:
//    Doodlebug():Organism(),daysSinceLastAte(0){}
//    Doodlebug(EcoSystem* mySystem, int xLo, int yLo): Organism(mySystem, xLo, yLo),daysSinceLastAte(0){}
//
//    virtual void breed();
//    virtual void move();
//    virtual char getType() {return DOODLE_CHAR;}
//    virtual bool starve() {return daysSinceLastAte >= DOODLE_DIE;}
//
//    friend class EcoSystem;
//
//private:
//    int daysSinceLastAte;
//};
//
//void Doodlebug::move() {
//    if (mySystem->getTheOrganism(x,y+1) != nullptr && (y+1)<=BIG_IDX){
//        if (mySystem->getTheOrganism(x,y+1)->getType() == ANT_CHAR){
//            mySystem->setTheOrganism(x,y+1,mySystem->getTheOrganism(x,y));
//            mySystem->setTheOrganism(x,y, nullptr);
//            y += 1;
//            daysSinceLastAte = 0;
//            return;
//        }
//    }
//    else if (mySystem->getTheOrganism(x,y-1) != nullptr && (y-1)>=SMALL_IDX){
//        if(mySystem->getTheOrganism(x,y-1)->getType() == ANT_CHAR){
//            mySystem->setTheOrganism(x,y-1,mySystem->getTheOrganism(x,y));
//            mySystem->setTheOrganism(x,y, nullptr);
//            y -= 1;
//            daysSinceLastAte = 0;
//            return;
//        }
//    }
//    else if (mySystem->getTheOrganism(x-1, y) != nullptr && (x-1) >= SMALL_IDX){
//        if (mySystem->getTheOrganism(x-1, y)->getType() == ANT_CHAR){
//            mySystem->setTheOrganism(x-1,y,mySystem->getTheOrganism(x,y));
//            mySystem->setTheOrganism(x,y, nullptr);
//            x -= 1;
//            daysSinceLastAte = 0;
//            return;
//        }
//    }
//    else if (mySystem->getTheOrganism(x+1, y) != nullptr && (x+1) <= BIG_IDX){
//        if (mySystem->getTheOrganism(x+1,y)->getType() == ANT_CHAR){
//            mySystem->setTheOrganism(x+1,y,mySystem->getTheOrganism(x,y));
//            mySystem->setTheOrganism(x,y, nullptr);
//            x += 1;
//            daysSinceLastAte = 0;
//            return;
//        }
//    }
//
//    int choice = rand()%4+1;
//    if (choice == 1 && mySystem->getTheOrganism(x,y+1) == nullptr && (y+1)<=BIG_IDX){
//        mySystem->setTheOrganism(x,y+1,mySystem->getTheOrganism(x,y));
//        mySystem->setTheOrganism(x,y, nullptr);
//        y += 1;
//        daysSinceLastAte += 1;
//    }
//    else if (choice == 2 && mySystem->getTheOrganism(x,y-1) == nullptr && (y-1)>=SMALL_IDX){
//        mySystem->setTheOrganism(x,y-1,mySystem->getTheOrganism(x,y));
//        mySystem->setTheOrganism(x,y, nullptr);
//        y -= 1;
//        daysSinceLastAte += 1;
//    }
//    else if (choice == 3 && mySystem->getTheOrganism(x-1, y) == nullptr && (x-1) >= SMALL_IDX){
//        mySystem->setTheOrganism(x-1,y,mySystem->getTheOrganism(x,y));
//        mySystem->setTheOrganism(x-1,y, nullptr);
//        x -= 1;
//        daysSinceLastAte += 1;
//    }
//    else if (choice == 4 && mySystem->getTheOrganism(x+1, y) == nullptr && (x+1) <= BIG_IDX){
//        mySystem->setTheOrganism(x+1,y,mySystem->getTheOrganism(x,y));
//        mySystem->setTheOrganism(x,y, nullptr);
//        x += 1;
//        daysSinceLastAte += 1;
//    }
//
//}
//
//void Doodlebug::breed() {
//    daysSinceLastBreed += 1;
//    daysSurvived += 1;
//    if (daysSinceLastBreed == DOODLE_BREED){
//        daysSinceLastBreed = 0;
//        int choice =  rand()%4 + 1;
//        if (choice == 1 && mySystem->getTheOrganism(x,y+1) == nullptr && (y+1)<=BIG_IDX){
//            new Doodlebug(mySystem, x, y+1);
//        }
//        else if (choice == 2 && mySystem->getTheOrganism(x,y-1) == nullptr && (y-1)>=SMALL_IDX){
//            new Doodlebug(mySystem, x, y-1);
//        }
//        else if (choice == 3 && mySystem->getTheOrganism(x-1, y) == nullptr && (x-1) >= SMALL_IDX){
//            new Doodlebug(mySystem, x-1, y);
//        }
//        else if (choice == 4 && mySystem->getTheOrganism(x+1, y) == nullptr && (x+1) <= BIG_IDX){
//            new Doodlebug(mySystem, x+1, y);
//        }
//    }
//}
//
//int main(){
//    srand(time(0));
//}
//
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


const int GARDENSIZE = 20;
const int ANT = 2;
const char ANTCHAR = 'O';
const char BUGCHAR = 'X';
const int BIG_IDX = 19;
const int SMALL_IDX = 0;

class Organism;

class Garden{
public:
    Garden();
    ~Garden();

    Organism* getAt(int x, int y);
    void setAt(int x, int y, Organism *org);
    void Display();

    friend class Organism;

private:
    Organism* grid[GARDENSIZE][GARDENSIZE]{};
};

class Organism{
public:
    Organism();
    Organism(Garden *garden, int x, int y);
    virtual ~Organism() = default;

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
            if(grid[i][j] != nullptr){
                delete grid[i][j];
                grid[i][j] = nullptr;
            }
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

Organism::Organism(){
    garden = nullptr;
    moved = false;
    breedTicks = 0;
    x = 0;
    y = 0;
}

Organism::Organism(Garden *garden, int x, int y){
    this->garden = garden;
    moved = false;
    this->x = x;
    this->y = y;
    this->garden->setAt(x, y, garden->getAt(x,y));
}

int main() {
    srand(time(0));
    return 0;
}