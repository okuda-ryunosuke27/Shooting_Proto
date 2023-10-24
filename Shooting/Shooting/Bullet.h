#pragma once


/****************************
型宣言
****************************/
typedef struct BulletStatus
{
	float BulletX;
	float BulletY;
	float BulletR;
	int IsBulletFlag;
};


/****************************
プロトタイプ宣言
****************************/
void Bullet_Initialize(float& PlayerX, float& PlayerY);
void Bullet_Updata(void);

void Bullet_Homing(void);
void Bullet_Draw(void);