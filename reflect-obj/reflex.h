#pragma once
//Reflex.h
#include <string>




class ClassInfo;
class Reflex
{
public:
	Reflex() {}
	virtual ~Reflex() {}
	//hash表注册
	static bool Register(ClassInfo* pCInfo);
	static Reflex* CreatObject(std::string className);
};

//新申明类成员函数以及变量的注册
#define DECLARE_CLASS(class_name) \
    public:\
        virtual ClassInfo* GetClassInfo() const { return &m_classInfo; }\
        static Reflex* CreatObject()\
        {\
            return new class_name;\
        }\
    protected:\
        static ClassInfo m_classInfo;


//新申明类ClassInfo注册
#define REGISTER_CLASS(class_name)\
    ClassInfo class_name::m_classInfo(#class_name, class_name::CreatObject);

//利用自写反射生成类对象
#define REFLEX_CLASS(class_name)\
    (class_name*)(Reflex::CreatObject(#class_name))
//
