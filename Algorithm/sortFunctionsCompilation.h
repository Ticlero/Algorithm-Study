#pragma once
#include <stdio.h>

void arrayPrint(int* arr, int length, char* des);
int* selectionSort(int* arr, int length);
int* bubbleSort(int* arr, int length);
int* insertionSort(int* arr, int length);
void quickSort(int* arr, int start, int end);

void arrayPrint(int* arr, int length, char* des) {
	int i;
	printf("%s\n	", des);
	for (i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//��������
//"���� ���� ���� ã�Ƽ� �� ������(<-> ���� ū ���� ã�Ƽ� �� ������) ������ �����ϴ� �˰���"
//�ð� ���⵵�� O(n^2);
int* selectionSort(int* arr, int length) {
	int i, j, min, index, temp;
	for (i = 0; i < length; i++) {
		min = 9999;
		for (j = i; j < length; j++) //i��°~10���� ��ȸ�ϸ鼭 ���� ���� ���� ã��
		{
			if (arr[j] < min) { //j��°�� ���� min�� ������ �۴ٸ�
				index = j; //j��°�� �ε��� ���� �� �����ϱ�
				min = arr[j];
			}
		}
		temp = arr[i];
		arr[i] = min;
		arr[index] = temp;
	}

	return arr;
}

//��������
//"���� �ִ� ���� ���ؼ� ���� ���� ������ ������"
//����Ŭ �������� ���� ū ���� �ڷ� ��������.
//�� ����Ŭ ���� ���Ͽ� �����ϹǷ� ���� �� ���� ���� ���
//�ð� ���⵵�� O(n^2);
int* bubbleSort(int* arr, int length)
{
	int i, j, temp;
	for (i = 0; i < length - 1; i++) { //�迭 ������ -1 ��ŭ cycle�� ����.

		//�� ������ ���ڴ� ���� ū ������ ���ĵǱ� ������, �迭�� ���� - (cycle ��(i) - 1)��ŭ ���Ͽ� �����Ѵ�.
		for (j = 0; j < length - (i + 1); j++) {
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr;
}

//��������
//"���� ������ ��ġ�� �����ϱ�"
//�ڷ� �迭�� ��� ��Ҹ� �տ������� ���ʴ�� �̹� ���ĵ� �迭 �κа� �� �Ͽ�, �ڽ��� ��ġ�� ã�� ���������ν� ������ �ϼ��ϴ� �˰���
//���� ������ �⺻������ '������ �Ǿ� �ִٰ� ����'
//�� �������� �ش� ���Ҹ� ������ �� �ִ� ��ġ�� ã�� �ش� ��ġ�� �ִ´�.
//https://gmlwjd9405.github.io/2018/05/06/algorithm-insertion-sort.html
//�ð� ���⵵�� �⺻������ O(n^2)������ �� ���ĵ� �ڷ� ������ �� ���� �񱳰� �Ͼ��  O(n)�̴�.

int* insertionSort(int* arr, int length)
{
	int i, j, k, key, fork;

	for (i = 1; i < length; i++) { //���� ������ �� ��° �ڷ������� ����. ( 0�� �ƴ� 1����)
		key = arr[i]; //�񱳰� �� ���� ��
		fork = i; //���Ե� ��ġ�� �˷��ִ� ��

		//���Ե� ��ġ�� ã�� ���� �� ���� '���� ��'�� ���Ͽ� �� ���� Ŭ ��� �� ������ ��ġ��Ų��.
		for (j = i - 1; j >= 0 /*&& arr[j] > key*/; j--) {
			// �� ���� �������� ��ġ��Ų��.
			//arr[j + 1] = arr[j];

			// �� �� ���� ��ġ�� �����Ѵ�.
			//fork = j;
			if (arr[j] <= key)
			{
				fork = j + 1;
				break;
			}
			
			if (arr[j] > key) {
				arr[j + 1] = arr[j];
				fork = j;
			}
			
		}

		// ����� ��ġ�� '���� ��'�� �����Ѵ�.
		if (fork != i) {
			arr[fork] = key;
		}

		//�������� ���� ���
		/*for (k = 0; k <= (i-1)+1; k++)
			printf("%d ", arr[k]);
		printf("\n");*/
	}
	return arr;
}


//�� ��Ʈ
//(�迭, ���� �ε���, ������ �ε���)
void quickSort(int* arr, int start, int end) {

	//pivot ���� ��
	int pivot;
	//left ���ʺ��� ū ���� ã�� �ε���
	int left;
	//rigth �����ʺ��� ���� ���� ã�� �ε���
	int right; 
	int temp = 0;
	
	//���Ұ� 1���� ���
	if (start >= end)
		return;

	pivot = start;
	left = start+1;
	right = end;	
	
	//pivot �ε��� ���� �������� ū ���� ã�� left�ε����� ���� ���� ã�� right�ε����� ������ ������
	while(left <= right)
	{
		while ( ( arr[left] <= arr[pivot] ) && (left <= end))
		{
			left++;
		}
	
		while ( ( arr[right] >= arr[pivot] ) && (right > start))
		{
			right--;
		}

		if(left <= right){
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}

	temp = arr[right];
	arr[right] = arr[pivot];
	arr[pivot] = temp;

	pivot = right;

	quickSort(arr, start, pivot - 1);
	quickSort(arr, pivot + 1, end);
}