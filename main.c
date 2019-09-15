/*                  16f1459
 *                  ---------
 *   +5 Volts    1 |Vdd      | 20 0 Volts
 *Player select  2 |RA5      | 19
 * Paddle up  L  3 |RA4      | 18
 *    MCLR/ RST  4 |         | 17
 *    GREEN LED  5 |RC5      | 16
 *           CE  6 |RC4      | 15
 *RST op to 5110 7 |         | 14  RC2 Paddle down L
 *           SS  8 |         | 13 
 *           SDO 9 |         | 12
 *           TX 10 |         | 11  SCK
 *                  ---------
 
 */



#include "config.h"
#include <stdio.h>
#include "main.h"
#include "config_osc.h"
#include "setup_ports.h"
#include "init_spi.h"
#include "set_usart.h"
#include "putch.h"
#include "lcd_setup.h"
#include "TMR0_setup.h"
#include "TMR1_setup.h"
#include "interrupt isr.h"
#include "lcdWrite.h"
#include "set_address.h"
#include "set_game_area.h"
#include "eraseBall.h"
#include "animate.h"
#include "posnBall.h"
#include "paddleMove.h"
#include "ball_fwd.h"
#include "ball_rev.h"

void main(void) 
{
config_osc();       // internal clock frequency = 8MHz
setup_ports();      
init_spi();
set_usart();
lcd_setup();        // configures the LCD
set_game_area();
TMR1_setup();
//TMR0_setup();
 uchar  col,row, erase = 0;
 uchar c, r;
erase = 0;
float x = 0.00;

        set_address(0, page);   // column = 0, page = 3
        //lcdWrite (paddle[0]| gameplay_area[0][page],HIGH);
        lcdWrite (paddle[0], HIGH);
        set_address(1, page);   // column = 1, page = 3
        lcdWrite (paddle[1],HIGH);
        position[page-1][0] = 0;       // page above paddle is empty
        position[page][0] = paddle[0]; // paddle is on page 3 all 8 bits are set - write paddle position into
        
        printf("Hello World!\n"); 
    
        yBall = ball_fwd(0.2, 8);    // delta 14 = 8 to 22
        
        ball_rev(0.2, 38);     

        c = 0;
        for(r = 0; r<6;r++)
        {
          //  printf(" Paddle position[%d][%d] = %x\t            Ball position[%d][%d] = %x\n" ,r, c, position[r][c],r, c, position[r][c+1]);    // paddle
            if(position[r][c]<=0x0f)
            {
                position[r][c] = 0;
            }
            if(position[r][c] && position[r][c+1] !=0)
            {
                ball_fwd(0.2, 38); //delta 0
            }

        }
        ball_rev(0.2, 47);  // delta 14 from 22 to 36
        
while(1)
    {
   
    }
}
