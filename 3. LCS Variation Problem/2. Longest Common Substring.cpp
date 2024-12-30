class Solution {
  public:
  
    int LCSubstringTabulation(string &s1, string &s2, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int ans=0;
        for (int i = 0; i < m+1; i++) {
            for (int j = 0; j < n+1; j++) {
                  if(i==0 or j==0) 
                        dp[i][j]=0;
            }
        }
        
        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        return ans;
    } 
    
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        return LCSubstringTabulation(s1, s2, s1.size(),  s2.size());
    }
};