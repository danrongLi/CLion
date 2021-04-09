#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

const int SIZE = 20;
const int BIG_LIMIT = SIZE - 1;
const int SMALL_LIMIT = 0;

class Coordinate{
public:
    void setXLocation(int newX);
    void setYLocation(int newY);
    int getXLocation() const;
    int getYLocation() const;


    Coordinate();
    Coordinate(int xLo, int yLo);

private:
    int xLocation;
    int yLocation;

};

Coordinate::Coordinate() {
    xLocation = 0;
    yLocation = 0;
}
Coordinate::Coordinate(int xLo, int yLo) {
    xLocation = xLo;
    yLocation = yLo;
}
void Coordinate::setXLocation(int newX) {
    xLocation = newX;
}
void Coordinate::setYLocation(int newY) {
    yLocation = newY;
}
int Coordinate::getXLocation() const {
    return xLocation;
}
int Coordinate::getYLocation() const {
    return yLocation;
}

class Organism{
public:
    Coordinate getCurrentLocation() const {return currentLocation;}
    void setCurrentLocation(int xLo, int yLo){Coordinate(xLo, yLo);}
    int getDaysSurvived() const {return daysSurvived;}
    void setDaysSurvived(int days) {daysSurvived = days;}
    bool getWhetherReadyToBreed() const{return readyToBreed;}
    void setToBreed() {readyToBreed = true;}


    virtual void checkBreed(){}
    virtual void move(){}
    virtual void breed(){}

    bool getWhetherHasDoodlebug() const{return hasDoodlebug;}
    bool getWhetherHasAnts() const{return hasAnt;}
    void setToHasDoodlebug() {hasDoodlebug = true;}
    void setToHasAnt() {hasAnt = true;}
    bool getWhetherValid() const{return isValidCoordinate;}
    void setIsValid(int xLo, int yLo);
    void setDaysSinceBreed(int days){daysSinceBreed = days;}
    int getDaysSinceBreed() const{return daysSinceBreed;}


    Organism():currentLocation(), daysSurvived(0), readyToBreed(false),
                daysSinceBreed(0), hasDoodlebug(false), hasAnt(false), isValidCoordinate(true){}
private:
    Coordinate currentLocation;
    int daysSurvived;
    bool readyToBreed;
    int daysSinceBreed;


    bool hasDoodlebug;
    bool hasAnt;
    bool isValidCoordinate;
};

void Organism::setIsValid(int xLo, int yLo) {
    if (xLo <= BIG_LIMIT && xLo >= SMALL_LIMIT && yLo <= BIG_LIMIT && yLo >= SMALL_LIMIT){
        isValidCoordinate = true;
    }
    else {
        isValidCoordinate = false;
    }
}


class Ants: public Organism{
public:
    virtual void move();
    virtual void checkBreed();
    virtual void breed();

    bool getWhetherBeingEaten() const{return beingEaten;}
    void setToBeEaten() {beingEaten = true;}

    Ants():Organism(), beingEaten(false){}

private:
    bool beingEaten;
};
void Ants::breed() {

}
void Ants::checkBreed() {
    if (getDaysSurvived() == 3){
        setToBreed();
        setDaysSurvived(0);
    }
}
void Ants::move() {
    srand(time(0));
    int temp = rand()%4+1;
    int newX = getCurrentLocation().getXLocation();
    int newY = getCurrentLocation().getYLocation();
    int days = getDaysSurvived();
    if (temp == 1){
        newX += 1;
        setIsValid(newX, newY);
    }
    else if (temp == 2){
        newX -= 1;
        setIsValid(newX, newY);
    }
    else if (temp == 3){
        newY += 1;
        setIsValid(newX, newY);
    }
    else if (temp == 4){
        newY -= 1;
        setIsValid(newX, newY);
    }
    if (getWhetherValid() && !getWhetherHasAnts() && !getWhetherHasDoodlebug()){
        setCurrentLocation(newX, newY);
        setToHasAnt();
    }
    days += 1;
    setDaysSurvived(days);
}
class DoodleBug: public Organism{
public:
    virtual void move();
    virtual void checkBreed();
    virtual void breed();

    void setToDeath();
    bool getWhetherDead() const {return starvedToDeath;}
    bool getWhetherJustAte() const {return justAte;}
    void setJustAte();

    DoodleBug():Organism(), justAte(false), starvedToDeath(false), daysSinceLastEat(0){}

private:
    bool justAte;
    bool starvedToDeath;
    int daysSinceLastEat;

};
void DoodleBug::setJustAte() {
    int xLo = getCurrentLocation().getXLocation();
    int yLo = getCurrentLocation().getYLocation();

    setIsValid(xLo+1, yLo);
    if (getWhetherValid() && getWhetherHasAnts()){
        setCurrentLocation(xLo+1, yLo);
        setToHasDoodlebug();
        justAte = true;
        daysSinceLastEat = 0;
        return;
    }
    else {
        setIsValid(xLo-1, yLo);
        if (getWhetherValid() && getWhetherHasAnts()){
            setCurrentLocation(xLo-1, yLo);
            setToHasDoodlebug();
            justAte = true;
            daysSinceLastEat = 0;
            return;
        }
        else {
            setIsValid(xLo, yLo+1);
            if (getWhetherValid() && getWhetherHasAnts()){
                setCurrentLocation(xLo, yLo+1);
                setToHasDoodlebug();
                justAte = true;
                daysSinceLastEat = 0;
                return;
            }
            else {
                setIsValid(xLo, yLo-1);
                if (getWhetherValid() && getWhetherHasAnts()){
                    setCurrentLocation(xLo, yLo-1);
                    setToHasDoodlebug();
                    justAte = true;
                    daysSinceLastEat = 0;
                    return;
                }
                else {
                    justAte = false;
                    daysSinceLastEat += 1;
                    return;
                }
            }
        }
    }

}
void DoodleBug::breed() {

}
void DoodleBug::move() {
    srand(time(0));
    int temp = rand()%4+1;
    int newX = getCurrentLocation().getXLocation();
    int newY = getCurrentLocation().getYLocation();
    int days = getDaysSurvived();
    if (temp == 1){
        newX += 1;
        setIsValid(newX, newY);
    }
    else if (temp == 2){
        newX -= 1;
        setIsValid(newX, newY);
    }
    else if (temp == 3){
        newY += 1;
        setIsValid(newX, newY);
    }
    else if (temp == 4){
        newY -= 1;
        setIsValid(newX, newY);
    }
    if (getWhetherValid() && !getWhetherHasAnts() && !getWhetherHasDoodlebug()){
        setCurrentLocation(newX, newY);
        setToHasDoodlebug();
    }
    days += 1;
    setDaysSurvived(days);
}
void DoodleBug::setToDeath() {
    if (daysSinceLastEat == 3 && justAte == false){
        starvedToDeath = true;
    }
}

void DoodleBug::checkBreed() {
    if (getDaysSurvived() == 8){
        setToBreed();
        setDaysSinceBreed(0);
    }
}


int main(){
    DoodleBug bug1;
    vector<vector<Organism*>> world (SIZE, vector<Organism*>(SIZE, nullptr));
    for (int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            world[i][j] = &bug1;
        }
    }
}