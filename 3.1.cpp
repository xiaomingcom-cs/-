#include<iostream>
#include<string>
using namespace std;
struct stu{//存储学生信息的结构体
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
};//重载等于号，可以直接对结构体进行赋值，不用分别对每一个数据成员赋值
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
		void insert(string name,string phonenum,int classs,int sushe);//插入学生信息
		void erase(string name);//删除学生信息
		void vary1(string name,int x,string str);//更改学生信息
		void vary2(string name,int x,int y);
		int select(string name);//查找学生
		int value(int r);//计算给定班级学生宿舍号的异或值
	private:
		stu *sstu;//结构体数组地址
		int arraylength;//数组大小
		int listsize;//实际学生人数
};
void student::insert(string name,string phonenum,int classs,int sushe){
	if(listsize==arraylength){//如果实际大小等于设定大小，就对数组进行扩容
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
//	sstu[--listsize].~stu(); 这样写只能输入12个数据，之后就终止了，然后返回value356，正常返回0，说明此处有问题；数组越界是456 
	--listsize;//在平台上能过，在陆荣州那里能过是因为编译器的设置问题，可能是删除元素的空间不能删除吧，会影响后续的插入 
}//改成 --listsize;就正常了
//需要研究一下编译器的设置 
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
}//因为手机号和班级号，宿舍号的数据类型不同，所以编辑函数要写两个，分别处理不同的数据类型
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
