#include <iostream>
#include <cmath>
using namespace std;

int factorial (int num);

int main() {

    int n, k, i, nFact, kFact, n_kFact, kComb;
    cout<<"Please n and k, n >= k:"<<endl;
    cin>>n>>k;

    nFact = factorial (n);
    kFact = factorial (k);
    n_kFact = factorial (n-k);


    kComb = nFact / (kFact * n_kFact);

    cout<<n<<" choose "<<k<<" is "<<kComb;

    return 0;
}

int factorial (int num){
    int factRes, i;
    factRes = 1;
    for (i = 1; i <= num; i += 1){
        factRes *= i;
    }
    return factRes;
}

