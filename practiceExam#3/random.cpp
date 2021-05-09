#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main(){
    int matrix[2][2];
    for (int i = 0; i < 2; i += 1){
        for (int j = 0; j < 2; j += 1){
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < 2; i += 1){
        for (int j = 0; j < 2; j += 1){
            if (matrix[i][j] == 0){
                matrix[i][j] = 1;
            }
            else if (matrix[i][j] == 1){
                matrix[i][j] = 2;
            }
            else if (matrix[i][j] == 2){
                matrix[i][j] = 3;
            }
        }
    }
    for (int i = 0; i < 2; i += 1){
        for (int j = 0; j < 2; j += 1){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}