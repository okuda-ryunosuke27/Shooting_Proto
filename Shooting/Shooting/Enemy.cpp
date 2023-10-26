#include "Enemy.h"
#include "DxLib.h"

/****************************
マクロ定義
****************************/
#define ENEMYSIZE	(32)

/****************************
変数宣言
****************************/
float EnemyX;
float EnemyY;
float EnemyR; 
float EnemySpeed;
int IsEnemyAlive;

/****************************
敵制御処理：敵の更新処理
引　数：なし
戻り値：なし
****************************/
void Enemy_Initialize(void)
{
	EnemyX = 300.f;
	EnemyY = 10.f;
	EnemyR = 18.f;
	EnemySpeed = 2.f;
	IsEnemyAlive = 1;
}

/****************************
敵制御処理：敵の更新処理
引　数：なし
戻り値：なし
****************************/
void Enemy_Update(void)
{
	if (EnemyX + ENEMYSIZE >= 640 || EnemyX <= 0)
	{
		EnemySpeed *= -1;
	}

	EnemyX += EnemySpeed;
}

/****************************
敵制御処理：敵の描画処理
引　数：なし
* 戻り値：なし
****************************/
void Enemy_Draw(void)
{
	DrawBoxAA(EnemyX, EnemyY, EnemyX + ENEMYSIZE, EnemyY + ENEMYSIZE, 0xFFFFFF, TRUE);
}

/****************************
*敵制御処理：敵のX座標を取得
* 引　数：なし
* 戻り値：なし
****************************/
float GetEnemyX(void)
{
	return EnemyX;
}

/****************************
*敵制御処理：敵のY座標を取得
* 引　数：なし
* 戻り値：なし
****************************/
float GetEnemyY(void)
{
	return EnemyY;
}