#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <vector>
#include "Player.h"
#include <Windows.h>
#include <ctime>
#include <fstream>

using namespace sf;
using namespace std;

const string FileScore = "Score.txt";

Music music;
SoundBuffer soundClickBuffer;
Sound soundClick;

Sprite fonMenu;
Sprite fonGame;

vector<int> vectorScore;
vector<int>::iterator itVect;

void writeFileScore() {
	ofstream fout(FileScore, ios::out);
	for (itVect = vectorScore.begin(); itVect != vectorScore.end(); itVect++)
	{
		cout << (*itVect) << endl;
		fout << (*itVect) << endl;
	}
	cout << endl;
	fout.close();
}
void readFileScore() {
	ifstream fin;
	fin.open(FileScore);
	vectorScore.clear();
	int i = 1;
	while (fin.peek() != EOF)
	{
		int num;
		fin >> num;
		vectorScore.push_back(num);
		if (i == 3) break;
		i++;
	}
	fin.close();
}

Vector2f vectorNormalize(Vector2f vector, Vector2f vector2);

list<Enemy*> listEnemy;
list<Enemy*> listBoomEnemy;
list<Enemy*>::iterator itEnemy;
list<Enemy*>::iterator itEnemy2;

list<Boost*> listBoost;
list<Boost*>::iterator itBoost;

list<Bullet*> listBullet;
list<Bullet*>::iterator itBullet;

int menuComplexity(RenderWindow& window) {
	Texture titelTexture, menuTexture1, menuTexture2, menuTexture3;
	titelTexture.loadFromFile("Sprite/slo.png");
	menuTexture1.loadFromFile("Sprite/easy.png");
	menuTexture2.loadFromFile("Sprite/norm.png");
	menuTexture3.loadFromFile("Sprite/nevos.png");
	Sprite titel(titelTexture),menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3);
	titel.setScale(2, 2);
	menu1.setScale(2, 2);
	menu2.setScale(2, 2);
	menu3.setScale(2, 2);
	bool isMenu = true;
	int menuNum = 0;
	titel.setPosition(660, 200);
	menu1.setPosition(770, 400);
	menu2.setPosition(770, 500);
	menu3.setPosition(770, 600);
	Sleep(100);
	while (isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		titel.setColor(Color::White);
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear();

		if (IntRect(800, 400, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Green); menuNum = 1; }
		else if (IntRect(800, 500, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Green); menuNum = 2; }
		else if (IntRect(800, 600, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Green); menuNum = 3; }
		else menuNum = 0;


		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) return menuNum;
			if (menuNum == 2) return menuNum;
			if (menuNum == 3) return menuNum;

		}

		window.draw(fonMenu);
		window.draw(titel);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
	return 0;
}

void menuScore(RenderWindow& window) {
	Texture menuTexture1, menuTexture2, titelTexture1, titelTexture2, titelTexture3, titelTexture4;
	menuTexture1.loadFromFile("Sprite/menu.png");
	menuTexture2.loadFromFile("Sprite/reset.png");
	titelTexture1.loadFromFile("Sprite/score.png");
	titelTexture2.loadFromFile("Sprite/easy.png");
	titelTexture3.loadFromFile("Sprite/norm.png");
	titelTexture4.loadFromFile("Sprite/nevos.png");
	Sprite menu1(menuTexture1), menuReset1(menuTexture2), menuReset2(menuTexture2), menuReset3(menuTexture2), titel1(titelTexture1), titel2(titelTexture2), titel3(titelTexture3), titel4(titelTexture4);
	menu1.setScale(2, 2);
	menuReset1.setScale(1.5, 1.5);
	menuReset2.setScale(1.5, 1.5);
	menuReset3.setScale(1.5, 1.5);
	titel1.setScale(2, 2);
	titel2.setScale(2, 2);
	titel3.setScale(2, 2);
	titel4.setScale(2, 2);
	bool isMenu = true;
	int menuNum = 0;
	menu1.setPosition(720, 600);
	menuReset1.setPosition(1100, 300);
	menuReset2.setPosition(1100, 400);
	menuReset3.setPosition(1100, 500);

	titel1.setPosition(720, 200);
	titel2.setPosition(450, 300);
	titel3.setPosition(450, 400);
	titel4.setPosition(450, 500);

	Font font;
	font.loadFromFile("Sprite/arial.ttf");
	sf::String stringScore = L"";
	Text textScoreEasy(stringScore, font, 36);
	Text textScoreNorm(stringScore, font, 36);
	Text textScoreHard(stringScore, font, 36);
	textScoreEasy.setPosition(900, 320);
	textScoreNorm.setPosition(900, 420);
	textScoreHard.setPosition(900, 520);

	textScoreEasy.setStyle(1);
	textScoreNorm.setStyle(1);
	textScoreHard.setStyle(1);

	while (isMenu)
	{
		//read();
		textScoreEasy.setString(to_string(vectorScore[0]));
		textScoreNorm.setString(to_string(vectorScore[1]));
		textScoreHard.setString(to_string(vectorScore[2]));

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		menu1.setColor(Color::White);
		menuReset1.setColor(Color::White);
		menuReset2.setColor(Color::White);
		menuReset3.setColor(Color::White);

		titel1.setColor(Color::White);
		menuNum = 0;
		window.clear();


		if (IntRect(720, 600, 320, 80).contains(Mouse::getPosition(window))) {
			menu1.setColor(Color::Green);
			menuNum = 1;

		}
		else if (IntRect(1100, 300, 220, 80).contains(Mouse::getPosition(window))) {
			menuReset1.setColor(Color::Green);
			menuNum = 2;
		}
		else if (IntRect(1100, 400, 220, 80).contains(Mouse::getPosition(window))) {
			menuReset2.setColor(Color::Green);
			menuNum = 3;
		}
		else if (IntRect(1100, 500, 220, 80).contains(Mouse::getPosition(window))) {
			menuReset3.setColor(Color::Green);
			menuNum = 4;
		}
		else menuNum = 0;

		if (Mouse::isButtonPressed(Mouse::Left))
		{

			if (menuNum == 1) {
				soundClick.play();
				isMenu = false;
			}
			if (menuNum == 2) {
				vectorScore[0] = 0;
				writeFileScore();
			}
			if (menuNum == 3) {
				vectorScore[1] = 0;
				writeFileScore();
			}
			if (menuNum == 4) {
				vectorScore[2] = 0;
				writeFileScore();
			}
		}
		window.draw(fonMenu);
		window.draw(menu1);
		window.draw(menuReset1);
		window.draw(menuReset2);
		window.draw(menuReset3);
		window.draw(titel1);
		window.draw(titel2);
		window.draw(titel3);
		window.draw(titel4);
		window.draw(textScoreEasy);
		window.draw(textScoreNorm);
		window.draw(textScoreHard);

		window.display();
	}
}

void menu(RenderWindow& window) {
	Texture menuTexture1, menuTexture2, menuTexture3, titelUploadTexture;
	menuTexture1.loadFromFile("Sprite/newGame.png");
	menuTexture2.loadFromFile("Sprite/exit.png");
	menuTexture3.loadFromFile("Sprite/score.png");
	titelUploadTexture.loadFromFile("Sprite/upload.png");

	Sprite menuNewGame(menuTexture1), menuExit(menuTexture2), menuRecord(menuTexture3), titelUpload(titelUploadTexture);
	menuNewGame.setScale(2, 2);
	menuExit.setScale(2, 2);
	menuRecord.setScale(2, 2);
	titelUpload.setScale(2, 2);

	bool isMenu = true;
	int menuNum = 0;
	menuNewGame.setPosition(760, 300);
	menuRecord.setPosition(750, 400);
	menuExit.setPosition(810, 500);
	titelUpload.setPosition(760,300);

	while (isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		menuNewGame.setColor(Color::White);
		menuExit.setColor(Color::White);
		menuRecord.setColor(Color::White);

		menuNum = 0;
		window.clear();


		if (IntRect(760, 300, 330, 80).contains(Mouse::getPosition(window))) { 
			menuNewGame.setColor(Color::Green);
			menuNum = 1;
		
		}
		else if (IntRect(820, 500, 210, 80).contains(Mouse::getPosition(window))) {
			menuExit.setColor(Color::Green);
			menuNum = 2;
		}
		else if (IntRect(780, 400, 270, 80).contains(Mouse::getPosition(window))) {
			menuRecord.setColor(Color::Green);
			menuNum = 3;
		}
		else menuNum = 0;

		if (Mouse::isButtonPressed(Mouse::Left))
		{

			if (menuNum == 1) {
				soundClick.play();
				window.clear();
				int num = menuComplexity(window);
				if(num == 1){
					soundClick.play();
					Enemy::level = 1;
					window.clear();
					window.draw(titelUpload);
					window.display();
					music.stop();
					break;
				}
				else if(num == 2)
				{
					soundClick.play();
					Enemy::level = 2;
					window.clear();
					window.draw(titelUpload);
					window.display();
					music.stop();
					break;
				}
				else if (num == 3)
				{
					soundClick.play();
					Enemy::level = 3;
					window.clear();
					window.draw(titelUpload);
					window.display();
					music.stop();
					break;
				}
			} 

			if (menuNum == 3) {
				soundClick.play();
				menuScore(window);
			}
			if (menuNum == 2) { 
				soundClick.play();
				music.stop();
				window.close();  
				isMenu = false; 
			}
		}
		window.draw(fonMenu);
		window.draw(menuNewGame);
		window.draw(menuExit);
		window.draw(menuRecord);
	
		window.display();
	}
}

int menuGameOver(RenderWindow& window, int score) {
	music.play();
	Texture titelTexture, titelTexture2, menuTexture1, menuTexture2;
	titelTexture2.loadFromFile("Sprite/shet.png");
	titelTexture.loadFromFile("Sprite/gameOver.png");
	menuTexture1.loadFromFile("Sprite/menu.png");
	menuTexture2.loadFromFile("Sprite/restart.png");
	Sprite titel(titelTexture), menu1(menuTexture1), menu2(menuTexture2), titel2(titelTexture2);
	titel.setScale(2, 2);
	titel2.setScale(2, 2);
	menu1.setScale(2, 2);
	menu2.setScale(2, 2);
	bool isMenu = true;
	int menuNum = 0;
	titel.setPosition(700, 200);
	titel2.setPosition(600, 300);
	menu1.setPosition(550, 400);
	menu2.setPosition(870, 400);

	Font font;
	font.loadFromFile("Sprite/arial.ttf");
	sf::String stringScore = L"";
	Text textScore(stringScore, font, 36);
	textScore.setStyle(1);

	textScore.setPosition(1000, 320);
	Sleep(200);
	while (isMenu)
	{
		textScore.setString(to_string(score));

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		titel.setColor(Color::White);
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menuNum = 0;
		window.clear();

		if (IntRect(550, 400, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Green); menuNum = 1; }
		if (IntRect(870, 400, 350, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Green); menuNum = 2; }


		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {
				soundClick.play();
				return menuNum;
			}
			if (menuNum == 2) {
				soundClick.play();
				return menuNum;
			}

		}
		window.draw(fonMenu);
		window.draw(titel);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(titel2);
		window.draw(textScore);

		window.display();
	}
	return 0;
}

int Game(RenderWindow& window);

void CreatFileScore() {
	ifstream file;
	file.open(FileScore);
	if (!file) {
		cout << "‘айл с именем " << FileScore << " создан" << endl;
		ofstream fout(FileScore, ios::out);
		vectorScore.push_back(0);
		vectorScore.push_back(0);
		vectorScore.push_back(0);
		for (itVect = vectorScore.begin(); itVect != vectorScore.end(); itVect++)
		{
			fout << (*itVect) << endl;
		}
		fout.close();
	}
	file.close();
}

int main()
{
	setlocale(0, "rus");
	srand(time(0));

	CreatFileScore();
	readFileScore();

	soundClickBuffer.loadFromFile("Sound/click.ogg");
	soundClick.setBuffer(soundClickBuffer);

	RenderWindow window(VideoMode(1920, 1080), "Star Wars");
	
	Image icon;
	icon.loadFromFile("Sprite/icon.png");
	window.setIcon(600,700,icon.getPixelsPtr());

	Texture fonMenuTexture;
	fonMenuTexture.loadFromFile("Sprite/fon2.png");
	Texture fonGameTexture;
	fonGameTexture.loadFromFile("Sprite/fonGame.png");

	fonGame.setTexture(fonGameTexture);
	fonGame.setPosition(0, 0);

	fonMenu.setTexture(fonMenuTexture);
	fonMenu.setPosition(0, 0);

	music.openFromFile("Sound/music.ogg");
	music.play();

	menu(window);
	bool flag = true;
	while (flag) {
	int num = Game(window);
	if (num == 2) {
		continue;
	}else {
		menu(window);
	}
	}
	return 0;
}

int Game(RenderWindow& window) {
	Texture textureRocket, enemy1, enemy2, bullet, boom, boost, heart, hp20Tex, hp50Tex, boomPlTex;
	Texture ultaTexture;
	ultaTexture.loadFromFile("Sprite/ulta2.png");
	Sprite ulta(ultaTexture), indicatorUlta(ultaTexture);
	ulta.setPosition(-100, -100);
	ulta.setOrigin(50, 50);
	ulta.setScale(7, 7);

	indicatorUlta.setScale(0.6f, 0.6f);
	indicatorUlta.setPosition(30, 90);

	boomPlTex.loadFromFile("Sprite/BoomPl.png");

	hp20Tex.loadFromFile("Sprite/20hp.png");
	hp50Tex.loadFromFile("Sprite/50hp.png");

	textureRocket.loadFromFile("Sprite/123.png");
	enemy1.loadFromFile("Sprite/enemy0.png");
	enemy2.loadFromFile("Sprite/enemy02.png");
	bullet.loadFromFile("Sprite/bullet.png");
	boom.loadFromFile("Sprite/boom.png");
	boost.loadFromFile("Sprite/boost.png");
	heart.loadFromFile("Sprite/heart.png");

	Player player(textureRocket, "Player", 960, 200);

	SoundBuffer shootBuffer, killBuffer, lootBuffer, kiillPlayerBuffer, ultaBuffer;
	ultaBuffer.loadFromFile("Sound/ulta.ogg");
	killBuffer.loadFromFile("Sound/kill.ogg");
	shootBuffer.loadFromFile("Sound/shoot.ogg");
	lootBuffer.loadFromFile("Sound/loot.wav");
	kiillPlayerBuffer.loadFromFile("Sound/killPlayer.wav");

	Sound shootSound(shootBuffer), killSound(killBuffer), lootSound(lootBuffer), killPlayerSound(kiillPlayerBuffer), ultaSound(ultaBuffer);

	Clock clock;

	float shootTimer = 0;
	float spawnTimer = 0;
	float timeBoom = 0;
	float timeBoost = 0;
	float timeDelBoost = 0;
	float blockTimeShoot = 400;
	float enemyTimer = 0;

	float timeUlta = 9001;
	bool boolUltaDel = false;
	float timeUltaDel = 0;

	int countEnemy = 5;
	
	Texture hpTexture;
	hpTexture.loadFromFile("Sprite/HP.png");
	Sprite HP(hpTexture);
	HP.setPosition(30, 20);
	HP.setScale(0.6f, 0.6f);

	Font font;
	font.loadFromFile("Sprite/arial.ttf");
	sf::String string1 = L"";
	Text text(string1, font, 36);
	text.setStyle(1);
	text.setPosition(100, 20);

	sf::String stringScore = L"—чет: ";
	Text textScore(stringScore, font, 36);
	textScore.setPosition(1520, 20);
	textScore.setStyle(1);
	

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 1000;

		timeBoom += time;
		if (timeBoom < 600) {
			timeBoom++;
		}
		if (timeBoom >= 600) {
			listBoomEnemy.clear();
			timeBoom = 0;
		}

		timeBoost += time;
		if (timeBoost < 3000) {
			timeBoost++;
		}
		if (timeBoost >= 3000) {
			int choice = rand() % 2;
			if (choice == 0) {
				listBoost.push_back(new Boost(boost,"boost"));
			}
			else {
				listBoost.push_back(new Boost(heart, "heart"));

			}
			timeBoost = 0;
		}

		timeDelBoost += time;
		if (timeDelBoost < 15000) {
			timeDelBoost++;
		}
		if (timeDelBoost >= 15000) {
			listBoost.clear();
			timeDelBoost = 0;
		}

		itBoost = listBoost.begin();
		while (itBoost != listBoost.end())
		{
			if ((*itBoost)->sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds())) {
				lootSound.play();
				if ((*itBoost)->name == "boost") {
					player.speed += (*itBoost)->boostSpeed;
					blockTimeShoot -= 20;
				}
				else {
					player.health += (*itBoost)->boostheart;
				}
				itBoost = listBoost.erase(itBoost);
			}
			else {
				itBoost++;
			}
		}

		text.setString(string1 + to_string(player.health));
		textScore.setString(stringScore + to_string(player.playerScore));

		Vector2i pixelPos = Mouse::getPosition(window);

		Entity::posPlX = player.sprite.getPosition().x;
		Entity::posPlY = player.sprite.getPosition().y;
		Entity::posMouseX = window.mapPixelToCoords(pixelPos).x;
		Entity::posMouseY = window.mapPixelToCoords(pixelPos).y;

		

		enemyTimer += time;
		if (enemyTimer < 25000) {
			enemyTimer++;
		}
		if (enemyTimer >= 25000) {
			countEnemy += 2;
			enemyTimer = 0;
		}

		spawnTimer += time;
		if (spawnTimer < 3000) {
			spawnTimer++;
		}
		if (spawnTimer >= 3000) {
			for (int i = 0; i < countEnemy; i++) {
				int choice = rand() % 2;
				if (choice == 0) {
					int choiceCord = rand() % 4;
					if (choiceCord == 0) {
						listEnemy.push_back(new Enemy(enemy1, "EasyEnemy", -1.f, float(rand() % 1081)));
					}
					else if(choiceCord == 1){
						listEnemy.push_back(new Enemy(enemy1, "EasyEnemy", 1921.f, float(rand() % 1081)));
					}
					else if (choiceCord == 2) {
						listEnemy.push_back(new Enemy(enemy1, "EasyEnemy", float(rand() % 1921), -1.f));
					}
					else if (choiceCord == 3) {
						listEnemy.push_back(new Enemy(enemy1, "EasyEnemy", float(rand() % 1921), 1081.f));
					}
				}
				else {
					int choiceCord = rand() % 4;
					if (choiceCord == 0) {
						listEnemy.push_back(new Enemy(enemy2, "HardEnemy", -1.f, float(rand() % 1081)));
					}
					else if (choiceCord == 1) {
						listEnemy.push_back(new Enemy(enemy2, "HardEnemy", 1921.f, float(rand() % 1081)));
					}
					else if (choiceCord == 2) {
						listEnemy.push_back(new Enemy(enemy2, "HardEnemy", float(rand() % 1921), -1.f));
					}
					else if (choiceCord == 3) {
						listEnemy.push_back(new Enemy(enemy2, "HardEnemy", float(rand() % 1921), 1081.f));
					}

				}
			}
			spawnTimer = 0;
		}
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		player.update(time);

		for (itEnemy = listEnemy.begin(); itEnemy != listEnemy.end(); itEnemy++)
		{
			(*itEnemy)->update(time);
		}
		for (itBullet = listBullet.begin(); itBullet != listBullet.end(); itBullet++)
		{
			(*itBullet)->update(time);
		}

		shootTimer += time;
		if (shootTimer < blockTimeShoot) {
			shootTimer++;
		}
		if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= blockTimeShoot) {
			listBullet.push_back(new Bullet(bullet, "Bullet", player.sprite.getPosition().x, player.sprite.getPosition().y, window.mapPixelToCoords(pixelPos).x, window.mapPixelToCoords(pixelPos).y));

			shootSound.play();
			shootTimer = 0;
		}
//////////////////////////////////
		timeUlta += time;
		if (timeUlta < 9000) {
			timeUlta++;
		}
		if (Mouse::isButtonPressed(Mouse::Right) && timeUlta >= 9000) {
			boolUltaDel = true;
			ulta.setPosition(player.sprite.getPosition().x, player.sprite.getPosition().y);
			ultaSound.play();
			timeUlta = 0;
		}

////////////////////////////////////
		itBullet = listBullet.begin();
		while (itBullet != listBullet.end())
		{
			bool del = false;

			itEnemy = listEnemy.begin();
			while (itEnemy != listEnemy.end())
			{
				if ((*itBullet)->sprite.getGlobalBounds().intersects((*itEnemy)->sprite.getGlobalBounds())) {
					listBoomEnemy.push_back((*itEnemy));
					killSound.play();
					itEnemy = listEnemy.erase(itEnemy);
					player.playerScore += 20;
					del = true;
					break;
				}
				else {
					itEnemy++;
				}
			}

			if (((*itBullet)->sprite.getPosition().x > 1920 || (*itBullet)->sprite.getPosition().x < 0) || ((*itBullet)->sprite.getPosition().y > 1080 || (*itBullet)->sprite.getPosition().y < 0) || del == true) {
				itBullet = listBullet.erase(itBullet);
			}
			else {
				itBullet++;
			}
		}

		itEnemy = listEnemy.begin();
		while (itEnemy != listEnemy.end())
		{
			FloatRect rectPl = player.sprite.getGlobalBounds();
			rectPl.left -= 10;
			rectPl.top += 10;
			rectPl.width = 75;
			rectPl.height = 70;
			//if ((*itEnemy)->sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds())) {
			if ((*itEnemy)->sprite.getGlobalBounds().intersects(rectPl)) {
				killSound.play();
				listBoomEnemy.push_back((*itEnemy));
				player.health -= (*itEnemy)->damage;
				itEnemy = listEnemy.erase(itEnemy);
				if (player.health <= 20) {
					player.sprite.setTexture(hp20Tex);
				}
				else if (player.health <= 50) {
					player.sprite.setTexture(hp50Tex);
				}
				else  if (player.health >= 50) {
					player.sprite.setTexture(textureRocket);
				}

				if (player.health <= 0) {
					player.sprite.setTexture(boomPlTex);
					window.draw(player.sprite);
					window.display();

					killPlayerSound.play();
					if (vectorScore[Enemy::level - 1] < player.playerScore) {
						vectorScore[Enemy::level - 1] = player.playerScore;
					}
					writeFileScore();
					listEnemy.clear();
					listBullet.clear();
					listBoomEnemy.clear();
					listBoost.clear();

					return menuGameOver(window, player.playerScore);
				}
			}
			else {
				itEnemy++;
			}
		}

		for (itEnemy = listBoomEnemy.begin(); itEnemy != listBoomEnemy.end(); itEnemy++)
		{
			(*itEnemy)->speed = 0;
			(*itEnemy)->sprite.setTexture(boom);
			(*itEnemy)->update(time);
		}

		if (boolUltaDel) {
		itEnemy = listEnemy.begin();
		while (itEnemy != listEnemy.end())
		{
			if (ulta.getGlobalBounds().intersects((*itEnemy)->sprite.getGlobalBounds())) {
				listBoomEnemy.push_back((*itEnemy));
				killSound.play();
				itEnemy = listEnemy.erase(itEnemy);
				player.playerScore += 20;
			}
			else {
				itEnemy++;
			}
		}
		}

		window.clear();
		window.draw(fonGame);
		////////////
		timeUltaDel += time;
		if (timeUltaDel < 1000) {
			timeUltaDel++;
		}
		if (boolUltaDel && timeUltaDel <= 1000) {
			window.draw(ulta);
		}
		else {
			boolUltaDel = false;
			timeUltaDel = 0;
		}
		//////////////
		for (itBoost = listBoost.begin(); itBoost != listBoost.end(); itBoost++)
		{
			window.draw((*itBoost)->sprite);
		}
		for (itEnemy = listEnemy.begin(); itEnemy != listEnemy.end(); itEnemy++)
		{
			window.draw((*itEnemy)->sprite);
		}
		for (itBullet = listBullet.begin(); itBullet != listBullet.end(); itBullet++)
		{
			window.draw((*itBullet)->sprite);
		}
		for (itEnemy = listBoomEnemy.begin(); itEnemy != listBoomEnemy.end(); itEnemy++)
		{
			window.draw((*itEnemy)->sprite);
		}

		window.draw(player.sprite);
		
		

		window.draw(text);
		window.draw(textScore);
		window.draw(HP);
		if (timeUlta >= 9000) {
			window.draw(indicatorUlta);
		}

		window.display();
	}
	return 0;
}