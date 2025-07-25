#include <stdio.h>
#define PI 3.14;
void main(){
	int r;
	printf("enter the radius of circle");

	scanf("%d",&r);
	int ans=  r *r*PI;
	printf("area= %d",ans);
}