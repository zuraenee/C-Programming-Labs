#include <iostream>
using namespace std;
int main() {
    int x;
    cin >> x;
    cout << x << " ";
    while (x != 1){
        if (x % 2 == 0){
            x = x/2;
        }
        else {
            x = x*3 + 1;
        }
        cout << x << " ";
    }

    return 0;
}


// [10 points] The 3n+1 problem, also known as the Collatz conjecture. Starting with any positive integer, repeatedly do the following: if the number is odd, multiply it by 3 and then add 1. If it is even, divide it by 2. It is conjectured that any starting number will eventually reach 1, but it is not proven.
// Write a program that reads the starting integer from the standard input, and print the list of integers produced, including the starting integer and the ending 1, with a space between any two numbers. For example:
// Sample input:
// 10

// Sample output:
// 10 5 16 8 4 2 1
