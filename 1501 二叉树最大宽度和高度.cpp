//last case after BFS
#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

void maxHeight(vector<pair<int, int> > &tree, int root, int &height)
{
    
    int hl = 0, hr = 0;
    
    if (tree[root].first != 0) maxHeight(tree, tree[root].first, hl);
    
    else if (tree[root].second != 0) maxHeight(tree, tree[root].second, hr);
        
   	height = max(hl, hr) + 1;
    
}

int main() {

	int n;
    
    cin >> n;
    
    if (n <= 0) {
     	cout << 0 << ' ' << 0 << endl;
        return 0;
    }
    
    vector<pair<int, int> >tree(n+1, make_pair(0, 0));
    
    for (int i = 1; i <= n; i++) {
     	cin >> tree[i].first >> tree[i].second;   
    }
    
    queue<pair<int, int> > q;
    
    q.push(make_pair(1, 0));
    
    int w = 0, max_w = 0, level = 0;
    
    while (!q.empty()) {
     	
        pair<int, int> pr = q.front();
        q.pop();
        
        if (pr.second > level) {
         	max_w = max(max_w, w);
            level = pr.second;
            w = 0;
        }
        
        w++;
        
        int troot = pr.first;
        
        if (tree[troot].first != 0) {
        	q.push(make_pair(tree[troot].first, pr.second+1));
            
        }
        
        if (tree[troot].second != 0) {
        
        	q.push(make_pair(tree[troot].second, pr.second+1));
        }
        
    }
    max_w = max(max_w, w);
    
    cout << max_w << ' ' << level + 1 << endl;
    
}