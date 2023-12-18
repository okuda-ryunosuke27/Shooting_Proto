#include "DxLib.h"
#include "FreamControl.h"

/****************************
�ϐ��錾
****************************/
int FreamTime;
int LastTime;
int FreamCount;

/****************************
�t���[������@�\�F����������
���@���F�Ȃ�
�߂�l�F�Ȃ�
****************************/
void FreamControl_Initialize(void)
{
	FreamTime = ((int) 1000.0f / FREAM_RATE);
	LastTime = GetNowCount();
	FreamCount = 0;	
}

/****************************
�t���[������@�\�F�X�V����
���@���F�Ȃ�
�߂�l�F�Ȃ�
****************************/
void FreamControl_Update(void)
{
	if (FreamCount == FREAM_RATE)
	{
		FreamCount = 0;
		LastTime = GetNowCount();
	}
	FreamCount++;

	int took = GetNowCount() - LastTime;
	int wait = FreamCount * 1000 / 60 - took;
	if (wait > 0)
	{
		WaitTimer(wait);
	}
}

/****************************
�t���[������@�\�F�t���[�����[�g���擾����
���@���F�Ȃ�
�߂�l�F�t���[�����[�g
****************************/
float GetFreamRate(void)
{
	return (float)(GetNowCount() - LastTime) / FreamCount;
}