#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double radius, area;

    cout<<"Please enter the radius:"<<endl;

    cin>>radius;

    area = M_PI* (radius * radius);

    cout<<"The area of the circle with radius of "<<radius<<" is "<<area<<endl;

    return 0;
}
