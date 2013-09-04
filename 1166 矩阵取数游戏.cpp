//mistake j as b index; forget break in max function;
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string multiply(string a, int b) {
    
    int carry = 0;
    string r;
    
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        int temp = (a[i] - '0') * b + carry;
        carry = temp / 10;
        temp %= 10;
        r.push_back('0' + temp);
    }
    
    if (carry)
        r.push_back(carry + '0');
    
    reverse(r.begin(), r.end());
    return r;
    
}

string addS(string a, string b) {
    string r;
    
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

    return r;
    
}

string max(string a, string b) {
    string r = a;
    
    if (a.size() > b.size()) r = a;
    else if (b.size() > a.size()) 
        r = b;
    else  
        for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] != b[i]) {
            if (a[i] > b[i]) r = a;
            else if (b[i] > a[i]) r = b;
            break;
        }
        
        }
    return r;
    
}

int main() {

    int n, m;
    
    cin >> n >> m;
    
    vector<vector<string> > matrix(n, vector<string>(m, "0"));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<string> temp(m + 1, "0");
    string total_value("0");
    
    for (int line = 0; line < n; line++) {
        
        vector<string> value = temp;
        
        string score("1");
        
        string max_value("0");
        
        for (int l = 1; l <= m; l++) {
            score = multiply(score, 2);
            for (int i = 0; i + l <= m; i++) {
              
                value[i] = max(value[i], addS(multiply(value[i], 2), multiply(matrix[line][i+l-1], 2)));

                value[i] = max(value[i], addS(multiply(value[i+1], 2), multiply(matrix[line][i],2)));
                max_value = max(max_value, value[i]);
            }
            
        }
        total_value = addS(total_value, max_value);
    }
    cout << total_value << endl;
    
    return 0;
}