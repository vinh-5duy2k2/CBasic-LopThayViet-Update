#include<stdio.h>
#include<String.h>
#define max 100
void ThayThe(char *str,char a,char b);
int main(){
	char str[100];
	char a,b;
	printf("Nhap chuoi: "); gets(str);
	fflush(stdin);
	printf("Chuoi vua nhap la: %s\n",str);
	char *ptr = str;
	printf("Nhap ky tu can thay the: ");scanf("%c",&a);
	fflush(stdin);
	printf("Nhap ky tu thay the: ");scanf("%c",&b);
	ThayThe(ptr,a,b);
	printf("Chuoi da thay the: %s ",*ptr);
}
void ThayThe(char *str,char a,char b){
	if(str == NULL) return ;
	while(*str != '\0'){
		if(*str == a){
			*str =b;
		}
		str;
	}
}
