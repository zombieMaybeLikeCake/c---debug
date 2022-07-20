#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <iostream> 
#include <algorithm> 
#include <queue> 
using namespace std; 
  
int m=0,n=0,k=0; 
bool Graph[300+5][300+5]={false};//true is connected,begin with 1 
int Coloring[300+5]={0};//1 is white 0 is no color -1 is black  so it is also visit array 
int BlackNum=0; 
int MaxColoring[300+5]={0}; 
int MaxBlack=0; 
int NowColor=0; 
  
/*DFS the graph and color the graph*/ 
int DFS(int cur) 
{ 
 if(NowColor>=n) 
 { 
      if(BlackNum>MaxBlack) 
       { 
          //printf("success!\n"); 
            MaxBlack=BlackNum; 
         memcpy(MaxColoring,Coloring,sizeof(Coloring)); 
     } 
  } 
  else 
   { 
      int i=0; 
       bool black=true; 
       bool white=true;//the cur node can be black and white  in the beginning 
        for(i=1;i<=n;i++)//two for is too long time 
     { 
          if(Graph[cur][i]==true) 
            { 
              if(Coloring[i]==-1) 
                { 
                  black=false; 
                   break; 
             } 
          } 
      } 
      int next=cur+1; 
        if(!black) 
     { 
          //white 
            NowColor++; 
            Coloring[cur]=1; 
           DFS(next); 
         Coloring[cur]=0; 
           NowColor--; 
        } 
      else 
       { 
          //black 
            BlackNum++; 
            NowColor++; 
            Coloring[cur]=-1; 
          DFS(next); 
         Coloring[cur]=0; 
           NowColor--; 
            BlackNum--; 
  
          //white 
            NowColor++; 
            Coloring[cur]=1; 
           DFS(next); 
         Coloring[cur]=0; 
           NowColor--; 
        } 
  } 
  return(0); 
} 
  
/*for test*/ 
int test() 
{ 
  
 return(0); 
} 
  
/*main process*/ 
int MainProc() 
{ 
   while(scanf("%d",&m)!=EOF&&m>0) 
 { 
      while(m--) 
     { 
          memset(Graph,false,sizeof(Graph)); 
         memset(Coloring,0,sizeof(Coloring)); 
           memset(MaxColoring,0,sizeof(MaxColoring)); 
         BlackNum=0; 
            MaxBlack=0; 
            scanf("%d%d",&n,&k); 
           int start=0,end=0; 
         int i=0; 
           for(i=1;i<=k;i++) 
           { 
              scanf("%d%d",&start,&end); 
             Graph[start][end]=true; 
                Graph[end][start]=true; 
            } 
          NowColor=0; 
            DFS(1);//DFS the graph and color the graph  AC 
         printf("%d\n",MaxBlack ); 
          for(i=1;i<=n;i++) 
           { 
              if(MaxColoring[i]==-1) 
             { 
                  printf("%d",i ); 
                   break; 
             } 
          } 
          for(i=i+1;i<=n;i++) 
         { 
              if(MaxColoring[i]==-1) 
             { 
                  printf(" %d",i ); 
              } 
          } 
  
            printf("\n"); 
      } 
  } 
  return(0); 
} 
  
int main(int argc, char const *argv[]) 
{ 
 MainProc(); 
    return 0; 
}