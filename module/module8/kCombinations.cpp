#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n, k, i, nFact, kFact, n_kFact, kComb;
    cout<<"Please n and k, n >= k:"<<endl;
    cin>>n>>k;

    nFact = 1;

    for (i = 1; i <= n; i += 1){
        nFact *= i;
    }

    kFact = 1;

    for (i = 1; i <= k; i += 1){
        kFact *= i;
    }

    n_kFact = 1;

    for (i = 1; i <= (n-k); i += 1){
        n_kFact *= 1;
    }

    kComb = nFact / (kFact * n_kFact);

    cout<<n<<" choose "<<k<<" is "<<kComb;

    return 0;
}
