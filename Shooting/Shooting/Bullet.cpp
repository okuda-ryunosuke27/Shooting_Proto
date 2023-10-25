#include "Bullet.h"
#include "DxLib.h"
#include "Enemy.h"
#include "FreamControl.h"
#include "Player.h"


//�X�g���[�g�ɐi�ޒe��
//�z�[�~���O���Đi�ޒe��
//�O�̕����ɐi�ޒe�����


//�O���[�o���ϐ��錾
float verX = 0.0f, verY = 0.0f;
float BulletSpX = 0.0f, BulletSpY = 0.0f;

BulletStatus Bullet[3];

void Bullet_Initialize(float& PlayerX, float& PlayerY)
{
	/*StraightBullet.BulletX = -10.0f;
	StraightBullet.BulletY = -10.0f;
	StraightBullet.BulletR = 10.0f;
	StraightBullet.IsBulletFlag = 0;*/

	for (int i = 0; i < 3; i++)
	{
		Bullet[i].BulletX = -10.f;
		Bullet[i].BulletY = -10.f;
		Bullet[i].BulletR = -10.f;
		Bullet[i].IsBulletFlag = 0;
	}

	if (ChangeStatus() == 0)
	{
		if (Bullet[Straight].IsBulletFlag == 0)
		{
			Bullet[Straight].BulletX = PlayerX + 15;
			Bullet[Straight].BulletY = PlayerY + 15;
			Bullet[Straight].IsBulletFlag = 1;
		}
	}
	else
	{
		if (Bullet[Straight].IsBulletFlag == 0 && Bullet[Right].IsBulletFlag == 0 &&
			Bullet[Left].IsBulletFlag == 0)
		{
			Bullet[Straight].BulletX = PlayerX + 15;
			Bullet[Straight].BulletY = PlayerY + 15;
			Bullet[Right].BulletX = PlayerX + 15;
			Bullet[Right].BulletY = PlayerY + 15;
			Bullet[Left].BulletX = PlayerX + 15;
			Bullet[Left].BulletY = PlayerY + 15;
			Bullet[Straight].IsBulletFlag = 1;
			Bullet[Right].IsBulletFlag = 1;
			Bullet[Left].IsBulletFlag = 1;
		}
	}
}

void Bullet_Updata(void)
{
	
		if (Bullet[Straight].IsBulletFlag == 1)
		{
			if (ChangeStatus() == 0)
			{
				Bullet[Straight].BulletY -= 5.5;

				if (Bullet[Straight].BulletY < -20)
				{
					Bullet[Straight].IsBulletFlag = 0;
				}
			}
			else
			{
				Bullet[Straight].BulletY -= 5.5f;
				Bullet[Right].BulletX += 5.f;
				Bullet[Right].BulletY -= 5.f;
				Bullet[Left].BulletX -= 5.f;
				Bullet[Left].BulletY -= 5.f;

				if (Bullet[Straight].BulletY < -20 && Bullet[Right].BulletY < -20 
					&& Bullet[Left].BulletY < -20)
				{
					Bullet[Straight].IsBulletFlag = 0;
					Bullet[Right].IsBulletFlag = 0;
					Bullet[Left].IsBulletFlag = 0;
				}
			}
		}
}


void Bullet_Draw(void)
{
	DrawCircleAA(Bullet[Straight].BulletX, Bullet[Straight].BulletY, Bullet[Straight].BulletR, 15, 0xFFFFFF, TRUE);
	DrawCircleAA(Bullet[Right].BulletX, Bullet[Right].BulletY, Bullet[Right].BulletR, 15, 0xFFFFFF, TRUE);
	DrawCircleAA(Bullet[Left].BulletX, Bullet[Left].BulletY, Bullet[Left].BulletR, 15, 0xFFFFFF, TRUE);

	DrawFormatString(0, 400, 0xffffff, "%.2f", Bullet[Straight].BulletX);
	DrawFormatString(70, 400, 0xffffff, "%.2f", Bullet[Straight].BulletY);
	DrawFormatString(140, 400, 0xffffff, "%.2f", ChangeStatus());
}

int GetBulletFlag(void)
{
	return Bullet[Straight].IsBulletFlag;
}


//�Â̗U���~�T�C��
//�g�����ǂ���������񂯂�
//��Y�Ƃ��Ă����Ƃ�
//void Bullet_Homing()
//{
//	//�e�𔭎˂���v���O����
//	if (StraightBullet.IsBulletFlag == 1)
//	{
//		if (StraightBullet.BulletY > 30)
//		{
//			//�x�N�g���̌v�Z�AX�̍��W
//			verX = GetEnemyX() - StraightBullet.BulletX;
//			//�x�N�g���̌v�Z�AY�̍��W
//			verY = GetEnemyY() - StraightBullet.BulletY;
//		}
//		BulletSpX = verX / GetFreamTime();
//		BulletSpY = verY / GetFreamTime();
//		if (StraightBullet.BulletY > 320)
//		{
//			StraightBullet.BulletY -= 1.5f;
//		}
//		else 
//		{
//			StraightBullet.BulletX -= -BulletSpX;
//			StraightBullet.BulletY -= -BulletSpY;
//		}
//
//		if (StraightBullet.BulletY < -20)
//		{
//			StraightBullet.BulletX = -10.f;
//			StraightBullet.BulletY = -10.f;
//			StraightBullet.IsBulletFlag = 0;
//		}
//	}
//}
