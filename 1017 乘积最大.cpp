#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    
    int n, k;
    
    cin >> n >> k;
    
    string str;
    
    cin >> str;
    
    vector<vector<long long> > num(n, vector<long long>(n+1, 0));
    
    vector<vector<long long> > value(n, vector<long long>(k+1, 0));
    
    for (int l = 1; l <= n; l++) {
    
        for (int j = 0; j < n; j++) {
        
            if (j + l > n) continue;
            
            num[j][l] = num[j][l-1] * 10 + str[j+l-1] - '0';
            
            //cout << num[j][l] << endl;
        }
    }
    
    for (int i = 0; i < n; i++) {
        
        value[i][0] = num[i][n-i];
    }
    
    for (int c = 1; c <= k; c++) {
        
        for (int i = 0; i < n; i++) {
            
            long long max_cut = 0;
            
            for (int t = 1; i + t + c <= n; t++) {
                
                
                max_cut = max(max_cut, num[i][t] * value[i+t][c-1]);
            }
            
            value[i][c] = max_cut;
        }
        
    }
    
    cout << value[0][k] << endl;
    
    return 0;
    
}