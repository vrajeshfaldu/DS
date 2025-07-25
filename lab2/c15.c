#include <stdio.h>
#include <math.h>

void main()
{
    int num, n, digit = 0, last, sum = 1;
    printf("Enter number: ");
    scanf("%d", &num);

    n=num;

    while (n!= 0){
        n =n/10;
        digit++;
    }

    n=num;

    while(n!=0){
        last = n % 10;
        sum += pow(last, digit);
        n /= 10;
    }
    printf("Sum: %d\n",sum);
    if (sum==num){
        printf("Armstrong");
    }
    else{
        printf("Not");  
    }
}
