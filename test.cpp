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
    
    matrix.resize(257, vector<int>(257, 0));
    
    slots.resize(n);
    
    S.resize(257, false);
    
    for (int i = 0; i < n; i++) {
        
        char a, b; 
        
        int d;
        
        cin >> a >> b >> d;
        
        slots[i] = a;
        
        matrix[a][b] = d;
        matrix[b][a] = d;
        
    }
    
    
    dist['Z'] = 0;
    
    for (int i = 0; i < n; i++) {
        
        int d = INT_MAX;
        
        int u;
        
        for (int j = 0; j < n; j++) {
            
            int idx = slots[j];
            
            if (!S[idx] && dist[idx] < d) {
                
                d = dist[idx];
                u = idx;
                
            }
            
        }
        
        S[u] = 1;
        cout << u << endl;
        if (u >= 'A' and u < 'Z') {
            cout << (char)u << ' ' << dist[u] << endl;  
            return 0;
        }
        
        for (int j = 0; j < n; j++) {
            int idx = slots[j];
            int w = dist[u];
            if (!S[idx] && matrix[u][idx] > 0 and w + matrix[u][idx] < dist[idx]) {
                dist[idx] = w + matrix[u][idx];   
            }
        }
        
    }
    return 0;
}