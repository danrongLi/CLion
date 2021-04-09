#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

const int SMALL_LIMIT = 0;
const int BIG_LIMIT = 19;
const int SIZE = 20;
const int ANT_BREED_STEPS = 3;
const int DOODLE_BREED_STEPS = 8;
const int DOODLE_STARVE_STEPS = 3;
const int INITIAL_DOODLE = 5;
const int INITIAL_ANT = 100;

class Organism{
public:
    virtual void move() = 0;
    virtual void breed() = 0;

    int getXLocation() const;
    int getYLocation() const;
    int getTimeStepsSurvived() const;
    bool getWhetherReadyToBreed() const;

    void setXLocation(int newXLocation);
    void setYLocation(int newYLocation);
    void setTimeStepsToZero(int newTime) {timeStepsSurvived = newTime;}
    void setToBreed(bool ready) {readyToBreed = ready;}


private:
    int xLocation;
    int yLocation;
    int timeStepsSurvived;
    bool readyToBreed;

};
void Organism::setXLocation(int newXLocation) {
    xLocation = newXLocation;
}
void Organism::setYLocation(int newYLocation) {
    yLocation = newYLocation;
}
int Organism::getXLocation() const {
    return xLocation;
}
int Organism::getYLocation() const {
    return yLocation;
}
int Organism::getTimeStepsSurvived() const {
    return timeStepsSurvived;
}
bool Organism::getWhetherReadyToBreed() const {
    return readyToBreed;
}


class Ant : public Organism{
public:
    virtual void move();
    virtual void breed();
    void setToBreed();
    Ant();

private:
    bool beingEaten;
};

class DoodleBug : public Organism{
public:
    virtual void move();
    virtual void breed();
    DoodleBug();

private:
    bool justAteOne;
    bool starvedToDeath;
    int timeStepsBeingStarved;

};

void Ant::setToBreed() {
    if (getTimeStepsSurvived() == 3){
        Organism::setToBreed(true);
        setTimeStepsToZero(0);
    }
}


int main(){
    vector<vector<Organism*>> world (SIZE, vector<Organism*>(SIZE, nullptr));

    int numDoodle = INITIAL_DOODLE;
    int numAnt = INITIAL_ANT;



    DoodleBug bug1;
    Ant ant1;
    char temp;

    do{
        bug1.move();
        ant1.move();
        cout<<"Again?"<<endl;
        cin>>temp;
    }while (temp == 'y');


}


