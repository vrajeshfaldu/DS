// Print Pascal triangle.
#include <stdio.h>

void main()
{ // nCr=n!/(r!*(n-r)!)
    int n, j = 0, i = 0;
    printf("Enter Number : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        for (int space = i; space < n; space++){
            printf(" ");
        }
        int coef = 1;
        for (j = 0; j <= i; j++){
            printf("% d", coef);
            coef = coef * (i - j) / (j + 1);
        }
        printf("\n");
    }
}
