#include "a.h"

void login(void) {
	MYSQL conn = { 0 };
	MYSQL* connection = NULL;
	MYSQL_RES* result = NULL;
	MYSQL_ROW row = { 0 };

	char buffer[100] = { 0 };
	char id[20] = { 0 };
	char pass[20] = { 0 };


	mysql_init(&conn);

	system("cls"); //화면을 지움 
	draw_map(); //맵 테두리를 그림 

	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME_USER, 3306, NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "error : %s\n", mysql_error(&conn));
	}
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "+--------------------------+");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|     스 네 이 크 게 임    |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "+--------------------------+");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "아이디 : ");
	gets(id);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "패드워드 : ");
	gets(pass);

	sprintf(buffer, "select * from user where id = '%s' and pass = '%s'", id, pass);
	mysql_query(connection, buffer);

	result = mysql_store_result(connection);

	if ((row = mysql_fetch_row(result)) != NULL) {
		system("cls");
		draw_map();
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "로그인 성공");
		Sleep(1500);
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "잠시후 게임이 시작됩니다");
		Sleep(3000);
		title();
	}
	else {
		system("cls");
		draw_map();
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "아이디 또는 비밀번호가 잘못되었습니다");
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "아무키를 입력해주세요");
		_getch();
		login();
	}
}