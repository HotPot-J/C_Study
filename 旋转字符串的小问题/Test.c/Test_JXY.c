#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 = AABCD和s2 = BCDAA，返回1
给定s1 = abcd和s2 = ACBD，返回0.
AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA
AABCD右旋一个字符得到DAABC
*/
//左旋比对：
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
//右旋比对：
int fun2(char* a,char* c, int len){
	int i;
	char mid;
	char* b = a;
	int F = 0;//记录旋转次数 当F=len-2时结束
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
        for (int t = 0; t < len; t++){ //判断a与c字符串此时是否相等 若相等返回1 说明c是由a右旋转得到的
			if (b[t] == c[t]){
				flag++;
			}
			if (flag == len){
				return 1;
			}
		}
		if (F==len-2){  //F==len-2 说明该字符串已经右旋转了一圈 仍然没有与c匹配 说明c不是由a旋转得到的
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

///* 1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB*/
//char* fun(char* a, int len, int num){
//	int i;
//	char mid;
//	char* b = a;
//	while (num){
//		char* str1 = b; char* str2 = b + 1;//设置两个指针分别指向前数组前两个地址
//		mid = *str1;
//        for (i = 0; i < len - 2; i++){//把str2指向的元素放入str1指向的地址中 例如5个元素旋转一次需要5-1次 
//                                         由于字符串末尾的\0不用移动 所以为len-2次
//			*str1 = *str2;
//			str1++;
//			str2++;
//		}
//		b[len - 2] = mid;
//		--num;                      //num代表需要旋转几个字母 控制循环次数
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