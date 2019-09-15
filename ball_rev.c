#include "config.h"
#include "animate.h"
uchar ball_rev(float gradient, uchar yIntercept)
{
    uchar row, col, erase;
    float x = 0;
    for (col = 81; col >=2; col--)
{
    erase = 0;  
     x = col;
     row = (-gradient * x) + yIntercept;
    animate(col,row, erase);
    __delay_ms(30);
    
     if(col>2)
      erase = 1;
    animate(col,row, erase); 
} 
    return row;
}
