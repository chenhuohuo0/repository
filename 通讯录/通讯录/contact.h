#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_SEX 5
#define MAX_ADDR 20

#define DEFAULT_SIZE 3

enum f
{
	EXIT,
	add,
	del,
	search,
	modify,
	show,
	sort
};

typedef struct peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}peoinfo;

typedef struct contact
{
	struct peoinfo* data;
	int size;
	int capacity;
}contact;

//ͨѶ¼��ʼ��
void init_contact(struct contact *p);

//1.�����ϵ��
void add_contact(struct contact *p);

//2.ɾ����ϵ��
void del_contact(struct contact *p);

//3.����ָ����ϵ��
void search_contact(const struct contact* p);

//4.�޸�ָ����ϵ��
void modify_contact(struct contact *p);

//5.չʾ�����˵���Ϣ
void show_contact(const struct contact *p);

//6.����
void sort_contact(struct peoinfo *p, int n);

void destory_contact(contact *p);


