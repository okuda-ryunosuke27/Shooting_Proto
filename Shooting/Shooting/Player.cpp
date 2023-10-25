#include "DxLib.h"
#include "Player.h"
#include "InputControl.h"
#include "Bullet.h"

float PlayerX, PlayerY;
int PlayerImage;
int trigger = 0;	//ストレートか三方向かを決める 0はストレート

void Player_Initialize(void)
{
	int ret = 0;

	PlayerImage = LoadGraph("images/ico.jpg");

	PlayerX = 250.0f, PlayerY = 360.0f;
}


void Player_Updata(void)
{
	//プレイヤーの移動処理
	if (key()[KEY_INPUT_A] == 1)
	{
		PlayerX -= 4.5f;
	}
	if (key()[KEY_INPUT_D] == 1)
	{
		PlayerX += 4.5f;
	}

	if (key()[KEY_INPUT_C] == 1 && GetBulletFlag() == 0)
	{
		trigger = 0;
	}
	else if (key()[KEY_INPUT_X] == 1 && GetBulletFlag() == 0)
	{
		trigger = 1;
	}


	//プレイヤーの弾打つ処理
	if (key()[KEY_INPUT_SPACE] == 1 && GetBulletFlag() == 0)
	{
		Bullet_Initialize(PlayerX, PlayerY);
	}

}


void Player_Draw(void)
{
	DrawGraphF(PlayerX, PlayerY, PlayerImage, TRUE);
}


int ChangeStatus(void)
{
	return trigger;
}