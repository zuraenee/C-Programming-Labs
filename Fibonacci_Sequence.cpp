// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n <= 1) {cout<< 0; return n;}
    if (n == 2) {cout << 1; return n;}

    int a = 0;
    int b = 1;
    for(long long i=2; i<= n-1; i++){
        int next = a + b;
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
