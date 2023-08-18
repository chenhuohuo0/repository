#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
////猜数字游戏
//void menu()
//{
//	printf("**************************\n");
//	printf("****  1.play  0.exit  ****\n");
//	printf("**************************\n");
//}
//
//void game()
//{
//	int x,guess;
//	x = rand() % 100 + 1;
//	//printf("%d\n", x);
//	while (1)
//	{
//		printf("请猜数字：");
//		scanf("%d", &guess);
//		if (guess < x)
//			printf("小了!\n");
//		if (guess > x)
//			printf("大了!\n");
//		if (guess == x)
//		{
//			printf("猜对了！！！");
//			break;
//		}
//
//	}
//
//}
//int main()
//{
//	int input;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择(1/0):>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:game(); break;
//		case 0:printf("退出程序\n"); break;
//		default:printf("输入错误\n"); break;
//		}
//	} while (input);

	



	////9*9乘法口诀表
	//int i, j;
	//for (i = 1; i<= 9; i++)
	//{
	//	for (j = 1; j <= i; j++)
	//	{
	//		printf("%d*%d=%-2d ",j, i, i*j);
	//	}
	//	printf("\n");
	//}

	//char arr1[] = "Hello world!!!!";
	//char arr2[] = "***************";
	//int left = 0, right = strlen(arr1) - 1;//strlen()需要头文件string.h
	//while (left <= right)
	//{
	//	arr2[left] = arr1[left];
	//	arr2[right] = arr1[right];
	//	printf("%s", arr2);
	//	Sleep(1000);//停留1000ms，需要头文件windows.h
	//	system("cls");//清屏，需要头文件stdlib.h
	//	left++; right--;
	//}
	//printf("%s", arr2);//保留最后一次的输出内容


	//对三个数排序
	//int a, b, c, t;
	//scanf("%d%d%d", &a, &b, &c);
	//if (a < b) {
	//	t = a; a = b; b = t;
	//}
	//if (a < c) {
	//	t = a; a = c; c = t;
	//}
	//if (b < c) {
	//	t = b; b = c; c = t;
	//}
	//printf("%d %d %d", a, b, c);


	//求两个数的最大公约数--辗转相除
	//int a, b, x;
	//scanf("%d%d", &a, &b);
	//while (x = a % b) {
	//	a = b;
	//	b = x;
	//}
	//printf("%d", b);


	//打印100-200中的素数
	//int i,j;
	//for (i = 100; i <= 200; i++)
	//{
	//	//试除法--只能被1和他本身整除
	//	for (j = 2; j < sqrt(i); j++)
	//	{
	//		if (i%j == 0)
	//			break;
	//	}
	//	if (j > sqrt(i))
	//		printf("%d ", i);
	//}


	////1-100中整数位出现9的次数
	//int i, count = 0;
	//for (i = 1; i <= 100; i++)
	//{
	//	if (i % 10 == 9)
	//		count++;
	//	if (i / 10 == 9)
	//		count++;
	//}
	//printf("%d\n", count);


	//计算1/1-1/2+1/3-1/4+...+1/99-1/100的值
	/*int i;
	double sum = 0.0;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		sum += flag * 1.0 / i;
		flag = -flag;
	}
	printf("%lf", sum);*/


	////判断1000-2000的闰年
	//
	//for (int year = 1000; year <= 2000; year++)
	//{
	//	if (year % 4 == 0 && year % 100 != 0)
	//		printf("%d ", year);
	//	if (year % 400 == 0)
	//		printf("%d ", year);
	//}


	////打印1~100中3的倍数
	//for (int i = 1; i <= 100; i++) {
	//	if (i % 3 == 0) {
	//		printf("%d ", i);
	//	}
	//}


	//int i;
	//int k;
	//scanf("%d", &k);
	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//for (i = 0; i < n; i++)
	//{
	//	if (k == arr[i])
	//	{
	//		printf("找到了，下标是%d\n", i);
	//		break;
	//	}
	//	if (i == n - 1)
	//	{
	//		printf("数组中没有这个值");
	//	}

	//}
	//int a, b;
	//scanf("%d%d", &a, &b);//&取地址符号
	//int sum = a + b;
	//printf("%d+%d=%d", a, b, sum);
	//return 0;
	
	//char arr1[] = "abc";
	//char arr2[] = { 'a','b','c',0};
	//
	//printf("%s\n", arr1);
	//printf("%s\n", arr2);

	
	//char ret;
	//char password[20] = { 0 };
	//printf("请输入密码:>");
	//scanf("%s", password);//接受用户从键盘上输入的密码，并赋值给password
	//printf("请确认:>");
	//while (getchar() != '\n')
	//{
	//	;//如果没有接收到\n,就执行空语句
	//}
	//ret = getchar();
	//	if (ret == 'Y')
	//	{
	//		printf("确认成功");
	//	}
	//	else
	//	{
	//		printf("确认失败");
	//	}
	

	//int i = 0, j = 0;
	//for (; i < 10; i++)
	//{
	//	for (; j < 10; j++)
	//	{
	//		printf("%d\n", i * 10 + j);
	//	}
	//}


	//int i;
	//int k;
	//scanf("%d", &k);
	//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//for (i = 0; i < n; i++)
	//{
	//	if (k == arr[i])
	//	{
	//		printf("找到了，下标是%d\n", i);
	//		break;
	//	}
	//	if (i == n - 1)
	//	{
	//		printf("数组中没有这个值");
	//	}
	//}


//函数--计算两个数的最大值
//int get_max(int a,int b)
//{
//	int max = a;
//	if (a < b)
//		max = b;
//	return max;
//}


//void swap(int x, int y)
//{
//	int t;
//	t = x; x = y; y = t;
//}
//int main() {
//	//int a = 200, b = 201;
//	//printf("%d\n", get_max(a, b));
//	int a = 10, b = 20;
//	swap(a, b);
//	printf("a=%d b=%d", a, b);
//}


//void swap(int* pa, int* pb)
//{
//	int t = *pa ; *pa= *pb ; *pb= t;
//}
//
//int main() {
//	int a = 10, b = 20;
//	swap(&a, &b);
//	printf("a=%d b=%d", a, b);
//	return 0;
//}


//打印100-200中的素数，不断优化如下，其实还有优化空间
//int main()
//{
//	//打印100-200中的素数，不断优化如下，其实还有优化空间
//	int i, j;
//	for (i = 100; i <= 200; i++)
//	{
//		//试除法--只能被1和他本身整除
//		for (j = 2; j < sqrt(i); j ++)  //sqrt需要头文件math.h
//		{
//			if (i%j == 0)
//				break;
//		}
//		if (j > sqrt(i))
//			printf("%d ", i);
//	}
//}


//函数--判断一个数是不是素数，打印100-200的素数
//int is_prime(int n)//是素数返回1，不是素数返回0
//{
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n%i == 0) {
//			return 0;
//			//return 0执行直接结束函数，所以不需要break
//		}
//	}
//	return 1;//如果程序可以执行到这一步就一定是素数
//}
//int main()
//{
//	int i, n;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}


//int is_leap_year(int y)
//{
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 4000 == 0))
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int y;
//	for (y = 1000; y <= 2000; y++)
//	{
//		if (is_leap_year(y) == 1)
//			printf("%d ", y);
//	}
//	return 0;
//}


////函数--实现有序整型数组中二分查找
//int binary_search(int* arr, int k, int n)
//{
//	//int n=sizeof(arr)/sizeof(arr[0]);  arr是一个指针，不能在函数内部计算数组长度
//	int left = 0, right = n - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//			left = mid + 1;
//		else if (arr[mid] > k)
//			right = mid - 1;
//		else
//			return mid;
//	}
//	return -1;//找到返回下标，没有找到返回-1
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int k; scanf("%d", &k);
//	int ret = binary_search(arr, k, n);
//	if (-1 == ret)
//		printf("数组中没有这个值");
//	else
//		printf("找到了，下标是%d\n", ret);
//	return 0;
//}


////函数--每调用一次，num的值+1
//int add(int* n)
//{
//	(*n)++;
//}
//int main()
//{
//	//涉及到实参的改变，采用传址调用
//	int num = 0;
//	add(&num);
//	printf("%d\n", num);
//	add(&num);
//	printf("%d\n", num);
//	add(&num);
//	printf("%d\n", num);
//	return 0;
//}


////递归--接收一个整型数，打印出他的每一位数
//void print(int n)
//{
//	if (n > 9)
//		print(n / 10);
//	printf("%d ", n % 10);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}


////递归--写一个函数完成strlen()的功能
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
////实际上这个函数用循环也可以实现
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "hello world!";
//	printf("len=%d", my_strlen(arr));
//	return 0;
//}

////递归，求n的阶乘
//int factorial(int n)
//{
//	if (n < 2)
//		return 1;
//	else
//		return n * factorial(n - 1);
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d", factorial(n));
//	return 0;
//}

////递归--求第n个斐波那契数
//int count = 0;
//int fib(int n)
//{
//	
//	if (n == 3)//测试第三个斐波那契数被重复计算的次数
//		count++;
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
////循环--求第n个斐波那契数
//int fib(int n)
//{
//	if (n < 3)
//		return 1;
//	int i;
//	int x1 = 1;
//	int x2 = 1;
//	int x3;
//	for (i = 3; i <= n; i++)
//	{
//		x3 = x1 + x2;
//		x1 = x2;
//		x2 = x3;
//	}
//	return x3;
//}
//int main()
//{
//	int n; scanf("%d", &n);
//	printf("%d\n", fib(n));
//	return 0;
//}


//int main()
//{
//	//数组在内存中是连续存放的
//	char arr[] = "1234567890";
//	int len = strlen(arr);
//	for (int i = 0; i <= len; i++)
//	{
//		printf("&arr[%d]=%p\n", i, &arr[i]);
//	}
//}
////二维数组的遍历
//int arr[3][4] = { {1,2,3},{4,5} };
//int i, j;
//int main() {
//
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("arr[%d][%d]=%p\n", i, j, &arr[i][j]);
//		}
//		
//	}
//}

////冒泡排序
//void bubble_sort(int arr[], int n)
//{
//	int i, j, t;
//	for (i = 0; i < n - 1; i++)//需要n-1轮冒泡排序
//	{
//		int flag = 1;
//		for (j = 0; j < n - i -1; j++)//需要判断n-i+1次
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
//				flag = 0;
//			}
//
//		}
//		if (flag == 1)
//			break;
//	}
//	
//}
//int main()
//{
//	int arr[] = { 10,9,8,7,6,5,4,3,2,1,11,12,14 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, n);
//	//排序完遍历数组
//	for (int i = 0; i < n; i ++ )
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1,2,3 };
//	printf("%p\n", &arr);
//	printf("%p\n", &arr[0]);
//	printf("%d\n", *arr);
//}

//int main()
//{
//	int arr[] = { 1,2,3 };
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0]+1);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);
//}


//int main()
//{
	/*int a = -1;
	int b = a >> 1;
	printf("%d ", b);*/

	//int n, i,count=0;
	//scanf("%d", &n);
	//for (i = 0; i < 32; i++)
	//{
	//	if (1 == ((n >> i) & 1))
	//		count++;
	//}
	//printf("%d\n", count);

	////字符类型赋值为整型，被截断
	//char a = 3;     //00000011
	//char b = 127;   //01111111
	//char c = a + b; //运算时整型提升，以第一位为符号补齐
	////00000000000000000000000000000011
	////00000000000000000000000001111111
	////10000010-c运算完成后被截断
	////整型提升，计算出原码
	////11111111111111111111111110000010
	//printf("%d\n", c);

	//一个应用场景
	//int arr[10] = { 0 };
	//int i;
	//char* p = &arr;//定义char*指针，看内存的改变
	//for (i = 0; i < 10; i++)
	//{
	//	*(p + i) = 1;
	//}
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	/*int a = 0x11223344;
	int* p1 = &a;
	char* p2 = &a;
	printf("%p\n", p1);
	printf("%p\n", p1 + 1);
	printf("%p\n", p2);
	printf("%p\n", p2 + 1);*/

	/*int a = 0;
	int *p = &a;
	printf("%p\n", &a);
	printf("%p\n", p);*/

	/*int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p1 = &arr[0];
	int* p2 = &arr[9];
	printf("%p\n", p1);
	printf("%p\n", p2);
	printf("%d\n", p2-p1);
	printf("%d\n", &arr[9] - &arr[0]);*/


	//统计一个数的二进制表示中1的个数
	/*unsigned int n =-1;
	int count = 0;
	while (n)
	{
		if (n&1==1)
			count++;
		n >>=1;
	}
	printf("%d\n", count);*/


	/*int count = 0;
	int n = -1;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	printf("%d\n", count);*/


	////分别打印一个数的二进制位的奇数位和偶数位
	//int n = 10922;
	//printf("奇数位:");
	//for (int i = 30; i >= 0; i -= 2)
	//{
	//	printf("%d ", (n >> i) & 1);

	//}
	//printf("\n");
	//printf("偶数位:");
	//for (int i = 31; i >= 1; i -= 2)
	//{
	//	printf("%d ", (n >> i) & 1);
	//}
	//printf("\n");


	////使用指针遍历数组
	//int arr[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d ", *(arr + i));
	//}


////递归--逆序一个字符串
//void reverse(char arr[])
//{
//	char t = arr[0];
//	int n = strlen(arr);
//	arr[0] = arr[n - 1];
//	arr[n - 1] = '\0';
//	if (strlen(arr + 1) >= 2)
//		reverse(arr + 1);
//	arr[n - 1] = t;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	reverse(arr);
//	printf("%s\n", arr);
//}

////递归--计算一个数每位数的和
//int sum(unsigned int n)
//{
//	if (n > 9)
//	{
//		int ret1 = sum(n / 10);
//		int ret2 = n % 10;
//		return ret1+ret2;
//	}
//	else
//		return n;
//}
//
//int main()
//{
//	unsigned int n = -1;
//	printf("%d\n", sum(n));
//}


////递归--计算n的k次方
//double pow(int n, int k)
//{
//	int t;
//	if (k < 0)
//		return (1.0 / pow(n, -k));
//	else if (k == 1)
//		return n;
//	else
//		t = n * pow(n, k - 1);
//		return t;
//}
//int main()
//{
//	int n, k;
//	scanf("%d%d", &n, &k);
//	double ret = pow(n, k);
//	printf("%lf\n", ret);
//}


//struct stu
//{
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[2];
//}s1, s2, s3;//创建了3个全局结构体变量

	
////结构体的成员可以是变量，指针，甚至其他结构体
//struct S
//{
//	int a;
//	char c;
//	char arr[20];
//};
//
//struct T
//{
//	char ch[10];
//	struct S s;
//	char *p;
//};
//
//int main()
//{
//	char arr[] = "hello world!!!";
//	struct T t = { "123",{1,'y',"hello world"},arr };
//	printf("%s\n", t.ch);//123
//	printf("%s\n", t.s.arr);//hello world
//	printf("%s\n", t.p);
//}


//typedef struct stu//struct stu是变量类型
//{
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//}stu;
//void print1(stu t)
//{
//	printf("name:%s\n", t.name);
//	printf("age :%d\n", t.age);
//	printf("tele:%s\n", t.tele);
//	printf("sex :%s\n", t.sex);
//}
//void print2(stu* p)
//{
//	printf("name :%s\n", p->name);
//	printf("age  :%d\n", p->age);
//	printf("tele :%s\n", p->tele);
//	printf("sex  :%s\n", p->sex);
//}
//int main()
//{
//	struct stu s = { "张三",20,"12345678900","男" };
//	print2(&s);
//}


////调试
//int main()
//{
//	int i;
//	for (i = 0; i < 100; i++)
//	{
//		printf("%d ", i);
//	}
//	system("pause");
//}
//int main()
//{
	////求1!+2!+3!+...+n!
	//int n, i, sum = 0, ret = 1;
	//scanf("%d", &n);
	//for (i = 1; i <= n; i++)
	//{
	//	ret = ret * i;
	//	sum = sum + ret;
	//}
	//printf("%d\n", sum);
	//调试--死循环
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	for (i = 0; i <= 12; i++)
//	{
//		printf("%d\n", i);
//		arr[i] = 0;
//	}
//}



//#include<assert.h>
////my_strcpy()
//char* my_strcpy(char* arr1,const char* arr2)
//{
//	char* ret = arr1;
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	while (*arr1++ = *arr2++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "#############";
//	char arr2[] = "bit";
//	my_strcpy(arr1, arr2);//将arr2的内容拷贝到arr1
//	printf("%s\n", arr1);
//}



//int main()
//{
//	int a = 0;
//	int* const p = &a;//修饰的是p,此时p不可以被改变,*p可以改变
//	*p = 1;
//	printf("%d\n", *p);
//}



//int main()
//{
	////写一个程序判断当前机器的字节序存储方式
	//int a = 1;
	//char* p = (char*)&a;
	//if (*p == 1)
	//	printf("小端\n");
	//else
	//	printf("大端\n");


	//char a = 128;
	////100000000000000000000010000000 - 原码
	////111111111111111111111101111111 - 反码
	////111111111111111111111110000000 - 补码
	////被截断10000000
	////需要打印前发生整型提升，有符号数按符号位补齐
	////111111111111111111111110000000
	//printf("%u\n", a);
	////%u打印10进制无符号数，%d打印十进制有符号数
	////无符号数补码即是原码111111111111111111111110000000被计算成十进制


	////死循环
	//unsigned char i = 0;
	//for (i = 0; i <= 255; i++)
	//{
	//	printf("%u\n", i);
	//	Sleep(100);
	//}


	/*int n = 9;
	float* p = (float*)&n;
	printf("%d\n", n);
	printf("%f\n", *p);
	*p = 9.0;
	printf("%d\n", n);
	printf("%f\n", *p);*/


	//float a = 5.5;
	////101.1 = (-1)^0*1.011*2^2
	////s=0,E=(2+127=)129,M=1.011
	////0100 0000 1011 0000 0000 0000 0000 0000
	////0x40b00000
	//return 0;


	////第一种定义方式
	//char a = 'a';
	//char* p = &a;
	//printf("%c\n", *p);
	////第二种定义方式
	//char arr[] = "abcdef";
	//char* p = arr;
	//printf("%s\n", arr);
	//printf("%s\n", p);


	////指针数组的应用
	//int arr1[] = { 1,2,3,4,5 };
	//int arr2[] = { 2,3,4,5,6 };
	//int arr3[] = { 3,4,5,6,7 };
	//int* parr[] = { arr1,arr2,arr3 };
	//int i, j;
	//for (i = 0; i < 3; i++)
	//{
	//	for (j = 0; j < 5; j++)
	//	{
	//		printf("%d ", *(parr[i] + j));
	//	}
	//	printf("\n");
	//}


	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int(*p)[10] = &arr;
	//int i;
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d ", (*p)[i]);//(*p)解引用得到arr
	//}
//}


//
//void print(int(*p)[5], int x, int y)
//{
//	int i, j;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", (*(p + i))[j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print(arr, 3, 5);//arr是指向首元素的指针，首元素是{1,2,3,4,5},此时的arr是一个数组指针
//}



////函数指针 - 存放函数的指针
////应用--计算器
//menu()
//{
//	printf("*** 0.exit ***\n");
//	printf("*** 1.add ***\n");
//	printf("*** 2.sub ***\n");
//	printf("*** 3.mul ***\n");
//	printf("*** 4.div ***\n");
//	printf("**************\n");
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int divi(int x, int y)
//{
//	return x / y;
//}
////回调函数--通过函数指针调用的函数
//void calc(int(*p)(int, int))
//{
//	int x, y;
//	printf("请输入两个操作数:>");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", p(x, y));
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请输入:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calc(add); break;
//		case 2:
//			calc(sub); break;
//		case 3:
//			calc(mul); break;
//		case 4:
//			calc(divi); break;
//		case 0:
//			printf("退出\n"); break;
//		default:
//			printf("输入非法，请重试！\n");
//		}
//
//	} while (input);
//}
//int main()
//{
//	int input = 0;
//	int x, y;
//	int(*p[5])(int，int) = { 0,add,sub,mul,divi };
//	do
//	{
//		menu();
//		printf("请输入:>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数:>");
//			scanf("%d%d", &x, &y);
//			int ret = p[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出……\n");
//			break;
//		}
//		else
//		{
//			printf("输入非法，请重试！\n");
//		}
//	} while (input);
//}



//void print(char* arr)
//{
//	printf("%s", arr);
//}
//void test(void(*p)(char*))
//{
//	printf("hello ");
//	p("world");
//}
//int main()
//{
//	test(print);
//}



//struct stu
//{
//	char name[20];
//	int age;
//};
//int cmp_int(const void *e1, const void *e2)
//{
//	return *(int*)e1 - *(int*)e2;
//	//当e1>e2,返回一个>0的数字
//	//当e1<e2,返回一个<0的数字
//	//当e1=e2,返回0,实际上相等返回任意数均可
//}
//int cmp_char(const void *e1, const void *e2)
//{
//	return *(char*)e1 - *(char*)e2;
//}
//int cmp_float(const void *e1, const void *e2)
//{
//	//float强制类型转换会造成精度丢失
//	return *(float*)e1 > *(float*)e2 ? 1 : -1;
//}
//int cmp_struct(const void *e1, const void *e2)
//{
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
//}
//int main()
//{
//	int arr[] = { 9,8,7,5,6,3,4,2,1 };//整型数组
//	char arr1[] = {'c','b','a'};//字符数组
//	struct stu s1 = { "张三",20 };
//	struct stu s2 = { "李四",30 };
//	struct stu s3 = { "王五",18 };
//	struct stu s[] = { s1,s2,s3 };//结构体数组
//	float arr2[] = {  5.0,4.0,3.0,2.0,1.0 };//浮点型数组
//	qsort(arr, 9, sizeof(arr[0]), cmp_int);
//	qsort(arr1, 3, sizeof(arr1[0]), cmp_char);
//	qsort(s, 3, sizeof(s[0]), cmp_struct);
//	qsort(arr2, 5, sizeof(arr2[0]), cmp_float);
//}


////bubble_sort优化 - 接收任意类型数组
//int cmp_int(const void *e1, const void *e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//void swap(char* buf1, char* buf2, int width)
//{
//	char t = *buf1;
//	*buf1 = *buf2;
//	*buf2 = t;
//	buf1++; buf2++;
//}
//
//void bubble_sort(void* base, int n, int width, int(*cmp)(void*e1, void*e2))
//{
//	int i, j, t;
//	for (i = 0; i < n - 1; i++)//需要n-1轮冒泡排序
//	{
//		int flag = 1;//假设数据已经有序
//		for (j = 0; j < n - i - 1; j++)//每一趟冒泡排序判断n-i-1次
//		{
//			//不能简单用><来判断大小，采用对应的比较策略
//			if (cmp((char*)base + j * width, (char*)base + (j + 1)*width) > 0)
//				//base不能解引用，所以先转为char*,再+j*width来决定访问步长
//			{
//				//如果cmp()>0交换两个数的顺序
//				swap((char*)base + j * width, (char*)base + (j + 1)*width, width);
//				flag = 0;//如果排序不对就进入if，并更新flagd的值
//			}
//
//		}
//		if (flag == 1)//如果本身有序，不会进入if，跳出循环
//			break;
//	}
//}
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,3,1 };
//	int n = 7;
//	bubble_sort(arr, n, sizeof(arr[0]), cmp_int);
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	//实际上arr可以是任意数组类型，应该用void*接收
//}



	//struct test
	//{
	//	int num;
	//	char *pcname;
	//	short sdata;
	//	char ch[2];
	//	short s[4];
	//}*p;//20个字节,p是一个结构体指针
	//int main()
	//{
	//	p = (struct test*)0x100000;
	//	printf("%p\n", p + 1);
	//	printf("%p\n", (unsigned long)p + 1);
	//	printf("%p\n", (unsigned int*)p + 1);
	//}
	//指针+1的步长由指针类型决定，数值+1就是单纯+1
	//0x00100014
	//0x00100001
	//0x00100004



//int main()
//{
//	int a[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int *p1 = (int *)(&a + 1);
//	int *p2 = (int *)(*(a + 1));
//	printf("%d %d", *(p1 - 1), *(p2 - 1));//10 5
//}



////逆序字符串
//#include<assert.h>
//void reverse(char* arr)
//{
//	assert(arr);//assert.h
//	int len = strlen(arr);
//	char* left = arr;
//	char* right = arr + len - 1;
//	while (left < right)
//	{
//		char t = *left;
//		*left = *right;
//		*right = t;
//		left++; right-- ;
//	}
//}
//int main()
//{
//	char arr[100];
//	gets(arr);//读取一行存到arr,可以包含空格
//	reverse(arr);
//	printf("%s\n", arr);
//}


//int main()
//{
	////输入n,k,计算n+nn+...+nnn...(k个n)
	//int n, k;
	//scanf("%d%d", &n, &k);
	//int sum = 0;
	//int i;
	//int a = 0;
	//for (i = 0; i < k; i++)
	//{
	//	a = a * 10 + n;
	//	sum = sum + a;
	//}
	//printf("%d\n", sum);


	////判断自幂数，他本身等于他每一位数k次方之和，k是位数，例如153=1^3+5^3+3^3，k=3
	//int n, i, sum = 0;
	//scanf("%d", &n);
	////计算n的位数
	//int m = n, k = 1;
	//while (m / 10)
	//{
	//	k++;
	//	m /= 10;
	//}
	////计算sum
	//m = n;
	//while (m)
	//{
	//	sum += pow(m % 10, k);
	//	m /= 10;
	//}
	//if (n == sum)
	//{
	//	printf("%d是自幂数\n", n);
	//}
	//else
	//{
	//	printf("%d不是自幂数\n",n);
	//}


	////打印菱形
	//printf("请输入要上半部分行数:>");
	//int n; scanf("%d", &n);
	//int i, j;
	////上半部分
	//for (i = 0; i < n; i++)
	//{
	//	//打印空格
	//	for (j = 0; j < n - i - 1; j++)
	//	{
	//		printf(" ");
	//	}
	//	//打印*
	//	for (j = 0; j < 2 * i + 1; j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	////打印下半部分
	//for (i = 0; i < n - 1; i++)
	//{
	//	//打印空格 
	//	for (j = 0; j < i + 1; j++)
	//	{
	//		printf(" ");
	//	}
	//	//打印*
	//	for (j = 0; j < 2 * (n - i) - 3; j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}


//	//1块钱一瓶汽水，两个空瓶再换一瓶汽水，n块钱能喝的汽水数
//	int money;
//	int empty;
//	int sum = 0;
//	scanf("%d", &money);
//
//	sum += money;//喝汽水
//	empty = money;//喝完得到的空瓶
//	while (empty >= 2)
//	{
//		sum = sum + empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", sum);
//}




//调整一个数组的顺序，让奇数全部在前面，偶数全部在后面
void move(int arr[], int n)
{
	int left=0, right = n - 1;
	int t;
	while (left < right)
	{
		//从左边找偶数,不是偶数left+1
		while (left < right&&arr[left] % 2 == 1)
		{
			left++;
		}
		//从右边找奇数,不是奇数right-1
		while (left < right&&arr[right] % 2 == 0)
		{
			right--;
		}
		//交换
		if (left < right)
		{
			t = arr[left]; arr[left] = arr[right]; arr[right] = t;
		}
	}
}
void print(int *arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = { 1,3,5,7,8,7,5,3,1};
	int n = sizeof(arr) / sizeof(arr[0]);
	move(arr, n);
	print(arr, n);
}






