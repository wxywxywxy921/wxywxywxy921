class Solution {
public:
  /**
   * @param n: An integer
   * @return: An integer
   */
  int climbStairs(int n) {
    // write your code here
        
    int dp[n];
    int i;
        
    if(!n)
      return 1;
        
    dp[0] = 1;
    dp[1] = 2;
        
    if(n > 1)
    {
      for(i = 2; i < n; i++)
      {
        dp[i] = dp[i - 1] + dp[i - 2];
      }
    }
        
    return dp[n-1];
  }
};
