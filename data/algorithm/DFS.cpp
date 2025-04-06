#include <iostream>
#include <vector>
using namespace std;

void Visit( Vertex V ){
    printf("正在访问顶点%d\n", V);
}

void DFS(LGraph Graph, Vertex V, void (*Visit)(Vertex) )
{  
    PtrToAdjVNode W;
    Visit( V ); 
    Visited[V] = true; 
    /* 对V的每个邻接点W->AdjV */
    for( W=Graph->G[V].FirstEdge; W; W=W->Next ) 
        if ( !Visited[W->AdjV] )    
            DFS( Graph, W->AdjV, Visit );  
}

int main(){

    return 0;
}