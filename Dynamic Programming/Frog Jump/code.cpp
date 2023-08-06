// Memomization

#include <bits/stdc++.h> 
int solve(int i, vector<int> &heights, vector<int> &dp){
    if(i == 0){
        dp[0] = 0;
        return 0;
    }
    if(dp[i] != INT_MAX)
        return dp[i];
    
    int jump1 = solve(i-1, heights, dp) + abs(heights[i] - heights[i-1]);
    int jump2 = INT_MAX;

    if(i-2 >= 0)
        jump2 = solve(i-2, heights, dp) + abs(heights[i] - heights[i-2]);

    return dp[i] = min(jump1, jump2);
}

int frogJump(int n, vector<int> &heights){
    vector<int> dp(n, INT_MAX);
    return solve(n-1, heights, dp);
}
