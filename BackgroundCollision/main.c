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


void animatesprite(UINT8 spriteIndex, INT8 movex, INT8 movey){
   
    move_sprite(0,playerlocation[0],playerlocation[1]);

    while(movex>0){
        playerlocation[0]+=1;
        movex-=1;
        move_sprite(0,playerlocation[0],playerlocation[1]);
        performantdelay(1);
    }

    while(movex<0){
        playerlocation[0]-=1;
        movex+=1;
        move_sprite(0,playerlocation[0],playerlocation[1]);
        performantdelay(1);
    }

    while(movey>0){
        playerlocation[1]+=1;
        movey-=1;
        move_sprite(0,playerlocation[0],playerlocation[1]);
        performantdelay(1);
    }

    while(movey<0){
        playerlocation[1]-=1;
        movey+=1;
        move_sprite(0,playerlocation[0],playerlocation[1]);
        performantdelay(1);
    }
}

UBYTE canplayermove(UINT8 newplayerx, UINT8 newplayery){
    UINT16 indexTLx, indexTLy, tileindexTL;

    indexTLx = (newplayerx-8) / 8;
    indexTLy = (newplayery-16) / 8;
    tileindexTL = 20 * indexTLy + indexTLx;

    //printf("indexTLx %d, indexTLy %d\n",indexTLx,indexTLy);

    //printf("%d",MazeMap[indexTLx*indexTLy]);

    if (MazeMap[tileindexTL] == 0){
        return 1;
    }
        return 0;
}


void main(){

//set_sprite_data(0,8,plainsGraphics);

//    setupPlayer();

set_bkg_data(0,4, MazeSprites);
set_bkg_tiles(0,0,20,18, MazeMap);

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
            if(canplayermove(playerlocation[0]-8,playerlocation[1])){
                //playerlocation[0] -= 8;
                //move_sprite(0,playerlocation[0],playerlocation[1]);
                
                animatesprite(0,-8,0);
            }
            //performantdelay(2);
            break;
        case J_RIGHT:
            if(canplayermove(playerlocation[0]+8,playerlocation[1])){
                //playerlocation[0] += 8;
                //move_sprite(0,playerlocation[0],playerlocation[1]);
                animatesprite(0,8,0);
                }
            //performantdelay(2);
            break;
        case J_UP:
            if(canplayermove(playerlocation[0],playerlocation[1]-8)){
                //playerlocation[1] -= 8;
                //move_sprite(0,playerlocation[0],playerlocation[1]);
                animatesprite(0,0,-8);
                }
            //performantdelay(2);
            break;
        
        case J_DOWN:
            if (canplayermove(playerlocation[0],playerlocation[1]+8)){
                //playerlocation[1] += 8;
                //move_sprite(0,playerlocation[0],playerlocation[1]);
                animatesprite(0,0,8);}
            //performantdelay(2);
            break;
        case J_A:
            break;
            
    }

    

    performantdelay(1);

    }

    
}
