int solve(int capacity, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp){
        
    // Recursion
    // n= wt.size();
    // if(capacity ==0 || n ==0){
    //     return 0;
    // }
    // if(wt[n-1]>=capacity){
    //     return max(val[n-1] +  solve(capacity- val[n-1], val, wt, n-1 ), 
    //                             solve(capacity, val, wt, n-1 ));
    // }
    // else{
    //     return solve(capacity, val, wt, n-1 );
    // }
    
    // Memoise
    // int m = capacity;
    
    // if(capacity ==0 || n ==0) return 0; 
    // if(dp[n][m]!=-1) return dp[n][m];
    
    // if(wt[n-1]<=capacity){
    //     dp[n][m]= max(val[n-1] +  solve(capacity- wt[n-1], val, wt, n-1, dp ) , 
    //                             solve(capacity, val, wt, n-1 , dp));
    // }
    // else{
    //     dp[n][m]= solve(capacity, val, wt, n-1 , dp);
    // }
    // return dp[n][m];
    
    //Top down n->i capacity->j
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j< capacity+1 ; j++){
            if (i==0 || j == 0)  dp[i][j] = 0;
        }
    }
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<=capacity+1 ; j++){
            if(wt[i-1]<= j){
                dp[i][j] = max (val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j] );
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }    
    return dp[n][capacity];
    
}
    
int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
    int n= wt.size();
    vector<vector<int>> dp(n+1, vector<int>(capacity+1,-1));
    return solve(capacity, val,wt,n, dp);
    
}