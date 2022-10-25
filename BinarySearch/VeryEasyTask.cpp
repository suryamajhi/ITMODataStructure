#include<bits/stdc++.h>
using namespace std;

const int N = 0;

int n, x , y;


bool good(int t) {
	t -= min(x, y);
	if (t < 0) return 0;
	return (t/x + t/ y + 1) >= n;
}

int main(){
	cin >> n >> x >> y;
	
	int l = 0; // l is bad
	int r = 1;
	while(!good(r)) r *= 2;
	
	while(r > l + 1) {
		int m = (r + l) / 2;
		if (good(m)) 
			r = m;
		else l = m;
	}
	cout << r;
}