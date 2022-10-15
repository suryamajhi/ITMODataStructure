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
	vector<int> b(m);
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	
	vector<int> res(m);
	
	int i = 0, j = 0, k = 0;
	
	while(i < n || j < m) {
		if(j == m || (i < n && a[i] < b[j])) {
			k++;
			i++;
		} else {
			res[j] = i;
			k++;
			j++;
		}
	}
	for(int x: res) {
		cout << x << " ";
	}
	
}