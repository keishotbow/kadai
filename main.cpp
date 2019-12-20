#include <stdio.h>
#include <stdlib.h>
#include "kadai.h"

void g_main_menu(Gakusei *, int); // ���C�����j���[
void g_out_menu(Gakusei *, int); // �\������
void g_srch_menu(Gakusei *, int); // ��������

int menu_no_get(void) {
	char buff[10] = "";
	if (gets_s(buff, sizeof(buff)) == NULL) return 0;
	return atoi(buff);
}

int main(void) {
	Gakusei gakusei[MAX_REC];
	int cunt = 1;

	// ���̎��_��Gakusei�ɏ�񂪓��͂���Ă���
	gakusei[0].gakuno = 111;

	// �\�����������I�����I��
	g_main_menu(gakusei, cunt);
	
	system("pause");
	return 0;
}

void g_main_menu(Gakusei * gakusei, int cunt) {
	int ret = 0;
	while (ret != 9) {
		printf("\n");
		printf("�������w����񏈗��V�X�e��������\n");
		printf("�@�@�w�����@�\�������F1\n");
		printf("�@�@�w�����@���������F2\n");
		printf("�@�@�@�@�@�@�@�@�@�I���F9\n");
		printf("�����ԍ���I�����Ă��������F");
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
			printf("\n!!!���͒l���Ԉ���Ă��܂�\n");
			break;
		}
		
	}
}

void g_out_menu(Gakusei *gakusei, int cunt) {
	printf("���R�[�h���̑S�w������\�����܂�\n");
	printf("�w�����̃w�b�_�[����͂��Ă��������F");
	int i = 0;
	char title[100] = "";
	scanf_s("%s", &title, 100);
	disp_gakusei(title, gakusei, cunt);
}

void g_srch_menu(Gakusei *gakusei, int cunt) {
	printf("���R�[�h���̊w�������������܂�\n");

	printf("�L�[���ʔԍ���I�����Ă��������B\n");
	printf("------------���ʔԍ��ꗗ------------\n");
	printf("�P�F�w�Дԍ��ŒT��\n");
	printf("�Q�F���J�i�ŒT��\n");
	printf("�R�F���J�i�ŒT��\n");
	printf("�S�F���J�i�A���J�i�ŒT��\n");
	printf("�T�F�X�֔ԍ�(�O3��)�ŒT��\n");
	printf("�U�F�X�֔ԍ�(�S��)�ŒT��\n");
	printf("�V�F�s���{���J�i�ŒT��\n");
	printf("�W�F�s���{���J�i�{�Z���J�i�ŒT��\n");
	printf("------------------------------------\n");
	Gakusei key_gakusei; // �T�������w���L�[
	int key; scanf_s("%d", &key);
	char buff[300];
	switch (key) {
	case 1:
		printf("�w�Дԍ�����͂��Ă��������F");
		int gakuno; scanf("%d", &gakuno);
		key_gakusei.gakuno = gakuno;
	case 2:
		printf("���J�i����͂��Ă��������F");
		gets_s(buff, sizeof(buff));
		strcpy_s(key_gakusei.namesei, buff);
		break;
	case 3:
		printf("���J�i����͂��Ă��������F");
		gets_s(buff, sizeof(buff));
		strcpy_s(key_gakusei.namesei, buff);
		break;
	case 4:
		printf("���J�i�A���J�i����͂��Ă��������F");
		gets_s(buff, sizeof(buff));
		strcpy_s(key_gakusei.namesei, buff);
		break;
	case 5:
		printf("�X�֔ԍ�(�O3��)����͂��Ă��������F");
		gets_s(buff, sizeof(buff));
		strcpy_s(key_gakusei.namesei, buff);
		break;
	case 6:
		printf("�X�֔ԍ�(�S��)����͂��Ă��������F");
		gets_s(buff, sizeof(buff));
		strcpy_s(key_gakusei.namesei, buff);
		break;
	case 7:
		printf("�s���{���J�i����͂��Ă��������F");
		gets_s(buff, sizeof(buff));
		strcpy_s(key_gakusei.namesei, buff);
		break;
	case 8:
		printf("�s���{���J�i�{�Z���J�i����͂��Ă��������F");
		gets_s(buff, sizeof(buff));
		strcpy_s(key_gakusei.namesei, buff);
		break;
	default:
		printf("�s���ȃL�[���ʔԍ��ł�\n");
		return;
	}

	printf("�T���A���S���Y����I�����Ă��������B(���`�T���F1, �񕪒T���F2)\n");
	int method; // 1�Ő��`�T���A2�œ񕪒T��
	scanf_s("%d", method); // 1��2����
	switch (method) {
	case 1:  // ���`�T���Ő擪���珇�Ԃ�key_gakusei���ɍ��v����w�����R�[�h��T��
		int pos = srch_gakusei_line(key, gakusei, 0, cunt-1, key_gakusei);
		disp_gakusei(gakusei[pos]); // �������ʂ̊w�����R�[�h�\��
		break;
	case 2:  // �񕪒T����key_gakusei���ɍ��v����w�����R�[�h��T��
		int pos = srch_gakusei_bin(key, gakusei, 0, cunt-1, key_gakusei);
		disp_gakusei(gakusei[pos]); // �������ʂ̊w�����R�[�h�\��
		break;
	default:
		printf("1��2�őI������\n");
		break;
	}
}
