#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>       
#include<math.h>
/*1.��д������ 
unsigned int reverse_bit(unsigned int value); 
��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ�� 

�磺 
��32λ������25���ֵ�������и�λ�� 
00000000000000000000000000011001 
��ת�󣺣�2550136832�� 
10011000000000000000000000000000 
���������أ� 
2550136832 */
//unsigned int reverse_bit(unsigned int value){  //��������  (a>>1)&1   ����˼����  ��������һλ���ֺ�1�߼���Ľ��  �����test_YouYi.c
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
//	printf("%u\n",c);   //��u��ʮ���������unsigned������(�޷�����)��
//	                   //ע�⣺%d��%u���޷��ŵ���ֵ��Χ��Ҳ���Ǽ��޵�ֵ����Ȼ��ֵ��ӡ����������
//	return 0;
//}
////2.��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ�� 
//int average(int a, int b){
//	int ave = ((a&b) + ( (a^b)>> 1) );
//	return ave;
//}
////�Ƶ�����
////&������ȡ��ͬ����˼,^����Ϊȡ��ͬ����˼��<<1Ϊ��2����˼����ô�������ְ���ͬ�Ĳ��ֳ���2���벻ͬ������ӣ���ô������Ϊ��������֮��
//void sum(int a, int b){
//	printf("�ͣ�%d\n",(( (a&b) <<1 ) + a^b)); 
//	//����������������Զ���>>1,���ܵõ�a��b��ƽ���������Եõ���
//	//  (( (a&b) <<1 ) + a^b)) >> 1 == ( (a&b)  + ((a^b) >>1) )
//}
//int main(){
//	int a, b;
//	scanf("%d%d", &a, &b);
//	int ave = average(a, b);
//	sum(a, b);
//	printf("%d��%d��ƽ����Ϊ�� %d\n",a,b,ave);
//	return 0;
//}
////3.���ʵ�֣� һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ����ҳ�������֡���ʹ��λ���㣩
////˼�룺������ͬ��������򣨼�^���Ľ��Ϊ0����0��������κ����ֵ��������κ����� 
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
//	printf("����һ�ε�����Ϊ�� %d\n",c);
//	return 0;
//}
//4.��һ���ַ����������Ϊ:"student a am i",���㽫��������ݸ�Ϊ"i am a student".Ҫ�󣺲���ʹ�ÿ⺯����ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
char* fun1(char* a,int i,int j){ //�˺���ʵ�ֵ����ַ�����
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