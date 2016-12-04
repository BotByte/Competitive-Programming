#include <bits/stdc++.h>

using namespace std;

int store, concert;
int val[105][55];
int cost[105][105];
int dp[105][105];

int f(int i, int cnts, int prev)
{
    if(cnts == concert+1) return 0;
    if(dp[i][cnts] != -1) return dp[i][cnts];
    int maxs = 0;
    for(int k=1; k<=store; k++){
        int temp;
        if(prev == 0) temp = val[k][cnts] + f(k, cnts+1, 1);
        else temp = val[k][cnts] + f(k, cnts+1, 1) - cost[i][k];
        maxs = max(temp, maxs);
    }
    return dp[i][cnts] = maxs;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d %d", &store, &concert);
        for(int i=1; i<=store; i++){
            for(int j=1; j<=concert; j++){
                scanf("%d", &val[i][j]);
            }
        }
        for(int i=1; i<=store; i++){
            for(int j=1; j<=store; j++){
                scanf("%d", &cost[i][j]);
            }
        }
        int maxs = 0;
        memset(dp, -1, sizeof dp);
        maxs = f(1, 1, 0);
        cout << maxs << endl;
    }
}
