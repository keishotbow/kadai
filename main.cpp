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

// メイン関数
int main(void) {

	Gakusei gakusei[MAX_REC];
	int cunt = 1;

	// この時点でGakuseiに情報が入力されている
	// ファイル入出力(ファイルがないので省略)
	gakusei[0].gakuno = 111; // 適当に学籍番号入れた

	// メインメニューへ
	g_main_menu(gakusei, cunt);
	
	system("pause");
	return 0;
}

// メインメニュー
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

// 学生情報を表示する
void g_out_menu(Gakusei *gakusei, int cunt) {
	printf("＜＜＜学生情報　表示処理＞＞＞");
	printf("　　　　学籍番号順表示：１\n");
	printf("　　　　氏名カナ順表示：２\n");
	printf("　　　　郵便番号準表示：３\n");
	printf("　メインメニューに戻る：９\n");
	printf("処理番号を選択してください：");
	
	// ココかえたよ！！！！！！！！！！！！！！！！！
	int num;
	while (true) {
		scanf_s("%d", &num);
		if (num == 1 || num == 2 || num == 3) {
			sort_gakusei_bubble(num, gakusei, cunt);
		}
		else if (num == 9) {
			return;
		}
		else {
			printf("1~3もしくは9を入力してください\n");
		}
	}
	// ココまで！！！！！！！！！！！！！！！！！！！

	int i = 0;
	char title[100] = "＜＜＜学生情報一覧＞＞＞";
	//scanf_s("%s", &title, 100);
	disp_gakusei(title, gakusei, cunt);
}

// 学生情報を検索する
void g_srch_menu(Gakusei *gakusei, int cunt) {

	printf("＜＜＜学生情報　検索処理メニュー＞＞＞\n");
	printf("------------識別番号一覧------------\n");
	printf("１：学籍番号で検索\n");
	printf("２：郵便番号(前3桁)で検索\n");
	printf("３：郵便番号(全7桁)で検索\n");
	printf("４：氏名カナ(姓)で検索\n");
	printf("５：氏名カナ(姓名)で検索\n");
	printf("６：都道府県カナで検索\n");
	printf("７：住所カナ(○○から始まる)で検索\n");
	printf("８：住所カナ(○○を含む)で探索\n");
	printf("９：メインメニューに戻る");
	printf("------------------------------------\n");
	Gakusei key_gakusei; // 探したい学生キー
	int key;
	while (true) {
		scanf_s("%d", &key);
		char buff[300];
		switch (key) {
		case 1:
			printf("学籍番号を入力してください：");
			int gakuno; scanf_s("%d", &gakuno);
			key_gakusei.gakuno = gakuno;
		case 2:
			printf("郵便番号(前3桁)を入力してください：");
			gets_s(buff, sizeof(buff));
			strcpy_s(key_gakusei.namesei, buff);
			break;
		case 3:
			printf("郵便番号(全7桁)を入力してください：");
			gets_s(buff, sizeof(buff));
			strcpy_s(key_gakusei.namesei, buff);
			break;
		case 4:
			printf("氏名カナ(姓)を入力してください：");
			gets_s(buff, sizeof(buff));
			strcpy_s(key_gakusei.namesei, buff);
			break;
		case 5:
			printf("氏名カナ(姓名)を入力してください：");
			gets_s(buff, sizeof(buff));
			strcpy_s(key_gakusei.namesei, buff);
			break;
		case 6:
			printf("都道府県カナを入力してください：");
			gets_s(buff, sizeof(buff));
			strcpy_s(key_gakusei.namesei, buff);
			break;
		case 7:
			printf("住所カナ(○○から始まる)を入力してください：");
			gets_s(buff, sizeof(buff));
			strcpy_s(key_gakusei.namesei, buff);
			break;
		case 8:
			printf("都道府県カナ＋住所カナを入力してください：");
			gets_s(buff, sizeof(buff));
			strcpy_s(key_gakusei.namesei, buff);
			break;
		case 9:
			return;
			break;
		default:
			break;
		}
	}

	printf("探索アルゴリズムを選択してください。(線形探索：1, 二分探索：2)\n");
	int method; // 1で線形探索、2で二分探索
	scanf_s("%d", &method); // 1か2入力
	switch (method) {
	case 1:  // 線形探索で先頭から順番にkey_gakusei情報に合致する学生レコードを探す
		srch_gakusei_line(key, gakusei, 0, cunt-1, key_gakusei);
		//disp_gakusei_record(gakusei[pos]); // 検索結果の学生レコード表示
		break;
	case 2:  // 二分探索でkey_gakusei情報に合致する学生レコードを探す
		srch_gakusei_bin(key, gakusei, 0, cunt-1, key_gakusei);
		//disp_gakusei_record(gakusei[pos]); // 検索結果の学生レコード表示
		break;
	default:
		printf("1か2で選択しろ\n");
		break;
	}
}
