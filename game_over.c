#include "a.h"

void game_over(void) { //게임종료 함수 
    int keystack = 1;

    system("cls"); //화면을 지움 
    draw_map(); //맵 테두리를 그림 
   
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 5, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 6, "|      게임 종료..     |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 7, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 8, " 당신의 점수는 : ");
    printf("%d", last_score = score);

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   →   메인화면 ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        랭킹등록 ");
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
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   →   메인화면 ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        랭킹등록 ");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        메인화면 ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "   →   랭킹등록 ");
                        break;
                    }

                case DOWN:
                    keystack++;
                    if (keystack == 3) keystack = 2;

                    if (keystack == 1) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   →   메인화면 ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        랭킹등록 ");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        메인화면 ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "   →   랭킹등록 ");
                        break;
                    }
                }
            }
        }
        if (score > best_score) {
            best_score = score;
            gotoxy(MAP_X + (MAP_WIDTH / 2) - 4, MAP_Y + 10, "☆ 최고점수달성 ☆");
        }

    }

    Sleep(500);
    if (keystack == 1) {    //메인화면 탭일시 title 함수로 이동
        title();
    }
    else if (keystack == 2) {//랭킹 등록 탭일시 랭킹등록 및 점수판 페이지로 이동
        ranking();
    }
}