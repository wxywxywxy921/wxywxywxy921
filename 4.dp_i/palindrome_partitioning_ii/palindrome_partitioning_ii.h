class Solution {
public:
  /**
   * @param s a string
   * @return an integer
   */
  int minCut(string s) {
    // write your code here
            
    int length = s.size();
    bool lookup_pali[length][length];
    int dp[length];
    int i, j;
    int max = s.size();
        
    if(!max)
      return 0;
        
    // build up the pali lookup table
            
    for(i = 0; i < length; i++)
    {
      lookup_pali[i][i] = true;
    }
        
    for(i = 0; i < length - 1; i++)
    {
      if(s[i] == s[i+1])
      {
        lookup_pali[i][i+1] = true;
      }
      else
      {
        lookup_pali[i][i+1] = false;
      }
    }
        
    for(j = 2; j < length; j++)
    {
      for(i = 0; i < length - j; i++)
      {
        if(lookup_pali[i + 1][i + j - 1]
           && s[i] == s[i + j])
        {
          lookup_pali[i][i + j] = true;
        }
        else
        {
          lookup_pali[i][i + j] = false;                    
        }
      }
    }
        
    if(lookup_pali[0][length-1])
      return 0;
        
    // calc the dp
    for(i = 0; i < length; i++)
    {
      dp[i] = max;
    }
        
    dp[0] = 0;
        
    for(i = 0; i < length; i++)
    {
      for(j = 0; j < i; j++)
      {
        if(lookup_pali[0][i])
        {
          dp[i] = 0;
          break;
        }
                
        if(dp[j] != max && lookup_pali[j + 1][i])
        {
          if(dp[i] > dp[j] + 1)
          {
            dp[i] = dp[j] + 1;
          }
        }
      }
    }
        
    return dp[length - 1];
  }
};

