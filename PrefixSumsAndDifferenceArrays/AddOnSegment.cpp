#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n + 1);
	vector<ll> diffArray(n, 0);
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++) {
		diffArray[i] = arr[i + 1] - arr[i];
	}
	
	int q;
	cin >> q;
	while(q--) {
		int l, r, d;
		cin >> l >> r >> d;
		diffArray[l - 1] += d;
		if(r < n)
			diffArray[r] -= d;
	}
	
	vector<ll> prefDiffSum(n);
	prefDiffSum[0] = diffArray[0];
	for(int i = 1; i < n; i++) {
		prefDiffSum[i] = prefDiffSum[i - 1] + diffArray[i];
	}
	
	for(auto x: prefDiffSum)
		cout << x << " ";
	
}