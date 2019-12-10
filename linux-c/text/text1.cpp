#include <iostream>
#include <string>
using namespace std;

class students
{
public:
	//students(int nu , string na, char s ): number(nu), name(na), sex(s) {};
	int h;
	students(int nu, string na, char s);
	students(int nu);
	void display();
	~students();
private:
	int number;
	string name;
	char sex;
};

class students1: public students
{
public:
	void display_1();
	void display_monitor();

	students1(int nu, string na, char s, int nu1, string na1, char s1, string A, int H, int W):
		students( nu, na,  s), monitor(nu1, na1, s1)
	{
		addr = A;
		height = H;
		weight = W;
		cout << "构造函数:" << A << endl;
	}

	~students1() {
		cout << "析构函数:" << addr << endl;
	}
private:
	string addr;
	int height;
	int weight;
	students monitor;
};

void students::display() {
	cout << "num: " << number << endl;
	cout << "name: " << name << endl;
	cout << "sex: " << sex << endl;

}

void students1::display_1() {
	display();
	cout << "Addr: " << addr << endl;
	cout << "height: " << height << endl;
	cout << "weight: " << weight << endl;
}

void students1::display_monitor() {
	cout << "the monitor:" << endl;
	monitor.display();

}
students::students(int nu, string na, char s)
{
	number = nu;
	name = na;
	sex = s;
	cout << "构造函数:" << nu << endl;
}


students::students(int nu)
{
	number = nu;
	name = "default";
	sex = 's';
	cout << "构造函数:" << number << endl;

}

students::~students() {
	cout << "析构函数:" << number << endl;
}


int main(int argc, char const *argv[])
{
	students stu1(1001, "wanger", 'm');
	stu1.display();
	students stu2(1002, "wangxiaoyan", 'w');
	stu2.display();
	students stu3(1003);
	stu3.display();
	// students STU[3] = {students(1003), students(1001, "wanger", 'm'), students(1002, "wangxiaoyan", 'w')};
	// for (int i = 0; i < 3; i++)
	// {
	// 	STU[i].display() ;
	// }
	// students *pt;
	// pt = &stu1;//指向对象
	// pt->display();
	stu1.h = 1;
	int *p;
	p = &stu1.h;//指向公共数据成员
	cout << *p << endl;
	// void (students::*ps)();//声明指向公共成员函数的指针
	// ps = &students::display;//指向公共成员函数
	// (stu1.*ps)();
	students1 stu4(1001, "wanger", 'm', 1002, "moniter", 'm', "xindu avunue 8th", 178, 59);
	stu4.display_1();
	stu4.display_monitor();


	return 0;
}