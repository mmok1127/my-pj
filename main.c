#include "a.h"

////////////////////////////MAIN START//////////////////////////////
int x[100], y[100]; //x,y 좌표값을 저장 총 100개 
int food_x, food_y; //food의 좌표값을 저장 
int length; //몸길이를 기억 
int speed; //게임 속도 
int score; //점수 저장  --reset함수에 의해 초기화됨
int best_score = 0; //최고 점수 저장 --reset함수에 의해 초기화 되지 않음 
int last_score = 0; //마지막 점수 저장  --reset함수에 의해 초기화 되지 않음
int dir; //이동방향 저장 
int key; //입력받은 키 저장 
int status_on = 0; // 개발자용 status 표시활성화 변수.. 게임중에 S키를 누르면 활성
int stage = 0;   //스테이지를 저장   
int sp_food = 0; //특별한 음식 사용

int main() {
    system("mode con:cols=100 lines=25");
    PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //노래출력

    login_sel();

    while (1) {
        if (kbhit()) do { key = getch(); } while (key == 224); //키 입력받음
        Sleep(speed);

        switch (key) { //입력받은 키를 파악하고 실행  
        case LEFT:
        case RIGHT:
        case UP:
        case DOWN:
            if ((dir == LEFT && key != RIGHT) || (dir == RIGHT && key != LEFT) || 
                (dir == UP && key != DOWN) || (dir == DOWN && key != UP))
                //180회전이동을 방지하기 위해 필요. 
                dir = key;
            key = 0; // 키값을 저장하는 함수를 reset 
            break;
        case PAUSE: // P키를 누르면 일시정지 
            pause();
            break;
        case 115: //S키를 누르면 개발자용 status를 활성화 시킴  
            if (status_on == 0) status_on = 1;
            else status_on = 0;
            key = 0;
            break;
        case ESC: //ESC키를 누르면 프로그램 종료 
            exit(0);
        }
        move(dir);

        if (status_on == 1) status(); // status표시 
    }
}

///////////////////////////MAIN END////////////////////////////////
