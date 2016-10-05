#include <stdio.h>
#include <stdlib.h>
#include "MGraph.h"

void printf_data(MVertex *v)
{
    printf("%s",(char *)v);
}
int main()
{
    MVertex *v[] = {"A","B","C","D","E","F"};
    MGraph *graph = MGraph_create(v,6);
    MGraph_addedge(graph, 0,1,1);
    MGraph_addedge(graph, 1,2,1);
    MGraph_display(graph, printf_data);
    



    MGraph_destory(graph);

    return 0
}
