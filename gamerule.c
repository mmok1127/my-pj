#include "a.h"

void gamerule(void) {
	int i, j;
	draw_map();
	for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) { // �� �׵θ� ������ ��ĭ���� ä�� 
		for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++) gotoxy(j, i, "  ");
	}

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "�� : ���� �̵�");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "�� : ������ �̵�");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "�� : �Ʒ��̵�");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 8, "�� : �����̵�");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 10, "����Ű�� �̿��Ͽ� �����̸� �ǰ�");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "��ǥ�� ������� ������ ��Ե˴ϴ�");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "�� ������ �ӵ��� �Բ�");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "�� ���� ������ ������");

    gotoxy(MAP_X + (MAP_WIDTH / 2), MAP_Y + 17, "�ƹ�Ű�� �Է��ϼ���");

    while (kbhit()) getch(); //Ű�Է½�
    key = getch();           //Ÿ��Ʋȭ������ �̵�
    title();
}