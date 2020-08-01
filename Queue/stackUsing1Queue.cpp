
/*
Idea is to use recursion to reverse the stack
while popping and reverse it back
*/
void QueueStack :: push(int x)
{
    q1.push(x);
}

void reverse(queue<int> &q) {
    if (q.empty())
        return;
    int a = q.front();
    q.pop();
    reverse(q);
    q.push(a);
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if (q1.empty())
        return -1;
    // Your Code
    reverse(q1);
    int a = q1.front();
    q1.pop();
    reverse(q1);
    return a;
}