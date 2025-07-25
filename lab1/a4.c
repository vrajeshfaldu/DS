#include <stdio.h>
void main(){
	int a,b,c;
	printf("enter number :");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	if(a>b&&a>c){
		printf("largest =%d",a);
	}
	else if(b>a&&b>c){
		printf("largest =%d",b);
	}
	else if(c>a&&b<c){
		printf("largest =%d",c);
	}
}
