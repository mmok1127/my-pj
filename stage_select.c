#include "a.h"

void(stage_select)(void) {
    int i, j, keystack = 1;
	draw_map();
	for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) { // �� �׵θ� ������ ��ĭ���� ä�� 
		for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++) gotoxy(j, i, "  ");
	}

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 4, "    ���������� ������ ��");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "      aŰ�� �Է� �ϼ���");

	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "    ��  �� 1��������");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "        �� 2��������");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        �� 3��������");

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
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "    ��  �� 1��������");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "        �� 2��������");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        �� 3��������");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "        �� 1��������");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "    ��  �� 2��������");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        �� 3��������");
                        break;
                    }
                    else if (keystack == 3) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "        �� 1��������");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "        �� 2��������");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "    ��  �� 3��������");
                        break;
                    }

                case DOWN:
                    keystack++;
                    if (keystack == 4) keystack = 3;

                    if (keystack == 1) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "    ��  �� 1��������");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "        �� 2��������");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        �� 3��������");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "        �� 1��������");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "    ��  �� 2��������");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "        �� 3��������");
                        break;
                    }
                    else if (keystack == 3) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "        �� 1��������");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "        �� 2��������");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "    ��  �� 3��������");
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