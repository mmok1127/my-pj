#include "a.h"

void status(void) { //각종 스텟을 볼수 있는 함수 
    gotoxy(MAP_X + MAP_WIDTH + 1, MAP_Y, "머리 = ");      //혀
    printf("%2d,%2d", x[0], y[0]);
    gotoxy(MAP_X + MAP_WIDTH + 1, MAP_Y + 1, "과일 = ");
    printf("%2d,%2d", food_x, food_y);
    gotoxy(MAP_X + MAP_WIDTH + 1, MAP_Y + 2, "길이 = ");
    printf("%2d", length);
    gotoxy(MAP_X + MAP_WIDTH + 1, MAP_Y + 3, "키보드 = ");
    printf("%3d", key);
    gotoxy(MAP_X + MAP_WIDTH + 1, MAP_Y + 4, "스피드 = ");
    printf("%3d", speed);
    gotoxy(MAP_X + MAP_WIDTH + 1, MAP_Y + 6, "점수 = ");
    printf("%3d", score);
}