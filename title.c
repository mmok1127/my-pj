#include "a.h"

void title(void) {
    int i, j, keystack = 1;

    while (kbhit()) getch(); //���ۿ� �ִ� Ű���� ���� 

    draw_map();    //�� �׵θ��� �׸� 
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) { // �� �׵θ� ������ ��ĭ���� ä�� 
        for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++) gotoxy(j, i, "  ");
    }

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|     �� �� �� ũ �� ��    |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "+--------------------------+");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 9, "< �����Ͻ÷��� aŰ�� �Է����ּ��� > ");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "    ��  �� ���ӽ���             ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        �� ���ӹ��             ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        �� �� ŷ ��               ");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 17, "       1705094 ������");

    while (1) {
        if (kbhit()) {           //Ű�Է¹��� 
            key = getch();
            if (key == ESC) exit(0); // ESCŰ�� ����
            else if (key == ALPA_A) break;      //a�� �Է¹����� ����
            else if (key == 224) {
                key = getch();
                switch (key) {              //Ű���� �Է��� ������ ���� �׸��� �����Ұ����� ǥ��
                case UP:                   //��Ű�� �Է¹����� ������ �׸�
                    keystack--;

                    if (keystack == 0) keystack = 1;
                    if (keystack == 1) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "    ��  �� ���ӽ���             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        �� ���ӹ��             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        �� �� ŷ ��               ");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        �� ���ӽ���             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "    ��  �� ���ӹ��             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        �� �� ŷ ��               ");
                        break;
                    }
                    else if (keystack == 3) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        �� ���ӽ���             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        �� ���ӹ��             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "    ��  �� �� ŷ ��               ");
                        break;
                    }

                case DOWN:
                    keystack++;
                    if (keystack == 4) keystack = 3;

                    if (keystack == 1) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "    ��  �� ���ӽ���             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        �� ���ӹ��             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        �� �� ŷ ��               ");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        �� ���ӽ���             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "    ��  �� ���ӹ��             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        �� �� ŷ ��               ");
                        break;
                    }
                    else if (keystack == 3) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        �� ���ӽ���             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        �� ���ӹ��             ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "    ��  �� �� ŷ ��               ");
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