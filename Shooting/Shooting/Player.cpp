#include "DxLib.h"
#include "Player.h"
#include "InputControl.h"
#include "Bullet.h"

float PlayerX, PlayerY;
int PlayerImage;

void Player_Initialize(void)
{
	int ret = 0;

	PlayerImage = LoadGraph("images/ico.jpg");

	PlayerX = 250.0f, PlayerY = 360.0f;
}


void Player_Updata(void)
{
	//�v���C���[�̈ړ�����
	if (key()[KEY_INPUT_A] == 1)
	{
		PlayerX -= 4.5f;
	}
	if (key()[KEY_INPUT_D] == 1)
	{
		PlayerX += 4.5f;
	}

	//�v���C���[�̒e�ł���
	if (key()[KEY_INPUT_SPACE] == 1)
	{
		Bullet_Initialize(PlayerX, PlayerY);
	}

}


void Player_Draw(void)
{
	DrawGraphF(PlayerX, PlayerY, PlayerImage, TRUE);
}