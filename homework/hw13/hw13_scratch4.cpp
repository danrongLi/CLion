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

private:
    Organism* system[SIZE][SIZE];
};

