#include "caculator.h"
#include "caculator.cpp"
//a test of caculator template class,and  call the function of the caculator class by the reflection machanism.
int main()
{	
	//template instantiation
	caculator<float> i;

	//define the input parameter 
	//input parameteres: param1, param2
	//output: result
	float param1, param2, result;

	//function name invoke by reflection
	char* fooname;
	
	//initialize parameter 
	param1=2.3;
	param2=4.3;

	//reflect and invoke the div function
	fooname="div";
	i.getClass().getMethod(fooname).invoke(result,&i,param1,param2);

	//print the result
	cout<<param1<<fooname<<param2<<"="<<result<<endl;

	//reflect Class name
	cout<<"Class name is:"<<i.getClass().getName()<<endl;
	 
}