#include <iostream>
#include <vector>

const int SONG_DIVIDE = 300;

using namespace std;

class Merchandise{
public:
    virtual double getPoints() = 0;

private:

};
class Songs: public Merchandise{
public:
    Songs(double newDuration = 0.0){duration = newDuration;}
    virtual double getPoints(){
        return -(duration/SONG_DIVIDE);
    }
private:
    double duration;
};

class Advertisements: public Merchandise{
public:
    Advertisements()= default;
    virtual double getPoints(){
        return 1.00;
    }
private:
};

class User{
public:
    User(vector<Merchandise*> newHeard = vector<Merchandise*>()){heard = newHeard;}

    vector<Merchandise*>* getHeard() {return &heard;}

    bool isPositive(){
        double points = 0.0;
        for (int i = 0; i < heard.size(); i += 1){
            points += heard[i]->getPoints();
        }
        cout<<points<<endl;
        if (points > 0.0){
            return true;
        }
        else {
            return false;
        }
    }
private:
    vector<Merchandise*> heard;
};



int main() {
    Songs a(600.00);
    User b;
    Advertisements c, d, e;
    b.getHeard()->push_back(&a);
    b.getHeard()->push_back(&c);
    b.getHeard()->push_back(&d);
    b.getHeard()->push_back(&e);
    bool result = b.isPositive();
    if (result){
        cout<<"positive"<<endl;
    }
    else{
        cout<<"negative"<<endl;
    }


    return 0;
}
