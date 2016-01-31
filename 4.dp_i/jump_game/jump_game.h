class Solution {
public:
  /**
   * @param A: A list of integers
   * @return: The boolean answer
   */
  bool canJump(vector<int> A) {
    // write you code here
        
    int length = A.size();
    int i,j;
    int dp[length];
        
    memset(dp, 0, length * sizeof(int));
        
    if(A[0])
      dp[0] = true;
    else
    {
      if(1 == length)
      {
        return true;
      }
    }
        
    for(i = 1; i < length; i++)
    {
      for(j = 0; j < i; j++)
      {
        if(dp[j] && A[j] + j >= i)   
        {
          dp[i] = true;
          break;
        }
      }
            
      if(dp[i] == false)
      {
        return false;
      }
    }
        
    return dp[length - 1];
  }
};


bool canJump_greedy(vector<int> A) {
  // write you code here
        
  if ( A.size() == 0) {
    return false;
  }
  int farthest = A[0];
  for (int i = 1; i < A.size(); i++) {
            
    if(i > farthest)
    {
      return false;
    }
            
    if (i <= farthest && A[i] + i >= farthest) {
      farthest = A[i] + i;
    }
  }
  return farthest >= A.size() - 1;
}
