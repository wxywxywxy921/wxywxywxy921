class Solution {
public:
  /**
   * @param triangle: a list of lists of integers.
   * @return: An integer, minimum path sum.
   */
  int minimumTotal(vector<vector<int> > &triangle) {
    // write your code here
        
    int m = triangle.size();
    int n = triangle.at(m - 1).size();
    int dp[2][n];
    int i, j;
    int temp = 999999;
        
    for(j = 0; j < m; j++)
    {
      for(i = 0; i <= j; i++)
      {
        if(j == 0)
        {
          dp[1][0] = triangle.at(0).at(0);
          break;
        }
        else if(j == 1)
        {
          dp[1][0] = dp[0][0] + triangle.at(1).at(0);
          dp[1][1] = dp[0][0] + triangle.at(1).at(1);
          break;
        }
        else
        {
          if(i == 0)
          {
            dp[1][i] = dp[0][0] + triangle.at(j).at(i);
          }
          else if(i == j)
          {
            dp[1][i] = dp[0][i - 1] + triangle.at(j).at(i);
          }
          else
          {
            if(dp[0][i - 1] < dp[0][i])
            {
              dp[1][i] = dp[0][i - 1] + triangle.at(j).at(i);
            }
            else
            {
              dp[1][i] = dp[0][i] + triangle.at(j).at(i);
            }
          }
        }
      }
      memcpy(&dp[0][0], &dp[1][0], sizeof(int) * n);
    }
        
    for(i = 0 ; i < n; i++)
    {
      if(dp[0][i] < temp)
        temp = dp[0][i];
    }
        
    return temp;
  }
};
