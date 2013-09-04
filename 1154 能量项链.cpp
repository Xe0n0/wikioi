#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    
    cin >> n;
    
    vector<pair<int, int> > ball(2 * n, make_pair(0, 0));
    
    for (int i = 0; i < n; i++) {
        cin >> ball[i].first;
        
        if (i > 0)
            ball[i-1].second = ball[i].first;
    }
    
    ball[n-1].second = ball[0].first;
    
    copy(ball.begin(), ball.begin() + n, ball.begin() + n);
    
    vector<vector<int> > value(n+1, vector<int> (2 * n, 0));
    
    int max_value = 0;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 2 * n - i; j++) {
            
            for (int k = 1; k < i; k++) {
                
                value[i][j] = max(value[k][j] + value[i-k][j+k] + ball[j].first * ball[j+k].first * ball[j+i].first, value[i][j]);
                
            }
            if (i == n)
            max_value = max(max_value, value[i][j]);
        }
    }
    cout << max_value << endl;
    return 0;
}