#include "a.h"

void game_over(void) { //�������� �Լ� 
    int keystack = 1;

    system("cls"); //ȭ���� ���� 
    draw_map(); //�� �׵θ��� �׸� 
   
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 5, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 6, "|      ���� ����..     |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 7, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 8, " ����� ������ : ");
    printf("%d", last_score = score);

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   ��   ����ȭ�� ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        ��ŷ��� ");
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
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   ��   ����ȭ�� ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        ��ŷ��� ");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        ����ȭ�� ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "   ��   ��ŷ��� ");
                        break;
                    }

                case DOWN:
                    keystack++;
                    if (keystack == 3) keystack = 2;

                    if (keystack == 1) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   ��   ����ȭ�� ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        ��ŷ��� ");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        ����ȭ�� ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "   ��   ��ŷ��� ");
                        break;
                    }
                }
            }
        }
        if (score > best_score) {
            best_score = score;
            gotoxy(MAP_X + (MAP_WIDTH / 2) - 4, MAP_Y + 10, "�� �ְ������޼� ��");
        }

    }

    Sleep(500);
    if (keystack == 1) {    //����ȭ�� ���Ͻ� title �Լ��� �̵�
        title();
    }
    else if (keystack == 2) {//��ŷ ��� ���Ͻ� ��ŷ��� �� ������ �������� �̵�
        ranking();
    }
}