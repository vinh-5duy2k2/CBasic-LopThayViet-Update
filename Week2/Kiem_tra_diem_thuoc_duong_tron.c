#include<stdio.h>
typedef struct point{
	double x;
	double y;
} point_t;

typedef	struct	circle{
	point_t center;
	double radius;
} circle_t;

int is_in_circle(point_t p,circle_t c){
	double denta_x = p.x - c.center.x;
	double denta_y = p.y - c.center.y;
	return (denta_x*denta_x + denta_y*denta_y) <= c.radius*c.radius;
}

int main(){
	point_t p;
	circle_t c;
	printf("Nhap diem A: \n");
	scanf("%lf%lf",&p.x,&p.y);
	
	printf("Nhap tam duong tron: \n");
	scanf("%lf%lf",&c.center.x,&c.center.y);
	
	printf("Nhap ban kinh: "); scanf("%lf",&c.radius);
	if(is_in_circle(p,c)){
		printf("Diem A thuoc duong tron!!!");
	} else {
		printf("Diem A nam ngoai duong tron!!");
	}
	
	
}
