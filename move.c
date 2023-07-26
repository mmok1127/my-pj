#include "a.h"
void move(int dir) {
    int i;

    if (x[0] == food_x && y[0] == food_y) { //food와 충돌했을 경우 
        score += 10; //점수 증가 
        food(); //새로운 food 추가 
        length++; //길이증가 
        x[length - 1] = x[length - 2]; //새로만든 몸통에 값 입력 
        y[length - 1] = y[length - 2];
        if (sp_food == 1) {
            score += 10;
            sp_food = 0;
        }
    }
    if (x[0] == 0 || x[0] == MAP_WIDTH - 1 || y[0] == 0 || y[0] == MAP_HEIGHT - 1) { //벽과 충돌했을 경우 
        game_over();
        return; //game_over에서 게임을 다시 시작하게 되면 여기서부터 반복되므로 
                //return을 사용하여 move의 나머지 부분이 실행되지 않도록 합니다. 
    }
    if (stage == 2) {
        if (x[0] == 20 && y[0] > 7 && y[0] < 14 ) {     //우측장애물 감지
            game_over();
            return;
        }
        else if (y[0] == 7 && (x[0] >= 9 && x[0] <= 20)) {   //상단장애물 감지
            game_over();
            return;
        }
        else if (y[0] == 13 && x[0] >= 9 && x[0] <= 20) {    //하단장애물 감지
            game_over();
            return;
        }
    }
    else if (stage == 3) {
        if (x[0] == 14 && y[0] >= 4 && y[0] <= 6) {     //상단장애물
            game_over();
            return;
        }
        else if (x[0] == 14 && y[0] >= 13 && y[0] <= 15) {  //하단장애물
            game_over();
            return;
        }
        else if (y[0] == 9 && x[0] >= 4 && x[0] <= 7) {     //좌측장애물
            game_over();
            return;
        }
        else if (y[0] == 9 && x[0] >= 22 && x[0] <= 24) {   //우측장애물
            game_over();
            return;
        }
    }

    for (i = 1; i < length; i++) { //자기몸과 충돌했는지 검사 
        if (x[0] == x[i] && y[0] == y[i]) {
            game_over();
            return;
        }
    }

    gotoxy(MAP_X + x[length - 1], MAP_Y + y[length - 1], "  "); //몸통 마지막을 지움 
    for (i = length - 1; i > 0; i--) { //몸통좌표를 한칸씩 옮김 
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }
    gotoxy(MAP_X + x[0], MAP_Y + y[0], "ㅇ"); //머리가 있던곳을 몸통으로 고침 
    if (dir == LEFT) --x[0]; //방향에 따라 새로운 머리좌표(x[0],y[0])값을 변경 
    if (dir == RIGHT) ++x[0];
    if (dir == UP) --y[0];
    if (dir == DOWN) ++y[0];
    gotoxy(MAP_X + x[i], MAP_Y + y[i], "ㅎ"); //새로운 머리좌표값에 머리를 그림 
}