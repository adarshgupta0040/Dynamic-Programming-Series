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
    
    string printLCS(int &m, int &n, string &s1, string &s2 ){
    //start from last index of dp, then compare the values of
    //strings. If equal then move diagnol becoz we came from diagnol
    //if string was equal in LCS. Else if not equal then we picked
    //max of upper box or left box in LCS so we have checked same
    //and moved in that direction which value was greater. Keep
    //continuing till we have reached 0th index or string len ==0
    
        int i= m, j=n;
        String ans="";
        while(i>0 and j>0){
            if(s1[i-1]==s2[j-1]){
                ans.push_back(s[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j]) 
                    i--;
                else
                    j--;
            }
        }
        cout << reverse(ans.begin(), ans.end());  //LCS String ans
    }

    int getLCSLength(string& s1, string& s2) {
        
        int m = s1.size(),  n = s2.size();
        dp.resize(m+1, vector<int>(n+1, -1));
        return LCS(s1, s2, m, n);
        
    }
};
