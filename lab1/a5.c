#include <stdio.h>
void main(){
	int y;
	printf("enter year");
	scanf("%d",&y);
	if(y%400==0 ||y%100!=0&&y%4==0){
		
		printf("leap year");
	}
	else{
		printf(" not leap year");
	}
}
