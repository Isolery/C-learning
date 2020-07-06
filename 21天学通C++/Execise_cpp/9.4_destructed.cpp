#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class MyString
{
private:
	char* buffer;
public:
	MyString(const char* initString)
	{
		if (initString != NULL)
		{
			buffer = new char[strlen(initString) + 1];
			strcpy(buffer, initString);
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

int main(void)
{
	MyString sayHello("Hello World!");
	sayHello.printString();
}

/* output:
-----------------------------------------------
Hello World!
Invoking destructor, clearing up
*/