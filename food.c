#include "a.h"

void food(void) {
    int i, num;

    int food_crush_on = 0;//food�� �� ������ǥ�� ���� ��� on 
    int r = 0; //���� ������ �絿�Ǵ� ���� 
    gotoxy(MAP_X, MAP_Y + MAP_HEIGHT, " �������� :"); //����ǥ�� 
    printf("%3d, �������� : %3d, �ְ����� : %3d", score, last_score, best_score);

    while (1) {
        food_crush_on = 0;
        srand((unsigned)time(NULL) + r); //����ǥ���� 
        food_x = (rand() % (MAP_WIDTH - 2)) + 1;    //������ ��ǥ���� ���� 
        food_y = (rand() % (MAP_HEIGHT - 2)) + 1;

        for (i = 0; i < length; i++) { //food�� �� ����� ��ġ���� Ȯ��  
            if (food_x == x[i] && food_y == y[i]) {
                food_crush_on = 1; //��ġ�� food_crush_on �� on 
                r++;
                break;
            }
        }
        if (stage == 2) {       //�������� 2 Ǫ�� üũ
            if (food_x == 20 && food_y > 7 && food_y < 14) {        //������ֹ� ����  
                food_crush_on = 1;
            }
            else if (food_y == 7 && food_x >= 9 && food_x <= 20) {   //�����ֹ� ����
                food_crush_on = 1;
            }
            else if (food_y == 13 && food_x >= 9 && food_x <= 20) {    //�ϴ���ֹ� ����
                food_crush_on = 1;
            }
        }
        if (stage == 3) {       //�������� 3 Ǫ�� üũ
            if (food_x == 14 && food_y >= 4 && food_y <= 6) {       //�����ֹ�
                food_crush_on = 1;
            }
            else if (food_x == 14 && food_y >= 13 && food_y <= 15) {//�ϴ���ֹ�
                food_crush_on = 1;
            }
            else if (food_y == 9 && food_x >= 4 && food_x <= 7) {   //������ֹ�
                food_crush_on = 1;
            }
            else if (food_y == 9 && food_x >= 22 && food_x <= 24) { //������ֹ�
                food_crush_on = 1;
            }
        }

        if (food_crush_on == 1) continue; //������ ��� while���� �ٽ� ���� 

        num = rand();
        if (num % 5 == 4) {     //rand�Լ��� ���� Ȯ�������� Ư���� ������ ���
            gotoxy(MAP_X + food_x, MAP_Y + food_y, "��");
            sp_food = 1;
        }
        else {
            gotoxy(MAP_X + food_x, MAP_Y + food_y, "��");
        }
        speed -= 2; //�ӵ� ���� 
        break;

    }
}