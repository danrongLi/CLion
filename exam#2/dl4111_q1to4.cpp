#include <iostream>
using namespace std;
int main()
{
    int sum = 0;
    for (int a = 0; a <= 6; a++) {
        for (int b = a + 1; b <= 7; b++) {
            for (int c = b + 1; c <= 8; c++) {
                for (int d = c + 1; d <= 9; d++) {
                    sum++;

                }
            }
        }
    }
    cout << sum;
}
/*
 * Danrong Li dl4111
 *
 *
 * Question 1
 *
 * Proof. By mathematical induction on n.
 *
 * Base case:
 * n = 1, a1 = 1,
 * n = 2, a2 = 1,
 * n = 3, a3 = a1+a2 = 2
 *
 * a1 = 1 >= (sqrt2)^1
 * a2 = 1 >= (sqrt2)^2
 * a3 = 2 >= (sqrt2)^3
 *
 * so the theorem holds true for the base.
 *
 * Inductive step: Suppose for every positive integer, ak >= (sqrt2)^k.
 * We will show that a(k+1) >= (sqrt2)^(k+1)
 *
 * a(k+1) = ak + a(k-1) By definition given
 *        >= (sqrt2)^k + (sqrt2)^(k-1) By inductive hypothesis
 *        = (sqrt2)^(k+1) * ((sqrt2)^(-1) + (sqrt2)^(-2)) By algebra
 *        >= (sqrt2)^(k+1) since ((sqrt2)^(-1) + (sqrt2)^(-2)) > 1
 *
 * Thus, we showed that a(k+1) >= (sqrt2)^(k+1).
 *
 * Question 2
 *
 * a. 10*9*8*7
 * Because the digit would have 10 choices, the second digit would have 9 choices,
 * the third digit would have 8 choices and the last digit would have 7 choices.
 *
 // b. 210
 // See the code above.
 *
 * Question 3
// P(X=1) = P(both even at the 1st toss) = 3/6 * 3/6 = 1/4
// P(X=2) = P(both even at the 2nd toss) = (1 - 1/4) * (3/6) *(3/6) = (3/4) * (1/4) = 3/16
// P(X=3) = P(both even at the 3rd toss) = (1- 1/4 - 3/16) * (3/6) * (3/6) = 9/16 * 1/4 = 9/64
// P(X=4) = all other possibilities = 1 -1/4 -3/16 -9/64 = 27/64
// So the distribution of X is {(1,1/4),(2,3/16),(3,9/64),(4,27/64)}
// E(X) = 1*P(X=1) + 2*P(X=2) + 3*P(X=3) + 4*P(X=4)
// = 1/4 + 6/16 + 27/64 + 27*4/64
// = 16/64 + 24/64 + 27/64 + 27*4/64
// = (67 + 108)/64 = 175/64
 * Question 4
 *
 * a. T(n) = theta(log*log(n))
 * In the outer loop, i increment by *2 from 1 to log(n). So that the last term is log(n).
 * In the inner loop, j increment by +1 from 1 to i, i is the log(n).
 * Since we have 1+2+3+...+log(n), we have the complexity of theta(log*log(n)) --> wrong
 *
//The num of inner for-loop iterations depends on the index of i
// For simplicity, assume n is a power of 2
//Since i doubles by 2 each time, i=1,2,4,8,...,log(n)
//So the total number of inner for-loop iterations = 1+2+4+8+...+(log(n)/2) + log(n)
// = (2*(log(n)/2)-1) + log(n) = 2log(n) -1
// The count+=1 operation nested inside is Theta(1)
//Hence, the overall complexity of func = Theta(2log(n) -1) = Theta(log(n))
 *
 * b. the return type of first10Squares is int*, but Ben is returning int arr[]
 * Address of stack memory associated with local variable 'arr' returned
 *
 * the change: changes are commented below with symbol of // (both main function & first10Square)
 *
 * int* first10Squares(){
    int* arr = new int[10]; // changed here
    for (int i = 0; i < 10; i ++){
        arr[i] = (i+1)*(i+1);
    }
    return arr;
}
int main(){
    int* arr;
    arr = first10Squares();

    for (int i = 0; i < 10; i ++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    delete[] arr; //changed here
    arr = nullptr; //changed here
    return 0;
}
 *
 *
 *
 *
 *
 *
 *
 */
