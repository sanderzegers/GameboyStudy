#include <gb/gb.h>
#include <stdio.h>
#include "plains.c"
#include "GameCharacter.c"



struct GameCharacter player;
struct GameCharacter enemy;

UBYTE spritesize = 8;


// pointer used for GameCharacter. Otherwise it would use a copy of the GameCharacter
void moveGameCharacter(struct GameCharacter* character, UINT8 x, UINT8 y){
    
    move_sprite(character->spritids[0], x,y);
    move_sprite(character->spritids[1], x+spritesize,y);
    move_sprite(character->spritids[2], x,y+spritesize);
    move_sprite(character->spritids[3], x+spritesize,y+spritesize);
}


void performantdelay(UINT8 numloops){
    UINT8 i;
    for (i=0;i<=numloops;i++){
        wait_vbl_done();
    }
}



void setupPlayer(){
    player.x = 80;
    player.y = 130;
    player.width = 16;
    player.height = 16;

    set_sprite_tile(0,0);
    player.spritids[0] = 0;
    set_sprite_tile(1,1);
    player.spritids[1] = 2;
    set_sprite_tile(2,2);
    player.spritids[2] = 1;
    set_sprite_tile(3,3);
    player.spritids[3] = 3;

    moveGameCharacter(&player,player.x,player.y);
}

void setupEnemy(){
    enemy.x = 80;
    enemy.y = 20;
    enemy.width = 16;
    enemy.height = 16;

    set_sprite_tile(4,4);
    enemy.spritids[0] = 4;
    set_sprite_tile(5,5);
    enemy.spritids[1] = 6;
    set_sprite_tile(6,6);
    enemy.spritids[2] = 5;
    set_sprite_tile(7,7);
    enemy.spritids[3] = 7;

    moveGameCharacter(&enemy,enemy.x,enemy.y);
}




void main(){

    set_sprite_data(0,8,plainsGraphics);

    setupPlayer();
    setupEnemy();

    SHOW_SPRITES;
    DISPLAY_ON;






    while(1){
    
    
    switch(joypad()){

        case J_LEFT:
            player.x -= 1;
            moveGameCharacter(&player, player.x,player.y);
            break;
        case J_RIGHT:
            player.x += 1;
            moveGameCharacter(&player, player.x,player.y);
            break;
        case J_UP:
            //scroll_sprite(0,0,-1);
            break;
        case J_DOWN:
            //scroll_sprite(0,0,1);
            break;
        case J_A:
            break;
            
    }

    enemy.y += 3;
    moveGameCharacter(&enemy,enemy.x,enemy.y);

    performantdelay(1);

    }

    
}
