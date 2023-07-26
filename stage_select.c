#include "a.h"

void(stage_select)(void) {
    int i, j, keystack = 1;
	draw_map();
	for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) { // 맵 테두리 안쪽을 빈칸으로 채움 
		for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++) gotoxy(j, i, "  ");
	}

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 4, "    스테이지를 선택한 뒤");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "      a키를 입력 하세요");

	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "    →  ◇ 1스테이지");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "        ◇ 2스테이지");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        ◇ 3스테이지");

    while (1) {
        if (kbhit()) {           //키입력받음 
            key = getch();
            if (key == ESC) exit(0); // ESC키면 종료
            else if (key == ALPA_A) break;      //a를 입력받으면 시작
            else if (key == 224) {
                key = getch();
                switch (key) {              //키보드 입력을 받으면 무슨 항목을 실행할것인지 표시
                case UP:                   //윗키를 입력받으면 수행할 항목
                    keystack--;

                    if (keystack == 0) keystack = 1;
                    if (keystack == 1) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "    →  ◇ 1스테이지");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "        ◇ 2스테이지");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        ◇ 3스테이지");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "        ◇ 1스테이지");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "    →  ◇ 2스테이지");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        ◇ 3스테이지");
                        break;
                    }
                    else if (keystack == 3) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "        ◇ 1스테이지");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "        ◇ 2스테이지");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "    →  ◇ 3스테이지");
                        break;
                    }

                case DOWN:
                    keystack++;
                    if (keystack == 4) keystack = 3;

                    if (keystack == 1) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "    →  ◇ 1스테이지");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "        ◇ 2스테이지");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        ◇ 3스테이지");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "        ◇ 1스테이지");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "    →  ◇ 2스테이지");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        ◇ 3스테이지");
                        break;
                    }
                    else if (keystack == 3) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "        ◇ 1스테이지");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "        ◇ 2스테이지");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "    →  ◇ 3스테이지");
                        break;
                    }
                }
            }
        }

    }
    if (keystack == 1) {
        stage = 1;
        reset();
    }
    else if (keystack == 2) {
        stage = 2;
        reset();
    }
    else if (keystack == 3) {
        stage = 3;
        reset();
    }
}