#define MAX 99999999

class Solution {
public:
  /**
   * @param A: A list of lists of integers
   * @return: An integer
   */
  int jump(vector<int> A) {
    // wirte your code here
        
    int i, j;
    int length = A.size();
    int dp[length];
        
    if(!length)
    {
      return 0;
    }
        
    for(i = 0; i < length; i++)
    {
      dp[i] = MAX;
    }
        
    dp[0] = 0;
        
    for(i = 1; i < length; i++)
    {
      if(dp[i - 1] < MAX && A[i - 1] + i >= length)
      {
        return dp[i - 1] + 1;
      }
            
      for(j = 0; j < i; j++)
      {
        if(dp[j] < MAX && A[j] + j >= i)
        {
          if(dp[j] + 1 <= dp[i])
          {
            dp[i] = dp[j] + 1;
          }
        }
      }
    }
        
    return dp[length - 1];
  }
};
