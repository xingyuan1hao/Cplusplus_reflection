#pragma once
//reflex.h
#include "reflex.h"
class CTest : public Reflex
{
public:
	CTest();
	virtual ~CTest();
	virtual ClassInfo* GetClassInfo() const { return &m_classInfo; }
	static Reflex* CreatObject() { return new CTest; }
protected:
	static ClassInfo m_classInfo;
};
//
