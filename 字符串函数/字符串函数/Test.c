#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
/*
// 1. 什么是const关键字？
 我们可以通过const关键字来声明一个常量： const int a ;声明a为一个int类型的数且不能被修改
   2. 如何让常量拥有一个值？
 方法一：由于如此声明下a的值无法被修改 所以一开始在声明时就对常量进行初始化：const int a = 10;
 方法二：在函数中声明为const的形参，在函数调用时会得到实参的值： 
      例如memmove（void*dst，const void*src,size_t len）; 
	  其中第一个参数是将字符串复制到（dst）那里去，所以这段内存区域必须是可写的
	  而第二个参数，是要将（stc）什么样的字符串复制出去，我们对这段内存区域只做读取，不写
   3.指向常量的指针：
        int const a = 1;
		int const b= 2;
		int const* pa = &a;
		printf("%d",*pa);//输出结果是1 
	    //*pa = b; 此时无法通过*pa来更改pa所指向的值
		pa = &b;  //但是可以改变pa的值 
		printf("%d",*pa);//输出结果是2   
	结论：用const修饰的变量，在int const*类型的指针指向时，不可用*解引用去修改变量值，只能去访问
	      但是可以修改int const*类型的指针的值 
   4. 常量指针
        int  a = 1;
		int const b= 2;
		int *const pa = &a;
		printf("%d",*pa);//输出结果是1 
	    //pa = &b; 此时无法更改pa的值
		*pa = b;  //但是可以改变通过解引用*pa来修改变量a的值 
		printf("%d",*pa);//输出结果是2 
    结论：用*const定义的指针 无法被修改，但是可以通过解引用去修改其所指向的变量的值

	长度不受限的字符串函数：
一、strcmp函数 字符串比较函数   在库函数中的定义：int strcmp（const char*string1,const char*string2）;
                                                str1<str2 return <0
												str1>str2 return >0
												str1 = str2 return 0
其实际上比较的是字符串所对应的ASCLL码值与长短无关 例如'abcd'>'abccccccc'
*/
////模拟实现strcmp函数
int my_strcmp(const char* str1, const char* str2){ //之所以用const修饰是因为只需要比较两个字符串而不用
	                                              //修改这两个字符串
	assert(str1 != NULL);
	assert(str2 != NULL);   //防止str1与str2为空指针
	while (*str1 == *str2 ){
		if (*str1 == '\0'){
			return 0;
		}
		++str1;
		++str2;
	}
	if (*str1 > *str2){
		return 1;
	}
	else{
		return -1;
	}
}
int main(){
	char str1[] = "abcd";
	char str2[] = "abcccc";
	int a = strcmp(str1, str2);
	int b = my_strcmp(str1, str2);
	printf("%d\n", a);//输出结果为1
	printf("%d\n", b);//输出结果为1
	return 0;
}


/*
长度受限的字符串函数
二、strncpy函数   拷贝一个字符串中的字符到另一个字符串中的函数 
    char *strncpy(char *strDest,const char *strSource,size_t count);//count表示要拷贝的字符个数
	当count大于strSource字符串长度的时候 自动往后补0;
*/
//模拟实现strncpy函数
char *my_strncpy(char *strDest, const char *strSource, size_t count){
  assert(strDest != NULL);
  assert(strSource != NULL);
	char *str = strDest;
	while (count){
		if (*strSource == '\0'){
			*str = '\0';
			*str++;       //当count大于strSource字符串长度的时候 自动往后补0;
		}
		else{
			*str = *strSource;
			++str;
			++strSource;
		}
		--count;
	}
	return str;
}
int main(){
	char arr1[20] = { 0 };
	char arr2[20] = { 0 };
	//strncpy(arr1, "hello", 8);
	*my_strncpy(arr2, "hello", 8);
	//printf("%s\n", arr1);
	printf("%s\n", arr2);
	return 0;
}

/*
三、strncat函数 字符串追加   char *strncat(char *strDest,const char *strSource,size_t count);
  从strDest字符串的'\0'的位置开始追加strSource
  追加完后面会自动在末尾补上一个'\0’
  当count大于strSource字符串长度的时候 不再往后补任何东西 直接添加'\0'即可
  而且当遇到strSource中的'\0'就不继续往后拷贝了 直接添加'\0'
*/
////模拟实现strncat函数
char *my_strncat(char *strDest, const char *strSource, size_t count){
	assert(strDest != NULL);
	assert(strSource != NULL);
	char *str = strDest;
	while (*str){  //让str指针指向目标字符串的'\0'的位置
		str++;
	}
	while (count){
		if (*strSource == '\0'){
			break;               //当count大于strSource字符串长度的时候 不再往后补任何东西 直接添加'\0'即可
		}
		else{
			*str = *strSource;
			str++;
			strSource++;
		}
		count--;
	}
	*(str + 1) = '\0';   //追加完后面会自动在末尾补上一个'\0’
	return str;
}
int main(){
	char arr1[20] = "hello ";
	strncat(arr1, "world", 5);
	printf("%s\n", arr1);
	char arr2[20] = "hello ";
	my_strncat(arr2, "world", 5);
    printf("%s\n", arr2);
	return 0;
}

/*
四、strncmp函数 比较前n个字符大小 int strncmp(char *strDest,const char *strSource,size_t count);
*/
////模拟实现strncmp函数
int my_strncmp(const char *strDest, const char *strSource, size_t count){
	while (count){
		if (*strDest == *strSource){
			strDest++;
			strSource++;
		}
		else if (*strDest > *strSource){
			return 1;
		}
		else{
			return -1;
		}
		--count;
	}
	return 0;
}
int main(){
	int ret1 = strncmp("abcde", "abcdddd",4);
	int ret2 = my_strncmp("abcde", "abcdddd", 4);
	printf("%d", ret1);
	printf("%d", ret2);
	return 0;
}

/*
5、    字符串查找（匹配）函数         char*strstr(char *string,const char *strCharSet);
                                string是被查找的字符串
				                strCharSet是要去查找的字符串
	返回这个字符串第一次出现的位置   若没有找到返回 NULL
*/
//模拟实现strstr函数 重点！！！  
char *my_strstr(const char*str1, const char*str2){
	assert(str1!=NULL);
	assert(str2!=NULL);
	const char *s1 = str1;
	const char *s2 = str2;
	const char *cp = str1;//控制循环 并记录当前如果比对成功 需要返回的位置
	if (*str2 == '\0'){   //如果需要查找一个空字符串 直接返回str1；
		return (char *)str1;
	}
	while (*s1){
		s1 = cp;
		s2 = str2;//让字串回到起始位置
		while (*s1 && *s2 && *s1 == *s2){ //该循环退出条件依次为：str1走完了 str2走完了 str1和str2不相等
			s1++;
			s2++;
		}
		if (*s2 == '\0'){  //此时字串走到结尾 说明匹配成功
			return  (char*)cp;  //cp定义的时候为const char* 类型 而该函数返回值为char*类型 所以强转为char*类型 才不会有警告
		}
		cp++;
	}
	return NULL;
}
int main(){
	char *p1 = "abcdbabcdefghi";
	char *p2 = "abcdef";
    char *ret1 = strstr(p1, p2);//在p2中找有没有p1这个字符串
	char *ret2 = my_strstr(p1, p2);
	printf("%s\n", ret1);
	printf("%s\n", ret2);
	return 0;
}
//内存相关的函数：
/*
memcpy（内存拷贝函数）函数：void *memcpy(void *destination,const void *source,size_t num);
  1.函数memcopy从source的位置开始向后赋值num个字节数据到destination的内存位置
  2.strcpy遇到'\0'就停止了 而memcpy不会
  3.
*/
//模拟实现memcpy函数
void *my_memcpy(void *dest,const void *source,size_t num){
	assert(dest!=NULL);
	assert(source!=NULL);
	char *Dest = dest;//由于要一个字节一个字节的拷贝 所以强制转换为char*类型
	const char *Source = source;
	while (num--){
		(*Dest) = *Source;
		Dest++;
		Source++;
	}
	return dest;
}
int main(){
	int arr1[] = { 0, 1, 2, 3, 4, 5, 6 };
	int arr2[10] = { 0 };
	memcpy(arr2, arr1, 5 * sizeof(arr2[0]));
	my_memcpy(arr2, arr1, 5 * sizeof(arr2[0]));
	printf("%d,%d,%d", arr2[0], arr2[3], arr2[4]);
	return 0;
}
/*
7.在内存重叠情况下进行内存拷贝，需要使用memmove函数
1.内存重叠举例：arr1[]={1,2,3,4,5,6};   
               若需要把arr1前两个元素拷贝到2 3 个元素内存中 即arr1变为：1 1 2 4 5 6
			   此时当把1拷贝到2内存中是 2 已经不存在了  所以arr1实际变为：1 1 1 4 5 6 
void *memmove(void *dest,const void *sour,size_t n);
*/
//模拟实现memmove函数
void *my_memmove(void *dest, const void *sour, size_t n){
//为了解决内存重叠问题  我的分析如下：
//如果sour的地址小于dest地址 说明sour数据在前 dest数据在后 如果从后往前拷贝则能避免内存重叠
//如果sour的地址大于dest地址 说明sour数据在后 dest数据在前 如果从前往后拷贝则能避免内存重叠
	assert(dest != NULL);//1234 
	assert(sour != NULL);
	char * Dest = dest;//12345
	const char * Sour = sour;
	if (sour < dest){
		while (n){
			*(Dest +n-1) = *(Sour + n-1);//从后往前拷贝 由于直接*（Sour+n）会指向sour的下一个元素首地址 会赋值有误 所以需要-1 
			n--;
		}
		*Dest = *Sour;   //由于当n==0时不进入循环导致*(dest + 0) = *(sour + 0);无法执行所以单独添加这一行
	}
	if (Sour > Dest){
		while (n--){
			*Dest = *Sour;//从前往后拷贝
			Dest++;
			Sour++;
		} 
	}
	return dest;
}
int main(){
	int arr[] = { 1, 2, 3, 4, 5 };
	//测试当sour<dest  从后往前拷贝
	//memmove(arr + 1, arr, 2 * sizeof(arr[0]));//把arr变为：11245
   // my_memmove(arr + 1, arr, 2 * sizeof(arr[0]));//测试成功

	//测试当sour>dest  从前往后拷贝
	//memmove(arr, arr + 1, 2 * sizeof(arr[0]));//把arr变为：23345
	my_memmove(arr, arr + 1, 2 * sizeof(arr[0]));//测试成功
	for (int i = 0; i < 5; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}