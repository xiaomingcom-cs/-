#include<iostream>
using namespace std;
template<class T>
class ssort{
	public:
		ssort(T *a=NULL,int n=0):a(a),n(n){
		};
		void ranksort();
		void sectionsort();
		bool bubble(int a[],int x);//��ν�����������ϵ���� 
		void maopao();
		void insertsort();
		void output();
		 
	private:
		T *a;
		int n; 
};
template<class T>
void ssort<T>::ranksort(){//��������
	T *b=new int[n];
	for(int i=0;i<n;i++){
		b[i]=0;//b[i]�洢���� 
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j]<=a[i]) b[i]++;
			else b[j]++;//��������
		}
	}
	for(int i=0;i<n;i++){
		while(b[i]!=i){
			T t=b[i];
			swap(a[i],a[t]);//����Ԫ��
			swap(b[i],b[t]);//����Ԫ�ص����β���д�� swap(t,b[t]),���b[t]����t,b[i]����û�䰡������ 
			
		}
	}
	delete []b; //����֮��ʱ�����ڴ� 
}
template<class T>
void ssort<T>::sectionsort(){//ѡ������
	bool sorted=false;
	for(int size=n;!sorted&&(size>1);size--){
		int indexofmax=0;
		sorted=true;
		for(int i=1;i<size;i++){
			if(a[indexofmax]<=a[i]) indexofmax=i;//�������Ԫ�ص�����
			else sorted=false;//˵����������
			
		}
		swap(a[indexofmax],a[size-1]);//�������Ԫ�������Ԫ�ص�λ��
	}
}
template<class T>
bool ssort<T>::bubble(int a[],int x){//һ��ð�ݹ��̣�ͬʱά������swapped�Լ�ʱ��ֹ�������
	bool swapped=false;
	for(int i=0;i<x-1;i++){
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
			swapped=true;
		}
		return swapped;
	}
}
template<class T>
void ssort<T>::maopao(){//����ð������
	for(int i=n;i>1&&bubble(a,i);i--);
}
template<class T>
void ssort<T>:: insertsort(){//��������
	for(int i=1;i<n;i++){
		T t=a[i];
		int j;
		for(j=i-1;j>=0&&t<a[j];j--){
			a[j+1]=a[j]; //������t��Ԫ�غ���
		}
		a[j+1]=t;//����Ԫ��
	}
}
template<class T>
void ssort<T>::output(){
	for(int i=0;i<n;i++){
		cout<<a[i];
		cout<<' ';
	}
}

int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i]; //��i����n���ַ���һ�δ� 
	}
	ssort<int>s(a,n);
	s.ranksort();
	s.output();
}

