#include "a.h"

void stage_2(void) {
    int i;
    for (i = 9; i < MAP_WIDTH - 9; i++) {           //��ܼ� �ۼ�
        gotoxy(MAP_X + i, MAP_Y + 7, "��");
    }
    for (i = MAP_Y + 8; i < MAP_Y + MAP_HEIGHT - 7; i++) {  //���� ���μ� �ۼ�
        gotoxy(MAP_X + MAP_WIDTH - 10, i, "��");
    }
    for (i = 9; i < MAP_WIDTH - 9; i++) {
        gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 7, "��");     //�ϴܼ� �ۼ�
    }
}