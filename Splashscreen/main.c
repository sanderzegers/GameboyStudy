#include <gb/gb.h>
#include <stdio.h>
#include "foto_data.c"
#include "foto_map.c"

void main(){


        set_bkg_data(0,252, foto_data);
        set_bkg_tiles(0,0,20,18, foto_map);

        
        
        SHOW_BKG;
        DISPLAY_ON;

    }
