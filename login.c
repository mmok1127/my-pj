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

	system("cls"); //ȭ���� ���� 
	draw_map(); //�� �׵θ��� �׸� 

	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME_USER, 3306, NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "error : %s\n", mysql_error(&conn));
	}
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "+--------------------------+");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|     �� �� �� ũ �� ��    |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "+--------------------------+");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "���̵� : ");
	gets(id);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "�е���� : ");
	gets(pass);

	sprintf(buffer, "select * from user where id = '%s' and pass = '%s'", id, pass);
	mysql_query(connection, buffer);

	result = mysql_store_result(connection);

	if ((row = mysql_fetch_row(result)) != NULL) {
		system("cls");
		draw_map();
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "�α��� ����");
		Sleep(1500);
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "����� ������ ���۵˴ϴ�");
		Sleep(3000);
		title();
	}
	else {
		system("cls");
		draw_map();
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "���̵� �Ǵ� ��й�ȣ�� �߸��Ǿ����ϴ�");
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "�ƹ�Ű�� �Է����ּ���");
		_getch();
		login();
	}
}