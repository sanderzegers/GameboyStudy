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
    
    currentSpriteIndex = (currentSpriteIndex + 1 )%5;
    printf("%d ",currentSpriteIndex);

    set_sprite_tile(0,currentSpriteIndex);

    scroll_sprite(0,2,0);

    delay(200);

    }

    
}
