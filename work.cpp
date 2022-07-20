#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>
#include <queue>
using namespace std;
short int visited[10000]={0};
int low[10000]={0};
int dfn[10000]={0};
int no=0;
struct graphlist{
   int n;
   int dfn;
   graphlist *node;
};
void init(void){
    int i;
    for(i = 0; i < 1000; i++) {
        dfn[i] = low[i] = -1;
    }
}
void addnode(int n,graphlist *a){
   graphlist *temp;        
   temp = new graphlist;
   temp->n=n;
   temp->node=NULL;
   while(a->node!=NULL){
      a=a->node;
   }
   a->node=temp;
}
void dfnlow(int u, int v,vector<graphlist> graph)
{/* compute dfn and low while performing a dfs search         
beginning at vertex u, v is the parent of u (if any) */         
    graphlist *ptr;         
    int w;         
    dfn[u] = low[u] = no;
    no++;        
    for (ptr = graph[u].node; ptr; ptr = ptr->node) {
               w = ptr->n;               
    if (dfn[w] < 0) {
      /*w is an unvisited vertex */
        dfnlow(w, u,graph);                    
        low[u] = min(low[u], low[w]);               
    } else if (w != v)                   
         low[u] = min(low[u], dfn[w] );         
    } 
}
int main(){
    int n,m,graph[100][100]={0},maxn=0;
    vector<graphlist> numglist;
    init();
    for(int i=0;i<1000;i++){
        graphlist temp;        
        temp.n=i;
        temp.node=NULL;
        numglist.push_back(temp);
    }       
    while(cin>>n>>m){
        maxn=max(n,maxn);
        maxn=max(m,maxn);
        addnode(m,&numglist[n]);
        addnode(n,&numglist[m]);
    }
    dfnlow(7,-1,numglist);
    cout<<"    ";
    for(int i=0;i<=maxn;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"dfn ";
    for(int i=0;i<=maxn;i++){
        cout<<dfn[i]<<" ";
    }
    cout<<endl;
    cout<<"low ";
    for(int i=0;i<=maxn;i++){
        cout<<low[i]<<" ";
    }
    return 0;
}