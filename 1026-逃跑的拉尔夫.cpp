#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> used;

void flee(vector<string> &city, vector<string> &r, vector<string>& steps, int idx, int x, int y) {
 	
    if (used.find(idx * 10000 + x * 100 + y) != used.end())
        return;
    
    used.insert(idx * 10000 + x * 100 + y);
    
    
    if (idx == steps.size()) {
     	
        r[x][y] = '*';
        return;
        
    }
    
    
    int n;
    
    if (steps[idx][0] == 'N' || steps[idx][0] == 'S') {
     	n = city.size();   
    }
    else
        n = city[0].size();
    
    for (int i = 0; i < n; i++) {
    	
        int xi = x, yi = y;
        
        switch(steps[idx][0]){
         	
            case 'E':
            	yi = y + i + 1;
            	break;
           	case 'W':
            	yi = y - i - 1;
            	break;
           	case 'S':
            	xi = x + i + 1;
            	break;
           	case 'N':
            	xi = x - i - 1;
            	break;
            default:
            	break;
            
        }
        
        if (xi < 0 || xi >= city.size() || yi < 0 || yi >= city[0].size() || city[xi][yi] == 'X')
            break;
        
	    flee(city, r, steps, idx+1, xi, yi);
    }    
}

int main() {
 	
    int r, c;
    
    cin >> r >> c;
    
    vector<string>city(r, string(c, '.'));
    
    int x, y;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
        
        	cin >> city[i][j];
            
            if (city[i][j] == '*') {
             	x = i;
                y = j;
                city[i][j] = '.';
            }
        }        
    }
    
    int n;
    
    cin >> n;
    
    vector<string> steps(n, ".");
    
    for (int i = i; i < n; i++) {
        
        cin >> steps[i];
        
    }
    
    vector<string> result = city;
    
    flee(city, result, steps, 0, x, y);
    
    for (int i = 0; i < r; i++) {
     	cout << result[i] << endl;   
    }
    
}