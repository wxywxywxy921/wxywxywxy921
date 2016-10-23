struct Node
{
  int val;
  Node *next;
  Node *prev;
};

class Stack {
public:

  Node *curr;

  Stack()
  {
    curr = NULL;
  }

  // Push a new item into the stack
  void push(int x) {
    // Write your code here
        
    if(curr == NULL)
    {
      curr = new Node;
      curr->val = x;
      curr->prev = NULL;
      curr->next = NULL;
    }
    else
    {
      curr->next = new Node;
      curr->next->next = NULL;
      curr->next->val = x;
      curr->next->prev = curr;
      curr = curr->next;
    }
  }

  // Pop the top of the stack
  void pop() {
    // Write your code here
        
    if(curr != NULL)
    {
      Node *temp = curr;
            
      curr = curr->prev;
            
      if(curr != NULL) // !!!!!!!!!!!for the case the curr is NULL after pop
      {
        curr->next = NULL;
      }
            
      delete[] temp;
    }
  }

  // Return the top of the stack
  int top() {
    // Write your code here
        
    if(curr != NULL)
    {
      return curr->val;
    }
    else
    {
      return 0;
    }
  }

  // Check the stack is empty or not.
  bool isEmpty() {
    // Write your code here
        
    return curr == NULL;
  }
};
