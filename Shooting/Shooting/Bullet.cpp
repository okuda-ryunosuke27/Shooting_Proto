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
	//�e�𔭎˂���v���O����
	if (IsBulletFlag == 1)
	{
		if (BulletY > 30)
		{
			//�x�N�g���̌v�Z�AX�̍��W
			verX = GetEnemyX() - BulletX;
			//�x�N�g���̌v�Z�AY�̍��W
			verY = GetEnemyY() - BulletY;
		}
		BulletSpX = verX / GetFreamTime();
		BulletSpY = verY / GetFreamTime();
		if (BulletY > 320)
		{
			BulletY -= 1.5f;
		}
		else 
		{
			BulletX -= -BulletSpX;
			BulletY -= -BulletSpY;
		}

		if (BulletY < -20)
		{
			BulletX = -10.f;
			BulletY = -10.f;
			IsBulletFlag = 0;
		}
	}
}

void Bullet_Draw(void)
{
	DrawCircleAA(BulletX, BulletY, BulletR, 15, 0xFFFFFF, TRUE);

	DrawFormatString(0, 400, 0xffffff, "%.2f", BulletX);
	DrawFormatString(70, 400, 0xffffff, "%.2f", BulletY);
	DrawFormatString(140, 400, 0xffffff, "%.2f", GetFreamTime());
}