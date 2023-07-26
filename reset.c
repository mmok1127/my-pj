#include "a.h"

void reset(void) {
    int i;
    system("cls"); //ȭ���� ���� 
    draw_map(); //�� �׵θ��� �׸� 
    while (kbhit()) getch(); //���ۿ� �ִ� Ű���� ���� 

    dir = LEFT; // ���� �ʱ�ȭ  
    speed = 100; // �ӵ� �ʱ�ȭ 
    length = 5; //�� ���� �ʱ�ȭ 
    score = 0; //���� �ʱ�ȭ 
    for (i = 0; i < length; i++) { //�� ���밪 �Է� 
        x[i] = MAP_WIDTH / 2 + i;
        y[i] = MAP_HEIGHT / 2;
        gotoxy(MAP_X + x[i], MAP_Y + y[i], "��");
    }
    gotoxy(MAP_X + x[0], MAP_Y + y[0], "��"); //�� �Ӹ� �׸� 

    if (stage == 1) {       //�������� 1
        food(); // food ����  
    }
    else if (stage == 2) {  //�������� 2
        stage_2();
        food(); // food ����  
    }
    else if (stage == 3) {  //�������� 3
        stage_3();
        food(); // food ����  
    }
    
}
