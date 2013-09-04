#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int N, M;
    
    vector<int>c(4, 1);
    
    cin >> N >> M;
    
    vector<int>score(N, 0);
    
    
    for (int i = 0; i < N; i++) {
        
     	cin >> score[i];   
    }
    
    for (int j = 0; j < M; j++) {
     	int temp;
        
        cin >> temp;
        
        c[temp-1]++;
    }
        
    vector<vector<vector<vector<int> > > > value(c[0]+1, vector<vector<vector<int> > >(c[1]+1, vector<vector<int> >(c[2]+1, vector<int>( c[3]+1, 0))));
    
    for (int i = 1; i <= c[0]; i++) {
        for (int j = 1; j <= c[1]; j++) {
            for (int k = 1; k <= c[2]; k++) {
                for (int l = 1; l <= c[3]; l++) {
                    
                    
					value[i][j][k][l] = max(value[i-1][j][k][l], value[i][j-1][k][l]);
                    value[i][j][k][l] = max(value[i][j][k][l], value[i][j][k-1][l]);
                    value[i][j][k][l] = max(value[i][j][k][l], value[i][j][k][l-1]);
                    
                    value[i][j][k][l] += score[i-1 + (j-1)*2 + (k-1)*3 + (l-1)*4];
                    
                }
            }
        }
    }
    
    cout << value[c[0]][c[1]][c[2]][c[3]];
    
 	return 0;   
}