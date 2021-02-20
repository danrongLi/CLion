#include <iostream>
#include <string>
using namespace std;

const int DAYS_IN_WEEK = 7;
const int MONTHS_IN_YEAR = 12;
int printMonthCalender(int numOfDays, int startingDay);
bool ifItsLeapYear(int yearInput);
void printYearCalender(int year, int startingDay);

int main() {

    int yearInput, startingDayInput;
    cout<<"Enter a year: ";
    cin>>yearInput;
    cout<<"Enter the starting day for that year: ";
    cin>>startingDayInput;

    printYearCalender(yearInput, startingDayInput);

    return 0;
}

int printMonthCalender(int numOfDays, int startingDay){
    cout<<"Mon\tTue\tWed\tThr\tFri\tSat\tSun"<<endl;

    int spaceCount, dayCount;

    for (spaceCount = 1; spaceCount <= (startingDay-1); spaceCount += 1){
        cout<<" \t";
    }
    for (dayCount = 1; dayCount <= (DAYS_IN_WEEK-startingDay+1); dayCount += 1){
        cout<<dayCount<<"\t";
    }
    cout<<endl;
    int currentCount;
    for (currentCount = dayCount; currentCount <= numOfDays; currentCount += 1){
        cout<<currentCount<<"\t";
        if (((currentCount-(DAYS_IN_WEEK-startingDay+1))%DAYS_IN_WEEK==0) && (currentCount != numOfDays)){
            cout<<endl;
        }
    }
    cout<<endl;

    int remainDay = (numOfDays-(DAYS_IN_WEEK-startingDay+1))%DAYS_IN_WEEK;
    if (remainDay == 7){
        return 1;
    }
    else {
        return remainDay;
    }
}

bool ifItsLeapYear(int yearInput){
    if (((yearInput%4 == 0) && (yearInput%100 != 0)) || (yearInput%400 == 0)){
        return true;
    }
    else {
        return false;
    }
}

void printYearCalender(int year, int startingDay){
    string monthOfYear;
    int monthCount;
    int numOfDays;
    for (monthCount = 1; monthCount <= MONTHS_IN_YEAR; monthCount += 1){
        switch (monthCount) {
            case 1:
                monthOfYear = "January";
                numOfDays = 31;
                break;
            case 2:
                monthOfYear = "February";
                if (ifItsLeapYear(year)){
                    numOfDays = 29;
                }
                else {
                    numOfDays = 28;
                }
                break;
            case 3:
                monthOfYear = "March";
                numOfDays = 31;
                break;
            case 4:
                monthOfYear = "April";
                numOfDays = 30;
                break;
            case 5:
                monthOfYear = "May";
                numOfDays = 31;
                break;
            case 6:
                monthOfYear = "June";
                numOfDays = 30;
                break;
            case 7:
                monthOfYear = "July";
                numOfDays = 31;
                break;
            case 8:
                monthOfYear = "August";
                numOfDays = 31;
                break;
            case 9:
                monthOfYear = "September";
                numOfDays = 30;
                break;
            case 10:
                monthOfYear = "October";
                numOfDays = 31;
                break;
            case 11:
                monthOfYear = "November";
                numOfDays = 30;
                break;
            case 12:
                monthOfYear = "December";
                numOfDays = 31;
                break;
            default:
                cout<<"month cannot be > 12"<<endl;
        }
        cout<<endl;
        // I added this empty line because the Appendix A results
        // indicated the black region before the calender output
        cout<<monthOfYear<<" "<<year<<endl;
        startingDay = printMonthCalender(numOfDays, startingDay)+1;
    }
}