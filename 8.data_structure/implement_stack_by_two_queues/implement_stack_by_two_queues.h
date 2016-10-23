class Stack {
public:
  // Push a new item into the stack
    
  queue<int> first;
  queue<int> second;
    
  void push(int x) {
    // Write your code here
        
    if(second.empty())
    {
      first.push(x);
    }
    else
    {
      second.push(x);
    }
  }

  // Pop the top of the stack
  void pop() {
    // Write your code here
        
    if(first.empty())
    {
      while(second.size() > 1)
      {
        first.push(second.front());
        second.pop();
      }
            
      second.pop();
    }
    else if(second.empty())
    {
      while(first.size() > 1)
      {
        second.push(first.front());
        first.pop();
      }
            
      first.pop();
    }
  }

  // Return the top of the stack
  int top() {
    // Write your code here
        
    if(first.empty())
    {
      return second.back();
    }
    else if(second.empty())
    {
      return first.back();
    }
  }

  // Check the stack is empty or not.
  bool isEmpty() {
    // Write your code here
        
    return first.empty() && second.empty();
  }
};
