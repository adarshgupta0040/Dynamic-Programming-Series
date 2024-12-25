class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        
        for(int i =0; i< coins.size()+1; i++ ){
            for(int j=0; j< amount+1; j++){
                if(i==0) dp[i][j]=INT_MAX -1;   //so that 1 get cancel later 
                if(j==0) dp[i][j]=0;            //if not then INT_MAX + 1 will give -ve no.
            }
        }
        for(int j =1; j< amount+1; j++ ){
            if(j % coins[0] == 0){
                dp[1][j] = j / coins[0];  // put 1 if get divides
            }
            else{
                dp[1][j]= INT_MAX - 1;
            }
            
        }
        
        for(int i =2; i< coins.size()+1; i++ ){
            for(int j=0; j< amount+1; j++){
                if(coins[i-1]<=j){
                    dp[i][j]= min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][amount]==INT_MAX-1 ? -1 : dp[n][amount] ;
    }
    
};