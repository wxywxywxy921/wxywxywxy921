struct node{
  int sum;
  int idx;
    
node(int a, int b):sum(a), idx(b) {}
    
  bool operator < (const node &p) const
    {
      if((sum < p.sum)
         || ((sum == p.sum) && (idx < p.idx)))
      {
        return true;
      }
      else
      {
        return false;
      }
    }
};

class Solution {
public:
  /**
   * @param nums: A list of integers
   * @return: A list of integers includes the index of the first number 
   *          and the index of the last number
   */
  vector<int> subarraySumClosest(vector<int> nums){
    // write your code here
        
    vector<int> ret;
        
    // [0] sanity check
    if(!nums.size())
    {
      ret.push_back(0);
      ret.push_back(0);
            
      return ret;
    }
        
    // [1] create a vector which maintains the sum from 0 to i;
    vector<node> sums;
    int i, sum;
        
    sum = 0;
        
    for(i = 0; i < nums.size(); i++)
    {
      sum += nums[i];
      sums.push_back(node(sum, i));
    }
        
    // [2] sort the sums
    sort(sums.begin(), sums.end());
        
    // [3] find the minimal interval
    int min_sum = 0x7fffffff;
    int lo = 0; 
    int hi = 0;
        
    for(i = 0; i < nums.size() - 1; i++)
    {
      if((sums[i + 1].sum - sums[i].sum) <= min_sum)
      {
        lo = sums[i].idx > sums[i + 1].idx ? sums[i + 1].idx : sums[i].idx;
        hi = sums[i].idx > sums[i + 1].idx ? sums[i].idx : sums[i + 1].idx;
        lo += 1; // This is very important since [i + 1] - [i] doesn't include [i]
        min_sum = sums[i + 1].sum - sums[i].sum;
      }
    }
        
    ret.push_back(lo);
    ret.push_back(hi);
        
    return ret;
  }
};
