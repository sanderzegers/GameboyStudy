#include <gb/gb.h>
#include <stdio.h>
#include "backgroundmap.c"
#include "simplebackground.c" q
#include "windowmap.c"
#include <gb/font.h>

void main(){


        font_t min_font;
        font_init();
        min_font = font_load(font_min); //36 tiles
        font_set(min_font);



        set_bkg_data(37,6, backgroundtiles);
        set_bkg_tiles(0,0,40,18, backgroundmap);

        
        set_win_tiles(0,0,5,1,windowmap);
        move_win(7,125);

        SHOW_BKG;
        SHOW_WIN;
        DISPLAY_ON;

        while(1){
                scroll_bkg(1,0);
                
                delay(100);
        }

    }
