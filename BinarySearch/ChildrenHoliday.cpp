#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 0;

ll m, n;
vector<ll> t, y, z;

bool good(ll time) {
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		sum += z[i] * (time/(z[i] * t[i] + y[i])) + min(time %(z[i] * t[i] + y[i])/t[i], z[i]);
	}
	return sum >= m;
}

int main(){
	cin >> m >> n;
	t.resize(n);
	y.resize(n);
	z.resize(n);
	
	for(int i = 0; i < n; i++) {
		cin >> t[i] >> z[i] >> y[i];
	}
	
	ll l = -1; // l is bad
	ll r = 1;
	while(!good(r)) r *= 2;
	
	while(r > l + 1) {
		ll m = (r + l) / 2;
		if (good(m)) 
			r = m;
		else l = m;
	}
	cout << r << "\n";
	
	ll ss = 0;
	for(int i = 0; i < n; i++) {
		ll x = z[i] * (r/(z[i] * t[i] + y[i])) + min(r %(z[i] * t[i] + y[i])/t[i], z[i]);
		ss += x;
		if (ss > m){
			cout << m - (ss - x) << " ";
			while(++i < n) {
				cout << 0 << " ";
				i++;
			}
		}else cout << x << " ";
	}	
}