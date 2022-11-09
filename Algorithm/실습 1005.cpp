//#include <stdio.h>
//#include <stdlib.h>
//
//void merge_sort(int list[], int left, int right);
//void merge(int mylist[], int left, int mid, int right);
//
//void merge_sort(int list[], int left, int right)
//{
//	if (left < right) {
//		int mid = (left + right) / 2;
//		merge_sort(list, left, mid);
//		merge_sort(list, mid + 1, right);
//		merge(list, left, mid, right);
//	}
//}
//
//void merge(int mylist[], int left, int mid, int right)
//{
//	int i = left, j = mid + 1, k = left;
//	int sorted[8];
//
//
//	while (i <= mid && j <= right)
//	{
//		if (mylist[i] <= mylist[j])
//			sorted[k++] = mylist[i++];
//
//		else sorted[k++] = mylist[j++];
//	}
//	while (i <= mid)
//	{
//		sorted[k++] = mylist[i++];
//	}
//	while (j <= right)
//	{
//		sorted[k++] = mylist[j++];
//	}
//	for (int a = left; a <= right; a++)
//	{
//		mylist[a] = sorted[a];
//	}
//	
//}
//
//
//
//int main() {
//	int i;
//	int mylist[8] = { 27,10,12,20,25,13,15,22 };
//
//	printf("before sorting, \n");
//
//	for (i = 0; i < 8; i++)
//	{
//		printf("%d ", mylist[i]);
//	}
//
//	merge_sort(mylist, 0, 7);
//
//	printf("\nafter sorting, \n");
//
//	for (i = 0; i < 8; i++)
//	{
//		printf("%d ", mylist[i]);
//	}
//
//	return 0;
//}

//===========================================================

//#include <stdio.h>
//#include <stdlib.h>
//#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
//
//int partition(int list[], int left, int right)
//{
//	int tmp;
//	int low = left + 1;
//	int high = right;
//	int pivot = list[left];
//
//	while (low < high) {
//		for (; low <= right && list[low] < pivot; low++);
//		for (; high >= left && list[high] > pivot; high--);
//
//		if (low < high) {
//			SWAP(list[low], list[high], tmp);
//		}
//	}
//	SWAP(list[left], list[high], tmp);
//	return high;
//}
//
//
//void quick_sort(int list[], int left, int right)
//{
//	int q;
//	if (left < right)
//	{
//		q = partition(list, left, right);
//		quick_sort(list, left, q - 1);
//		quick_sort(list, q + 1, right);
//
//	}
//}
//
//
//int main()
//{
//	int i;
//	int mylist[9] = { 5,3,8,4,9,1,6,2,7 };
//
//		printf("Before sorting, \n");
//	
//		for (i = 0; i < 9; i++)
//		{
//			printf("%d ", mylist[i]);
//		}
//
//		quick_sort(mylist, 0, 8);
//	
//		printf("\nAfter sorting, \n");
//	
//		for (i = 0; i < 9; i++)
//		{
//			printf("%d ", mylist[i]);
//		}
//}

//==========================================================

//#include <stdio.h>
//#include <Stdlib.h>
//
//#define MAX_VERTICES 50
//
//typedef struct GraohType {
//	int n;
//	int adj_mat[MAX_VERTICES][MAX_VERTICES];
//}GraphType;
//
//void init(GraphType* g)
//{
//	int r, c;
//	g->n = 0;
//	for (r = 0; r < MAX_VERTICES; r++)
//	{
//		for (c = 0; c < MAX_VERTICES; c++)
//		{
//			g->adj_mat[r][c] = 0;
//		}
//	}
//}
//
//void insert_vertex(GraohType* g, int v)
//{
//	if (((g->n) + 1) > MAX_VERTICES)
//	{
//		printf("Graph: The number if vertices is greater than given MAX_VERTICES");
//		return;
//	}
//	g->n++;
//}
//
//void insert_edge(GraohType* g, int start, int end)
//{
//	if (start >= g->n || end >= g->n) {
//		printf("Grapg:Vertex index error");
//		return;
//	}
//	g->adj_mat[start][end] = 1;
//	g->adj_mat[end][start] = 1;
//
//}
//
//void print_adj_mat(GraohType* g)
//{
//	for (int i = 0; i < g->n; i++)
//	{
//		for (int j = 0; j < g->n; j++)
//		{
//			printf("%d ", g->adj_mat[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main() {
//	GraohType* g;
//	g = (GraohType*)malloc(sizeof(GraohType));
//	init(g);
//	for (int i = 0; i <= 4; i++)
//	{
//		insert_vertex(g, i);
//	}
//	insert_edge(g, 0, 1);
//	insert_edge(g, 0, 2);
//	insert_edge(g, 0, 3);
//	insert_edge(g, 1, 2);
//	insert_edge(g, 2, 3);
//
//	print_adj_mat(g);
//	free(g);
//
//	return 0;
//}

