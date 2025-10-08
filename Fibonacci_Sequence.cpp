// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n <= 1) {cout<< 0; return n;}
    if (n == 2) {cout << 1; return n;}

    long long a = 0;
    long long b = 1;
    for(long long i=2; i<= n-1; i++){
        long long next = a + b;
        a = b;
        b = next;
    }
    cout << b;
    return 0;
}

// int fibonacci(int n){
//     //recursion simple fibonacci
//     if(n==1) return n;
//     return fibonacci(n-1) + fibonacci(n-2);
// }

//max is 99 before it goes negative on 100 
