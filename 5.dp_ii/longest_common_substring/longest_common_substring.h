class Solution {
public:    
  /**
   * @param A, B: Two string.
   * @return: the length of the longest common substring.
   */
  int longestCommonSubstring(string &A, string &B) {
    // write your code here
        
    int i, j;
    int a_size = A.size();
    int b_size = B.size();
    int dp[a_size + 1][b_size + 1];
    int max = -99999;
        
    if(!a_size || !b_size)
      return 0;
        
    for(i = 0; i <= a_size; i++)
    {
      dp[i][0] = 0;
    }
        
    for(i = 0; i <= b_size; i++)
    {
      dp[0][i] = 0;
    }
        
    for(i = 1; i <= a_size; i++)
    {
      for(j = 1; j <= b_size; j++)
      {
        if(A[i-1] == B[j-1])
        {
          if(dp[i - 1][j - 1] > dp[i - 1][j])
            dp[i][j] = dp[i - 1][j - 1] + 1;
          else
            dp[i][j] = dp[i - 1][j] + 1;
                        
          if(dp[i][j] - 1 < dp[i][j - 1])
            dp[i][j] = dp[i][j - 1] + 1;
                        
                        
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        else
        {
          dp[i][j] = 0; 
        }
                
        if(dp[i][j] > max)
        {
          max = dp[i][j];
        }
      }
    }
        
    return max;
  }
};
