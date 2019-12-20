#include <stdio.h>
#include <stdlib.h>
#include "kadai.h"

void g_main_menu(Gakusei *, int); // メインメニュー
void g_out_menu(Gakusei *, int); // 表示処理
void g_srch_menu(Gakusei *, int); // 検索処理

int menu_no_get(void) {
	char buff[10] = "";
	if (gets_s(buff, sizeof(buff)) == NULL) return 0;
	return atoi(buff);
}

int main(void) {
	Gakusei gakusei[MAX_REC];
	int cunt = 1;

	// この時点でGakuseiに情報が入力されている
	gakusei[0].gakuno = 111;

	// 表示か検索か終了か選ぶ
	g_main_menu(gakusei, cunt);
	
	system("pause");
	return 0;
}

void g_main_menu(Gakusei * gakusei, int cunt) {
	int ret = 0;
	while (ret != 9) {
		printf("\n");
		printf("＜＜＜学生情報処理システム＞＞＞\n");
		printf("　　学生情報　表示処理：1\n");
		printf("　　学生情報　検索処理：2\n");
		printf("　　　　　　　　　終了：9\n");
		printf("処理番号を選択してください：");
		ret = menu_no_get();
		switch (ret) {
		case 1:
			g_out_menu(gakusei, cunt);
			break;
		case 2:
			g_srch_menu(gakusei, cunt);
			break;
		case 9:
			break;
		default:
			printf("\n!!!入力値が間違っています\n");
			break;
		}
		
	}
}

void g_out_menu(Gakusei *gakusei, int cunt) {
	printf("レコード内の全学生情報を表示します\n");
	printf("学生情報のヘッダーを入力してください：");
	int i = 0;
	char title[100] = "";
	scanf_s("%s", &title, 100);
	disp_gakusei(title, gakusei, cunt);
}

void g_srch_menu(Gakusei *gakusei, int cunt) {
	printf("レコード内の学生情報を検索します\n");

	printf("キー識別番号を選択してください。\n");
	printf("------------識別番号一覧------------\n");
	printf("１：学籍番号で探索\n");
	printf("２：性カナで探索\n");
	printf("３：名カナで探索\n");
	printf("４：性カナ、名カナで探索\n");
	printf("５：郵便番号(前3桁)で探索\n");
	printf("６：郵便番号(全桁)で探索\n");
	printf("７：都道府県カナで探索\n");
	printf("８：都道府県カナ＋住所カナで探索\n");
	printf("------------------------------------\n");
	Gakusei key_gakusei; // 探したい学生キー
	int key; scanf_s("%d", &key);
	char buff[300];
	switch (key) {
	case 1:
		printf("学籍番号を入力してください：");
		int gakuno; scanf("%d", &gakuno);
		key_gakusei.gakuno = gakuno;
	case 2:
		printf("性カナを入力してください：");
		gets_s(buff, sizeof(buff));
		strcpy_s(key_gakusei.namesei, buff);
		break;
	case 3:
		printf("名カナを入力してください：");
		gets_s(buff, sizeof(buff));
		strcpy_s(key_gakusei.namesei, buff);
		break;
	case 4:
		printf("性カナ、名カナを入力してください：");
		gets_s(buff, sizeof(buff));
		strcpy_s(key_gakusei.namesei, buff);
		break;
	case 5:
		printf("郵便番号(前3桁)を入力してください：");
		gets_s(buff, sizeof(buff));
		strcpy_s(key_gakusei.namesei, buff);
		break;
	case 6:
		printf("郵便番号(全桁)を入力してください：");
		gets_s(buff, sizeof(buff));
		strcpy_s(key_gakusei.namesei, buff);
		break;
	case 7:
		printf("都道府県カナを入力してください：");
		gets_s(buff, sizeof(buff));
		strcpy_s(key_gakusei.namesei, buff);
		break;
	case 8:
		printf("都道府県カナ＋住所カナを入力してください：");
		gets_s(buff, sizeof(buff));
		strcpy_s(key_gakusei.namesei, buff);
		break;
	default:
		printf("不正なキー識別番号です\n");
		return;
	}

	printf("探索アルゴリズムを選択してください。(線形探索：1, 二分探索：2)\n");
	int method; // 1で線形探索、2で二分探索
	scanf_s("%d", method); // 1か2入力
	switch (method) {
	case 1:  // 線形探索で先頭から順番にkey_gakusei情報に合致する学生レコードを探す
		int pos = srch_gakusei_line(key, gakusei, 0, cunt-1, key_gakusei);
		disp_gakusei(gakusei[pos]); // 検索結果の学生レコード表示
		break;
	case 2:  // 二分探索でkey_gakusei情報に合致する学生レコードを探す
		int pos = srch_gakusei_bin(key, gakusei, 0, cunt-1, key_gakusei);
		disp_gakusei(gakusei[pos]); // 検索結果の学生レコード表示
		break;
	default:
		printf("1か2で選択しろ\n");
		break;
	}
}
