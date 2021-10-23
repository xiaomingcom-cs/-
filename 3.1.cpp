#include<iostream>
#include<string>
using namespace std;
struct stu{//�洢ѧ����Ϣ�Ľṹ��
		string name;
		string phonenum;
		int classs;
		int sushe;
		stu & operator =(const stu &a){
			name=a.name;
			phonenum=a.phonenum;
			classs=a.classs;
			sushe=a.sushe;
		}
};//���ص��ںţ�����ֱ�ӶԽṹ����и�ֵ�����÷ֱ��ÿһ�����ݳ�Ա��ֵ
class student{
	public:
		student(int initialc=100){
			arraylength=initialc;
			sstu=new stu[arraylength];
			listsize=0;
		};
//		~student(){
//			delete []sstu;
//		};	
		void insert(string name,string phonenum,int classs,int sushe);//����ѧ����Ϣ
		void erase(string name);//ɾ��ѧ����Ϣ
		void vary1(string name,int x,string str);//����ѧ����Ϣ
		void vary2(string name,int x,int y);
		int select(string name);//����ѧ��
		int value(int r);//��������༶ѧ������ŵ����ֵ
	private:
		stu *sstu;//�ṹ�������ַ
		int arraylength;//�����С
		int listsize;//ʵ��ѧ������
};
void student::insert(string name,string phonenum,int classs,int sushe){
	if(listsize==arraylength){//���ʵ�ʴ�С�����趨��С���Ͷ������������
		stu *temp=new stu[arraylength*2]; 
		for(int i=0;i<listsize;i++){
			temp[i]=sstu[i];
		}
		delete []sstu;
		sstu=temp;
		arraylength*=2;
	}
	sstu[listsize].name=name;
	sstu[listsize].phonenum=phonenum;
	sstu[listsize].classs=classs;
	sstu[listsize].sushe=sushe; 
	listsize++; 
}
void student::erase(string name){
	int index;
	for(int i=0;i<listsize;i++){
		if(sstu[i].name==name){
			index=i;
			break;	
		}
			
	}
	for(int i=index;i<listsize-1;i++) sstu[i]=sstu[i+1];
//	sstu[--listsize].~stu(); ����дֻ������12�����ݣ�֮�����ֹ�ˣ�Ȼ�󷵻�value356����������0��˵���˴������⣻����Խ����456 
	--listsize;//��ƽ̨���ܹ�����½���������ܹ�����Ϊ���������������⣬������ɾ��Ԫ�صĿռ䲻��ɾ���ɣ���Ӱ������Ĳ��� 
}//�ĳ� --listsize;��������
//��Ҫ�о�һ�±����������� 
void student::vary1(string name,int x,string str){
	int index; 
	for(int i=0;i<listsize;i++){
		if(sstu[i].name==name){
			index=i;
			break;
		}
		
	}
	sstu[index].phonenum=str;
}
void student::vary2(string name,int x,int y){
	int index;
	for(int i=0;i<listsize;i++){
		if(sstu[i].name==name){
			index=i;
			break;
		}
		
	}
	if(x==2) sstu[index].classs=y;
	if(x==3) sstu[index].sushe=y;
}//��Ϊ�ֻ��źͰ༶�ţ�����ŵ��������Ͳ�ͬ�����Ա༭����Ҫд�������ֱ���ͬ����������
int student::select(string name){
	for(int i=0;i<listsize;i++){
		if(sstu[i].name==name){
			return 1;
		}
	}
	return 0;
}
int student::value(int r){
	int val=0;
	for(int i=0;i<listsize;i++){
		if(sstu[i].classs==r){
			val=val^sstu[i].sushe;	
		}
	}
	return val;	
}
int main(){
	student s;
	int n;
	cin>>n;
//	int out[n]; 
//	int k=0;
	while(n--){
		int e;
		cin>>e;
		if(e==0){
			string name,phonenum;
//			string phonenum;
			int classs,sushe;
//			int sushe;
			cin>>name>>phonenum>>classs>>sushe;
			s.insert(name,phonenum,classs,sushe);
		}
		else if(e==1){
			string name;
			cin>>name;
			s.erase(name);
		}	
		else if(e==2){
			string name,str;
			int x,y;
//			string str;
			cin>>name>>x;
			if(x==1){
				cin>>str;
				s.vary1(name,x,str);
			}
			else{
				cin>>y;
				s.vary2(name,x,y);
			}
		}
		else if(e==3){
			string name; 
			cin>>name;
			cout<<s.select(name)<<endl;
//			out[k++]=s.select(name);
		}	
		else {
			int r;
			cin>>r;
			cout<<s.value(r)<<endl;
//			out[k++]=s.value(r);
		}			
	}
//	for(int i=0;i<k;i++){
//		cout<<out[i]<<endl;
//	}
}       
