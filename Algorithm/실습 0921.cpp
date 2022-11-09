#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int list[], int n);

int main()
{
	int i;
	int list_num = 10;
	int mylist[10];

	srand(time(NULL));

	for (i = 0; i < list_num; i++)
	{
		mylist[i] = rand() % 100;
	}
	printf("unsorted list is \n\n");
	for (i = 0; i < list_num; i++)
	{
		printf("%d \t", mylist[i]);
	}
	insertion_sort(mylist, list_num);

	printf("\n\nsorted list is \n\n");
	for (i = 0; i < list_num; i++)
	{
		printf("%d \t", mylist[i]);
	}

	return 0;
}




void insertion_sort(int list[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}



//void bubble_sort(int list[], int n)
//{
//	int i, j, temp;
//	for (i = n - 1; i > 0; i--)
//	{
//		for (j = 0; j < i; j++)
//		{
//			if (list[j] > list[j + 1])
//			{
//				SWAP(list[j], list[j + 1], temp);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int nums[] = { 2,3,5,9,7,6,8,4,1 };
//	bubble_sort(nums, 9);
//	for (int i = 0; i < 9; i++)
//	{
//		printf("%d \t", nums[i]);
//	}
//}









//#include <time.h>
//
//
//int main()
//{
//	clock_t start, stop;
//	double duration;
//	start = clock();
//
//	for (int i = 0; i < 10000000; i++);
//
//	stop = clock();
//	duration = (double)(stop - start) / CLOCKS_PER_SEC;
//	printf("Implementation time is %f.\n", duration);
//	return 0;
//}

// void selection_sort(int list[], int n);
//
//int main()
//{
//	int list_num = 9;
//	int mylist[9] = { 5,3,8,4,9,1,6,2,7 };
//	int i;
//
//	printf("unsorted list is \n\n");
//	for (i = 0; i < 9; i++)
//	{
//		printf("%d \t", mylist[i]);
//	}
//
//	selection_sort(mylist, list_num);
//
//	printf("\n\nsorted list is \n\n");
//	for (i = 0; i < 9; i++)
//	{
//		printf("%d \t", mylist[i]);
//	}
//
//	return 0;
//}
//
//void selection_sort(int list[], int n)
//{
//	int i, j, least, tmp;
//	for (i = 0; i < n - 1; i++)
//	{
//		least = i;
//		for (j = i + 1; j < n; j++)
//		{
//			if (list[j] < list[least])
//				least = j;
//		}
//		SWAP(list[i], list[least], tmp);
//	}
//}