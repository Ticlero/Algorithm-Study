#include <stdlib.h>
#include "sortFunctionsCompilation.h"
#include "linkedList.h";

void printSort()
{
	int arr[16] = { 1, 10, -5, 2, 4, 6, 7, 9, 8, 3, 20, 15, 26, -4, 5, -200 };
	int length = sizeof(arr) / sizeof(int);
	//arrayPrint(selectionSort(arr, length), length, "Selection\0"); //선택정렬
	//arrayPrint(bubbleSort(arr2, length2), length2, "Bubble\0"); //버블정렬
	//arrayPrint(insertionSort(arr3, length3), length3, "insertion\0"); //삽입정렬
	quickSort(arr, 0, length - 1); //퀵 정렬
	arrayPrint(arr, length, "Quick\0"); //퀵 정렬
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