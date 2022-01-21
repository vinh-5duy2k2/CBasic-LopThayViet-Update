#include<stdio.h>
#include<stdlib.h>
int main (){
	int n,i,*ptr;
	printf("Nhap so luong phan tu: "); scanf("%d",&n);
	
	ptr = (int *)malloc(n * sizeof(int));
	if(ptr == NULL){
		printf("Co loi!");
		return 1;
	}  
	fflush(stdin);
	for(i=0;i<n;i++){
		printf("Nhap phan tu thu %d: ",i+1); scanf("%d",&ptr[i]);
		fflush(stdin);
	}
	printf("Mang dao nguoc: \n");
	for(i=n-1;i>=0;i--){
		printf("%d ",ptr[i]);
	}
		free(ptr);
}

