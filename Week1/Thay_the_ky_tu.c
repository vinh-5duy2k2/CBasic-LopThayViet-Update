#include<stdio.h>
#include<string.h>
#define max 100
int main(){
	char str[max+1],a,b;
	fflush(stdin);
	printf("Nhap chuoi: "); scanf("%s",str);
	printf("chuoi vua nhap: %s\n",str);
	fflush(stdin);
	printf("Nhap ky tu can thay the: ");scanf("%c",&a);
	fflush(stdin);
	printf("Nhap ky tu thay the: ");scanf("%c",&b);
	int i;
	for(i=0;i<strlen(str);i++){
		if(str[i] == a) str[i] =b;
	}
	printf("Chuoi da thay the: %s",str);
	
}
