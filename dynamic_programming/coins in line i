    bool firstWillWin(int n) {
        // write your code here
        
        int dp[n+1];
        dp[0]=false;
        dp[1]=true;
        dp[2]=true;
        for(int i=3;i<=n;i++){
            if(dp[i-1]==false || dp[i-2]==false)dp[i]=true;
            else dp[i]=false;
        }
        return dp[n];
    }
    bool firstWillWin(int n) {
        // write your code here
        return n%3!=0;
    }
