class Solution {
public:
  /**
   * @param A: an integer array.
   * @param k: a positive integer (k <= length(A))
   * @param target: a integer
   * @return an integer
   */
  int kSum(vector<int> A, int k, int target) {
    // wirte your code here
        
    int a_size = A.size();
    int dp[a_size + 1][k + 1][target + 1];
    int i, j, l;
        
    memset(&dp[0][0][0], 0, sizeof(int) * (a_size + 1) *(k + 1)*(target + 1));
        
    for(i = 0; i <= a_size; i++)
    {
      dp[i][0][0] = 1;
    }
        
    for(i = 1; i <= a_size; i++)
    {
      for(j = 1; j < k + 1; j++)
      {
        for(l = 1; l < target + 1; l++)
        {
          if(A[i - 1] > l)
          {
            dp[i][j][l] = dp[i - 1][j][l];
          }
          else
          {
            dp[i][j][l] = dp[i - 1][j - 1][l - A[i - 1]] + dp[i - 1][j][l];
          }
                    
        }
      }
    }
        
    return dp[a_size][k][target];
  }
};
