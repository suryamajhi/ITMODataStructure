    #include<bits/stdc++.h>
    using namespace std;
    const int N = 0;
     
     
    int get(int p[], int a){
    	if (p[a]!= a){
    		p[a] = get(p, p[a]);
    	}
    	return p[a];
    }
     
    void unionn(int p[],int a,int b) {
    	a = get(p, a);
    	b = get(p, b);
    	p[a] = b;
    }
     
     
    int main(){
    	int n, m;
    	cin >> n >> m;
    	
    	int p[n];
    	for(int i = 0; i < n; i++){
    		p[i] = i;
    	}
    	
    	while (m--){
    		string command;
    		int x, y;
    		cin >> command;
    		cin >> x >> y;
    		
    		if (command == "get"){
    			if (get(p, x - 1 ) == get(p, y - 1)) {
    				cout << "YES"<< endl; 
    			} else {
    				cout << "NO" << endl;
    			}
    		} else if (command == "union") {
    			unionn(p, x - 1, y - 1);
    		}
    	}
    }