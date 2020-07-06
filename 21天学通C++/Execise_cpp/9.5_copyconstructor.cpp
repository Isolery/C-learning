#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class MyString
{
//private:
public:
	char* buffer;
public:
	MyString(const char* initString)
	{
		if (initString != NULL)
		{
			buffer = new char[strlen(initString) + 1];
			strcpy(buffer, initString);
			cout << "buffer pointer to 0x" << (unsigned int*)buffer << endl;    //新建对象时buffer地址0x0078F328
		}
		else
			buffer = NULL;
	}

	~MyString()    //析构函数，当对象的作用域消失后自动执行该函数
	{
		cout << "Invoking destructor, clearing up" << endl;
		if (buffer != NULL)
		{
			delete[] buffer;    //清除new出来的内存
		}
	}

	void printString()
	{
		cout << buffer << endl;
	}

};

void UseMyString(MyString str)
{
	cout << "str.buffer pointer to 0x" << (unsigned int*)str.buffer << endl;    //0x0078F328 复制对象时buffer地址与新建对象
	                                                                                                               //的地址一样。第二次delete会报错。
	str.printString();
}

int main(void)
{
	MyString sayHello("Hello World!");
	UseMyString(sayHello);    //sayHello按值传递给形参str，这时会在内存中开辟一块空间保存buffer变量，虽然这个buffer
	                                       //变量与上一个buffer变量存放地址不同，但他们都是指针，里面的内容是相同的，也就是说指向
	                                       //了同一块内存地址，当UseMyString作用域结束后会释放掉buffer指向的内存单元，紧接着对象
	                                       //的作用域结束后也要释放buffer指向的内存单元，因为该内存无效而导致错误。这就是浅复制带来的后果。
}

/* output:
-----------------------------------------------
buffer pointer to 0x0078F328
str.buffer pointer to 0x0078F328
Hello World!
Invoking destructor, clearing up
Invoking destructor, clearing up
*/