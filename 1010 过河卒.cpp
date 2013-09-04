#include <iostream>
#include <vector>
#include <cmath>
#include <stdint.h>


using namespace std;

int main() {

    int m, n;
    int x, y;
    
    cin >> n >> m;
    cin >> x >> y;
    
    
    vector<int64_t> count(m+1, 0);
    
    for (int i = 0; i <= n; i++) {
    
        for (int j = 0; j <= m; j++) {
                        
             if (i == 0 && j == 0) {
                 count[j] = 1;
             }
             else if (j > 0) {
                 count[j] = count[j] + count[j-1];
             }
            
             if (x == i && y == j ||
                 abs(i-x) == 1 && abs(j-y) == 2 ||
                 abs(i-x) == 2 && abs(j-y) == 1)
             {
                count[j] = 0;   
             }
        }
    }
    
    cout << count[m] << endl;
    
    return 0;
}