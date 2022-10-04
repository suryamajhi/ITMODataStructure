#include<bits/stdc++.h>
using namespace std;

const int N = 0;

typedef int item;


struct segtree {
	
	int size;
	vector<item> values;
	
	item NEUTRAL_ELEMENT = INT_MIN;
	
	item merge(item a, item b) {
		return max(a, b);
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
	
	int first_above(int v,int l, int x, int lx, int rx) {
		if ( values[x] < v) return -1;
		if ( rx <= l) return -1;
		if (rx - lx == 1) return lx;
		int m = (lx + rx) / 2;
		int res = first_above(v, l, 2 * x + 1, lx, m);
		if (res == -1) {
			res = first_above(v, l, 2 * x + 2, m, rx);
		}
		return res;
	}
	
	
	int first_above(int k, int l) {
		return first_above(k, l, 0, 0, size);
	}
	
};

int main(){
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	segtree st;
	st.init(n);
	
	vector<int> a(n);
	
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	st.build(a);
	
	while(m--) {
		int op;
		cin >> op;
		
		if (op == 1) {
			int i, v;
			cin >> i >> v;
			st.set(i, v);
		} else {
			int k, l;
			cin >> k >> l;
			cout << st.first_above(k, l) << "\n";
		}
	}
	
	return 0;
	
}