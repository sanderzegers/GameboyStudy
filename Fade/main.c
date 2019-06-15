#include <gb/gb.h>
#include <stdio.h>
#include "foto_data.c"
#include "foto_map.c"

UINT8 i;
UINT8 ii;

void performantdelay(UINT8 loops)
{

    for (ii = 0; ii < loops; ii++)
    {
        wait_vbl_done();
    }
}

/**
 *  BGP_REG
 * 
 *  11 10 01 01
 *  00: White
 *  01: Light grey
 *  10: Dark grey
 *  11: Black
 * 
 *  */

void fadeout()
{

    for (i = 0; i < 4; i++)
    {
        BGP_REG = (BGP_REG >> 2) + 0xc0;
        //BGP_REG = BGP_REG + 0xc0;
        performantdelay(8);
    }

}

void main()
{

    set_bkg_data(0, 252, foto_data);
    set_bkg_tiles(0, 0, 20, 18, foto_map);

    SHOW_BKG;
    DISPLAY_ON;

    waitpad(J_START);
    fadeout();
}
