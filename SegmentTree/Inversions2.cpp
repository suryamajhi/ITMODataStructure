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
	
	int find(int k, int x, int lx, int rx) {
		if (rx - lx == 1) {
			set(lx, 0);
			return lx + 1;
		}
		int m = (lx + rx) / 2;
		int sl = values[2 * x + 2];
		if (k < sl) {
			return find(k, 2 * x + 2, m, rx);

		} else {
			return find(k - sl, 2 * x + 1, lx, m);
		}
		
	}
	
	int find(int k) {
		return find(k, 0, 0, size);
	}
	
};

int main(){
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	vector<int> a(n, 1);
	vector<int> v(n);
	vector<int> res(n);
	
	segtree st;
	st.init(n);
	
	st.build(a);
	
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	for(int i = n - 1; i >= 0; i--) {
		res[i] = st.find(v[i]);
	}
	
	for(int i = 0; i < n; i ++) {
		cout << res[i] << " ";
	}
	
	return 0;
}