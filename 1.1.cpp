#include<iostream>
using namespace std;
void subset(int *a,int *mark,int n,int l,int &aa){
	int ans;
	int b[n],x=0;
	if(n==l){
		x=0;
		for(int i=0;i<l;i++){
			ans=0;
			if(mark[i]==1){
				b[x++]=a[i];//数组b存储01序列对应的子集 
			} 
		}
		if(x==0) ans=0;
		else{
			for(int i=0;i<x;i++){
			ans+=b[i]*(i+1);//ans为序列的价值 
			}
		} 
		aa=aa^ans;
	}
	else{
		mark[n]=0;//在mark[n]将01序列置为0 
	 	subset(a,mark,n+1,l,aa);//递归下一位 
		mark[n]=1;
		subset(a,mark,n+1,l,aa);
	}//01序列的每一位可以是0也可以是1，所以从mark[0]开始将01序列置为0，然后递归接下来的01序列，将01序列置为1，然后递归，就能得出所有情况 
} 
int main(){
	int n;
int aa=0;//aa存储最终结果 
	cin>>n;
	int a[n],mark[n];//a[n]存储原序列，mark[n]存储代表子集的01序列 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	subset(a,mark,0,n,aa);
	cout<<aa;
} 
