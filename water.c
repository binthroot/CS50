#include <stdio.h>
#include <cs50.h>

int water(int n);

int main(void){
    
    printf("minutes: ");
    int minutes = get_int();
    
    int showerInBottles = water(minutes);
    printf("bottles: %d\n", showerInBottles);
}

int water(int n){
    
    int bottlesPerMinute = 12;
    
    return n * bottlesPerMinute;
    
}