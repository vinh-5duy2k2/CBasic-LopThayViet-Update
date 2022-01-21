#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

ElementType list[20];

void show(int i){
	printf("Name: %s\n", list[i].name);
	printf("Telephone number: %s\n", list[i].phoneNumber);
	printf("Email: %s\n", list[i].email);
}

void swap(ElementType *a, ElementType *b){
	ElementType temp = *a;
	*a = *b;
	*b = temp;
}

void sort(ElementType a[], int n){
	int i, j;
	for (i = 0; i < n-1; i++){
		for(j = i+1; j < n; j++){
			if (strcmp(a[i].name , a[j].name) > 0){
				swap(&a[i], &a[j]);
			}
		}
	}
}

void readFile (){
	FILE *f = fopen("D:\\CProgramingBasic\\CBasic_NguDuyVinh_20205049_126898\\Midterm_exam\\Copy_file.txt", "r");
	if (f == NULL){
		printf("Cannot open read file.\n");
		exit(0);
	}
	int i = 0;
	while (!feof(f)){
		fscanf(f,"%s\n%s\n%s\n",&list[i].name, &list[i].phoneNumber, &list[i].email);
		i++;
	}
	sort(list, 10);
	fclose(f);
}

int BinarySearch(ElementType a[], char target[], int x, int y){
	if (x > y) return -1;
	int m = (x + y) / 2;
	if (strcmp(a[m].name , target) < 0) return (a, target, m+1, y);
	else if (strcmp(a[m].name, target) > 0) return BinarySearch(a, target, x, m-1);
	else return m;
	return -1;
}

void writefile(int i){
	FILE *f = fopen("D:\\CProgramingBasic\\CBasic_NguDuyVinh_20205049_126898\\Midterm_exam\\Copy_file.txt","w");
	fprintf(f,"Name: %s\n", list[i].name);
	fprintf(f,"Telephone number: %s\n", list[i].phoneNumber);
	fprintf(f,"Email: %s\n", list[i].email);
	fclose(f);
}

int main (){
	readFile();
	int i;
	char tar[20];
	printf("Which name do you want to search: ");
	scanf("%s", &tar);
	int f;
	if ((f = BinarySearch(list, tar, 0, 9)) == -1){
		printf("Not Found!\n");
	} else {
		printf("Result: \n");
		show(f);
		writefile(f);
	}
	return 0;
}

