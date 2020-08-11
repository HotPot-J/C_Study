#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>       
#include<math.h>
/*1.编写函数： 
unsigned int reverse_bit(unsigned int value); 
这个函数的返回值是value的二进制位模式从左到右翻转后的值。 

如： 
在32位机器上25这个值包含下列各位： 
00000000000000000000000000011001 
翻转后：（2550136832） 
10011000000000000000000000000000 
程序结果返回： 
2550136832 */
//unsigned int reverse_bit(unsigned int value){  //经过测试  (a>>1)&1   的意思是是  移完的最后一位数字和1逻辑与的结果  结果见test_YouYi.c
//	unsigned int sum = 0;
//	for (int i = 0; i < 32; i++){
//		
//		sum += ((value >> i) & 1) *pow((double)2, 31-i);
//	}
//	return sum;
//}
//
//int main(){
//	unsigned int a = 25;
//
//	unsigned int c = reverse_bit(a);
//	printf("%u\n",c);   //％u以十进制数输出unsigned型数据(无符号数)。
//	                   //注意：%d与%u有无符号的数值范围，也就是极限的值，不然数值打印出来会有误。
//	return 0;
//}
////2.不使用（a+b）/2这种方式，求两个数的平均值。 
//int average(int a, int b){
//	int ave = ((a&b) + ( (a^b)>> 1) );
//	return ave;
//}
////推导过程
////&运算是取相同的意思,^运算为取不同的意思，<<1为乘2的意思。那么两个数字把相同的部分乘以2再与不同部分相加，那么其结果就为两个数字之和
//void sum(int a, int b){
//	printf("和：%d\n",(( (a&b) <<1 ) + a^b)); 
//	//所以如果给其结果除以二即>>1,就能得到a，b的平均数，所以得到：
//	//  (( (a&b) <<1 ) + a^b)) >> 1 == ( (a&b)  + ((a^b) >>1) )
//}
//int main(){
//	int a, b;
//	scanf("%d%d", &a, &b);
//	int ave = average(a, b);
//	sum(a, b);
//	printf("%d与%d的平均数为： %d\n",a,b,ave);
//	return 0;
//}
////3.编程实现： 一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。请找出这个数字。（使用位运算）
////思想：两个相同的数字异或（即^）的结果为0，而0异或其他任何数字等于其他任何数字 
//int Fun(int*a,int Len){
//	int b = a[0];
//	for (int i = 1; i < Len; i++){
//		b = b ^ a[i];
//	}
//	return b;
//}
//int main(){
//	int arr[] = { 1, 5, 9, 5, 9, 1, 8 };  
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int c = Fun(arr,len);
//	printf("出现一次的数字为： %d\n",c);
//	return 0;
//}
//4.有一个字符数组的内容为:"student a am i",请你将数组的内容改为"i am a student".要求：不能使用库函数。只能开辟有限个空间（空间个数和字符串的长度无关）。
char* fun1(char* a,int i,int j){ //此函数实现倒序字符功能
	char temp;
	while (i<j)
	{
		temp = a[i]; a[i] = a[j]; a[j] = temp;
		i++;
		j--;
	}
	return a;
}
char*fun2(char*b, int length){
	for (int i = 0; i < length; i++){
		int Len = 0;
		while ((b[i] != ' ')&& (b[i] != '\0'))
		{
			Len++;
			i++;
		}
		int k = i - Len; int j = i - 1;
		fun1(b, k, j);
		
	}
	return b;
}

    int main(){
	char arr[] = "student a am i";
    int length = sizeof(arr) / sizeof(arr[0]);
	int i = 0; int j = length - 1;
	char* str1 = fun1(arr, i, j);
	char* str2 = fun2(str1, length);
	for (int i = 0; i < length; i++){
		printf("%c", str2[i]);
	}
	return 0;
}