#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum{
	NAME_LENGT = 31, 
	EMAIL_LENGT = 51, 
	PHONE_NUMBER = 11, 
	MAX = 10
}; 
typedef struct {
	char name[NAME_LENGT];
	char email[EMAIL_LENGT];
	char phoneNumber[PHONE_NUMBER];
} ElementType;

typedef struct NodeType {
    ElementType inf;
    struct NodeType *next;
} List;
typedef struct {
    List *front, *rear;
} Queue;

List *create(){
    List *newnode = (List *)malloc(sizeof(List));
    if (newnode == NULL){
        printf("Error!\n");
        exit(0);
    }

    newnode->next = NULL;
    return newnode;
}

// make null queue
Queue *MakeNullQueue(){
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    if (Q == NULL){
        printf("Error!\n");
        exit(0);
    }

    List *head = create();
    Q->front = head;
    Q->rear = head;
    return Q;
}

// check queue is empty?
int isEmpty(Queue *Q){
    return (Q->front == Q->rear);
}

void push(Queue *Q, List *topush){
    Q->rear->next = create();
    Q->rear->inf = topush->inf;
    Q->rear = Q->rear->next;
}

// pop 
ElementType pop(Queue *Q){
    if (!isEmpty(Q)){
        ElementType temp = Q->front->inf;
        List *T = Q->front;
        Q->front = Q->front->next;
        free(T);
        return temp;
    }
    else {
        printf("ERROR: Queue is empty!\n");
        exit(0);
    }
}

// read file
List *readFile(FILE *fin){
    List *newnode = create();
    fscanf(fin,"%s\n%s\n%s\n",newnode->inf.name , newnode->inf.phoneNumber, newnode->inf.email);
    return newnode;
}

// show queue
void showQueue(Queue *Q)
{
    if (isEmpty(Q)) {
        printf("Queue is empty!\n");
        return;
    } else {
        List *tg = Q->front;
        while (tg->next != NULL){
            printf("Name: %s\n", tg->inf.name);
            printf("Telephone number: %s\n",tg->inf.phoneNumber);
            printf("Email: %s\n",tg->inf.email);
            printf("---------------------------------\n");
            tg=tg->next;    
        }
    }
}

// write file
void writeFile(FILE *fout, Queue *Q){
    List *tg = Q->front;
    while (!isEmpty(Q)){
        ElementType temp = pop(Q);
        fprintf(fout,"%s\n%s\n%s\n",temp.name,temp.phoneNumber,temp.email);
    }
}

int main (){
    FILE *fptr1, *fptr2;
    int count = 0;
    Queue *newqueue = MakeNullQueue();
    char fRead[] = "D:\\CProgramingBasic\\CBasic_NguDuyVinh_20205049_126898\\Midterm_exam\\File_nguon.txt";
	char fWhile[] = "D:\\CProgramingBasic\\CBasic_NguDuyVinh_20205049_126898\\Midterm_exam\\Copy_file.txt";
    if ((fptr1 = fopen(fRead,"r")) == NULL){
        printf("Khong the mo file %s\n",fRead);
        return 0;
    }
    else if ((fptr2 = fopen(fWhile,"w")) == NULL){
        printf("Khong the mo file %s\n",fWhile);
        return 0;
    }
    else {
    	printf("\n------------------Phan tu bi xoa:------------------- \n");
        while(!feof(fptr1)){
            List *newnode = readFile(fptr1); 
            if(count == 10){
            	ElementType temp = pop(newqueue);
            	printf("%s\n%s\n%s\n",temp.name,temp.phoneNumber,temp.email);
            	--count;
			}
            push(newqueue, newnode);
            ++count;
        }

        printf("\n-----------Show Telephone List----------------\n");
        showQueue(newqueue);
        printf("\n-----------------$$$$$$$$$$-------------------\n");
        writeFile(fptr2, newqueue);
    }

    
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
