class Solution {
  public:
    vector<vector<int>> dp;
    bool isPalindrome(string& str, int left, int right) {
        // int left = 0;
        // int right = str.length() - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    int SolveMCM(string s, int i, int j){
        if(i>=j) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        if(isPalindrome(s, i, j) == true) return 0;

        int mini = INT_MAX, left, right;
        for(int k=i; k<j; k++){
            // int temp = 1 + SolveMCM(s, i, k) + SolveMCM(s, k+1, j);
            
            if(isPalindrome(s, i, k)==true){ 
                int temp = 1 + SolveMCM(s, k+1, j);
                
            // if(dp[i][k]!=-1){
            //     left = dp[i][k];
            // }
            // else{
            //     left = SolveMCM(s, i, k);
            //     dp[i][k] = left;
            // }

            // if(dp[k+1][j]!=-1){
            //     right = dp[k+1][j];
            // }
            // else{
            //     right = SolveMCM(s, k+1, j);
            //     dp[k+1][j] = right;
            // }
            // int temp = 1 + left+ right;

            mini = min(mini, temp);
            dp[i][j]= mini;
            }
        }

        return dp[i][j];
    }

    int palindromicPartition(string &s) {
        int n = s.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return SolveMCM(s, 0, n-1);
    }
};
