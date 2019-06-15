#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdio.h>

#include "LooneyTunes.h"


const UWORD spritepalette[]={
    LooneyTunesCGBPal0c0,
 LooneyTunesCGBPal0c1,
 LooneyTunesCGBPal0c2,
LooneyTunesCGBPal0c3,

 LooneyTunesCGBPal1c0,
 LooneyTunesCGBPal1c1,
 LooneyTunesCGBPal1c2,
 LooneyTunesCGBPal1c3
};

const UWORD backgroundpalette[]={
    RGB_LIGHTGRAY,RGB_DARKGRAY,RGB_DARKGRAY,RGB_DARKGRAY
};

void pause(UINT8 numloops){
    UINT8 i;
    for (i=0; i <numloops;i++){
        wait_vbl_done();
    }
}


void main(){

SPRITES_8x16;

set_bkg_palette(0,1,&backgroundpalette[0]);

set_sprite_data(0,4,LooneyTunes);

set_sprite_palette(0,2,&spritepalette[0]);

set_sprite_prop(0,0);
set_sprite_prop(1,1);

set_sprite_tile(0,0);
move_sprite(0,20,78);

set_sprite_tile(1,2);
move_sprite(1,80,78);

SHOW_BKG;
SHOW_SPRITES;

    /*while(1){

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
    }*/

    

}