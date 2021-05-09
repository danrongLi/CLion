#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int WORLD_SIZE = 20;
const int ANT_BREED = 3;
const int DOODLE_BREED = 8;
const int DOODLE_STARVE = 3;
const int INITIAL_ANT = 100;
const int INITIAL_DOODLE = 5;
const char ANT_CHAR = 'O';
const char DOODLE_CHAR = 'X';
const char EMPTY_CHAR = '-';
const int SMALL_LIMIT = 0;
const int BIG_LIMIT = 19;

class Organism;

class World{
public:

    World();
    ~World();

    void display();
    void oneTimeStep();

    Organism* getOrganism(int xLo, int yLo) const {return grid[xLo][yLo];}
    void setOrganism(int xLo, int yLo, Organism* toPlace){grid[xLo][yLo] = toPlace;}


private:
    Organism* grid[WORLD_SIZE][WORLD_SIZE]{};
};

class Organism{
public:

    Organism();
    virtual ~Organism() = default;
    Organism(World* inputWorld, int xLo, int yLo);

    virtual void move() = 0;
    virtual void breed() = 0;
    virtual bool starve() = 0;
    virtual char getType() = 0;

    int getDaysSinceLastBreed() const {return daysSinceLastBreed;}
    bool getWhetherMoved() const {return alreadyMoved;}
    void setWhetherMoved(bool whether){alreadyMoved = whether;}

protected:
    int daysSinceLastBreed;
    bool alreadyMoved;
    int x;
    int y;
    World* myWorld;
};

World::World() {
    for (int i = 0; i < WORLD_SIZE; i += 1){
        for (int j = 0; j < WORLD_SIZE; j += 1){
            grid[i][j] = nullptr;
        }
    }
}
World::~World() {
    for (int i = 0; i < WORLD_SIZE; i += 1){
        for (int j = 0; j < WORLD_SIZE; j += 1){
            delete grid[i][j];
            grid[i][j] = nullptr;
        }
    }
}
void World::display() {
    for (int i = 0; i < WORLD_SIZE; i += 1){
        for (int j = 0; j < WORLD_SIZE; j += 1){
            if (grid[i][j] != nullptr){
                cout<<grid[i][j]->getType()<<" ";
            }
            else {
                cout<<EMPTY_CHAR<<" ";
            }
        }
        cout<<endl;
    }
}
void World::oneTimeStep() {
    cout<<"preparing"<<endl;
    for (int i = 0; i < WORLD_SIZE; i += 1){
        for (int j = 0; j < WORLD_SIZE; j += 1){
            if (grid[i][j]!= nullptr){
                grid[i][j]->setWhetherMoved(false);
            }
        }
    }
    cout<<"moving doodle"<<endl;
    for (int i = 0; i < WORLD_SIZE; i += 1){
        for (int j = 0; j < WORLD_SIZE; j += 1){
            if (grid[i][j]!= nullptr && grid[i][j]->getType() == DOODLE_CHAR && (!grid[i][j]->getWhetherMoved())){
                grid[i][j]->move();
            }
        }
    }
    cout<<"moving ant"<<endl;
    for (int i = 0; i < WORLD_SIZE; i += 1){
        for (int j = 0; j < WORLD_SIZE; j += 1){
            if (grid[i][j]!= nullptr && grid[i][j]->getType() == ANT_CHAR && (!grid[i][j]->getWhetherMoved())){
                grid[i][j]->move();
            }
        }
    }
    cout<<"breeding doodle"<<endl;
    for (int i = 0; i < WORLD_SIZE; i += 1){
        for (int j = 0; j < WORLD_SIZE; j += 1){
            if (grid[i][j]!= nullptr && grid[i][j]->getType() == DOODLE_CHAR ){
                grid[i][j]->breed();
            }
        }
    }
    cout<<"breeding ant"<<endl;
    for (int i = 0; i < WORLD_SIZE; i += 1){
        for (int j = 0; j < WORLD_SIZE; j += 1){
            if (grid[i][j]!= nullptr && grid[i][j]->getType() == ANT_CHAR){
                grid[i][j]->breed();
            }
        }
    }
    cout<<"deleting starved organism"<<endl;
    for (int i = 0; i < WORLD_SIZE; i += 1){
        for (int j = 0; j < WORLD_SIZE; j += 1){
            if (grid[i][j]!= nullptr){
                if (grid[i][j]->starve()){
                    delete grid[i][j];
                    grid[i][j] = nullptr;
                }
            }
        }
    }
}

Organism::Organism() {
    daysSinceLastBreed = 0;
    alreadyMoved = false;
    x = 0;
    y = 0;
    myWorld = nullptr;
}
Organism::Organism(World* inputWorld, int xLo, int yLo) {
    daysSinceLastBreed = 0;
    alreadyMoved = false;
    x = xLo;
    y = yLo;
    myWorld = inputWorld;
}

class Ant: public Organism{
public:
    Ant():Organism(){}
    Ant(World* inputWorld, int xLo, int yLo): Organism(inputWorld, xLo, yLo){}

    virtual void move();
    virtual void breed();
    virtual char getType() {return ANT_CHAR;}
    virtual bool starve() {return false;}

private:
};
void Ant::move() {
    int choice = rand()%4 + 1;
    if (choice == 1){
        if ((y+1) <= BIG_LIMIT && myWorld->getOrganism(x,y+1) == nullptr){
            myWorld->setOrganism(x,y+1,myWorld->getOrganism(x,y));
            myWorld->setOrganism(x,y, nullptr);
            alreadyMoved = true;
            daysSinceLastBreed += 1;
            y += 1;
        }
        else {
            daysSinceLastBreed += 1;
        }
    }
    else if (choice == 2){
        if ((y-1) >= SMALL_LIMIT && myWorld->getOrganism(x,y-1) == nullptr){
            myWorld->setOrganism(x,y-1,myWorld->getOrganism(x,y));
            myWorld->setOrganism(x,y, nullptr);
            alreadyMoved = true;
            daysSinceLastBreed += 1;
            y -= 1;
        }
        else {
            daysSinceLastBreed += 1;
        }
    }
    else if (choice == 3){
        if ((x-1) >= SMALL_LIMIT && myWorld->getOrganism(x-1,y) == nullptr){
            myWorld->setOrganism(x-1,y,myWorld->getOrganism(x,y));
            myWorld->setOrganism(x,y, nullptr);
            alreadyMoved = true;
            daysSinceLastBreed += 1;
            x -= 1;
        }
        else {
            daysSinceLastBreed += 1;
        }
    }
    else if (choice == 4){
        if ((x+1) <= BIG_LIMIT && myWorld->getOrganism(x+1,y) == nullptr){
            myWorld->setOrganism(x+1,y,myWorld->getOrganism(x,y));
            myWorld->setOrganism(x,y, nullptr);
            alreadyMoved = true;
            daysSinceLastBreed += 1;
            x += 1;
        }
        else {
            daysSinceLastBreed += 1;
        }
    }
}
void Ant::breed() {
    if (getDaysSinceLastBreed() >= ANT_BREED){
        daysSinceLastBreed = 0;
        if (myWorld->getOrganism(x,y+1) == nullptr && (y+1) <= BIG_LIMIT){
            myWorld->setOrganism(x,y+1,new Ant(myWorld,x,y+1));
        }
        else if (myWorld->getOrganism(x,y-1) == nullptr && (y-1) >= SMALL_LIMIT){
            myWorld->setOrganism(x,y-1, new Ant(myWorld,x,y-1));
        }
        else if (myWorld->getOrganism(x-1,y) == nullptr && (x-1) >= SMALL_LIMIT){
            myWorld->setOrganism(x-1,y,new Ant(myWorld,x-1,y));
        }
        else if (myWorld->getOrganism(x+1,y) == nullptr && (x+1) <= BIG_LIMIT){
            myWorld->setOrganism(x+1,y, new Ant(myWorld,x+1,y));
        }
    }
}

class Doodlebug: public Organism{
public:

    Doodlebug():Organism(){daysSinceLastAte = 0;}
    Doodlebug(World* inputWorld, int xLo, int yLo): Organism(inputWorld, xLo, yLo){daysSinceLastAte = 0;}

    virtual void move();
    virtual void breed();
    virtual char getType() {return DOODLE_CHAR;}
    virtual bool starve() {return getDaysSinceLastAte() >= DOODLE_STARVE;}

    int getDaysSinceLastAte() const {return daysSinceLastAte;}
private:
    int daysSinceLastAte;
};

void Doodlebug::move() {
    if ((y+1) <= BIG_LIMIT && myWorld->getOrganism(x,y+1) != nullptr && myWorld->getOrganism(x,y+1)->getType() == ANT_CHAR){
        myWorld->setOrganism(x,y+1,myWorld->getOrganism(x,y));
        myWorld->setOrganism(x,y, nullptr);
        daysSinceLastAte = 0;
        alreadyMoved = true;
        daysSinceLastBreed += 1;
        y += 1;
    }
    else if ((y-1) >= SMALL_LIMIT && myWorld->getOrganism(x,y-1) != nullptr && myWorld->getOrganism(x,y-1)->getType() == ANT_CHAR){
        myWorld->setOrganism(x,y-1,myWorld->getOrganism(x,y));
        myWorld->setOrganism(x,y, nullptr);
        daysSinceLastAte = 0;
        alreadyMoved = true;
        daysSinceLastBreed += 1;
        y -= 1;
    }
    else if ((x-1) >= SMALL_LIMIT && myWorld->getOrganism(x-1,y) != nullptr && myWorld->getOrganism(x-1,y)->getType() == ANT_CHAR){
        myWorld->setOrganism(x-1,y,myWorld->getOrganism(x,y));
        myWorld->setOrganism(x,y, nullptr);
        daysSinceLastAte = 0;
        alreadyMoved = true;
        daysSinceLastBreed += 1;
        x -= 1;
    }
    else if ((x+1) <= BIG_LIMIT && myWorld->getOrganism(x+1,y) != nullptr && myWorld->getOrganism(x+1,y)->getType() == ANT_CHAR){
        myWorld->setOrganism(x+1,y,myWorld->getOrganism(x,y));
        myWorld->setOrganism(x,y, nullptr);
        daysSinceLastAte = 0;
        alreadyMoved = true;
        daysSinceLastBreed += 1;
        x += 1;
    }
    else {
        int choice  =  rand()%4 + 1;
        if (choice == 1){
            if ((y+1) <= BIG_LIMIT && myWorld->getOrganism(x,y+1) == nullptr){
                myWorld->setOrganism(x,y+1,myWorld->getOrganism(x,y));
                myWorld->setOrganism(x,y, nullptr);
                daysSinceLastAte += 1;
                alreadyMoved = true;
                daysSinceLastBreed += 1;
                y += 1;
            }
            else {
                daysSinceLastBreed += 1;
                daysSinceLastAte += 1;
            }
        }
        else if (choice == 2){
            if ((y-1) >= SMALL_LIMIT && myWorld->getOrganism(x,y-1) == nullptr){
                myWorld->setOrganism(x,y-1,myWorld->getOrganism(x,y));
                myWorld->setOrganism(x,y, nullptr);
                daysSinceLastAte += 1;
                alreadyMoved = true;
                daysSinceLastBreed += 1;
                y -= 1;
            }
            else {
                daysSinceLastBreed += 1;
                daysSinceLastAte += 1;
            }
        }
        else if (choice == 3){
            if ((x-1) >= SMALL_LIMIT && myWorld->getOrganism(x-1,y) == nullptr){
                myWorld->setOrganism(x-1,y,myWorld->getOrganism(x,y));
                myWorld->setOrganism(x,y, nullptr);
                daysSinceLastAte += 1;
                alreadyMoved = true;
                daysSinceLastBreed += 1;
                x -= 1;
            }
            else {
                daysSinceLastBreed += 1;
                daysSinceLastAte += 1;
            }
        }
        else if (choice == 4){
            if ((x+1) <= BIG_LIMIT && myWorld->getOrganism(x+1,y) == nullptr){
                myWorld->setOrganism(x+1,y,myWorld->getOrganism(x,y));
                myWorld->setOrganism(x,y, nullptr);
                daysSinceLastAte += 1;
                alreadyMoved = true;
                daysSinceLastBreed += 1;
                x += 1;
            }
            else {
                daysSinceLastBreed += 1;
                daysSinceLastAte += 1;
            }
        }
    }
}
void Doodlebug::breed() {
    if (getDaysSinceLastBreed() >= DOODLE_BREED){
        daysSinceLastBreed = 0;
        if (myWorld->getOrganism(x,y+1) == nullptr && (y+1) <= BIG_LIMIT){
            myWorld->setOrganism(x,y+1,new Doodlebug(myWorld,x,y+1));
        }
        else if (myWorld->getOrganism(x,y-1) == nullptr && (y-1) >= SMALL_LIMIT){
            myWorld->setOrganism(x,y-1, new Doodlebug(myWorld,x,y-1));
        }
        else if (myWorld->getOrganism(x-1,y) == nullptr && (x-1) >= SMALL_LIMIT){
            myWorld->setOrganism(x-1,y,new Doodlebug(myWorld,x-1,y));
        }
        else if (myWorld->getOrganism(x+1,y) == nullptr && (x+1) <= BIG_LIMIT){
            myWorld->setOrganism(x+1,y, new Doodlebug(myWorld,x+1,y));
        }
    }
}

int main(){
    srand(time(nullptr));

    World simulatedWorld;

    int antCount = 0;
    int doodleCount = 0;

    while (antCount < INITIAL_ANT){
        int x = rand() % WORLD_SIZE;
        int y = rand() % WORLD_SIZE;
        if (simulatedWorld.getOrganism(x,y) == nullptr){
            simulatedWorld.setOrganism(x,y, new Ant(&simulatedWorld, x,y));
        }
        antCount += 1;
    }

    while (doodleCount < INITIAL_DOODLE){
        int x = rand() % WORLD_SIZE;
        int y = rand() % WORLD_SIZE;
        if (simulatedWorld.getOrganism(x,y) == nullptr){
            simulatedWorld.setOrganism(x,y, new Doodlebug(&simulatedWorld, x, y));
        }
        doodleCount += 1;
    }

    cout<<"Finished world initialization ... "<<endl;
    simulatedWorld.display();
    cout<<"Press Enter to start simulation or any other keys to exit"<<endl;


    while (cin.get() == '\n'){
        simulatedWorld.oneTimeStep();
        simulatedWorld.display();
        cout<<"Press Enter to start simulation or any other keys to exit"<<endl;
    }


}