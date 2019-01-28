// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>

#include "testClass.h"
#include "classFactory.h"


#include "reflex.h"
#include "reflextest.h"



//#define _CRT_SECURE_NO_WARNINGS

using namespace std;
class CBox1 {
};
class CBox2 {
	int length, width, height;
};
class CBox3 {
	int length, width, height;
	static int count;
};
class CBox4 {
	int foo();
};
class CBox5 {
public:
	CBox5() {};
	~CBox5() {};
};
class CBox6 {
public:
	CBox6() {};
	virtual ~CBox6() {};
};
class A {
};
class B {
};
class C :public A {
};
class D :public virtual B {
};
class E :public A, public B {
};

class String
{
public:
	String(const char *str = NULL);// 普通构造函数  
	String(const String &other);// 拷贝构造函数  
	~String(void);// 析构函数  
	String & operator = (const String &other);// 赋值函数  
private:
	char *m_data;// 用于保存字符串  
};


vector<string> StringSplit(const string& sData, const string& sDelim) 
{
	vector<string>vItems;
	vItems.clear();
	string::size_type bpos = 0;
	string::size_type epos = 0;
	string::size_type nlen = sDelim.size();
	while ((epos = sData.find(sDelim, epos)) != string::npos) {
		vItems.push_back(sData.substr(bpos, epos - bpos));
		epos += nlen;
		bpos = epos;
	}
	vItems.push_back(sData.substr(bpos, sData.size() - bpos));
	return vItems;
}

int value = 3;
//void func(int *&p)
//{
//	p = &value;
//}
 
void func(int **p)
{
	*p = &value;
}

//普通构造函数  
String::String(const char *str)
{
	if (str == NULL)
	{
		m_data = new char[1];// 得分点：对空字符串自动申请存放结束标志'\0'的，加分点：对m_data加NULL判断  
		*m_data = '\0';
	}
	else
	{
		int length = strlen(str);
		m_data = new char[length + 1];// 若能加 NULL 判断则更好
		strcpy(m_data, str);
	}
	printf("String:%s\r\n", m_data);

}


// String的析构函数  
String::~String(void)
{
	delete[] m_data; // 或delete m_data;  
}


//拷贝构造函数  
String::String(const String &other)// 得分点：输入参数为const型  
{
	int length = strlen(other.m_data);
	m_data = new char[length + 1];// 若能加 NULL 判断则更好  
	strcpy(m_data, other.m_data);
	printf("String&:%s\r\n", m_data);

}


//赋值函数  
String & String::operator = (const String &other) // 得分点：输入参数为const型  
{
	if (this == &other)//得分点：检查自赋值  
		return *this;
	if (m_data)
		delete[] m_data;//得分点：释放原有的内存资源  
	int length = strlen(other.m_data);
	m_data = new char[length + 1];//加分点：对m_data加NULL判断  
	strcpy(m_data, other.m_data);
	printf("String& operator:%s\r\n", m_data);
	return *this;//得分点：返回本对象的引用    
}


#if 1
int _tmain(int argc, _TCHAR* argv[])
{
#if 0
	float f = 0.123456789;

	printf("float:%.10f\r\n",f);
	double d = 0.123457689;
	 
	printf("double:%.20lf\r\n", d);

	unsigned long long ul = 0x7ffffffff;
	long long l = 0x7ffffffff;
	printf("long long:%lld\r\n", ul);

	d = 0x7ffffffff;
	printf("doubleD:%lf\r\n", d);

	f = 0x7fffffff;
	printf("floatF:%lf\r\n", f);


	char *value = "a=1&b=2&c=3";
	/*"a=1&b=2&c=3"*/
	vector<string>paras = StringSplit((const string)value, "&");
	vector<string>::iterator iter = paras.begin();
	for (; iter != paras.end(); iter++) {
		vector<string>singlepara = StringSplit(*iter, "=");
		cout << *iter << endl;
		cout << singlepara[0] << " " << singlepara[1] << endl;
	}
#endif

#if 0
	CBox1 box1obj;
	cout << "box1: " << sizeof(box1obj) << endl;//输出1

	CBox2 box2obj;
	cout << "box2: " << sizeof(box2obj) << endl;

	CBox3 box3obj;
	cout << "box3: " << sizeof(box3obj) << endl;

	CBox4 box4obj;
	cout << "box4: " << sizeof(box4obj) << endl;

	CBox5 box5obj;
	cout << "box5: " << sizeof(box5obj) << endl;

	CBox6 box6obj;
	cout << "box6: " << sizeof(box6obj) << endl;

	A a;
	B b;
	C c;
	D d;
	E e;
	cout << "sizeof(a):" << sizeof(a) << endl;
	cout << "sizeof(b):" << sizeof(b) << endl;
	cout << "sizeof(c):" << sizeof(c) << endl;
	cout << "sizeof(d):" << sizeof(d) << endl;
	cout << "sizeof(e):" << sizeof(e) << endl;
#endif	
#if 0
	int n = 2;
	int *pn = &n;
	cout << *pn << endl;
	func(pn);
	cout << *pn << endl;


	int n = 1;
	int *pn = &n;
	cout << *pn << endl;
	func(&pn);
	cout << *pn << endl;
#endif
#if 0
	char* p = "Hello World !";
	String s(p); 
	//cout << s << endl;
	String s1("How are you ?");

	String s2 = s;
	//cout << s1 << endl;
	//s1 = s; cout << s << endl << s1 << endl;
	s = s2 = s1;
	//cout << s << endl << s1 << endl;
#endif

#if 0
	//注册
	ClassFactory::getInstance().registClass("Test", create_Test);

	//获取类对象
	Test *t = (Test*)ClassFactory::getInstance().getClassByName("Test");
	if (!t) {
		std::cout << "get instnce Test err;" << std::endl;
		return 1;
	}

	t->print();
	delete t;
#endif


	CTest* test = (CTest*)(Reflex::CreatObject("CTest"));
	delete test;

	getchar();
	return 0;

}
#endif
