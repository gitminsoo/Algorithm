
//// 시험에서 순서 나타내는 문제 낼 수도 있음
//// DFS BFS 같은거
//
//// DFS 는 4개로만 하자
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define TRUE 1
//#define FALSE 0
//#define MAX_VERTICES 50
//
//typedef struct GraphType {
//	int n;
//	int adj_mat[MAX_VERTICES][MAX_VERTICES];
//}GraphType;
//
//int visited[MAX_VERTICES];
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
//void  insert_vertex(GraphType* g, int v)
//{
//	if (((g->n) + 1) > MAX_VERTICES)
//	{
//		fprintf(stderr,"Graph: The number of vertices is greater than given MAX_VERTICES");
//		return;
//	}
//	g->n++;
//	return;
//}
//
//void insert_edge(GraphType* g, int start, int end)
//{
//	if (start >= g->n || end >= g->n)
//	{
//		fprintf(stderr, "Graph: Vertex index error");
//		return;
//	}
//	g->adj_mat[start][end] = 1;
//	g->adj_mat[end][start] = 1;
//	return;
//}
//
//void dfs(GraphType* g, int v)
//{
//	int w;
//	visited[v] = TRUE;
//	printf("Visited Vertex %d -> ", v);
//
//	for (w = 0; w < g->n; w++)
//	{
//		if (g->adj_mat[v][w] && !visited[w])
//			dfs(g, w);
//	}
//}
//
//int main()
//{
//	GraphType* g;
//	g = (GraphType*)malloc(sizeof(GraphType));
//	init(g);
//	for (int i = 0; i < 4; i++)
//	{
//		insert_vertex(g, i);
//	}
//	insert_edge(g, 0, 1);
//	insert_edge(g, 0, 2);
//	insert_edge(g, 0, 3);
//	insert_edge(g, 1, 2);
//	insert_edge(g, 2, 3);
//
//	printf("Implement DFS \n");
//	dfs(g, 0);
//	printf("\n");
//	free(g);
//	return 0;
//}





#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef struct {
	int queue[MAX_QUEUE_SIZE];
	int front;
	int rear;
}QueueType;

void queue_init(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, int item)
{
	if (is_full(q))
	{
		printf("Queue is Full ! \n");
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

int dequeue(QueueType* q)
{
	if (is_empty(q))
	{
		printf("Queue is empty ! \n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}
// dequeue 를 해도 값이 남아있는 듯?

#define MAX_VERTICES 50

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];

void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
	{
		for (c = 0; c < MAX_VERTICES; c++)
		{
			g->adj_mat[r][c] = 0;
		}
	}
}

void  insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES)
	{
		fprintf(stderr, "Graph: The number of vertex exeeds the given limit ! \n");
		return;
	}
	g->n++;
	return;
}

void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n)
	{
		fprintf(stderr, "Graph: The index of Vertex is wrong ! \n");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
	return;
}

void bfs(GraphType* g, int v)
{
	int w;
	QueueType q;

	queue_init(&q);
	visited[v] = 1;
	printf("%d visited -> ",v);

	enqueue(&q, v);

	while (!is_empty(&q))
	{
		v = dequeue(&q);
		for (w = 0; w < g->n; w++)
		{
			if (g->adj_mat[v][w] && !visited[w])
			{
				visited[w] = TRUE;
				printf("%d visited -> ", w);
				enqueue(&q, w);
			}
		}
	}
}

int main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 6; i++)
	{
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);

	printf("Implementation \n");
	bfs(g, 0);
	free(g);
	return 0;
}