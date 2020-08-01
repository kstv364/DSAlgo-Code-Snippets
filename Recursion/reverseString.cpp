void reverse(char *str, int len)
{

// Your code goes here
	if (len == 1)  return;
	char a = str[0];
	reverse(str + 1 , len - 1);
	for (int i = 1; i < len; i++) {
		str[i - 1] = str[i];
	}
	str[len - 1] = a;
}