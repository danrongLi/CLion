#include <iostream>
using namespace std;

const double PROMOTION_RATE = 0.5;
const double ADDITIONAL_PROMO = 0.1;

int main() {

    double firstItemPrice, secondItemPrice;
    char haveClubCard;
    double taxRate;

    cout<<"Enter price of first item: ";
    cin>>firstItemPrice;

    cout<<"Enter price of second item: ";
    cin>>secondItemPrice;

    cout<<"Does customer have a club card? (Y/N): ";
    cin>>haveClubCard;

    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>taxRate;

    double basePrice = firstItemPrice + secondItemPrice;
    double priceAfterPromotion = basePrice;

    if (firstItemPrice <= secondItemPrice){
        priceAfterPromotion = firstItemPrice * PROMOTION_RATE + secondItemPrice;
    }
    else{
        priceAfterPromotion = firstItemPrice + secondItemPrice * PROMOTION_RATE;
    }

    double priceAfterCard = priceAfterPromotion;

    switch (haveClubCard){
        case 'Y':
        case 'y':
            priceAfterCard = priceAfterPromotion * (1-ADDITIONAL_PROMO);
            break;

        case 'N':
        case 'n':
            priceAfterCard = priceAfterPromotion;
            break;

        default:
            cout<<"Unable to understand whether you have a club card or not."<<endl;
            cout<<"I guess you might not have the club card. The price without 10% off is shown as below:"<<endl;
            break;
    }

    double priceAfterTax = priceAfterCard * (1+taxRate/100);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout<<"Base price: "<<basePrice<<endl;
    cout<<"Price after discounts: "<<priceAfterCard<<endl;

    cout.precision(5);
    cout<<"Total price: "<<priceAfterTax<<endl;

    return 0;
}
