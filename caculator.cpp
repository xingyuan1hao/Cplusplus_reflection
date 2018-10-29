#include <iostream>
#include "caculator.h"

//implement default constructor
template <class T>
caculator<T>::caculator()
{

}

//implement default deconstructor
template <class T>
caculator<T>::~caculator()
{

}

//implement add function
template <class T>
T caculator<T>::add(const T a, const T b)
{
	this->m_result= a + b;
	return this->m_result;
}

//implement sub function
template <class T>
T caculator<T>::sub(const T a, const T b)
{
	this->m_result= a - b;
	return this->m_result;
}

//implement div function
template <class T>
T caculator<T>::div(const T a, const T b)
{	
//the divisor must not be zero!	
	if (b == 0)
	{
		return 0;
	}else
	{
		this->m_result=a / b;
		return this->m_result;
	}
}
//implement mul function
template <class T>
T caculator<T>::mul(const T a, const T b)
{
	this->m_result= a* b;
	return this->m_result;
}



