#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, INF = 1e18 + 5;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	
	int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
 
    int gcd = 0, mn = INF;
    int l = 0, r = 0;
    while (r < n)
    {
        if (a[r] == 1)
            mn = 1;
        gcd = __gcd(gcd, a[r]);
        if (gcd == 1)
        {
            int ed = r, _gcd = a[ed];
            while (__gcd(_gcd, a[ed - 1]) != 1)
                _gcd = __gcd(_gcd, a[--ed]);
 
            l = ed;
            gcd = _gcd;
            mn = min(mn, r - l + 2);
        }
        r++;
    }
    cout << (mn == INF ? -1 : mn) << "\n";
    return 0;
	
}