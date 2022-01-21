#include<stdio.h>
#include<String.h>
#define max 100
int main(){
	char str1[max+1];
	int str2[26] = {0}; 
	printf("Nhap chuoi: "); gets(str1);
	printf("Chuoi vua nhap la: %s\n",str1);
	int i; 
	for(i=0;i<strlen(str1);i++){
		if(str1[i]>= 'a' && str1[i] <= 'z'){
			str2[str1[i]-'a']++; 
		}
	}
	int j; 
	for(j=0;j<26;j++){
		if(str2[j]==0) continue; 
		printf("chu cai %c xuat hien %d lan \n",j+97,str2[j]); 
	} 
	}
