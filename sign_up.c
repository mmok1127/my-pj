#include "a.h"

void sign_up(void) {
	MYSQL conn = { 0 };
	MYSQL* connection = NULL;
	MYSQL_RES* result = NULL;
	MYSQL_ROW row = { 0 };

	char buffer[100] = { 0 };
	char id[20] = { 0 };
	char pass[20] = { 0 };


	mysql_init(&conn);

	system("cls"); //ȭ���� ���� 
	draw_map(); //�� �׵θ��� �׸� 

	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME_USER, 3306, NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "error : %s\n", mysql_error(&conn));
	}
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "+--------------------------+");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|      ȸ  ��  ��  ��      |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "+--------------------------+");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "���̵� : ");
	gets(id);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "�е���� : ");
	gets(pass);

	sprintf(buffer, "select * from user where id = '%s'", id);
	mysql_query(connection, buffer);

	result = mysql_store_result(connection);

	if ((row = mysql_fetch_row(result)) != NULL) {
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "�ߺ��� ���̵��Դϴ�");
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "                      ");
		Sleep(1000);
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "�ٽ� �Է��� �ּ���");
		Sleep(2000);
		sign_up();
	}
	else {
		sprintf(buffer, "insert into user values" "('%s', '%s')", id, pass);
		mysql_query(connection, buffer);
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "ȸ�������� �Ϸ�Ǿ����ϴ�");
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "                            ");
		Sleep(1000);
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "3�ʵ� �α���ȭ������ �̵��մϴ�");
		Sleep(3000);
		login();
	}
}