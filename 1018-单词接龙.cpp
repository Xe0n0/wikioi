#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void search(string state, map<string, int> &counts, int& max_r, int r) {
 	
    map<string, int>::iterator it = counts.begin();
    
    
    for (;it != counts.end(); it++) {
     	
        
        if (it->second >= 2) {
         	continue;	   
        }
        
        for (int i = 1; i < it->first.size() - 1; i++) {
         	
            
            
            if (state.size() > i && state.substr(state.size() - i, i) == it->first.substr(0, i)) {
                
                //string temp = state;
                //state = it->first;
                counts[it->first] += 1;
                search(it->first, counts, max_r, r+it->first.size() - i);
                counts[it->first] -= 1;
                //state = temp;
            	break;    
            }
            
            
        }
        
    }
    
    max_r = max(max_r, r);
    
}

int main(){
 	
    
    int n;
    cin >> n;
        
    string temp;
    
    map<string, int> counts;
    
    for (int i = 0; i < n; i++) {
        
     	cin >> temp;
        counts.insert(make_pair(temp, 0));
        
    }
    
    char a;
    
    cin >> a;
    
    int max_r = 0;
    
    map<string, int>::iterator it;
    
    for (it = counts.begin(); it != counts.end(); it++) {
     	
        if ((it->first)[0] == a) {
         	string temp = it->first;
            counts[temp] += 1;
            search(temp, counts, max_r, temp.size());
            counts[temp] -= 1;
        }
        
    }
    
    cout << max_r << endl;
    
    return 0;
    
}   