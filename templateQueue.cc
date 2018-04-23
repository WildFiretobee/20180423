 ///
 /// @file    templateQueue.cc
 /// @date    2018-04-20 19:00:04
 ///
 
#include "Mylogger.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename Type, size_t kSize = 5>
class Queue
{
public:
	Queue()
	: _head(0)
	, _tail(0)
	, _base(new Type[kSize]())
	{
		LogDebug("Queue()");
	}

	~Queue();
	
	//在类模板之中嵌套一个成员函数模板
	template <typename Arg>
	void display(const Arg & arg);

	bool full() const;
	bool empty() const;
	void push(const Type & type);
	void pop();
	Type head();
	Type tail();

private:
	int _head;
	int _tail;
	Type * _base;
};


template <typename Type, size_t kSize>
template <typename Arg>
void Queue<Type, kSize>::display(const Arg & arg)
{
	LogInfo("display()  arg = %s", arg);
}


template <typename Type, size_t kSize>
Queue<Type, kSize>::~Queue()
{
	LogDebug("~Queue()");
	delete [] _base;
}

template <typename Type, size_t kSize>
bool Queue<Type, kSize>::empty() const
{
	return _head == _tail ;
}

template <typename Type, size_t kSize>
bool Queue<Type, kSize>::full() const
{
	return _head == (_tail + 1 + kSize) % kSize;
}


template <typename Type, size_t kSize>
void Queue<Type, kSize>::push(const Type & t) 
{
	if(full())
	{
		LogInfo("queue is full, can't push elments");
		return;
	}
	else
	{
		_base[_tail++] = t;
		_tail %= kSize;
	}
}


template <typename Type, size_t kSize>
void Queue<Type, kSize>::pop()
{
	if(empty())
	{
		LogInfo("queue is empty, no elments");
		return;
	}
	else
	{
		++_head;
		_head %= kSize;
	}
}

template <typename Type, size_t kSize>
Type Queue<Type, kSize>::head()
{
	return _base[_head];
}

template <typename Type, size_t kSize>
Type Queue<Type, kSize>::tail()
{
	return _base[_tail-1];
}


void test1(void)
{
	Queue<string> queue;
	LogInfo("The Queue is empty?%d", queue.empty());
	queue.push("AA");

	LogInfo("The Queue is empty?%d", queue.empty());

	for(size_t idx = 1; idx != 4; ++idx)
	{
		queue.push(string(2, 'A' + idx));
	}

	LogInfo("The Queue head is %s", queue.head().c_str());
	LogInfo("The Queue tail is %s", queue.tail().c_str());

	LogInfo("The Queue is full??%d", queue.full());

	while(!queue.empty())
	{
		LogInfo("%s", queue.head().c_str());
		queue.pop();
	}
	LogInfo("The Queue is empty?%d", queue.empty());

}

int main(void)
{
	test1();
	return 0;
}
