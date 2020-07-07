#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class MyString
{
private:
	char* buffer;

	MyString(const MyString& copySource)    //�����ƹ��캯������Ϊprivate����������ʵ��������
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
	str.printString();
}

int main(void)
{
	MyString sayHello("Hello World!");
	UseMyString(sayHello);    //���ܸ���sayHello
}

/* output:
-----------------------------------------------

*/