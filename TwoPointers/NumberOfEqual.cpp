#include<bits/stdc++.h>
using namespace std;

const int N = 0;

int main(){
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	map<int, int> b;
	int x;
	for(int i = 0; i < m; i++) {
		cin >> x;
		if(b.count(x)){
			b.insert({x, b[x]++});
		}else b.insert({x, 1});
	}
	long long res = 0;
	
	for(int i = 0; i < n; i++) {
		if(b.count(a[i])) {
			res += b[a[i]];
		}
	}	
	
	cout << res;
}