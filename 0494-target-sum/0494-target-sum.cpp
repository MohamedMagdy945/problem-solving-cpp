class Solution {
    private:
      
    public:
        int findTargetSumWays(vector<int>& nums, int target) {
           int totalSum = 0 ;

            for(int n : nums) totalSum += n ;
            
            if ( abs(target) > totalSum ) return 0 ;
            
            if ((target + totalSum) % 2 != 0 ) return 0 ;
            
            int p = (target + totalSum) / 2 ;

            vector<int> dp(p+1 , 0);
            dp[0] = 1 ;
            
            for (int n : nums)
            {
                for (int i = p ; i>= n  ; i--)
                {
                    dp[i] = dp[i] + dp[i - n];
                }
            }
            return dp[p];
        }
};