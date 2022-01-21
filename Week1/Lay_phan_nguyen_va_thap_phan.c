#include<stdio.h>
void split(float num, int *phan_nguyen,float *phan_thap_phan){
	*phan_nguyen = (int)num;
	*phan_thap_phan = num - *phan_nguyen;
}
int main(){
	float so_thuc, phan_thap_phan; 
	int phan_nguyen;
	printf("Nhap so thuc: "); scanf("%f", &so_thuc);
	split(so_thuc, &phan_nguyen, &phan_thap_phan);
	printf("Phan nguyen: %d \n", phan_nguyen);
	printf("Phan thap phan: %f \n", phan_thap_phan);
	return 0;
}
