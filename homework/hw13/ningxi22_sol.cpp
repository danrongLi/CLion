#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Coordinate{
private:
    int x;
    int y;

public:
    int getX(){return x;}
    int getY(){return y;}
    void setX(int newX){x = newX;}
    void setY(int newY){y = newY;}
    Coordinate(){x=0.0; y=0.0;}
    Coordinate(int X, int Y) : x(X), y(Y) {}

};

class Organism{

private:
    Coordinate location;
    int turns_since_reproduced;

public:
    Coordinate getLocation(){return location;}
    void setLocation(int newX, int newY);
    int getTurnsSinceReproduced(){return turns_since_reproduced;}
    void setTurnsSinceReproduced(int new_turns_since_reproduced){turns_since_reproduced = new_turns_since_reproduced;}
    virtual void move(bool ant_locations[20][20], bool doodle_locations[20][20]){cout<<"error"<<endl;}
    Organism reproduce(bool ant_locations[20][20], bool doodle_locations[20][20]){}
    virtual bool die(bool bug_locations[20][20]){}
    Organism(){location.setX(0.0); location.setY(0.0);}
    Organism(int X, int Y) : location(X, Y), turns_since_reproduced(0){}
    vector<Coordinate> getSurroundingSquares(Coordinate location);
    bool isValidCoordinate(Coordinate coor);
    bool hasBug(Coordinate coor, bool bug_locations[20][20]);
};

bool Organism::hasBug(Coordinate coor, bool (*bug_locations)[20]) {
    return bug_locations[coor.getX()][coor.getY()];
}
bool Organism::isValidCoordinate(Coordinate coor) {
    int x = coor.getX();
    int y = coor.getY();
    if (-1 < x && x < 20 && -1 < y && y < 20){
        return true;
    }
    return false;
}
vector<Coordinate> Organism::getSurroundingSquares(Coordinate location) {
    vector<Coordinate> surrounding_squares;
    surrounding_squares.push_back(Coordinate(location.getX() + 1, location.getY()));
    surrounding_squares.push_back(Coordinate(location.getX() - 1, location.getY()));
    surrounding_squares.push_back(Coordinate(location.getX(), location.getY() + 1));
    surrounding_squares.push_back(Coordinate(location.getX(), location.getY() - 1));
    return surrounding_squares;
}
void Organism::setLocation(int newX, int newY){
    location.setX(newX);
    location.setY(newY);
}

// Ant Class

class Ant : public Organism{

public:
    Ant(int X, int Y) : Organism(X, Y) {}
    virtual void move(bool ant_locations[20][20], bool doodle_locations[20][20]);
    virtual bool die(bool ant_locations[20][20]);
    Ant(){}
    Ant reproduce(bool ant_locations[20][20], bool doodle_locations[20][20]);
};
void Ant::move(bool ant_locations[20][20], bool doodle_locations[20][20]){
    srand(time(0));
    int direction = rand() % 4;
    vector <Coordinate> surrounding_squares = getSurroundingSquares(getLocation());
    Coordinate proposed_move = surrounding_squares[direction];
    if (isValidCoordinate(proposed_move)){
        if(!doodle_locations[proposed_move.getX()][proposed_move.getY()] && !ant_locations[proposed_move.getX()][proposed_move.getY()]){
            ant_locations[getLocation().getX()][getLocation().getY()] = false;
            setLocation(proposed_move.getX(), proposed_move.getY());
            ant_locations[getLocation().getX()][getLocation().getY()] = true;
        }
    }
}
Ant Ant::reproduce(bool ant_locations[20][20], bool doodle_locations[20][20]){
    setTurnsSinceReproduced(getTurnsSinceReproduced() + 1);
    if (getTurnsSinceReproduced() > 2){ // are we ready to make babies?
        vector<Coordinate> surrounding_squares = getSurroundingSquares(getLocation());
        for (Coordinate coord : surrounding_squares){ // try all 4 surrounding squares
            if (isValidCoordinate(coord)){ // is the square on the board?
                if (!ant_locations[coord.getX()][coord.getY()] && !doodle_locations[coord.getX()][coord.getY()]){
                    // is the square empty?
                    ant_locations[coord.getX()][coord.getY()] = true;
                    setTurnsSinceReproduced(0);
                    return Ant(coord.getX(),coord.getY());
                }
            }
        }
    }
    return Ant(-1,-1);
}
bool Ant::die(bool ant_locations[20][20]){
    return !ant_locations[getLocation().getX()][getLocation().getY()];
}

// Doodle Class

class Doodle : public Organism{

public:
    Doodle(int X, int Y) : Organism(X, Y), turns_since_ate(0) {}
    virtual void move(bool ant_locations[20][20], bool doodle_locations[20][20]);
    Doodle(){}
    Doodle reproduce(bool ant_locations[20][20], bool doodle_locations[20][20]);
    virtual bool die(bool doodle_locations[20][20]);
    int getTurnsSinceAte(){return turns_since_ate;}
    void setTurnsSinceAte(int new_turns_since_ate){turns_since_ate = new_turns_since_ate;}

private:
    int turns_since_ate;
};
// doodles move
// return vector of surrounding coordinates ... given a Coordinate.
// loop over the coordinate Vector one at a time
// first check if it's a valid square
// if there's an ant in a coordinate, move there ... update the ant and doodle boards
// Randomly pick a number between 1 and 4 ... select the coordinate of the vector corresponding to that number
// if there are no doodles in the adjacent square and it is on the board, go there.
void Doodle::move(bool ant_locations[20][20], bool doodle_locations[20][20]){
    vector <Coordinate> surrounding_squares = getSurroundingSquares(getLocation()); // get sur squares
    for(Coordinate coor : surrounding_squares){
        if (isValidCoordinate(coor)){
            if (hasBug(coor, ant_locations)){ // doodle eats an ant
                doodle_locations[getLocation().getX()][getLocation().getY()] = false;
                setLocation(coor.getX(), coor.getY());
                doodle_locations[getLocation().getX()][getLocation().getY()] = true;
                ant_locations[getLocation().getX()][getLocation().getY()] = false;
                setTurnsSinceAte(0);
                return;
            }
        }
    }
    srand(time(0));
    int direction = rand() % 4;
    Coordinate proposed_move = surrounding_squares[direction];
    if (isValidCoordinate(proposed_move)){
        if (!doodle_locations[proposed_move.getX()][proposed_move.getY()]){
            doodle_locations[getLocation().getX()][getLocation().getY()] = false;
            setLocation(proposed_move.getX(), proposed_move.getY());
            doodle_locations[getLocation().getX()][getLocation().getY()] = true;
            setTurnsSinceAte(getTurnsSinceAte() + 1);
            return;
        }
    }
    setTurnsSinceAte(getTurnsSinceAte() + 1);
}
// reproduction
// increment turns since reproduced
// if ready to reproduce
// get surrounding coordinates
// check surrounding coordinates for validity and then for presence of bugs
// if there's an empty valid square,
// reproduce there and reset the counter
Doodle Doodle::reproduce(bool ant_locations[20][20], bool doodle_locations[20][20]){
    setTurnsSinceReproduced(getTurnsSinceReproduced() + 1);
    if (getTurnsSinceReproduced() > 7){ // are we ready to make babies?
        vector<Coordinate> surrounding_squares = getSurroundingSquares(getLocation());
        for (Coordinate coord : surrounding_squares){ // try all 4 surrounding squares
            if (isValidCoordinate(coord)){ // is the square on the board?
                if (!ant_locations[coord.getX()][coord.getY()] && !doodle_locations[coord.getX()][coord.getY()]){
                    // is the square empty?
                    doodle_locations[coord.getX()][coord.getY()] = true;
                    setTurnsSinceReproduced(0);
                    return Doodle(coord.getX(),coord.getY());
                }
            }
        }
    }
    return Doodle(-1,-1);
}
bool Doodle::die(bool doodle_locations[20][20]){
    if (getTurnsSinceAte() > 2){
        doodle_locations[getLocation().getX()][getLocation().getY()] = false;
        return true;
    }
    else{
        return false;
    }
}

// global functions

Coordinate generateLegalCoordinate(bool ant_locations[20][20], bool doodle_locations[20][20]){
    srand(time(0));
    int x, y;
    while (true){
        x = rand() % 20;
        y = rand() % 20;
        if (!ant_locations[x][y] && !doodle_locations[x][y]){
            Coordinate new_bug_location(x,y);
            return new_bug_location;
        }
    }
}

void printBoard(bool ant_locations[20][20], bool doodle_locations[20][20]){
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            if(!ant_locations[i][j] && !doodle_locations[i][j]){
                cout << "-";
            }
            else if(ant_locations[i][j]){
                cout << "O";
            }
            else{
                cout << "X";
            }
        }
        cout << endl;
    }
}

int main(){

    // initialize the board
    // 0 will mean that there is no bug ... 1 will mean that there is a bug
    bool ant_locations[20][20];
    bool doodle_locations[20][20];
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            ant_locations[i][j] = false;
            doodle_locations[i][j] = false;
        }
    }

    // make initial bugs ... put them in their vectors and also update the board
    vector<Ant> ants;
    vector<Doodle> doodles;

    for (int i = 0; i < 5; i++){
        Coordinate next_coordinate = generateLegalCoordinate(ant_locations, doodle_locations);
        doodle_locations[next_coordinate.getX()][next_coordinate.getY()] = true;
        doodles.push_back(Doodle(next_coordinate.getX(),next_coordinate.getY()));
    }
    for (int i = 0; i < 100; i++){
        Coordinate next_coordinate = generateLegalCoordinate(ant_locations, doodle_locations);
        ant_locations[next_coordinate.getX()][next_coordinate.getY()] = true;
        ants.push_back(Ant(next_coordinate.getX(),next_coordinate.getY()));
    }

    int round = 0;
    Doodle baby_doodle;
    Ant baby_ant;
    int num_orig_left;
    while(true){
        cout << "Press the enter key to continue the simulation." << endl;
        cout << "Enter any character and then press the enter key to end the simulation." << endl;
        if (cin.get()== '\n'){
            cout << "Round: " << round << endl;
            // loop over doodles
            num_orig_left = doodles.size();
            for(int i = 0; i < num_orig_left; i++){
                // doodle moves ... update boards in function
                doodles[i].move(ant_locations, doodle_locations);
                // doodle breeds ... update board in function
                baby_doodle = doodles[i].reproduce(ant_locations, doodle_locations);
                if (baby_doodle.isValidCoordinate(baby_doodle.getLocation())){
                    doodles.push_back(baby_doodle);
                }
                // doodle dies ... update board in function & update doodle vector outside of function
                if (doodles[i].die(doodle_locations)){
                    doodles.erase(doodles.begin() + i);
                    i--;
                    num_orig_left--;
                }
            }
            // loop over ants
            num_orig_left = ants.size();
            for(int i = 0; i < num_orig_left; i++){
                // ant dies ... update board in function & update ant vector outside of function
                if (ants[i].die(ant_locations)){
                    ants.erase(ants.begin() + i);
                    i--;
                    num_orig_left--;
                }
                // ants move ... update board in function
                ants[i].move(ant_locations,doodle_locations);
                // ants breed ... update board in function
                baby_ant = ants[i].reproduce(ant_locations, doodle_locations);
                if (baby_ant.isValidCoordinate(baby_ant.getLocation())){
                    ants.push_back(baby_ant);
                }
            }
            // print board
            printBoard(ant_locations, doodle_locations);
            cout << "there are " << ants.size() << " ants and " << doodles.size() << " doodles" << endl;
            round++;
        }
        else{
            break;
        }
    }
    return 0;
}