#!/bin/sh

rm main.o main.gb

/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o main.o main.c
#/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -c -o main.o main.c
/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -o main.gb main.o
#/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o main.gb main.o

if [ -f main.gb]; then
		echo "main.gb found"	
		wine /home/vmware/bgb/bgb.exe main.gb
	else
		echo "no main.gb found"
fi


[ -f main.gb ] && wine /home/vmware/bgb/bgb.exe main.gb
