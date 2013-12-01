#include <iostream>
#include <vector>
#include <climits>
#include <cstdio>

using namespace std;

vector<vector<int> > matrix;
vector<vector<int> > dist;

int main(){
    
    int n;
    
    cin >> n;
    
    matrix.resize(n, vector<int>(n, INT_MAX));
    
    dist.resize(n, vector<int>(n, INT_MAX));
    
    
    int i, j, k;
    
    for (i = 0; i < n; i++) {
     	
        for (j = 0; j < n; j++) {
         
            cin >> matrix[i][j];
            
            dist[i][j] = matrix[i][j];
            
            if (i == j)
                dist[i][j] = 0;
            
        }
        
    }
    
    for (k = 0; k < n; k++){
     	
        for (i = 0; i < n; i++) {
         
            for (j = 0; j < n; j++) {
                
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                 	
                    dist[i][j] = dist[i][k] + dist[k][j];
                    
                }
                
            }
            
        }
        
    }
    
    int Q;
    
    cin >> Q;
    
    while (Q--) {
     	
        int a, b;
        
        scanf("%d %d\n", &a, &b);
        
        printf("%d\n", dist[a-1][b-1]);
        
    }
    
}