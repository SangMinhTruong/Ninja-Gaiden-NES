#pragma once


//Tên ứng dụng
#define WINDOW_CLASS_NAME L"Ninja Gaiden"
#define MAIN_WINDOW_TITLE L"Ninja Gaiden"
//Màu background, kích cỡ màn hình
#define BACKGROUND_COLOR D3DCOLOR_XRGB(200, 200, 255)
#define SCREEN_WIDTH 313
#define SCREEN_HEIGHT 176

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
//Các số để chạy animation của Ninja
#define NINJA_ANI_IDLE					0
#define NINJA_ANI_WALKING 				1
#define NINJA_ANI_STANDING_ATTACKING 	2
#define NINJA_ANI_CROUCHING_ATTACKING 	3
#define NINJA_ANI_JUMPING 				4
#define NINJA_ANI_CROUCHING 			5
#define NINJA_ANI_HURT		 			6
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
#define ZOMBIE_ANI_STANDING_ATTACKING 		2
#define ZOMBIE_ANI_CROUCHING_ATTACKING		-1
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
#define MACHINE_GUNNER_ANI_STANDING_ATTACKING 		2
#define MACHINE_GUNNER_ANI_CROUCHING_ATTACKING		-1
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
//Explosion
//

#define EXPLOSION_TEXTURE_LOCATION L"Resources\\Misc\\Explosion.png"
#define EXPLOSION_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define EXPLOSION_TEXTURE_COLUMNS 3
#define EXPLOSION_TEXTURE_ROWS 1
#define EXPLOSION_SPRITE_WIDTH 48
#define EXPLOSION_SPRITE_HEIGHT 48

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
#define GAME_OBJ_ID_ZOMBIE_BULLET			90
#define GAME_OBJ_ID_MACHINE_GUNNER_BULLET	91
// Misc >= 100, < 200
#define GAME_OBJ_ID_EXPLOSION				100
// Weapons >= 200, < 300
#define GAME_OBJ_ID_SWORD					200

// Utility
#define SIGN(K) K > 0 ? 1 : -1