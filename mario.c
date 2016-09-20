#include <stdio.h>
#include <cs50.h>

void mario(int n, int m);
void reverseMario(int n, int m);

int main(void)
{
    
    int height;
    
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while(height < 0 || height > 23);
    
    for (int i = 0; i < height; i++)
    {
        mario(height-1-i, i+1);
        printf("  ");
        reverseMario(i+1, height-1-i);
        printf("\n");
    }
   
    
    return 0;
}

void mario(int n, int m)
{
    while(n > 0)
    {
        printf(" ");
        n--;
    }
    
    while(m > 0)
    {
        printf("#");
        m--;
    }
    
}

void reverseMario(int n, int m)
{
    while(n > 0)
    {
        printf("#");
        n--;
    }
    
    m=0;
    // while(m > 0)
    // {
    //     printf(" ");
    //     m--;
    // }
    
}