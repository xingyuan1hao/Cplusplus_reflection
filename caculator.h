#pragma once
#ifndef CACULATOR_H
#define CACULATOR_H
//Include the head file of reflection lib.
#include "reflection.hpp"

using namespace agm::reflection;
using namespace std;

//The Template class of caculator provided arithmetic(add, subtract, multiple and division)functions.

template <class T>
class caculator
{
public:
//default constructor
	caculator();

//default deconstructor
public:
	~caculator();


public:
//The function Method
//define by C++ reflection lib synax to declare this does not have super class 
	CLASS(caculator,agm::reflection::NullClass);
//define add function the by reflection lib syntax
//Access attribute:public
//@param a The first add number
//@param b The second add number
	METHOD(public, T, add, (T a, T b));

//define sub function by reflection lib syntax
//Access attribute:public
//@param a The minuend 
//@param b The subtrahend
	METHOD(public, T, sub, (T a, T b));

//define div function by reflection lib syntax
//Access attribute:public
//@param a The dividend
//@param b The divisor
	METHOD(public, T, div, (T a, T b));

//define mul function by reflection lib syntax
//Access attribute:public
//@param a The multiplier
//@param b The faciend
	METHOD(public, T, mul, (T a, T b));

private:
//keep the result of caculating
//define class member by reflection lib syntax
//Access attribute:private
// Type : template T
	FIELD(private, T, m_result);	

};

#endif