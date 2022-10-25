#include<bits/stdc++.h>
using namespace std;

const int N = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	
	for(int i = 0; i < n ;i++) {
		cin >> a[i];
	}
	
	while(k--) {
		int x;
		cin >> x;
		int l = -1; // a[l] <= x
		int r = n; // a[r] > x
		
		while( r > l + 1) {
			int m = (l + r) / 2;
			if(a[m] <= x) {
				l = m;
			} else r = m;
		}
		cout << l + 1 << "\n";
	}
}