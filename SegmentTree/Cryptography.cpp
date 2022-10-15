#include<bits/stdc++.h>
using namespace std;

const int N = 0;
int r_modulo;

struct item {
	long long p, q, r, s;
};


struct segtree {
	
	int size;
	vector<item> values;
	
	item NEUTRAL_ELEMENT = {1, 0, 0, 1};
	
	item merge(item a, item b) {
		return {
			(a.p * b.p + a.q * b.r) % r_modulo, (a.p * b.q + a.q * b.s) % r_modulo,
			(a.r * b.p + a.s * b.r) % r_modulo, (a.r * b.q + a.s * b.s) % r_modulo
		};
	}
	
	item single(item v) {
		return v;
	}
	
	void init(int n) {
		size = 1;
		while(size < n) size *= 2;
		values.resize(2 * size);
	}
	
	void build(vector<item> &a, int x, int lx, int rx) {
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
	
	void build(vector<item> &a) {
		build(a, 0, 0, size);	
	}
	
	void set(int i, item v, int x, int lx, int rx) {	
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
	
	void set(int i, item v) {
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
	
	int r_mod, n, m;
	cin >> r_mod >> n >> m;
	r_modulo = r_mod;
	
	vector<item> a(n);
	
	int p, q, r, s;
	for(int i = 0; i < n; i++) {
		cin >> p >> q >> r >> s;
		a[i] = {p, q, r, s};
	}
	
	segtree st;
	st.init(n);
	
	st.build(a);
	
	while(m--) {
		int l, r;
		cin >> l >> r;
		item result = st.calc(l - 1, r);
		cout << result.p << " " << result.q << "\n" << result.r << " " << result.s << "\n\n";
	}
	return 0;
	
}