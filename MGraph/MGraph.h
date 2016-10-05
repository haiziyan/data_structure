#ifndef _MGRAPH_H
#define _MGRAPH_H

typedef void MGraph;
typedef void MVertex;
typedef void (MGraph_printf)(MVertex *);

MGraph *MGraph_create(MVertext **v, int n);
void MGraph_destory(MGraph *graph);
void MGraph_clear(MGraph *graph);
int MGraph_addedge(MGraph *graph, int v1, int v2, int w);
int MGraph_removeedge(MGraph *graph, int v1, int v2);
int MGraph_getedge(MGraph *graph, int v1, int v2);
int MGraph_td(MGraph *graph, int v);
int MGraph_vertexcount(MGraph *graph);
int MGraph_edgecount(MGraph *graph);
void MGraph_dfs(MGraph *graph, int v, MGraph_printf *pFunc);
void MGraph_bfs(MGraph *graph, int v, MGraph_printf *pFunc);
void MGraph_display(MGraph *graph, MGraph_printf *pFunc);




#endif
