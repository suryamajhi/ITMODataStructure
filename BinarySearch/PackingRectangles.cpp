#include<bits/stdc++.h>
using namespace std;

const int N = 0;
long long  w, h, n;


bool good(long long x) {
	return (x/ w) * ( x/ h) >= n;
}

int main(){	
	cin >> w >> h >> n;
	
	long long l = 0; // l is bad
	long long r = 1; // l is good
	while(!good(r)) r *= 2;
	
	while(r > l + 1) {
		long long m = (r + l) / 2;
		if (good(m)) 
			r = m;
		else l = m;
	}
	
	cout << r << "\n";
}