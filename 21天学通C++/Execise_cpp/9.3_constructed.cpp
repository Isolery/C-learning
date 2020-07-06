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
	Human firstWoman;
	firstWoman.SetName("Gaoman");
	firstWoman.IntroductionSelf();
}

/* output:
-----------------------------------------------
Constructed an instance of class Human
My name is Gaoman, and 1 years old
*/