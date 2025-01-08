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

    string shortestCommonSupersequence(string str1, string str2) {
        int m= str1.size(), n = str2.size();
        dp.resize(m+1, vector<int>(n+1, -1));
        int lcs = LCS(m,n, str1, str2);
        
        // shortestCommonSupersequence len= (m+n) - LCS 
        // Here we will Add char which are equal as well as not equal because SCS = M+n-LCS
        int i = m, j= n;
        string ans =  "";
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1] ){
                    ans.push_back(str1[i-1]);
                    i--;          
                }
                else{                    
                    ans.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(str2[j-1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};