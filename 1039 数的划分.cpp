#include <iostream>
#include <vector>
#include <string>

using namespace std;

int partition(int n, int k, int max_num) {

    if (k >= n || k <= 0 || n <= 0) return 0;
   
    vector<vector<vector<int> > >counts(n+1, vector<vector<int> >(k+1, vector<int>(n+1 ,0)));
    
    counts[0][0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int c = 0; c <= k; c++) {
            for (int j = c; j <= n; j++) {                
                for (int t = 0; t * i <= j; t++) {
                    if (c - t  < 0 || j-t*i < 0) continue;
                    counts[i][c][j] += counts[i-1][c-t][j-t*i];
                }
                
            }
        }
    }
    
    return counts[n][k][n];
}

int main(){
    
    int n, k;
    
    cin >> n >> k;
    
    cout << partition(n, k, n) << endl;
    
    return 0;
    
}