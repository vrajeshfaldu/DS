#include <stdio.h>

int main(){
	int y,w,d,a,b,c;
	scanf("%d",&d);
	printf("enter second");
	y=d/365;
	a=d%365;
	
	w=a/52;
	b=a%52;
	
	d=d%7;
	printf("%d:%d:%d",y,w,d);
	
	return 0;
}
