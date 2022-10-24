    #include<bits/stdc++.h>
     
    using namespace std;
     
    const int N = 0;
     
     
    int get(int p[], int size[], int a){
    	if (p[a]!= a){
    		p[a] = get(p,size, p[a]);
    	}
    	return p[a];
    }
     
    void unionn(int p[], int size[], int a,int b, vector<pair<int,int>>& minmax, int length[]) {
    	a = get(p, size, a);
    	b = get(p, size, b);
    	// if (size[a] > size[b]){
    	// 	swap(a, b);
    	// }
    	p[a] = b;
    	size[b] += size[a];
    	
    	minmax[b].first = min(minmax[b].first, minmax[a].first);
    	minmax[b].second = max(minmax[b].second, minmax[a].second);
    	if (a != b){
    		length[b] += length[a];
    	}
    }
     
     
    int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
     
    	int n, m;
    	cin >> n >> m;
    	
    	int p[n];
    	int size[n];
    	
    	vector<pair<int, int>> minmax;
    	int length[n];
    	
    	for(int i = 0; i < n; i++){
    		p[i] = i;
    		size[i] = 1;
    		minmax.push_back(make_pair(i, i));
    		length[i] = 1;
    	}
    	
    	while (m--){
    		string command;
    		cin >> command;
    		
    		if (command == "get"){
    			int x;
    			cin >> x;
    			int index = get(p, size, x - 1);
    			cout << minmax[index].first + 1 << " " << minmax[index].second + 1 << " " << length[index] << endl;
    		} else if (command == "union") {
    			int x, y;
    			cin >> x >> y;
    			unionn(p, size, x - 1, y - 1, minmax, length);
    		}
    	}
    }