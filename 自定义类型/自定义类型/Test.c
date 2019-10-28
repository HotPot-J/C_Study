#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
1.结构体的声明：
       struct 结构体名  例子： struct Student
	   {                     {
	   成员变量;                char name[20];
	   };                       int age;
	                            int tel;
								//......等等
							 };
//什么是声明 什么是定义？ 上述受声明 而定义：struct Student s;
struct 结构体名{。。。}stu; 此时stu为该结构体类型变量  同上一行的s为同一类型变量
typedfe struct 结构体名{。。。}stu; 此时stu为类型  可以用stu s；代替struct Student s;
//**结构体内存对齐（空间换时间） 见课件： 
struct s{char c1；char c2；int i；}； vs默认对齐数为8
c1c2--i---   c1为首元素放在相对地址为0的地方 char字节1<8 所以c2对齐数为1放在1的倍数地址
 处 所以直接放在c1后面就行     i的对齐数为4 放在4的倍数 往后加4的地方  该结构体成员中 
最大对齐数为4 所以结构体大小为4的倍数 最近的倍数为8 由于i占4个字节 此时的总体字节数正好满足结构体大小                                                                                        
所以总大小为8个字节
//结构体传参最好传指针

2.  位段  ：
         1.位段的成员可以是 int  unsigned int  signed int   或者是char（属于整形家族）类型
		 2.位段在空间上是按照以4个字节（int）或者1个字节（char）的方式来开辟的
		 3.位段不跨平台
*/                                  
//int main(){
//	struct t
//	{
//		char c1;
//		char c2;
//		int i;
//	};
//	struct s         //c1---i---c2---   12字节
//	{           
//		char c1;
//		int i;
//		char c2;
//	};
//	printf("%d\n", sizeof(struct t));
//	printf("%d\n", sizeof(struct s));
//	return 0;
//}
//	struct A
//	{                  //由于a b c 一共17位 所以一个整型int就能放得下 而d 30位需要令开一个整型int空间
//		//整个A的字节大小为8个字节 即两个整型int的大小
//		int _a : 2;
//		int _b : 5;
//		int _c : 10;
//		int _d : 30;
//	};
//	printf("%d\n", sizeof(struct A));
//	struct S
//	{
//		char a : 3;  //a b 一共8位 占用一个字节   
//		char b : 4;
//		char c : 5;  //c 5位  一个字节放不下d的4位 所以自己占用一个字节
//		char d : 4;  //d 4位 占用一个字节     所以S大小3个字节
//
//	};
//	printf("%d\n", sizeof(struct S));
//
//	return 0;
//}

/*
联合体（共用体）  使几个变量共享同一段内存的结构，
                 union 共用体名
                 {  成员列表
				 }  变量列表；
 1.共用体变量所占的内存长度等于最长的成员的长度。
 2.同一个内存段可以用来存放几种不同类型的成员，但在每一瞬间只能存放其中一个成员，而不是同时存放几个。				    
*/
//int main(){
//	union S{
//		int a ;
//		char b;
//		float c;
//	};
//	union S T;
//	T.a = 98;
//	printf("%d,%c,%f", T.a, T.b, T.c);  //98  字符a  0.000000    所以共用体的初始化列表只能有一个常量
//	return 0;                         //也可以单独初始化某一指定成员 但不可初始化三个成员（举例如下）
//}
//S={98,b,2.0}  该初始化错误 同时初始化三个成员
// S.c = 1.0; S.b = 'c'; S.a = 40; 这三条语句逐条执行完以后 实际上是指定初始化了S.c  分别用
//%d  %c  %f 输出的话，结果为 40 '('   0.000000

/*
枚举类型    enum 枚举名 {枚举元素列表}；  //其中枚举名应遵循标识符的命名规则（首字母大写）
enum Weekday
{
 sun，
 mon，
 tue，
 wed，
 thu，fri，sat
};               enum Weekday workday，weekend；
1. c编译对枚举类型的枚举元素按常量处理，故称枚举常量  不能对其赋值：sun =  10；则错误
2.没有一个枚举元素都代表一个整数，c语言编译按定义时的顺序默认他们的值为0，1，2，3...... 
  对于上面的枚举定义则sun的值为0，mon的值为1以此类推 
  workday = mon； //正确 相当于workday = 1
  weekend = sun；//正确 相当于weekend = 0
  weekday = monday；//错误 monday不是指定的枚举常量之一
*/
int main(){
	enum Weekday{sun,mon,tue,wed,thu,fri,sat};
	enum Weekday workday, weekend;
	workday = mon;
	weekend = sun;
	//weekend = monday; 错误 monday不是指定的枚举常量之一
	printf("%d,%d,%d", workday, weekend, tue );//1 0 2
	return 0;
}