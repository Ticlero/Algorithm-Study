#include <stdlib.h>
#include "sortFunctionsCompilation.h"
#include "linkedList.h";

void printSort()
{
	int arr[16] = { 1, 10, -5, 2, 4, 6, 7, 9, 8, 3, 20, 15, 26, -4, 5, -200 };
	int length = sizeof(arr) / sizeof(int);
	//arrayPrint(selectionSort(arr, length), length, "Selection\0"); //��������
	//arrayPrint(bubbleSort(arr2, length2), length2, "Bubble\0"); //��������
	//arrayPrint(insertionSort(arr3, length3), length3, "insertion\0"); //��������
	quickSort(arr, 0, length - 1); //�� ����
	arrayPrint(arr, length, "Quick\0"); //�� ����
}

int main(void)
{
	//printSort();

	struct linkedList* linkedlist = (linkedList *)malloc(sizeof(linkedList));
	linkedlist->current = NULL;
	linkedlist->head = NULL;
	linkedlist->tail = NULL;

	return 0;
}