#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int SIZE = 20;
const int SMALL_IDX = 0;
const int BIG_IDX = SIZE - 1;
const int INITIAL_ANT = 100;
const int INITIAL_DOODLE = 5;
const char ANT_CHAR = 'O';
const char DOODLE_CHAR = 'X';
const char EMPTY_CHAR = '-';
const int ANT_BREED = 3;
const int DOODLE_BREED = 8;
const int DOODLE_DIE = 3;


class Organism;
class Ant;
class Doodlebug;

class EcoSystem{
public:
    friend class Organism;
    friend class Ant;
    friend class Doodlebug;

    EcoSystem();
    ~EcoSystem();

    Organism* getTheOrganism(int xLo, int yLo){return gridBoard[xLo][yLo];}
    void setTheOrganism(int xLo, int yLo, Organism* theOrganism){gridBoard[xLo][yLo] = theOrganism;}

    void display();
    void simulateOneTimeStep();


private:
    Organism* gridBoard[SIZE][SIZE]{};
};


class Organism{
public:
    friend class EcoSystem;

    Organism();
    virtual ~Organism()= default;

    Organism(EcoSystem* inputSystem, int xLo, int yLo);

    virtual void move() = 0;
    virtual void breed() = 0;
    virtual char getType() = 0;
    virtual bool starve() = 0;

protected:
    int x;
    int y;
    bool alreadyMoved;
    int daysSurvived;
    int daysSinceLastBreed;
    EcoSystem* mySystem;
};
Organism::Organism() {
    x = 0;
    y = 0;
    alreadyMoved = false;
    daysSurvived = 0;
    daysSinceLastBreed = 0;
    mySystem = nullptr;
}
Organism::Organism(EcoSystem* inputSystem, int xLo, int yLo) {
    x = xLo;
    y = yLo;
    mySystem = inputSystem;
//    mySystem->setTheOrganism(x, y, inputSystem->getTheOrganism(xLo,yLo));
    alreadyMoved = false;
    daysSurvived = 0;
    daysSinceLastBreed = 0;
}
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
//    else {
//        cout<<"You are trying to access invalid location"<<endl;
//        cout<<xLo<<" "<<yLo<<endl;
//        exit(1);
//    }
//}

//void EcoSystem::setTheOrganism(int xLo, int yLo, Organism* theOrganism) {
//    if (xLo >= SMALL_IDX && xLo <= BIG_IDX && yLo >= SMALL_IDX && yLo <= BIG_IDX){
//        gridBoard[xLo][yLo] = theOrganism;
//    }
//}
EcoSystem::EcoSystem() {
    for (int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            gridBoard[i][j] = nullptr;
        }
    }
}
EcoSystem::~EcoSystem() {
    for (int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            if (gridBoard[i][j] != nullptr){
                delete gridBoard[i][j];
                gridBoard[i][j] = nullptr;
            }
        }
    }
}

void EcoSystem::display() {
    for(int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            if (gridBoard[i][j] != nullptr) {
                cout<<gridBoard[i][j]->getType()<<" ";
            }
            else {
                cout<<EMPTY_CHAR<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void EcoSystem::simulateOneTimeStep() {
    for(int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            if (gridBoard[i][j] != nullptr){
                gridBoard[i][j]->alreadyMoved = false;
            }
        }
    }

    for(int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            if (gridBoard[i][j] != nullptr && gridBoard[i][j]->getType() == DOODLE_CHAR && (!gridBoard[i][j]->alreadyMoved)){
                gridBoard[i][j]->move();
            }
        }
    }
    for (int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            if (gridBoard[i][j] != nullptr && gridBoard[i][j]->getType() == DOODLE_CHAR){
                gridBoard[i][j]->breed();
            }
        }
    }

    for (int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            if (gridBoard[i][j] != nullptr && gridBoard[i][j]->getType() == DOODLE_CHAR){
                if (gridBoard[i][j]->starve()){
                    delete gridBoard[i][j];
                    gridBoard[i][j] = nullptr;
                }
            }
        }
    }

    for (int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            if (gridBoard[i][j] != nullptr && gridBoard[i][j]->getType() == ANT_CHAR && (!gridBoard[i][j]->alreadyMoved)){
                gridBoard[i][j]->move();
            }
        }
    }

    for (int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            if (gridBoard[i][j] != nullptr && gridBoard[i][j]->getType() == ANT_CHAR){
                gridBoard[i][j]->breed();
            }
        }
    }
}


class Ant: public Organism{
public:
    friend class EcoSystem;
    Ant():Organism(){}
    Ant(EcoSystem* inputSystem, int xLo, int yLo): Organism(inputSystem, xLo, yLo){}

    virtual void move();
    virtual void breed();
    virtual char getType() {return ANT_CHAR;}
    virtual bool starve() {return false;}
private:

};

void Ant::move() {
    int choice = rand()%4+1;
    if (choice == 1 && (y+1)<=BIG_IDX && mySystem->getTheOrganism(x,y+1) == nullptr){
        mySystem->setTheOrganism(x,y+1,mySystem->getTheOrganism(x,y));
        mySystem->setTheOrganism(x,y, nullptr);
        y += 1;
        alreadyMoved = true;
    }
    else if (choice == 2 && (y-1)>=SMALL_IDX && mySystem->getTheOrganism(x,y-1) == nullptr){
        mySystem->setTheOrganism(x,y-1,mySystem->getTheOrganism(x,y));
        mySystem->setTheOrganism(x,y, nullptr);
        y -= 1;
        alreadyMoved = true;
    }
    else if (choice == 3 && (x-1) >= SMALL_IDX && mySystem->getTheOrganism(x-1, y) == nullptr){
        mySystem->setTheOrganism(x-1,y,mySystem->getTheOrganism(x,y));
        mySystem->setTheOrganism(x,y, nullptr);
        x -= 1;
        alreadyMoved = true;
    }
    else if (choice == 4 && (x+1) <= BIG_IDX && mySystem->getTheOrganism(x+1, y) == nullptr){
        mySystem->setTheOrganism(x+1,y,mySystem->getTheOrganism(x,y));
        mySystem->setTheOrganism(x,y, nullptr);
        x += 1;
        alreadyMoved = true;
    }
    daysSinceLastBreed += 1;
    daysSurvived += 1;
}

void Ant::breed() {
    if (daysSinceLastBreed == ANT_BREED){
        daysSinceLastBreed = 0;
        if ((y+1)<=BIG_IDX && mySystem->getTheOrganism(x,y+1) == nullptr){
            mySystem->setTheOrganism(x,y+1,new Ant(mySystem,x,y+1));
        }
        else if ( (y-1)>=SMALL_IDX && mySystem->getTheOrganism(x,y-1) == nullptr){
            mySystem->setTheOrganism(x,y-1,new Ant(mySystem,x,y-1));
        }
        else if ( (x-1) >= SMALL_IDX && mySystem->getTheOrganism(x-1, y) == nullptr){
            mySystem->setTheOrganism(x-1,y,new Ant(mySystem, x-1, y));
        }
        else if ( (x+1) <= BIG_IDX && mySystem->getTheOrganism(x+1, y) == nullptr){
            mySystem->setTheOrganism(x+1, y, new Ant(mySystem, x+1, y));
        }
    }
}

class Doodlebug: public Organism{
public:
    Doodlebug():Organism(),daysSinceLastAte(0){}
    Doodlebug(EcoSystem* mySystem, int xLo, int yLo): Organism(mySystem, xLo, yLo),daysSinceLastAte(0){}

    virtual void breed();
    virtual void move();
    virtual char getType() {return DOODLE_CHAR;}
    virtual bool starve() {return daysSinceLastAte >= DOODLE_DIE;}

    friend class EcoSystem;

private:
    int daysSinceLastAte;
};

void Doodlebug::move() {
    daysSinceLastBreed += 1;
    daysSurvived += 1;
    if ((y+1)<=BIG_IDX && mySystem->getTheOrganism(x,y+1) != nullptr && mySystem->getTheOrganism(x,y+1)->getType() == ANT_CHAR){
        mySystem->setTheOrganism(x,y+1,mySystem->getTheOrganism(x,y));
        mySystem->setTheOrganism(x,y, nullptr);
        y += 1;
        daysSinceLastAte = 0;
        alreadyMoved = true;
        return;

    }
    else if ((y-1)>=SMALL_IDX && mySystem->getTheOrganism(x,y-1) != nullptr && mySystem->getTheOrganism(x,y-1)->getType() == ANT_CHAR){
        mySystem->setTheOrganism(x,y-1,mySystem->getTheOrganism(x,y));
        mySystem->setTheOrganism(x,y, nullptr);
        y -= 1;
        daysSinceLastAte = 0;
        alreadyMoved = true;
        return;

    }
    else if ((x-1) >= SMALL_IDX && mySystem->getTheOrganism(x-1, y) != nullptr && mySystem->getTheOrganism(x-1, y)->getType() == ANT_CHAR){
        mySystem->setTheOrganism(x-1,y,mySystem->getTheOrganism(x,y));
        mySystem->setTheOrganism(x,y, nullptr);
        x -= 1;
        daysSinceLastAte = 0;
        alreadyMoved = true;
        return;

    }
    else if ((x+1) <= BIG_IDX && mySystem->getTheOrganism(x+1, y) != nullptr && mySystem->getTheOrganism(x+1,y)->getType() == ANT_CHAR){

        mySystem->setTheOrganism(x+1,y,mySystem->getTheOrganism(x,y));
        mySystem->setTheOrganism(x,y, nullptr);
        x += 1;
        daysSinceLastAte = 0;
        alreadyMoved = true;
        return;
    }

    int choice = rand()%4+1;
    if (choice == 1 && (y+1)<=BIG_IDX && mySystem->getTheOrganism(x,y+1) == nullptr){
        mySystem->setTheOrganism(x,y+1,mySystem->getTheOrganism(x,y));
        mySystem->setTheOrganism(x,y, nullptr);
        y += 1;
        daysSinceLastAte += 1;
        alreadyMoved = true;
    }
    else if (choice == 2 && (y-1)>=SMALL_IDX && mySystem->getTheOrganism(x,y-1) == nullptr){
        mySystem->setTheOrganism(x,y-1,mySystem->getTheOrganism(x,y));
        mySystem->setTheOrganism(x,y, nullptr);
        y -= 1;
        daysSinceLastAte += 1;
        alreadyMoved = true;
    }
    else if (choice == 3 && (x-1) >= SMALL_IDX && mySystem->getTheOrganism(x-1, y) == nullptr){
        mySystem->setTheOrganism(x-1,y,mySystem->getTheOrganism(x,y));
        mySystem->setTheOrganism(x,y, nullptr);
        x -= 1;
        daysSinceLastAte += 1;
        alreadyMoved = true;
    }
    else if (choice == 4 && (x+1) <= BIG_IDX && mySystem->getTheOrganism(x+1, y) == nullptr){
        mySystem->setTheOrganism(x+1,y,mySystem->getTheOrganism(x,y));
        mySystem->setTheOrganism(x,y, nullptr);
        x += 1;
        daysSinceLastAte += 1;
        alreadyMoved = true;
    }

}

void Doodlebug::breed() {
    if (daysSinceLastBreed == DOODLE_BREED){
        daysSinceLastBreed = 0;
        if ((y+1)<=BIG_IDX && mySystem->getTheOrganism(x,y+1) == nullptr){
            mySystem->setTheOrganism(x,y+1,new Doodlebug(mySystem,x,y+1));
        }
        else if ( (y-1)>=SMALL_IDX && mySystem->getTheOrganism(x,y-1) == nullptr){
            mySystem->setTheOrganism(x,y-1, new Doodlebug(mySystem, x, y-1));
        }
        else if ((x-1) >= SMALL_IDX && mySystem->getTheOrganism(x-1, y) == nullptr){
            mySystem->setTheOrganism(x-1,y, new Doodlebug(mySystem, x-1, y));
        }
        else if ((x+1) <= BIG_IDX && mySystem->getTheOrganism(x+1, y) == nullptr){
            mySystem->setTheOrganism(x+1, y, new Doodlebug(mySystem, x+1, y));
        }
    }
}


int main(){
    srand(time(0));
    EcoSystem mainSystem;

    int antNum = 0;
    int doodleNum = 0;

    while (antNum < INITIAL_ANT){
        int x = rand()%SIZE;
        int y = rand()%SIZE;
        if (mainSystem.getTheOrganism(x,y) == nullptr){
            mainSystem.setTheOrganism(x,y,new Ant(&mainSystem, x, y));
            antNum += 1;
        }
    }

    while (doodleNum < INITIAL_DOODLE){
        int x = rand()%SIZE;
        int y = rand()%SIZE;
        if (mainSystem.getTheOrganism(x,y) == nullptr){
            mainSystem.setTheOrganism(x,y,new Doodlebug(&mainSystem, x, y));
            doodleNum += 1;
        }
    }
    cout<<endl;
    cout<<"********** Game Begins **********"<<endl;
    cout<<"Finished Initializing the world with antNum = "<<antNum<<" doodleNum = "<<doodleNum<<endl;
    mainSystem.display();

    cout<<"press Enter key to start or any other key to exit"<<endl;
    while (cin.get() == '\n'){
        mainSystem.simulateOneTimeStep();
        mainSystem.display();
        cout<<"press Enter key to start or any other key to exit"<<endl;
    }

    return 0;
}
