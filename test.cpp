#include<iostream>
#include<vector>
//new
using namespace std;
int findroot(int a,vector<int> &arry,int d[]){
   int temp=arry[a];
   if(arry[a]!=a){
      arry[a]=findroot(arry[a],arry,d);   
      d[a]=(d[a]+d[temp])%3;
   }   
   return arry[a];
}
void inti(vector<int> &arry){
      for(int i=1;i<arry.size();i++){
         arry[i]=i;
      }
}

int main(){
   int d[500000]={0};
   vector<int> fa(600000,0);
   inti(fa);
   int m,n,a,b,temp,num=0,k,x,y;
   int flag;
   scanf("%d%d",&n,&k);
   for(int i=0;i<k;i++){
      scanf("%d%d%d",&flag,&a,&b);
      if(a>n||b>n||(flag==2&&a==b)){
         num++;
      }
      else{
         x=findroot(a,fa,d);
         y=findroot(b,fa,d);
         if(x==y){
            if((d[a]-d[b]+3)%3!=flag-1)
               num++;
         }
         else{
            fa[x]=y;
            d[x]=(d[b]-d[a]+3+flag-1)%3;
         }
      }
   }
   printf("%d\n",num);
   return 0;
}