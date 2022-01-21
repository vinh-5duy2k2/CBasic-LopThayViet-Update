#include<stdio.h>
#define max 100
int compare_arr(int arr1[],int arr2[],int size){
	int i;
	for(i=0;i<size;i++){
		if(arr1[i]!=arr2[i]) return 0;
	}
	return 1;
}
int main (){
	int arr1[max],arr2[max],size;
	printf("Nhap so luong phan tu cho mang: ");scanf("%d",&size);
	printf("Nhap phan tu cho mang 1:\n");
	int i;
	for(i=0;i<size;i++){
		fflush(stdin);
		printf("Nhap phan tu thu %d: ",i+1); scanf("%d",&arr1[i]);
	}
	printf("Nhap phan tu cho mang 2:\n");
	for(i=0;i<size;i++){
		fflush(stdin);
		printf("Nhap phan tu thu %d: ",i+1); scanf("%d",&arr2[i]);
	}
	int check = compare_arr(arr1,arr2,size);
	if(check == 1 ){
		printf("2 mang giong nhau\n");
	} else {
		printf("2 mang khac nhau\n");
	}
	
}
