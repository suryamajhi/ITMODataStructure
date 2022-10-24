#include<bits/stdc++.h>
using namespace std;

const int N = 0;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<long long>> prefixSum(n + 1, vector<long long> (m + 1, 0));
	int x;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> x;
			prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] + prefixSum[i + 1][j] - prefixSum[i][j] + x;
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		
		cout << prefixSum[rx][ry] + prefixSum[lx - 1][ly - 1] - prefixSum[lx - 1][ry] - prefixSum[rx][ly - 1] << "\n";
	}
}