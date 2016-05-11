class Solution {
public:    
  /**
   * @param word1 & word2: Two string.
   * @return: The minimum number of steps.
   */
  int minDistance(string word1, string word2) {
    // write your code here
        
    int word1_size = word1.size();
    int word2_size = word2.size();
    int i, j;
    int dp[word2_size+1][word1_size+1];
        
    if(!word1_size)
      return word2_size;
            
    if(!word2_size)
      return word1_size;
        
    for(i = 0; i <= word2_size; i++)
    {
      dp[i][0] = i;
    }
        
    for(i = 0; i <= word1_size; i++)
    {
      dp[0][i] = i;
    }
        
    for(i = 1; i <= word2_size; i++)
    {
      for(j = 1; j <= word1_size; j++)
      {
        if(word1[j - 1] == word2[i - 1])
        {
          dp[i][j] = dp[i - 1][j - 1];
        }
        else
        {
          if(dp[i - 1][j] < dp[i][j - 1])
          {
            dp[i][j] = dp[i - 1][j] + 1;
          }
          else
          {
            dp[i][j] = dp[i][j - 1] + 1;
          }
                    
          if(dp[i][j] > dp[i - 1][j - 1] + 1)
          {
            dp[i][j] = dp[i - 1][j - 1] + 1;
          }
        }
      }
    }
        
    return dp[word2_size][word1_size];
  }
};
