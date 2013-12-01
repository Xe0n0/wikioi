#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;

queue<pair<string, char> > q;
    
vector<pair<string, string> > rules;

set<string> used;

int add(string& str, char level) {
    
    for (int i = 0; i < rules.size(); i++) {
        
        for (int j = 0; j < str.size(); j++) {
            
            int n;
            
            if ((n = str.substr(j, str.size()).find(rules[i].first)) == -1) break;
                         
            string temp = str;
            temp.replace(j+n, rules[i].first.size(), rules[i].second);
            
            if (used.find(temp) == used.end()) {
                  used.insert(temp);
                  q.push(make_pair(temp, level+1));
            }
            
            j = j + n;
        }
        
    }
    
    return -1;
    
}


int main() {
    
    string start, end;
    
    cin >> start >> end;
    
    if(start == end) {
        cout << 0 << endl;
        return 0;
    }
    
    
    string t1, t2;
    
    while (cin >> t1 >> t2 != 0) {
        
        rules.push_back(make_pair(t1, t2));
        
    }
    
    used.insert(start);
    //used.insert(end);
    
    q.push(make_pair(start, 0));
    
    
    
    
    while (!q.empty()) {
      
            pair <string, char> pr = q.front();
        
            q.pop();
        
            if (pr.second > 10) {
                continue;
            }
           
            if (pr.first == end) {
                cout << (int)pr.second << endl;
                
                return 0;
            }

            add(pr.first, pr.second);
            
        
    }
    cout << "NO ANSWER!" << endl;
    
    return 0;    
    
}
// #include <iostream>
// #include <string>
// #include <vector>
// #include <utility>
// #include <queue>
// #include <set>
// #include <map>

// using namespace std;

// queue<pair<string, char> > q;
// queue<pair<string, char> > q2;
    
// vector<pair<string, string> > rules;

// set<string> used;

// int add(string& str, char level) {
    
//     for (int i = 0; i < rules.size(); i++) {
        
//         for (int j = 0; j < str.size(); j++) {
            
//             int n;
            
//             if ((n = str.substr(j, str.size()).find(rules[i].first)) == -1) break;
                         
//             string temp = str;
//             temp.replace(j+n, rules[i].first.size(), rules[i].second);
            
//             if (used.find(temp) == used.end()) {
//                   used.insert(temp);
//                   q.push(make_pair(temp, level+1));
//             }
            
//             j = j + n;
//         }
        
//     }
    
//     return -1;
    
// }

// int add2(string& str, char level) {
    
//     for (int i = 0; i < rules.size(); i++) {
        
//         for (int j = 0; j < str.size(); j++) {
            
//             int n;
            
//             if ((n = str.substr(j, str.size()).find(rules[i].second)) == -1) break;
                         
//             string temp = str;
//             temp.replace(j+n, rules[i].second.size(), rules[i].first);
            
//             if (used.find(temp) == used.end()){
//                 q2.push(make_pair(temp, level+1));
//                 used.insert(temp);
//             }
//             else {
//                 return level;
//             }
                
//             j = j + n;
//         }
        
//     }
    
    
//     return -1;
    
// }

// int main() {
    
//     string start, end;
    
//     cin >> start >> end;
    
//     if(start == end) {
//         cout << 0 << endl;
//         return 0;
//     }
    
    
//     string t1, t2;
    
//     while (cin >> t1 >> t2 != 0) {
        
//         rules.push_back(make_pair(t1, t2));
        
//     }
    
//     used.insert(start);
//     //used.insert(end);
    
//     q.push(make_pair(start, 0));
    
    
    
    
//     while (!q.empty()) {
        
      
//             pair <string, char> pr = q.front();
        
//             q.pop();
        
//             if (pr.second > 10) {
//                 cout << "NO ANSWER!" << endl;
//                 return 0;
//             }
        
        
       
//             int temp;
            
//             if (pr.first == end) {
//                 cout << (int)pr.second << endl;
                
//                 return 0;
//             }

//             add(pr.first, pr.second);
            
        
//     }
    
//     return 0;    
    
// }