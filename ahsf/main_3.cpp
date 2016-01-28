#include <iostream>
/*1.枚举
*[ ]3x6528=3[ ]x8256，括号中填入同一个数使等式成立。
*/
void test_0()
{
	for (int i = 1; i <= 9; i++)
	{
		if ((i * 10 + 3)*6528==(30 + i)*8256)
		{
			printf("\n %d\n", i);
		}
	}
}
/*
*2.[a][b][c]+[d][e][f]=[j][h][i],1-9,不重复
*/
void test_1()
{
	/*
	*1.1-9随机排列
	*2.
	*/
}
int main()
{
	test_0();
	system("pause");
	return 0;
}