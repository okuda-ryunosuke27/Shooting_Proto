#include "Enemy.h"
#include "DxLib.h"

#define ENEMYSIZE	(32)

float EnemyX = 300.0f,
float EnemyY = 10.0f, EnemyR = 18.0f, EnemySpeed = 2.0f;
int IsEnemyAlive = 1;

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