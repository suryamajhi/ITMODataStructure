#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 0;
double c;

bool good(double m) {
	return m * m + sqrt(m) >= c;
}

int main(){
	cin >> c;
	
	double l = 0;
	double r = 1;
	
	cout << setprecision(20);
	
	while(!(good(r))) r *= 2; 
	
	for(int i = 0; i < 100; i++) {
		double m = (l + r) / 2;
		if(good(m)) {
			r = m;
		}else l = m;
	}
	cout << r;
}