class Solution {
public:
  /**
   * Determine whether s3 is formed by interleaving of s1 and s2.
   * @param s1, s2, s3: As description.
   * @return: true of false.
   */
  bool isInterleave(string s1, string s2, string s3) {
    // write your code here
        
    int i,j;
    int s1_size = s1.size();
    int s2_size = s2.size();
    int s3_size = s3.size();
    bool dp[s1_size + 1][s2_size + 1];
        
    if(!s1_size && !s2_size && !s3_size)
      return true;            
            
    if(s3_size != s1_size + s2_size)
      return false;
            
    if(!s1_size && s2 == s3)
      return true;
            
    if(!s2_size && s1 == s3)
      return true;
            
    if(s3[0] == s1[0] || s3[0] == s2[0])
    {
      dp[0][0] = true;
    }
    else
    {
      return false;
    }
        
    for(i = 1; i <= s1_size; i++)
    {
      if(s1[i-1] == s3[i-1] && dp[i - 1][0])
      {
        dp[i][0] = true;
      }
      else
      {
        dp[i][0] = false;
      }
    }
        
    for(i = 1; i <= s2_size; i++)
    {
      if(s2[i-1] == s3[i-1] && dp[0][i - 1])
      {
        dp[0][i] = true;
      }
      else
      {
        dp[0][i] = false;
      }
    }
        
    for(i = 1; i <= s1_size; i++)
    {
      for(j = 1; j <= s2_size; j++)
      {
        if((s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j])
        {
          dp[i][j] = true;
        }
        else if((s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1])
        {
          dp[i][j] = true;
        }
        else
        {
          dp[i][j] = false;
        }
      }
    }
        
    return dp[s1_size][s2_size];
  }
};
