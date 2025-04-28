#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

typedef struct MNode {
    int Nv, Ne;
    vector<vector<int>> G;
    vector<int> Data;
} *PtrToGNode;

typedef PtrToGNode MGraph;
typedef int VerTex, WeightType;

typedef struct ENode {
    VerTex V1, V2;
    WeightType Weight;
} *Edge;

MGraph CreateGraph(int VertexNum) {
    MGraph Graph = new MNode;
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    Graph->G.resize(VertexNum, vector<int>(VertexNum, 0));
    Graph->Data.resize(VertexNum, 0);
    return Graph;
}

void InsertEdge(MGraph Graph, Edge E) {
    Graph->G[E->V1][E->V2] = E->Weight;
    // 如果是无向图，还需要插入反向边
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph() {
    int Nv, Ne;
    cin >> Nv;
    MGraph Graph = CreateGraph(Nv);
    cin >> Ne;
    Graph->Ne = Ne;
    if (Graph->Ne != 0) {
        Edge E = new ENode;
        for (int i = 0; i < Ne; ++i) {
            cin >> E->V1 >> E->V2 >> E->Weight;
            InsertEdge(Graph, E);
        }
        delete E;
    }

    for (int i = 0; i < Graph->Nv; ++i) {
        cin >> Graph->Data[i];
    }
    return Graph;
}

int main() {
    MGraph Graph = BuildGraph();

    // 输出邻接矩阵
    for (int i = 0; i < Graph->Nv; ++i) {
        for (int j = 0; j < Graph->Nv; ++j) {
            cout << Graph->G[i][j] << " ";
        }
        cout << endl;
    }

    // 输出顶点数据
    for (int i = 0; i < Graph->Nv; ++i) {
        cout << Graph->Data[i] << " ";
    }
    cout << endl;

    delete Graph;
    return 0;
}