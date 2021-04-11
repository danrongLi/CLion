#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
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

    Organism* getTheOrganism(int xLo, int yLo);
    void setTheOrganism(int xLo, int yLo, Organism* theOrganism);

    void display();
    void simulateOneTimeStep();

    void checkWhetherValid(int xLo, int yLo);
    bool getWhetherValid() const {return ifValid;}

private:
    Organism* gridBoard[SIZE][SIZE]{};
    bool ifValid;
};
void EcoSystem::checkWhetherValid(int xLo, int yLo) {
    if (xLo >= SMALL_IDX && xLo <= BIG_IDX && yLo >= SMALL_IDX && xLo <= BIG_IDX){
        ifValid = true;
    }
    else {
        ifValid = false;
    }
}
Organism* EcoSystem::getTheOrganism(int xLo, int yLo) {
    checkWhetherValid(xLo, yLo);
    if (ifValid){
        if(gridBoard[xLo][yLo] != nullptr){
            return gridBoard[xLo][yLo];
        }
        else {
            return nullptr;
        }
    }
    else {
        cout<<"You are trying to access data that is out of range!"<<endl;
        exit(1);
    }
}
void EcoSystem::setTheOrganism(int xLo, int yLo, Organism *theOrganism) {
    if (xLo >= SMALL_IDX && xLo <= BIG_IDX && yLo >= SMALL_IDX && xLo <= BIG_IDX && gridBoard[xLo][yLo] == nullptr){
        gridBoard[xLo][yLo] = theOrganism;
    }
}
EcoSystem::EcoSystem() {
    ifValid = false;
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

}
void EcoSystem::simulateOneTimeStep() {

}

class Organism{
public:
    friend class EcoSystem;

    Organism();
    virtual ~Organism();

    Organism(EcoSystem* inputSystem, int xLo, int yLo);

    virtual void move() = 0;
    virtual void breed() = 0;
    virtual void getType() = 0;
    virtual void starve() = 0;

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
Organism::Organism(EcoSystem *inputSystem, int xLo, int yLo) {
    x = xLo;
    y = yLo;
    this->mySystem = inputSystem;
    inputSystem->setTheOrganism(x, y, this);
}
