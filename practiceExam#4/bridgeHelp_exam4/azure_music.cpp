#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Audio {
public:
    virtual double getPoints() const = 0;
};

class Songs : public Audio {
private:
    double _duration;
public:
    Songs() : _duration { 0.00 } {}
    Songs(double duration) : _duration { duration } {}

    double getPoints() const {
        return (std::floor(_duration / 300) * (-1.00));
    }
};

class Advertisements : public Audio {
public:
    double getPoints() const {
        return 1.00;
    }
};

class User {
private:
    std::vector<Audio*> heard;
public:
    std::vector<Audio*>* getHeard() {
        return &heard;
    }

    bool isPositive() const {
        cout<<std::accumulate(heard.begin(), heard.end(), 0.00, [](double acc, const Audio* audio){ return acc + audio->getPoints();})<<endl;
        return std::accumulate(heard.begin(), heard.end(), 0.00, [](double acc, const Audio* audio){ return acc + audio->getPoints();}) > 0.00;
    }
};

int main(int argc, char const *argv[]) {
    Songs a(600.00);
    User b;
    Advertisements c, d, e;
    b.getHeard()->push_back(&a);
    b.getHeard()->push_back(&c);
    b.getHeard()->push_back(&d);
    b.getHeard()->push_back(&e);
    std::cout << (b.isPositive() ? "Positive" : "Negative") << std::endl;
    return 0;
}
