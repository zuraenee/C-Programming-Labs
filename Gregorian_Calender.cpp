#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int y, m, d, z, w;
    cin >> y >> m >> d;
    int dayofweek;
    if (m < 3){
        z = y-1;
        w = 0;
    }
    else{
        z = y;
        w = 2;
    }
    dayofweek = ( (23*m/9) + d + 4 + y + (z/4) - (z/100) + (z/400) - w ) % 7;
    cout << dayofweek << endl;
    vector<string> names = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    cout << names[dayofweek];
    return 0;
}

// [10 points] In the Gregorian calendar, the day of the week of any given date can be computed by the following formula:

// dayofweek = ( [23m/9] + d + 4 + y + [z/4] - [z/100] + [z/400] - w ) mod 7
// where
// dayofweek is 0-6 (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
// d is the day (1-31)
// m is the month (1-12)
// y is the year
// z = y-1 if m<3, else = y
// w = 0 if m<3, else = 2
// [...] is rounding the number inside the square brackets down to the nearest integer
// X mod Y means the remainder when X is divided by Y
// Write a program that reads the year, month and day from the standard input, then prints out the day of the week (in words).
// Sample input:
// 2021
// 10
// 5

// Sample output:
// Tuesday
