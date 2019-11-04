#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
/*
// 1. ʲô��const�ؼ��֣�
 ���ǿ���ͨ��const�ؼ���������һ�������� const int a ;����aΪһ��int���͵����Ҳ��ܱ��޸�
   2. ����ó���ӵ��һ��ֵ��
 ����һ���������������a��ֵ�޷����޸� ����һ��ʼ������ʱ�ͶԳ������г�ʼ����const int a = 10;
 ���������ں���������Ϊconst���βΣ��ں�������ʱ��õ�ʵ�ε�ֵ�� 
      ����memmove��void*dst��const void*src,size_t len��; 
	  ���е�һ�������ǽ��ַ������Ƶ���dst������ȥ����������ڴ���������ǿ�д��
	  ���ڶ�����������Ҫ����stc��ʲô�����ַ������Ƴ�ȥ�����Ƕ�����ڴ�����ֻ����ȡ����д
   3.ָ������ָ�룺
        int const a = 1;
		int const b= 2;
		int const* pa = &a;
		printf("%d",*pa);//��������1 
	    //*pa = b; ��ʱ�޷�ͨ��*pa������pa��ָ���ֵ
		pa = &b;  //���ǿ��Ըı�pa��ֵ 
		printf("%d",*pa);//��������2   
	���ۣ���const���εı�������int const*���͵�ָ��ָ��ʱ��������*������ȥ�޸ı���ֵ��ֻ��ȥ����
	      ���ǿ����޸�int const*���͵�ָ���ֵ 
   4. ����ָ��
        int  a = 1;
		int const b= 2;
		int *const pa = &a;
		printf("%d",*pa);//��������1 
	    //pa = &b; ��ʱ�޷�����pa��ֵ
		*pa = b;  //���ǿ��Ըı�ͨ��������*pa���޸ı���a��ֵ 
		printf("%d",*pa);//��������2 
    ���ۣ���*const�����ָ�� �޷����޸ģ����ǿ���ͨ��������ȥ�޸�����ָ��ı�����ֵ

	���Ȳ����޵��ַ���������
һ��strcmp���� �ַ����ȽϺ���   �ڿ⺯���еĶ��壺int strcmp��const char*string1,const char*string2��;
                                                str1<str2 return <0
												str1>str2 return >0
												str1 = str2 return 0
��ʵ���ϱȽϵ����ַ�������Ӧ��ASCLL��ֵ�볤���޹� ����'abcd'>'abccccccc'
*/
////ģ��ʵ��strcmp����
int my_strcmp(const char* str1, const char* str2){ //֮������const��������Ϊֻ��Ҫ�Ƚ������ַ���������
	                                              //�޸��������ַ���
	assert(str1 != NULL);
	assert(str2 != NULL);   //��ֹstr1��str2Ϊ��ָ��
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
	printf("%d\n", a);//������Ϊ1
	printf("%d\n", b);//������Ϊ1
	return 0;
}


/*
�������޵��ַ�������
����strncpy����   ����һ���ַ����е��ַ�����һ���ַ����еĺ��� 
    char *strncpy(char *strDest,const char *strSource,size_t count);//count��ʾҪ�������ַ�����
	��count����strSource�ַ������ȵ�ʱ�� �Զ�����0;
*/
//ģ��ʵ��strncpy����
char *my_strncpy(char *strDest, const char *strSource, size_t count){
  assert(strDest != NULL);
  assert(strSource != NULL);
	char *str = strDest;
	while (count){
		if (*strSource == '\0'){
			*str = '\0';
			*str++;       //��count����strSource�ַ������ȵ�ʱ�� �Զ�����0;
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
����strncat���� �ַ���׷��   char *strncat(char *strDest,const char *strSource,size_t count);
  ��strDest�ַ�����'\0'��λ�ÿ�ʼ׷��strSource
  ׷���������Զ���ĩβ����һ��'\0��
  ��count����strSource�ַ������ȵ�ʱ�� ���������κζ��� ֱ�����'\0'����
  ���ҵ�����strSource�е�'\0'�Ͳ��������󿽱��� ֱ�����'\0'
*/
////ģ��ʵ��strncat����
char *my_strncat(char *strDest, const char *strSource, size_t count){
	assert(strDest != NULL);
	assert(strSource != NULL);
	char *str = strDest;
	while (*str){  //��strָ��ָ��Ŀ���ַ�����'\0'��λ��
		str++;
	}
	while (count){
		if (*strSource == '\0'){
			break;               //��count����strSource�ַ������ȵ�ʱ�� ���������κζ��� ֱ�����'\0'����
		}
		else{
			*str = *strSource;
			str++;
			strSource++;
		}
		count--;
	}
	*(str + 1) = '\0';   //׷���������Զ���ĩβ����һ��'\0��
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
�ġ�strncmp���� �Ƚ�ǰn���ַ���С int strncmp(char *strDest,const char *strSource,size_t count);
*/
////ģ��ʵ��strncmp����
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
5��    �ַ������ң�ƥ�䣩����         char*strstr(char *string,const char *strCharSet);
                                string�Ǳ����ҵ��ַ���
				                strCharSet��Ҫȥ���ҵ��ַ���
	��������ַ�����һ�γ��ֵ�λ��   ��û���ҵ����� NULL
*/
//ģ��ʵ��strstr���� �ص㣡����  
char *my_strstr(const char*str1, const char*str2){
	assert(str1!=NULL);
	assert(str2!=NULL);
	const char *s1 = str1;
	const char *s2 = str2;
	const char *cp = str1;//����ѭ�� ����¼��ǰ����ȶԳɹ� ��Ҫ���ص�λ��
	if (*str2 == '\0'){   //�����Ҫ����һ�����ַ��� ֱ�ӷ���str1��
		return (char *)str1;
	}
	while (*s1){
		s1 = cp;
		s2 = str2;//���ִ��ص���ʼλ��
		while (*s1 && *s2 && *s1 == *s2){ //��ѭ���˳���������Ϊ��str1������ str2������ str1��str2�����
			s1++;
			s2++;
		}
		if (*s2 == '\0'){  //��ʱ�ִ��ߵ���β ˵��ƥ��ɹ�
			return  (char*)cp;  //cp�����ʱ��Ϊconst char* ���� ���ú�������ֵΪchar*���� ����ǿתΪchar*���� �Ų����о���
		}
		cp++;
	}
	return NULL;
}
int main(){
	char *p1 = "abcdbabcdefghi";
	char *p2 = "abcdef";
    char *ret1 = strstr(p1, p2);//��p2������û��p1����ַ���
	char *ret2 = my_strstr(p1, p2);
	printf("%s\n", ret1);
	printf("%s\n", ret2);
	return 0;
}
//�ڴ���صĺ�����
/*
memcpy���ڴ濽��������������void *memcpy(void *destination,const void *source,size_t num);
  1.����memcopy��source��λ�ÿ�ʼ���ֵnum���ֽ����ݵ�destination���ڴ�λ��
  2.strcpy����'\0'��ֹͣ�� ��memcpy����
  3.
*/
//ģ��ʵ��memcpy����
void *my_memcpy(void *dest,const void *source,size_t num){
	assert(dest!=NULL);
	assert(source!=NULL);
	char *Dest = dest;//����Ҫһ���ֽ�һ���ֽڵĿ��� ����ǿ��ת��Ϊchar*����
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
7.���ڴ��ص�����½����ڴ濽������Ҫʹ��memmove����
1.�ڴ��ص�������arr1[]={1,2,3,4,5,6};   
               ����Ҫ��arr1ǰ����Ԫ�ؿ�����2 3 ��Ԫ���ڴ��� ��arr1��Ϊ��1 1 2 4 5 6
			   ��ʱ����1������2�ڴ����� 2 �Ѿ���������  ����arr1ʵ�ʱ�Ϊ��1 1 1 4 5 6 
void *memmove(void *dest,const void *sour,size_t n);
*/
//ģ��ʵ��memmove����
void *my_memmove(void *dest, const void *sour, size_t n){
//Ϊ�˽���ڴ��ص�����  �ҵķ������£�
//���sour�ĵ�ַС��dest��ַ ˵��sour������ǰ dest�����ں� ����Ӻ���ǰ�������ܱ����ڴ��ص�
//���sour�ĵ�ַ����dest��ַ ˵��sour�����ں� dest������ǰ �����ǰ���󿽱����ܱ����ڴ��ص�
	assert(dest != NULL);//1234 
	assert(sour != NULL);
	char * Dest = dest;//12345
	const char * Sour = sour;
	if (sour < dest){
		while (n){
			*(Dest +n-1) = *(Sour + n-1);//�Ӻ���ǰ���� ����ֱ��*��Sour+n����ָ��sour����һ��Ԫ���׵�ַ �ḳֵ���� ������Ҫ-1 
			n--;
		}
		*Dest = *Sour;   //���ڵ�n==0ʱ������ѭ������*(dest + 0) = *(sour + 0);�޷�ִ�����Ե��������һ��
	}
	if (Sour > Dest){
		while (n--){
			*Dest = *Sour;//��ǰ���󿽱�
			Dest++;
			Sour++;
		} 
	}
	return dest;
}
int main(){
	int arr[] = { 1, 2, 3, 4, 5 };
	//���Ե�sour<dest  �Ӻ���ǰ����
	//memmove(arr + 1, arr, 2 * sizeof(arr[0]));//��arr��Ϊ��11245
   // my_memmove(arr + 1, arr, 2 * sizeof(arr[0]));//���Գɹ�

	//���Ե�sour>dest  ��ǰ���󿽱�
	//memmove(arr, arr + 1, 2 * sizeof(arr[0]));//��arr��Ϊ��23345
	my_memmove(arr, arr + 1, 2 * sizeof(arr[0]));//���Գɹ�
	for (int i = 0; i < 5; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}