#include <iostream>
#include <stdio.h>
#include <queue>
 
using namespace std;
 
int count_price_push(vector<int> &p, vector<int> &data, priority_queue<vector<int> >&pq)
{
    int max_pro = 0, val = 0;
    int max_in = data[2];
    int max_out = data[2];
    int in = data[2];
 
    for(int i = data[2]; i < data[3]; ++i){
        if(0 == data[1]){
            val += p[i];
        }else{
            val -= p[i];
        }
        if(val > max_pro){
            max_pro = val;
            max_in = in;
            max_out = i+1;
        }
        if(val < 0) {
            val = 0;
            in = i+1;
        }
    }
    data[4] = max_in;
    data[5] = max_out;
    data[0] = max_pro;
    pq.push(data);
    return 0;
}
 
int maxProfit(vector<int> &p, int k)
{//vec里面 价值 方向(0最大,1最小) 起点 终点 买入 卖出
    int max_pro = 0;
    priority_queue<vector<int> >pq;
    vector<int> data(6, 0);
    data[1] = 0;
    data[2] = 0;
    data[3] = p.size();
    count_price_push(p, data, pq);
    for(int i = 0; i<k; ++i){
        data = pq.top();
        pq.pop();
        if(data[0] <= 0) return max_pro;
        max_pro += data[0];
        vector<int> left(6, 0);
        vector<int> mid(6, 0);
        vector<int> right(6, 0);
        left[1] = data[1];
        mid[1] = 1 - data[1];
        right[1] = data[1];
        left[2] = data[2];
        mid[2] = data[4];
        right[2] = data[5];
        left[3] = data[4];
        mid[3] = data[5];
        right[3] = data[3];
        count_price_push(p, left, pq);
        count_price_push(p, mid, pq);
        count_price_push(p, right, pq);
    }
    return max_pro;
}
 
int main()
{
    int n, k;
 
    while(~scanf("%d%d", &n, &k)) 
    {
        vector<int> p(n,0);
        scanf("%d",&p[0]);
        for(int i=1;i<n;++i){
            scanf("%d",&p[i]);
            p[i-1] = p[i] - p[i-1];
        }   
        p.pop_back();
        printf("%d\n", maxProfit(p, k));
    }
    return 0;
}