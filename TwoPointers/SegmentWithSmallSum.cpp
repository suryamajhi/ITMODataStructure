#include<bits/stdc++.h>
using namespace std;

const int N = 0;

int main(){
	ios::sync_with_stdio(false);
	
	int n;
	long long s;
	
	cin >> n >> s;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0, x = 0, res = 0;
	for(int r = 0; r < n; r++){
		x += a[r];
		while(x > s) {
			x -= a[l];
			l++;
		}
		res = max(res, r -l + 1);
	}
	cout << res;
}