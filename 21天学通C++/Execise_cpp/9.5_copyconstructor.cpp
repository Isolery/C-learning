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
			cout << "buffer pointer to 0x" << (unsigned int*)buffer << endl;    //�½�����ʱbuffer��ַ0x0078F328
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
	cout << "str.buffer pointer to 0x" << (unsigned int*)str.buffer << endl;    //0x0078F328 ���ƶ���ʱbuffer��ַ���½�����
	                                                                                                               //�ĵ�ַһ�����ڶ���delete�ᱨ��
	str.printString();
}

int main(void)
{
	MyString sayHello("Hello World!");
	UseMyString(sayHello);    //sayHello��ֵ���ݸ��β�str����ʱ�����ڴ��п���һ��ռ䱣��buffer��������Ȼ���buffer
	                                       //��������һ��buffer������ŵ�ַ��ͬ�������Ƕ���ָ�룬�������������ͬ�ģ�Ҳ����˵ָ��
	                                       //��ͬһ���ڴ��ַ����UseMyString�������������ͷŵ�bufferָ����ڴ浥Ԫ�������Ŷ���
	                                       //�������������ҲҪ�ͷ�bufferָ����ڴ浥Ԫ����Ϊ���ڴ���Ч�����´��������ǳ���ƴ����ĺ����
}

/* output:
-----------------------------------------------
buffer pointer to 0x0078F328
str.buffer pointer to 0x0078F328
Hello World!
Invoking destructor, clearing up
Invoking destructor, clearing up
*/