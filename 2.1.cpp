#include<iostream>
using namespace std;
template<class T>
class ssort{
	public:
		ssort(T *a=NULL,int n=0):a(a),n(n){
		};
		void ranksort();
		void sectionsort();
		bool bubble(int a[],int x);//如何将两个函数联系起来 
		void maopao();
		void insertsort();
		void output();
		 
	private:
		T *a;
		int n; 
};
template<class T>
void ssort<T>::ranksort(){//名词排序
	T *b=new int[n];
	for(int i=0;i<n;i++){
		b[i]=0;//b[i]存储名次 
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j]<=a[i]) b[i]++;
			else b[j]++;//计算名次
		}
	}
	for(int i=0;i<n;i++){
		while(b[i]!=i){
			T t=b[i];
			swap(a[i],a[t]);//交换元素
			swap(b[i],b[t]);//交换元素的名次不能写成 swap(t,b[t]),你把b[t]换给t,b[i]还是没变啊！！！ 
			
		}
	}
	delete []b; //排序之后及时管理内存 
}
template<class T>
void ssort<T>::sectionsort(){//选择排序
	bool sorted=false;
	for(int size=n;!sorted&&(size>1);size--){
		int indexofmax=0;
		sorted=true;
		for(int i=1;i<size;i++){
			if(a[indexofmax]<=a[i]) indexofmax=i;//计算最大元素的索引
			else sorted=false;//说明数组无序
			
		}
		swap(a[indexofmax],a[size-1]);//交换最大元素与最后元素的位置
	}
}
template<class T>
bool ssort<T>::bubble(int a[],int x){//一次冒泡过程，同时维护变量swapped以及时终止排序过程
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
void ssort<T>::maopao(){//进行冒泡排序
	for(int i=n;i>1&&bubble(a,i);i--);
}
template<class T>
void ssort<T>:: insertsort(){//插入排序
	for(int i=1;i<n;i++){
		T t=a[i];
		int j;
		for(j=i-1;j>=0&&t<a[j];j--){
			a[j+1]=a[j]; //将大于t的元素后移
		}
		a[j+1]=t;//插入元素
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
		cin>>a[i]; //是i不是n，又犯了一次错 
	}
	ssort<int>s(a,n);
	s.ranksort();
	s.output();
}

