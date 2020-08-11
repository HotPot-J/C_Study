//#define _crt_secure_no_warnings 1
//#include<stdio.h>
//void yhsj(int arr[][10],int row,int col){
//	for (int i = 0; i < row; i++){
//		for (int j = 0; j <= i; j++){
//			if (i == 0 || i == j){
//				arr[i][j] = 1;
//			}
//			else{
//				arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
//			}
//
//		}
//	}
//}
//void show(int arr[][10], int row, int col){
//	for (int i = 0; i < row; i++){
//		for (int j = 0; j <= i; j++){
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main(){
//	
//	int arr[10][10] = {0};
//	yhsj(arr, 10, 10);
//	show(arr, 10, 10 );
//
//	
//	return 0;
//}