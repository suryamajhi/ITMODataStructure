#include<bits/stdc++.h>
using namespace std;

const int N = 0;

struct segtree {
	
	int size;
	vector<long long> sums;
	
	void init(int n) {
		size = 1;
		while(size < n) size *= 2;
		sums.assign(2 * size, 0LL);
	}
	
	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int)a.size()) {
				sums[x] = a[lx];
			}
			return;
		}		
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];

	}
	
	void build(vector<int> &a) {
		build(a, 0, 0, size);	
	}
	
	void set(int i, int v, int x, int lx, int rx) {	
		if (rx - lx == 1) {
			sums[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2*x + 1, lx, m);
		} else {
			set(i, v, 2 * x + 2, m , rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
	
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
	
	long long sum(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && rx <= r) return sums[x];
		int m = (lx + rx) / 2;
		long long s1 = sum(l, r , 2 * x + 1, lx, m);
		long long s2 = sum(l, r, 2 * x + 2, m, rx);
		return s1 + s2;
	}
	
	
	long long sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
	
	int get(int i, int x, int lx, int rx) {
		if(rx - lx  == 1) return sums[x];
		int m = (lx + rx) / 2;
		if (i < m)
			return get(i, 2 * x + 1, lx, m);
		else return get(i, 2 * x + 2, m , rx);
	}
	
	int get(int i) {
		return get(i, 0, 0, size);
	}
	
};

int main(){
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	segtree st;
	st.init(n);
	
	segtree st2;
	st2.init(n);
	
	vector<int> a(n);
	vector<int> b(n);
	int in;
	
	bool alternate = true;
	for(int i = 0; i < n; i++){
		cin >> in;
		
		if (alternate) {
			a[i] = in;
			b[i] = -in;
			alternate = false;
		} else {
			a[i] = -in;
			b[i] = in;
			alternate = true;
		}
	}
	
	st.build(a);
	st2.build(b);
	
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int op;
		cin >> op;
		if (op == 0) {
			int i, j;
			cin >> i >> j;
			
			int p = st.get(i - 1);
			if (p < 0) {
				st.set(i - 1, -j);
				st2.set(i - 1, j);
			} else {
				st.set(i - 1, j);
				st2.set(i - 1, -j);
			}
			
		} else {
			int l, r;
			cin >> l >> r;
			int x = st.get(l - 1);
			if (x < 0)
				cout << st2.sum(l - 1, r) << "\n";	
			else cout << st.sum(l - 1, r) << "\n";
		}
	}
	
	return 0;
	
}