class Solution {
  public:
  
    int countSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>> dp(arr.size()+1, vector<int>(target+1, -1));
        for(int i =0; i< arr.size()+1; i++ ){
            for(int j=0; j< target+1; j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        
        for(int i =1; i< arr.size()+1; i++ ){
            for(int j=0; j< target+1; j++){
                if(arr[i-1]<=j){
                    dp[i][j]= dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][target];
    }
    
    int countPartitions(vector<int>& arr, int d) {
        //Sum(s1)-sum(s2) = d   -----1
        //Sum(s1)+sum(s2) = TotalSum   ----2
        // 1+2 we get -> sum(s1) = (d + TotalSum)/2
        //we need to find only those subset S1 whose sum is  (d + TotalSum)/2
        
        int TotalSum= 0;
        for(int i=0;i<arr.size();i++){
            TotalSum+=arr[i];
        }
        
        if(TotalSum<d || (TotalSum+d)%2!=0)return 0;
        
        int calculatedSum = (d + TotalSum)/2;
        return countSubsetSum(arr, calculatedSum);
        
    }
};