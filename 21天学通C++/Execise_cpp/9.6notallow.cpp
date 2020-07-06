#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class MyString
{
private:
	char* buffer;

	MyString(const MyString& copySource)    //将复制构造函数声明为private将不允许复制实例化对象
	{
		buffer = NULL;
		cout << "Copy constructor: copying from MyString" << endl;
		if (copySource.buffer != NULL)
		{
			buffer = new char[strlen(copySource.buffer) + 1];
			strcpy(buffer, copySource.buffer);

			cout << "buffer points to: 0x" << (unsigned int*)buffer << endl;    //新new的buffer地址0x0095E830
		}
	}

public:
	MyString(const char* initString)
	{
		if (initString != NULL)
		{
			buffer = new char[strlen(initString) + 1];
			strcpy(buffer, initString);
			cout << "buffer pointer to 0x" << (unsigned int*)buffer << endl;    //新建对象时buffer地址0x0095F328
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
	str.printString();
}

int main(void)
{
	MyString sayHello("Hello World!");
	UseMyString(sayHello);    //不能复制sayHello
}

/* output:
-----------------------------------------------

*/