#include "a.h"

void login_sel(void) {
	draw_map();
    int keystack = 1;
 
    draw_map(); //�� �׵θ��� �׸� 

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|     �� �� �� ũ �� ��    |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   ��   �� �� �� ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        ȸ������ ");
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
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   ��   �� �� �� ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        ȸ������ ");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        �� �� �� ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "   ��   ȸ������ ");
                        break;
                    }

                case DOWN:
                    keystack++;
                    if (keystack == 3) keystack = 2;

                    if (keystack == 1) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   ��   �� �� �� ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "        ȸ������ ");
                        break;
                    }
                    else if (keystack == 2) {
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "        �� �� �� ");
                        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "   ��   ȸ������ ");
                        break;
                    }
                }
            }
        }
    }

    Sleep(500);
    if (keystack == 1) {    //�α��� ���Ͻ� login �Լ��� �̵�
        login();
    }
    else if (keystack == 2) {//ȸ������ ���Ͻ� sign_up�Լ��� �̵�
        sign_up();
    }

}