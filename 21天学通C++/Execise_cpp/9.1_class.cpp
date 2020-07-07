#include <iostream>

using namespace std;

class Human
{
private:    //将属性设置为私有的，不能在外部直接访问它
	int age;
	string name;

public:    //将方法设置为共有，供外部调用
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