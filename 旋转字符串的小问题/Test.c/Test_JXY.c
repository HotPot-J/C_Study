#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
���磺����s1 = AABCD��s2 = BCDAA������1
����s1 = abcd��s2 = ACBD������0.
AABCD����һ���ַ��õ�ABCDA
AABCD���������ַ��õ�BCDAA
AABCD����һ���ַ��õ�DAABC
*/
//�����ȶԣ�
int fun1(char* a,char* c, int len){
	int i;
	char mid;
	char* b = a;
	int F  = 0;
	while (1){
		char* str1 = b; char* str2 = b + 1;
		mid = *str1;
        for (i = 0; i < len - 2; i++){
			*str1 = *str2;
			str1++;
			str2++;
		}
		++F;
		b[len - 2] = mid;
		int flag = 1;
		for (int t = 0; t < len; t++){
			if (b[t] == c[t]){
				flag++;
			}
			if (flag == len){
				return 1;
			}
			
		}
		if (F == len - 2){
			return 0;
		}
	
	}
}
//�����ȶԣ�
int fun2(char* a,char* c, int len){
	int i;
	char mid;
	char* b = a;
	int F = 0;//��¼��ת���� ��F=len-2ʱ����
	while (1){
		char* str1 = b + len - 2; char* str2 = b + len - 3;
		mid = *str1;
        for (i = 0; i < len - 2; i++){
			*str1 = *str2;
			str1--;
			str2--;
		}
		++F;
		b[0] = mid;
		int flag = 1;
        for (int t = 0; t < len; t++){ //�ж�a��c�ַ�����ʱ�Ƿ���� ����ȷ���1 ˵��c����a����ת�õ���
			if (b[t] == c[t]){
				flag++;
			}
			if (flag == len){
				return 1;
			}
		}
		if (F==len-2){  //F==len-2 ˵�����ַ����Ѿ�����ת��һȦ ��Ȼû����cƥ�� ˵��c������a��ת�õ���
			return 0;
		}
	}
}
int fun3(char*a,char*b,int len){
	if (fun1(a, b, len) == 1 || fun2(a, b, len) == 1){
		return 1;
	}
	else {
		return 0;
	}
}
int main(){
	char arr1[] = "AABCD";
	char arr2[] = "BCDAA";
	int len1 = sizeof(arr1) / sizeof(arr1[0]);
	char arr3[] = "ABCD";
	char arr4[] = "ACBD";
	int len2 = sizeof(arr3) / sizeof(arr3[0]);
	//int result1 = fun3(arr1, arr2, len1);
	int result2 = fun3(arr3, arr4, len2);
	printf("result2 = %d",result2);
	return 0;
}

///* 1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB*/
//char* fun(char* a, int len, int num){
//	int i;
//	char mid;
//	char* b = a;
//	while (num){
//		char* str1 = b; char* str2 = b + 1;//��������ָ��ֱ�ָ��ǰ����ǰ������ַ
//		mid = *str1;
//        for (i = 0; i < len - 2; i++){//��str2ָ���Ԫ�ط���str1ָ��ĵ�ַ�� ����5��Ԫ����תһ����Ҫ5-1�� 
//                                         �����ַ���ĩβ��\0�����ƶ� ����Ϊlen-2��
//			*str1 = *str2;
//			str1++;
//			str2++;
//		}
//		b[len - 2] = mid;
//		--num;                      //num������Ҫ��ת������ĸ ����ѭ������
//	}
//	return b;
//}
//int main(){
//	char arr[] = "ABCD";
//	int len = sizeof(arr)/sizeof(arr[0]);
//	int num; 
//	scanf("%d", &num);
//	char* result = fun2(arr, len, num);
//	for (int i = 0; i < len; i++){
//		printf("%c", result[i]);
//	}
//	return 0;
//}