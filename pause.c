#include "a.h"
void pause(void) { // pŰ�� ������ ��� ������ �Ͻ� ���� 
    while (1) {
        if (key == PAUSE) {
            gotoxy(MAP_X + (MAP_WIDTH / 2) - 9, MAP_Y, "< �Ͻ����� : �ƹ�Ű�� ������ ����� > ");
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