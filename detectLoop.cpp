bool detectLoop(Node* head)
{
	unordered_set<Node*> set;
	while (head) {
		if (set.find(head) != set.end()) {
			return true;
		}
		set.insert(head);
		head = head->next;
	}
	return false;
}