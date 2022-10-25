#include "bits/stdc++.h"
using namespace std;

// Use binary search for first occurance of element and last occurance of element.
// Always maintain invariants.

void count_sort(vector<int> &p, vector<int> &c){
	int n = p.size();


	vector<int> cnt(n);
	for(auto x: c){
		cnt[x]++;
	}
	vector<int> p_new(n);
	vector<int> pos(n);
	pos[0] = 0;
	for(int i = 1; i < n; i++){
		pos[i] = pos[i - 1] + cnt[i - 1];
	}
	for(auto x: p){
		int i = c[x];
		p_new[pos[i]] = x;
		pos[i]++;
	}
	p = p_new;
}

vector<int> suffix_array(string &s){
	
	s += "$";
	int n = s.size();
	vector<int> p(n), c(n);
	{
		vector<pair<char, int>> a(n);
		for(int i = 0; i < n; i++) a[i] = {s[i], i};
		sort(a.begin(), a.end());

		for(int i = 0; i < n; i++) p[i] = a[i].second;

		c[p[0]] = 0;
		for(int i = 1; i < n; i++){
			if(a[i].first == a[i-1].first){
				c[p[i]] = c[p[i-1]];
			} else {
				c[p[i]] = c[p[i-1]] + 1;
			}
		}
	}
	int k = 0;
	while((1 << k) < n){
		// k => k + 1
		
		for(int i = 0; i < n; i++){
			p[i] = (p[i] - (1 << k) + n) % n;
		}


		count_sort(p, c);


		vector<int> c_new(n);
		c_new[p[0]] = 0;
		for(int i = 1; i < n; i++){
			pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k))% n]};
			pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k))% n]};

			if(prev == now){
				c_new[p[i]] = c_new[p[i-1]];
			} else {
				c_new[p[i]] = c_new[p[i-1]] + 1;
			}
		}
	
		c = c_new;
		k++;
	}

	return p;
}

bool good(string &t, string &s, vector<int> &p, int m){
	for(int i = 0; i < s.length(); i++){
		if(s[i] > t[(p[m] + i)%t.length()])
			return false;
		else if(s[i] < t[(p[m] + i)%t.length()]) 
			return true;
	}
	return true;
}



int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string t;
	cin >> t;
	vector<int> p;
	
	
	p = suffix_array(t);
	
	

	
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		int l = -1;           // a[l] < x 
		int r = t.size();     // a[r] >= x
		
		// while(r > l + 1){
		// 	int m = (r + l) / 2;
		// 	if(good(t, s, p, m)){
		// 		r = m;
		// 	} else l = m;

		// }
		while(r > l + 1){
			int m = (r + l) / 2;
			if(t.substr(p[m], s.size()).compare(s) < 0){
				l = m;
			} else r = m;
		}
		int lIndex = r;
		
		l = -1;     // a[l] <= x
		r = t.size(); // a[r] > x
		
		while(r > l + 1){
			int m = (r + l) / 2;
			if(t.substr(p[m], s.size()).compare(s)  <= 0){
				l = m;
			} else r = m;
		}
		int rIndex = r;
		
		cout << rIndex - lIndex << "\n";
	}
}