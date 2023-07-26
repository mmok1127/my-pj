#include "a.h"

void reset(void) {
    int i;
    system("cls"); //화면을 지움 
    draw_map(); //맵 테두리를 그림 
    while (kbhit()) getch(); //버퍼에 있는 키값을 버림 

    dir = LEFT; // 방향 초기화  
    speed = 100; // 속도 초기화 
    length = 5; //뱀 길이 초기화 
    score = 0; //점수 초기화 
    for (i = 0; i < length; i++) { //뱀 몸통값 입력 
        x[i] = MAP_WIDTH / 2 + i;
        y[i] = MAP_HEIGHT / 2;
        gotoxy(MAP_X + x[i], MAP_Y + y[i], "ㅇ");
    }
    gotoxy(MAP_X + x[0], MAP_Y + y[0], "ㅎ"); //뱀 머리 그림 

    if (stage == 1) {       //스테이지 1
        food(); // food 생성  
    }
    else if (stage == 2) {  //스테이지 2
        stage_2();
        food(); // food 생성  
    }
    else if (stage == 3) {  //스테이지 3
        stage_3();
        food(); // food 생성  
    }
    
}
