#!/bin/sh
rm main.o ColorSprite.gb LooneyTunes.o

/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o LooneyTunes.o LooneyTunes.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o main.o main.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -Wl-yp0x143=0x80 -o ColorSprite.gb LooneyTunes.o main.o



wine /home/vmware/bgb/bgb.exe ColorSprite.gb
