#include <stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX_LEN 100
enum {SUCCESS, FAIL};

void writeChar(FILE *fin, FILE *fout)
{
	int c;
	while ((c=fgetc(fin)) != EOF){
	if (islower(c)){
		c=toupper(c);
	} 
	if (isupper(c)){
		c=tolower(c);
	}
	fputc(c, fout); 
	putchar(c);
	}
}
void writeLine(FILE *fin, FILE *fout){
	char buff[MAX_LEN]; 
	while (fgets(buff, MAX_LEN, fin) != NULL) {
		fputs(buff, fout); 
		printf("%s", buff);
	}
}
void write(FILE *fin, FILE *fout){
	char buff[MAX_LEN]; 
	int len;
	while (fgets(buff, MAX_LEN, fin) != NULL) {
	len = strlen(buff);
	fprintf(fout, "%d %s", len, buff);
	printf("%d %s",len, buff);
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
		//writeChar(fptr1,fptr2); // ghi theo ky tu
		//writeLine(fptr1,fptr2); // ghi theo dong
		write(fptr1,fptr2);
		fclose(fptr1);
		fclose(fptr2);
	}
	return reval;
}
