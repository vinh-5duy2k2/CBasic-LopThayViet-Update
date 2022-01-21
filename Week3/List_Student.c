#include<stdio.h>
#include<string.h>
#include<stdlib.h>
enum {
	NAME_LENGT = 31, ID_LENGT = 10
};
typedef struct student_t{
	char hoten[NAME_LENGT];
	char id[ID_LENGT];
	float grade;
	struct student_t *next;
} student;

// create a new node
student *createNewStudent(){
	student *newStudent = (student*)malloc(sizeof(student));
	if(newStudent==NULL){
		printf("Error!!!");
		exit(0);
	}
	printf("Nhap ID: ");scanf("%s",&newStudent->id);
	fflush(stdin);
	printf("Nhap ho ten: ");gets(newStudent->hoten);
	fflush(stdin);
	printf("Nhap diem: "); scanf("%f",&newStudent->grade);
	fflush(stdin);
	newStudent->next=NULL;
	return newStudent;
}

//insert new node after current
student *addStudent(student *root,student *newStudent){
	if(root == NULL){
		return newStudent;
	} else if (newStudent->grade >= root->grade){
		newStudent->next = root;
		return newStudent;
	} 
	student *cur,*prev;
	cur = root;
	while(cur != NULL && newStudent->grade < cur->grade){
		prev = cur;
		cur = cur->next;
	}
	prev->next = newStudent;
	newStudent->next = cur;
	return root;
}

// show list student
void showStudent(student *root){
	student	*cur = root;
	while(cur!=NULL){
		printf("ID: %s\n",cur->id);
		printf("Ho ten: %s\n",cur->hoten);
		printf("Grade: %.2f\n",cur->grade);
		cur = cur->next;
	}

}

// delete a student 
student *deleteStudent(student *root,char id[ID_LENGT]){
	student *cur,*prev;
	if (root == NULL) 
	return root;
	cur = root;
	if (strcmp(cur->id,id) == 0){
		root = root->next;
		free(cur);
		return root;
	} else {
		while (cur != NULL && strcmp(cur->id, id) != 0){
			prev = cur;
			cur = cur->next;
		}
		if (cur != NULL){
		prev->next = cur->next;
		free(cur);
		}
	}
	return root;
}
student *find_student(student *root,char id[ID_LENGT]){
	if (root == NULL) 
	return root;
	if (strcmp(root->id,id) == 0){
		return root;
	} else {
		student *cur;
		cur = root;
		while (cur != NULL && strcmp(cur->id, id) != 0){
			cur = cur->next;
		}
		return cur;
	}
	return NULL;
}
student *changeGrade(student *root,char id[ID_LENGT],float gradechange){
	student *temp;
//	tim dia chi cua id
	temp = find_student(root,id);
	if(temp!= NULL){
//		create new student 
		student *newStudent = (student*)malloc(sizeof(student));
		if(newStudent==NULL){
			printf("Error!!!");
			exit(0);
		}
		strcpy(newStudent->hoten,temp->hoten);
		strcpy(newStudent->id,temp->id);
		newStudent->grade = gradechange;
		newStudent->next = NULL;
//		delete old student
		root = deleteStudent(root,id);
//		add new student
		root = addStudent(root,newStudent);	
	}
	return root;
}

// delete list address
void deleteListStudent(student *root){
	student *freeStudent = root ;
	while (freeStudent != NULL) {
		root = root->next;
		free(freeStudent);
		freeStudent = root;
	}
}
int main(){
	student *root = NULL;
	int i;
	student *newStudent;
	for(i=0;i<4;i++){
		newStudent = createNewStudent();
		root = addStudent(root,newStudent);
	}
	printf("======== Show List Student =========\n");
	showStudent(root);
	
	printf("\n======== Delete student by ID =========\n");
	deleteStudent(root,"3");
	showStudent(root);
	
	printf("\n=========== Show pointer by id ============= \n");
	printf("%x \n",find_student(root,"2"));
	
	printf("\n=========== Change grade by id ============= \n");
	changeGrade(root,"2",8.6);
	showStudent(root);
	
	deleteListStudent(root);
	return 0;
} 
