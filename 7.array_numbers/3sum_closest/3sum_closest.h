struct node
{
  int val;
  int idx;
    
node(int _val, int _idx) : val(_val), idx(_idx) {}
    
  bool operator < (const node &p) const
    {
      if((val < p.val)
         ||((val == p.val) &&(idx < p.idx)))
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
   * @param numbers: Give an array numbers of n integer
   * @param target: An integer
   * @return: return the sum of the three integers, the sum closest target.
   */
  int threeSumClosest(vector<int> nums, int target) {
    // write your code here
        
    int i, j, k, min_dist, sum;
    vector<node> sorted_node;
        
    min_dist = 0x7fffffff;
    sum = 0;
        
    for(i = 0; i < nums.size(); i ++)
    {
      sorted_node.push_back(node(nums[i], i));
    }
        
    sort(sorted_node.begin(), sorted_node.end());
        
    for(i = 0; i < (nums.size() - 2); i ++)
    {
      j = i + 1;
      k = nums.size() - 1;
            
      while(j < k)
      {
        if(abs(target - sorted_node[i].val - sorted_node[j].val - sorted_node[k].val) < min_dist)
        {
          min_dist = abs(target - sorted_node[i].val - sorted_node[j].val - sorted_node[k].val);
          sum = sorted_node[i].val + sorted_node[j].val + sorted_node[k].val;
        }
                    
        if(target > (sorted_node[i].val + sorted_node[j].val + sorted_node[k].val))
        {
          j ++;
        }
        else if(target < (sorted_node[i].val + sorted_node[j].val + sorted_node[k].val))
        {
          k --;
        }
        else
        {
          goto _EXIT;
        }
      }
    }
        
  _EXIT:        
    return sum;
  }
};
