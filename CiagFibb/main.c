#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("ktory element ciagu obliczyc?\n");
    int n;
    scanf("%d",&n);
    int i;
    if(n<=2) printf("%d elementem ciagu Fibonacciego jest 1\n",n);
    else
    {
        int el1=1;
        int el2=1;
        int zmienna;
        for( i=3; i<=n; i++)
        {
            zmienna=el1+el2;
            el1=el2;
            el2=zmienna;

        }
        printf("%d elementem ciagu Fibonacciego jest %d\n",n,el2);
    }
    return 0;
}
