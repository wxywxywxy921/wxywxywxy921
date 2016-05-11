class Solution {
public:    
  /**
   * @param S, T: Two string.
   * @return: Count the number of distinct subsequences
   */
  int numDistinct(string &S, string &T) {
    // write your code here
        
    int s_size = S.size();
    int t_size = T.size();
    int dp[t_size + 1][s_size + 1];
    int i,j;
        
    if(t_size > s_size)
      return 0;
            
    if(!t_size)
      return 1;
            
    for(i = 0; i <= t_size; i++)
      dp[i][0] = 0;
            
    for(i = 0; i <= s_size; i++)
      dp[0][i] = 1;
            
    dp[0][0] = 1;
            
    for(i = 1; i <= t_size; i++)
    {
      for(j = 1; j <= s_size; j++)
      {
        if(i > j)
        {
          dp[i][j] = 0;
          continue;
        }
                
        if(S[j - 1] == T[i - 1])
        {
          dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        }
        else
        {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
        
    return dp[t_size][s_size];
  }
};
