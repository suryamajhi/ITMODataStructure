#include<bits/stdc++.h>
using namespace std;

const int N = 0;

int get(int p[], int a){
	if (p[a]!= a){
		return p[a] = get(p, p[a]);
	}
	return p[a];
}
 
void unionn(int p[],int a,int b) {
	a = get(p, a);
	b = get(p, b);
	p[a] = b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<string> ans;
	string command[k];
	pair<int, int> queries[k];
	int p[n+ 1];
	for(int i = 1; i <= n; i++){
		p[i] = i;
	}
	
	for(int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		
	}
	for(int i = 0; i < k; i++) {
		string cmd;
		int u, v;
		cin >>cmd;
		cin >> u >> v;
		command[i] = cmd;
		queries[i] = {u, v};
	}
	
	for(int i = k - 1; i >= 0; i--) {
		string cmd;
		pair<int, int> pair;
		cmd = command[i];
		pair = queries[i];
		
		if (cmd == "ask") {
			if (get(p, pair.first) == get(p, pair.second)) {
				ans.push_back("YES");
			} else ans.push_back("NO");
		} else if(cmd == "cut") {
			unionn(p, pair.first, pair.second);
		}
	}
	for(int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << endl;
	}
	
}