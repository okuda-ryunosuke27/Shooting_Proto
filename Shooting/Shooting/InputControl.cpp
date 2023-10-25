#include "InputControl.h"
#include "ErrorFlag.h"
#include "DxLib.h"


char keys[256] = { 0 };
char oldkeys[256] = { 0 };

/****************************
���͐���@�\�F�X�V����
���@���F�Ȃ�
�߂�l�F�Ȃ�
****************************/
void Input_Updata(void)
{
	//�ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
	for (int i = 0; i < 256; ++i)
	{
		oldkeys[i] = keys[i];
	}

	//�ŐV�̃L�[�{�[�h�����擾
	GetHitKeyStateAll(keys);
}

/****************************
���͐���@�\�FESC�L�[���̓`�F�b�N
���@���F�Ȃ�
�߂�l�FTRUE(���͂��ꂽ)�AFALSE(������)
****************************/
int Input_Escape(void)
{
	int ret = FALSE;

	//ESC�L�[�������ꂽ�烋�[�v���甲����
	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ret = TRUE;
	}

	return ret;
}

/****************************
���͐���@�\�F���͏��擾����
���@���F�Ȃ�
�߂�l�F���͂��ꂽ����n��
****************************/
char* key(void)
{
	return keys;
}

/****************************
���͐���@�\�F���͏��擾����
���@���F�Ȃ�
�߂�l�F�ߋ��ɓ��͂��ꂽ����n��
****************************/
char* oldkey(void)
{
	return oldkeys;
}