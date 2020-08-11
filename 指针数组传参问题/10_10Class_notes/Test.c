
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*
1.void qsort(参数列表)函数  c语言库函数  排序  其头文件：<stdlib.h>

*/
/*void qsort(int* arr,int len){  //冒泡排序 
	int m; int flag = 0;
	for (int i=0; i < len-1; i++){  //控制趟数
		int j = 0;
		flag = 0;
		for ( j ; j < len-1-i;j++){
		   if (arr[j]>arr[j + 1]){
				m = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = m;
				flag = 1;
			}
	   }
		if (!flag){
			break;
		}
	}
}
*/

//int main(){

	//二维数组 
	//对于二二维数组 例：a[2][2]  &a[0]代表的是第一行的地址  a[0]代表第一行的数组名 类比一维数组sizeof（数组名）其结果为该数组的字节大小
	//a指向第一行 保存第一行地址 其类型为数组指针
/*
int a[3][4] = {0};
	printf("%d\n",sizeof(a));  //计算整个数组字节大小： 12*4=48
	printf("%d\n",sizeof(a[0][0]));//下标为0，0的元素长字节大小：4
	printf("%d\n",sizeof(a[0]));//对于二维数组 a[0]是其第一行的数组名 所以把第一行类比为一维数组其字节大小为：16
	printf("%d\n",sizeof(a[0]+1)); // a[0]为第一行数组名，而数组名代表数组首元素地址 其+1代表数组第二个元素地址即：&a[0][1]
	printf("%d\n",sizeof(*(a[0]+1))); //同上一行 所以 *（&a[0][1]）= a[0][1] 该元素字节大小为：4
	printf("%d\n",sizeof(a+1)); //a为整个二维数组的数组名 代表整个数组首元素地址即第一行地址 其+1即第二行的地址 地址字节大小为：4
	printf("%d\n",sizeof(*(a+1))); //同上一行 *（a+1）为第二行字节长度为：16
	printf("%d\n",sizeof(&a[0]+1));//为第二行地址 地址字节大小为：4
	printf("%d\n",sizeof(*(&a[0]+1)));//第二行元素字节大小为：16
	printf("%d\n",sizeof(*a)); //第一行元素字节大小为：16
	printf("%d\n",sizeof(a[3])); //编译期间确定 不会参与运算a[0] a[1]都为其1、2行数组名 则a[3]在编译中也为与a[0]、a[1]相同数据类型 其字节长度为：16
	*/


	//用字符串给arr数组初始化
	  
	/*
	char arr[] = "abcdef"; 
	printf("%d\n", sizeof(arr));  //7  字符串后系统会自动有\0 用字符串给arr初始化以后 arr最后一个元素为\0 所以长度为7
	printf("%d\n", sizeof(arr + 0)); //4 传进去的就是一个首元素的地址 地址长度为4个字节
	printf("%d\n", sizeof(*arr));  //1 传进去的为首元素'a' 其长度为1个字节
	printf("%d\n", sizeof(arr[1])); // 1
	printf("%d\n", sizeof(&arr));//4 地址长度为4个字节
	printf("%d\n", sizeof(&arr + 1)); //4  地址长度为4个字节
	printf("%d\n", sizeof(&arr[0] + 1));// 4  传进去的为地址长度为4个字节

	printf("%d\n", strlen(arr));//6 传进去的为arr首元素地址 到\0结束 所以长度为6
	printf("%d\n", strlen(arr + 0)); //6
	//printf("%d\n", strlen(*arr)); //语法错误
	//printf("%d\n", strlen(arr[1]));//语法错误
	//printf("%d\n", strlen(&arr)); //语法错误 应该用一个数组指针去接收&a
	//printf("%d\n", strlen(&arr + 1)); //语法错误 应该用一个数组指针去接收&a
	printf("%d\n", strlen(&arr[0] + 1));//5 传的是第二个元素的地址 其到\0的
	*/
	


	//字符串
    /*
	char *p = "abcdef";
	/*printf("%d\n", sizeof(p));//4  p就是一个指针 保存地址  地址为4个字节 
	printf("%d\n", sizeof(p + 1)); //4
	printf("%d\n", sizeof(*p)); //1 为首元素
	printf("%d\n", sizeof(p[0]));//1
	printf("%d\n", sizeof(&p));//4
	printf("%d\n", sizeof(&p + 1));//4 
	printf("%d\n", sizeof(&p[0] + 1));//4

	printf("%d\n", strlen(p));//6  p为指针 指向该字符串长度为6
	printf("%d\n", strlen(p + 1));//5 传进去的为第二个元素地址 到\0前一个元素的长度为5
	//printf("%d\n", strlen(*p)); //语法错误 给strlen函数传入了字符a 
	//printf("%d\n", strlen(p[0])); //语法错误
	//printf("%d\n", strlen(&p)); //语法错误  应该用一个数组指针去接受&p
	//printf("%d\n", strlen(&p + 1));//语法错误  应该用一个数组指针去接受&p
	printf("%d\n", strlen(&p[0] + 1));//5  传进去的为第二个元素地址 到\0前一个元素的长度为5
	*/
	


    //字符数组 
	/*
	char arr[] = {'a','b','c','d','e','f'};

	printf("%d\n", sizeof(arr)); //6
	printf("%d\n", sizeof(arr+0));//4  代表的是一个地址  地址为4个字节
	printf("%d\n", sizeof(*arr));//1
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr)); //4
	printf("%d\n", sizeof(&arr+1));//4
	printf("%d\n", sizeof(&arr[0]+1));//4 
	
	//strlen函数为计算字符串长度 遇见\0停止    其参数为指针类型给其传递的参数应与其保持一致
	printf("%d\n", strlen(arr));//arr为地址可以传 该数组没有\0所以打印的是随机数 X
	printf("%d\n", strlen(arr + 0));//随机数 X
	//printf("%d\n", strlen(*arr)); //语法错误
	//printf("%d\n", strlen(arr[1]));//语法错误
	//printf("%d\n", strlen(&arr));//语法错误 &arr为整个数组的地址 因该用一个数组指针去接收
	//printf("%d\n", strlen(&arr + 1));// 语法错误 其类型也是整个数组的类型 因该用一个数组指针去接收
	printf("%d\n", strlen(&arr[0] + 1));//首元素地址+1 为第二个元素地址 X-1
	
	*/
	

	/*一维数组
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a)); //16 整个数组字节大小
	printf("%d\n", sizeof(a + 0));//4  a+0发生运算 代表首元素地址这个值 地址为4个字节 
	printf("%d\n", sizeof(*a));//4  解引用a（其为首元素地址），代表首元素即1
	printf("%d\n", sizeof(a + 1));//4 a+1代表将数组第二个元素地址这个值传入sizeof这个函数
	printf("%d\n", sizeof(a[1]));//4  传入的是第二个元素
	printf("%d\n", sizeof(&a));//4  传入的是一个地址，地址为4个字节
	printf("%d\n", sizeof(*&a)); //16  取地址a（即&a）为整个数组的地址，再对其解引用即传入整个数组 其大小为16个字节
	printf("%d\n", sizeof(&a + 1)); //4 代表传入数组第二个元素的地址  地址为4个字节
	printf("%d\n", sizeof(&a[0])); //4   数组首元素地址  地址为4个字节
	printf("%d\n", sizeof(&a[0] + 1));//4 首元素地址加一为第二个元素地址 还是传入了一个地址 而地址为4个字节
	*/
	 
	 
//	 return 0; 
//}
//	*/


