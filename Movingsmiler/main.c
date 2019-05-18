#include </opt/gbdk/include/gb/gb.h>
#include <stdio.h>
#include "smiley.c"

void main(){

    UINT8 currentSpriteIndex = 0;

    set_sprite_data(0,5,Smiler);
    set_sprite_tile(0,1);
    //set_sprite_tile(0,1);
    move_sprite(0,88,78); // set initial position

    SHOW_SPRITES;



    while(1){
    
    
    switch(joypad()){

        case J_LEFT:
            scroll_sprite(0,-1,0);
            break;
        case J_RIGHT:
            scroll_sprite(0,1,0);
            break;
        case J_UP:
            scroll_sprite(0,0,-1);
            break;
        case J_DOWN:
            scroll_sprite(0,0,1);
            break;
        case J_A:
            currentSpriteIndex = (currentSpriteIndex + 1 )%5;
            //printf("%d ",currentSpriteIndex);
            set_sprite_tile(0,currentSpriteIndex);
            delay(100);
    }


    delay(50);

    }

    
}
