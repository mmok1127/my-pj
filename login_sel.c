#include "a.h"

void login_sel(void) {
	draw_map();
    int keystack = 1;
 
    draw_map(); //맵 테두리를 그림 

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|     스 네 이 크 게 임    |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   →   로 그 인 ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        회원가입 ");
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
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   →   로 그 인 ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        회원가입 ");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        로 그 인 ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "   →   회원가입 ");
                        break;
                    }

                case DOWN:
                    keystack++;
                    if (keystack == 3) keystack = 2;

                    if (keystack == 1) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   →   로 그 인 ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        회원가입 ");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        로 그 인 ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "   →   회원가입 ");
                        break;
                    }
                }
            }
        }
    }

    Sleep(500);
    if (keystack == 1) {    //로그인 탭일시 login 함수로 이동
        login();
    }
    else if (keystack == 2) {//회원가입 탭일시 sign_up함수로 이동
        sign_up();
    }

}