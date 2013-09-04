#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

    int n;
    
    cin >> n;
    
    int max_value = INT_MIN;
    
    vector<int> value(n, 0);
    vector<int> num(n, 0);
    
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j <= i; j++) {
            
            cin >> num[j];
            if (i == 0) value[0] = num[0];
        }
        
        for (int j = i; j >= 0; j--) {
            
            if (j < i)
	            value[j] = value[j] + num[j];
            
           	if (j > 0)
                value[j] = max(value[j], value[j-1] + num[j]);
            
            if (i == n-1) max_value = max(max_value, value[j]);
            
        }
    }
    
    cout << max_value << endl;

    return 0;
}