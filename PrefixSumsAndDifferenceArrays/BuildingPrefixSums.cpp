#include<bits/stdc++.h>
using namespace std;

const int N = 0;

int main(){
	int n;
	cin >> n;
	
	vector<long long> prefixSum(n + 1, 0);
	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	cout << "0" << " ";
	for(int i = 0; i < n; i++) {
		prefixSum[i + 1] += prefixSum[i] + arr[i];
		cout << prefixSum[i + 1] << " ";
	}
}