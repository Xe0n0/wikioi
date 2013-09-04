#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int x1, y1;
    int x2, y2;
    int n, m;
    
    cin >> n >> m;
    
    cin >> x1 >> y1 >> x2 >> y2;
    
    vector<vector<long long> > count(n+1, vector<long long>(m+4,0));
    
    count[x1][y1+1] = 1;
    
    for (int i = x1+1; i <= x2; i++) {
        
        for (int j = 0; j < m; j++) {
        
            count[i][j+2] += count[i-2][j+1] + count[i-2][j+3] +
                    count[i-1][j] + count[i-1][j+4];
            
        }
        
    }
    
    cout << count[x2][y2+1] << endl;

    return 0;
}