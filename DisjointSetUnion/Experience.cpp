#include<bits/stdc++.h>

using namespace std;


struct disjoinSet {
    
    vector<int> p, rank, experiance;
    
    
    void init(int n) {
        p.resize(n+1);
        rank.resize(n+1);
        experiance.resize(n+1);
        
        for(int i = 1; i <= n; i++){
            p[i] = i;
            rank[i] = 1;
        }   
    }
    
    int get(int a) {
        if (p[a] == a){
            return a;
        }
        return get(p[a]);
    }
    
    void unionn(int a, int b) {
        a = get(a);
        b = get(b);
        if(a == b) {
            return;
        }
        if (rank[a] < rank[b]){
            swap(a, b);
        }
        p[b] = a;
        experiance[b] -= experiance[a];
        if(rank[a] == rank[b]) {
            rank[a]++;
        }
    }
    
    int getExperiance(int a) {
        if(p[a] == a)
            return experiance[a];
        return experiance[a] + getExperiance(p[a]);
    }
};
 
int main(){
	int n, m;
	cin >> n >> m;
	
	disjoinSet ds;
        
    ds.init(n);
	
	while (m--){
		string command;
		cin >> command;
        
        if(command == "add"){
            int x, v;
            cin >> x >> v;
            ds.experiance[ds.get(x)] += v;
        } else if(command == "join"){
            int x, y;
            cin >> x >> y;
            ds.unionn(x, y);
        } else {
            int x;
            cin >> x;
            cout << ds.getExperiance(x) << endl;
        }
	}
}