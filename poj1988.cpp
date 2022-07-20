#include<iostream>
#include<vector>
#include<string>
#include<list>
#include <set>
#include<algorithm>
using namespace std;
struct cubes{
 int node;
 int num;
};
int findroot(int a,vector<cubes> &arry,int d[]){
   int temp=arry[a].node;
   if(arry[a].node!=a){
      arry[a].node=findroot(arry[a].node,arry,d);
      d[a]+=d[temp];
   }
   return arry[a].node;
}
void Union(int a,int b,vector<cubes> &arry,int d[]){
      a=findroot(a,arry,d);
      b=findroot(b,arry,d);
      if(a!=b){
         arry[a].node=b;
         d[a]=arry[b].num;
         arry[b].num+=arry[a].num;
      }
}
void inti(vector<cubes> &arry){
      for(int i=0;i<=arry.size();i++){
         arry[i].node=i;
         arry[i].num=1;
      }
}
int main(){
   cubes node;
   vector<cubes> cube(30001,node);
   int d[30001]={0};
   int m,n,a,b,temp,num=0;
   char flag;
   cin>>n;
   
   inti(cube);
   for(int i=0;i<n;i++){
      cin>>flag;
      if(flag=='M'){
         cin>>a>>b;
         Union(a,b,cube,d);
      }
      else if(flag=='C'){
         num=0;
         cin>>a;
         findroot(a,cube,d);
         cout<<d[a]<<endl;
      }
   }   
   return 0;
}