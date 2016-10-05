#include <stdio.h>
#include <stdio.h>
#include "MGraph.h"
#include "LinkQueue.h"

typedef struct _tag_MGraph
{
    int count;
    MVertex **v;
    int **matrix;
}TMGraph;

MGraph_create(MVertex **v, int n)
{
    TMGraph *ret = NULL;
    if(v != NULL && n > 0)
    {
    	ret = (TMGraph *)malloc(sizeof(TMGraph));
	if( ret )
	{
	    int *p = NULL;
	    ret->count = n;
	    ret->v = (MVertex **)malloc(sizeof(MVertex *) * n);
	    re->matrix = (int **)malloc(sizeof(int *) * n);
	    p = (int *)calloc(n * n, sizeod(int));
	    if(ret-> && ret->matrix && p)
	    {
	    	int i = 0;
		for(i = 0; i < n; i++)
		{
		ret->v[i] = v[i];
		ret->matrix[i] = p + i * n;
		}
	    }
	    else
	    {
	    	free(p);
		free(ret->matrix);
		free(ret->v);
		free(ret);
	    }
	}
    }
    return ret ;
}

void MGraph_destory(MGraph *graph)
{
    TMGraph *Graph = (TMGraph *)graph;
    if( Graph )
    {
    	free(Graph->v);
	free(Graph->matrix[0]);
	free(Graph->matrix);
	free(Graph);
    }
}

void MGraph_clear(MGraph *graph)
{
    TMGraph *Graph = (TMGraph *)graph;
    if( Graph )
    {
    	int i = 0;
	int j = 0;
	for(i = 0; i<Graph->count; i++)
	{
	    for(j = 0; j<Graph->count; j++)
	    {
	    	Graph->matrix[i][j] = 0;
	    }
	}
    }
}

int MGraph_addedge(MGraph *graph, int v1, int v2, int w)
{
    TMGraph *Graph = (TMGraph *)graph;
    int ret = (Graph != NULL);
    ret = ret && (v1 >= 0) && (v1 < Graph->count);
    ret = ret && (v2 >= 0) && (v2 < Graph->count);
    ret = ret && (w >= 0);
    if( ret )
    {
    	Graph->matrix[v1][v2] = w;
    }
    return ret ;
}
int MGraph_removeedge(MGraph *graph, int v1, int v2)
{
    int ret = MGraph_get(graph,v1,v2);
    if( ret != 0)
    {
    	((TMGraph *)graph)->matrix[v1][v2] = 0;
    }
    return ret;
}
int MGraph_get(MGraph *graph, int v1, int v2)
{
    TMGraph *Graph = (TMGraph *)graph;
    int condition = (Graph != NULL);
    int ret = 0;
    condition = condition && (v1 >= 0) && (v1 < Graph->count);
    condition = condition && (v2 >= 0) && (v2 < Graph->count);
    if( condition )
    {
    	ret = Graph->matrix[v1][v2];
    }
    return ret ;
}

int MGraph_td(MGraph *garph, int v)
{
    TMGraph *Graph = (TMGraph *)graph;
    int ret = 0;
    int condition = (Graph != NULL) && (v >= 0) && (v < Graph->count);
    if( condition )
    {
    	int i - 0;
	for(i = 0; i<Graph->count; i++)
	{
	    if(Graph->matrix[v][i] != 0)
	    {
	    	ret++;
	    }
	    if(Graph->matrix[i][v] != 0)
	    {
	    	ret++;
	    }
	}
    }
    return ret ;
}

int MGraph_count(MGraph *graph)
{
    TMGraph *Graph = (TMGraph *)graph;
    int ret = 0;
    if( Graph )
    {
    	ret = Graph->count;
    }
    return ret ;
}

int MGraph_edgecount(MGraph *graph)
{
    TMGraph *graph = (TMGraph *)graph;
    int ret = 0;
    if( Graph )
    {
    	int i = 0;
	int j = 0;
	for(i = 0; i < Graph->count; i++)
	{
	    for(j = 0; j < Graph->count; j++)
	    {
	    	if(Graph->matrix[i][j] != 0)
		{
		    ret++;
		}
	    }
	}
    }
    return ret;
}

void MGraph_display(MGraph *graph, MGraph_printf *pFunc)
{
    TMGraph *graph = (TMGraph *)graph;
    if(Graph && pFunc)
    {
    	int i = 0;
	int j = 0;
	for(i = 0; i < Graph->count; i++)
	{
	    printf("%d:",i);
	    pFunc(Graph->v[i]);
	    printf(" ");
	}
	printf("\n");
	for(i = 0; i < Graph->count; i++)
	{
	    for(j = 0; j < Graph->count; j++)
	    {
	    	if(Graph->matrix[i][j] != 0)
		{
		    printf("<");
		    pFunc(Graph->v[i]);
		    printf(",");
		    pFunc(Graph->v[j]);
		    printf(",%d",Graph->matrix[i][j]);
		    printf(">");
		    printf(" ");
		}
	    }
	}
	printf("\n");
    }
}

void recursive_dfs(MGraph *graph, int v, int visited[],MGraph_printf *pFunc)
{
    int i = 0;
    pFunc(graph->v[v]);
    visited[v] = 1;
    printf(",");
    for(i = 0 ; i < graph->count; i++)
    {
    	if(graph->matrix[v][i] != 0 && !visited[i])
	{
	    recursive_dfs(graph, i, visted, pFunc);
	}
    }
}
static void MGraph_dfs(MGraph *graph, int v, MGraph_printf *pFunc)
{
    TMGraph *Graph = (TMGraph *)graph;
    int *visted = NULL;
    int condition = (Graph != NULL);
    condition = condition &&(v > 0) && (v < Graph->count);
    condition = condition && (pFunc != NULL);
    condition = condition && ((visited = (int *)calloc(Graph->count,sizeof(int))) != NULL);
    if( condition )
    {
    	int i = 0;
	recursive_dfs(Graph, v, visited, pFunc);
	for(i = 0;i < Graph->count; i++)
	{
	    if(!visited[i])
	    {
	    	recursive_dfs(Graph, i, visited, pFunc);
	    }
	}
	printf("\n");
    }
    free(visited);
}
static void bfs(MGraph *graph , int v, int visited[],MGraph_printf *pFunc)
{
    LinkQueue *queue = LinkQueue_create();
    if( queue )
    {
    	LinkQueue_append(queue, graph->v + v);
	visited[v] = 1;
	while(LinkQueue_length(queue) > 0)
	{
	    int i = 0;
	    v = (MVertex **)LinkQueue_retrieve(queue) - graph->v;
	    pFunc(graph->v);
	    printf(",");
	    for(i = 0; i<graph->count; i++)
	    {
	    	if(graph->matrix[v][i]!=0&&!visited[i])
		{
		    LinkQueue_append(queue,graph->v + i);
		    visited[i] = 1;
		}
	    }
	}
    }
}
void MGraph_bfs(MGraph *graph, int v, MGraph_printf *pFunc)
{
    TMGraph *Graph = (TMGraph *)graph;
    int *visited = NULL;
    int condition = (Gtaph != NULL);
    condition = condition && (v >= 0) && (v < Graph->count) &&(pFunc) &&(visited=(int *)calloc(Graph->count, sizeof(int)));
    if( condition )
    {
    	int i = 0;
	bfs(Graph, v, visited, pFunc);
	for(i = 0; i < Graph->count; i++)
	{
	    if(!visited[i])
	    {
	    	bfs(Graph, i, visited, pFunc);
	    }
	}
	printf("\n");
    }
    free(visited);
}
