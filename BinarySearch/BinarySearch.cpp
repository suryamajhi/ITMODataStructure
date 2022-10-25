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
		int l = -1;
		int r = n;
		while( r > l + 1) {
			int m = (l + r) / 2;
			if(a[m] < x) {
				l = m;
			} else r = m;
		}
		if(a[r] == x) 
			cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}