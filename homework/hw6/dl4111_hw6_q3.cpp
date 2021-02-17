#include <iostream>
using namespace std;

double eApprox(int n);

int main() {

    cout.precision(30);

    for (int n = 1; n <= 15; n += 1){
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }
    return 0;
}

double eApprox(int n){

    double currentTerm;
    double sumTerms = 0.0, numerator = 1.0, currentDenominator = 1.0;
    int count;

    for (count = 1; count <= n; count += 1){
        currentTerm = numerator / currentDenominator;
        sumTerms +=  currentTerm;
        currentDenominator *= count;
    }
    return sumTerms;
}