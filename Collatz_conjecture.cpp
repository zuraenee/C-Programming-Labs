#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    
    // //basic collatz conjecture
    // int x, total;
    // cin >> x;
    // cout << x << " ";
    // while(x != 1){
    //     if (x % 2 == 0){
    //         x = x/2;
    //     }
    //     else {
    //         x = x* 3 + 1;
    //     }
    //     cout << x << " ";
    // }
    
    //complex average collatz conjecture
    int x, y, total;
    cin >> x >> y;
    if(y<x){
        cout << "error, first number has to be smaller than second number" << endl;
    }
    int temp, max;
    float topRatio=0;
    int bestN, topMax;
    float ratio;
    for (int i=x; i<= y; i++){
        temp = i;
        max = i;
        cout << temp << " ";
        while(temp > 1){
            if(temp % 2 == 0){
                temp = temp/2;
            }
            else{
                temp = temp*3 + 1;
            }
            
            if (max <= temp){
                max = temp;
            }
            cout << temp << " ";
        }
        ratio = static_cast<double>(max) / i;
        if(topRatio < ratio){
            topMax = max;
            bestN = i;
            topRatio = ratio;
        }
        cout << "max " << max;
        cout << endl;
    }
    
    cout << bestN << " " << topMax << " " << setprecision(5) << topRatio;
    return 0;
}

// [15 points] Returning to the 3n+1 problem (Q1), we want to find starting numbers that lead to very large intermediate values in the sequence, relative to the value of the starting number. For example, starting with 10, the maximum ever reached is 16 (see Q1) so it is 1.6 times the starting value. If starting with 7, however, the maximum reached is 52 (7-22-11-34-17-52-26-13-40-20-10-5-16-8-4-2-1), and the ratio is 52/7 = 7.42857.

// Given two integers a and b, where a < b, the program finds the number within the range [a..b] that produces the maximum such ratio, and prints that starting number, the maximum, and the ratio. For simplicity, you can assume there is only one maximum within the given range.

// Sample input:
// 1 10

// Sample output:
// 7 52 7.42857
