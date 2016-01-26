#include <iostream>
#include <ctime>
/*算法代码*/
/*1.桶排序*/
void sort1_0(int nums[], int length);
/*2.冒泡排序*/
void bubble_sort_01(int nums[], int length);
/*3.冒泡排序--struct*/
struct student_01
{
	std::string name;
	char score;
};//结构体存储姓名和分数
void bubble_sort_02(student_01 students[],int length);
/*4.快速排序*/
int quick_arry[10] = { 4, 3, 5, 7, 9, 10, 2, 1, 6, 8 };
void quick_scort_0(int start, int end);
void quick_sort_1(int start, int end);
/*5.小哼买书*/
int book_ISBN[20] = { 1, 2, 2, 3, 1, 11, 22, 33, 44, 11, 22, 2, 33, 55, 66, 897, 234, 1223 ,1112,33234};
void buy_book_0(int start,int end);
void buy_book_0_1();
void buy_book_1();
/*测试代码*/
void test_sort1_0(std::string text_name)
{
	printf("====%s start====\n",text_name.c_str());
	int nums[5] = {2,5,3,5,8};
	sort1_0(nums,5);
	printf("\nend %s====\n", text_name.c_str());
}
void test_bubble_sort_01(const char * test_name)
{
	printf("====%s start====\n", test_name);
	int nums[5] = { 2, 5, 3, 5, 8 };
	bubble_sort_01(nums, 5);
	printf("\nend %s====\n", test_name);
}
void test_bubble_sort_02(const char * test_name)
{
	printf("====%s start====\n", test_name);
	struct student_01 students[5];
	students[0].name = "a";
	students[0].score = 2;
	students[1].name = "b";
	students[1].score = 5;
	students[2].name = "c";
	students[2].score = 3;
	students[3].name = "d";
	students[3].score = 5;
	students[4].name = "e";
	students[4].score = 8;
	bubble_sort_02(students, 5);
	printf("\nend %s====\n", test_name);
}
void test_quick_sort_1(const char * test_name)
{
	printf("====%s start====\n", test_name);
	printf("before sort:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", quick_arry[i]);
	}
	quick_sort_1(0, 9);
	printf("\nafter sort:\n");
	for (int i = 0; i < 10;i++)
	{
		printf("%d,", quick_arry[i]);
	}
	printf("\nend %s====\n", test_name);
}
void test_xhms(const char * test_name)
{
	printf("\n====start %s====\n", test_name);
	printf("\ntime:");
	time_t now;
	now = time(nullptr);
	std::cout << now << std::endl;
	//buy_book_0(0, 19);
	buy_book_1();
	for (int i = 0; i < 20; i++)
	{
		printf("%d,", book_ISBN[i]);
	}
	buy_book_0_1();
	printf("\n");
	time_t now_1;
	now_1 = time(nullptr);
	std::cout << now_1 << std::endl;
	printf("\nend %s====\n", test_name);
}
int main_1()
{

	//test_sort1_0("sort_01");
	//test_bubble_sort_01("bubble_sorle_01");
	//test_bubble_sort_02("bubble_sorle_02");
	//test_quick_sort_1("quick_sort_01");
	test_xhms("小哼买书");
	system("pause");
	return 0;
}


void sort1_0(int nums[], int length)
{
	int all_num[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < length; i++)
	{
		all_num[nums[i]]++;
	}
	//print
	for (int i = 0; i < 11; i++)
	{
		if (all_num[i] > 0)
		{
			for (int j = 0; j < all_num[i]; j++)
			{
				printf("%d", i);
			}
		}
	}
}
void bubble_sort_01(int nums[], int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i; j++)
		{
			if (nums[j] < nums[j + 1])
			{
				int tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < length;i++)
	{
		printf("%d,",nums[i]);
	}
}
void bubble_sort_02(student_01 students[], int length)
{
	for (int i = 0; i < length - 1;i++)
	{
		for (int j = 0; j < length - i; j++)
		{
			if (students[j].score < students[j + 1].score)
			{
				struct student_01 tmp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < length; i++)
	{
		printf("[%s,%d]", students[i].name.c_str(), students[i].score);
	}
}
void quick_scort_0(int start, int end)
{
	int aim = quick_arry[start];
	if (start > end)
		return;

	int tmp = quick_arry[start];
	int i = start;
	int j = end;
	while (i != j)
	{
		while (quick_arry[j] >= aim && i < j)
			j--;
		while (quick_arry[i]<= aim && i < j)
			i++;
		if (i < j)
		{
			int t = quick_arry[i];
			quick_arry[i] = quick_arry[j];
			quick_arry[j] = t;
		}
	}
	quick_arry[start] = quick_arry[i];
	quick_arry[i] = tmp;
	quick_scort_0(start, i-1);
	quick_scort_0(i + 1, end);
}

void quick_sort_1(int start, int end)
{
	if (start > end)
	{
		return;
	}
	int tmp = quick_arry[start];
	int left = start;
	int right = end;
	while (left != right)
	{
		while (quick_arry[right] >= tmp && left < right)
			right--;
		while (quick_arry[left] <= tmp && left < right)
			left++;
		if (left < right)
		{
			int t = quick_arry[left];
			quick_arry[left] = quick_arry[right];
			quick_arry[right] = t;
		}
	}
	quick_arry[start] = quick_arry[left];
	quick_arry[left] = tmp;

	quick_sort_1(start, left - 1);
	quick_sort_1(left + 1, end);
}
void buy_book_0(int start, int end)
{
	if (start>end)
	{
		return;
	}
	int aim = book_ISBN[start];
	int left = start;
	int right = end;
	while (left != right)
	{
		while (book_ISBN[right] >= aim && left < right)
			right--;
		while (book_ISBN[left] <= aim && left < right)
			left++;
		if (left < right)
		{
			int t = book_ISBN[left];
			book_ISBN[left] = book_ISBN[right];
			book_ISBN[right] = t;
		}
	}
	book_ISBN[start] = book_ISBN[left];
	book_ISBN[left] = aim;
	buy_book_0(start, left - 1);
	buy_book_0(left + 1, end);
}
void buy_book_0_1()
{
	int result[20];
	//初始化
	for (int i = 0; i < 20; i++)
	{
		result[i] = -1;
	}
	int cur_idx = 0;
	for (int i = 0; i < 20;i++)
	{
		int isbn = book_ISBN[i];
		bool is_have = false;
		int j = 0;
		while (j<cur_idx)
		{
			if (result[j] == isbn)
			{
				is_have = true;
				break;
			}
			j++;
		}
		if (!is_have)
		{
			result[cur_idx] = isbn;
			cur_idx++;
		}
	}
	printf("\n%d\n", cur_idx);
	for (int i = 0; i < cur_idx;i++)
	{
		printf("%d,", result[i]);
	}
}
void buy_book_1()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20 - i; j++)
		{
			if (book_ISBN[j] > book_ISBN[j+1])
			{
				int t = book_ISBN[j];
				book_ISBN[j] = book_ISBN[j + 1];
				book_ISBN[j + 1] = t;
			}
		}
	}
}