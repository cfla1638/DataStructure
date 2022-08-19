#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_IMCLUDE
#define inf 0x3f3f3f3f
#include <string>
using namespace std;

#define MAX 1000

typedef string ElementType;                //图的每一个顶点的值的类型
typedef int Vertex;                     //图的顶点的类型
const ElementType defaultVal("0");       //初始化图时的默认值
const Vertex NotAVertex = -1;           //定义找不到结点的标志为-1

typedef struct Edge *EdgeNode;
typedef struct Edge
{
    Vertex vertex;     //指向的边
    int weight;     //权重
    EdgeNode nextPtr;
}Edge;

typedef struct
{
    ElementType elem;
    EdgeNode edgeList;
    bool existFlag;         //删除的标记
}AdjTableNode;      //邻接表的结点

typedef struct
{
    AdjTableNode adjacentTable[MAX];    //邻接表
    int volume;         //已使用空间
    int vertexNum;      //结点数量
}Graph;

void InitializeGraph(Graph &G);                 //初始化有向图图
void AddVertex(Graph &G, ElementType elem);     //添加元素
void AddEdgeByIndex(Graph &G, int weight, Vertex u, Vertex v);    //建立一条从u到v的边
void AddEdge(Graph &G, int weight, ElementType u, ElementType v);
void DeleteNode(Graph &G, Vertex v);
void DeleteEdge(Graph &G, Vertex u, Vertex v);
Vertex FindVertex(const Graph &G, ElementType elem);
int GetIndegree(const Graph &G, Vertex v);


void DebugShowAll(const Graph &G);

#endif