#include <iostream>
#include <cmath>
using namespace std;

int factorial (int num);
int kCombinations (int n, int k);

int main() {

    int n, k, i,  kComb;
    cout<<"Please n and k, n >= k:"<<endl;
    cin>>n>>k;

    kComb = kCombinations(n, k);

    cout<<n<<" choose "<<k<<" is "<<kComb;

    return 0;
}

int kCombinations (int n, int k){
    int nFact, kFact, n_kFact;
    nFact = factorial (n);
    kFact = factorial (k);
    n_kFact = factorial (n-k);
    return (nFact/(kFact*n_kFact));
}


int factorial (int num){
    int factRes, i;
    factRes = 1;
    for (i = 1; i <= num; i += 1){
        factRes *= i;
    }
    return factRes;
}

