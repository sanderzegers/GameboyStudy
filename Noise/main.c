#include <gb/gb.h>
#include <stdio.h>

void main(){

    UINT8 currentSpriteIndex = 0;


    //register must be set in this specific order
   
   NR52_REG = 0x80; // turns on sound
   NR50_REG = 0x77; // set volume for left and right channel to max 0x77
   NR51_REG = 0xFF; // select which channels. 


    while(1){
    
    
    switch(joypad()){

        case J_LEFT:
            scroll_sprite(0,-1,0);
            break;
        case J_RIGHT:
            scroll_sprite(0,1,0);
            break;
        case J_UP:
            printf("up pressed\n");
            NR10_REG = 0x16;
            NR11_REG = 0x40;
            NR12_REG = 0x73;
            NR13_REG = 0x00;
            NR14_REG = 0xC3;
            break;
        case J_DOWN:
            printf("down pressed\n");
            NR41_REG = 0x1F; //sound lenght = MAX
            NR42_REG = 0XF1; // volume envelope
            NR43_REG = 0x30;  // frequency of noise
            NR44_REG = 0xC0;
            

            break;
    }


    delay(1000);

    }

    
}
