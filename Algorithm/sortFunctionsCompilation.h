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

//선택정렬
//"가장 작은 값을 찾아서 맨 앞으로(<-> 가장 큰 값을 찾아서 맨 앞으로) 보내어 정렬하는 알고리즘"
//시간 복잡도는 O(n^2);
int* selectionSort(int* arr, int length) {
	int i, j, min, index, temp;
	for (i = 0; i < length; i++) {
		min = 9999;
		for (j = i; j < length; j++) //i번째~10까지 순회하면서 가장 작은 값을 찾기
		{
			if (arr[j] < min) { //j번째의 값이 min의 값보다 작다면
				index = j; //j번째의 인덱스 값과 값 저장하기
				min = arr[j];
			}
		}
		temp = arr[i];
		arr[i] = min;
		arr[index] = temp;
	}

	return arr;
}

//버블정렬
//"옆에 있는 값을 비교해서 작은 값을 앞으로 보내기"
//사이클 과정에서 가장 큰 값은 뒤로 보내진다.
//매 사이클 마다 비교하여 변경하므로 가장 안 좋은 정렬 방법
//시간 복잡도는 O(n^2);
int* bubbleSort(int* arr, int length)
{
	int i, j, temp;
	for (i = 0; i < length - 1; i++) { //배열 길이의 -1 만큼 cycle을 돈다.

		//맨 마지막 숫자는 가장 큰 값으로 정렬되기 때문에, 배열의 길이 - (cycle 수(i) - 1)만큼 비교하여 정렬한다.
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

//삽입정렬
//"값을 적절한 위치에 삽입하기"
//자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교 하여, 자신의 위치를 찾아 삽입함으로써 정렬을 완성하는 알고리즘
//삽입 정렬은 기본적으로 '정렬이 되어 있다고 가정'
//매 순서마다 해당 원소를 삽입할 수 있는 위치를 찾아 해당 위치에 넣는다.
//https://gmlwjd9405.github.io/2018/05/06/algorithm-insertion-sort.html
//시간 복잡도는 기본적으로 O(n^2)이지만 잘 정렬된 자료 값에서 한 번만 비교가 일어나면  O(n)이다.

int* insertionSort(int* arr, int length)
{
	int i, j, k, key, fork;

	for (i = 1; i < length; i++) { //삽입 정렬은 두 번째 자료형부터 시작. ( 0이 아닌 1부터)
		key = arr[i]; //비교가 될 기준 값
		fork = i; //삽입될 위치를 알려주는 값

		//삽입될 위치를 찾는 과정 비교 값과 '기준 값'을 비교하여 비교 값이 클 경우 뒤 쪽으로 위치시킨다.
		for (j = i - 1; j >= 0 /*&& arr[j] > key*/; j--) {
			// 비교 값을 뒤쪽으로 위치시킨다.
			//arr[j + 1] = arr[j];

			// 비교 값 앞의 위치를 저장한다.
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

		// 저장된 위치에 '기준 값'을 저장한다.
		if (fork != i) {
			arr[fork] = key;
		}

		//삽입정렬 순서 출력
		/*for (k = 0; k <= (i-1)+1; k++)
			printf("%d ", arr[k]);
		printf("\n");*/
	}
	return arr;
}


//퀵 소트
//(배열, 시작 인덱스, 마지막 인덱스)
void quickSort(int* arr, int start, int end) {

	//pivot 기준 값
	int pivot;
	//left 왼쪽부터 큰 값을 찾는 인덱스
	int left;
	//rigth 오른쪽부터 작은 값을 찾는 인덱스
	int right; 
	int temp = 0;
	
	//원소가 1개인 경우
	if (start >= end)
		return;

	pivot = start;
	left = start+1;
	right = end;	
	
	//pivot 인덱스 값을 기준으로 큰 값을 찾는 left인덱스와 작은 값을 찾는 right인덱스가 엇갈릴 때까지
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