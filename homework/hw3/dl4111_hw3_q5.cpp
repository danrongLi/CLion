#include <iostream>
#include <string>
using namespace std;

const double KILO_PER_POUND = 0.453592;
const double METER_PER_INCH = 0.0254;

int main() {

    double weightPounds, heightInches;

    cout<<"Please enter weight (in pounds): ";
    cin>>weightPounds;

    cout<<"Please enter height (in inches): ";
    cin>>heightInches;

    double weightKilo = weightPounds * KILO_PER_POUND;
    double heightMeter = heightInches * METER_PER_INCH;
    double bmiValue = weightKilo / (heightMeter * heightMeter);

    string weightStatus;

    if (bmiValue < 18.5){
        weightStatus = "Underweight";
    }
    else if ((bmiValue >= 18.5) && (bmiValue < 25)){
        weightStatus = "Normal";
    }
    else if ((bmiValue >= 25) && (bmiValue < 30)){
        weightStatus = "Overweight";
    }
    else if (bmiValue >= 30){
        weightStatus = "Obese";
    }
    cout<<"The weight status is: "<<weightStatus<<endl;

    return 0;
}
