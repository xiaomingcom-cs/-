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
				b[x++]=a[i];//����b�洢01���ж�Ӧ���Ӽ� 
			} 
		}
		if(x==0) ans=0;
		else{
			for(int i=0;i<x;i++){
			ans+=b[i]*(i+1);//ansΪ���еļ�ֵ 
			}
		} 
		aa=aa^ans;
	}
	else{
		mark[n]=0;//��mark[n]��01������Ϊ0 
	 	subset(a,mark,n+1,l,aa);//�ݹ���һλ 
		mark[n]=1;
		subset(a,mark,n+1,l,aa);
	}//01���е�ÿһλ������0Ҳ������1�����Դ�mark[0]��ʼ��01������Ϊ0��Ȼ��ݹ��������01���У���01������Ϊ1��Ȼ��ݹ飬���ܵó�������� 
} 
int main(){
	int n;
int aa=0;//aa�洢���ս�� 
	cin>>n;
	int a[n],mark[n];//a[n]�洢ԭ���У�mark[n]�洢�����Ӽ���01���� 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	subset(a,mark,0,n,aa);
	cout<<aa;
} 
