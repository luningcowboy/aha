#include <iostream>
/*1.½âÃÜqqºÅÂë*/
int q[200];
void decrypt_qq(int nums[], int length);
/*2.queue*/
struct queue{
	int data[100];
	int head;
	int tail;
};
void decrypt_qq_queue(int nums[], int length);
/*3.»ØÎÄÅĞ¶Ï*/
bool is_palindrome(char c[])
{
	int len = strlen(c);
	
	return true;
}
/*²âÊÔ´úÂë*/
void test_decrypt_qq(const char * test_name)
{
	printf("\n=====%s=====\n",test_name);
	for (int i = 0; i < 200;i++)
	{
		q[i] = 0;
	}
	int nums[] = {6,3,1,7,5,8,9,2,4};
	decrypt_qq(nums, 9);
	printf("\n=====%s=====\n", test_name);
}
void test_queue(const char * test_name)
{
	printf("\n=====%s=====\n", test_name);
	int nums[] = { 6, 3, 1, 7, 5, 8, 9, 2, 4 };
	decrypt_qq_queue(nums, 9);
	printf("\n=====%s=====\n", test_name);
}
int main()
{
	//test_decrypt_qq("qq_decrypt");
	test_queue("queue");
	system("pause");
	return 0;
}

void decrypt_qq(int nums[], int length)
{
	int head = 1;
	int tail = head + length;
	for (int i = head; i < tail;i++)
	{
		q[i] = nums[i - 1];
	}

	while (tail > head)
	{
		printf("%d,", q[head]);
		head++;
		tail++;
		q[tail - 1] = q[head];
		head++;
	}
}
void decrypt_qq_queue(int nums[], int length)
{
	struct queue q;
	q.head = 1;
	q.tail = 1;
	for (int i = 0; i < length; i++)
	{
		q.data[q.tail++] = nums[i];
	}
	while (q.head < q.tail)
	{
		printf("%d,", q.data[q.head++]);
		q.data[q.tail++] = q.data[q.head++];
	}
}