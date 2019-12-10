#include <stdio.h>
#include <string.h>

typedef struct stu{
	int number;
	char *name;//
	int grade;
	int age;

}STU;
    struct sdu{
        char *name;  //姓名
        int num;  //学号
        int age;  //年龄
        char group;  //所在小组 
        float score;  //成绩
    }class[5] = {
        {"Li ping", 5, 18, 'C', 145.0},
        {"Zhang ping", 4, 19, 'A', 130.5},
        {"He fang", 1, 18, 'A', 148.5},
        {"Cheng ling", 2, 17, 'F', 139.0},
        {"Wang ming", 3, 17, 'B', 144.5}
    };
    
int main(int argc, char const *argv[])
{
	STU stu1,stu2; 
	STU *p = &stu1; //STU *p; p=&stu;
	stu1.number=103004;
	stu1.age = 19;
	stu1.name = "tom";
	stu1.grade = 111;
	stu2.number=103005;
	stu2.age = 19;
	stu2.name = "rom";
	stu2.grade = 111;
	printf("%s\t%d\n",stu1.name,stu1.age);
	printf("%s\t%d\n",p->name,p->age);
	printf("%s\t%d\n",(*p).name,(*p).age);

	return 0;
}