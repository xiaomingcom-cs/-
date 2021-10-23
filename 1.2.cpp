#include<iostream>
#include<algorithm> 
using namespace std;
template<class T>
void digui(T a[],int k,int n,int &ans){
	int v=0;
	if(k==n) {
		for(int i=0;i<=n;i++){
			v+=a[i]^(i+1);
		}
		ans=ans|v;	
		v=0;
	}//基础部分，递归出口，当k等于n时，输出其中一个排列 
	else {
		for(int i=k;i<=n;i++){
			swap(a[k],a[i]);//将其中一个元素拿出来作为前缀 
			digui(a,k+1,n,ans);//剩余部分递归处理 
			swap(a[k],a[i]);//再将交换的部分换回来，恢复到第一个swap递归前的状态 
		}
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	int ans=0;//存储最终结果 
	for(int i=0;i<n;i++){
		cin>>a[i];//是i而不是n
	}
	digui(a,0,n-1,ans);
	cout<<ans;
} 
