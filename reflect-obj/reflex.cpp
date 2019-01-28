#include "stdafx.h"


#include <map>

#include "reflex.h"
#include "classinfo.h"
//Reflex.cpp
static std::map<std::string, ClassInfo*> *m_classInfoMap = NULL;

bool Reflex::Register(ClassInfo* pCInfo)
{
	if (!m_classInfoMap)
	{
		m_classInfoMap = new std::map<std::string, ClassInfo*>();
	}
	if (!pCInfo)
	{
		return false;
	}
	if (m_classInfoMap->end() == m_classInfoMap->find(pCInfo->m_className))
	{
		m_classInfoMap->insert(std::map<std::string, ClassInfo*>::value_type(pCInfo->m_className, pCInfo));
	}
	return true;
}

Reflex* Reflex::CreatObject(std::string className)
{
	std::map<std::string, ClassInfo*>::const_iterator c_iter = m_classInfoMap->find(className);
	if (m_classInfoMap->end() != c_iter)
	{
		//当传入字符串name后,通过name找到info,然后调用对应的CreatObject()即可  
		return c_iter->second->CreateObject();
	}
	return NULL;
}
//
