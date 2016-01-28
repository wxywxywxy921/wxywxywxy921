class Solution {
public:
  /**
   * @param grid: a list of lists of integers.
   * @return: An integer, minimizes the sum of all numbers along its path
   */
  int minPathSum(vector<vector<int> > &grid) {
    // write your code here
        
    int m = grid.size();
    int n = grid.at(0).size();
    int dp[m][n];
    int x,y;
        
    dp[0][0] = grid.at(0).at(0);
        
    for(x = 1; x < n; x++)
    {
      dp[0][x] = grid.at(0).at(x) + dp[0][x-1];
    }
        
    for(y = 1; y < m; y++)
    {
      dp[y][0] = grid.at(y).at(0) + dp[y - 1][0];
    }
        
    for(y = 1; y < m; y++)
    {
      for(x = 1; x < n; x++)
      {
        if(dp[y][x-1] < dp[y-1][x])
        {
          dp[y][x] = dp[y][x-1] + grid.at(y).at(x);
        }
        else
        {
          dp[y][x] = dp[y-1][x] + grid.at(y).at(x);
        }
                
      }
    }
        
    return dp[m-1][n-1];
  }
};
