#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 0;

int cnt[100001];
int num;

void add(int x) {
	cnt[x]++;
	if(cnt[x] == 1) num++;
}

void remove(int x){
	cnt[x]--;
	if(cnt[x] == 0) num--;
}

int k;

bool good(){
	return num <= k;
}


int main(){
	ios::sync_with_stdio(false);
	
	int n;
	
	cin >> n >> k;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0;
	ll res = 0;
	for(int r = 0; r < n; r++){
		add(a[r]);
		while(!good()) {
			remove(a[l]);
			l++;
		}
		
		// i..r, i = 0..l-1
		res += r - l + 1;
	}
	cout << res;
}