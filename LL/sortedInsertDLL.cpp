/*structure of the node of the DLL is as
struct Node {
	int data;
	struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
//Return the head after insertion
Node* sortedInsert(Node * head, int x)
{
	// Code here
	Node * cur = head;
	Node * k = getNode(x);
	if (!head)
		return k;
	while (cur) {
		if (cur->data > x) {
			if (cur->prev) {
				k->next = cur;
				k->prev = cur->prev;
				cur->prev->next = k;
				cur->prev = k;
			}
			else {
				k->next = cur;
				k->prev = NULL;
				cur->prev = k;
				head = k;
			}
			return head;
		}
		else if (!cur->next) {
			cur->next = k;
			k->prev = cur;
			return head;
		}
		cur = cur->next;
	}
}