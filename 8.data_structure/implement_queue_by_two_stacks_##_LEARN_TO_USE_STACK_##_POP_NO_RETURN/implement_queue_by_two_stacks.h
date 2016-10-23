class Queue {
public:
  stack<int> stack1;
  stack<int> stack2;
  bool bank;

  Queue() {
    // do intialization if necessary
    bank = true;
  }

  void push(int element) {
    // write your code here
        
    int temp;
        
    if(bank)
    {
      stack1.push(element);
    }
    else
    {
      while(!stack2.empty())
      {
        temp = stack2.top();
        stack2.pop();
        stack1.push(temp);
      }
            
      stack1.push(element);
            
      bank = true;
    }
  }
    
  int pop() {
        
    int temp;
        
    if(bank)
    {
      while(!stack1.empty())
      {
        temp = stack1.top();
        stack1.pop();
        stack2.push(temp);
      }
            
      temp = stack2.top();
      stack2.pop();
            
      bank = false;
    }
    else
    {
      temp = stack2.top();
      stack2.pop();
    }
        
    return temp;
    // write your code here
  }

  int top() {
    // write your code here
        
    int temp;
        
    if(bank)
    {
      while(!stack1.empty())
      {
        temp = stack1.top();
        stack1.pop();
        stack2.push(temp);
      }
            
      temp = stack2.top();
            
      bank = false;
    }
    else
    {
      temp = stack2.top();
    }
        
    return temp;
  }
};
