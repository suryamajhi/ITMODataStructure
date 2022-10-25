#include<bits/stdc++.h>
using namespace std;

const int N = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	
	for(int i = 0; i < n ;i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	int k;
	cin >>k;
	
	while(k--) {
		int p, q;
		cin >> p >> q;
		int l = -1; // a[l] < p
		int r = n; // a[r] >= p
		
		while( r > l + 1) {
			int m = (l + r) / 2;
			if(a[m] < p) {
				l = m;
			} else r = m;
		}
		int rIndex = r;
		
		l = -1; // a[l] <= q
		r = n; // a[r] > q
		
		while( r > l + 1) {
			int m = (l + r) / 2;
			if(a[m] <= q) {
				l = m;
			} else r = m;
		}
		int lIndex = l;
		
		cout <<lIndex - rIndex + 1 << "\n";
	}
}