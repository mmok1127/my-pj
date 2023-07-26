#include "a.h"
void pause(void) { // p키를 눌렀을 경우 게임을 일시 정지 
    while (1) {
        if (key == PAUSE) {
            gotoxy(MAP_X + (MAP_WIDTH / 2) - 9, MAP_Y, "< 일시정지 : 아무키나 누르면 재시작 > ");
            Sleep(400);
            gotoxy(MAP_X + (MAP_WIDTH / 2) - 9, MAP_Y, "                                      ");
            Sleep(400);
        }
        else {
            draw_map();
            return;
        }
        if (kbhit()) {

            do {
                key = getch();
            } while (key == 224);
        }

    }
}