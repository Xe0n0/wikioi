//rev.1
#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

void allorder(vector<pair<int, int> > &tree, int root, vector<int> &pre, vector<int> &post, vector<int> &inorder) {
    
    pre.push_back(root);
    
    if (tree[root].first != 0) allorder(tree, tree[root].first, pre, post, inorder);
    
    inorder.push_back(root);
    
    if (tree[root].second != 0) allorder(tree, tree[root].second, pre, post, inorder);
    
    post.push_back(root);
    
}

int main(){

    int n;
    
    cin >> n;
    
    vector<pair<int, int> > tree(n+1, make_pair(0, 0));
    
    for (int i = 1; i <= n; i++) {
        
        cin >> tree[i].first >> tree[i].second;
        
    }
    
    
    vector<int> pre;
    vector<int> post;
    vector<int> inorder;
    
    stack<int> s;
        
    vector<bool> visited(n+1, false);
    
    int p = 1;
    
    while (p || !s.empty()) {
        
        if (p) {
            
            s.push(p);
            pre.push_back(p);
            p = tree[p].first;
            
        }
        else {
            p = s.top();
            
            if (visited[p]){
                
                s.pop();
                post.push_back(p);
                p = 0;
                
            }
            else {
                visited[p] = true;
                inorder.push_back(p);
                p = tree[p].second;

            }
        }
        
    }
    
    
    for (int i = 0; i < pre.size(); i++) {
        if (i > 0)
            cout << ' ' << pre[i];   
        else
            cout << pre[i];
    }
    
    cout << endl;
    
     for (int i = 0; i < inorder.size(); i++) {
        if (i > 0)
            cout << ' ' << inorder[i];   
        else
            cout << inorder[i];
    }
    
    cout << endl;
    
     for (int i = 0; i < post.size(); i++) {
        if (i > 0)
            cout << ' ' << post[i];   
        else
            cout << post[i];
    }
    
    cout << endl;
    
}
//rev.2
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void allorder(vector<pair<int, int> > &tree, int root, vector<int> &pre, vector<int> &post, vector<int> &inorder) {
 	
    pre.push_back(root);
    
    if (tree[root].first != 0) allorder(tree, tree[root].first, pre, post, inorder);
    
    inorder.push_back(root);
    
    if (tree[root].second != 0) allorder(tree, tree[root].second, pre, post, inorder);
    
    post.push_back(root);
    
}

int main(){

	int n;
    
    cin >> n;
    
    vector<pair<int, int> > tree(n+1, make_pair(0, 0));
    
    for (int i = 1; i <= n; i++) {
     	
        cin >> tree[i].first >> tree[i].second;
        
    }
    
    
    vector<int> pre;
    vector<int> post;
    vector<int> inorder;
    
    allorder(tree, 1, pre, post, inorder);
    
    for (int i = 0; i < pre.size(); i++) {
        if (i > 0)
	     	cout << ' ' << pre[i];   
        else
            cout << pre[i];
    }
    
    cout << endl;
    
     for (int i = 0; i < inorder.size(); i++) {
        if (i > 0)
	     	cout << ' ' << inorder[i];   
        else
            cout << inorder[i];
    }
    
    cout << endl;
    
     for (int i = 0; i < post.size(); i++) {
        if (i > 0)
	     	cout << ' ' << post[i];   
        else
            cout << post[i];
    }
    
    cout << endl;
    
}