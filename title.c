#include "a.h"

void title(void) {
    int i, j, keystack = 1;

    while (kbhit()) getch(); //버퍼에 있는 키값을 버림 

    draw_map();    //맵 테두리를 그림 
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) { // 맵 테두리 안쪽을 빈칸으로 채움 
        for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++) gotoxy(j, i, "  ");
    }

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|     스 네 이 크 게 임    |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "+--------------------------+");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 9, "< 시작하시려면 a키를 입력해주세요 > ");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "    →  ◇ 게임시작             ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        ◇ 게임방법             ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        ◇ 랭 킹 판               ");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 17, "       1705094 이종목");

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
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "    →  ◇ 게임시작             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        ◇ 게임방법             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        ◇ 랭 킹 판               ");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        ◇ 게임시작             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "    →  ◇ 게임방법             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        ◇ 랭 킹 판               ");
                        break;
                    }
                    else if (keystack == 3) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        ◇ 게임시작             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        ◇ 게임방법             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "    →  ◇ 랭 킹 판               ");
                        break;
                    }

                case DOWN:
                    keystack++;
                    if (keystack == 4) keystack = 3;

                    if (keystack == 1) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "    →  ◇ 게임시작             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        ◇ 게임방법             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        ◇ 랭 킹 판               ");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        ◇ 게임시작             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "    →  ◇ 게임방법             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        ◇ 랭 킹 판               ");
                        break;
                    }
                    else if (keystack == 3) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        ◇ 게임시작             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        ◇ 게임방법             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "    →  ◇ 랭 킹 판               ");
                        break;
                    }
                }
            }
        }

    }
    if (keystack == 1) {
        stage_select();
    }
    else if (keystack == 2) {
        gamerule();
    }
    else if (keystack == 3) {
        rank_board();
    }

}