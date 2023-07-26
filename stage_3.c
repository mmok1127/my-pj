#include "a.h"

void stage_3(void) {
    int i;

    for (i = MAP_Y + 4; i < MAP_Y + MAP_HEIGHT - 4; i++) {
        gotoxy(MAP_X + MAP_WIDTH / 2 - 1, i, "бс");
    }
    for (i = MAP_Y + 7; i < MAP_Y + MAP_HEIGHT - 7; i++) {
        gotoxy(MAP_X + MAP_WIDTH / 2 - 1, i, "  ");
    }
    for (i = 4; i < MAP_WIDTH - 4; i++) {
        gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT / 2 - 1, "бс");
    }
    for (i = 7; i < MAP_WIDTH - 7; i++) {
        gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT / 2 - 1, "  ");
    }
}