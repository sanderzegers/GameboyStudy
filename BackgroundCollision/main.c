#include <gb/gb.h>
#include <stdio.h>
#include "GameCharacter.c"
#include "mazesprite.c" // MazeSprites[]
#include "mazemap.c" // MazeMap[]
#include "playersprite.c" // PlayerSprite[]


//struct GameCharacter player;

UBYTE spritesize = 8;
UINT8 playerlocation[2];




// pointer used for GameCharacter. Otherwise it would use a copy of the GameCharacter


void performantdelay(UINT8 numloops){
    UINT8 i;
    for (i=0;i<=numloops;i++){
        wait_vbl_done();
    }
}




void main(){

 //set_sprite_data(0,8,plainsGraphics);

//    setupPlayer();

set_bkg_data(0,4, MazeSprites);
set_bkg_tiles(0,0,19,17, MazeMap);

set_sprite_data(0,1,PlayerSprite);
set_sprite_tile(0,0);

playerlocation[0] = 16;
playerlocation[1] = 24;

move_sprite(0,playerlocation[0],playerlocation[1]);

    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;



    while(1==1){
    
    
    switch(joypad()){
        case J_LEFT:
            playerlocation[0] -= 8;
            move_sprite(0,playerlocation[0],playerlocation[1]);
            performantdelay(5);
            break;
        case J_RIGHT:
            playerlocation[0] += 8;
            move_sprite(0,playerlocation[0],playerlocation[1]);
            performantdelay(5);
            break;
        case J_UP:
            playerlocation[1] -= 8;
            move_sprite(0,playerlocation[0],playerlocation[1]);
            performantdelay(5);
            break;
        
        case J_DOWN:
            playerlocation[1] += 8;
            move_sprite(0,playerlocation[0],playerlocation[1]);
            performantdelay(5);
            break;
        case J_A:
            break;
            
    }

    

    performantdelay(1);

    }

    
}
