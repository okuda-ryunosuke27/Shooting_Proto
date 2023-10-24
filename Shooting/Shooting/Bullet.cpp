#include "Bullet.h"
#include "DxLib.h"
#include "Enemy.h"
#include "FreamControl.h"
#include "Player.h"


//ストレートに進む弾と
//ホーミングして進む弾と
//三つの方向に進む弾を作る


//グローバル変数宣言
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

	if (GetTrigger() == 0)
	{
		if (Bullet[Straight].IsBulletFlag == 0)
		{
			StraightBullet.BulletX = PlayerX + 15;
			StraightBullet.BulletY = PlayerY + 15;
			StraightBullet.IsBulletFlag = 1;
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
	if (GetTrigger() == 0)
	{
		if (StraightBullet.IsBulletFlag == 1)
		{
			StraightBullet.BulletY -= 5.5;

			if (StraightBullet.BulletY < -20)
			{
				StraightBullet.IsBulletFlag = 0;
			}
		}
	}
	else
	{
		if (StraightBullet.IsBulletFlag == 1)
		{
			StraightBullet.BulletX -= 5.5;

			if (StraightBullet.BulletX < -20)
			{
				StraightBullet.IsBulletFlag = 0;
			}
		}
	}
}


void Bullet_Draw(void)
{
	DrawCircleAA(StraightBullet.BulletX, StraightBullet.BulletY, StraightBullet.BulletR, 15, 0xFFFFFF, TRUE);

	DrawFormatString(0, 400, 0xffffff, "%.2f", StraightBullet.BulletX);
	DrawFormatString(70, 400, 0xffffff, "%.2f", StraightBullet.BulletY);
	DrawFormatString(140, 400, 0xffffff, "%.2f", GetTrigger());
}


//古の誘導ミサイル
//使うかどうか分からんけど
//遺産としておいとく
void Bullet_Homing()
{
	//弾を発射するプログラム
	if (StraightBullet.IsBulletFlag == 1)
	{
		if (StraightBullet.BulletY > 30)
		{
			//ベクトルの計算、Xの座標
			verX = GetEnemyX() - StraightBullet.BulletX;
			//ベクトルの計算、Yの座標
			verY = GetEnemyY() - StraightBullet.BulletY;
		}
		BulletSpX = verX / GetFreamTime();
		BulletSpY = verY / GetFreamTime();
		if (StraightBullet.BulletY > 320)
		{
			StraightBullet.BulletY -= 1.5f;
		}
		else 
		{
			StraightBullet.BulletX -= -BulletSpX;
			StraightBullet.BulletY -= -BulletSpY;
		}

		if (StraightBullet.BulletY < -20)
		{
			StraightBullet.BulletX = -10.f;
			StraightBullet.BulletY = -10.f;
			StraightBullet.IsBulletFlag = 0;
		}
	}
}
