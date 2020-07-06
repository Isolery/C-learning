#include <iostream>

using namespace std;

class Human
{
private:    //����������Ϊ˽�еģ��������ⲿֱ�ӷ�����
	int age;
	string name;

public:    //����������Ϊ���У����ⲿ����
	Human()    //���캯���ڴ�������ʱ������
	{
		age = 1;    //��ʼ������ֹ�����Աδ��ֵ����ɲ�ȷ����ֵ
		cout << "Constructed an instance of class Human" << endl;
	}

	Human(string humansName, int huamnsAge)
	{
		name = humansName;
		age = huamnsAge;
		cout << "Overloaded constructor creates" << endl;
		IntroductionSelf();
	}

	void SetAge(int inputAge)
	{
		age = inputAge;
	}

	void SetName(string inputName)
	{
		name = inputName;
	}

	void IntroductionSelf()
	{
		cout << "My name is " << name;
		cout << ", and " << age << " years old" << endl;
	}
};

int main(void)
{
	Human firstMan;    //ʹ��Ĭ�Ϲ��캯��
	firstMan.SetName("Liuxuewen");
	firstMan.IntroductionSelf();

	Human firstWoman("Gaoman", 24);    //ʹ�����ع��캯��
}

/* output:
-----------------------------------------------
Constructed an instance of class Human
My name is Liuxuewen, and 1 years old
Overloaded constructor creates
My name is Gaoman, and 24 years old
*/