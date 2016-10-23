class Solution {
public:
  /**
   * @param stk an integer stack
   * @return void
   */
  void stackSorting(stack<int>& stk) {
    // Write your code here
        
    stack<int> helper;
    int temp;
    int cnt, i;
        
    while(!stk.empty())
    {
      temp = stk.top();
      stk.pop();
            
      if(helper.empty() || temp > helper.top())
      {
        helper.push(temp);
      }
      else
      {
        cnt = 0;
                
        while(helper.size() && temp < helper.top())  // [xywu] corner case, the helper is empty!!!
        {
          stk.push(helper.top());
          helper.pop();
          cnt ++;
        }
                
        helper.push(temp);
                
        for(i = 0; i < cnt; i++)
        {
          helper.push(stk.top());
          stk.pop();
        }
      }
    }
        
    stk = helper;
  }
};
