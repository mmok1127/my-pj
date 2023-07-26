#include "a.h"
void move(int dir) {
    int i;

    if (x[0] == food_x && y[0] == food_y) { //food�� �浹���� ��� 
        score += 10; //���� ���� 
        food(); //���ο� food �߰� 
        length++; //�������� 
        x[length - 1] = x[length - 2]; //���θ��� ���뿡 �� �Է� 
        y[length - 1] = y[length - 2];
        if (sp_food == 1) {
            score += 10;
            sp_food = 0;
        }
    }
    if (x[0] == 0 || x[0] == MAP_WIDTH - 1 || y[0] == 0 || y[0] == MAP_HEIGHT - 1) { //���� �浹���� ��� 
        game_over();
        return; //game_over���� ������ �ٽ� �����ϰ� �Ǹ� ���⼭���� �ݺ��ǹǷ� 
                //return�� ����Ͽ� move�� ������ �κ��� ������� �ʵ��� �մϴ�. 
    }
    if (stage == 2) {
        if (x[0] == 20 && y[0] > 7 && y[0] < 14 ) {     //������ֹ� ����
            game_over();
            return;
        }
        else if (y[0] == 7 && (x[0] >= 9 && x[0] <= 20)) {   //�����ֹ� ����
            game_over();
            return;
        }
        else if (y[0] == 13 && x[0] >= 9 && x[0] <= 20) {    //�ϴ���ֹ� ����
            game_over();
            return;
        }
    }
    else if (stage == 3) {
        if (x[0] == 14 && y[0] >= 4 && y[0] <= 6) {     //�����ֹ�
            game_over();
            return;
        }
        else if (x[0] == 14 && y[0] >= 13 && y[0] <= 15) {  //�ϴ���ֹ�
            game_over();
            return;
        }
        else if (y[0] == 9 && x[0] >= 4 && x[0] <= 7) {     //������ֹ�
            game_over();
            return;
        }
        else if (y[0] == 9 && x[0] >= 22 && x[0] <= 24) {   //������ֹ�
            game_over();
            return;
        }
    }

    for (i = 1; i < length; i++) { //�ڱ���� �浹�ߴ��� �˻� 
        if (x[0] == x[i] && y[0] == y[i]) {
            game_over();
            return;
        }
    }

    gotoxy(MAP_X + x[length - 1], MAP_Y + y[length - 1], "  "); //���� �������� ���� 
    for (i = length - 1; i > 0; i--) { //������ǥ�� ��ĭ�� �ű� 
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }
    gotoxy(MAP_X + x[0], MAP_Y + y[0], "��"); //�Ӹ��� �ִ����� �������� ��ħ 
    if (dir == LEFT) --x[0]; //���⿡ ���� ���ο� �Ӹ���ǥ(x[0],y[0])���� ���� 
    if (dir == RIGHT) ++x[0];
    if (dir == UP) --y[0];
    if (dir == DOWN) ++y[0];
    gotoxy(MAP_X + x[i], MAP_Y + y[i], "��"); //���ο� �Ӹ���ǥ���� �Ӹ��� �׸� 
}