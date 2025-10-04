#include <iostream>
using namespace std;

double sigma(int n, int j) {

	double sum = 0;
	int denom = j; // 8k+j
	for(int k=0; k<=n; k++) {
		int sixteenpower = 1;
		for(int i=0;i<n-k;i++)
			sixteenpower = (sixteenpower * 16) % denom;
		sum += sixteenpower * 1.0 / denom;
		denom += 8;
//		sum -= (int)sum;
//		while (sum<0) sum++;
	}

	double sixteenf = 1.0/16;
	for(int k=n+1;k<=n+10;k++) {
		sum += sixteenf/denom;
		sixteenf /= 16;
		denom += 8;
	}
//	sum -= (int)sum;
	return sum;
}

int main() {

	int n;
	cin >> n;

	double x = 4*sigma(n,1) - 2*sigma(n,4) - sigma(n,5) - sigma(n,6);
	while(x<0) x++;
	int d = 16*(x - (int)x);

	if (d<10) cout << d;
	else cout << (char)(d-10+'a');
	cout << endl;
}

// (Note: treat this as an optional question - only for those who find the above questions "too simple". It requires a bit of math knowledge explained - but not quite fully - in the second link below.)

// [20 points] You know the number pi:

// pi = 3.141592653589...
// When expressed in hexadecimal (base 16), it looks like this:
// pi = 3.243f6a8885a3...
// It turns out there is a way to calculate directly any digit of pi, without first calculating all the digits before it. Unfortunately it only works in base 16, not base 10. Here is the algorithm. Implement it into a C++ program. It should read an integer n, and print the n-th digit of pi. Use the symbols 0-9 and a-f. (Following the notation in the above link, the first digit after the dot is the "0-th" digit.)
