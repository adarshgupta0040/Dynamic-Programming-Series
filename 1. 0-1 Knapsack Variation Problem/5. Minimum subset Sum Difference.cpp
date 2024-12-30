class Solution {

  public:
    int minDifference(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (auto i : nums) {
            sum += i;
        }
        
        // cout << sum << endl;
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (i == 0) dp[i][j] = false;
                if (j == 0) dp[i][j] = true;
            }
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        vector<int> v;
        for(int j=0; j < (sum)/2 +1; j++){
            if(dp[n][j]==true){
                v.push_back(j);
            }
        }
        
        int minimumDiff = INT_MAX;
        for(int j=0; j < v.size(); j++){
            minimumDiff = min(minimumDiff, sum-2*v[j]);
        }
        
        return minimumDiff;
    }
};