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
	}//�������֣��ݹ���ڣ���k����nʱ���������һ������ 
	else {
		for(int i=k;i<=n;i++){
			swap(a[k],a[i]);//������һ��Ԫ���ó�����Ϊǰ׺ 
			digui(a,k+1,n,ans);//ʣ�ಿ�ֵݹ鴦�� 
			swap(a[k],a[i]);//�ٽ������Ĳ��ֻ��������ָ�����һ��swap�ݹ�ǰ��״̬ 
		}
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	int ans=0;//�洢���ս�� 
	for(int i=0;i<n;i++){
		cin>>a[i];//��i������n
	}
	digui(a,0,n-1,ans);
	cout<<ans;
} 
