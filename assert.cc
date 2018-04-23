 ///
 /// @file    assert.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-23 20:36:54
 ///

#include <assert.h>
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	int *p = new int(1);
	assert(p);

	cout << "hello,world" << endl;
	delete p;
	return 0;
}
