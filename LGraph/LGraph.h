#ifndef _LGRAPH_H
#define _LGRAPH_H


typedef void LGraph;
typedef void LVertex;
typedef void (LGraph_printf)(LVertex *);

LGraph *LGraph_create(LVertex **v, int n);
void LGraph_destory(LGraph *graph);
void LGraph_clear(LGraoh *graph);
int LGraph_addedege(LGraph *graph, int v1, int v2, int w);
int LGraph_removeedge(LGraph *graph, int v1, int v2);
int LGraph_getedge(LGraph *graph, int v1, int v2);
int LGraph_edgecount(LGraph *graph);
int LGraph_td(LGraph *graph, int v);
int LGraph_vertexcount(Graph *graph);
void LGraph_dfs(Graph *graph, LGraph_printf *pFunc);
void LGraph_bfs(Graph *graph, LGraph_printf *pFunc);
void LGraph_display(Graph *graph, LGraph_printff*pFunc);








#endif
