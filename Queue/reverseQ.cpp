void reverse(queue<int> &q) {
	if (q.empty())
		return;
	int a = q.front();
	q.pop();
	reverse(q);
	q.push(a);
}

void reverse(queue<int> &q) {
	stack<int> s;
	while (!q.empty()) {
		s.push(q.front());
		q.pop();
	}
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
}