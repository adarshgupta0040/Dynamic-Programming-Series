class Solution {
  public:
    vector<vector<int>> dp;
    
    // int LCSRecursive(string& s1, string& s2, int m, int n){
    //     //base Condn
    //     if(m==0 or n==0) return 0;
        
    //     if(s1[m-1] == s2[n-1]){
    //         return 1 + LCS(s1, s2, m-1, n-1);
    //     }
    //     else{
    //         return max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
    //     }
    // }
    
    // Function to find the length of the longest common subsequence in two strings.
    int LCS(string& s1, string& s2, int m, int n){
        
        //base Condn
        if(m==0 or n==0) return 0;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        if(s1[m-1] == s2[n-1]){
            dp[m][n] = 1 + LCS(s1, s2, m-1, n-1);
        }
        else{
            dp[m][n] = max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
        }
        
        return dp[m][n];
    }
    
    // int LCSTabulation(string &s1, string &s2, int m, int n) {

    //     vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    
    //     for (int i = 0; i < m+1; i++) {
    //         for (int j = 0; j < n+1; j++) {
    //               if(i==0 or j==0) 
    //                     dp[i][j]=0;
    //         }
    //     }
        
    //     for (int i = 1; i < m+1; i++) {
    //         for (int j = 1; j < n+1; j++) {
    //             if (s1[i - 1] == s2[j - 1]) {
    //                 dp[i][j] = 1 + dp[i - 1][j - 1];
    //             } else {
    //                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //             }
    //         }
    //     }
    //     return dp[m][n];
    // }

    
    int getLCSLength(string& s1, string& s2) {
        
        int m = s1.size(),  n = s2.size();
        dp.resize(m+1, vector<int>(n+1, -1));
        return LCS(s1, s2, m, n);
        
    }
};