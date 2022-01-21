#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum{
	NAME_LENGT = 31, 
	GMAIL_LENGT = 51, 
	PHONE_NUMBER = 10, 
	MAX = 5
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
phone *create(){
	phone *newElement = (phone*)malloc(sizeof(phone));
	if(newElement==NULL){
		printf("ERROR!!!!!");
		exit(0);
	}
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
void freeList(phone *stack){
	phone *freePhone = stack;
	while (freePhone != NULL) {
		stack = stack->top;
		free(freePhone);
		freePhone = stack;
	}
}
int main (){
	phone *stack = NULL;
	phone *newElement;
	int number;
	int choose;
	do{
		printf("=========##### MENU #####===========\n");
		printf("1.Create new Stack\n");
		printf("2.Push\n");
		printf("3.Pop\n");
		printf("4.Show\n");
		printf("5.Exit\n");
		do{
			printf("Choose? (1->5): ======>  "); scanf("%d",&choose);
			fflush(stdin);
			printf("\n");
		} while (choose <0 || choose >5);
		if(choose == 1){
			printf("\t++++++++++++\n");
			do{
				printf("How many numbers (0 < Number < %d) ======>  ",MAX); scanf("%d",&number);
				fflush(stdin);
			} while (number <0 || number > MAX);
			int i;
			for(i=0;i<number;i++){
				newElement = create();
				stack = push(stack,newElement);
			}
			printf("\n");
		}
		if(choose == 2){
			printf("\t++++++++++++\n");
			stack = push(stack,create());
			printf("\n");
		}
		if(choose == 3){
			printf("\t++++++++++++\n");
			stack = pop(stack);
			printf("\n");
		}
		if(choose == 4){
			printf("\t++++++++++++\n");
			showListPhone(stack);
			printf("\n");
		}
		if(choose == 5){
			freeList(stack);
		}
	} while (choose !=5 );
	
	
}


