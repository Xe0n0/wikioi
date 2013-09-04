#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    
    int n;
    
    cin >> n;
    
    int *num = new int[n];
    
    int count = n;
    int total = 0;
    
    while (count--) {
        cin >> num[count];
        total += num[count];
    }
    
    cout << total << endl;
    
    int r = 0; int avg = total / n;
    
    for (int i = 0; i < n - 1; i++) {
        
        if (num[i] != avg) {
            num[i+1] += num[i] - avg;
            r++;
        }
    }
    
    return r;
    
}