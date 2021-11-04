#pragma once
#include <string>
#include <ctime>
#include <math.h>

using namespace std;
using namespace sf;

Vector2f vectorNormalize(Vector2f vector, Vector2f vector2)
{
	float velocity = 1 / std::sqrt((abs((vector - vector2).x * 5) * abs((vector - vector2).x) * 5) + (abs((vector - vector2).y * 5) * abs((vector - vector2).y * 5)));
	return Vector2f(vector.x * velocity, vector.y * velocity);
}

class Entity {
public:
	static float posPlX;
	static float posPlY;
	static float posMouseX;
	static float posMouseY;

	float X, Y, moveTime;
	FloatRect rect;
	Sprite sprite;
	string name;
	bool life;
	int health;
	int damage;
	

	Entity(Texture &image, string Name, float x, float y) {
		life = true;
		sprite.setTexture(image);
		name = Name;
		X = x;
		Y = y;
		rect.left = X;
		rect.top = Y;
		sprite.setPosition(rect.left, rect.top);
		moveTime = 0;
	}

	
	virtual void update(float){}
};

float Entity::posMouseX = 0;
float Entity::posMouseY = 0;
float Entity::posPlX = 0;
float Entity::posPlY = 0;

class Player : public Entity
{
	float speedX;
	float speedY;
	
public:
	float speed;
	int playerScore;

	Player(Texture& image, string Name, float X, float Y):Entity(image, Name, X, Y) {
		playerScore = 0;
		health = 100;
		damage = 100;
		speed = 0.3f;
		sprite.setOrigin(50, 50);
		posMouseX = 0;
		posMouseY = 0;
		speedX = 0;
		speedY = 0;
	}
	void update(float time) {
		bool keyA = false;
		bool keyD = false;
		bool keyW = false;
		bool keyS = false;

		control(speedX, speedY, keyA, keyD, keyW, keyS);
		mouseControl();

		X = speedX*time;
		Y = speedY*time;
		rect.left += X; 
		rect.top += Y;
		if (rect.left > 1970) rect.left = -50;
		if (rect.left < -50) rect.left = 1970;
		if (rect.top > 1130) rect.top = -50;
		if (rect.top < -50) rect.top = 1130;

		sprite.setPosition(rect.left, rect.top);
		autoControl(speedX, speedY, keyA, keyD, keyW, keyS);

		string playerHealthString = to_string(health);		
	}
	void control(float& speedX, float& speedY, bool& keyA, bool& keyD, bool& keyW, bool& keyS) {
		//float speed = 0.3;
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			speedX = -speed;
			keyA = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			speedX = speed;
			keyD = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			speedY = -speed;
			keyW = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			speedY = speed;
			keyS = true;
		}
	}
	void autoControl(float& speedX, float& speedY, bool keyA, bool keyD, bool keyW, bool keyS) {
		if (keyA) {
			speedX = -0.09f;
		}
		if (keyD) {
			speedX = 0.09f;
		}
		if (keyS) {
			speedY = 0.09f;
		}
		if (keyW) {
			speedY = -0.09f;
		}
	}
	void mouseControl() {
		float dX = posMouseX - rect.left;//вектор , колинеарный прямой, которая пересекает спрайт и курсор
		float dY = posMouseY - rect.top;//он же, координата y
		float rotation = (atan2(dY, dX)) * 180 / 3.14159265f;//получаем угол в радианах и переводим его в градусы
		sprite.setRotation(rotation);//поворачиваем спрайт на эти градусы	
	}
};

class Enemy: public Entity
{
	
public:
	float speed;
	static float level;

	Enemy(Texture& image, string Name, float X, float Y) :Entity(image, Name, X, Y) {
		health = 100;
		if (level == 1) {
			speed = 0.2f;
			damage = 20;
		}
		else if (level == 2) {
			speed = 0.4f;
			damage = 25;
		}
		else {
			damage = 30;
			speed = 0.5f;
		}
		sprite.setOrigin(50, 50);
		sprite.setScale(0.7f, 0.7f);
	}
	void update(float Time) { 
		X = posPlX - rect.left;
		Y = posPlY - rect.top;
		float rotation = (atan2(Y, X)) * 180.f / 3.14159265f;
		sprite.setRotation(rotation);

		float distance = sqrt((posPlX - rect.left) * (posPlX - rect.left) + (posPlY - rect.top) * (posPlY - rect.top));
		if (distance > 1) {
			rect.left += speed * Time * (posPlX - rect.left) / distance;
			rect.top += speed * Time * (posPlY - rect.top) / distance;
		}
		else {
			rect.left += 0;
			rect.top += 0;
		}

		//rect.left += X * 0.0013f * Time;
	    //rect.top += Y * 0.0013f* Time;
		sprite.setPosition(rect.left, rect.top);
	}
};

float Enemy::level = 1;

class Bullet : public Entity {
public:
	int direction;
	float tempPosX;
	float tempPosY;
	Vector2f vect2f;

	Bullet (Texture& image, string Name, float x, float y, float tX, float tY) : Entity(image, Name, x, y){
		sprite.setOrigin(16, 9/2.f);
		direction = 0;
		tempPosX = tX;
		tempPosY = tY;
		X = tempPosX - rect.left;
		Y = tempPosY - rect.top;
		float angle = atan2(Y, X);
		float rotation = (angle) * 180.f / 3.14159265f;
		sprite.setRotation(rotation);
		vect2f = Vector2f(cos(angle) * 4, sin(angle) * 4);
	}
	void update( float Time){
		rect.left += vect2f.x;
		rect.top += vect2f.y;

		sprite.setPosition(rect.left, rect.top);
	}
};

class Boost {
public:
	FloatRect rect;
	Sprite sprite;
	string name;
	float boostSpeed;
	int boostheart;

	Boost(Texture& image, string _name) {
		rect.left = float(rand() % 1921);
		rect.top = float(rand() % 1081);
		sprite.setTexture(image);
		sprite.setScale(0.5f, 0.5f);
		sprite.setPosition(rect.left, rect.top);
		name = _name;
		if (name == "boost") boostSpeed = 0.05f;
		else boostSpeed = 0;

		if (name == "heart") boostheart = 30;
		else boostheart = 0;
	}

};