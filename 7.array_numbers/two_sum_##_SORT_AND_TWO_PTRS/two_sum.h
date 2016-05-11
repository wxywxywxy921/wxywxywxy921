struct node
{
  int val;
  int idx;
    
node(int _val, int _idx) : val(_val), idx(_idx) {}
    
  bool operator < (const node &p) const
    {
      if((val < p.val)
         || ((val == p.val) && (idx < p.idx )))
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
  /*
   * @param numbers : An array of Integer
   * @param target : target = numbers[index1] + numbers[index2]
   * @return : [index1+1, index2+1] (index1 < index2)
   */
  vector<int> twoSum(vector<int> &nums, int target) {
    // write your code here
        
    vector<node> sort_target;
    int i, j, sum; 
        
        
    // [1] sort
    for(i = 0; i < nums.size(); i++)
    {
      sort_target.push_back(node(nums[i], i));
    }
        
    sort(sort_target.begin(), sort_target.end());
        
    // [2] 2-pointer search
    i = 0; j = nums.size() - 1;
        
    while(1)
    {
      sum = sort_target[i].val + sort_target[j].val;
            
      if(sum == target)
      {
        break;
      }
      else if(sum > target)
      {
        j --;
      }
      else
      {
        i ++;
      }
    }
        
    // [3] return
    vector<int> ret;
        
    ret.push_back(sort_target[i].idx + 1);
    ret.push_back(sort_target[j].idx + 1);
    sort(ret.begin(), ret.end());           // CAUTION!!!!!
        
    return ret;
  }
};
