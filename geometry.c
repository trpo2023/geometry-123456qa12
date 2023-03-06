#include <stdio.h>
#include <math.h>
void circleperimeter(float p){
	printf("perimeter = %f\n", 2*M_PI*p);
}
void circlearea(float p){
	printf("area = %f\n", M_PI*p*p);
}
void intersects(float xl1, float yl1, float radl1, float xl2, float yl2, float radl2, int n){
	float xlen=fabs(xl1-xl2);
	float ylen=fabs(yl1-yl2);
	float distance=sqrt(xlen*xlen+ylen*ylen);
	if (distance-radl1-radl2<=0){
		printf("%d.circle\n", n+1);
	}
}
int main(){
	int circlenumber;
	float x,y,rad;
	printf("Введите количество кругов ");
	scanf ("%d", &circlenumber);
	float centerx[circlenumber];
	float centery[circlenumber];
	float radius[circlenumber];
	for (int q=0; q<circlenumber; q++){
		printf("Введите координату x центра %d круга ", q+1);
		scanf("%f", &x);
		centerx[q]=x;
		printf("Введите координату y центра %d круга ", q+1);
		scanf("%f", &y);
		centery[q]=y;
		printf("Введите радиус %d круга ", q+1);
		scanf("%f", &rad);
		radius[q]=rad;
	}
	for (int i=0; i<circlenumber; i++){
		printf("%d.circle(%f, %f %f)\n", i+1, centerx[i], centery[i], radius[i]);
		circleperimeter(radius[i]);
		circlearea(radius[i]);
		printf("intersects:\n");
		for (int j=0; j<circlenumber; j++){
			if (i != j) {
				intersects(centerx[i], centery[i], radius[i], centerx[j], centery[j], radius[j], j);
			}
		}
	}
	return 0;
}

