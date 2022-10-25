#include<bits/stdc++.h>
using namespace std;

const int N = 0;




bool good(double x, vector<int>& a, int k) {
	int s = 0;
	for(int i = 0; i < a.size(); i++) {
		s += floor(a[i]/ x);
	}
	return s >= k;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);

	for(int i = 0; i < n; i++) cin >> a[i];
		
	double l = 0; // l is good
	double r = 1e8; // r is bad
	
	cout << setprecision(20);
	for(int i = 0; i < 100; i++) {
		double m = (l + r) / 2;
		if( good(m, a, k)) 
			l = m;
		else r = m;
	}
	
	cout << l << "\n";
}	