class Solution {

  public:
    vector<vector<int>> dp;
    
    int LCS(int &m, int &n, string &s1, string &s2 ){
        for(int i=0; i<m+1;i++){
            for(int j=0; j<n+1; j++){
                if(i==0 or j==0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=1; i<m+1;i++){
            for(int j=1; j<n+1; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
    
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        // We will first convert s1 to LCS and then to s2. so "heap" --> "ea" --> "pea"
        int m = s1.size(), n = s2.size();
        dp.resize(m+1, vector<int>(n+1, -1));
        int lcs = LCS(m, n, s1, s2);
        int totalDeletion = s1.size() - lcs;
        int totalInsertion = s2.size() - lcs;
        return (totalDeletion + totalInsertion);
    }
};