#include<stdio.h>
#include<string.h>
#define MAX_LEN 100
enum {SUCCESS, FAIL};
void readText(FILE *fptr){
	char str[MAX_LEN];
	int len;
	while (fgets(str, MAX_LEN, fptr) != NULL) {
		len = strlen(str);
		printf("%d %s",len,str);
	}
}
int main(){
	char file_name[] = "D:\\Test\\Lab1.txt";
	FILE *fptr; 
	if((fptr =  fopen(file_name,"r")) == NULL){
		printf("Can't open file %s ",file_name);
		return FAIL;
	} else {
		readText(fptr);
		close(fptr);
	}
	return FAIL;
}
