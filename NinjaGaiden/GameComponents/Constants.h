﻿#pragma once
#include <vector>

//Tên ứng dụng
#define WINDOW_CLASS_NAME L"Ninja Gaiden"
#define MAIN_WINDOW_TITLE L"Ninja Gaiden"
//Màu background, kích cỡ màn hình
#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 0)
#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 240

//Framerate tối đa
#define MAX_FRAME_RATE 60
//Id texture của các vật thể
#define ID_TEX_NINJA 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20
//
//TiledMap
//

#define TILED_MAP_ID_3_1 1
#define TILED_MAP_ID_3_2 2
#define TILED_MAP_ID_3_3 3


#define TILES_LOCATION_3_1 L"Resources\\TiledMap\\3-1_tiles.png"
#define TILES_MATRIX_3_1 L"Resources\\TiledMap\\3-1_matrix.txt"

#define TILES_LOCATION_3_2 L"Resources\\TiledMap\\3-2_tiles.png"
#define TILES_MATRIX_3_2 L"Resources\\TiledMap\\3-2_matrix.txt"

#define TILES_LOCATION_3_3 L"Resources\\TiledMap\\3-3_tiles.png"
#define TILES_MATRIX_3_3 L"Resources\\TiledMap\\3-3_matrix.txt"

#define TILES_MATRIX_DELIMITER ","
#define TILES_WIDTH_PER_TILE	16
#define TILES_HEIGHT_PER_TILE	16
#define TILES_TRANSCOLOR D3DCOLOR_XRGB(255, 0, 255)

//
//Ryu
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define NINJA_WALKING_SPEED		0.125f
#define NINJA_JUMP_SPEED_Y		0.5f
#define NINJA_GRAVITY			0.025f
#define NINJA_CLIMBING_SPEED	0.075f
#define NINJA_INVINSIBLE_TIME	2000
//Các số để chạy animation của Ninja
#define NINJA_ANI_IDLE					0
#define NINJA_ANI_WALKING 				1
#define NINJA_ANI_STANDING_ATTACKING 	2
#define NINJA_ANI_CROUCHING_ATTACKING 	3
#define NINJA_ANI_JUMPING 				4
#define NINJA_ANI_CROUCHING 			5
#define NINJA_ANI_HURT		 			6
#define NINJA_ANI_CLIMBING		 		7
#define NINJA_ANI_THROWING	 			8
#define NINJA_ANI_DYING		 			-1

#define NINJA_TEXTURE_LOCATION L"Resources\\Ninja\\Ninja.png"
#define NINJA_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define NINJA_TEXTURE_COLUMNS 10
#define NINJA_TEXTURE_ROWS 3
#define NINJA_SPRITE_WIDTH 26
#define NINJA_SPRITE_HEIGHT 36

//
//Whip
//
#define WHIP_NORMAL			0
#define WHIP_SHORT_CHAIN	1
#define WHIP_LONG_CHAIN		2

#define WHIP_TEXTURE_LOCATION L"Resources\\Weapons\\Sword\\Sword.png"
#define WHIP_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define WHIP_TEXTURE_COLUMNS 1
#define WHIP_TEXTURE_ROWS 1
#define WHIP_SPRITE_WIDTH 24
#define WHIP_SPRITE_HEIGHT 16

//
//Subweapon
//
#define SUBWEAPON_SPEED_X		0.3f
#define SUBWEAPON_SPEED_Y		0.1f
#define SUBWEAPON_GRAVITY		0.025f

////Shuriken
#define SUBWEAPON_SHURIKEN						0
#define SUBWEAPON_SHURIKEN_TEXTURE_LOCATION		L"Resources\\Weapons\\Subweapons\\Shuriken.png"
#define SUBWEAPON_SHURIKEN_TEXTURE_TRANS_COLOR	D3DCOLOR_XRGB(255, 0, 255)
#define SUBWEAPON_SHURIKEN_TEXTURE_COLUMNS		2
#define SUBWEAPON_SHURIKEN_TEXTURE_ROWS			1
#define SUBWEAPON_SHURIKEN_SPRITE_WIDTH			8
#define SUBWEAPON_SHURIKEN_SPRITE_HEIGHT		8

////Windmill Shuriken
#define SUBWEAPON_WINDMILLSHURIKEN						3
#define SUBWEAPON_WINDMILLSHURIKEN_TEXTURE_LOCATION		L"Resources\\Weapons\\Subweapons\\WindmillShuriken.png"
#define SUBWEAPON_WINDMILLSHURIKEN_TEXTURE_TRANS_COLOR	D3DCOLOR_XRGB(255, 0, 255)
#define SUBWEAPON_WINDMILLSHURIKEN_TEXTURE_COLUMNS		2
#define SUBWEAPON_WINDMILLSHURIKEN_TEXTURE_ROWS			1
#define SUBWEAPON_WINDMILLSHURIKEN_SPRITE_WIDTH			16
#define SUBWEAPON_WINDMILLSHURIKEN_SPRITE_HEIGHT		16

////FIRE WHEEL
#define SUBWEAPON_FIREWHEEL							2 
#define SUBWEAPON_FIREWHEEL_TEXTURE_LOCATION		L"Resources\\Weapons\\Subweapons\\FireWheel.png"
#define SUBWEAPON_FIREWHEEL_TEXTURE_TRANS_COLOR		D3DCOLOR_XRGB(255, 0, 255)
#define SUBWEAPON_FIREWHEEL_TEXTURE_COLUMNS			4
#define SUBWEAPON_FIREWHEEL_TEXTURE_ROWS			1
#define SUBWEAPON_FIREWHEEL_SPRITE_WIDTH			29
#define SUBWEAPON_FIREWHEEL_SPRITE_HEIGHT			36

//
//Thug
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define THUG_WALKING_SPEED		0.075f
#define THUG_JUMP_SPEED_Y		0.0f
#define THUG_GRAVITY			0.025f
//Các số để chạy animation của Ninja
#define THUG_ANI_IDLE					0
#define THUG_ANI_WALKING 				1
#define THUG_ANI_STANDING_ATTACKING 	-1
#define THUG_ANI_CROUCHING_ATTACKING 	-1
#define THUG_ANI_JUMPING 				-1
#define THUG_ANI_CROUCHING 				-1
#define THUG_ANI_DYING		 			2

#define THUG_TEXTURE_LOCATION L"Resources\\Enemies\\Thug.png"
#define THUG_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define THUG_TEXTURE_COLUMNS 3
#define THUG_TEXTURE_ROWS 1
#define THUG_SPRITE_WIDTH 25
#define THUG_SPRITE_HEIGHT 40

//
//Yellow Bird
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define YELLOW_BIRD_WALKING_SPEED		0.075f
#define YELLOW_BIRD_JUMP_SPEED_Y		0.0f
#define YELLOW_BIRD_GRAVITY				0.0f
//Các số để chạy animation của Ninja
#define YELLOW_BIRD_ANI_IDLE					0
#define YELLOW_BIRD_ANI_WALKING 				1
#define YELLOW_BIRD_ANI_STANDING_ATTACKING 		-1
#define YELLOW_BIRD_ANI_CROUCHING_ATTACKING 	-1
#define YELLOW_BIRD_ANI_JUMPING 				-1
#define YELLOW_BIRD_ANI_CROUCHING 				-1
#define YELLOW_BIRD_ANI_DYING		 			2

#define YELLOW_BIRD_TEXTURE_LOCATION L"Resources\\Enemies\\YellowBird.png"
#define YELLOW_BIRD_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define YELLOW_BIRD_TEXTURE_COLUMNS 3
#define YELLOW_BIRD_TEXTURE_ROWS 1
#define YELLOW_BIRD_SPRITE_WIDTH 25
#define YELLOW_BIRD_SPRITE_HEIGHT 40

//
//Zombie
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define ZOMBIE_WALKING_SPEED		0.03f
#define ZOMBIE_WALKING_ACCEL		0.001f
#define ZOMBIE_JUMP_SPEED_Y			0.0f
#define ZOMBIE_GRAVITY				0.025f
//Các số để chạy animation của Ninja
#define ZOMBIE_ANI_IDLE						0
#define ZOMBIE_ANI_WALKING 					1
#define ZOMBIE_ANI_STANDING_ATTACKING 		-1
#define ZOMBIE_ANI_CROUCHING_ATTACKING		-1
#define ZOMBIE_ANI_THROWING	 				2
#define ZOMBIE_ANI_JUMPING 					-1
#define ZOMBIE_ANI_CROUCHING 				-1
#define ZOMBIE_ANI_DYING		 			3

#define ZOMBIE_TEXTURE_LOCATION L"Resources\\Enemies\\Zombie.png"
#define ZOMBIE_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define ZOMBIE_TEXTURE_COLUMNS	3
#define ZOMBIE_TEXTURE_ROWS		1
#define ZOMBIE_SPRITE_WIDTH		24
#define ZOMBIE_SPRITE_HEIGHT	48

//
//Cougar
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define COUGAR_WALKING_SPEED		0.125f
#define COUGAR_JUMP_SPEED_Y			0.0f
#define COUGAR_GRAVITY				0.025f
//Các số để chạy animation của Ninja
#define COUGAR_ANI_IDLE						0
#define COUGAR_ANI_WALKING 					1
#define COUGAR_ANI_STANDING_ATTACKING 		-1
#define COUGAR_ANI_CROUCHING_ATTACKING 		-1
#define COUGAR_ANI_JUMPING 					-1
#define COUGAR_ANI_CROUCHING 				-1
#define COUGAR_ANI_DYING		 			2

#define COUGAR_TEXTURE_LOCATION L"Resources\\Enemies\\Cougar.png"
#define COUGAR_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define COUGAR_TEXTURE_COLUMNS	2
#define COUGAR_TEXTURE_ROWS		1
#define COUGAR_SPRITE_WIDTH		32
#define COUGAR_SPRITE_HEIGHT	24

//
//Bat
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define BAT_WALKING_SPEED		0.075f
#define BAT_JUMP_SPEED_Y		0.0f
#define BAT_GRAVITY				0.0f
//Các số để chạy animation của Ninja
#define BAT_ANI_IDLE					0
#define BAT_ANI_WALKING 				1
#define BAT_ANI_STANDING_ATTACKING 		-1
#define BAT_ANI_CROUCHING_ATTACKING 	-1
#define BAT_ANI_JUMPING 				-1
#define BAT_ANI_CROUCHING 				-1
#define BAT_ANI_DYING		 			2

#define BAT_TEXTURE_LOCATION L"Resources\\Enemies\\Bat.png"
#define BAT_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define BAT_TEXTURE_COLUMNS 2
#define BAT_TEXTURE_ROWS	1
#define BAT_SPRITE_WIDTH	16
#define BAT_SPRITE_HEIGHT	16

//
//Runner
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define RUNNER_WALKING_SPEED		0.125f
#define RUNNER_JUMP_SPEED_Y			0.0f
#define RUNNER_GRAVITY				0.025f
//Các số để chạy animation của Ninja
#define RUNNER_ANI_IDLE						0
#define RUNNER_ANI_WALKING 					1
#define RUNNER_ANI_STANDING_ATTACKING 		-1
#define RUNNER_ANI_CROUCHING_ATTACKING 		-1
#define RUNNER_ANI_JUMPING 					-1
#define RUNNER_ANI_CROUCHING 				-1
#define RUNNER_ANI_DYING		 			2

#define RUNNER_TEXTURE_LOCATION L"Resources\\Enemies\\Runner.png"
#define RUNNER_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define RUNNER_TEXTURE_COLUMNS	2
#define RUNNER_TEXTURE_ROWS		1
#define RUNNER_SPRITE_WIDTH		16
#define RUNNER_SPRITE_HEIGHT	32


//
//MachineGunner
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define MACHINE_GUNNER_WALKING_SPEED		0.0625f
#define MACHINE_GUNNER_JUMP_SPEED_Y			0.0f
#define MACHINE_GUNNER_GRAVITY				0.025f
//Các số để chạy animation của Ninja
#define MACHINE_GUNNER_ANI_IDLE						0
#define MACHINE_GUNNER_ANI_WALKING 					1
#define MACHINE_GUNNER_ANI_STANDING_ATTACKING 		-1
#define MACHINE_GUNNER_ANI_CROUCHING_ATTACKING		-1
#define MACHINE_GUNNER_ANI_THROWING	 				2
#define MACHINE_GUNNER_ANI_JUMPING 					-1
#define MACHINE_GUNNER_ANI_CROUCHING 				-1
#define MACHINE_GUNNER_ANI_DYING		 			3

#define MACHINE_GUNNER_TEXTURE_LOCATION L"Resources\\Enemies\\MachineGunner.png"
#define MACHINE_GUNNER_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define MACHINE_GUNNER_TEXTURE_COLUMNS	4
#define MACHINE_GUNNER_TEXTURE_ROWS		1
#define MACHINE_GUNNER_SPRITE_WIDTH		24
#define MACHINE_GUNNER_SPRITE_HEIGHT	32

//
//Cannon Shooter
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define CANNON_SHOOTER_WALKING_SPEED		0.0f
#define CANNON_SHOOTER_JUMP_SPEED_Y			0.0f
#define CANNON_SHOOTER_GRAVITY				0.025f
//Các số để chạy animation của Ninja
#define CANNON_SHOOTER_ANI_IDLE						0
#define CANNON_SHOOTER_ANI_WALKING 					1
#define CANNON_SHOOTER_ANI_STANDING_ATTACKING 		-1
#define CANNON_SHOOTER_ANI_CROUCHING_ATTACKING		-1
#define CANNON_SHOOTER_ANI_THROWING	 				2
#define CANNON_SHOOTER_ANI_JUMPING 					-1
#define CANNON_SHOOTER_ANI_CROUCHING 				-1
#define CANNON_SHOOTER_ANI_DYING		 			3

#define CANNON_SHOOTER_TEXTURE_LOCATION L"Resources\\Enemies\\CannonShooter.png"
#define CANNON_SHOOTER_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define CANNON_SHOOTER_TEXTURE_COLUMNS	2
#define CANNON_SHOOTER_TEXTURE_ROWS		1
#define CANNON_SHOOTER_SPRITE_WIDTH		32
#define CANNON_SHOOTER_SPRITE_HEIGHT	32

//
//Boss
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define BOSS_WALKING_SPEED		0.075f
#define BOSS_JUMP_SPEED_Y		0.0f
#define BOSS_GRAVITY			0.0f
//Các số để chạy animation của Ninja
#define BOSS_ANI_IDLE					0
#define BOSS_ANI_WALKING 				-1
#define BOSS_ANI_STANDING_ATTACKING 	-1
#define BOSS_ANI_CROUCHING_ATTACKING 	-1
#define BOSS_ANI_JUMPING 				1
#define BOSS_ANI_CROUCHING 				-1
#define BOSS_ANI_DYING		 			2

#define BOSS_TEXTURE_LOCATION L"Resources\\Enemies\\Boss.png"
#define BOSS_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define BOSS_TEXTURE_COLUMNS	2
#define BOSS_TEXTURE_ROWS		1
#define BOSS_SPRITE_WIDTH		38
#define BOSS_SPRITE_HEIGHT		53


//
//Zombie Bullet
//

#define ZOMBIE_BULLET_TEXTURE_LOCATION L"Resources\\Enemies\\ZombieBullet.png"
#define ZOMBIE_BULLET_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define ZOMBIE_BULLET_TEXTURE_COLUMNS	2
#define ZOMBIE_BULLET_TEXTURE_ROWS		1
#define ZOMBIE_BULLET_SPRITE_WIDTH		8
#define ZOMBIE_BULLET_SPRITE_HEIGHT		16
#define ZOMBIE_BULLET_SPEED_X			0.2f
#define ZOMBIE_BULLET_SPEED_Y			0.35f
#define ZOMBIE_BULLET_GRAVITY			0.025f

//
//Machine Gunner Bullet
//

#define MACHINE_GUNNER_BULLET_TEXTURE_LOCATION L"Resources\\Enemies\\MachineGunnerBullet.png"
#define MACHINE_GUNNER_BULLET_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define MACHINE_GUNNER_BULLET_TEXTURE_COLUMNS	1
#define MACHINE_GUNNER_BULLET_TEXTURE_ROWS		1
#define MACHINE_GUNNER_BULLET_SPRITE_WIDTH		8
#define MACHINE_GUNNER_BULLET_SPRITE_HEIGHT		4
#define MACHINE_GUNNER_BULLET_SPEED_X			0.125f
#define MACHINE_GUNNER_BULLET_SPEED_Y			0.0f
#define MACHINE_GUNNER_BULLET_GRAVITY			0.0f
//
//Cannon Shooter Bullet
//

#define CANNON_SHOOTER_BULLET_TEXTURE_LOCATION L"Resources\\Enemies\\CannonShooterBullet.png"
#define CANNON_SHOOTER_BULLET_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define CANNON_SHOOTER_BULLET_TEXTURE_COLUMNS	1
#define CANNON_SHOOTER_BULLET_TEXTURE_ROWS		1
#define CANNON_SHOOTER_BULLET_SPRITE_WIDTH		8
#define CANNON_SHOOTER_BULLET_SPRITE_HEIGHT		4
#define CANNON_SHOOTER_BULLET_SPEED_X			0.125f
#define CANNON_SHOOTER_BULLET_SPEED_Y			0.0f
#define CANNON_SHOOTER_BULLET_GRAVITY			0.0f
//
//Boss Bullet
//

#define BOSS_BULLET_TEXTURE_LOCATION L"Resources\\Enemies\\BossBullet.png"
#define BOSS_BULLET_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define BOSS_BULLET_TEXTURE_COLUMNS		1
#define BOSS_BULLET_TEXTURE_ROWS		1
#define BOSS_BULLET_SPRITE_WIDTH		5
#define BOSS_BULLET_SPRITE_HEIGHT		5
#define BOSS_BULLET_SPEED_X				0.125f
#define BOSS_BULLET_SPEED_Y				0.0f
#define BOSS_BULLET_GRAVITY				0.0f
//
//Explosion
//

#define EXPLOSION_TEXTURE_LOCATION L"Resources\\Misc\\Explosion.png"
#define EXPLOSION_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define EXPLOSION_TEXTURE_COLUMNS 3
#define EXPLOSION_TEXTURE_ROWS 1
#define EXPLOSION_SPRITE_WIDTH 48
#define EXPLOSION_SPRITE_HEIGHT 48

#define EXPLOSION_BOSS_TEXTURE_LOCATION L"Resources\\Misc\\BossExplosion.png"
#define EXPLOSION_BOSS_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define EXPLOSION_BOSS_TEXTURE_COLUMNS 2
#define EXPLOSION_BOSS_TEXTURE_ROWS 1
#define EXPLOSION_BOSS_SPRITE_WIDTH 35
#define EXPLOSION_BOSS_SPRITE_HEIGHT 37
//
//Item
//
#define ITEM_BUTTERFLY			1
#define ITEM_BIRD				2

#define ITEM_TEXTURE_LOCATION_BUTTERFLY L"Resources\\Items\\Butterfly.png"
#define ITEM_TEXTURE_LOCATION_BIRD L"Resources\\Items\\Bird.png"
#define ITEM_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define ITEM_TEXTURE_COLUMNS	2
#define ITEM_TEXTURE_ROWS		1
#define ITEM_SPRITE_WIDTH		16
#define ITEM_SPRITE_HEIGHT		16

#define IS_ITEM_DROP(id) (id >= 310 && id < 400) ? true : false
//Blue Spirit Point
#define ITEM_BLUE_SPIRIT_POINT_SPEED_X				0.0f
#define ITEM_BLUE_SPIRIT_POINT_SPEED_Y				0.0f
#define ITEM_BLUE_SPIRIT_POINT_GRAVITY				0.025f

#define ITEM_BLUE_SPIRIT_POINT_TEXTURE_LOCATION						L"Resources\\Items\\BlueSpiritPoint.png"
#define ITEM_BLUE_SPIRIT_POINT_TEXTURE_TRANS_COLOR					D3DCOLOR_XRGB(255, 0, 255)
#define ITEM_BLUE_SPIRIT_POINT_TEXTURE_COLUMNS						1
#define ITEM_BLUE_SPIRIT_POINT_TEXTURE_ROWS							1
#define ITEM_BLUE_SPIRIT_POINT_SPRITE_WIDTH							15
#define ITEM_BLUE_SPIRIT_POINT_SPRITE_HEIGHT						15

//Red Spirit Point
#define ITEM_RED_SPIRIT_POINT_SPEED_X				0.0f
#define ITEM_RED_SPIRIT_POINT_SPEED_Y				0.0f
#define ITEM_RED_SPIRIT_POINT_GRAVITY				0.025f

#define ITEM_RED_SPIRIT_POINT_TEXTURE_LOCATION						L"Resources\\Items\\RedSpiritPoint.png"
#define ITEM_RED_SPIRIT_POINT_TEXTURE_TRANS_COLOR					D3DCOLOR_XRGB(255, 0, 255)
#define ITEM_RED_SPIRIT_POINT_TEXTURE_COLUMNS						1
#define ITEM_RED_SPIRIT_POINT_TEXTURE_ROWS							1
#define ITEM_RED_SPIRIT_POINT_SPRITE_WIDTH							15
#define ITEM_RED_SPIRIT_POINT_SPRITE_HEIGHT							15

//Shuriken Drop
#define ITEM_SHURIKEN_DROP_SPEED_X				0.0f
#define ITEM_SHURIKEN_DROP_SPEED_Y				0.0f
#define ITEM_SHURIKEN_DROP_GRAVITY				0.025f

#define ITEM_SHURIKEN_DROP_TEXTURE_LOCATION						L"Resources\\Items\\ShurikenDrop.png"
#define ITEM_SHURIKEN_DROP_TEXTURE_TRANS_COLOR					D3DCOLOR_XRGB(255, 0, 255)
#define ITEM_SHURIKEN_DROP_TEXTURE_COLUMNS						1
#define ITEM_SHURIKEN_DROP_TEXTURE_ROWS							1
#define ITEM_SHURIKEN_DROP_SPRITE_WIDTH							16
#define ITEM_SHURIKEN_DROP_SPRITE_HEIGHT						16

//Windmill Drop
#define ITEM_WINDMILL_DROP_SPEED_X				0.0f
#define ITEM_WINDMILL_DROP_SPEED_Y				0.0f
#define ITEM_WINDMILL_DROP_GRAVITY				0.025f

#define ITEM_WINDMILL_DROP_TEXTURE_LOCATION						L"Resources\\Items\\WindmillDrop.png"
#define ITEM_WINDMILL_DROP_TEXTURE_TRANS_COLOR					D3DCOLOR_XRGB(255, 0, 255)
#define ITEM_WINDMILL_DROP_TEXTURE_COLUMNS						1
#define ITEM_WINDMILL_DROP_TEXTURE_ROWS							1
#define ITEM_WINDMILL_DROP_SPRITE_WIDTH							16
#define ITEM_WINDMILL_DROP_SPRITE_HEIGHT						16

//Firewheel Drop
#define ITEM_FIREWHEEL_DROP_SPEED_X				0.0f
#define ITEM_FIREWHEEL_DROP_SPEED_Y				0.0f
#define ITEM_FIREWHEEL_DROP_GRAVITY				0.025f

#define ITEM_FIREWHEEL_DROP_TEXTURE_LOCATION						L"Resources\\Items\\FirewheelDrop.png"
#define ITEM_FIREWHEEL_DROP_TEXTURE_TRANS_COLOR						D3DCOLOR_XRGB(255, 0, 255)
#define ITEM_FIREWHEEL_DROP_TEXTURE_COLUMNS							1
#define ITEM_FIREWHEEL_DROP_TEXTURE_ROWS							1
#define ITEM_FIREWHEEL_DROP_SPRITE_WIDTH							16
#define ITEM_FIREWHEEL_DROP_SPRITE_HEIGHT							16

//Blue Bonus Drop
#define ITEM_BLUE_BONUS_DROP_SPEED_X				0.0f
#define ITEM_BLUE_BONUS_DROP_SPEED_Y				0.0f
#define ITEM_BLUE_BONUS_DROP_GRAVITY				0.025f

#define ITEM_BLUE_BONUS_DROP_TEXTURE_LOCATION						L"Resources\\Items\\BlueBonus.png"
#define ITEM_BLUE_BONUS_DROP_TEXTURE_TRANS_COLOR						D3DCOLOR_XRGB(255, 0, 255)
#define ITEM_BLUE_BONUS_DROP_TEXTURE_COLUMNS							1
#define ITEM_BLUE_BONUS_DROP_TEXTURE_ROWS							1
#define ITEM_BLUE_BONUS_DROP_SPRITE_WIDTH							16
#define ITEM_BLUE_BONUS_DROP_SPRITE_HEIGHT							15

//Red Bonus Drop
#define ITEM_RED_BONUS_DROP_SPEED_X				0.0f
#define ITEM_RED_BONUS_DROP_SPEED_Y				0.0f
#define ITEM_RED_BONUS_DROP_GRAVITY				0.025f

#define ITEM_RED_BONUS_DROP_TEXTURE_LOCATION						L"Resources\\Items\\RedBonus.png"
#define ITEM_RED_BONUS_DROP_TEXTURE_TRANS_COLOR						D3DCOLOR_XRGB(255, 0, 255)
#define ITEM_RED_BONUS_DROP_TEXTURE_COLUMNS							1
#define ITEM_RED_BONUS_DROP_TEXTURE_ROWS							1
#define ITEM_RED_BONUS_DROP_SPRITE_WIDTH							16
#define ITEM_RED_BONUS_DROP_SPRITE_HEIGHT							15

//FREEZE_DROP Drop
#define ITEM_FREEZE_DROP_SPEED_X				0.0f
#define ITEM_FREEZE_DROP_SPEED_Y				0.0f
#define ITEM_FREEZE_DROP_GRAVITY				0.025f

#define ITEM_FREEZE_DROP_TEXTURE_LOCATION						L"Resources\\Items\\Freeze.png"
#define ITEM_FREEZE_DROP_TEXTURE_TRANS_COLOR						D3DCOLOR_XRGB(255, 0, 255)
#define ITEM_FREEZE_DROP_TEXTURE_COLUMNS							1
#define ITEM_FREEZE_DROP_TEXTURE_ROWS							1
#define ITEM_FREEZE_DROP_SPRITE_WIDTH							12
#define ITEM_FREEZE_DROP_SPRITE_HEIGHT							15

//HEALTH_DROP Drop
#define ITEM_HEALTH_DROP_SPEED_X				0.0f
#define ITEM_HEALTH_DROP_SPEED_Y				0.0f
#define ITEM_HEALTH_DROP_GRAVITY				0.025f

#define ITEM_HEALTH_DROP_TEXTURE_LOCATION						L"Resources\\Items\\Health.png"
#define ITEM_HEALTH_DROP_TEXTURE_TRANS_COLOR						D3DCOLOR_XRGB(255, 0, 255)
#define ITEM_HEALTH_DROP_TEXTURE_COLUMNS							1
#define ITEM_HEALTH_DROP_TEXTURE_ROWS							1
#define ITEM_HEALTH_DROP_SPRITE_WIDTH							12
#define ITEM_HEALTH_DROP_SPRITE_HEIGHT							15

//Grid Spatial Partitioning Parameters
#define GRID_SIZE 64
#define GRID_MAX_X 48
#define GRID_MAX_Y 5
#define GRID_INFO_DELIMITER ","


//
// Game Object IDs
//

// Ninja = 0
#define GAME_OBJ_ID_NINJA					0
// Enemies > 0, < 100
#define GAME_OBJ_ID_THUG					1
#define GAME_OBJ_ID_YELLOW_BIRD				2
#define GAME_OBJ_ID_ZOMBIE					3
#define GAME_OBJ_ID_COUGAR					4
#define GAME_OBJ_ID_BAT						5
#define GAME_OBJ_ID_RUNNER					6
#define GAME_OBJ_ID_MACHINE_GUNNER			7
#define GAME_OBJ_ID_CANNON_SHOOTER			8
#define GAME_OBJ_ID_BOSS					9
#define GAME_OBJ_ID_ZOMBIE_BULLET			90
#define GAME_OBJ_ID_MACHINE_GUNNER_BULLET	91
#define GAME_OBJ_ID_CANNON_SHOOTER_BULLET	92
#define GAME_OBJ_ID_BOSS_BULLET				93
// Misc >= 100, < 200
#define GAME_OBJ_ID_EXPLOSION				100
// Weapons >= 200, < 300
#define GAME_OBJ_ID_SWORD					200
#define GAME_OBJ_ID_SHURIKEN				210
#define GAME_OBJ_ID_WINDMILLSHURIKEN		220
#define GAME_OBJ_ID_FIREWHEEL               230
// Item >= 300, < 400
#define GAME_OBJ_ID_ITEM					300
#define GAME_OBJ_ID_BLUE_SPIRIT_POINT		310
#define GAME_OBJ_ID_RED_SPIRIT_POINT		320
#define GAME_OBJ_ID_BLUE_BONUS_DROP			330
#define GAME_OBJ_ID_RED_BONUS_DROP			340
#define GAME_OBJ_ID_FREEZE_DROP				350
#define GAME_OBJ_ID_HEALTH_DROP				360
#define GAME_OBJ_ID_SHURIKEN_DROP			370
#define GAME_OBJ_ID_WINDMILL_DROP			380
#define GAME_OBJ_ID_FIREWHEEL_DROP			390

// Utility
#define SIGN(K) K > 0 ? 1 : -1

//
//UI
//

//Font
#define GAME_FONT L"Resources\\UI\\font.ttf"
#define SPIRIT_SYMBOL L"Resources\\UI\\Spirit.png"
#define ITEM_SYMBOL L"Resources\\UI\\Items.png"
#define HP_SYMBOL L"Resources\\UI\\HP.bmp"
#define NOHP_SYMBOL L"Resources\\UI\\NOHP.bmp"
#define ITEM_FRAME_SYMBOL L"Resources\\UI\\ItemFrame.png"




//
//Sound
//

enum IDSound{
		SWORD,
		WINDMILL,
		SHURIKEN,
		TIMER,
		NINJA_HURT,
		MACHINE_GUNNER,
		NINJA_JUMP,
		ITEM_COLLECT,
		FIREWHEEL,
		ENEMYDESTROYED,
		CANNONSHOOTER,
		BOSS_JUMP,
		BOSS_DESTROYED,
		WINNING_TIMER,
		STAGE_31,
		STAGE_32,
		STAGE_33,
		GAME_OVER,
		PRESS_START,
		START
};

#define SOUND_PATH_SWORD "Resources\\Sound\\Effect\\Sword.wav"
#define SOUND_PATH_WINDMILL "Resources\\Sound\\Effect\\WindmillShuriken.wav"
#define SOUND_PATH_SHURIKEN "Resources\\Sound\\Effect\\Shuriken.wav"
#define SOUND_PATH_TIMER "Resources\\Sound\\Effect\\Timer.wav"
#define SOUND_PATH_NINJA_HURT "Resources\\Sound\\Effect\\NinjaHurt.wav"
#define SOUND_PATH_MACHINE_GUNNER "Resources\\Sound\\Effect\\MachineGunner.wav"
#define SOUND_PATH_NINJA_JUMP "Resources\\Sound\\Effect\\Jumping.wav"
#define SOUND_PATH_ITEM_COLLECT "Resources\\Sound\\Effect\\ItemCollecting.wav"
#define SOUND_PATH_FIREWHEEL "Resources\\Sound\\Effect\\FireWheel.wav"
#define SOUND_PATH_ENEMYDESTROYED "Resources\\Sound\\Effect\\EnemyHurt.wav"
#define SOUND_PATH_CANNONSHOOTER "Resources\\Sound\\Effect\\CannonShooter.wav"
#define SOUND_PATH_BOSS_JUMP "Resources\\Sound\\Effect\\BossJumping.wav"
#define SOUND_PATH_BOSS_DESTROYED "Resources\\Sound\\Effect\\BossDestroyed.wav"
#define SOUND_PATH_WINNING_TIMER "Resources\\Sound\\Effect\\WinningTimer.wav"
#define SOUND_PATH_STAGE_31 "Resources\\Sound\\Stage\\3-1 - Pursuit.wav"
#define SOUND_PATH_STAGE_32 "Resources\\Sound\\Stage\\3-2 - High Ground.wav"
#define SOUND_PATH_STAGE_33 "Resources\\Sound\\Stage\\3-3 Boss Battle.wav"
#define SOUND_PATH_GAME_OVER "Resources\\Sound\\Stage\\Over - All Gone (Game Over).wav"
#define SOUND_PATH_PRESS_START "Resources\\Sound\\Stage\\PressStart- Master Ninja Theme.wav"
#define SOUND_PATH_START "Resources\\Sound\\Stage\\Start - Title.wav"
