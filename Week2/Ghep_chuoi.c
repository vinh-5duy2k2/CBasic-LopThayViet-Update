#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100

 
char *my_strcat(char*str1, char*str2){
	int len1, len2;
	char *result;
	len1 = strlen(str1);
	len2 = strlen(str2);
	result = (char *)malloc((len1 + len2 + 1) *  sizeof(char));
	if(result == NULL) {
		printf("Cap phat bo nho that bai!!1");
		return NULL;
	}
	strcpy(result, str1);  // copy chuoi str1 vao resurt bat dau tu vi tri 0
	strcpy(result + len1, str2); // copy chuoi str2 vao resurt bat dau tu vi tri len1 
	return result;
}

int main (){
	char str1[MAX_LEN + 1], str2[MAX_LEN + 1];
	char *cat_str;
	printf("Nhap chuoi 1: "); scanf("%s", str1);
	printf("Nhap chuoi 2: "); scanf("%s", str2);
	cat_str = my_strcat(str1, str2);
	if (cat_str == NULL ){
		printf("Khong cap phat bo nho!!");
		return 1;
	}
	printf("Ghep chuoi %s va %s la : %s \n", str1, str2, cat_str);
	free(cat_str);
	return 0;
}
	

