#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

    int m, n;
    
    cin >> m >> n;
    
    vector<vector<int> >num(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num[i][j];
        }
    }
    
    vector<vector<vector<int> > > value(n+m-1, vector<vector<int> >(n, vector<int>(n, 0)));
    
    
    
    for (int i = 1; i < n + m - 2; i++) {
        for (int j = 0; j < n - 1 && j <= i; j++) {
            for (int k = j + 1; k < n && k <= i; k++) {
                
                if (i - j >= m || i-k >= m) continue;
                
                value[i][j][k] = max(value[i][j][k], value[i-1][j][k]);
                
                if (j > 0) {
                    value[i][j][k] = max(value[i][j][k], value[i-1][j-1][k]);
                    value[i][j][k] = max(value[i][j][k], value[i-1][j-1][k-1]);
                }
                
                if (k - j > 1)
                    value[i][j][k] = max(value[i][j][k], value[i-1][j][k-1]);
                    
                value[i][j][k] += num[i-j][j] + num[i-k][k];
                
            }
        }
    }
    
    cout << value[n+m-3][n-2][n-1] << endl;

    return 0;
}