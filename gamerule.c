#include "a.h"

void gamerule(void) {
	int i, j;
	draw_map();
	for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) { // 맵 테두리 안쪽을 빈칸으로 채움 
		for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++) gotoxy(j, i, "  ");
	}

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "↑ : 위로 이동");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "→ : 오른쪽 이동");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "↓ : 아래이동");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 8, "← : 왼쪽이동");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 10, "방향키를 이용하여 움직이면 되고");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "음표를 먹을경우 점수를 얻게됩니다");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "더 빨라진 속도와 함께");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "더 많은 점수를 얻어보세요");

    gotoxy(MAP_X + (MAP_WIDTH / 2), MAP_Y + 17, "아무키를 입력하세요");

    while (kbhit()) getch(); //키입력시
    key = getch();           //타이틀화면으로 이동
    title();
}