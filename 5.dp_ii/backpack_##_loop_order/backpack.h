class Solution {
public:
  /**
   * @param m: An integer m denotes the size of a backpack
   * @param A: Given n items with size A[i]
   * @return: The maximum size
   */
  int backPack(int m, vector<int> A) {
    // write your code here
        
    int size = A.size();
    int dp[m + 1];
    int i, j;
        
    dp[0] = true;
        
    for(i = 0; i <= m; i++)
    {
      dp[i] = false;
    }
        
    for(j = 0; j < size; j++)
    {
      for(i = m; i >= A[j]; i--)
      {
        if(A[j] == i || dp[i - A[j]] == true)
        {
          dp[i] = true;
        }
      }
    }
        
    for(i = m; i >= 0; i--)
    {
      if(dp[i])
      {
        break;
      }
    }
        
    return i;
  }
};
