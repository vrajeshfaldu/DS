#include <stdio.h>
void main(){
	int h,m,s,a,b,c;
	scanf("%d",&s);
	printf("enter second");
	h=s/3600;
	a=s%3600;
	
	m=a/60;
	b=a%60;
	
	s=b%60;
	printf("%d:%d:%d",h,m,s);
	
	
}
