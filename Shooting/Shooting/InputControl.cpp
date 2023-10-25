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
���@��
****************************/
int Input_Escape(void)
{
	int ret = FALSE;

	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ret = TRUE;
	}

	return ret;
}

/****************************
����cpp�ɓ��͏������g����悤�ɂ���֐��B
****************************/
char* key(void)
{
	return keys;
}

char* oldkey(void)
{
	return oldkeys;
}