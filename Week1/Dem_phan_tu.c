#include<stdio.h>	
int main(){
	int i,a[10],b[10];
	int index=0;
	int kiemtra = 1;
	printf("Nhap 10 phan tu cua mang \n");
	for(i=0;i<10;i++){
		printf("Nhap phan tu thu %d: ",i+1); scanf("%d", &a[i]);
		if(i==0){
			b[index]=a[0];
			index++;
		} else{
			int j;
			for( j=0;j<index;j++){
				if(a[i]==b[j]) {
					kiemtra= 0;
					break;
				}
				kiemtra = 1;
			}
			if(kiemtra==1){
				b[index]=a[i];
				index++;
			}
		
		}
		
	}
	printf("Mang gom a: ");
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("Mang phan tu phan biet gom: ");
	for(i=0;i<index;i++){
		printf("%d ",b[i]);
	}
	
}
