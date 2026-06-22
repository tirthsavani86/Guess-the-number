#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int x, y, a, b, i, z=1, choice;
    start:
    printf("\n Enter first number");
    if ( scanf("%d", &x) == 1.00)
    {
        start1:
        printf("\n Enter second number");
        if( scanf("%d", &y) == 1)
        {
            printf("\n Choose your operation:- \n 1 - Addition \n 2 - Subtraction \n 3 - Multiplication \n 4 - Division \n 5 - Power operation \n 6 - Modulus ");
            scanf("%d", &choice);
            switch (choice)
            {
                case 1:
                printf("\n The Addition of %d and %d is %d", x, y, x + y);        
                break;
                case 2:
                printf("\n The Subtraction of %d and %d is %d", x, y, x - y);
                break;
                case 3:
                printf("\n The Product of %d and %d is %d", x, y, x * y);
                break;
                case 4:
                if ( y != 0)
                {
                    printf("\n  %d divided by %d is %.2f", x, y, (float)x / y);
                }
                else 
                {
                    printf("\n Denominator cannot be zero");
                }
                break;
                case 5:
                for ( i=1; i<=y; i++)
                {
                    z = z * x;
                }
                printf("\n %d to the power of %d is %d", x, y, z);
                break;
                case 6:
                printf("\n The remainder when %d is divided by %d is %d", x, y, x % y);
                break;
                default:
                printf("\n Invalid choice");
            }
        }
        else
        {
            printf("\n Invalid input");
            while (getchar() != '\n');
            goto start1;
        }
    }
    else
    {
        printf("\n Invalid input");
        while (getchar() != '\n');
        goto start;
    }
    return 0;
}