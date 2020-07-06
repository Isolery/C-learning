#include <iostream>

using namespace std;

class Human
{
public:
	int age;
	string name;
	
	void Introduction()
	{
		cout << "Myname name is " << name;
		cout << ", and " << age << " years old" << endl;
	}
};

int main(void)
{
	Human firstMan;
	firstMan.age = 25;
	firstMan.name = "Liuxuewen";

	Human firstWoman;
	firstWoman.age = 24;
	firstWoman.name = "Goaman";

	firstMan.Introduction();
	firstWoman.Introduction();
}

/* output:
-----------------------------------------------
Myname is Liuxuewen, and 25 years old
Myname is Gaoman, and 24 years old
*/