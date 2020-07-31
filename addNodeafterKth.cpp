void addNode(Node *head, int pos, int data)
{
  // Your code here

  // simplifed that linkedlist is not empty and
  // 0 <= pos <= n - 1
  Node *cur = head;
  while (cur and cur->next and pos--) {
    cur = cur->next;
  }
  Node *k = new Node(data);
  if (cur->next) {
    k->next = cur->next;
    k->next->prev = k;
    cur->next = k;
    cur->next->prev = cur;
  }
  else {
    k->next = cur->next;
    cur->next = k;
    k->prev = cur;
  }


}