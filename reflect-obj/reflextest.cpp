#include "stdafx.h"

#include<iostream>
#include "reflextest.h"
#include "classinfo.h"

//Test.cpp
//зЂВс
ClassInfo CTest::m_classInfo("CTest", CTest::CreatObject);

CTest::CTest()
{
	std::cout << "ADDR: [" << std::hex << (long)this
		<< "] ,The Object Name is \"CTest\" construced!" << std::endl;
}


CTest::~CTest()
{
	std::cout << "ADDR: [" << std::hex << (long)this
		<< "] ,The Object Name is \"CTest\" destroyed!" << std::endl;
}
//
