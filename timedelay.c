// C function showing how to do time delay 
#include <stdio.h> 
// To use time library of C 
#include <time.h> 
  
void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

// Driver code to test above function 
int main() 
{ 
    int i; 
    for (i = 0; i < 10; i++) { 
        // delay of one second 
        delay(1000); 
        printf("%d seconds have passed\n", i + 1); 
    } 
    return 0; 
} 
