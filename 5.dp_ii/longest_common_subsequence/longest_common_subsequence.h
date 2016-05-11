class Solution {
public:
  /**
   * @param A, B: Two strings.
   * @return: The length of longest common subsequence of A and B.
   */
  int max(int a, int b)
  {
    if(a > b)
      return a;
    else
      return b;
  }
     
  int longestCommonSubsequence(string A, string B) {
    // write your code here
        
    int i, j;
    int a_size = A.size();
    int b_size = B.size();
    int dp[a_size + 1][b_size + 1];
        
    if(!a_size || !b_size)
      return 0;
            
    for(i = 0; i <= a_size; i ++)
      dp[i][0] = 0;
            
    for(i = 0; i <= b_size; i ++)
      dp[0][i] = 0;
            
    for(i = 1; i <= a_size; i++)
    {
      for(j = 1; j <= b_size; j++)
      {
        if(A[i-1] == B[j-1])
        {
          dp[i][j] = dp[i-1][j-1] + 1;
        }
        else
        {
          dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
        }
      }
    }
        
    return dp[a_size][b_size];
  }
};
