#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool> > adj;

void search(vector<int> &state, int &r, int idx) {
    
    if (idx == state.size()) {
     	r++;   
        return;
    }
    
    for (int i = 1; i <= 4; i++) {
     	
        bool has_same = false;
        
        for (int j = 0; j < adj.size(); j++) {
            if (adj[j][idx] && state[j] == i) {
             	has_same = true;
                break;
            }
        }
        
        if (!has_same) {
         	state[idx] = i;
            search(state, r, idx+1);
            state[idx] = 0;
        }
        
    }
}

int main() {
 	
    int n;
    
    cin >> n;
    
    adj.resize(n, vector<bool>(n, false));
    
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < n; j++) {
        	
            bool t;
            cin >> t;
            adj[i][j] = t;
            
        }
        
    }
    
    int r = 0;
    vector<int>state(n, 0);
    
    search(state, r, 0);
    
    cout << r << endl;
    
    
    return 0;
}