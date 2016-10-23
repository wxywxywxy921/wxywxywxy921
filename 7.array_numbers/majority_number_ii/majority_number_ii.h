class Solution {
public:
  /**
   * @param nums: A list of integers
   * @return: The majority number occurs more than 1/3.
   */
  int majorityNumber(vector<int> nums) {
    // write your code here
        
    if(!nums.size())
      return 0;
        
    int cand_0, cand_1, cnt_0, cnt_1;
    int i;
        
    cnt_0 = 0;
    cnt_1 = 0;
        
    for(i = 0; i < nums.size(); i++)
    {
      if(nums[i] == cand_0 && cnt_0)
      {
        cnt_0 ++;
      }
      else if(nums[i] == cand_1 && cnt_1)
      {
        cnt_1 ++;
      }
      else if(!cnt_0)
      {
        cand_0 = nums[i];
        cnt_0 ++;
      }
      else if(!cnt_1)
      {
        cand_1 = nums[i];
        cnt_1 ++;
      }
      else
      {
        cnt_0 --;
        cnt_1 --;
      }
    }
        
    cnt_0 = 0;
    cnt_1 = 0;
        
    for(i = 0; i < nums.size(); i++)
    {
      if(nums[i] == cand_0) cnt_0 ++;
      if(nums[i] == cand_1) cnt_1 ++;
    }
        
    if(cnt_0 > cnt_1)
    {
      return cand_0;
    }
    else
    {
      return cand_1;
    }
  }
};
