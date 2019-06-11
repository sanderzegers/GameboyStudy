#include <gb/gb.h>


//generic char structure: id, position, graphics
typedef struct GameCharacter{
  UBYTE spritids[4];
  INT8 x;
  INT8 y;
  UINT8 width;
  UINT8 height;
};
