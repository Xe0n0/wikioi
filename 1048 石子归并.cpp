#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
 	
    int n;
    
    cin >> n;
    
    if (n <= 1) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> num(n, 0);
    vector<vector<pair<int, int> > > cost(n, vector<pair<int, int> >(n, make_pair(0, INT_MAX)));
    
    for (int i = 0; i < n; i++) {
        cost[0][i].second = 0;
        cin >> cost[0][i].first;
    }
    
    int total_cost = 0;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
        	for (int k = 1; k <= i; k++) {
                
                int temp = cost[k-1][j].second + cost[i-k][j+k].second
                    	+ cost[k-1][j].first + cost[i-k][j+k].first;
                
                if (cost[i][j].second > temp) {
                    cost[i][j].first = cost[k-1][j].first + cost[i-k][j+k].first;
                    cost[i][j].second = temp;
                }
        	}
        }
    }
    
    cout << cost[n-1][0].second << endl;
    
    return 0;
}