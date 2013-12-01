#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

void next_permutation(string& c){
    for (int k = 0; k < c.size(); k++) {
           
       	if (k > 0) printf(" ");
		
        printf("%c", c[k]);   

    }
    
    for (int i = c.size() - 2; i >= 0; i--) {
     	
        if (c[i] < c[i+1]) {
         	
            for (int j = c.size() - 1; j >= 0; j--) {
             	
                if (c[j] > c[i]) {
                    
                    swap(c[i], c[j]);
                    reverse(c.begin() + i + 1, c.end());
                    
                    
        			printf("\n");
                    next_permutation(c);
                    break;
                }
                
            }
            
            break;
        }
        
    }
    
}

void all_permutation(vector<string> &r, int idx, set<int> &avails, string &state) {
 	
    if (avails.size() == 0) {
        for (int j = 0; j < state.size(); j++) {
           
            if (j > 0) printf(" ");
            printf("%c", state[j]);   

        }
        printf("\n");
        return;
    }
    
    set<int>::iterator it;
    
    for (it = avails.begin(); it != avails.end(); it++) {
    
         	state.push_back(*it + '0');
        	int temp = *it;
            avails.erase(it);
            all_permutation(r, idx + 1, avails, state);
        	state.erase(state.end()-1);
            avails.insert(temp);
        	it = avails.find(temp);
        
    }
}
                     

int main() {
    
    int n;
    
    cin >> n;
    
    set<int> avails;
    
    string c;
    
    for (int i = 1; i <= n; i++){
     	//avails.insert(i);   
        c.push_back(i + '0');
                    
    }
    
    next_permutation(c);
    
    string temp;
    
    vector<string> r;
    
    //all_permutation(r, 0, avails, temp);
    
    
    
    return 0;
    
}