#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	
	int n;
	ll p;
	
	cin >> n >> p;
	
	ll num = 0LL;
	ll sum=0, cnt=0, s=0;
	
	vector<long> a(n);
	
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = x;
		sum += x;
	}
	if(p>=sum){
		cnt += n*(p/sum);
	}
	
	p = p%sum;
	int i=0,j=0, index=0, songs=n;
	while(j<2*n){
		s += a[j%n];
		while(s>=p){
			if(j-i+1<songs){
				songs = j-i+1;
				index=i%n;
			}
			s -= a[i%n];
			i++;
		}
		j++;
	}
	cout<<index+1<<" "<<cnt+songs;
}