#include <iostream>

using namespace std;

class Human
{
private:    //将属性设置为私有的，不能在外部直接访问它
	int age;
	string name;

public:    //将方法设置为共有，供外部调用
	Human()    //构造函数在创建对象时被调用
	{
		age = 1;    //初始化，防止对象成员未赋值而变成不确定的值
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
	Human firstMan;    //使用默认构造函数
	firstMan.SetName("Liuxuewen");
	firstMan.IntroductionSelf();

	Human firstWoman("Gaoman", 24);    //使用重载构造函数
}

/* output:
-----------------------------------------------
Constructed an instance of class Human
My name is Liuxuewen, and 1 years old
Overloaded constructor creates
My name is Gaoman, and 24 years old
*/