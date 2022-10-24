#include<bits/stdc++.h>
using namespace std;

const int N = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> prefixSums(n + 1, 0);
	int x;
	for(int i = 0; i < n; i++) {
		cin >> x;
		prefixSums[i + 1] = prefixSums[i] ^ x;
	}
	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << (prefixSums[r] ^ prefixSums[l - 1]) << endl;
	}
}