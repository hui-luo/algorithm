#include <iostream>
 
using namespace std;
class MGraph{
public:
    MGraph(char a[],int n,int e);
    void Prim(int v);
private:
    char vertex[100];//存放图中顶点
    int edge[100][100];//存放图中边
    int vertexNum,edgeNum;
    int MinEdge(int r[],int n);
};
MGraph::MGraph(char a[],int n,int e){
    int i,j,k,w;
    vertexNum=n;
    edgeNum=e;
    for(i=0;i<vertexNum;i++)//存储顶点
        vertex[i]=a[i];
    for(i=0;i<vertexNum;i++){//初始化邻接矩阵
        for(j=0;j<vertexNum;j++){
            if(i==j)
                edge[i][j]==0;
            else
                edge[i][j]=100;//假设边上的权值最大是100
        }
    }
    for(k=0;k<edgeNum;k++){
            cin>>i>>j>>w;
            edge[i][j]=w;
            edge[j][i]=w;
        }
}
 
void MGraph::Prim(int v){//从顶点v出发
    int i,j,k;
    int adjvex[100];//候选最短边的邻接点
    int lowcost[100];//候选最短边的权值
    lowcost[v]=0;//把顶点v加入集合U
    for(i=0;i<vertexNum;i++){
        lowcost[i]=edge[v][i];
        adjvex[i]=v;
    }
    for(k=1;k<vertexNum;k++){//迭代n-1次
        j=MinEdge(lowcost,vertexNum);//找出每次V-U到U的最小权值对应的j
        cout<<j<<" "<<adjvex[j]<<" "<<lowcost[j]<<endl;
        lowcost[j]=0;//把顶点j加入U
        for(i=0;i<vertexNum;i++){
                if(edge[i][j]<lowcost[i]){
                    lowcost[i]=edge[i][j];
                    adjvex[i]=j;
                  }
            }
      }
}
 
int MGraph::MinEdge(int r[],int n){
    int i,index=0;
    int min=100;//假设边上的权值最大是100
    for(i=1;i<n;i++){
        if(r[i]!=0&&r[i]<min){
            min=r[i];
            index=i;
        }
    }
    return index;
}
int main( )
{
	char ch[6]={'A','B','C','D','E','F'};
	MGraph mg(ch,6,9);
	mg.Prim(0);
	return 0;
}
 