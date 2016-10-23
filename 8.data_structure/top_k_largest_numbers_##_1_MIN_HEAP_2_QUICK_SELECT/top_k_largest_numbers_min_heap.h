struct comparator 
{
  bool operator()(int i, int j) 
    {
      return i > j;
    }
};

class Solution {
public:
  /*
   * @param nums an integer array
   * @param k an integer
   * @return the top k largest numbers in array
   */
     
  vector<int> topk(vector<int>& nums, int k) {
    // Write your code here
    priority_queue<int, std::vector<int>, comparator> min_heap;
    int i;
    vector<int> ret;
        
    if(!k || !nums.size())
    {
      return ret;
    }
        
    if(k == nums.size())
    {
      sort(nums.rbegin(), nums.rend());
      return nums;
    }
        
    for(i = 0; i < k; i++)
    {
      min_heap.push(nums[i]);
    }
        
    for(i = k; i < nums.size(); i++)
    {
      if(nums[i] < min_heap.top())
      {
        continue;
      }
      else
      {
        min_heap.pop();
        min_heap.push(nums[i]);
      }
    }
        
    while(min_heap.size())
    {
      ret.push_back(min_heap.top());
      min_heap.pop();
    }
        
    sort(ret.rbegin(), ret.rend());
    return ret;
  }
};
