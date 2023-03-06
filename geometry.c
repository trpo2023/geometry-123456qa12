#include <stdio.h>
#include <math.h>
#include <string.h>
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
		printf("	%d.circle\n", n+1);
	}
}
int main(){
	int circlenumber=0;
	char input[50];
	float x, y, rad;
	float centerx[100];
	float centery[100];
	float radius[100];
	int start=1;
	while(1) {
		if (start==1){
			printf("Введите stop, чтобы закончить ввод\n");
			start=0;
		}
		if(fgets(input, sizeof(input), stdin) == NULL) {
			break;
		}
		if(strncmp(input, "stop", 4) == 0) {
			break;
		}
		if(sscanf(input, "circle(%f %f, %f)", &x, &y, &rad) != 3) {
			printf("Ошибка ввода.\n");
		} else {
			centerx[circlenumber]=x;
			centery[circlenumber]=y;
			radius[circlenumber]=rad;
			circlenumber+=1;
		}
	}
	float cx[circlenumber];
	float cy[circlenumber];
	float crad[circlenumber];
	for (int c=0; c!=circlenumber; c++){
		cx[c]=centerx[c];
		cy[c]=centery[c];
		crad[c]=radius[c];
	}
	for (int i=0; i!=circlenumber; i++){
		printf("%d.circle(%f, %f %f)\n", i+1, cx[i], cy[i], crad[i]);
		circleperimeter(crad[i]);
		circlearea(crad[i]);
		printf("intersects:\n");
		for (int j=0; j<circlenumber; j++){
			if (i != j) {
				intersects(cx[i], cy[i], crad[i], cx[j], cy[j], crad[j], j);
			}
		}
	}
	return 0;
}

