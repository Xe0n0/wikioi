#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string myminus(string a, string b) {
    
    
    int i = a.size() - 1, j = b.size() - 1;
    
    string r;
    
    while (i >= 0 && j >= 0) {
    	if (a[i] >= b[j])
            r.push_back(a[i] - b[j] + '0');
        else {
            
            r.push_back(10 + a[i] - b[j] + '0');
            if (i > 0) a[i-1] = a[i-1] - 1;
            
        }
        
        
        
        i--;
        j--;
    }
    if (a[0] > '0')
    while (i >=0 ) {
    	
        r.push_back(a[i]);
        i--;
        
    }
    
    reverse(r.begin(), r.end());
    
    return r;
    
}

int main(){
    
    string a, b;
    
    cin >> a >> b;
       
    if (a.size() > b.size()) cout << myminus(a, b) << endl;
    else if (a.size() < b.size()) {
     	string r = myminus(b, a);
        r.insert(r.begin(), '-');
        cout << r << endl;
    }
    
    else {
        for (int i = 0; i < a.size(); i++) {
            
            if (a[i] != b[i]) {
                
                if (a[i] > b[i]) {
                 	cout << myminus(a,b) << endl;
                    return 0;
                }
                else {
                 	string r = myminus(b, a);
                    cout << '-' << r << endl;
                    return 0;
                }
                
            }
            
        }
        
        cout << '0' << endl;
    }
    
    
    return 0;
}