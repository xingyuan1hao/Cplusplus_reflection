#pragma once
#ifndef __TEST_H
#define __TEST_H

#include <iostream>

class Test {
public:
	Test() { std::cout << "call Test Constructor fun" << std::endl; }
	~Test() { std::cout << "call Test Destructor fun" << std::endl; }
	void print() { std::cout << "call Test print fun" << std::endl; }
};

void* create_Test() {
	Test *t = new Test;
	return (t == NULL) ? NULL : t;
}

#endif