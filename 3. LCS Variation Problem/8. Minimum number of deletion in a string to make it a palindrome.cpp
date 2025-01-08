class Solution {
public:
    vector<vector<int>> dp;
    int LCS(int m, int n, string s1, string s2){
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

    int longestPalindromicSubsequence(string s) {
        int m = s.size(), n = m;
        dp.resize(m+1, vector<int>(n+1, -1));
        string s1 = s;
        reverse(s.begin(), s.end());
        return LCS(m,n, s1, s);
    }
    

    int minDeletion(string s) {
        // No.of Deletion inversely proportional to length of PalindromicSubsequence
        // so Min Deletion depend on  Longest PalindromicSubsequence.
        // so (totallength of str - LPS ) is ans.
    
        int LPS = longestPalindromicSubsequence(s);
        int totalDeletion = s.size() - LPS;
        return totalDeletion;
    }
};
