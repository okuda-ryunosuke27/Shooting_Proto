#include "Enemy.h"
#include "DxLib.h"

/****************************
�}�N����`
****************************/
#define ENEMYSIZE	(32)

/****************************
�ϐ��錾
****************************/
float EnemyX;
float EnemyY;
float EnemyR; 
float EnemySpeed;
int IsEnemyAlive;

/****************************
�G���䏈���F�G�̍X�V����
���@���F�Ȃ�
�߂�l�F�Ȃ�
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
�G���䏈���F�G�̍X�V����
���@���F�Ȃ�
�߂�l�F�Ȃ�
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
�G���䏈���F�G�̕`�揈��
���@���F�Ȃ�
* �߂�l�F�Ȃ�
****************************/
void Enemy_Draw(void)
{
	DrawBoxAA(EnemyX, EnemyY, EnemyX + ENEMYSIZE, EnemyY + ENEMYSIZE, 0xFFFFFF, TRUE);
}

/****************************
*�G���䏈���F�G��X���W���擾
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
****************************/
float GetEnemyX(void)
{
	return EnemyX;
}

/****************************
*�G���䏈���F�G��Y���W���擾
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
****************************/
float GetEnemyY(void)
{
	return EnemyY;
}