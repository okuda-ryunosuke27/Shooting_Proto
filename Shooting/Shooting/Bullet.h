#pragma once


/****************************
型宣言
****************************/
typedef struct Bullet
{
	float BulletX;
	float BulletY;
	float BulletR;
	int IsBulletFlag;
}BulletStatus;

typedef enum BulletWay
{
	Straight,
	Right,
	Left,
};


/****************************
プロトタイプ宣言
****************************/
void Bullet_Initialize(float& PlayerX, float& PlayerY);
void Bullet_Updata(void);

void Bullet_Homing(void);
void Bullet_Draw(void);

int GetBulletFlag(void);