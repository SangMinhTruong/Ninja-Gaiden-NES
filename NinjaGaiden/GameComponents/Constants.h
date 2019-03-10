﻿#pragma once


//
//TiledMap
//

#define TILES_LOCATION L"Resources\\TiledMap\\3-1_tiles.png"
#define TILES_MATRIX L"Resources\\TiledMap\\3-1_matrix.txt"
#define TILES_MATRIX_DELIMITER ","
#define TILES_WIDTH_PER_TILE 16
#define TILES_HEIGHT_PER_TILE 16
#define TILES_TRANSCOLOR D3DCOLOR_XRGB(255, 0, 255)

//
//Simon
//
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 448

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define SIMON_WALKING_SPEED		0.125f
#define SIMON_JUMP_SPEED_Y		0.5f
#define SIMON_GRAVITY			0.025f
//Các số để chạy animation của Simon
#define SIMON_ANI_IDLE					0
#define SIMON_ANI_WALKING 				1
#define SIMON_ANI_STANDING_ATTACKING 	2
#define SIMON_ANI_CROUCHING_ATTACKING 	3
#define SIMON_ANI_JUMPING 				4
#define SIMON_ANI_CROUCHING 			5

#define SIMON_TEXTURE_LOCATION L"Resources\\Simon\\Simon.png"
#define SIMON_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define SIMON_TEXTURE_COLUMNS 8
#define SIMON_TEXTURE_ROWS 4
#define SIMON_SPRITE_WIDTH 60
#define SIMON_SPRITE_HEIGHT 66

//
//Whip
//
#define WHIP_NORMAL			0
#define WHIP_SHORT_CHAIN	1
#define WHIP_LONG_CHAIN		2

#define WHIP_TEXTURE_LOCATION L"Resources\\Weapons\\Whips\\Whips.png"
#define WHIP_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define WHIP_TEXTURE_COLUMNS 3
#define WHIP_TEXTURE_ROWS 6
#define WHIP_SPRITE_WIDTH 240
#define WHIP_SPRITE_HEIGHT 66

//
//Subweapon
//
#define SUBWEAPON_SPEED_X		0.3f
#define SUBWEAPON_SPEED_Y		0.5f
#define SUBWEAPON_GRAVITY		0.025f
////Knife
#define SUBWEAPON_KNIFE		0
#define SUBWEAPON_KNIFE_TEXTURE_LOCATION		L"Resources\\Weapons\\Subweapons\\Knife.png"
#define SUBWEAPON_KNIFE_TEXTURE_TRANS_COLOR		D3DCOLOR_XRGB(255, 0, 255)
#define SUBWEAPON_KNIFE_TEXTURE_COLUMNS 1
#define SUBWEAPON_KNIFE_TEXTURE_ROWS 1
#define SUBWEAPON_KNIFE_SPRITE_WIDTH 32
#define SUBWEAPON_KNIFE_SPRITE_HEIGHT 18