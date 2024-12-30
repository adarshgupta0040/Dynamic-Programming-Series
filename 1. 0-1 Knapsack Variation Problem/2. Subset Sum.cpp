class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        
        //base condn
        for(int i =0; i < n+1; i++){
            for(int j=0; j < target+1; j++){
                if(i==0) dp[i][j] = false;
                if(j==0) dp[i][j] = true ;
                
            }
        }
        
        for(int i =1; i < n+1; i++){
            for(int j=1; j < target+1; j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        
        // for(int i =0; i < n+1; i++){
        //     for(int j=0; j < target+1; j++){
        //         cout<< dp[i][j] << " ";
        //     }
        //     cout<< endl;
        // }
        return dp[n][target];
    }
};