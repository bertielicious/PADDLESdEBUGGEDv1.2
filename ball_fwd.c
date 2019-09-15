#include "config.h"
#include "animate.h"
#include <stdio.h>
uchar ball_fwd(float gradient, uchar yIntercept)
{
    static uchar row, col, erase;
    float x = 0;
    for (col = 3; col < 82; col++)
    {
     erase = 0;  
     x = col;
     row = (gradient * x) + yIntercept;       //  
    
     
     animate(col,row, erase); //draw the ball , erase = 0, offsetDwn = 5, offsetUp = 0;
     __delay_ms(30);
     if(col<80)
     erase = 1;
     animate(col,row, erase);  // erase the ball*/
     printf("row = %d\n", row);
    }
    //return row;
}
