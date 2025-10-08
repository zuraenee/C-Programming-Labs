// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
    string input, output;
    cin >> input;
    for (char &c : input) c = toupper(static_cast<unsigned char>(c));
    bool isPalindrome= true;
    bool isMirrored = true;
    unordered_map<char, char> dict = {
        {'A','A'}, {'E','3'}, {'3','E'}, {'J','L'}, {'L','J'},
        {'S','2'}, {'2','S'}, {'Z','5'}, {'5','Z'},
        {'H','H'}, {'I','I'}, {'M','M'}, {'O','O'}, {'T','T'},
        {'U','U'}, {'V','V'}, {'W','W'}, {'X','X'}, {'Y','Y'},
        {'1','1'}, {'8','8'}
    };
    
    
    int i=0,j=input.length()-1;
    
    
    while(i<=j){
        if (input[i] != input[j]){
            isPalindrome = false;
        }
        if (dict[input[i]] == input[j]){
            isMirrored = true;
        }
        else isMirrored = false;
        ++i;
        --j;
    }
    if (!isMirrored && !isPalindrome){
        cout << input << " -- is not a palindrome.";}
    else if (!isMirrored && isPalindrome){
        cout << input << " -- is a regular palindrome.";}
    else if (isMirrored && !isPalindrome){
        cout << input << " -- is a mirrored string.";}
    else {
        cout << input << " -- is a mirrored palindrome.";}
    return 0;
}
