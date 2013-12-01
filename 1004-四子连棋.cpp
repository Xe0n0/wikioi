#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class board {
 	
public:

    vector<vector<char> > data;
    
    int x1;
    int y1;
    
    int x2;
    int y2;
    int level;
    char now;
    
    board(){
        data = vector<vector<char> >(4, vector<char>(4, 'O'));
        level = 0;
        x1 = -1;
        x2 = -1;
    }
    
    void addToQueue(char target, queue<board> &q, int x, int y) {
        
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
             	
                if (i >= 0 and i <= 3 and j >= 0 and j <= 3 and abs(x-i) + abs(y-j) == 1) {
                    if (data[i][j] == target) {
                        

                     	board temp = *this;
                        temp.data[i][j] = 'O';
                        temp.data[x][y] = target;
                        temp.now = target;

                        //may have two 'O' in same row
                        if (temp.x1 == x and temp.y1 == y) {
                            temp.x1 = i;
                            temp.y1 = j;
                        }
                        else {
                            
                            temp.x2 = i;
                            temp.y2 = j;
                            
                        }
                        temp.level++;
                        q.push(temp);
                    }
                    
                }
                
            }
        }
        
    }
    
    void addToQueue1(char target, queue<board> &q){
        addToQueue(target, q, x1, y1);
    }
    
    void addToQueue2(char target, queue<board> &q){
    	addToQueue(target, q, x2, y2);
    }
    
    void addAll(queue<board> &q) {
        if (now == 'B') {
            
           	addToQueue1('W', q);
    		addToQueue2('W', q);
            return;
        }

        addToQueue1('B', q);

        addToQueue2('B', q);

    }
    
    bool isValid(){
                
        bool foundx1 = false;
        bool foundx2 = false;
        for (int i = 0; i < 4; i++) {
            
            bool found = false;
        	
            for (int j = 0; j < 4; j++) {
             	
                if (data[i][j] != data[i][0]) {
                    
                    found = true;
                    break;
                }
                
            }
            
            if (!found) return true;
            
            
            bool found2 = false;
            
            for (int j = 0; j < 4; j++) {
                if (data[j][i] != data[0][i]) {
                 	found2 = true;
                    break;
                }
            }
            
            if (!found2) return true;
            
            if (data[i][i] != data[0][0]) foundx1 = true;
            
            if (data[i][3-i] != data[0][3]) foundx2 = true;
            
        }
        
        if (!foundx1 || !foundx2) return true;
        
        return false;
        
    }
    
};

int main() {

    
    board a;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            
        	cin >> a.data[i][j];
            if (a.data[i][j] == 'O') {
                if (a.x1 == -1) {
                 	a.x1 = i;
                    a.y1 = j;
                }
                else {
                 	a.x2 = i;
                    a.y2 = j;
                }
            }
        }
    }
    
    queue<board> q;
    
    a.now = 'B';

    q.push(a);
    
    a.now = 'W';
    
    q.push(a);
    
   
    
    while (!q.empty()) {
        
        board temp = q.front();
        q.pop();
        
        if (temp.isValid()) {
         	cout << temp.level << endl;
            break;
        }
        
        temp.addAll(q);
        
    }
    
	return 0;
}
