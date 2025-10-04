#include <iostream>
using namespace std;
int main() {
    int x, y , k;
    cin >> x >> y >> k;
    double output;
    output = x + y + k;
    cout << output/3;

    // int x, output, count;
    // while(cin >> x){
    //     output += x;
    //     count++;
    // }
    // float avg = output/count;
    // cout << avg;
    return 0;
}


// [10 points] Write a program that reads a list of integers from the standard input, and output their average (as a floating point number) to the standard output. The number of integers to be read is unknown in advance. (In a linux terminal you can signal the end of input by typing Ctrl-D.)

// You can assume the input is correct (i.e. actually integers) and each of the integers fit inside a C++ int.

// For an easier version, assume the input always contain 3 integers. This will allow you to pass some test cases and get a partial score on Hackerrank. For the full version you will need something not yet covered (how to test the state of cin).

// Sample input 0:
// 6 8 9

// Sample output 0:
// 7.6667

// Sample input 1:
// 6 8 9 4

// Sample output 1:
// 6.75
