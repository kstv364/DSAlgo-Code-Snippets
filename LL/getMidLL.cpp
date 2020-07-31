/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
  // Your code here
  if (head) {
    Node * p1 , *p2;
    p1 = head; p2 = head;
    while ( p2->next and p2->next->next != NULL) {
      p1 = p1->next;
      p2 = p2->next->next;
    }
    if (p2->next)
      return p1->next->data;
    return p1->data;

  }
  return -1;
}