#include <stdio.h>
enum {SUCCESS, FAIL};
void writechar(FILE *fptr1,FILE *fptr2){
	int c;
	if((c=fgetc(fptr1))!=EOF){
		fputc(c,fptr2);
		putchar(c);
	}
}
int main(){
	FILE *fptr1,*fptr2;
	char filename1[] = "D:\\Test\\Lab1.txt";
	char filename2[] = "D:\\Test\\Lab1w.txt";
	int reval=SUCCESS;
	if((fptr1 = fopen(filename1,"r"))==NULL){
		printf("Error!!! Khong the doc duoc file %s",filename1);
		reval = FAIL;
	} else if((fptr2 = fopen(filename2,"w")) == NULL){
		printf("Error!!! Khong the ghi duoc file %s",filename2);
		reval = FAIL;
	} else {
		writechar(fptr1,fptr2);
		fclose(fptr1);
		fclose(fptr2);
	}
	return reval;
}
