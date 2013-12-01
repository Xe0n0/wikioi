#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//without comp is ok
class comp {
public:
    string a;
    
    comp(int v = 0){
        a.push_back(v + '0');   
    }
    
    comp(string v){
        a = v;   
    }
    comp(const comp& o){

        a = o.a;

    }
    comp operator+(const comp& o) {

        string r;
        string b = o.a;
        
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        
        while (i >= 0 and j >= 0) {
            
            int temp = a[i] - '0' + b[j] - '0' + carry;
            carry = temp / 10;
            temp %= 10;
            r.push_back(temp + '0');
            i--;
            j--;
        }
        
        while (i >= 0) {
            int temp = a[i] - '0' + carry;
            carry = temp / 10;
            temp %= 10;
            r.push_back(temp + '0');
            i--;
        }
        
        while (j >= 0) {
            int temp = b[j] - '0' + carry;
            carry = temp / 10;
            temp %= 10;
            r.push_back(temp + '0');
            j--;
        }
        
        if (carry) {
            r.push_back(carry + '0');
        }
        reverse(r.begin(), r.end());

        return comp(r);
    
    }
};

comp max(comp a, comp b) {
    comp r = a;
    
    if (a.a.size() > b.a.size()) r = a;
    else if (b.a.size() > a.a.size()) 
        r = b;
    else
        for (int i = 0; i < (int)a.a.size(); i++) {
        if (a.a[i] != b.a[i]) {
            if (a.a[i] > b.a[i]) r = a;
            else if (b.a[i] > a.a[i]) r = b;
            break;
        }
    }
    return r;
    
}

int main() {

    int t;
    
    cin >> t;
    
    while (t--) {
    
    int p, k;
        
    cin >> p >> k;
        
    string str;
    
    while(p--) {
        
        string temp;
        cin >> temp;
        str.append(temp);
        
    }
    int n = str.size();
    
    int s;
    
    cin >> s;
        
    vector<string> dict;
        
    while (s--) {
        string temp;
        cin >> temp;
        dict.push_back(temp);
    }
        
    vector<vector<comp> > num_ocur(n, vector<comp>(n, comp(0)));
    
    for (int j = n-1; j >= 0; j--) {
    
        for (int i = n-1; i >= 0; i--) {
                        
            for (int k = 0; k < dict.size(); k++) {
                
                if (dict[k].size() > j-i+1) continue;
                
                if (str.substr(i, dict[k].size()) == dict[k]) {
                    num_ocur[i][j] = num_ocur[i][j] + comp(1);
                    break;
                }
            }
            
            if (i < j)
                num_ocur[i][j] = num_ocur[i][j] + num_ocur[i+1][j];  
            
        }
    }
        
    vector<vector<comp> > value(n, vector<comp>(k+1, comp(0)));
    
    for (int i = 0; i < n; i++) {
        value[i][1] = num_ocur[i][n-1];
    }
    
    for (int c = 2; c <= k; c++) {
        for (int i = 0; i + c - 1 < n; i++) {
            
            for (int j = i; j + c <= n; j++) {
                
                value[i][c] = max(value[i][c], num_ocur[i][j] + value[j+1][c-1]);
            }

        }
    }
    
    cout << value[0][k].a << endl;
        
    }
    
    return 0;
}