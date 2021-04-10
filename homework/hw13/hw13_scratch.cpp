#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

const int SIZE = 20;
const int SMALL_INDEX = 0;
const int BIG_INDEX = 19;
const int ANT_NUM = 100;
const int DOODLEBUG_NUM = 5;

class Coordinate{
public:
    Coordinate():xLo(0), yLo(0), isValid(true){}
    Coordinate(int x, int y): xLo(x), yLo(y), isValid(false){}

    int getXLo() const {return xLo;}
    int getYLo() const {return yLo;}
    bool getWhetherValid() const {return isValid;}
    void setWhetherValid();
    void setXLo(int x);
    void setYLo(int y);

private:
    int xLo;
    int yLo;
    bool isValid;
};
void Coordinate::setWhetherValid() {
    int x = getXLo();
    int y = getYLo();
    if (x <= BIG_INDEX && x >= SMALL_INDEX && y <= BIG_INDEX && y >= SMALL_INDEX){
        isValid = true;
    }
    else {
        isValid = false;
    }
}
void Coordinate::setXLo(int x) {
    xLo = x;
}
void Coordinate::setYLo(int y) {
    yLo = y;
}

class Organism{
public:
    Organism():daysSurvived(0), readyToBreed(false), daysSinceLastBreed(0), isDead(false), currentLocation(), typeOrganism('n'){}
    Organism(int x, int y): currentLocation(x,y),daysSurvived(0), readyToBreed(false), daysSinceLastBreed(0), isDead(false), typeOrganism('n'){}

    virtual void move(){}
    virtual void reproduce(){}

    Coordinate getCurrentLo() const {return currentLocation;}
    int getDaysSurvived() const {return daysSurvived;}
    bool getWhetherReadyBreed() const {return readyToBreed;}
    int getDaysSinceLastBreed() const {return daysSinceLastBreed;}
    bool getWhetherDead() const {return isDead;}
    char getOrganismType() const {return typeOrganism;}

    void setCurrentLocation(int x, int y);
    void setDaysSurvived(int days);
    void setDaysSinceLastBreed(int days);
    void setToDead(){isDead = true;}
    void setToReady(){readyToBreed = true;}
    void setOrganismType(char input){typeOrganism = input;}

private:
    Coordinate currentLocation;
    int daysSurvived;
    bool readyToBreed;
    int daysSinceLastBreed;
    bool isDead;
    char typeOrganism;

};
void Organism::setDaysSurvived(int days) {
    daysSurvived = days;
}
void Organism::setDaysSinceLastBreed(int days) {
    daysSinceLastBreed = days;
}
void Organism::setCurrentLocation(int x, int y) {
    currentLocation.setXLo(x);
    currentLocation.setYLo(y);
}

class Ant: public Organism{
public:
    Ant(int x, int y): Organism(x, y){setOrganismType('O');}
    Ant(): Organism(){setOrganismType('O');}

    virtual void move();
    virtual void reproduce();

private:
};
void Ant::move() {
    srand(time(0));
    int choice = rand()%4+1;
    int x = getCurrentLo().getXLo();
    int y =  getCurrentLo().getYLo();
    Coordinate up = Coordinate(x, y+1);
    Coordinate down = Coordinate(x, y-1);
    Coordinate left = Coordinate(x-1, y);
    Coordinate right = Coordinate(x+1, y);
    up.setWhetherValid();
    down.setWhetherValid();
    left.setWhetherValid();
    right.setWhetherValid();
    if (choice == 1 && up.getWhetherValid()){
        setCurrentLocation(x,y+1);
    }
    else if (choice == 2 && down.getWhetherValid()){
        setCurrentLocation(x, y-1);
    }
    else if (choice == 3 && left.getWhetherValid()){
        setCurrentLocation(x-1, y);
    }
    else if (choice == 4 && right.getWhetherValid()){
        setCurrentLocation(x+1, y);
    }
    int currentSurvived = getDaysSurvived();
    int currentBreed = getDaysSinceLastBreed();
    setDaysSurvived(currentSurvived+1);
    setDaysSinceLastBreed(currentBreed+1);
    if (getDaysSurvived() >= 3 && getDaysSinceLastBreed() == 3){
        setToReady();
        setDaysSinceLastBreed(0);
    }
}

void Ant::reproduce() {
//    bool whetherReady = getWhetherReadyBreed();
//    if (whetherReady){
//        srand(time(0));
//        int x = rand()%SIZE;
//        int y = rand()%SIZE;
//        Coordinate newAnt = Coordinate(x,y);
//        newAnt.setWhetherValid();
//
//    }
}

class Doodlebug: public Organism{
public:
    Doodlebug(int x, int y):Organism(x,y), daysSinceLastAte(0), justAte(false){setOrganismType('X');}
    Doodlebug():Organism(), daysSinceLastAte(0), justAte(false){setOrganismType('X');}

    virtual void move();
    virtual void reproduce();

    int getDaysSinceLastAte() const{return daysSinceLastAte;}
    bool getWhetherJustAte() const{return justAte;}
    void setDaysSinceLastAte(int days){daysSinceLastAte = days;}
    void setJustAte(){justAte=true;}

private:
    int daysSinceLastAte;
    bool justAte;
};
void Doodlebug::move() {

}
void Doodlebug::reproduce() {

}

int main(){


}