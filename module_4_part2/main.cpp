#include <iostream>
using namespace std;

const double PI = 3.14;
int main() {

    double radius, area;

    cout<<"Please enter the radius:"<<endl;

    cin>>radius;

    area = PI* (radius * radius);

    cout<<"The area of the circle with radius of "<<radius<<" is "<<area<<endl;

    return 0;
}
