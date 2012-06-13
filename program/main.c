#include <stdio.h>
#include <mean.h>

int main() 
{
    int x;
    printf( "Declare x first\n" );

    double d = mean(3,8);
    printf( "Mean: %f \n", d );

    return 0;
}
