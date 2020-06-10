#include "sortFunctionsCompilation.h"
#include "linkedList.h"

void sortFunctions()
{
	int arr[10] = { 15, 55, 12, 6, 36, 22, 9 ,75, 47, 98 };

	int length = sizeof(arr) / sizeof(int);

	//arrayPrint(selectionSort(arr, length), length, "Selection\0"); //선택정렬
	//arrayPrint(bubbleSort(arr, length), length, "Bubble\0"); //버블정렬
	//arrayPrint(insertionSort(arr, length), length, "insertion\0"); //삽입정렬
	//arrayPrint(insertionSort2(arr, length), length, "insertion\0"); //삽입정렬
	//quickSort(arr, 0, length - 1);
	//arrayPrint(arr, length, "Quick Sort");

	mergeSort(arr, 0, length - 1);
	arrayPrint(arr, length, "Merge Sort");
}

int main(void)
{
	//sortFunctions();

	L* l = (L *)malloc(sizeof(L));
	l->header = NULL;
	l->tail = NULL;
	l->cur = NULL;

	addLinkedListNode(l, 10);
	addLinkedListNode(l, 20);
	addLinkedListNode(l, 30);
	printLinkedList(l);
	printf("삭제\n");
	deleteLinkedListNode(l, 20);
	printLinkedList(l);
	printf("tail:[%d] \n", l->tail->data);
	addLinkedListNode(l, 40);
	addLinkedListNode(l, 50);
	printLinkedList(l);
	printf("tail:[%d] \n", l->tail->data);
	deleteLinkedListNode(l, 10);
	printLinkedList(l);
	return 0;
}