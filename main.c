#include "a.h"

////////////////////////////MAIN START//////////////////////////////
int x[100], y[100]; //x,y ��ǥ���� ���� �� 100�� 
int food_x, food_y; //food�� ��ǥ���� ���� 
int length; //�����̸� ��� 
int speed; //���� �ӵ� 
int score; //���� ����  --reset�Լ��� ���� �ʱ�ȭ��
int best_score = 0; //�ְ� ���� ���� --reset�Լ��� ���� �ʱ�ȭ ���� ���� 
int last_score = 0; //������ ���� ����  --reset�Լ��� ���� �ʱ�ȭ ���� ����
int dir; //�̵����� ���� 
int key; //�Է¹��� Ű ���� 
int status_on = 0; // �����ڿ� status ǥ��Ȱ��ȭ ����.. �����߿� SŰ�� ������ Ȱ��
int stage = 0;   //���������� ����   
int sp_food = 0; //Ư���� ���� ���

int main() {
    system("mode con:cols=100 lines=25");
    PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //�뷡���

    login_sel();

    while (1) {
        if (kbhit()) do { key = getch(); } while (key == 224); //Ű �Է¹���
        Sleep(speed);

        switch (key) { //�Է¹��� Ű�� �ľ��ϰ� ����  
        case LEFT:
        case RIGHT:
        case UP:
        case DOWN:
            if ((dir == LEFT && key != RIGHT) || (dir == RIGHT && key != LEFT) || 
                (dir == UP && key != DOWN) || (dir == DOWN && key != UP))
                //180ȸ���̵��� �����ϱ� ���� �ʿ�. 
                dir = key;
            key = 0; // Ű���� �����ϴ� �Լ��� reset 
            break;
        case PAUSE: // PŰ�� ������ �Ͻ����� 
            pause();
            break;
        case 115: //SŰ�� ������ �����ڿ� status�� Ȱ��ȭ ��Ŵ  
            if (status_on == 0) status_on = 1;
            else status_on = 0;
            key = 0;
            break;
        case ESC: //ESCŰ�� ������ ���α׷� ���� 
            exit(0);
        }
        move(dir);

        if (status_on == 1) status(); // statusǥ�� 
    }
}

///////////////////////////MAIN END////////////////////////////////
