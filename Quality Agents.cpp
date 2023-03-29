int findLargestSquareSize(vector<vector<int>> samples) {
        int n = samples.size();
        vector<vector<int>>dp(n, vector<int> (n));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    dp[i][j] = samples[i][j];
                }
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(samples[i][j]==1){
                    dp[i][j] = 1+ min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                }
            }
        }
        
        int maxi = INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]>maxi){
                    maxi = dp[i][j];
                }
            }
        }
        return maxi;
}
