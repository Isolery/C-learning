#include <iostream>

using namespace std;

class Human
{
private:    //����������Ϊ˽�еģ��������ⲿֱ�ӷ�����
	int age;
	string name;

public:    //����������Ϊ���У����ⲿ����
	void SetAge(int inputAge)
	{
		age = inputAge;
	}

	void SetName(string inputName)
	{
		name = inputName;
	}

	void Introduction()
	{
		cout << "My name name is " << name;
		cout << ", and " << age << " years old" << endl;
	}
};

int main(void)
{
	Human firstMan;
	firstMan.SetAge(25);
	firstMan.SetName("Liuxuewen");

	Human firstWoman;
	firstWoman.SetAge(24);
	firstWoman.SetName("Gaoman");

	firstMan.Introduction();
	firstWoman.Introduction();
}

/* output:
-----------------------------------------------
My name is Liuxuewen, and 25 years old
My name is Gaoman, and 24 years old
*/