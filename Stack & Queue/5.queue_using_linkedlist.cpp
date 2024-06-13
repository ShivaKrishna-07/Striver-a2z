

// GFG - Implement stack using linkedlist

void stackPush(int x) {
    stackNode * element = new stackNode(x);
    element -> next = top;
    top = element;
    cout << "Element pushed" << "\n";
    size++;
  }
  int stackPop() {
    if (top == NULL) {
      return -1;
    }
    int topData = top -> data;
    stackNode * temp = top;
    top = top -> next;
    delete temp;
    size--;
    return topData;
  }