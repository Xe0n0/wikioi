#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int>dist;
vector<vector<int> > matrix;
vector<char> slots;
vector<bool> S;

int main(){
 	
    int n;
    
    cin >> n;
    
    dist.resize(257, INT_MAX);
    
    matrix.resize(257, vector<int>(257, INT_MAX));
    
    slots.resize(n);
    
    S.resize(257, false);
    
    for (int i = 0; i < n; i++) {
     	
        char a, b; 
        
        int d;
        
        cin >> a >> b >> d;
        
        slots[i] = a;
        
        matrix[a][b] = min(matrix[a][b], d);
        matrix[b][a] = min(matrix[a][b], d);
        
    }
    
    
    
    for (int i = 0; i < n; i++) {
     	dist[slots[i]] = matrix[slots[i]]['Z'];
    }
    
    dist['Z'] = 0;
    
    int u = 0;
    
    for (int i = 0; i < n; i++) {
     	
        int d = INT_MAX;
                
        for (int j = 0; j < n; j++) {
         	
            int idx = slots[j];
            
            if (!S[idx] && dist[idx] < d) {
                
                d = dist[idx];
                u = idx;
                
            }
            
        }
        
        S[u] = 1;
        
        if (u >= 'A' and u < 'Z') {
         	  
            break;
        }
        
        for (int j = 0; j < n; j++) {
         	int idx = slots[j];
            int w = dist[u];
            if (!S[idx] && matrix[u][idx] < INT_MAX and w + matrix[u][idx] < dist[idx]) {
             	dist[idx] = w + matrix[u][idx];   
            }
        }
        
    }
    
    cout << (char)u << ' ' << dist[u] << endl;
    
    
    return 0;
}