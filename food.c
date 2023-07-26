#include "a.h"

void food(void) {
    int i, num;

    int food_crush_on = 0;//food가 뱀 몸통좌표에 생길 경우 on 
    int r = 0; //난수 생성에 사동되는 변수 
    gotoxy(MAP_X, MAP_Y + MAP_HEIGHT, " 현재점수 :"); //점수표시 
    printf("%3d, 지난점수 : %3d, 최고점수 : %3d", score, last_score, best_score);

    while (1) {
        food_crush_on = 0;
        srand((unsigned)time(NULL) + r); //난수표생성 
        food_x = (rand() % (MAP_WIDTH - 2)) + 1;    //난수를 좌표값에 넣음 
        food_y = (rand() % (MAP_HEIGHT - 2)) + 1;

        for (i = 0; i < length; i++) { //food가 뱀 몸통과 겹치는지 확인  
            if (food_x == x[i] && food_y == y[i]) {
                food_crush_on = 1; //겹치면 food_crush_on 를 on 
                r++;
                break;
            }
        }
        if (stage == 2) {       //스테이지 2 푸드 체크
            if (food_x == 20 && food_y > 7 && food_y < 14) {        //우측장애물 감지  
                food_crush_on = 1;
            }
            else if (food_y == 7 && food_x >= 9 && food_x <= 20) {   //상단장애물 감지
                food_crush_on = 1;
            }
            else if (food_y == 13 && food_x >= 9 && food_x <= 20) {    //하단장애물 감지
                food_crush_on = 1;
            }
        }
        if (stage == 3) {       //스테이지 3 푸드 체크
            if (food_x == 14 && food_y >= 4 && food_y <= 6) {       //상단장애물
                food_crush_on = 1;
            }
            else if (food_x == 14 && food_y >= 13 && food_y <= 15) {//하단장애물
                food_crush_on = 1;
            }
            else if (food_y == 9 && food_x >= 4 && food_x <= 7) {   //좌측장애물
                food_crush_on = 1;
            }
            else if (food_y == 9 && food_x >= 22 && food_x <= 24) { //우측장애물
                food_crush_on = 1;
            }
        }

        if (food_crush_on == 1) continue; //겹쳤을 경우 while문을 다시 시작 

        num = rand();
        if (num % 5 == 4) {     //rand함수를 통해 확률적으로 특별한 음식을 출력
            gotoxy(MAP_X + food_x, MAP_Y + food_y, "★");
            sp_food = 1;
        }
        else {
            gotoxy(MAP_X + food_x, MAP_Y + food_y, "♪");
        }
        speed -= 2; //속도 증가 
        break;

    }
}