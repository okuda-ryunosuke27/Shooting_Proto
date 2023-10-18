#include "Bullet.h"
#include "DxLib.h"
#include "Enemy.h"
#include "FreamControl.h"


//�X�g���[�g�ɐi�ޒe��
//�z�[�~���O���Đi�ޒe��
//�O�̕����ɐi�ޒe�����


//�O���[�o���ϐ��錾
float BulletX = -10.0f, BulletY = -10.0f, BulletR = 10.0f; 
int IsBulletFlag = 0;
float verX = 0.0f, verY = 0.0f;
float BulletSpX = 0.0f, BulletSpY = 0.0f;


void Bullet_Initialize(float& PlayerX, float& PlayerY)
{
	if (IsBulletFlag == 0)
	{
		BulletX = PlayerX + 15;
		BulletY = PlayerY + 15;
		IsBulletFlag = 1;
	}
}

void Bullet_Updata(void)
{
	if (IsBulletFlag == 1)
	{
		BulletY -= 5.5;

		if (BulletY < -20)
		{
			IsBulletFlag = 0;
		}
	}
}

void Bullet_Homing()
{
	//�G���ړ����Ȃ��x�N�g���̌v�Z������B
	//�x�N�g���̌v�Z������
	//��_�Ԃ̋�����X�AY���v�Z����
	//�v�Z����X�AY��1�t���[�����ƂɊ�����
	//������ړ��ʂɂ���B
	if (IsBulletFlag == 1)
	{
		//�x�N�g���̌v�Z�AX�̍��W
		verX = GetEnemyX() - BulletX;

		//�x�N�g���̌v�Z�AY�̍��W
		verY = GetEnemyY() - BulletY;

		BulletSpX = verX / GetFreamTime();
		BulletSpY = verY / GetFreamTime();
		
		BulletY -= -BulletSpY;

		if (BulletY < -20)
		{
			BulletX = 0;
			BulletY = 0;
			IsBulletFlag = 0;
		}
		/*if (BulletY > GetEnemyY())
		{
			BulletY -= 5.5;

			if (BulletY < GetEnemyY())
			{
				IsBulletFlag = 0;
			}
		}
		if (BulletX < GetEnemyX())
		{
			BulletX += 2.5;
		}*/
	}
}

void Bullet_Draw(void)
{
	DrawCircleAA(BulletX, BulletY, BulletR, 15, 0xFFFFFF, TRUE);

	DrawFormatString(0, 400, 0xffffff, "%.2f", BulletX);
	DrawFormatString(70, 400, 0xffffff, "%.2f", BulletY);
}