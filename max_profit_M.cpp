#include <vector>
#include <stdio.h>
using namespace std;
 
int maxProfit(vector<int> &prices, int m){
    int profit=0, i=1, nlen=prices.size();
    vector<int> dp(m+1,0);
    vector<int> segMax(m+1, 0);
    for(; i<m && i< nlen; ++i){
        segMax[i] = dp[i] = max(dp[i-1], dp[i-1]+prices[i]-prices[i-1]);
    }
    for(; i<nlen; ++i){
        for(int j=m; j>0; --j){
            dp[j] = max(dp[j], segMax[j-1]) + prices[i] - prices[i-1];
            segMax[j] = max(segMax[j], dp[j]);
        }
    }
    for(i=0; i<=m; ++i){
        profit = max(profit, segMax[i]);
    }
    return profit;
}
 
int main(){
    int n,k;
    while(~scanf("%d %d", &n, &k)){
        vector<int> p(n,0);
        for(int i=0;i<n;++i){
            scanf("%d",&p[i]);
        }   
        printf("%d\n", maxProfit(p, k));
    }
    return 0;
}