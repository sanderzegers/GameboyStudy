#include <gb/gb.h>
#include <stdio.h>
#include "plains.c"
#include "GameCharacter.c"


struct GameCharacter player;
struct GameCharacter enemy;

UBYTE spritesize = 8;



UBYTE checkCollisions(struct GameCharacter* character1, struct GameCharacter* character2){

    if( character1->x < character2->x + character2->width-4 && character1->x + character1->width-4 > character2->x)
    { 
	    if( character1->y < character2->y+character2->height-4 && character1->y + character1->height-4 > character2->y){
            return FALSE;
        }
    }
    return TRUE;
	
        
}

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

    set_sprite_prop(4, S_FLIPY); 
    set_sprite_prop(5, S_FLIPY); 
    set_sprite_prop(6, S_FLIPY); 
    set_sprite_prop(7, S_FLIPY); 

    set_sprite_tile(4,4);
    enemy.spritids[0] = 5;
    set_sprite_tile(5,5);
    enemy.spritids[1] = 7;
    set_sprite_tile(6,6);
    enemy.spritids[2] = 4;
    set_sprite_tile(7,7);
    enemy.spritids[3] = 6;

    moveGameCharacter(&enemy,enemy.x,enemy.y);
}




void main(){

    set_sprite_data(0,8,plainsGraphics);

    setupPlayer();
    setupEnemy();

    SHOW_SPRITES;
    DISPLAY_ON;






    while(checkCollisions(&player,&enemy)){
    
    
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

    //printf("%d\n",enemy.y);


    if(enemy.y>=-80 && enemy.y<=-70){
        enemy.y=0;
        enemy.x=player.x;
    }

    

    performantdelay(1);

    }

    
}
