#pragma once
#include <stdio.h>

typedef struct node {
	struct node *next;
	int data;
};

typedef struct linkedList{
	struct node *head;
	struct node *tail;
	struct node *current;
} linkedList;

