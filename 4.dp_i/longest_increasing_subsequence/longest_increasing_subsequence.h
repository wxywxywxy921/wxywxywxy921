class Solution {
public:
  /**
   * @param nums: The integer array
   * @return: The length of LIS (longest increasing subsequence)
   */
  int longestIncreasingSubsequence(vector<int> nums) {
    // write your code here
        
    int length = nums.size();
    int dp[length];
    int i, j;
    int max = 0;
        
    for(i = 0; i < length; i++)
    {
      dp[i] = 1;
    }
        
    for(i = 1; i < length; i++)
    {
      for(j = 0; j < i; j++)
      {
        if(nums[j] <= nums[i] && dp[j] + 1 > dp[i])
        {
          dp[i] = dp[j] + 1;
        }
      }
    }
        
    for(i = 0; i < length; i++)
    {
      if(dp[i] > max)
        max = dp[i];
    }
        
    return max;
  }
};
