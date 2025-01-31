#include "Enemies.h"
#include "AIE.h"
#include "Singleton.h"

Enemies::Enemies()	{
	dir = -1;
	Singleton* globalManager = Singleton::GetInstance();
	speed = 200.f;
	width = 50;
	height = 50;
	leftExtreme = 0;
	x = leftExtreme + height * .5f;
	y = 800;
	rightExtreme = globalManager->screenWidth;
	bottomExtreme = 0 + height * .5f;
	topExtreme = 800;
	spriteID = CreateSprite("./images/yellowplane.png", width, height, true);
} 

Enemies::~Enemies()	{
	//DestroySprite(spriteID);
}

void Enemies::SetPosition(float a_x, float a_y){
	x = a_x;
	y = a_y;
}

void Enemies::SetSize(float a_width, float a_height){
	width = a_width;
	height = a_height;
}

void Enemies::SetMovementExtremes(float a_leftExtreme, float a_rightExtreme, float a_bottomExtreme, float a_topExtreme){
	leftExtreme = a_leftExtreme;
	rightExtreme = a_rightExtreme;
	bottomExtreme = a_bottomExtreme;
	topExtreme = a_topExtreme;
}

void Enemies::Movement(float a_deltaTime){

	if (y <= bottomExtreme)
	{
		y = bottomExtreme;
		dir *= -1;
		RotateSprite(spriteID, 180);
	}

	if (y >= topExtreme)
	{
		y = topExtreme;
		dir *= -1;
		RotateSprite(spriteID, 180);
	}
	y += speed * dir * a_deltaTime;

	MoveSprite(spriteID, x, y);
	DrawSprite(spriteID);
}

bool Enemies::Collide(){

	
	while (x - width * .5f <= player.x + player.width * .5f &&
		x + width * .5f >= player.x - player.width * .5f &&
		y - height * .5f <= player.y + player.height * .5f &&
		y + height * .5f >= player.y - player.height * .5f){
		return true;
	}
	return false;
}