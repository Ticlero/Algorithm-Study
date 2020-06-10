#pragma once
#include <stdlib.h>

//linked list�� metadata ����
typedef struct linkedList {
	struct node* header;
	struct node* tail;
	struct node* cur;
}L;

//����� ����ü
typedef struct node {
	struct node* next;
	int data;
}node;

void addLinkedListNode(L* list, int data);
void deleteLinkedListNode(L* list, int sdata);
void printLinkedList(L* list);

void addLinkedListNode(L* list, int ndata) {
	//���� �޸� ���(�� �޸�)���� -> stack �޸𸮴� ���� ����� �Ѿ�� �Ǹ� ������� ����.
	node* newNode = (node *)malloc(sizeof(node));

	newNode->next = NULL;
	newNode->data = ndata;

	//�߰� �Ǵ� ��尡 ù ��° ����� ���
	if (list->header == NULL && list->tail == NULL)
	{
		list->header = newNode;
		list->tail = newNode;
	}
	else
	{
		//�߰��ϴ� ��尡 ù ��° ��尡 �ƴ� ���
		//������ �߰��Ͽ� tail�� ����Ű�� �ִ� ����� ���� ��带 newNode�� �ٿ��ش�.
		list->tail->next = newNode;
		//tail�� ��带 newNode�� �ٲ��־� ���� �߰��Ǵ� ��带 ������ ���� ����Ų��.
		list->tail = newNode;
	}
}

void deleteLinkedListNode(L* list, int sdata)
{
	node* p = list->header;
	node* tempPtr = p;

	if (p == NULL)
		return;

	printf("%d ������ ����\n", sdata);
	while (p != NULL)
	{
		if (p->data == sdata)
		{
			if (p == list->header)
			{
				list->header = p->next;
			}
			else {
				tempPtr->next = p->next;
			}

			if (p->next == NULL)
				list->tail = p->next;

			free(p);
			break;
		}
		tempPtr = p;
		p = p->next;
	}
}

void printLinkedList(L* list)
{
	int cnt = 0;
	node* p = list->header;
	while (p != NULL)
	{
		printf("%d ��° ��:%d\n", cnt++, p->data);
		p = p->next;
	}
}