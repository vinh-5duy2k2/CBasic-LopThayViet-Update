#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {
    SUCCESS, FAIL,
    NAME_LENGTH = 30,
    EMAIL_LENGTH = 50,
    TEL_LENGTH = 12,
    MAX = 50
};

// info
typedef struct {
    char name[NAME_LENGTH+1];
    char tel[TEL_LENGTH+1];
    char email[EMAIL_LENGTH+1];
} ElementType;

// node
typedef struct NodeType {
    ElementType inf;
    struct NodeType *next;
} List;

// front vs rear
typedef struct {
    List *front, *rear;
} Queue;

// create new node
List *create(){
    List *newnode = (List *)malloc(sizeof(List));
    if (newnode == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }

    newnode->next = NULL;
    return newnode;
}

// make null queue
Queue *MakeNullQueue(){
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    if (Q == NULL){
        printf("Memory Allocation Error!\n");
        exit(0);
    }

    List *head = create();
    Q->front = head;
    Q->rear = head;
    return Q;
}

// kiem tra queue empty
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
    fscanf(fin,"%s\n%s\n%s\n",newnode->inf.name , newnode->inf.tel, newnode->inf.email);
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
            printf("Telephone number: %s\n",tg->inf.tel);
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
        fprintf(fout,"%s\n%s\n%s\n",temp.name,temp.tel,temp.email);
    }
}

int main (){
    FILE *fptr1, *fptr2;
    Queue *newqueue = MakeNullQueue();
    char fRead[] = "D:\\CProgramingBasic\\CBasic_NguDuyVinh_20205049_126898\\Week4\\File_nguon.txt";
	char fWhile[] = "D:\\CProgramingBasic\\CBasic_NguDuyVinh_20205049_126898\\Week4\\Copy_file.txt";
    if ((fptr1 = fopen(fRead,"r")) == NULL){
        printf("Cannot open %s\n",fRead);
        return 0;
    }
    else if ((fptr2 = fopen(fWhile,"w")) == NULL){
        printf("Cannot open %s\n",fWhile);
        return 0;
    }
    else {
        while(!feof(fptr1)){
            List *newnode = readFile(fptr1);
            push(newqueue, newnode);
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
