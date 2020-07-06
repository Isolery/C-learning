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
			cout << "buffer pointer to 0x" << (unsigned int*)buffer << endl;    //�½�����ʱbuffer��ַ0x0095F328
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

			cout << "buffer points to: 0x" << (unsigned int*)buffer << endl;    //��new��buffer��ַ0x0095E830
		}
	}

	~MyString()    //�������������������������ʧ���Զ�ִ�иú���
	{
		cout << "Invoking destructor, clearing up" << endl;
		if (buffer != NULL)
		{
			delete[] buffer;    //���new�������ڴ�
		}
	}

	void printString()
	{
		cout << buffer << endl;
	}

};

void UseMyString(MyString str)
{
	cout << "str.buffer pointer to 0x" << (unsigned int*)str.buffer << endl;    //0x0095E830 ���ƶ���ʱbuffer��ַ                                                                                                             
	str.printString();
}

int main(void)
{
	MyString sayHello("Hello World!");
	UseMyString(sayHello);    //��sayHello���ݸ�UseMyStringʱ���Զ����ø��ƹ��캯����Ϊbuffer����newһ����ַ  
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