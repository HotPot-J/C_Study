
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*
1.void qsort(�����б�)����  c���Կ⺯��  ����  ��ͷ�ļ���<stdlib.h>

*/
/*void qsort(int* arr,int len){  //ð������ 
	int m; int flag = 0;
	for (int i=0; i < len-1; i++){  //��������
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

	//��ά���� 
	//���ڶ���ά���� ����a[2][2]  &a[0]������ǵ�һ�еĵ�ַ  a[0]�����һ�е������� ���һά����sizeof��������������Ϊ��������ֽڴ�С
	//aָ���һ�� �����һ�е�ַ ������Ϊ����ָ��
/*
int a[3][4] = {0};
	printf("%d\n",sizeof(a));  //�������������ֽڴ�С�� 12*4=48
	printf("%d\n",sizeof(a[0][0]));//�±�Ϊ0��0��Ԫ�س��ֽڴ�С��4
	printf("%d\n",sizeof(a[0]));//���ڶ�ά���� a[0]�����һ�е������� ���԰ѵ�һ�����Ϊһά�������ֽڴ�СΪ��16
	printf("%d\n",sizeof(a[0]+1)); // a[0]Ϊ��һ����������������������������Ԫ�ص�ַ ��+1��������ڶ���Ԫ�ص�ַ����&a[0][1]
	printf("%d\n",sizeof(*(a[0]+1))); //ͬ��һ�� ���� *��&a[0][1]��= a[0][1] ��Ԫ���ֽڴ�СΪ��4
	printf("%d\n",sizeof(a+1)); //aΪ������ά����������� ��������������Ԫ�ص�ַ����һ�е�ַ ��+1���ڶ��еĵ�ַ ��ַ�ֽڴ�СΪ��4
	printf("%d\n",sizeof(*(a+1))); //ͬ��һ�� *��a+1��Ϊ�ڶ����ֽڳ���Ϊ��16
	printf("%d\n",sizeof(&a[0]+1));//Ϊ�ڶ��е�ַ ��ַ�ֽڴ�СΪ��4
	printf("%d\n",sizeof(*(&a[0]+1)));//�ڶ���Ԫ���ֽڴ�СΪ��16
	printf("%d\n",sizeof(*a)); //��һ��Ԫ���ֽڴ�СΪ��16
	printf("%d\n",sizeof(a[3])); //�����ڼ�ȷ�� �����������a[0] a[1]��Ϊ��1��2�������� ��a[3]�ڱ�����ҲΪ��a[0]��a[1]��ͬ�������� ���ֽڳ���Ϊ��16
	*/


	//���ַ�����arr�����ʼ��
	  
	/*
	char arr[] = "abcdef"; 
	printf("%d\n", sizeof(arr));  //7  �ַ�����ϵͳ���Զ���\0 ���ַ�����arr��ʼ���Ժ� arr���һ��Ԫ��Ϊ\0 ���Գ���Ϊ7
	printf("%d\n", sizeof(arr + 0)); //4 ����ȥ�ľ���һ����Ԫ�صĵ�ַ ��ַ����Ϊ4���ֽ�
	printf("%d\n", sizeof(*arr));  //1 ����ȥ��Ϊ��Ԫ��'a' �䳤��Ϊ1���ֽ�
	printf("%d\n", sizeof(arr[1])); // 1
	printf("%d\n", sizeof(&arr));//4 ��ַ����Ϊ4���ֽ�
	printf("%d\n", sizeof(&arr + 1)); //4  ��ַ����Ϊ4���ֽ�
	printf("%d\n", sizeof(&arr[0] + 1));// 4  ����ȥ��Ϊ��ַ����Ϊ4���ֽ�

	printf("%d\n", strlen(arr));//6 ����ȥ��Ϊarr��Ԫ�ص�ַ ��\0���� ���Գ���Ϊ6
	printf("%d\n", strlen(arr + 0)); //6
	//printf("%d\n", strlen(*arr)); //�﷨����
	//printf("%d\n", strlen(arr[1]));//�﷨����
	//printf("%d\n", strlen(&arr)); //�﷨���� Ӧ����һ������ָ��ȥ����&a
	//printf("%d\n", strlen(&arr + 1)); //�﷨���� Ӧ����һ������ָ��ȥ����&a
	printf("%d\n", strlen(&arr[0] + 1));//5 �����ǵڶ���Ԫ�صĵ�ַ �䵽\0��
	*/
	


	//�ַ���
    /*
	char *p = "abcdef";
	/*printf("%d\n", sizeof(p));//4  p����һ��ָ�� �����ַ  ��ַΪ4���ֽ� 
	printf("%d\n", sizeof(p + 1)); //4
	printf("%d\n", sizeof(*p)); //1 Ϊ��Ԫ��
	printf("%d\n", sizeof(p[0]));//1
	printf("%d\n", sizeof(&p));//4
	printf("%d\n", sizeof(&p + 1));//4 
	printf("%d\n", sizeof(&p[0] + 1));//4

	printf("%d\n", strlen(p));//6  pΪָ�� ָ����ַ�������Ϊ6
	printf("%d\n", strlen(p + 1));//5 ����ȥ��Ϊ�ڶ���Ԫ�ص�ַ ��\0ǰһ��Ԫ�صĳ���Ϊ5
	//printf("%d\n", strlen(*p)); //�﷨���� ��strlen�����������ַ�a 
	//printf("%d\n", strlen(p[0])); //�﷨����
	//printf("%d\n", strlen(&p)); //�﷨����  Ӧ����һ������ָ��ȥ����&p
	//printf("%d\n", strlen(&p + 1));//�﷨����  Ӧ����һ������ָ��ȥ����&p
	printf("%d\n", strlen(&p[0] + 1));//5  ����ȥ��Ϊ�ڶ���Ԫ�ص�ַ ��\0ǰһ��Ԫ�صĳ���Ϊ5
	*/
	


    //�ַ����� 
	/*
	char arr[] = {'a','b','c','d','e','f'};

	printf("%d\n", sizeof(arr)); //6
	printf("%d\n", sizeof(arr+0));//4  �������һ����ַ  ��ַΪ4���ֽ�
	printf("%d\n", sizeof(*arr));//1
	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr)); //4
	printf("%d\n", sizeof(&arr+1));//4
	printf("%d\n", sizeof(&arr[0]+1));//4 
	
	//strlen����Ϊ�����ַ������� ����\0ֹͣ    �����Ϊָ�����͸��䴫�ݵĲ���Ӧ���䱣��һ��
	printf("%d\n", strlen(arr));//arrΪ��ַ���Դ� ������û��\0���Դ�ӡ��������� X
	printf("%d\n", strlen(arr + 0));//����� X
	//printf("%d\n", strlen(*arr)); //�﷨����
	//printf("%d\n", strlen(arr[1]));//�﷨����
	//printf("%d\n", strlen(&arr));//�﷨���� &arrΪ��������ĵ�ַ �����һ������ָ��ȥ����
	//printf("%d\n", strlen(&arr + 1));// �﷨���� ������Ҳ��������������� �����һ������ָ��ȥ����
	printf("%d\n", strlen(&arr[0] + 1));//��Ԫ�ص�ַ+1 Ϊ�ڶ���Ԫ�ص�ַ X-1
	
	*/
	

	/*һά����
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a)); //16 ���������ֽڴ�С
	printf("%d\n", sizeof(a + 0));//4  a+0�������� ������Ԫ�ص�ַ���ֵ ��ַΪ4���ֽ� 
	printf("%d\n", sizeof(*a));//4  ������a����Ϊ��Ԫ�ص�ַ����������Ԫ�ؼ�1
	printf("%d\n", sizeof(a + 1));//4 a+1��������ڶ���Ԫ�ص�ַ���ֵ����sizeof�������
	printf("%d\n", sizeof(a[1]));//4  ������ǵڶ���Ԫ��
	printf("%d\n", sizeof(&a));//4  �������һ����ַ����ַΪ4���ֽ�
	printf("%d\n", sizeof(*&a)); //16  ȡ��ַa����&a��Ϊ��������ĵ�ַ���ٶ�������ü������������� ���СΪ16���ֽ�
	printf("%d\n", sizeof(&a + 1)); //4 ����������ڶ���Ԫ�صĵ�ַ  ��ַΪ4���ֽ�
	printf("%d\n", sizeof(&a[0])); //4   ������Ԫ�ص�ַ  ��ַΪ4���ֽ�
	printf("%d\n", sizeof(&a[0] + 1));//4 ��Ԫ�ص�ַ��һΪ�ڶ���Ԫ�ص�ַ ���Ǵ�����һ����ַ ����ַΪ4���ֽ�
	*/
	 
	 
//	 return 0; 
//}
//	*/


