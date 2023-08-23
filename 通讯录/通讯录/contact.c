#define _CRT_SECURE_NO_WARNINGS

//contact.c - ͨѶ¼����ʵ��
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

//ͨѶ¼��ʼ��
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
		//�ӱ��ؼ������ݵ��ڴ�
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

//static���κ�����ʹfind_by_name()ֻ����contact.c����Ч
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

//1.���
void add_contact(struct contact *p)
{
	add_capacity(p);

	printf("����������:>");
	scanf("%s", &(p->data[p->size].name));
	printf("����������:>");
	scanf("%d", &(p->data[p->size].age));
	printf("�������Ա�:>");
	scanf("%s", &(p->data[p->size].sex));
	printf("������绰:>");
	scanf("%s", &(p->data[p->size].tele));
	printf("�������ַ:>");
	scanf("%s", &(p->data[p->size].addr));
	printf("��ӳɹ�\n");
	p->size++;

}

//2.ɾ��
void del_contact(struct contact *p)
{
	printf("������Ҫɾ������ϵ��:>");
	char name[MAX_NAME] = {0};
	scanf("%s", &name);
	int index = find_by_name(p, name);
	if ( index== -1 )
	{
		printf("û�������\n");
	}
	else
	{
		for (int j = index; j < p->size; j++)
		{
			p->data[j] = p->data[j + 1];
		}
		p->size--;
		printf("��ɾ��\n");
	}
}

//3.����ָ����ϵ��
void search_contact(const struct contact* p)
{
	char name[MAX_NAME] = {0};
	printf("������Ҫ���ҵ���ϵ��:>");
	scanf("%s", name);
	int index = find_by_name(p, name);
	if (-1 == index)
	{
		printf("û�������\n");
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

//4.�޸�ָ����ϵ��
void modify_contact(struct contact *p)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ���ϵ��:>");
	scanf("%s", name);
	int index = find_by_name(p, name);
	if (index == -1)
	{
		printf("û�������\n");
	}
	else
	{
		printf("�����޸���\n\n\n");
		printf("����������:>");
		scanf("%s", &(p->data[index].name));
		printf("����������:>");
		scanf("%d", &(p->data[index].age));
		printf("�������Ա�:>");
		scanf("%s", &(p->data[index].sex));
		printf("������绰:>");
		scanf("%s", &(p->data[index].tele));
		printf("�������ַ:>");
		scanf("%s", &(p->data[index].addr));
		printf("�޸ĳɹ�\n");
	}
}

//5.չʾ�����˵���Ϣ
void show_contact(const struct contact* p)
{
	if(p->size==0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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


//6.����
void sort_contact(struct peoinfo *p, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)//��Ҫn-1��ð������
	{
		int flag = 1;//���������Ѿ�����
		for (j = 0; j < n - i - 1; j++)//ÿһ��ð�������ж�n-i-1��
		{
			//���ܼ���><���жϴ�С�����ö�Ӧ�ıȽϲ���
			if ( strcmp( (p+j)->name,(p+j+1)->name )>0 )
			{
				struct peoinfo t;
				t= *(p+j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = t;

				flag = 0;//������򲻶Ծͽ���if��������flag��ֵ
			}

		}
		if (flag == 1)//����������򣬲������if������ѭ��
			break;
	}
	printf("�����\n");
}

//7.����
void save_contact(contact *p)
{
	//���ڴ汣�浽����
	FILE* pf = fopen("contact.txt", "wb");
	for (int i = 0; i < p->size; i++)
	{
		fwrite(&p->data[i], sizeof(peoinfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
	printf("����ɹ�\n");
}

void destory_contact(contact *p)
{
	free(p->data);
	p = NULL;
}

