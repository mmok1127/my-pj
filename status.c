#include "a.h"

void status(void) { //���� ������ ���� �ִ� �Լ� 
    gotoxy(MAP_X + MAP_WIDTH + 1, MAP_Y, "�Ӹ� = ");      //��
    printf("%2d,%2d", x[0], y[0]);
    gotoxy(MAP_X + MAP_WIDTH + 1, MAP_Y + 1, "���� = ");
    printf("%2d,%2d", food_x, food_y);
    gotoxy(MAP_X + MAP_WIDTH + 1, MAP_Y + 2, "���� = ");
    printf("%2d", length);
    gotoxy(MAP_X + MAP_WIDTH + 1, MAP_Y + 3, "Ű���� = ");
    printf("%3d", key);
    gotoxy(MAP_X + MAP_WIDTH + 1, MAP_Y + 4, "���ǵ� = ");
    printf("%3d", speed);
    gotoxy(MAP_X + MAP_WIDTH + 1, MAP_Y + 6, "���� = ");
    printf("%3d", score);
}