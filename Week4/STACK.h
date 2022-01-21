#ifndef STACK
#define STACK
#include<stdlib.h>
#include<string.h>
#define NAME_LENGT 31, GMAIL_LENGT 51,PHONE_NUMBER 10, MAX 30
typedef struct listPhone{
	char name[NAME_LENGT];
	char gmail[GMAIL_LENGT];
	
	char phoneNumber[PHONE_NUMBER];
	struct listPhone *top;
} phone;
bool isEmpty(phone *stack);
bool isFull(phone *stack){
	int dem = 0;
	phone *cur = stack;
	while(cur != NULL){
		dem++;
		cur = cur->top;
	}
	return dem == MAX;
}
phone *push(phone *stack,phone *newElement){
	if(isFull(stack,MAX) == true) {
		printf("Push fail !!! List is full\n");
		return stack;
	}
	if(isEmpty(stack) == true) {
		stack = newElement;
	} else {
		newElement->top=stack;
		stack = newElement;
	}
	printf("Push succes!!\n");
	return stack;
}
phone *pop(phone *stack){
	if(isEmpty(stack) == true) {
		printf("Pop fail!!! List is empty\n");
	} else {
		phone *cur = stack;
		stack = stack->top;
		free(cur);
		printf("Pop success!!!!\n");
	}
	return stack;
}
#endi
