#include <stdio.h>
#include <stdlib.h>
#include<string.h>
enum {
	SUCCESS, FAIL, MAX_ELEMENT = 20
};// the phone book structure
typedef struct phoneaddress {
	char name[20];
	char tel[11];
	char email[25];
} phoneaddress;
int main(void){
	FILE *fptr;
	phoneaddress *phonearr;
	int i,n, irc,reval; // return codeint 
	reval = SUCCESS;
	printf("Read from 2sd data to 3rd data \n");
	if ( (fptr = fopen("phonebook.dat","r+b")) == NULL){
		printf("Can not open %s.\n", "phonebook.dat");
		reval = FAIL;
	}// Memory allocation
	phonearr = (phoneaddress *)malloc(2 * sizeof(phoneaddress));
	if (phonearr == NULL){
		printf("Memory allocation failed!\n");
		return FAIL;
	}
	if (fseek(fptr,1*sizeof(phoneaddress),SEEK_SET) != 0){
		printf("Fseek failed!\n");
		return FAIL;
	}
	irc = fread(phonearr, sizeof(phoneaddress), 2, fptr);
	for (i=0; i<2; i++){
		printf("%s-",phonearr[i].name);
		printf("%s-",phonearr[i].tel);
		printf("%s\n",phonearr[i].email);
	}
	strcpy(phonearr[1].name,"Lan Hoa");
	strcpy(phonearr[1].tel,"0923456");
	strcpy(phonearr[1].email,"lovelybuffalo@hut.edu.vn");
	fseek(fptr,1*sizeof(phoneaddress),SEEK_SET);
	irc = fwrite(phonearr, sizeof(phoneaddress), 2, fptr);
	printf(" fwrite return code = %d\n", irc);
	fclose(fptr); 
	free(phonearr);
	return reval;
}
