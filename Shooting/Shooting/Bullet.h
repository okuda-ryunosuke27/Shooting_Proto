#pragma once
/****************************
型宣言
****************************/
typedef struct				//弾のステータスを作った。
{
	float BulletX;
	float BulletY;
	float BulletR;
	int IsBulletFlag;
}BulletStatus;

typedef enum				//弾の三方向を示している
{
	Straight,
	Right,
	Left,
}BulletWay;

/****************************
プロトタイプ宣言
****************************/
void Bullet_Initialize(void);
void Bullet_Create(float& PlayerX, float& PlayerY);
void Bullet_Updata(void);
void Bullet_Draw(void);

int GetBulletFlag(void);

//古の文献ホーミングという名の誘導ミサイルを
//作っていた時のものである。
//とりあえずおじゃんになったのでコメント化している
//void Bullet_Homing(void);
