#include <gb/gb.h>
#include <stdio.h>
#include "GameCharacter.c"
#include "mazesprite.c"   // MazeSprites[]
#include "mazemap.c"      // MazeMap[]
#include "playersprite.c" // PlayerSprite[]

//struct GameCharacter player;

UBYTE spritesize = 8;
UINT8 playerlocation[2];

UBYTE haskey = 0;
UINT8 i;

// pointer used for GameCharacter. Otherwise it would use a copy of the GameCharacter

void performantdelay(UINT8 numloops)
{
    for (i = 0; i <= numloops; i++)
    {
        wait_vbl_done();
    }
}

void animatesprite(UINT8 spriteIndex, INT8 movex, INT8 movey)
{

    //move_sprite(0,playerlocation[0],playerlocation[1]);

    //move_sprite vs scroll_sprite??

    while (movex > 0)
    {
        set_sprite_tile(0, 1);
        set_sprite_prop(0,0);

        playerlocation[0] += 1;
        movex -= 1;
        move_sprite(0, playerlocation[0], playerlocation[1]);
        wait_vbl_done();
    }

    while (movex < 0)
    {
        set_sprite_tile(0, 1);
        set_sprite_prop(0,S_FLIPX);

        playerlocation[0] -= 1;
        movex += 1;
        move_sprite(0, playerlocation[0], playerlocation[1]);
        wait_vbl_done();
    }

    while (movey > 0)
    {
        set_sprite_tile(0, 0);
        set_sprite_prop(0,S_FLIPY);
        playerlocation[1] += 1;
        movey -= 1;
        move_sprite(0, playerlocation[0], playerlocation[1]);
        wait_vbl_done();
    }

    while (movey < 0)
    {
        set_sprite_tile(0, 0);
        set_sprite_prop(0,0);
        playerlocation[1] -= 1;
        movey += 1;
        move_sprite(0, playerlocation[0], playerlocation[1]);
        wait_vbl_done();
    }
}

UBYTE canplayermove(UINT8 newplayerx, UINT8 newplayery)
{
    UINT16 indexTLx, indexTLy, tileindexTL;

    indexTLx = (newplayerx - 8) / 8;
    indexTLy = (newplayery - 16) / 8;
    tileindexTL = 20 * indexTLy + indexTLx;

    if (MazeMap[tileindexTL] == 0)
    {
        if (indexTLy >= MazeMapHeight - 1 | indexTLy <= 0)
        {
            HIDE_SPRITES;
            printf("\n \n \n \n \n \n \n \n \n      You WIN!");
        }

        if (indexTLx >= MazeMapWidth - 1 | indexTLx <= 0)
        {
            HIDE_SPRITES;
            printf("\n \n \n \n \n \n \n \n \n      You WIN!");
        }
        return 1;
    }
    if (MazeMap[tileindexTL] == 2)
    {
        //Key
        haskey = 1;
        set_bkg_tiles(indexTLx, indexTLy, 1, 1, 0);
        return 1;
    }
    if (MazeMap[tileindexTL] == 3)
    {
        //Door
        if (haskey)
        {
            set_bkg_tiles(indexTLx, indexTLy, 1, 1, 0);
            return 1;
        }
        else
            return 0;
    }

    return 0;
}

void main()
{

    //set_sprite_data(0,8,plainsGraphics);

    //    setupPlayer();

    set_bkg_data(0, 4, MazeSprites);
    set_bkg_tiles(0, 0, 20, 18, MazeMap);

    set_sprite_data(0, 2, PlayerSprite);
    set_sprite_tile(0, 0);

    playerlocation[0] = 16;
    playerlocation[1] = 24;

    move_sprite(0, playerlocation[0], playerlocation[1]);

    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;

    while (1 == 1)
    {

        switch (joypad())
        {
        case J_LEFT:
            if (canplayermove(playerlocation[0] - 8, playerlocation[1]))
            {
                animatesprite(0, -8, 0);
            }
            break;
        case J_RIGHT:
            if (canplayermove(playerlocation[0] + 8, playerlocation[1]))
            {
                animatesprite(0, 8, 0);
            }
            break;
        case J_UP:
            if (canplayermove(playerlocation[0], playerlocation[1] - 8))
            {
                animatesprite(0, 0, -8);
            }
            break;

        case J_DOWN:
            if (canplayermove(playerlocation[0], playerlocation[1] + 8))
            {
                animatesprite(0, 0, 8);
            }
            break;
        case J_A:
            break;
        }

        performantdelay(1);
    }
}
