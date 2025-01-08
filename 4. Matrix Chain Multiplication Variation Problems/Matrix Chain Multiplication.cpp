class Solution {
  public:
    vector<vector<int>> dp;
    int solveMCMRecursive(vector<int> &arr, int i, int j)
    {
        if(i>=j) return 0;
        
        int temp,min = INT_MAX;
        
        for(int k=i; k<=j-1; k++){
            int temp = solveMCM(arr, i, k) + solveMCM(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]);
            if(temp < min) min = temp;
            
        }
        
        return min;
    }
    
    int solveMCM(vector<int> &arr, int i, int j)
    {
        int n= arr.size();
        if(i>=j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int temp,min = INT_MAX;
        
        for(int k=i; k<=j-1; k++){
            int temp = solveMCM(arr, i, k) + solveMCM(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]);
            if(temp < min) 
                min = temp;
            dp[i][j] = min;
        }
        
        return dp[i][j];
    }
    
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return solveMCM(arr, 1, n-1);
        // code here
    }
};