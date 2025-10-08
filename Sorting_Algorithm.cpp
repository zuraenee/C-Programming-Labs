// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void printarray(vector<int>& arr){
    for (int i : arr) {
      cout << i;
    }
    cout << "\n";
}
int main() {
    int length;
    cin >> length;
    vector<int> arr(length);
    for(int i=0; i<length; i++){
        int x;
        cin >> x;
        arr[i] = x;
    }
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            if (arr[i] < arr[j]){
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                printarray(arr);
            }
        }
    }
    
    return 0;
}
