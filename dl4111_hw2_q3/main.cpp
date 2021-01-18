#include <iostream>
using namespace std;

const int MINUTES_PER_HOUR = 60;
const int HOURS_PER_DAY = 24;

int main() {

    int daysJohnWorked, hoursJohnWorked, minutesJohnWorked;
    int daysBillWorked, hoursBillWorked, minutesBillWorked;

    cout<<"Please enter the number of days John has worked: ";
    cin>>daysJohnWorked;
    cout<<"Please enter the number of hours John has worked: ";
    cin>>hoursJohnWorked;
    cout<<"Please enter the number of minutes John has worked: ";
    cin>>minutesJohnWorked;
    cout<<"\n";

    cout<<"Please enter the number of days Bill has worked: ";
    cin>>daysBillWorked;
    cout<<"Please enter the number of hours Bill has worked: ";
    cin>>hoursBillWorked;
    cout<<"Please enter the number of minutes Bill has worked: ";
    cin>>minutesBillWorked;
    cout<<"\n";

    int combinedMinutes = (minutesJohnWorked + minutesBillWorked) % MINUTES_PER_HOUR;
    int carriedOverMinutes = (minutesJohnWorked + minutesBillWorked) / MINUTES_PER_HOUR;

    int combinedHours = (carriedOverMinutes + hoursJohnWorked + hoursBillWorked) % HOURS_PER_DAY;
    int carriedOverHours = (carriedOverMinutes + hoursJohnWorked + hoursBillWorked) / HOURS_PER_DAY;

    int combinedDays = daysJohnWorked + daysBillWorked + carriedOverHours;

    cout<<"The total time both of them worked together is: ";
    cout<<combinedDays<<" days, "<<combinedHours<<" hours and "<<combinedMinutes<<" minutes."<<endl;

    return 0;
}
