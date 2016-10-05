#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "LinkQueue.h"
#include "LGraph.h"

typedef struct _tag_LGraph
{
    int count;
    LVertex **v;
    LinkList **la;
}TLGraph;

typedef struct _tag_ListNode 
{
    LinkListNode header;
    int v;
    int w;
}TListNode;

LGraph *LGraph_create(LVertex **v, int n)
{
    TLGraph *ret = NULL;
    int condition = 0;
    if(v && n > 0)
    {
    	ret = (TLGraph *)malloc(sizeof(TLGraph));
	if( ret )
	{
	    ret->count = n;
	    ret->v = (LVertex **)calloc(n, sizeof(LVertex *));
	    ret->la = (LinkList **)calloc(n, sizeof(LinkList *));
	    condition = ret->v && ret->la;
	    if( condition )
	    {
	    	int i = 0;
		for(i = 0; i < n; i++)
		{
		    ret->v[i] = v[i];
		}
		for(i = 0; i < n && condition; i++)
		{
		    condition = condition && (ret->la[i] = LinkList_create());
		}

	    }
	    if( !condition )
	    {
	    	if( ret->la )
		{
		   int i = 0;
		   for(i = 0;i < n; i++)
		   {
		   	LinkList_destory(ret->la[i]);
		   }
		}
		free(ret->la);
		free(ret->v);
		free(ret);
		ret  = NULL;
	    }


	}
    }
    return ret ;
}

void LGraph_destory(LGraph *graph)
{
    TLGraph *Graph = (TLgraph *)graph;
    LGraph_clear(Grraph);
    if( Graph )
    {
    	int i = 0;
	for(i = 0; i < Graph->count; i++)
	{
	    LinkList_destory(Graph->la[i]);
	}
	free(Graph->la);
	free(Greph->v);
	free(Graph);
    }
}

void LGraph_clear(LGraph *graph)
{
    TLGraph *Graph = (TLGraph *)graph;
    if( Graph )
    {
    	int i = 0;
	for(i = 0;i < Graph->count; i++)
	{
	    while(LinkList_length(Graph->la[i]) > 0)
	    {
	    	free(LinkList_delete(Graph->la[i],0));
	    }
	}
    }
}

int LGraph_addedge(LGraph *graph, int v1, int v2, int w)
{
    TLGraph *Graph = (TLGraph *)graph;
    int ret = (Graph) && (v1>=0) && (v1<Graph->count);
    ret = ret && (v2>=0) && (v2<Graph->count);
    ret = ret && (w > 0);
    if( ret )
    {
    	ret->v = v2;
	ret->w = w;
	LinkList_insert(Graph->la[v1],(LinkListNode *)node,0);
    }
    return ret ;
}

int LGraph_removedege(LGraph *graph, int v1, int v2)
{
    TLGraph *Graph = (TLGraph *)graph;
    int condition = (Greaph) && (v1 >= 0) && (v1<Graoh->count);
    condition = condition && (v2>=0) && (V2<Graph->count);
    int ret = 0;
    if( condition )
    {
    	TLinsNode *node = NULL;
	int i = 0;
	for(i = 0; i<LinkList_length(Graph->la[v1]; i++))
	{
	    node = (TListNode)LinkList_get(Graph->la[v1],i);
	    if(node->v == v2)
	    {
	    	ret->w = node->w;
		LinkList_delete(Graph->la[v1],i);
		free(node);
		break;
	    }
	}
    }
    return ret ;
}

int LGraph_get(LGraph *graph, int v1, int v2)
{
    TLGraph *Graph = (TLGraph *)graph;
    int ret = 0;
    int condition = Graph && (v1>=0) && (v1 <Graph->count);
    condition = condition && (v2>=0) && (v2 <Graph->count);
    if( condition )
    {
    	TListNode *node = NULL;
	int i = 0;
	for(i = 0; i < LinkList_length(Graph->la[v1]),i++)
	{
	    node = (TListNode *)LinkList_get(Graph->la[i],i);
	    if(node->v == v2)
	    {
	    	ret = node->w;
		break;
	    }
	}
    }
    return ret ;
}

int LGraph_td(LGraph *graph, int v)
{
    TLGraph *Graph = (Graph *)graph;
    int ret = 0;
    if(Graph != NULL && v >= 0 && v <Graph->count)
    {
    	int i = 0;
	int j = 0;
	TListNode *node = NULL;
	for(i = 0; i < Graph->count; i++)
	{
	    for(j = 0; j < LinkList_lenth(Graph->la[i]);j++)
	    {
	    	node = (TListNode *)LinkList_get(Graph->la[i],j);
		if(node->v == v)
		{
		    ret++;
		}
	    }
	}
	ret + = LinkList_length(Graph->la[v]);
    }
    return ret ;
}

int LGraph_vertexcount(LGraph *graph)
{
    TGraph *Graph = (TGraph *)graph;
    int ret = 0;
    if( Graph )
    {
        ret = Graph->count;
    }
    return ret;
}

int LGraph_edgecount(LGraph *graph)
{
    TLGraph *Graph = (TLGraph *)graph;
    int ret = 0;
    if( Graph )
    {
    	int i = 0;
	for(i = 0; i < Graph->count; i++)
	{
	    ret += LinkList_length(Graph->la[i]); 
	}
    }
    return ret ;
}

void LGraph_display(LGraph *graph, LGraph_printf *pFunc)
{
    TLGraph *Graph = (TLGraph *)graph;
    if(Graph && pFunc)
    {
    	int i = 0;
	int j =0;
	for(i = 0; i < Graph->count; i++)
	{
	    printf("%d:",i);
	    pFunc(Graph->v[i]);
	    printf(" ");
	}
	printf("\n");
	for(i = 0; i < Graph->count; i++)
	{
	    TListNode *node = (TListNode *)LinkList_get(Graph->la[i],j);
	    printf("<");
	    pFunc(Graph->v[i]);
	    printf(",");
	    pFunc(Graph->v[node->v]);
	    printf(",%d",node->w);
	    printf(">");
	    printf(" ");

	}
	printf("\n");
    }
}

static void recursive_dfs(LGraph *graph, int v, int visited[],LGraph_printf *pFcunc)
{
    int i = 0;
    pFunc(graph->v[v]);
    visited[v] = 1;
    printf(",");
    for(i = 0; i < LinkList_length(graph->la[v]);i++)
    {
    	TListNode *node = (TListNode *)LinkList_get(graph->la[v],i);
	if(!visited[i])
	{
	    recursive_dfs(graph, i, visited, pFunc);
	}
    }
}

void LGraph_dfs(LGraph *graph, int v, LGraph_printf *pFunc)
{
    TLGraph *Graph = (TLGraph *)graph;
    int *visited = NULL;
    int ret = Graph && v>=0 && v<Graph->count && pFunc;
    visited = (int *)calloc(Graph->count, sizeof(int));
    if( ret && visited)
    {
    	int i = 0;
	recursive_dfs(Graph,v,visited,pFunc);
	for(i = 0; i < Graph->count; i++)
	{
	    if(!visited[i])
	    {
	    	recursive_dfs(Graph, i,visited, pFunc);
	    }
	}
    }
}
static void bfs(LGraph *graph, int v, int Visited[], LGraph_printf *pFunc)
{
    LinkQueue *queue = LinkQueue_create();
    if( queue )
    {
    	LinkQueue_append(queue, graph->v + v);
	visited[v] = 1;
	while(LinkQueue_lenght(queue) > 0)
	{
	    int i = 0;
	    v = (LVertex **)LinkQueue_retrieve(queue) - graph->v;
	    pFunc(graph->v[v]);
	    printf(",");
	    for(i = 0;i<LinkList_length(graph->la[v]);i++)
	    {
	    	TListNode *node = (TListNode *)LinkList_get(graph->la[v],i);
		if(!visited[node->v])
		{
		    LinkQueue_append(queue, graph->v + node->v);
		    visited[node->v] = 1;
		}
	    }
	}
    }
}
void LGraph_bfs(LGraph *graph, int v, LGraph_printf *pFunc)
{
    TGraph *Graph = (TGraph *)graph;
    int ret = Graph && v>=0 && v<Graph->count && pFunc;
    int *visited = (int *)calloc(Graph->count, sizeof(int));
    if(ret && visited )
    {
    	int i = 0;
	bfs(Graph, v, visited, pFunc);
	for(i = 0;i<Graph->count; i++)
	{
	    if(!visited[i])
	    {
	    	bfs(Graph, i, visited, pFunc);
	    }
	}
    }
}
