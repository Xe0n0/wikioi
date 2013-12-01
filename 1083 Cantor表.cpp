#include <iostream>
#include <vector>

using namespace std;

int main(){

    
    int n;
    
    cin >> n;
    
    
    vector<int>num(n, 0);
    
    
    num[0] = 1;
    
    int count = 1;
    
	bool leftToRight = false;
    
    for (int i = 1; i < n; i++) {
        
     	
        for (int j = i; j >= 0; j--) {
            
            
            num[j] = i - j + 1;
            
        }
        
        count += i + 1;
        
        if (count >= n) {
        
            if (leftToRight) {
                
             	cout << num[i - (count - n)] << '/' << (i + 1) - (count - n) << endl;
                
            }
            else {
             	
                
                cout << num[(count - n)] << '/' << count - n + 1 << endl;
            }
            break;
            
        }
        
        leftToRight = !leftToRight;
        
    }
    
    
    return 0;
}