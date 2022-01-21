#include<stdio.h>
#include<String.h>

enum { 
	MAX =20
};
typedef struct phone{
	char name[31];
	char phone_numbers[11];
	char email[51];
} phone_t;
int main(){
	FILE *fptr;
	phone_t list[MAX];
	int n;
	printf("So luong (n<100): "); scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		printf("Nhap ten: ");scanf("%s",&list[i].name);
		fflush(stdin);
		printf("Nhap sdt: ");scanf("%s",&list[i].phone_numbers);
		fflush(stdin);
		printf("Nhap email: ");scanf("%s",&list[i].email);
		fflush(stdin);
	}
	if ((fptr = fopen("D:\\Test\\phonebook.txt","wb")) == NULL){
		printf("Khong the mo file %s.\n", "phonebook.txt");
		return -1;
	} else {
			int num = fwrite(list,sizeof(phone_t),n,fptr);
			printf("%d da duoc ghi\n",num);
			close(fptr);
		}
	printf("Doc thong tin:");
	if ((fptr = fopen("D:\\Test\\phonebook.txt","r")) == NULL){
		printf("Khong the mo file %s.\n", "phonebook.txt");
		return -1;
	} else {
			int num = fread(list,sizeof(phone_t),n,fptr);
			printf("%d da duoc ghi\n",num);
			close(fptr);
			for(i=0;i<n;i++){
				printf("Ho ten: %s\n",list[i].name);
				printf("sdt: %s\n",list[i].phone_numbers);
				printf("email: %s\n",list[i].email);
				printf("\n");
			}
		}
	return 0;
	}

