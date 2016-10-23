class Solution {
public:
  /**
   * @param nums: A list of integers
   * @return: An integer indicate the value of maximum difference between two
   *          Subarrays
   */
  int maxDiffSubArrays(vector<int> nums) {
    // write your code here
        
    if(!nums.size() || nums.size() == 1)
    {
      return 0;
    }
        
    vector<int> left_max(nums.size());
    vector<int> left_min(nums.size());
    vector<int> right_max(nums.size());
    vector<int> right_min(nums.size());
    int i = 0;
    int local_max, local_min;
        
    local_max = -999999;
    local_min = 999999;
        
    for(i = 0; i < nums.size(); i++)
    {
      if(i == 0)
      {
        left_max[i] = nums[i];
        left_min[i] = nums[i];
      }
      else
      {
        left_max[i] = max(left_max[i - 1] + nums[i], nums[i]);
        left_min[i] = min(left_min[i - 1] + nums[i], nums[i]);
      }
    }
        
    for(i = nums.size() - 1; i >= 0; i--)
    {
      if(i == nums.size() - 1)
      {
        right_max[i] = nums[i];
        right_min[i] = nums[i];
      }
      else
      {
        right_max[i] = max(right_max[i + 1] + nums[i], nums[i]);
        right_min[i] = min(right_min[i + 1] + nums[i], nums[i]);
      }
    }
        
    int ret = -999999;
        
    for(i = 0; i < nums.size() - 1; i++)
    {
      if(abs(right_max[i + 1] - left_min[i]) > ret)
      {
        ret = abs(right_max[i + 1] - left_min[i]);
      }
      if(abs(left_max[i] - right_min[i + 1]) > ret)       // REMEMBER RIGHT ALWAYS + 1
      {
        ret = abs(left_max[i] - right_min[i + 1]);
      }
    }
        
    return ret;
  }
};
