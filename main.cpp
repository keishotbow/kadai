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

// ���C���֐�
int main(void) {

	Gakusei gakusei[MAX_REC];
	int cunt = 1;

	// ���̎��_��Gakusei�ɏ�񂪓��͂���Ă���
	// �t�@�C�����o��(�t�@�C�����Ȃ��̂ŏȗ�)
	gakusei[0].gakuno = 111; // �K���Ɋw�Дԍ����ꂽ

	// ���C�����j���[��
	g_main_menu(gakusei, cunt);
	
	system("pause");
	return 0;
}

// ���C�����j���[
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

// �w������\������
void g_out_menu(Gakusei *gakusei, int cunt) {
	printf("�������w�����@�\������������");
	printf("�@�@�@�@�w�Дԍ����\���F�P\n");
	printf("�@�@�@�@�����J�i���\���F�Q\n");
	printf("�@�@�@�@�X�֔ԍ����\���F�R\n");
	printf("�@���C�����j���[�ɖ߂�F�X\n");
	printf("�����ԍ���I�����Ă��������F");
	
	// �R�R��������I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I
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
			printf("1~3��������9����͂��Ă�������\n");
		}
	}
	// �R�R�܂ŁI�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I

	int i = 0;
	char title[100] = "�������w�����ꗗ������";
	//scanf_s("%s", &title, 100);
	disp_gakusei(title, gakusei, cunt);
}

// �w��������������
void g_srch_menu(Gakusei *gakusei, int cunt) {

	printf("�������w�����@�����������j���[������\n");
	printf("------------���ʔԍ��ꗗ------------\n");
	printf("�P�F�w�Дԍ��Ō���\n");
	printf("�Q�F�X�֔ԍ�(�O3��)�Ō���\n");
	printf("�R�F�X�֔ԍ�(�S7��)�Ō���\n");
	printf("�S�F�����J�i(��)�Ō���\n");
	printf("�T�F�����J�i(����)�Ō���\n");
	printf("�U�F�s���{���J�i�Ō���\n");
	printf("�V�F�Z���J�i(��������n�܂�)�Ō���\n");
	printf("�W�F�Z���J�i(�������܂�)�ŒT��\n");
	printf("�X�F���C�����j���[�ɖ߂�");
	printf("------------------------------------\n");
	Gakusei key_gakusei; // �T�������w���L�[
	int key;
	while (true) {
		scanf_s("%d", &key);
		char buff[300];
		switch (key) {
		case 1:
			printf("�w�Дԍ�����͂��Ă��������F");
			int gakuno; scanf_s("%d", &gakuno);
			key_gakusei.gakuno = gakuno;
		case 2:
			printf("�X�֔ԍ�(�O3��)����͂��Ă��������F");
			gets_s(buff, sizeof(buff));
			strcpy_s(key_gakusei.namesei, buff);
			break;
		case 3:
			printf("�X�֔ԍ�(�S7��)����͂��Ă��������F");
			gets_s(buff, sizeof(buff));
			strcpy_s(key_gakusei.namesei, buff);
			break;
		case 4:
			printf("�����J�i(��)����͂��Ă��������F");
			gets_s(buff, sizeof(buff));
			strcpy_s(key_gakusei.namesei, buff);
			break;
		case 5:
			printf("�����J�i(����)����͂��Ă��������F");
			gets_s(buff, sizeof(buff));
			strcpy_s(key_gakusei.namesei, buff);
			break;
		case 6:
			printf("�s���{���J�i����͂��Ă��������F");
			gets_s(buff, sizeof(buff));
			strcpy_s(key_gakusei.namesei, buff);
			break;
		case 7:
			printf("�Z���J�i(��������n�܂�)����͂��Ă��������F");
			gets_s(buff, sizeof(buff));
			strcpy_s(key_gakusei.namesei, buff);
			break;
		case 8:
			printf("�s���{���J�i�{�Z���J�i����͂��Ă��������F");
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

	printf("�T���A���S���Y����I�����Ă��������B(���`�T���F1, �񕪒T���F2)\n");
	int method; // 1�Ő��`�T���A2�œ񕪒T��
	scanf_s("%d", &method); // 1��2����
	switch (method) {
	case 1:  // ���`�T���Ő擪���珇�Ԃ�key_gakusei���ɍ��v����w�����R�[�h��T��
		srch_gakusei_line(key, gakusei, 0, cunt-1, key_gakusei);
		//disp_gakusei_record(gakusei[pos]); // �������ʂ̊w�����R�[�h�\��
		break;
	case 2:  // �񕪒T����key_gakusei���ɍ��v����w�����R�[�h��T��
		srch_gakusei_bin(key, gakusei, 0, cunt-1, key_gakusei);
		//disp_gakusei_record(gakusei[pos]); // �������ʂ̊w�����R�[�h�\��
		break;
	default:
		printf("1��2�őI������\n");
		break;
	}
}
