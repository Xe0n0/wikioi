#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
 	int N;
    
    cin >> N;
    
    vector<int>num(N, 0);
    
    for (int i = 0; i < N; i++) {
     	cin >> num[i];   
    }
    
    vector<int>len(N, 0);
    vector<int>best;
    
    for (int i = 0; i < N; i++) {
        
        vector<int>::iterator it = upper_bound(best.begin(), best.end(), num[i]);
        
        if (it == best.end()) {
            best.push_back(num[i]);
        }
        else
            *it = num[i];
        
    }
    
    cout << best.size();
    
    return 0;
    
}