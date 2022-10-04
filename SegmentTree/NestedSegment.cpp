#include<bits/stdc++.h>
using namespace std;

const int N = 0;

typedef int item;


struct segtree {
	
	int size;
	vector<item> values;
	
	item NEUTRAL_ELEMENT = 0;
	
	item merge(item a, item b) {
		return a + b;
	}
	
	item single(int v) {
		return v;
	}
	
	void init(int n) {
		size = 1;
		while(size < n) size *= 2;
		values.resize(2 * size);
	}
	
	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int)a.size()) {
				values[x] = single(a[lx]);
			}
			return;
		}
		
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		values[x] = merge(values[2 * x + 1], values[2 * x + 2]);

	}
	
	void build(vector<int> &a) {
		build(a, 0, 0, size);	
	}
	
	void set(int i, int v, int x, int lx, int rx) {	
		if (rx - lx == 1) {
			values[x] = single(v);
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2*x + 1, lx, m);
		} else {
			set(i, v, 2 * x + 2, m , rx);
		}
		values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
	}
	
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
	
	item calc(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return NEUTRAL_ELEMENT;
		if (lx >= l && rx <= r) return values[x];
		int m = (lx + rx) / 2;
		item s1 = calc(l, r , 2 * x + 1, lx, m);
		item s2 = calc(l, r, 2 * x + 2, m, rx);
		return merge(s1, s2);
	}
	
	
	item calc(int l, int r) {
		return calc(l, r, 0, 0, size);
	}
	
};

int main(){
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	segtree st;
	st.init(2 * n);
	
	vector<int> a(2 * n);
	vector<int> visited(n, INT_MAX);
	vector<int> result(n);
	
	for(int i = 0; i < 2 * n; i++) {
		int x;
		cin >> x;
		if (visited[x - 1] != INT_MAX) {
			result[x - 1] = st.calc(visited[x - 1], i);
			st.set(visited[x - 1], 1);
		} else {
			visited[x -1] = i;
		}
	}
	for(int i = 0; i < n; i++) cout << result[i] << " ";
	
	return 0;
	
}