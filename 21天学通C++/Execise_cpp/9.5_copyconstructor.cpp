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
			cout << "buffer pointer to 0x" << (unsigned int*)buffer << endl;    //新建对象时buffer地址0x0095F328
		}
		else
			buffer = NULL;
	}

	MyString(const MyString& copySource)
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
	cout << "str.buffer pointer to 0x" << (unsigned int*)str.buffer << endl;    //0x0095E830 复制对象时buffer地址                                                                                                             
	str.printString();
}

int main(void)
{
	MyString sayHello("Hello World!");
	UseMyString(sayHello);    //将sayHello传递给UseMyString时将自动调用复制构造函数，为buffer重新new一个地址  
}

/* output:
-----------------------------------------------
buffer pointer to 0x0095F328
Copy constructor: copying from MyString
buffer points to: 0x0095E830
str.buffer pointer to 0x0095E830
Hello World!
Invoking destructor, clearing up
Invoking destructor, clearing up
*/