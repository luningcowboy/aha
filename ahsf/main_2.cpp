#include <iostream>
/*1.解密qq号码*/
int q[200];
void decrypt_qq(int nums[], int length);
/*2.queue*/
struct queue{
	int data[1000];
	int head;
	int tail;
};//队列
void decrypt_qq_queue(int nums[], int length);
/*3.回文判断*/
bool is_palindrome(char c[])
{
	int len = strlen(c);
	char s[100];
	int top = -1;
	int mid = len / 2;
	for (int i = 0; i < mid;i++)
	{
		s[++top] = c[i];
	}
	int start = (len % 2 == 0) ? mid : mid + 1;
	for (int i = 0; i < mid;i++)
	{
		if (s[top--] != c[start++])
		{
			printf("false");
			return false;
		}
	}
	printf("true");
	return true;
}
/*4.链表*/
void list_0()
{
	int a = 10;
	int *p;
	p = &a;
	printf("%d", *p);
}
void list_1()
{
	int *p;
	p = (int *)malloc(sizeof(int));
	*p = 10;
	printf("%d", *p);
}
struct node
{
	int data;
	struct node *next;

};
void list_2();
void list_3();
/*模拟链表*/
void list_4();
/*测试代码*/
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
void test_palindrome(const char* test_name)
{
	printf("\n=====%s=====\n", test_name);
	is_palindrome("ababa");
	is_palindrome("abba");
	is_palindrome("abcaba");
	is_palindrome("abacba");
	printf("\n=====%s=====\n", test_name);
}
/*小猫钓鱼*/
struct stack{
	int data[1000];
	int top;
};//栈
void test_cat_fish(const char * test_name)
{
	struct queue ha;//小哈手中的牌
	struct queue heng;//小哼手中的牌
	struct stack desk;//桌面上的牌
	//初始化
	ha.head = 0;
	ha.tail = 0;
	heng.head = 0;
	heng.tail = 0;
	desk.top = -1;
	int ha_arr[] = {2,4,1,2,5,6};
	int heng_arr[] = {3,1,3,5,6,4};
	for (int i = 0; i < 6;i++)
	{
		ha.data[ha.tail++] = ha_arr[i];
		heng.data[heng.tail++] = heng_arr[i];
	}
	//出牌
	while (ha.head != ha.tail && heng.head != heng.tail)
	{
		//小哼出牌
		desk.data[++desk.top] = heng.data[heng.head++];
		bool is_win_card = false;
		for (int i = 0; i < desk.top; i++)
		{
			if (desk.data[i] == desk.data[desk.top])
			{
				is_win_card = true;
				break;
			}
		}
		//赢牌
		if (is_win_card)
		{
			int tmp = desk.data[desk.top];
			while (tmp != desk.data[desk.top])
			{
				heng.data[heng.tail++] = desk.data[desk.top--];
			}
			heng.data[heng.tail++] = desk.data[desk.top--];
		}
		//是否输牌
		if (heng.head == heng.tail)
		{
			break;
		}
		is_win_card = false;
		//小哈出牌
		desk.data[++desk.top] = ha.data[ha.head++];
		for (int i = 0; i < desk.top; i++)
		{
			if (desk.data[i] == desk.data[desk.top])
			{
				is_win_card = true;
				break;
			}
		}
		//赢牌
		if (is_win_card)
		{
			int tmp = desk.data[desk.top];
			while (tmp != desk.data[desk.top])
			{
				ha.data[ha.tail++] = desk.data[desk.top--];
			}
			ha.data[ha.tail++] = desk.data[desk.top--];
		}
		//是否输牌
		if (ha.head == ha.tail)
		{
			printf("小哈输了\n");
			break;
		}
		printf("\n============================\n");
		//小哼的牌
		printf("小哼的牌:");
		for (int i = heng.head; i < heng.tail;i++)
		{
			printf("%d,", heng.data[i]);
		}
		printf("\n");
		//小哈的牌
		printf("小哈的牌:");
		for (int i = ha.head; i < ha.tail; i++)
		{
			printf("%d,", ha.data[i]);
		}
		printf("\n");
		//牌堆
		printf("牌堆:");
		for (int i = 0; i <= desk.top; i++)
		{
			printf("%d,", desk.data[i]);
		}
		printf("\n");
		printf("\n============================\n");

	}
}
void test_cat_fish_02(const char * test_name)
{
	struct queue q1, q2;
	struct stack s;
	int book[10];
	int i, t;
	//初始化队列
	q1.head = 1; q1.tail = 1;
	q2.head = 1; q2.tail = 1;
	//初始化栈
	s.top = 0;
	//初始化用来标记的数组
	for (int i = 1; i <= 9; i++)
	{
		book[i] = 0;
	}
	int ha_arr[] = { 2, 4, 1, 2, 5, 6 };
	int heng_arr[] = { 3, 1, 3, 5, 6, 4 };
	for (i = 1; i <= 6; i++)
	{
		q1.data[q1.tail++] = ha_arr[i-1];
		q2.data[q2.tail++] = heng_arr[i-1];
	}
	
	while (q1.head < q1.tail
		&& q2.head < q2.tail)
	{
		t = q1.data[q1.head];
		if (book[t] == 0)
		{
			q1.head++;
			s.data[++s.top] = t;
			book[t] = 1;
		}
		else
		{
			q1.head++;
			q1.data[q1.tail++] = t;
			while (s.data[s.top]!= t)
			{
				book[s.data[s.top]] = 0;
				q1.data[q1.tail++] = s.data[s.top--];
			}
		}
		t = q2.data[q2.head];
		if (book[t]==0)
		{
			q2.head++;
			s.data[s.top++] = t;
			book[t] = 1;
		}
		else
		{
			q2.head++;
			q2.data[q2.tail++] = t;
			while (s.data[s.top] != t)
			{
				book[s.data[s.top]] = 0;
				q2.data[q2.tail++] = s.data[s.top--];
			}
		}
	}
	if (q2.head == q2.tail)
	{
		printf("q2 win\n");
	}
	else
	{
		printf("q1 win\n");
	}
}
int main_2()
{
	//test_decrypt_qq("qq_decrypt");
	//test_queue("queue");
	//test_palindrome("palindrome");
	//test_cat_fish_02("小猫钓鱼");
	//list_0();
	//list_1();
	//list_2();
	//list_3();
	list_4();
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
void list_2()
{
	struct node *head, *p, *q, *t;
	int i, n, a;
	head = nullptr;
	head = (struct node *)malloc(sizeof(struct node));
	head->data = 10;
	p = (struct node*)malloc(sizeof(struct node));
	p->data = 20;
	head->next = p;
	q = (struct node*)malloc(sizeof(struct node));
	q->data = 30;
	p->next = q;
	q->next = nullptr;

	t = head;
	while (t != nullptr)
	{
		printf("%d,", t->data);
		t = t->next;
	}
}
void list_3()
{
	//新建一个列表并插入新的值
	int a[] = {1,2,5,7,8};
	struct node * head = (struct node*)(malloc(sizeof(struct node)));
	head->data = a[0];
	head->next = nullptr;
	struct node * tmp = nullptr;
	for (int i = 1; i < sizeof(a) / sizeof(int);i++)
	{
		struct node * next = (struct node*)(malloc(sizeof(struct node)));
		next->data = a[i];
		next->next = nullptr;
		if (head->next == nullptr)
		{
			head->next = next;
			tmp = next;
		}
		else
		{
			tmp->next = next;
			tmp = next;
		}
	}
	tmp = head;
	while (tmp != nullptr)
	{
		printf("%d,",tmp->data);
		tmp = tmp->next;
	}
	bool loop = true;
	tmp = head;
	int in_data = 6;
	while (loop)
	{
		if (tmp->data < in_data 
			&& tmp->next != nullptr 
			&& tmp->next->data >= in_data)
		{
			loop = false;
			struct node * n = (struct node*)malloc(sizeof(struct node*));
			n->data = in_data;
			n->next = tmp->next;
			tmp->next = n;
		}
		else if (tmp->next == nullptr)
		{
			struct node * n = (struct node*)malloc(sizeof(struct node*));
			n->data = in_data;
			tmp->next = n;
			n->next = nullptr;
			loop = false;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	
	in_data = 4;
	tmp = head;
	loop = true;
	while (loop)
	{
		if (tmp->data < in_data
			&& tmp->next != nullptr
			&& tmp->next->data >= in_data)
		{
			loop = false;
			struct node * n = (struct node*)malloc(sizeof(struct node*));
			n->data = in_data;
			n->next = tmp->next;
			tmp->next = n;
		}
		else if (tmp->next == nullptr)
		{
			struct node * n = (struct node*)malloc(sizeof(struct node*));
			n->data = in_data;
			tmp->next = n;
			n->next = nullptr;
			loop = false;
		}
		else
		{
			tmp = tmp->next;
		}
	}

	tmp = head;
	printf("\n");
	while (tmp != nullptr)
	{
		printf("%d,", tmp->data);
		tmp = tmp->next;
	}
}
int data[10] = {1,2,3,4,5,6,7,8,9,10};
int right[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//存储数据右侧的idx
void list_4()
{
	int itor = 0;
	for (int i = 0; i <=9;i++)
	{
		printf("Value:%d,idx:%d,Next:[idx:%d,value:%d]\n", data[i],i,right[i],data[right[i]]);
	}
}