#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

const int SIZE = 20;
const int SMALL_IDX = 0;
const int BIG_IDX = SIZE - 1;
const int INITIAL_ANT = 100;
const int INITIAL_DOODLE = 5;

class Point{
public:
    Point():x(0),y(0),ifValid(true), ifOccupied(false), whetherAnt(false){}
    Point(int newX, int newY): x(newX), y(newY), ifValid(true), ifOccupied(false), whetherAnt(false){}

    int getX() const {return x;}
    int getY() const {return y;}
    bool getIfValid() const {return ifValid;};
    bool getIfOccupied() const {return ifOccupied;}
    bool getWhetherAnt() const {return whetherAnt;}

    void setX(int newX){x = newX;}
    void setY(int newY){y = newY;}
    void setIfValid();
    void setToOccupied(){ifOccupied = true;} //call to make it occupied
    void setToHaveAnt(){whetherAnt = true;} //call to make it ANT


private:
    int x;
    int y;
    bool ifValid;
    bool ifOccupied;
    bool whetherAnt;
};
void Point::setIfValid() {
    if (x <= BIG_IDX && x >= SMALL_IDX && y <= BIG_IDX && y >= SMALL_IDX && (!ifOccupied)){
        ifValid = true;
    }
    else {
        ifValid = false;
    }
}


class Organism{
public:
    virtual void move() = 0;
    virtual ~Organism() = default;
    Organism():location(), daysSurvived(0), daysSinceLastBreed(0), readyToBreed(false), ifDead(false){}
    Organism(int x, int y): location(x,y),daysSurvived(0), daysSinceLastBreed(0), readyToBreed(false), ifDead(false){}

    Point getLocation() const {return location;}
    void setLocation(int x, int y){location.setX(x); location.setY(y);}
    int getDaysSurvived() const {return daysSurvived;}
    int getDaysSinceLastBreed() const {return daysSinceLastBreed;}
    bool getWhetherReadyBreed() const {return readyToBreed;}
    bool getIfDead() const {return ifDead;}
    void setDaysSurvived(int days) {daysSurvived = days;}
    void setDaysSinceLastBreed(int days){daysSinceLastBreed = days;}
    void setToReady(){readyToBreed = true;}
    void setToDead() {ifDead = true;}

    void display(){cout<<getType()<<" ";}
    char getType() const {return type;}
    void setType(char newType) {type = newType;}

    Point getNextLocation() const{return nextLocation;}
    void setNextLocation();

private:
    Point location;
    int daysSurvived;
    int daysSinceLastBreed;
    bool readyToBreed;
    bool ifDead;
    char type;
    Point nextLocation;
};
void Organism::setNextLocation() {
    int currentX = location.getX();
    int currentY = location.getY();
    Point up = Point(currentX, currentY+1);
    Point down = Point(currentX, currentY-1);
    Point left = Point(currentX-1, currentY);
    Point right = Point(currentX+1, currentY);
    up.setIfValid();
    down.setIfValid();
    left.setIfValid();
    right.setIfValid();

    if (type == 'X'){
        if (up.getIfValid() && up.getWhetherAnt()){
            nextLocation.setX(currentX);
            nextLocation.setY(currentY+1);
//            location.setToOccupied();
        }
        else if (down.getIfValid() && down.getWhetherAnt()){
            nextLocation.setX(currentX);
            nextLocation.setY(currentY-1);
//            location.setToOccupied();
        }
        else if (left.getIfValid() && left.getWhetherAnt()){
            nextLocation.setX(currentX-1);
            nextLocation.setY(currentY);
//            location.setToOccupied();
        }
        else if (right.getIfValid() && right.getWhetherAnt()){
            nextLocation.setX(currentX+1);
            nextLocation.setY(currentY);
//            location.setToOccupied();
        }
        else {
            srand(time(0));
            int choice = rand()%4+1;
            if (choice == 1){
                if (up.getIfValid()){
                    nextLocation.setY(currentY+1);
//                    location.setToOccupied();
                }
            }
            else if (choice == 2){
                if (down.getIfValid()){
                    nextLocation.setY(currentY-1);
//                    location.setToOccupied();
                }
            }
            else if (choice == 3){

                if (left.getIfValid()){
                    nextLocation.setX(currentX-1);
//                    location.setToOccupied();
                }
            }
            else if (choice == 4){

                if (right.getIfValid()){
                    nextLocation.setX(currentX+1);
//                    location.setToOccupied();
                }
            }
            else {
                nextLocation.setX(currentX);
                nextLocation.setY(currentY);
            }
        }
    }
    else if (type == 'O'){
        srand(time(0));
        int choice = rand()%4+1;
        if (choice == 1){

            if (up.getIfValid()){
                nextLocation.setY(currentY+1);
//            location.setToOccupied();
//            if (type == 'O'){
//                location.setToHaveAnt();
//            }
            }
        }
        else if (choice == 2){

            if (down.getIfValid()){
                nextLocation.setY(currentY-1);
//            location.setToOccupied();
//            if (type == 'O'){
//                location.setToHaveAnt();
//            }
            }
        }
        else if (choice == 3){

            if (left.getIfValid()){
                nextLocation.setX(currentX-1);
//            location.setToOccupied();
//            if (type == 'O'){
//                location.setToHaveAnt();
//            }
            }
        }
        else if (choice == 4){

            if (right.getIfValid()){
                nextLocation.setX(currentX+1);
//            location.setToOccupied();
//            if (type == 'O'){
//                location.setToHaveAnt();
//            }
            }
        }
        else {
            nextLocation.setX(currentX);
            nextLocation.setY(currentY);
        }
    }
    else {
        cout<<"wrong type somehow!"<<endl;
        exit(1);
    }


}
class Ant: public Organism{
public:
    Ant():Organism(){setType('O');}
    Ant(int x, int y):Organism(x,y){setType('O');}

    virtual void move();
private:

};
void Ant::move() {
    Point next = getNextLocation();
    int currentSurvived = getDaysSurvived();
    int getBreed = getDaysSinceLastBreed();
//    more to come..
}

class Doodlebug : public Organism{
public:
    Doodlebug():Organism(), whetherJustAte(false){setType('X');}
    Doodlebug(int x, int y):Organism(x,y), whetherJustAte(false){setType('X');}
    virtual void move();
private:
    bool whetherJustAte;
};
void Doodlebug::move() {

}

int main(){
    srand(time(0));
    Organism* world[20][20];
    for (int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            world[i][j] = nullptr;
        }
    }
    int initialDoodle = 0;
    int initialAnt = 0;
    while (initialDoodle < INITIAL_DOODLE){
        int x = rand()%SIZE;
        int y = rand()%SIZE;
        Doodlebug tempDoodle(x,y);
        if (world[x][y] == nullptr){
            tempDoodle.getLocation().setToOccupied();
            world[x][y] = &tempDoodle;
            initialDoodle += 1;
        }
    }
    while (initialAnt < INITIAL_ANT){
    int x = rand()%SIZE;
    int y = rand()%SIZE;
    Ant tempAnt(x,y);
    if (world[x][y] == nullptr){
        tempAnt.getLocation().setToOccupied();
        tempAnt.getLocation().setToHaveAnt();
        world[x][y] = &tempAnt;
        initialAnt += 1;
    }
}
    cout<<"********** Game Begin **********"<<endl<<endl;
    cout<<"World Initialization with Ant# = "<<INITIAL_ANT<<" Doodlebug# = "<<INITIAL_DOODLE<<endl<<endl;
    for (int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            if (world[i][j] != nullptr){
                cout<<world[i][j]->getType()<<" ";
            }
            else {
                cout<<"- ";
            }
        }
        cout<<endl;
    }




    return 0;
}