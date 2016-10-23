class MinStack {
public:
    
  stack<int> norm_stack;
  stack<int> min_stack;
  int curr_min;
    
  MinStack() {
    // do initialization if necessary
        
    curr_min = 99999999;
  }

  void push(int number) {
    // write your code here
        
    norm_stack.push(number);
        
    if(curr_min > number)
    {
      curr_min = number;
      min_stack.push(curr_min);
    }
    else
    {
      min_stack.push(curr_min);
    }
  }

  int pop() {
    // write your code here
    int temp = norm_stack.top();
    min_stack.pop();
    norm_stack.pop();
        
    if(min_stack.empty())
    {
      curr_min = 999999;
    }
    else
    {
      curr_min = min_stack.top();
    }
            
    return temp;
  }

  int min() {
    // write your code here
        
        
    return min_stack.top();
  }
};
