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

class Organism;
class Ant;
class Doodlebug;

class Point{
public:
    Point():x(0),y(0),ifValid(true), ifOccupied(false), whetherAnt(false){}
    Point(int newX, int newY): x(newX), y(newY), ifValid(true), ifOccupied(false), whetherAnt(false){}

    int getX() const {return x;}
    int getY() const {return y;}
    bool getIfValid() const {return ifValid;}
    bool getIfOccupied() const {return ifOccupied;}
    bool getWhetherAnt() const {return whetherAnt;}

    void setX(int newX){x = newX;}
    void setY(int newY){y = newY;}
    void setIfValid();
    void setToOccupied(){ifOccupied = true;} //call to make it occupied
    void setToHaveAnt(){whetherAnt = true;} //call to make it ANT

    void setToNotOccupied(){ifOccupied = false;} //call to make it not occupied
    void setToNotAnt(){whetherAnt = false;} //call to make it non-ANT

    void setIfOccupied(Organism* world[SIZE][SIZE]);

    friend class Organism;
    friend class Ant;
    friend class Doodlebug;

private:
    int x;
    int y;
    bool ifValid;
    bool ifOccupied;
    bool whetherAnt;
};
void Point::setIfOccupied(Organism *(*world)[20]) {
    if(world[x][y] == nullptr){
        ifOccupied = false;
    }
    else{
        ifOccupied = true;
    }
}

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
    virtual ~Organism()=default;
    Organism():location(), daysSurvived(0), daysSinceLastBreed(0), readyToBreed(false), ifDead(false), type('-'), whetherAnt(false), ifOccupied(false), alreadyPlaced(false){}
    Organism(int x, int y): location(x,y),daysSurvived(0), daysSinceLastBreed(0), readyToBreed(false), ifDead(false), type('-'),  whetherAnt(false), ifOccupied(false), alreadyPlaced(false){}

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

    void setToOccupied(){ifOccupied = true;} //call to make it occupied
    void setToHaveAnt(){whetherAnt = true;} //call to make it ANT

    void setToNotOccupied(){ifOccupied = false;} //call to make it not occupied
    void setToNotAnt(){whetherAnt = false;} //call to make it non-ANT

    bool getIfOccupied() const {return ifOccupied;}
    bool getWhetherAnt() const {return whetherAnt;}

    bool getIfPlace() const {return alreadyPlaced;}
    void setToPlace() {alreadyPlaced = true;}

private:
    Point location;
    int daysSurvived;
    int daysSinceLastBreed;
    bool readyToBreed;
    bool ifDead;
    char type;
    Point nextLocation;

    bool whetherAnt;
    bool ifOccupied;

    bool alreadyPlaced;
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
            cout<<"Found ant"<<endl;
            nextLocation.setX(currentX);
            nextLocation.setY(currentY+1);
        }
        else if (down.getIfValid() && down.getWhetherAnt()){
            cout<<"Found ant"<<endl;
            nextLocation.setX(currentX);
            nextLocation.setY(currentY-1);
        }
        else if (left.getIfValid() && left.getWhetherAnt()){
            cout<<"Found ant"<<endl;
            nextLocation.setX(currentX-1);
            nextLocation.setY(currentY);
        }
        else if (right.getIfValid() && right.getWhetherAnt()){
            cout<<"Found ant"<<endl;
            nextLocation.setX(currentX+1);
            nextLocation.setY(currentY);
        }
        else {
            int choice = rand()%4+1;
            if (choice == 1){
                if (up.getIfValid()){
                    nextLocation.setX(currentX);
                    nextLocation.setY(currentY+1);
                }
                else {
                    nextLocation.setX(currentX);
                    nextLocation.setY(currentY);
                }
            }
            else if (choice == 2){

                if (down.getIfValid()){
                    nextLocation.setX(currentX);
                    nextLocation.setY(currentY-1);
                }
                else {
                    nextLocation.setX(currentX);
                    nextLocation.setY(currentY);
                }
            }
            else if (choice == 3){

                if (left.getIfValid()){
                    nextLocation.setX(currentX-1);
                    nextLocation.setY(currentY);
                }
                else {
                    nextLocation.setX(currentX);
                    nextLocation.setY(currentY);
                }
            }
            else if (choice == 4){

                if (right.getIfValid()){
                    nextLocation.setX(currentX+1);
                    nextLocation.setY(currentY);
                }
                else {
                    nextLocation.setX(currentX);
                    nextLocation.setY(currentY);
                }
            }
        }
    }
    else if (type == 'O'){
        int choice = rand()%4+1;
        if (choice == 1){
            if (up.getIfValid()){
                nextLocation.setX(currentX);
                nextLocation.setY(currentY+1);
            }
            else {
                nextLocation.setX(currentX);
                nextLocation.setY(currentY);
            }
        }
        else if (choice == 2){

            if (down.getIfValid()){
                nextLocation.setX(currentX);
                nextLocation.setY(currentY-1);
            }
            else {
                nextLocation.setX(currentX);
                nextLocation.setY(currentY);
            }
        }
        else if (choice == 3){

            if (left.getIfValid()){
                nextLocation.setX(currentX-1);
                nextLocation.setY(currentY);
            }
            else {
                nextLocation.setX(currentX);
                nextLocation.setY(currentY);
            }
        }
        else if (choice == 4){

            if (right.getIfValid()){
                nextLocation.setX(currentX+1);
                nextLocation.setY(currentY);
            }
            else {
                nextLocation.setX(currentX);
                nextLocation.setY(currentY);
            }
        }
    }
    else {
        cout<<"wrong type somehow!"<<endl;
        exit(1);
    }


}
class Ant: public Organism{
public:
    friend class Point;
    Ant():Organism(){setType('O');setToHaveAnt(); setToOccupied();}
    Ant(int x, int y):Organism(x,y){setType('O');setToHaveAnt(); setToOccupied();}

    virtual void move();
private:
};
void Ant::move() {
    setNextLocation();
    Point next = getNextLocation();
//    cout<<"old location: "<<getLocation().getX()<<" "<<getLocation().getY()<<endl;
//    cout<<"proposed next location: "<<next.getX()<<" "<<next.getY()<<endl;
    int currentSurvived = getDaysSurvived();
    int getBreed = getDaysSinceLastBreed();
    setToNotOccupied();
    setToNotAnt();
    setLocation(next.getX(), next.getY());
    setToOccupied();
    setToHaveAnt();
    setDaysSurvived(currentSurvived+1);
    setDaysSinceLastBreed(getBreed+1);
//    Add breed things
//    cout<<"new location: "<<getLocation().getX()<<" "<<getLocation().getY()<<endl;
}

class Doodlebug : public Organism{
public:
    friend class Point;
    Doodlebug():Organism(), whetherJustAte(false){setType('X');setToOccupied();}
    Doodlebug(int x, int y):Organism(x,y), whetherJustAte(false){setType('X');setToOccupied();}
    virtual void move();
private:
    bool whetherJustAte;
};
void Doodlebug::move() {
    setNextLocation();
    Point next = getNextLocation();
//    cout<<"old location: "<<getLocation().getX()<<" "<<getLocation().getY()<<endl;
//    cout<<"proposed next location: "<<next.getX()<<" "<<next.getY()<<endl;
    int currentSurvived = getDaysSurvived();
    int getBreed = getDaysSinceLastBreed();
    setToNotOccupied();
    setLocation(next.getX(), next.getY());
    setToOccupied();
    setDaysSurvived(currentSurvived+1);
    setDaysSinceLastBreed(getBreed+1);
//    cout<<"new location: "<<getLocation().getX()<<" "<<getLocation().getY()<<endl;
//    Add breed things
}
void printWorld(Organism* world[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            if (world[i][j] != nullptr){
                world[i][j]->display();
            }
            else {
                cout<<"- ";
            }
        }
        cout<<endl;
    }
}

int main(){
    srand(time(0));
    Organism* world[SIZE][SIZE];
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
        if (world[x][y] == nullptr){
            world[x][y] = new Doodlebug(x,y);

            initialDoodle += 1;
        }
    }
    while (initialAnt < INITIAL_ANT){
    int x = rand()%SIZE;
    int y = rand()%SIZE;
    if (world[x][y] == nullptr){
        world[x][y] = new Ant(x,y);

        initialAnt += 1;
    }
}
    cout<<"********** Game Begin **********"<<endl<<endl;
    cout<<"World Initialization with Ant# = "<<INITIAL_ANT<<" Doodlebug# = "<<INITIAL_DOODLE<<endl<<endl;
    printWorld(world);

    string s;
    getline(cin, s);
    int round = 1;
    cout<<"Round "<<round;

    for (int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            if (world[i][j] != nullptr && world[i][j]->getType() == 'X'){
                int newX = i;
                int newY = j;
//                cout<<"old location "<<i<<" "<<j<<endl;
                world[i][j]->move();
                if(world[newX][newY] != nullptr && !world[newX][newY]->getIfPlace()){
                    newX = world[i][j]->getLocation().getX();
                    newY = world[i][j]->getLocation().getY();
                    if(world[newX][newY] != nullptr && world[newX][newY]->getLocation().getIfValid()){
                        world[newX][newY] = world[i][j];
                        world[newX][newY]->setToPlace();
                        world[i][j] = nullptr;
                    }
//                    cout<<"mew location "<<newX<<" "<<newY<<endl;
//                    world[newX][newY] = world[i][j];
//                    world[newX][newY]->setToPlace();
//                    world[i][j] = nullptr;
                }
            }
        }
    }

    for (int i = 0; i < SIZE; i += 1){
        for (int j = 0; j < SIZE; j += 1){
            if (world[i][j] != nullptr && world[i][j]->getType() == 'O'){
                int newX = i;
                int newY = j;
                world[i][j]->move();
                if(world[newX][newY] != nullptr && !world[newX][newY]->getIfPlace()){
                    newX = world[i][j]->getLocation().getX();
                    newY = world[i][j]->getLocation().getY();
                    if(world[newX][newY] != nullptr && world[newX][newY]->getLocation().getIfValid()){
                        world[newX][newY] = world[i][j];
                        world[newX][newY]->setToPlace();
                        world[i][j] = nullptr;
                    }
//                    cout<<"mew location "<<newX<<" "<<newY<<endl;
//                    world[newX][newY] = world[i][j];
//                    world[newX][newY]->setToPlace();
//                    world[i][j] = nullptr;
                }
            }
        }
    }
    cout<<" with Ant# = "<<" "<<" Doodlebug# = "<<" "<<endl<<endl;
    printWorld(world);



    return 0;
}