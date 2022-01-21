#include<stdio.h>
#include<string.h>
#define MAX_LEN 100
enum {SUCCESS, FAIL};
void copyFile(FILE *fptr1,FILE *fptr2){
	char str[MAX_LEN+1];
	int num;
	while(!feof(fptr1)){
		num=fread(str,sizeof(char),MAX_LEN,fptr1);
		str[num*sizeof(char)] = '\0';
		fwrite(str,sizeof(char),num,fptr2);
		printf("%s",str);
	}
}
int main(int argc, char* argv[]){
	if(argc<3){
		printf("Error!!!");
	}
	FILE *fptr1,*fptr2;
	if((fptr1 = fopen(argv[1],"r"))==NULL){
		printf("Error!!! Khong the doc duoc file %s",argv[1]);
		return FAIL;
	} else if((fptr2 = fopen(argv[2],"w")) == NULL){
		printf("Error!!! Khong the ghi duoc file %s",argv[2]);
		return FAIL;
	} else {
		copyFile(fptr1,fptr2);
		close(fptr1);
		close(fptr2);
	}
	return SUCCESS;
}
