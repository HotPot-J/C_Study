#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
1.�ṹ���������
       struct �ṹ����  ���ӣ� struct Student
	   {                     {
	   ��Ա����;                char name[20];
	   };                       int age;
	                            int tel;
								//......�ȵ�
							 };
//ʲô������ ʲô�Ƕ��壿 ���������� �����壺struct Student s;
struct �ṹ����{������}stu; ��ʱstuΪ�ýṹ�����ͱ���  ͬ��һ�е�sΪͬһ���ͱ���
typedfe struct �ṹ����{������}stu; ��ʱstuΪ����  ������stu s������struct Student s;
//**�ṹ���ڴ���루�ռ任ʱ�䣩 ���μ��� 
struct s{char c1��char c2��int i��}�� vsĬ�϶�����Ϊ8
c1c2--i---   c1Ϊ��Ԫ�ط�����Ե�ַΪ0�ĵط� char�ֽ�1<8 ����c2������Ϊ1����1�ı�����ַ
 �� ����ֱ�ӷ���c1�������     i�Ķ�����Ϊ4 ����4�ı��� �����4�ĵط�  �ýṹ���Ա�� 
��������Ϊ4 ���Խṹ���СΪ4�ı��� ����ı���Ϊ8 ����iռ4���ֽ� ��ʱ�������ֽ�����������ṹ���С                                                                                        
�����ܴ�СΪ8���ֽ�
//�ṹ�崫����ô�ָ��

2.  λ��  ��
         1.λ�εĳ�Ա������ int  unsigned int  signed int   ������char���������μ��壩����
		 2.λ���ڿռ����ǰ�����4���ֽڣ�int������1���ֽڣ�char���ķ�ʽ�����ٵ�
		 3.λ�β���ƽ̨
*/                                  
//int main(){
//	struct t
//	{
//		char c1;
//		char c2;
//		int i;
//	};
//	struct s         //c1---i---c2---   12�ֽ�
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
//	{                  //����a b c һ��17λ ����һ������int���ܷŵ��� ��d 30λ��Ҫ�һ������int�ռ�
//		//����A���ֽڴ�СΪ8���ֽ� ����������int�Ĵ�С
//		int _a : 2;
//		int _b : 5;
//		int _c : 10;
//		int _d : 30;
//	};
//	printf("%d\n", sizeof(struct A));
//	struct S
//	{
//		char a : 3;  //a b һ��8λ ռ��һ���ֽ�   
//		char b : 4;
//		char c : 5;  //c 5λ  һ���ֽڷŲ���d��4λ �����Լ�ռ��һ���ֽ�
//		char d : 4;  //d 4λ ռ��һ���ֽ�     ����S��С3���ֽ�
//
//	};
//	printf("%d\n", sizeof(struct S));
//
//	return 0;
//}

/*
�����壨�����壩  ʹ������������ͬһ���ڴ�Ľṹ��
                 union ��������
                 {  ��Ա�б�
				 }  �����б�
 1.�����������ռ���ڴ泤�ȵ�����ĳ�Ա�ĳ��ȡ�
 2.ͬһ���ڴ�ο���������ż��ֲ�ͬ���͵ĳ�Ա������ÿһ˲��ֻ�ܴ������һ����Ա��������ͬʱ��ż�����				    
*/
//int main(){
//	union S{
//		int a ;
//		char b;
//		float c;
//	};
//	union S T;
//	T.a = 98;
//	printf("%d,%c,%f", T.a, T.b, T.c);  //98  �ַ�a  0.000000    ���Թ�����ĳ�ʼ���б�ֻ����һ������
//	return 0;                         //Ҳ���Ե�����ʼ��ĳһָ����Ա �����ɳ�ʼ��������Ա���������£�
//}
//S={98,b,2.0}  �ó�ʼ������ ͬʱ��ʼ��������Ա
// S.c = 1.0; S.b = 'c'; S.a = 40; �������������ִ�����Ժ� ʵ������ָ����ʼ����S.c  �ֱ���
//%d  %c  %f ����Ļ������Ϊ 40 '('   0.000000

/*
ö������    enum ö���� {ö��Ԫ���б�}��  //����ö����Ӧ��ѭ��ʶ����������������ĸ��д��
enum Weekday
{
 sun��
 mon��
 tue��
 wed��
 thu��fri��sat
};               enum Weekday workday��weekend��
1. c�����ö�����͵�ö��Ԫ�ذ����������ʳ�ö�ٳ���  ���ܶ��丳ֵ��sun =  10�������
2.û��һ��ö��Ԫ�ض�����һ��������c���Ա��밴����ʱ��˳��Ĭ�����ǵ�ֵΪ0��1��2��3...... 
  ���������ö�ٶ�����sun��ֵΪ0��mon��ֵΪ1�Դ����� 
  workday = mon�� //��ȷ �൱��workday = 1
  weekend = sun��//��ȷ �൱��weekend = 0
  weekday = monday��//���� monday����ָ����ö�ٳ���֮һ
*/
int main(){
	enum Weekday{sun,mon,tue,wed,thu,fri,sat};
	enum Weekday workday, weekend;
	workday = mon;
	weekend = sun;
	//weekend = monday; ���� monday����ָ����ö�ٳ���֮һ
	printf("%d,%d,%d", workday, weekend, tue );//1 0 2
	return 0;
}