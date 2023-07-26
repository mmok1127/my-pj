#include "a.h"

void stage_2(void) {
    int i;
    for (i = 9; i < MAP_WIDTH - 9; i++) {           //상단선 작성
        gotoxy(MAP_X + i, MAP_Y + 7, "■");
    }
    for (i = MAP_Y + 8; i < MAP_Y + MAP_HEIGHT - 7; i++) {  //우측 세로선 작성
        gotoxy(MAP_X + MAP_WIDTH - 10, i, "■");
    }
    for (i = 9; i < MAP_WIDTH - 9; i++) {
        gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 7, "■");     //하단선 작성
    }
}