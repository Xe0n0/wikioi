#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct part {
    int a;
    int b;
    int v;
    part(int _a = 0, int _b = 0, int _c = 0):a(_a), b(_b), v(_c){
    };
};

bool operator < (const part& a, const part& b) {
    
    return a.b < b.b;
}

int main() {
    
    int n;
    
    cin >> n;
    
    vector<part>parts(n);
    
    for (int i = 0; i < n; i++) {
        cin >> parts[i].a >> parts[i].b >> parts[i].v;
    }
    
    sort(parts.begin(), parts.end());
    
    vector<int>best(n, 0);
    
    int v_best = 0;
    
    for (int i = 0; i < n; i++) {
        
        if (parts[i].v > 0)
	        best[i] = parts[i].v;
        
    	int temp = 0;
        
        for (int j = 0; j < i; j++) {
            if (parts[i].a >= parts[j].b)
	            temp = max(temp, best[j]);
        }
        best[i] += temp;
        v_best = max(v_best, best[i]);
        
    }
    
    cout << v_best;
    
    return 0;
    
}