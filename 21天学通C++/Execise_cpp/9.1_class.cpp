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
		cout << "Myname name is " << name;
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
Myname is Liuxuewen, and 25 years old
Myname is Gaoman, and 24 years old
*/