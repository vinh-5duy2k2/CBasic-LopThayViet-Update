#include<stdio.h>
#include<string.h>
#include<stdlib.h>
enum {
	NAME_LENGT = 31, 
	EMAIL_LENGT = 51, 
	PHONE_NUMBER = 11, 
};
typedef struct {
	char name[NAME_LENGT];
	char email[EMAIL_LENGT];
	char phoneNumber[PHONE_NUMBER];
} ElementType;

typedef struct node{
	ElementType inf;
	struct node *next;
} node;

// create a new node
node *create(){
	node *newEle = (node*)malloc(sizeof(node));
	if(newEle==NULL){
		printf("Error!!!");
		exit(0);
	}
	newEle->next=NULL;
	return newEle;
}

//insert new node after current
void addNode(node *root,node *newEle){
	if(root == NULL){
		root = newEle;
	} 

	node *cur = create();
	cur = root;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = newEle;
}


// read file
node *readFile(FILE *fin){
    node *newnode = create();
    fscanf(fin,"%s\n%s\n%s\n",newnode->inf.name , newnode->inf.phoneNumber, newnode->inf.email);
    return newnode;
}

// show queue
void show(node *root)
{
    if (root==NULL) {
        printf("Empty!\n");
        return;
    } else {
        node *tg = create();
        tg = root->next;
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
void writeFile(FILE *fout, node *root){
    node *tg = create();
    tg = root->next;
    while (tg->next != NULL){
        ElementType temp = tg->inf;
        fprintf(fout,"%s\n%s\n%s\n",temp.name,temp.phoneNumber,temp.email);
        tg = tg->next;
    }
}

void freeAllNode(node *root){
	node *freeNode = root ;
	while (freeNode != NULL) {
		root = root->next;
		free(freeNode);
		freeNode = root;
	}
}

int main(){
	node *root = create();
	FILE *fptr1, *fptr2;
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
        while(!feof(fptr1)){
            node *newnode = readFile(fptr1);
            addNode(root, newnode);
        }
        printf("\n-----------Show Telephone List----------------\n");
        show(root);
        printf("\n-----------------$$$$$$$$$$-------------------\n");
        writeFile(fptr2, root);
    }

    freeAllNode(root);
    fclose(fptr1);
    fclose(fptr2);
	return 0;
} 
