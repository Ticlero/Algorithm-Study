#pragma once
#include <stdlib.h>

//linked list의 metadata 정보
typedef struct linkedList {
	struct node* header;
	struct node* tail;
	struct node* cur;
}L;

//노드의 구초체
typedef struct node {
	struct node* next;
	int data;
}node;

void addLinkedListNode(L* list, int data);
void deleteLinkedListNode(L* list, int sdata);
void printLinkedList(L* list);

void addLinkedListNode(L* list, int ndata) {
	//동적 메모리 사용(힙 메모리)이유 -> stack 메모리는 지역 블록을 넘어가게 되면 사라지기 때문.
	node* newNode = (node *)malloc(sizeof(node));

	newNode->next = NULL;
	newNode->data = ndata;

	//추가 되는 노드가 첫 번째 노드일 경우
	if (list->header == NULL && list->tail == NULL)
	{
		list->header = newNode;
		list->tail = newNode;
	}
	else
	{
		//추가하는 노드가 첫 번째 노드가 아닐 경우
		//이전에 추가하여 tail이 가리키고 있던 노드의 다음 노드를 newNode로 붙여준다.
		list->tail->next = newNode;
		//tail의 노드를 newNode로 바꿔주어 새로 추가되는 노드를 마지막 노드로 가리킨다.
		list->tail = newNode;
	}
}

void deleteLinkedListNode(L* list, int sdata)
{
	node* p = list->header;
	node* tempPtr = p;

	if (p == NULL)
		return;

	printf("%d 데이터 삭제\n", sdata);
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
		printf("%d 번째 값:%d\n", cnt++, p->data);
		p = p->next;
	}
}