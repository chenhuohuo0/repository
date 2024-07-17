#define _CRT_SECURE_NO_WARNINGS

//contact.c - 通讯录功能实现
#include "contact.h"

void add_capacity(contact* p)
{
	if (p->size == p->capacity)
	{
		peoinfo* ptr = (peoinfo*)realloc(p->data, (p->capacity + 2) * sizeof(peoinfo));
		if (ptr != NULL)
		{
			p->data = ptr;
		}
	}
}

//通讯录初始化
void init_contact(contact *p)
{
	p->data = (peoinfo*)malloc(3 * sizeof(peoinfo));
	p->size = 0;
	p->capacity = DEFAULT_SIZE;
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	else
	{
		//从本地加载数据到内存
		peoinfo t;
		while (fread(&t, sizeof(peoinfo), 1, pf))
		{
			add_capacity(p);
			p->data[p->size] = t;
			p->size++;
		}
		fclose(pf);
		pf = NULL;
	}
}

//static修饰函数，使find_by_name()只能在contact.c中生效
static int find_by_name(const struct contact *p, const char arr[MAX_NAME])
{
	int i;
	for (i = 0; i < p->size; i++)
	{
		if (0 == strcmp(p->data[i].name, arr))
		{
			return i;
		}
	}
	return -1;
}

//1.添加
void add_contact(struct contact *p)
{
	add_capacity(p);

	printf("请输入姓名:>");
	scanf("%s", &(p->data[p->size].name));
	printf("请输入年龄:>");
	scanf("%d", &(p->data[p->size].age));
	printf("请输入性别:>");
	scanf("%s", &(p->data[p->size].sex));
	printf("请输入电话:>");
	scanf("%s", &(p->data[p->size].tele));
	printf("请输入地址:>");
	scanf("%s", &(p->data[p->size].addr));
	printf("添加成功\n");
	p->size++;

}

//2.删除
void del_contact(struct contact *p)
{
	printf("请输入要删除的联系人:>");
	char name[MAX_NAME] = {0};
	scanf("%s", &name);
	int index = find_by_name(p, name);
	if ( index== -1 )
	{
		printf("没有这个人\n");
	}
	else
	{
		for (int j = index; j < p->size; j++)
		{
			p->data[j] = p->data[j + 1];
		}
		p->size--;
		printf("已删除\n");
	}
}

//3.查找指定联系人
void search_contact(const struct contact* p)
{
	char name[MAX_NAME] = {0};
	printf("请输入要查找的联系人:>");
	scanf("%s", name);
	int index = find_by_name(p, name);
	if (-1 == index)
	{
		printf("没有这个人\n");
	}
	else
	{
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			p->data[index].name,
			p->data[index].age,
			p->data[index].sex,
			p->data[index].tele,
			p->data[index].addr
		);
	}
}

//4.修改指定联系人
void modify_contact(struct contact *p)
{
	char name[MAX_NAME];
	printf("请输入要修改的联系人:>");
	scanf("%s", name);
	int index = find_by_name(p, name);
	if (index == -1)
	{
		printf("没有这个人\n");
	}
	else
	{
		printf("正在修改中\n\n\n");
		printf("请输入姓名:>");
		scanf("%s", &(p->data[index].name));
		printf("请输入年龄:>");
		scanf("%d", &(p->data[index].age));
		printf("请输入性别:>");
		scanf("%s", &(p->data[index].sex));
		printf("请输入电话:>");
		scanf("%s", &(p->data[index].tele));
		printf("请输入地址:>");
		scanf("%s", &(p->data[index].addr));
		printf("修改成功\n");
	}
}

//5.展示所有人的信息
void show_contact(const struct contact* p)
{
	if(p->size==0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
		for (i = 0; i < p->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				p->data[i].name,
				p->data[i].age,
				p->data[i].sex,
				p->data[i].tele,
				p->data[i].addr
				);
		}
	}
}


//6.排序
void sort_contact(struct peoinfo *p, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)//需要n-1轮冒泡排序
	{
		int flag = 1;//假设数据已经有序
		for (j = 0; j < n - i - 1; j++)//每一趟冒泡排序判断n-i-1次
		{
			//不能简单用><来判断大小，采用对应的比较策略
			if ( strcmp( (p+j)->name,(p+j+1)->name )>0 )
			{
				struct peoinfo t;
				t= *(p+j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = t;

				flag = 0;//如果排序不对就进入if，并更新flag的值
			}

		}
		if (flag == 1)//如果本身有序，不会进入if，跳出循环
			break;
	}
	printf("已完成\n");
}

//7.保存
void save_contact(contact *p)
{
	//从内存保存到本地
	FILE* pf = fopen("contact.txt", "wb");
	for (int i = 0; i < p->size; i++)
	{
		fwrite(&p->data[i], sizeof(peoinfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
	printf("保存成功\n");
}

void destory_contact(contact *p)
{
	free(p->data);
	p = NULL;
}

