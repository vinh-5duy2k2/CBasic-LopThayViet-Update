#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum{
	NAME_LENGT = 31, 
	GMAIL_LENGT = 51, 
	PHONE_NUMBER = 10, 
	MAX = 5
}; 
typedef struct inf{
	char name[NAME_LENGT];
	char gmail[GMAIL_LENGT];
	char phoneNumber[PHONE_NUMBER];
} info;
typedef struct listPhone{
	info inf;
	struct listPhone *top;
} phone;
typedef struct {
	phone* front;
	phone* last;
	int count;
}queue;
void makeNullQueue(queue *q){
	q->last=q->front=NULL;
	q->count=0;
}
int isEmpty(queue *q){
	return q->count==0;
}
phone *declare(){
	phone *newElement = (phone*)malloc(sizeof(phone));
	if(newElement==NULL){
		printf("ERROR!!!!!");
		exit(0);
	}
	return newElement;
}

void enqueue(queue *q,phone *newElement){
	if(isEmpty(q)){
		q->front = newElement;
		q->last	= newElement;
	}
	else{
		q->last->top = newElement;
		q->last = newElement;
		printf("Push succes!!\n");
	}
	q->count++;
}
queue* dequeue(queue *q){
	if(isEmpty(q)) {
		printf("Pop fail!!! Stack underflow\n");
	} 
	if(q->count==1){
		free(q->front);
		makeNullQueue(q);
	}else {
		phone *temp = q->front;
		q->front = q->front->top;
		free(temp);
		printf("Pop success!!!!\n");
		q->count--;
	}
	return q;
}
phone *readFile(FILE *f_read){
	phone *newElement = declare();
	fscanf(f_read,"%s\n%s\n%s\n",newElement->inf.name,newElement->inf.phoneNumber,newElement->inf.gmail);
	newElement->top = NULL;
	return newElement;
}
queue * writeFile(queue *q,FILE *fwrite){
	while(q->count!=0){
		fprintf(fwrite,"%s\n%s\n%s\n",q->front->inf.name,q->front->inf.phoneNumber,q->front->inf.gmail);
		q=dequeue(q);
	}
	return q;
}
int main (){
//	FILE *f_read,*f_write;
//	phone *p ;
//	char fRead[] = "D:\\CProgramingBasic\\CBasic_NguDuyVinh_20205049_126898\\Week4\\File_nguon.txt";
//	char fWhile[] = "D:\\CProgramingBasic\\CBasic_NguDuyVinh_20205049_126898\\Week4\\Copy_file.txt";
//	if((f_read = fopen(fRead,"r"))==NULL){
//		printf("Error!!! Khong the doc duoc file %s",fRead);
//		return 0;
//	} else if((f_write = fopen(fWhile,"w"))==NULL){
//		printf("Error!!! Khong the ghi duoc file %s",fWhile);
//		return 0;
//	} else {
//		while(!feof(f_read)){
//			p = readFile(f_read);
//			printf("Name: %s\n",p->inf.name);
//			printf("Email: %s\n",p->inf.gmail);
//			printf("Phone: %s\n",p->inf.phoneNumber);
//			printf("\t\t----------\n");
//		}
//		if(q!=NULL){
//			printf("READ SUCCESS\n");
//		}
//		q=writeFile(q,f_write);
//		if(q==NULL){
//			printf("COPY SUCCESS\n");
//		}
//	}
	queue *q;
	makeNullQueue(q);
	printf("%d\n",q->count);
//	fclose(f_read);
//	fclose(f_write);
	return 0;
}
