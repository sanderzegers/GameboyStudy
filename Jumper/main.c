#include <gb/gb.h>
#include <stdio.h>

#include "man.c"


INT8 playerlocation[2];
BYTE jumping;
UINT8 gravity = -2;
INT8 currentJumpSpeedY = 0;
UINT8 floorYposition = 100;

void pause(UINT8 numloops){
    UINT8 i;
    for (i=0; i <numloops;i++){
        wait_vbl_done();
    }
}


UINT8 wouldhitsurface(UINT8 projectedYPosition){

    if (projectedYPosition >= floorYposition){
        return floorYposition;
    } else {
    return -1;}

}


void jump(){
    INT8 possibleSurfaceY;

    if(jumping == 0){
        jumping = 1;
        currentJumpSpeedY = 10;
        }
    


    //printf("%d\n",currentJumpSpeedY);

    if(currentJumpSpeedY <= 2 && currentJumpSpeedY >= -2){
        set_sprite_tile(0,2);
    }

    else if(currentJumpSpeedY >= 0){
        set_sprite_tile(0,1);
    }
    else if(currentJumpSpeedY <= 0){
        set_sprite_tile(0,3);
    }
  


    currentJumpSpeedY = currentJumpSpeedY + gravity;


    playerlocation[1] = playerlocation[1] - currentJumpSpeedY ;

    possibleSurfaceY = wouldhitsurface(playerlocation[1]);

    if (possibleSurfaceY > -1){
        jumping = 0;
        move_sprite(0,playerlocation[0],possibleSurfaceY);
        set_sprite_tile(0,0);
    }

    else{
        move_sprite(0,playerlocation[0],playerlocation[1]);
    }
}


void main(){

    playerlocation[0] = 10;
    playerlocation[1] = 100;

    set_sprite_data(0,4,Man);

    set_sprite_tile(0,0);

    move_sprite(0,playerlocation[0],playerlocation[1]);

    DISPLAY_ON;
    SHOW_SPRITES;


    while(1){

        if (jumping == 1 || (joypad() & J_A)){
            jump();
        }

        if (joypad() & J_LEFT){
            playerlocation[0] = playerlocation[0] - 2 ;
            move_sprite(0,playerlocation[0],playerlocation[1]);
        }

        if (joypad() & J_RIGHT){
            playerlocation[0] = playerlocation[0] + 2 ;
            move_sprite(0,playerlocation[0],playerlocation[1]);
        }

        pause(4);
    }

    

}