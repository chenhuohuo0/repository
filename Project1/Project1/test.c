#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
////��������Ϸ
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
//		printf("������֣�");
//		scanf("%d", &guess);
//		if (guess < x)
//			printf("С��!\n");
//		if (guess > x)
//			printf("����!\n");
//		if (guess == x)
//		{
//			printf("�¶��ˣ�����");
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
//		printf("��ѡ��(1/0):>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:game(); break;
//		case 0:printf("�˳�����\n"); break;
//		default:printf("�������\n"); break;
//		}
//	} while (input);

	



	////9*9�˷��ھ���
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
	//int left = 0, right = strlen(arr1) - 1;//strlen()��Ҫͷ�ļ�string.h
	//while (left <= right)
	//{
	//	arr2[left] = arr1[left];
	//	arr2[right] = arr1[right];
	//	printf("%s", arr2);
	//	Sleep(1000);//ͣ��1000ms����Ҫͷ�ļ�windows.h
	//	system("cls");//��������Ҫͷ�ļ�stdlib.h
	//	left++; right--;
	//}
	//printf("%s", arr2);//�������һ�ε��������


	//������������
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


	//�������������Լ��--շת���
	//int a, b, x;
	//scanf("%d%d", &a, &b);
	//while (x = a % b) {
	//	a = b;
	//	b = x;
	//}
	//printf("%d", b);


	//��ӡ100-200�е�����
	//int i,j;
	//for (i = 100; i <= 200; i++)
	//{
	//	//�Գ���--ֻ�ܱ�1������������
	//	for (j = 2; j < sqrt(i); j++)
	//	{
	//		if (i%j == 0)
	//			break;
	//	}
	//	if (j > sqrt(i))
	//		printf("%d ", i);
	//}


	////1-100������λ����9�Ĵ���
	//int i, count = 0;
	//for (i = 1; i <= 100; i++)
	//{
	//	if (i % 10 == 9)
	//		count++;
	//	if (i / 10 == 9)
	//		count++;
	//}
	//printf("%d\n", count);


	//����1/1-1/2+1/3-1/4+...+1/99-1/100��ֵ
	/*int i;
	double sum = 0.0;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		sum += flag * 1.0 / i;
		flag = -flag;
	}
	printf("%lf", sum);*/


	////�ж�1000-2000������
	//
	//for (int year = 1000; year <= 2000; year++)
	//{
	//	if (year % 4 == 0 && year % 100 != 0)
	//		printf("%d ", year);
	//	if (year % 400 == 0)
	//		printf("%d ", year);
	//}


	////��ӡ1~100��3�ı���
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
	//		printf("�ҵ��ˣ��±���%d\n", i);
	//		break;
	//	}
	//	if (i == n - 1)
	//	{
	//		printf("������û�����ֵ");
	//	}

	//}
	//int a, b;
	//scanf("%d%d", &a, &b);//&ȡ��ַ����
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
	//printf("����������:>");
	//scanf("%s", password);//�����û��Ӽ�������������룬����ֵ��password
	//printf("��ȷ��:>");
	//while (getchar() != '\n')
	//{
	//	;//���û�н��յ�\n,��ִ�п����
	//}
	//ret = getchar();
	//	if (ret == 'Y')
	//	{
	//		printf("ȷ�ϳɹ�");
	//	}
	//	else
	//	{
	//		printf("ȷ��ʧ��");
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
	//		printf("�ҵ��ˣ��±���%d\n", i);
	//		break;
	//	}
	//	if (i == n - 1)
	//	{
	//		printf("������û�����ֵ");
	//	}
	//}


//����--���������������ֵ
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


//��ӡ100-200�е������������Ż����£���ʵ�����Ż��ռ�
//int main()
//{
//	//��ӡ100-200�е������������Ż����£���ʵ�����Ż��ռ�
//	int i, j;
//	for (i = 100; i <= 200; i++)
//	{
//		//�Գ���--ֻ�ܱ�1������������
//		for (j = 2; j < sqrt(i); j ++)  //sqrt��Ҫͷ�ļ�math.h
//		{
//			if (i%j == 0)
//				break;
//		}
//		if (j > sqrt(i))
//			printf("%d ", i);
//	}
//}


//����--�ж�һ�����ǲ�����������ӡ100-200������
//int is_prime(int n)//����������1��������������0
//{
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n%i == 0) {
//			return 0;
//			//return 0ִ��ֱ�ӽ������������Բ���Ҫbreak
//		}
//	}
//	return 1;//����������ִ�е���һ����һ��������
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


////����--ʵ���������������ж��ֲ���
//int binary_search(int* arr, int k, int n)
//{
//	//int n=sizeof(arr)/sizeof(arr[0]);  arr��һ��ָ�룬�����ں����ڲ��������鳤��
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
//	return -1;//�ҵ������±꣬û���ҵ�����-1
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int k; scanf("%d", &k);
//	int ret = binary_search(arr, k, n);
//	if (-1 == ret)
//		printf("������û�����ֵ");
//	else
//		printf("�ҵ��ˣ��±���%d\n", ret);
//	return 0;
//}


////����--ÿ����һ�Σ�num��ֵ+1
//int add(int* n)
//{
//	(*n)++;
//}
//int main()
//{
//	//�漰��ʵ�εĸı䣬���ô�ַ����
//	int num = 0;
//	add(&num);
//	printf("%d\n", num);
//	add(&num);
//	printf("%d\n", num);
//	add(&num);
//	printf("%d\n", num);
//	return 0;
//}


////�ݹ�--����һ������������ӡ������ÿһλ��
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


////�ݹ�--дһ���������strlen()�Ĺ���
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
////ʵ�������������ѭ��Ҳ����ʵ��
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

////�ݹ飬��n�Ľ׳�
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

////�ݹ�--���n��쳲�������
//int count = 0;
//int fib(int n)
//{
//	
//	if (n == 3)//���Ե�����쳲����������ظ�����Ĵ���
//		count++;
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
////ѭ��--���n��쳲�������
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
//	//�������ڴ�����������ŵ�
//	char arr[] = "1234567890";
//	int len = strlen(arr);
//	for (int i = 0; i <= len; i++)
//	{
//		printf("&arr[%d]=%p\n", i, &arr[i]);
//	}
//}
////��ά����ı���
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

////ð������
//void bubble_sort(int arr[], int n)
//{
//	int i, j, t;
//	for (i = 0; i < n - 1; i++)//��Ҫn-1��ð������
//	{
//		int flag = 1;
//		for (j = 0; j < n - i -1; j++)//��Ҫ�ж�n-i+1��
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
//	//�������������
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

	////�ַ����͸�ֵΪ���ͣ����ض�
	//char a = 3;     //00000011
	//char b = 127;   //01111111
	//char c = a + b; //����ʱ�����������Ե�һλΪ���Ų���
	////00000000000000000000000000000011
	////00000000000000000000000001111111
	////10000010-c������ɺ󱻽ض�
	////���������������ԭ��
	////11111111111111111111111110000010
	//printf("%d\n", c);

	//һ��Ӧ�ó���
	//int arr[10] = { 0 };
	//int i;
	//char* p = &arr;//����char*ָ�룬���ڴ�ĸı�
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


	//ͳ��һ�����Ķ����Ʊ�ʾ��1�ĸ���
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


	////�ֱ��ӡһ�����Ķ�����λ������λ��ż��λ
	//int n = 10922;
	//printf("����λ:");
	//for (int i = 30; i >= 0; i -= 2)
	//{
	//	printf("%d ", (n >> i) & 1);

	//}
	//printf("\n");
	//printf("ż��λ:");
	//for (int i = 31; i >= 1; i -= 2)
	//{
	//	printf("%d ", (n >> i) & 1);
	//}
	//printf("\n");


	////ʹ��ָ���������
	//int arr[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d ", *(arr + i));
	//}


////�ݹ�--����һ���ַ���
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

////�ݹ�--����һ����ÿλ���ĺ�
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


////�ݹ�--����n��k�η�
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
//}s1, s2, s3;//������3��ȫ�ֽṹ�����

	
////�ṹ��ĳ�Ա�����Ǳ�����ָ�룬���������ṹ��
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


//typedef struct stu//struct stu�Ǳ�������
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
//	struct stu s = { "����",20,"12345678900","��" };
//	print2(&s);
//}


////����
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
	////��1!+2!+3!+...+n!
	//int n, i, sum = 0, ret = 1;
	//scanf("%d", &n);
	//for (i = 1; i <= n; i++)
	//{
	//	ret = ret * i;
	//	sum = sum + ret;
	//}
	//printf("%d\n", sum);
	//����--��ѭ��
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
//	my_strcpy(arr1, arr2);//��arr2�����ݿ�����arr1
//	printf("%s\n", arr1);
//}



//int main()
//{
//	int a = 0;
//	int* const p = &a;//���ε���p,��ʱp�����Ա��ı�,*p���Ըı�
//	*p = 1;
//	printf("%d\n", *p);
//}



//int main()
//{
	////дһ�������жϵ�ǰ�������ֽ���洢��ʽ
	//int a = 1;
	//char* p = (char*)&a;
	//if (*p == 1)
	//	printf("С��\n");
	//else
	//	printf("���\n");


	//char a = 128;
	////100000000000000000000010000000 - ԭ��
	////111111111111111111111101111111 - ����
	////111111111111111111111110000000 - ����
	////���ض�10000000
	////��Ҫ��ӡǰ���������������з�����������λ����
	////111111111111111111111110000000
	//printf("%u\n", a);
	////%u��ӡ10�����޷�������%d��ӡʮ�����з�����
	////�޷��������뼴��ԭ��111111111111111111111110000000�������ʮ����


	////��ѭ��
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


	////��һ�ֶ��巽ʽ
	//char a = 'a';
	//char* p = &a;
	//printf("%c\n", *p);
	////�ڶ��ֶ��巽ʽ
	//char arr[] = "abcdef";
	//char* p = arr;
	//printf("%s\n", arr);
	//printf("%s\n", p);


	////ָ�������Ӧ��
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
	//	printf("%d ", (*p)[i]);//(*p)�����õõ�arr
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
//	print(arr, 3, 5);//arr��ָ����Ԫ�ص�ָ�룬��Ԫ����{1,2,3,4,5},��ʱ��arr��һ������ָ��
//}



////����ָ�� - ��ź�����ָ��
////Ӧ��--������
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
////�ص�����--ͨ������ָ����õĺ���
//void calc(int(*p)(int, int))
//{
//	int x, y;
//	printf("����������������:>");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", p(x, y));
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("������:>");
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
//			printf("�˳�\n"); break;
//		default:
//			printf("����Ƿ��������ԣ�\n");
//		}
//
//	} while (input);
//}
//int main()
//{
//	int input = 0;
//	int x, y;
//	int(*p[5])(int��int) = { 0,add,sub,mul,divi };
//	do
//	{
//		menu();
//		printf("������:>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("����������������:>");
//			scanf("%d%d", &x, &y);
//			int ret = p[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�����\n");
//			break;
//		}
//		else
//		{
//			printf("����Ƿ��������ԣ�\n");
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
//	//��e1>e2,����һ��>0������
//	//��e1<e2,����һ��<0������
//	//��e1=e2,����0,ʵ������ȷ�������������
//}
//int cmp_char(const void *e1, const void *e2)
//{
//	return *(char*)e1 - *(char*)e2;
//}
//int cmp_float(const void *e1, const void *e2)
//{
//	//floatǿ������ת������ɾ��ȶ�ʧ
//	return *(float*)e1 > *(float*)e2 ? 1 : -1;
//}
//int cmp_struct(const void *e1, const void *e2)
//{
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
//}
//int main()
//{
//	int arr[] = { 9,8,7,5,6,3,4,2,1 };//��������
//	char arr1[] = {'c','b','a'};//�ַ�����
//	struct stu s1 = { "����",20 };
//	struct stu s2 = { "����",30 };
//	struct stu s3 = { "����",18 };
//	struct stu s[] = { s1,s2,s3 };//�ṹ������
//	float arr2[] = {  5.0,4.0,3.0,2.0,1.0 };//����������
//	qsort(arr, 9, sizeof(arr[0]), cmp_int);
//	qsort(arr1, 3, sizeof(arr1[0]), cmp_char);
//	qsort(s, 3, sizeof(s[0]), cmp_struct);
//	qsort(arr2, 5, sizeof(arr2[0]), cmp_float);
//}


////bubble_sort�Ż� - ����������������
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
//	for (i = 0; i < n - 1; i++)//��Ҫn-1��ð������
//	{
//		int flag = 1;//���������Ѿ�����
//		for (j = 0; j < n - i - 1; j++)//ÿһ��ð�������ж�n-i-1��
//		{
//			//���ܼ���><���жϴ�С�����ö�Ӧ�ıȽϲ���
//			if (cmp((char*)base + j * width, (char*)base + (j + 1)*width) > 0)
//				//base���ܽ����ã�������תΪchar*,��+j*width���������ʲ���
//			{
//				//���cmp()>0������������˳��
//				swap((char*)base + j * width, (char*)base + (j + 1)*width, width);
//				flag = 0;//������򲻶Ծͽ���if��������flagd��ֵ
//			}
//
//		}
//		if (flag == 1)//����������򣬲������if������ѭ��
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
//	//ʵ����arr�����������������ͣ�Ӧ����void*����
//}



	//struct test
	//{
	//	int num;
	//	char *pcname;
	//	short sdata;
	//	char ch[2];
	//	short s[4];
	//}*p;//20���ֽ�,p��һ���ṹ��ָ��
	//int main()
	//{
	//	p = (struct test*)0x100000;
	//	printf("%p\n", p + 1);
	//	printf("%p\n", (unsigned long)p + 1);
	//	printf("%p\n", (unsigned int*)p + 1);
	//}
	//ָ��+1�Ĳ�����ָ�����;�������ֵ+1���ǵ���+1
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



////�����ַ���
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
//	gets(arr);//��ȡһ�д浽arr,���԰����ո�
//	reverse(arr);
//	printf("%s\n", arr);
//}


//int main()
//{
	////����n,k,����n+nn+...+nnn...(k��n)
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


	////�ж��������������������ÿһλ��k�η�֮�ͣ�k��λ��������153=1^3+5^3+3^3��k=3
	//int n, i, sum = 0;
	//scanf("%d", &n);
	////����n��λ��
	//int m = n, k = 1;
	//while (m / 10)
	//{
	//	k++;
	//	m /= 10;
	//}
	////����sum
	//m = n;
	//while (m)
	//{
	//	sum += pow(m % 10, k);
	//	m /= 10;
	//}
	//if (n == sum)
	//{
	//	printf("%d��������\n", n);
	//}
	//else
	//{
	//	printf("%d����������\n",n);
	//}


	////��ӡ����
	//printf("������Ҫ�ϰ벿������:>");
	//int n; scanf("%d", &n);
	//int i, j;
	////�ϰ벿��
	//for (i = 0; i < n; i++)
	//{
	//	//��ӡ�ո�
	//	for (j = 0; j < n - i - 1; j++)
	//	{
	//		printf(" ");
	//	}
	//	//��ӡ*
	//	for (j = 0; j < 2 * i + 1; j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	////��ӡ�°벿��
	//for (i = 0; i < n - 1; i++)
	//{
	//	//��ӡ�ո� 
	//	for (j = 0; j < i + 1; j++)
	//	{
	//		printf(" ");
	//	}
	//	//��ӡ*
	//	for (j = 0; j < 2 * (n - i) - 3; j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}


//	//1��Ǯһƿ��ˮ��������ƿ�ٻ�һƿ��ˮ��n��Ǯ�ܺȵ���ˮ��
//	int money;
//	int empty;
//	int sum = 0;
//	scanf("%d", &money);
//
//	sum += money;//����ˮ
//	empty = money;//����õ��Ŀ�ƿ
//	while (empty >= 2)
//	{
//		sum = sum + empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", sum);
//}




//����һ�������˳��������ȫ����ǰ�棬ż��ȫ���ں���
void move(int arr[], int n)
{
	int left=0, right = n - 1;
	int t;
	while (left < right)
	{
		//�������ż��,����ż��left+1
		while (left < right&&arr[left] % 2 == 1)
		{
			left++;
		}
		//���ұ�������,��������right-1
		while (left < right&&arr[right] % 2 == 0)
		{
			right--;
		}
		//����
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






