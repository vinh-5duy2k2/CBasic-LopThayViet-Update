#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
	double width, height;
	if(argc != 3) {
		printf("Sai");
		return 1;
	} 

	width = atof(argv[1]);
	height = atof(argv[2]);
	printf("Dien tich: %f\n", width * height);
	printf("Chu vi:  %f\n",2 * (width + height));		
	return 0;
}
