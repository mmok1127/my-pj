#include "a.h"

void ranking(void) {

	MYSQL conn = { 0 };
	MYSQL* connection = NULL;
	MYSQL_RES* result = NULL;
	MYSQL_ROW row = { 0 };

	char buffer[100] = { 0 };
	char id[20] = { 0 };


	mysql_init(&conn);

	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0);
	if (connection == NULL) {
		fprintf(stderr, "error : %s\n", mysql_error(&conn));
	}

	system("cls"); //ȭ���� ���� 
	draw_map(); //�� �׵θ��� �׸� 

	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "���̵� �Է����ּ��� : ");
	gets(id);

	sprintf(buffer, "insert into rank values" "('%s', '%d')",id, score);
	mysql_query(connection, buffer);

	mysql_query(connection, "select * from rank order by score desc limit 5");

	result = mysql_store_result(connection);

	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "���̵�            ����");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 8, "--------------------------");
	while ((row = mysql_fetch_row(result)) != NULL) {
		printf("\n      ��   %15s  %15s\n", row[0], row[1]);	
	}

	while (kbhit()) getch(); //Ű�Է½�
	key = getch();           //Ÿ��Ʋȭ������ �̵�
	title();
}