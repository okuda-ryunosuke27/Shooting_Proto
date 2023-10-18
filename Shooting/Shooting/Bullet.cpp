#include "Bullet.h"
#include "DxLib.h"
#include "Enemy.h"
#include "FreamControl.h"


//ストレートに進む弾と
//ホーミングして進む弾と
//三つの方向に進む弾を作る


//グローバル変数宣言
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
	//敵が移動しないベクトルの計算をする。
	//ベクトルの計算をする
	//二点間の距離のX、Yを計算して
	//計算したX、Yを1フレームごとに割って
	//それを移動量にする。
	if (IsBulletFlag == 1)
	{
		//ベクトルの計算、Xの座標
		verX = GetEnemyX() - BulletX;

		//ベクトルの計算、Yの座標
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