#include<iostream>
#include<vector>
#include<string>
#include<list>
#include <set>
#include<algorithm>
using namespace std;
int findroot(int a,vector<int> &arry,int d[]){
    if(arry[a]!=a){
        arry[a]=findroot(arry[a],arry,d);
    }
   return arry[a];
}
void Union(int a,int b,vector<int> &arry,int d[]){
      a=findroot(a,arry,d);
      b=findroot(b,arry,d);
      if(a!=b){
        if(d[a]>=d[b]){
            arry[b]=a;
            d[a]++;
        }
        else{
            arry[a]=b;
            d[b]++;
        }
    }
}
void inti(vector<int> &arry){
      for(int i=1;i<arry.size();i++){
         arry[i]=i;
      }
}
int main(){
   int m,n,a,b,temp,num=0,t;
   int d[200002];
   char flag;
   cin>>t;
   while(t--){
        cin>>n>>m;
        vector<int> people(2*n+1,0);
        inti(people);
        while(m--){
            cin>>flag;
            if(flag=='A'){
                scanf("%d%d",&a,&b);
                if((findroot(a,people,d)==findroot(b+n,people,d))||(findroot(b,people,d)==findroot(a+n,people,d)))
                    printf("%s","In different gangs.\n");
                else if((findroot(a,people,d)==findroot(b,people,d))||(findroot(b+n,people,d)==findroot(a+n,people,d)))
                    printf("%s","In the same gang.\n");
                else
                    printf("%s","Not sure yet.\n");
            }
            else{
                scanf("%d%d",&a,&b);
                Union(a,b+n,people,d);
                Union(b,a+n,people,d);
            }
        }
   }
   return 0;
}