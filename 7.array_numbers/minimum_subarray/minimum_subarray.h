class Solution {
public:    
  /**
   * @param nums: A list of integers
   * @return: A integer indicate the sum of max subarray
   */
  int minSubArray(vector<int> nums) {
    // write your code here
        
    if(!nums.size())
      return 0;
           
    int i;
    int local_min, global_min;
        
    local_min = 0;
    global_min = 9999999;
        
    for(i = 0; i < nums.size(); i++)
    {
      if(i == 0)
      {
        local_min = nums[0];
      }
      else
      {
        local_min = min(local_min + nums[i], nums[i]);
      }
            
      if(local_min < global_min)
      {
        global_min = local_min;
      }
    }
        
    return global_min;
  }
};
