#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>

using namespace std;

int main() {
    
 
    
    vector<int>num;
    
    int temp;
    
    while (cin >> temp != 0){
     	num.push_back(temp);   
    }
    
    vector<int>best;
    vector<int>up;
    int count = 0;
    
    for (int i = 0; i < (int)num.size(); i++) {
        
        vector<int>::iterator it = upper_bound(best.begin(), best.end(), num[i], greater<int>());
        
        if (it == best.end()) {
            best.push_back(num[i]);
        }
        else
            *it = num[i];
        
        it = upper_bound(up.begin(), up.end(), num[i]);
        
        if (it == up.end()) {
            if (!up.empty() && up.back() == num[i]) continue;
         	up.push_back(num[i]);
        }
        else {
            
            if (it == up.begin() && *(it-1) == num[i]) continue;
            *it = num[i];
        }
    }
    
    cout << best.size() << endl << up.size() << endl;
    
    return 0;
    
}
	