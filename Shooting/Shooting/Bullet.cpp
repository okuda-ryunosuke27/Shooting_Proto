#include "Bullet.h"
#include "DxLib.h"
#include "Enemy.h"
#include "FreamControl.h"
#include "Player.h"

/****************************
* グローバル変数宣言
****************************/
BulletStatus Bullet[3];


/****************************
弾の制御機能：初期化処理
引　数：なし
戻り値：なし
****************************/
void Bullet_Initialize(void)
{
	//三方向の弾の初期化をfor文でしている。
	for (int i = 0; i < 3; i++)
	{
		Bullet[i].BulletX = -10.f;
		Bullet[i].BulletY = -10.f;
		Bullet[i].BulletR = -10.f;
		Bullet[i].IsBulletFlag = 0;
	}
}

/****************************
弾の制御機能：弾の生成処理
引　数：なし
戻り値：なし
****************************/
void Bullet_Create(float& PlayerX, float& PlayerY)
{
	//弾の特徴を変化させている
	//0の場合はストレート
	//それ以外は三方向に出る弾を出す。
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
		if (Bullet[Straight].IsBulletFlag == 0 && Bullet[Right].IsBulletFlag == 0 && Bullet[Left].IsBulletFlag == 0)
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

/****************************
弾の制御機能：更新処理
引　数：なし
戻り値：なし
****************************/
void Bullet_Updata(void)
{
	//弾のフラグが１になったら
	//弾の動きを更新する。
	if (Bullet[Straight].IsBulletFlag == 1)
	{
		//弾の特徴を変化させている
		//0の場合はストレート
		//それ以外は三方向に出る弾を出す。
		if (ChangeStatus() == 0)
		{
			Bullet[Straight].BulletY -= 5.5;

			//ストレートの弾が -20に行ったら
			//弾のフラグを0にする。
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

			//弾たちが -20に行ったら弾たちのフラグを0にする。
			if (Bullet[Straight].BulletY < -20 && Bullet[Right].BulletY < -20 && Bullet[Left].BulletY < -20)
			{
				Bullet[Straight].IsBulletFlag = 0;
				Bullet[Right].IsBulletFlag = 0;
				Bullet[Left].IsBulletFlag = 0;
			}
		}
	}
}

/****************************
弾の制御機能：描画処理
引　数：なし
戻り値：なし
****************************/
void Bullet_Draw(void)
{
	DrawCircleAA(Bullet[Straight].BulletX, Bullet[Straight].BulletY, Bullet[Straight].BulletR, 15, 0xFFFFFF, TRUE);
	DrawCircleAA(Bullet[Right].BulletX, Bullet[Right].BulletY, Bullet[Right].BulletR, 15, 0xFFFFFF, TRUE);
	DrawCircleAA(Bullet[Left].BulletX, Bullet[Left].BulletY, Bullet[Left].BulletR, 15, 0xFFFFFF, TRUE);
}

int GetBulletFlag(void)
{
	return Bullet[Straight].IsBulletFlag;
}


//古の誘導ミサイル
//使うかどうか分からんけど
//遺産としておいとく
//void Bullet_Homing()
//{
//	//弾を発射するプログラム
//	if (StraightBullet.IsBulletFlag == 1)
//	{
//		if (StraightBullet.BulletY > 30)
//		{
//			//ベクトルの計算、Xの座標
//			verX = GetEnemyX() - StraightBullet.BulletX;
//			//ベクトルの計算、Yの座標
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
