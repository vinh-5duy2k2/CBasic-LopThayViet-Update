#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum{
	NAME_LENGT = 31, 
	GMAIL_LENGT = 51, 
	PHONE_NUMBER = 10, 
	MAX = 50
}; 
typedef struct listPhone{
	char name[NAME_LENGT];
	char gmail[GMAIL_LENGT];
	
	char phoneNumber[PHONE_NUMBER];
	struct listPhone *top;
} phone;
int isEmpty(phone *stack){
	return stack == NULL;
}
int isFull(phone *stack){
	int dem = 0;
	phone *cur = stack;
	while(cur != NULL){
		dem++;
		cur = cur->top;
	}
	return dem == MAX;
}
phone *declare(){
	phone *newElement = (phone*)malloc(sizeof(phone));
	if(newElement==NULL){
		printf("ERROR!!!!!");
		exit(0);
	}
	return newElement;
}
phone *create(){
	phone *newElement = declare();
	printf("Insert name: "); gets(newElement->name);
	fflush(stdin);
	printf("Insert email: "); gets(newElement->gmail);
	fflush(stdin);
	printf("Insert phone: "); gets(newElement->phoneNumber);
	fflush(stdin);
	newElement->top = NULL;
	return newElement;
}
phone *push(phone *stack,phone *newElement){
	if(isFull(stack) == 1) {
		printf("Push fail !!! Stack overflow\n");
		return stack;
	}
	if(isEmpty(stack) == 1) {
		stack = newElement;
	} else {
		newElement->top=stack;
		stack = newElement;
	}
	printf("Push succes!!\n");
	return stack;
}

phone *pop(phone *stack){
	if(isEmpty(stack) == 1) {
		printf("Pop fail!!! Stack underflow\n");
	} else {
		phone *cur = stack;
		stack = stack->top;
		free(cur);
		printf("Pop success!!!!\n");
	}
	return stack;
}
phone* readFile(FILE *f_read){
	phone *newElement = declare();
	fscanf(f_read,"%s\n%s\n%s\n",newElement->name,newElement->phoneNumber,newElement->gmail);
//	fscanf(f_read,"%s",&newElement->phoneNumber);
//	fscanf(f_read,"%s",&newElement->gmail);
//	fgets(newElement->name,NAME_LENGT,f_read);
//	fgets(newElement->phoneNumber,PHONE_NUMBER,f_read);
//	fgets(newElement->gmail,GMAIL_LENGT,f_read);
	newElement->top = NULL;
	return newElement;
}
void showListPhone(phone *stack){
	if(isEmpty(stack)==1){
		printf("Stack underflow\n");
		return;
	} else {
		phone *cur = stack;
		while(cur!=NULL){
			printf("Name: %s\n",cur->name);
			printf("Email: %s\n",cur->gmail);
			printf("Phone: %s\n",cur->phoneNumber);
			printf("\t\t----------\n");
			cur = cur->top;
		}
	}
}
phone* writeFile(phone *stack,FILE *fwrite){
	while(stack!=NULL){
		fprintf(fwrite,"%s\n%s\n%s\n",stack->name,stack->phoneNumber,stack->gmail);
//		fprintf(fwrite,"%s\n",root->phoneNumber);
//		fprintf(fwrite,"%s\n",root->gmail);
//		fputs(root->name,fwrite);
//		fputs(root->phoneNumber,fwrite);
//		fputs(root->gmail,fwrite);
		stack = pop(stack);
	}
	return stack;
}
int main(){
	FILE *f_read,*f_write;
	phone *stack = NULL;
	char fRead[] = "D:\\CProgramingBasic\\CBasic_NguDuyVinh_20205049_126898\\Week4\\File_nguon.txt";
	char fWhile[] = "D:\\CProgramingBasic\\CBasic_NguDuyVinh_20205049_126898\\Week4\\Copy_file.txt";
	if((f_read = fopen(fRead,"r"))==NULL){
		printf("Error!!! Khong the doc duoc file %s",fRead);
		return 0;
	} else if((f_write = fopen(fWhile,"w"))==NULL){
		printf("Error!!! Khong the ghi duoc file %s",fWhile);
		return 0;
	} else {
		while(!feof(f_read)){
			phone *newEle = readFile(f_read);
			stack = push(stack,newEle);
		}
		printf("\n-----------------------Show List Phone-------------------------\n");
		showListPhone(stack);
		printf("\n-----------------------$$$$$$$$$$$-------------------------\n");
		stack = writeFile(stack,f_write);
		if(stack == NULL){
			printf("COPY SUCCESS\n");
		}
	}
	
	fclose(f_read);
	fclose(f_write);
	return 0;
}

