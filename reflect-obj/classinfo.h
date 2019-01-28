#pragma once
#include "reflex.h"

//函数指针、指向创建类实例的回调函数
typedef Reflex* (*ObjConstructorFun)();
class ClassInfo
{
public:
	ClassInfo(const std::string className, ObjConstructorFun classConstructor)
		:m_className(className), m_objectConstructor(classConstructor)
	{
		//classInfo的构造函数是传入类名和类对应的new函数然后自动注册进map中
		Reflex::Register(this);
	}
	virtual ~ClassInfo() {}
	Reflex* CreateObject()const { return m_objectConstructor ? (*m_objectConstructor)() : NULL; }
	bool IsDynamic()const { return NULL != m_objectConstructor; }
	const std::string GetClassName()const { return m_className; }
	ObjConstructorFun GetConstructor()const { return m_objectConstructor; }
public:
	std::string m_className;
	ObjConstructorFun m_objectConstructor;
};
//
