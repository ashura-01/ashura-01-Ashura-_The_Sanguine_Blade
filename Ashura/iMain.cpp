#include "Resources.h"
#include "Character.h"
#include <ctime>
#include <fstream>

#include <map>
#include <thread> 

#pragma comment(lib, "winmm.lib")
#include <windows.h>
#include <mmsystem.h>
#include <iostream>

//#include"backend.h"

using namespace std;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Variables Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://



Character hero;
Boss boss;
RagnaBoss ragna;

MedusaBoss medusa;
ArakuneBoss arak;


Mobs mob2(1000, STAND_B, 0, 2000, 0, 1, true, false); // Uses provided values
Mobs mob3(1000, STAND_B, 0, 1800, 0, 1, true, false); // Uses provided values
Mobs mob4(1000, STAND_B, 0, 1200, 0, 1, true, false); // Uses provided values;

TagerMobs tager1(1000, STAND_B, 0, 2000, 0, 1, true, false);
TagerMobs tager2(1000, STAND_B, 0, 1800, 0, 1, true, false);
TagerMobs tager3(1000, STAND_B, 0, 1200, 0, 1, true, false); // Uses provided values;

//level3 exclusive
Mobs mob1(1000, STAND_B, 0, 1800, 0, 1, true, false);
Mobs mob(1000, STAND_B, 0, 2000, 0, 1, true, false);

TagerMobs tager(1000, STAND_B, 0, 1200, 0, 1, true, false);
TagerMobs tager4(1000, STAND_B, 0, 1500, 0, 1, true, false);


/////////////////// mob \\\\\\\\\\\\\\\\\

int mob1_adjust = 0;
int mob2_adjust = 0;
int mob3_adjust = 0;
int mob4_adjust = 0;


bool mob2_dead = false;
bool mob3_dead = false;
bool mob4_dead = false;

bool tager1Dead = false;
bool tager2Dead = false;
bool tager3Dead = false;

// level exclusive




int flag = 1;

int ragnaFlag = 1;

int mobNumber = 3;

int tagerNumber = 3;

//level 3 essentials

int mob_adjust = 0;


bool mob_dead = false;
bool mob1_dead = false;
bool tagerDead = false;
bool tager4Dead = false;


int level3MobCount = 4;


int morphFlag = 1;
int openingFlag = 1;
int mobOutFlag = 1;
int level3Pic = 4;

//end





int amplify = 0;
int increment = 0;

int samplify = 0;
int sincrement = 0;


//10:14 3/3//
int ragna_H_adjust = 0;
int ragna_w_adjust = 0;

int ragna_y_adjust = 0;




// Maximum health values for hero and boss
const int heroMaxHealth = 10000;  // Hero's max health
const int bossMaxHealth = 15000;  // Boss's max health

// Maximum width for the health bars (different for hero and boss)
const int heroMaxBarWidth = 2600;  // Hero's health bar max width
const int bossMaxBarWidth = 3850;  // Boss's health bar max width


int bgx = 0;
int bgHelper = -500;

int levelPic = 0;
int level2Pic = 2;

int maxHp = hero.hp;
int bmaxHp = boss.hp;

// global variables for file io

bool showSlides = true;

/*
	bool level2Unlocked = false;
	bool level3Unlocked = false;

*/

// newly added

int tagY = 0;
int tag1Y = 0;

int tag2Y = 0;
int tag3Y = 0;

int tag4Y = 0;




// ==================================================== file io ===========================================================//

void readValuesFromFile(bool &showSlides, bool &level2Unlocked, bool &level3Unlocked) {

	ifstream file("game_settings.txt");

	if (!file) {
		cerr << "Error opening file!" << endl;
		return;
	}

	int s, l2, l3;  // Temporary integer variables to store 0 or 1
	file >> s >> l2 >> l3;

	showSlides = (s != 0);
	level2Unlocked = (l2 != 0);
	level3Unlocked = (l3 != 0);

	file.close();
}

// Function to write boolean values to the file
void writeValuesToFile(bool showSlides, bool level2Unlocked, bool level3Unlocked) {
    ofstream file("game_settings.txt");

    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    file << showSlides << endl;
    file << level2Unlocked << endl;
    file << level3Unlocked << endl;

    file.close();
}




// ====================================================== file io end =======================================================//



//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

clock_t deathTime = 0;


void drawHealthBars3(Character hero, MedusaBoss boss);
void drawHealthBars4(Character hero, ArakuneBoss boss);



void resetLevelThree(){

	//hero
	hero.hp = 1000; hero.modelState = STAND_B; hero.modelIndex = 0; hero.moveX = 100; hero.moveY = 0; hero.modelCount = 0; hero.alive = true;

	//medusa
	medusa.hp = 1000; medusa.modelState = STAND_B; medusa.modelIndex = 0; medusa.moveX = 2000; medusa.moveY = 0; medusa.modelCount = 0; medusa.alive = true; medusa.isFollow = false;
	morphFlag = 1;
	openingFlag = 1;
	mobOutFlag = 1;

	//arakune
	arak.hp = 1000; arak.modelState = STAND_B; arak.modelIndex = 0; arak.moveX = 2000; arak.moveY = 0; arak.modelCount = 0; arak.alive = true; arak.isFollow = false;

	//mobs
	level3MobCount = 4;
	mob_dead = false;
	mob1_dead = false;

	mob.hp = 1000; mob.modelState = STAND_B; mob.modelIndex = 0; mob.moveX = 2000; mob.moveY = 0; mob.modelCount = 0; mob.alive = true; mob.isFollow = false;
	mob1.hp = 1000; mob1.modelState = STAND_B; mob1.modelIndex = 0; mob1.moveX = 1800; mob1.moveY = 0; mob1.modelCount = 0; mob1.alive = true; mob1.isFollow = false;

	tagerDead = false;
	tager4Dead = false;


	tager.hp = 1000; tager.modelState = STAND_B; tager.modelIndex = 0; tager.moveX = 1200; tager.moveY = 0; tager.modelCount = 0; tager.alive = true; tager.isFollow = false;
	tager4.hp = 1000; tager4.modelState = STAND_B; tager4.modelIndex = 0; tager4.moveX = 1500; tager4.moveY = 0; tager4.modelCount = 0; tager4.alive = true; tager4.isFollow = false;
	
	//ui

	level3Pic = 4;
	bgx = 0;
	bgHelper = -500;

}


void resetLevelOne(){
	
	//hero
	hero.hp = 1000;
	hero.modelState = STAND_B;
	hero.modelIndex = 0;
	hero.moveX = 100;
	hero.moveY = 0;
	hero.modelCount = 0;
	hero.alive = true;

	//boss
	boss.hp = 1000;
	boss.modelState = STAND_B;
	boss.modelIndex = 0;
	boss.moveX = 2000;
	boss.moveY = 0;
	boss.modelCount = 0;
	boss.alive = true;
	boss.isFollow = false;
	flag = 1;

	//mob
	mobNumber = 3;
	mob2_dead = false;
	mob3_dead = false;
	mob4_dead = false;

	mob2.hp = 1000; mob2.modelState = STAND_B; mob2.modelIndex = 0; mob2.moveX = 2000; mob2.moveY = 0; mob2.modelCount = 0; mob2.alive = true; mob2.isFollow = false;

	mob3.hp = 1000; mob3.modelState = STAND_B; mob3.modelIndex = 0; mob3.moveX = 1800; mob3.moveY = 0; mob3.modelCount = 0; mob3.alive = true; mob3.isFollow = false;

	mob4.hp = 1000; mob4.modelState = STAND_B; mob4.modelIndex = 0; mob4.moveX = 1200; mob4.moveY = 0; mob4.modelCount = 0; mob4.alive = true; mob4.isFollow = false;

	//ui
	levelPic = 0; 
	bgx = 0;
	bgHelper = -500;




}


int medusa_Y_adjust = 0;
int medusa_H_adjust = 0;
int medusa_W_adjust = 0;

void resetLevelTwo(){


	//hero
	hero.hp = 1000;
	hero.modelState = STAND_B;
	hero.modelIndex = 0;
	hero.moveX = 100;
	hero.moveY = 0;
	hero.modelCount = 0;
	hero.alive = true;

	//ragna
	ragna.hp = 1000;
	ragna.modelState = STAND_B;
	ragna.modelIndex = 0;
	ragna.moveX = 2000;
	ragna.moveY = 0;
	ragna.modelCount = 1;
	ragna.alive = true;
	ragna.isFollow = false;
	ragnaFlag = 1;

	//tager
	tagerNumber = 3;
	tager1Dead = false;
	tager2Dead = false;
	tager3Dead = false;

	tager1.hp = 1000; tager1.modelState = STAND_B; tager1.modelIndex = 0; tager1.moveX = 2000; tager1.moveY = 0; tager1.modelCount = 0; tager1.alive = true; tager1.isFollow = false;
	tager2.hp = 1000; tager2.modelState = STAND_B; tager2.modelIndex = 0; tager2.moveX = 1200; tager2.moveY = 0; tager2.modelCount = 0; tager2.alive = true; tager2.isFollow = false;
	tager3.hp = 1000; tager3.modelState = STAND_B; tager3.modelIndex = 0; tager3.moveX = 1800; tager3.moveY = 0; tager3.modelCount = 0; tager3.alive = true; tager3.isFollow = false;


	//ui

	level2Pic = 2;
	bgx = 0;
	bgHelper = -500;
}

// hp bar test for mob //

void testDrawHealthBars(Character hero)
{
	// Scale the hero's and boss's health to fit the respective health bar widths
	int heroHealthBarWidth = (hero.hp * heroMaxBarWidth) / heroMaxHealth;
	int bossHealthBarWidth = (boss.hp * bossMaxBarWidth) / bossMaxHealth;

	// **Hero Health Bar**
	if (hero.hp < (maxHp / 2))
	{
		iSetColor(255, 0, 0);
	}
	else
	{
		iSetColor(0, 255, 0);
	}
	iFilledRectangle(106, 956, heroHealthBarWidth, 7);

	
}

int tester = 1;




void showLevelThree_1(){

	//level 1 mobs
	mob_adjust = (mob.modelIndex == 128) ? 180 : 0;
	mob1_adjust = (mob1.modelIndex == 128) ? 180 : 0;


	iShowImage(mob.moveX, 320, 300, 300 - mob_adjust, mob.model[mob.modelIndex]);
	iShowImage(mob1.moveX, 320, 300, 300 - mob1_adjust, mob1.model[mob1.modelIndex]);


	if (mob.hp == 0 && !mob_dead) {
		level3MobCount--;
		mob_dead = true;
	}
	if (mob1.hp == 0 && !mob1_dead) {
		level3MobCount--;
		mob1_dead = true;
	}
	iShowImage(1480, 880, 400, 100, healthBar[2]); // mob bar

	iSetColor(255, 255, 255);
	string num = to_string(level3MobCount); // Convert number to string
	iText(1732, 945, (char*)num.c_str(), GLUT_BITMAP_TIMES_ROMAN_24);

	//level 2 mobs

	mob_adjust = (mob.modelIndex == 128) ? 180 : 0;

	if (tager.modelIndex == 102 || tager.modelIndex == 109 )
	{
		tagY = 80;
	}
	else if (tager4.modelIndex == 102 || tager4.modelIndex == 109)
	{
		tag4Y = 80;
	}

	else
	{
		tagY = 0;
		tag4Y = 0;
	}

	iShowImage(tager.moveX, 320-tagY, 300, 300 - mob_adjust, tager.model[tager.modelIndex]);
	iShowImage(tager4.moveX, 320-tag4Y, 300, 300 - mob_adjust, tager4.model[tager4.modelIndex]);


	//iShowImage(1480, 880, 400, 100, tager3.model[110]);

	if (tager.hp == 0 && !tagerDead) {
		level3MobCount--;
		tagerDead = true;
	}
	if (tager4.hp == 0 && !tager4Dead) {
		level3MobCount--;
		tager4Dead = true;
	}
	/*
	
		iShowImage(1480, 700, 400, 100, tager.model[110]); //  tager mob bar

		iSetColor(255, 255, 255);
		string num2 = to_string(level3MobCount); // Convert number to string
		iText(1732, 745, (char*)num2.c_str(), GLUT_BITMAP_TIMES_ROMAN_24);
	*/

	// end


	


}

void showLevelThree_2(){


	if (medusa.hp > 0){
		iShowImage(1510, 880, 400, 100, healthBar[0]);
		drawHealthBars3(hero, medusa);
	}
	else{
		iShowImage(1510, 880, 400, 100, healthBar[1]);
		drawHealthBars4(hero, arak);
	}

	if (medusa.hp <= 0 && morphFlag == 1){
		medusa.isFollow = false;
		arak.moveX = medusa.moveX;
		arak.isFollow = true;
		morphFlag = 0;

	}
	else if (arak.isFollow == true)
	{
		iShowImage(arak.moveX, 320, 300, 300, arak.model[arak.modelIndex]);
		if (openingFlag == 1){
			arak.modelState = STARTING;
			if (arak.modelIndex == 190){
				openingFlag = 0;
			}
		}
	}
	else{

		if (medusa.modelIndex == 186 || medusa.modelIndex == 195)
		{
			medusa_H_adjust = 100;
			medusa_W_adjust = 100;
			medusa_Y_adjust = 80;
		}
		else
		{
			medusa_H_adjust = 0;
			medusa_W_adjust = 0;
			medusa_Y_adjust = 0;
		}

		iShowImage(medusa.moveX, 320 - medusa_Y_adjust, 280 + medusa_W_adjust, 280 - medusa_H_adjust, medusa.model[medusa.modelIndex]);

	}

}

void showLevelTwo_1(){
	//iShowImage(bgHelper + bgx, -50, 3800, 1080, levelImg[2]);

	//iShowImage(hero.moveX, 320, 250, 250, hero.model[hero.modelIndex]);
	mob2_adjust = (mob2.modelIndex == 128) ? 180 : 0;
	mob3_adjust = (mob3.modelIndex == 128) ? 180 : 0;
	mob4_adjust = (mob4.modelIndex == 128) ? 180 : 0;

	if (tager1.modelIndex == 102 || tager1.modelIndex == 109)
	{
		tag1Y = 80;
	}
	else if (tager2.modelIndex == 102 || tager2.modelIndex == 109)
	{
		tag2Y = 80;
	}
	else if (tager3.modelIndex == 102 || tager3.modelIndex == 109)
	{
		tag3Y = 80;
	}
	else
	{
		tag1Y = 0;
		tag2Y = 0;
		tag3Y = 0;
	}
	iShowImage(tager1.moveX, 320-tag1Y, 300, 300 - mob2_adjust, tager1.model[tager1.modelIndex]);

	iShowImage(tager2.moveX, 320-tag2Y, 300, 300 - mob3_adjust, tager2.model[tager2.modelIndex]);

	iShowImage(tager3.moveX, 320-tag3Y, 300, 300 - mob3_adjust, tager3.model[tager3.modelIndex]);

	//iShowImage(1480, 880, 400, 100, tager3.model[110]);

	if (tager1.hp == 0 && !tager1Dead) {
		tagerNumber--;
		tager1Dead = true;
	}

	if (tager2.hp == 0 && !tager2Dead) {
		tagerNumber--;
		tager2Dead = true;
	}

	if (tager3.hp == 0 && !tager3Dead) {
		tagerNumber--;
		tager3Dead = true;
	}

	iShowImage(1480, 880, 400, 100, healthBar[3]); //  tager mob bar

	iSetColor(255, 255, 255);
	string num = to_string(tagerNumber); // Convert number to string
	iText(1732, 945, (char*)num.c_str(), GLUT_BITMAP_TIMES_ROMAN_24);


}

void showLevelTwo_2(){
	//iShowImage(bgHelper + bgx, -50, 3800, 1080, levelImg[3]);
	//iShowImage(hero.moveX, 320, 250, 250, hero.model[hero.modelIndex]);
	if (ragna.modelIndex >= 0 && ragna.modelIndex <= 6 || ragna.modelIndex >= 7 && ragna.modelIndex <= 13)
	{
		ragna_H_adjust = 0;
		ragna_w_adjust = 0;
		ragna_y_adjust = 0;
	}
	else if (ragna.modelIndex == 169 || ragna.modelIndex == 176)
	{
		ragna_H_adjust = 170;
		ragna_y_adjust = 50;
		ragna_w_adjust = -10;
	}
	else
	{


		ragna_H_adjust = 30;
		ragna_w_adjust = 100;
	}

	iShowImage(ragna.moveX, 320 - ragna_y_adjust, 300 - ragna_w_adjust, 300 - ragna_H_adjust, ragna.model[ragna.modelIndex]);
	//iShowImage(ragna.moveX, 320, 300, 300 - samplify, ragna.model[ragna.modelIndex]);

	// ragna bar

	iShowImage(1510, 880, 400, 100, ragna.model[177]);

}

void showPhaseOne_1(){


	//mob1_adjust = (mob1.modelIndex == 128) ? 180 : 0;
	mob2_adjust = (mob2.modelIndex == 128) ? 180 : 0;
	mob3_adjust = (mob3.modelIndex == 128) ? 180 : 0;
	mob4_adjust = (mob4.modelIndex == 128) ? 180 : 0;

	iShowImage(mob2.moveX, 320, 300, 300 - mob2_adjust, mob2.model[mob2.modelIndex]);

	iShowImage(mob3.moveX, 320, 300, 300 - mob3_adjust, mob3.model[mob3.modelIndex]);

	iShowImage(mob4.moveX, 320, 300, 300 - mob4_adjust, mob4.model[mob4.modelIndex]);


	//iShowImage(1510, 880, 400, 100, boss.model[124]);






	// Check each mob's HP and decrease mobNumber only once per death

	if (mob2.hp == 0 && !mob2_dead) {
		mobNumber--;
		mob2_dead = true;
	}

	if (mob3.hp == 0 && !mob3_dead) {
		mobNumber--;
		mob3_dead = true;
	}

	if (mob4.hp == 0 && !mob4_dead) {
		mobNumber--;
		mob4_dead = true;
	}

	iShowImage(1480, 880, 400, 100, mob2.model[129]); // mob bar

	iSetColor(255, 255, 255);
	string num = to_string(mobNumber); // Convert number to string
	iText(1732, 945, (char*)num.c_str(), GLUT_BITMAP_TIMES_ROMAN_24);

}

void showPhaseOne_2(){



	iShowImage(boss.moveX, 320, 300, 300 - samplify, boss.model[boss.modelIndex]);

	
	
	iShowImage(1510, 880, 400, 100, boss.model[124]);
	
	

}

int backer = 0;

void goback(Character zero, Boss voss){

	if (!voss.alive && voss.hp <= 0) {
		if (deathTime == 0) deathTime = clock(); // Start timer when boss dies
		if ((clock() - deathTime) / CLOCKS_PER_SEC >= 10) {
			//backer = 1;
			page = LEVELPAGE;

		}


	}

	else if (!zero.alive && zero.hp <= 0) {
		if (deathTime == 0) deathTime = clock(); // Start timer when hero dies
		if ((clock() - deathTime) / CLOCKS_PER_SEC >= 10) {
			//backer = 1;
			page = LEVELPAGE;
		}


	}

}

void goback2(Character zero, RagnaBoss voss){

	if (!voss.alive && voss.hp <= 0) {
		if (deathTime == 0) deathTime = clock(); // Start timer when boss dies
		if ((clock() - deathTime) / CLOCKS_PER_SEC >= 10) {
			//backer = 1;
			page = LEVELPAGE;
		}


	}

	else if (!zero.alive && zero.hp <= 0) {
		if (deathTime == 0) deathTime = clock(); // Start timer when hero dies
		if ((clock() - deathTime) / CLOCKS_PER_SEC >= 10) {
			//backer = 1;
			page = LEVELPAGE;
		}


	}

}

void goback3(Character zero, ArakuneBoss voss){

	if (!voss.alive && voss.hp <= 0) {
		if (deathTime == 0) deathTime = clock(); // Start timer when boss dies
		if ((clock() - deathTime) / CLOCKS_PER_SEC >= 10) {
			//backer = 1;
			page = LEVELPAGE;
		}


	}

	else if (!zero.alive && zero.hp <= 0) {
		if (deathTime == 0) deathTime = clock(); // Start timer when hero dies
		if ((clock() - deathTime) / CLOCKS_PER_SEC >= 10) {
			//backer = 1;
			page = LEVELPAGE;
		}


	}

}


void resultPageShow(Character zero, Boss voss){

	if (!voss.alive && voss.hp <= 0) {
		if (deathTime == 0) deathTime = clock(); // Start timer when boss dies
		if ((clock() - deathTime) / CLOCKS_PER_SEC >= 5) {
			iShowImage(0, 0, 1900, 1000, result[0]);
		}
		level2Unlocked = true;
		
	}

	else if (!zero.alive && zero.hp <= 0) {
		if (deathTime == 0) deathTime = clock(); // Start timer when hero dies
		if ((clock() - deathTime) / CLOCKS_PER_SEC >= 5) {
			iShowImage(0, 0, 1900, 1000, result[1]);
		}

		
	}

	

}



void resultPageShow(Character zero, RagnaBoss voss){

	if (!voss.alive && voss.hp <= 0) {
		if (deathTime == 0) deathTime = clock(); // Start timer when boss dies
		if ((clock() - deathTime) / CLOCKS_PER_SEC >= 5) {
			iShowImage(0, 0, 1900, 1000, result[0]);
		}
		level3Unlocked = true;
	}

	else if (!zero.alive && zero.hp <= 0) {
		if (deathTime == 0) deathTime = clock(); // Start timer when hero dies
		if ((clock() - deathTime) / CLOCKS_PER_SEC >= 5) {
			iShowImage(0, 0, 1900, 1000, result[1]);
		}
		
	}

	

}

void resultPageShow(Character zero, ArakuneBoss voss){

	if (!voss.alive && voss.hp <= 0) {
		if (deathTime == 0) deathTime = clock(); // Start timer when boss dies
		if ((clock() - deathTime) / CLOCKS_PER_SEC >= 5) {
			iShowImage(0, 0, 1900, 1000, result[0]);
		}
	}

	else if (!zero.alive && zero.hp <= 0) {
		if (deathTime == 0) deathTime = clock(); // Start timer when hero dies
		if ((clock() - deathTime) / CLOCKS_PER_SEC >= 5) {
			iShowImage(0, 0, 1900, 1000, result[1]);
		}
	}



}

void drawHealthBars(Character hero, Boss boss)
{
	// Scale the hero's and boss's health to fit the respective health bar widths
	int heroHealthBarWidth = (hero.hp * heroMaxBarWidth) / heroMaxHealth;
	int bossHealthBarWidth = (boss.hp * bossMaxBarWidth) / bossMaxHealth;

	// **Hero Health Bar**
	if (hero.hp < (maxHp / 2))
	{
		iSetColor(255, 0, 0);
	}
	else
	{
		iSetColor(0, 255, 0);
	}
	iFilledRectangle(106, 956, heroHealthBarWidth, 7);

	// **Boss Health Bar (shrinks from left)**
	int bossLeftX = 1542 + 257 - bossHealthBarWidth;

	if (boss.hp < (bmaxHp / 2))
	{
		iSetColor(255, 0, 0);
	}
	else
	{
		iSetColor(0, 255, 0);
	}
	if (levelPic == 1)
	{
		iFilledRectangle(bossLeftX, 956, bossHealthBarWidth, 7);
	}
}



void drawHealthBars2(Character hero, RagnaBoss boss)
{
	// Scale the hero's and boss's health to fit the respective health bar widths
	int heroHealthBarWidth = (hero.hp * heroMaxBarWidth) / heroMaxHealth;
	int bossHealthBarWidth = (boss.hp * bossMaxBarWidth) / bossMaxHealth;

	// **Hero Health Bar**
	if (hero.hp < (maxHp / 2))
	{
		iSetColor(255, 0, 0);
	}
	else
	{
		iSetColor(0, 255, 0);
	}

	iFilledRectangle(106, 956, heroHealthBarWidth, 7);

	// **Boss Health Bar (shrinks from left)**
	int bossLeftX = 1542 + 257 - bossHealthBarWidth;

	if (boss.hp < (bmaxHp / 2))
	{
		iSetColor(255, 0, 0);
	}
	else
	{
		iSetColor(0, 255, 0);
	}
	if (boss.isFollow)
	{
		iFilledRectangle(bossLeftX, 956, bossHealthBarWidth, 7);
	}
}

void drawHealthBars3(Character hero, MedusaBoss boss)
{
	// Scale the hero's and boss's health to fit the respective health bar widths
	int heroHealthBarWidth = (hero.hp * heroMaxBarWidth) / heroMaxHealth;
	int bossHealthBarWidth = (boss.hp * bossMaxBarWidth) / bossMaxHealth;

	// **Hero Health Bar**
	if (hero.hp < (maxHp / 2))
	{
		iSetColor(255, 0, 0);
	}
	else
	{
		iSetColor(0, 255, 0);
	}

	iFilledRectangle(106, 956, heroHealthBarWidth, 7);

	// **Boss Health Bar (shrinks from left)**
	int bossLeftX = 1542 + 257 - bossHealthBarWidth;

	if (boss.hp < (bmaxHp / 2))
	{
		iSetColor(255, 0, 0);
	}
	else
	{
		iSetColor(0, 255, 0);
	}
	if (boss.isFollow)
	{
		iFilledRectangle(bossLeftX, 956, bossHealthBarWidth, 7);
	}
}

void drawHealthBars4(Character hero, ArakuneBoss boss)
{
	// Scale the hero's and boss's health to fit the respective health bar widths
	int heroHealthBarWidth = (hero.hp * heroMaxBarWidth) / heroMaxHealth;
	int bossHealthBarWidth = (boss.hp * bossMaxBarWidth) / bossMaxHealth;

	// **Hero Health Bar**
	if (hero.hp < (maxHp / 2))
	{
		iSetColor(255, 0, 0);
	}
	else
	{
		iSetColor(0, 255, 0);
	}

	iFilledRectangle(106, 956, heroHealthBarWidth, 7);

	// **Boss Health Bar (shrinks from left)**
	int bossLeftX = 1542 + 257 - bossHealthBarWidth;

	if (boss.hp < (bmaxHp / 2))
	{
		iSetColor(255, 0, 0);
	}
	else
	{
		iSetColor(0, 255, 0);
	}
	if (boss.isFollow)
	{
		iFilledRectangle(bossLeftX, 956, bossHealthBarWidth, 7);
	}
}







map<unsigned char, const char*> soundMap = {
	{ 'a', "resources\\music\\kick.wav" },
	{ 's', "resources\\music\\slash.wav" },
	{ 'z', "resources\\music\\dash.wav" },
	{ 'x', "resources\\music\\thrust.wav" },
	{ 'c', "resources\\music\\swing.wav" }
};

void playSound(unsigned char key) {
	// Stop any currently playing sound to avoid conflict
	PlaySound(0, 0, 0); // Stop all sounds

	if (soundMap.find(key) != soundMap.end()) {
		PlaySound(soundMap[key], NULL, SND_FILENAME | SND_ASYNC); // Play sound asynchronously
	}
}


// ++++++++++++++++++++   background moveing helper ++++++++++++++++++++++++++++
int bgWidth = 3800;
int screenW = 1900;
// +++++++++++++++++++++++++++    end  ++++++++++++++++++++++++++++++++++++++++



/*

int amplify = 0;
int increment = 0;

int samplify = 0;
int sincrement = 0;




// Maximum health values for hero and boss
const int heroMaxHealth = 10000;  // Hero's max health
const int bossMaxHealth = 15000;  // Boss's max health

// Maximum width for the health bars (different for hero and boss)
const int heroMaxBarWidth = 2600;  // Hero's health bar max width
const int bossMaxBarWidth = 3850;  // Boss's health bar max width


int bgx = 0;
int bgHelper = -500;


int maxHp = hero.hp;
int bmaxHp = boss.hp;
*/




void iDraw() {
	iClear();

	

	if (level3MobCount==0)
	{
		tester = 0;
	}

	if (medusa.modelIndex == 186 || medusa.modelIndex == 195)
	{
		 medusa_Y_adjust = 100;
		 medusa_H_adjust = 100;
		 medusa_W_adjust = 150;
	}
	else
	{
		medusa_Y_adjust = 0;
		medusa_H_adjust = 0;
		medusa_W_adjust = 0;
	}


	if (page == LEVELPAGE)
	{
		hero.hp = 1000;
		boss.hp = 1000;
		deathTime = 0;

		resetLevelOne();
		resetLevelTwo();
		resetLevelThree();

	}



	if (page == LEVEL1){

		

		/////////////////// hero \\\\\\\\\\\\\\\\\

		if (hero.modelIndex == 161) {
			amplify = 170;
			increment = 70;
		}
		else if (hero.modelIndex != 161) {
			amplify = 0;
			increment = 0;
		}

		/////////////////// mob ////////////////

		/*
		int mob1_adjust = 0;
		int mob2_adjust = 0;
		int mob3_adjust = 0;
		int mob4_adjust = 0;

		//mob1_adjust = (mob1.modelIndex == 128) ? 180 : 0;
		mob2_adjust = (mob2.modelIndex == 128) ? 180 : 0;
		mob3_adjust = (mob3.modelIndex == 128) ? 180 : 0;
		mob4_adjust = (mob4.modelIndex == 128) ? 180 : 0;
		
		*/
		
		




		//////////////////// boss \\\\\\\\\\\\\\\\\\\\\

		if (boss.modelIndex == 123) {
			samplify = 170;
			sincrement = 70;
		}
		else if (hero.modelIndex != 123) {
			samplify = 0;
			sincrement = 0;
		}



		//-------------------- image starts ---------------------




		iShowImage(bgHelper + bgx, -50, 3800, 1080, levelImg[levelPic]);

		iShowImage(hero.moveX, 320, 250, 250 - amplify, hero.model[hero.modelIndex]);

		// hero bar
		iShowImage(2, 880, 400, 100, hero.model[186]);
		// hero bar

		if (mobNumber != 0){
			showPhaseOne_1();
		}


		if (mobNumber == 0 && bgx == -1400)
		{
			levelPic = 1;
		}
		if (levelPic == 1){
			if (flag){
				bgx = 0;
				hero.moveX = 0;
				flag = 0;
				boss.isFollow = true;
			}
			showPhaseOne_2();
			

		}
		drawHealthBars(hero, boss);
		
		resultPageShow(hero, boss);

		// come back mthod

		goback(hero, boss);

		if (backer == 1)
		{
			page = LEVELPAGE;
		}

	}


	////////////////////////////////////////////////////////////////////////   level 2 starts ////////////////////////////////////////////////////////////////////

	else if (page == LEVEL2)
	{
		if (hero.modelIndex == 161) {
			amplify = 170;
			increment = 70;
		}
		else if (hero.modelIndex != 161) {
			amplify = 0;
			increment = 0;
		}

		iShowImage(bgHelper + bgx, -50, 3800, 1080, levelImg[level2Pic]);
		if (tagerNumber != 0){
			showLevelTwo_1();
		}
		iShowImage(hero.moveX, 320, 250, 250 - amplify, hero.model[hero.modelIndex]);

		// hero bar
		iShowImage(2, 880, 400, 100, hero.model[186]);

		if (tagerNumber == 0 && bgx == -1400)
		{
			level2Pic = 3;
		}
		if (level2Pic == 3){
			if (ragnaFlag){
				bgx = 0;
				hero.moveX = 0;
				ragnaFlag = 0;
				ragna.isFollow = true;
			}
			showLevelTwo_2();

			
		}

		drawHealthBars2(hero, ragna);

		resultPageShow(hero, ragna);

		// come back mthod

		goback2(hero, ragna);

		if (backer == 1)
		{
			page = LEVELPAGE;
		}
		





		

	}
	else if (page == LEVEL3){
		if (hero.modelIndex == 161) {
			amplify = 170;
			increment = 70;
		}
		else if (hero.modelIndex != 161) {
			amplify = 0;
			increment = 0;
		}

		iShowImage(bgHelper + bgx, -50, 3800, 1080, levelImg[level3Pic]);
		if (level3MobCount!=0){
			showLevelThree_1();
		}
		iShowImage(hero.moveX, 320, 250, 250 - amplify, hero.model[hero.modelIndex]);

		// hero bar
		iShowImage(2, 880, 400, 100, hero.model[186]);

		if (level3MobCount==0 && bgx == -1400)
		{
			level3Pic = 5;
		}
		if (level3Pic == 5){
			if (mobOutFlag){
				bgx = 0;
				hero.moveX = 0;
				mobOutFlag = 0;
				medusa.isFollow = true;
			}
			showLevelThree_2();
		}

		//drawHealthBars2(hero, ragna);


		resultPageShow(hero, arak);

		// come back mthod

		goback3(hero, arak);

		if (backer == 1)
		{
			page = LEVELPAGE;
		}



	}
	else{
		showUI();
	}


	if (tester && page == LEVEL3)
	{
		testDrawHealthBars(hero);
	}



}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//**********************ipassiveMouse************************//
void iPassiveMouseMove(int mx, int my)
{
	if ((mx >= 40 && mx <= 440) && (my >= 650 && my <= 840)) // Updated
		highlight = 1;
	else if ((mx >= 40 && mx <= 440) && (my >= 500 && my <= 690)) // Updated
		highlight = 2;
	else if ((mx >= 40 && mx <= 440) && (my >= 400 && my <= 590)) // Updated
		highlight = 3;
	else if ((mx >= 40 && mx <= 440) && (my >= 300 && my <= 490)) // Updated
		highlight = 4;
	else
		highlight = 0;

	cout << mx << " " << my << endl;
	if (page == LEVELPAGE){
		if ((mx > 280 && mx<580) && (my>140 && my < 875)){
			levelButtonHighlight = 1;
		}
		else if ((mx > 780 && mx<1080) && (my>140 && my < 875)){
			levelButtonHighlight = 2;
		}
		else if ((mx > 1280 && mx<1580) && (my>140 && my < 875)){
			levelButtonHighlight = 3;
			cout << "clicked" << endl;
		}
		else
			levelButtonHighlight = 0;
	}
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) // Ensuring only one click event
	{
		if (page == HOMEPAGE)
		{
			if ((mx >= 40 && mx <= 440) && (my >= 650 && my <= 840)) // Button 1
			{
				// need to update here manga

				if (showSlides)
				{
					page = MANGAPAGE;

					if (mangashift>=35)
					{
						page = LEVELPAGE;
					}
				}
				else
				{
					page = LEVELPAGE;
				}
				
				






				cout << "Button 1 clicked!" << endl;
			}
			else if ((mx >= 40 && mx <= 440) && (my >= 500 && my <= 690)) // Button 2
			{
				page = CREDIT;
				cout << "Button 2 clicked!" << endl;
				// Navigate to Level One Page
			}
			else if ((mx >= 40 && mx <= 440) && (my >= 400 && my <= 590)) // Button 3
			{
				page = INSTRUCTION;
				cout << "Button 3 clicked!" << endl;
			}
			else if ((mx >= 40 && mx <= 440) && (my >= 300 && my <= 490)) // Button 4
			{
				cout << "Button 4 clicked!" << endl;

		        writeValuesToFile(showSlides, level2Unlocked, level3Unlocked);

				
				exit(0);
			}
		}
		else if (page == LEVELPAGE)
		{
			if ((mx > 280 && mx < 580) && (my > 140 && my < 875))
			{
				if (hero.hp>0)
				{
					hero.modelState = STAND;
					hero.alive = true;
					hero.moveX = 100;
					//deathTime = 0;
				}
				if (boss.hp>0)
				{
					boss.modelState = STAND;
					boss.alive = true;
					boss.isFollow = true;
					boss.moveX = 1000;
					//deathTime = 0;

				}

				bgHelper = -500;
				backer = 0;

				bgx = 0;


				page = LOADINGSCREEN;

				cout << "Navigating to Loading Screen!" << endl;
			}
			else if ((mx > 780 && mx<1080) && (my>140 && my < 875)){
				page = LEVEL2;
				if (hero.hp>0)
				{
					hero.modelState = STAND;
					hero.alive = true;
					hero.moveX = 100;
					//deathTime = 0;
					
				}
				if (ragna.hp>0)
				{
					ragna.modelState = STAND;
					ragna.alive = true;
					ragna.isFollow = false;
					ragna.moveX = 1000;
					//deathTime = 0;

				}

				backer = 0;

				bgHelper = -500;
				bgx = 0;
			}
			else if ((mx > 1280 && mx<1580) && (my>140 && my < 875))
			{
				page = LEVEL3;
				if (hero.hp>0)
				{
					hero.modelState = STAND;
					hero.alive = true;
					hero.moveX = 100;
					//deathTime = 0;

				}
				if (medusa.hp>0)
				{
					medusa.modelState = STAND;
					medusa.alive = true;
					medusa.isFollow = false;
					medusa.moveX = 1500;
					//deathTime = 0;

				}

				backer = 0;

				bgHelper = -500;
				bgx = 0;

			}
		}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		cout << "Right button clicked!" << endl;
	}
}


/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'm')
	{
		if (musicOn)
		{
			musicOn = false;
			PlaySound(0, 0, 0); // Stop background music
		}
		else
		{
			musicOn = true;
			// Ensure background music doesn't restart if it's already playing
			PlaySound("resources\\music\\bg_music.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}
	if (key == ' ')
	{
		if (page == TAPPAGE)
		{
			page = HOMEPAGE;
		}
	}

	if (key == ']'){

		if (page == STARTPAGE)
			page = TAPPAGE;
		else if (page == TAPPAGE)
			page = HOMEPAGE;
		else if (page == HOMEPAGE)
			page = LEVELPAGE;
		else if (page == LEVELPAGE)
			page = LOADINGSCREEN;
		else if (page == LOADINGSCREEN){
			//boss.isFollow = true;
			page = LEVEL1;
		}

	}
	if (key == '['){

		if (page == LEVEL1){
			boss.isFollow = false;
			page = LOADINGSCREEN;
		}
		else if (page == LOADINGSCREEN){

			page = LEVELPAGE;

		}
		else if (page == LEVELPAGE){
			page = HOMEPAGE;

		}
		else if (page == HOMEPAGE)
			page = TAPPAGE;
		else if (page == TAPPAGE){
			startPageIndex = 0;
			page = STARTPAGE;
		}
		else if (page == INSTRUCTION){
			page = HOMEPAGE;
		}
		else if (page == CREDIT){
			page = HOMEPAGE;
		}

		else if (page == LEVEL3){
			medusa.isFollow = false;
			page = LEVELPAGE;

		}

	}
	if (page == LEVEL1)
	{
		if (key == 'l'){

			//boss.isFollow = true;
			mob2.isFollow = true;
			mob3.isFollow = true;
			mob4.isFollow = true;


		}
		if (key == 'p'){

			mob2.isFollow = false;
			mob3.isFollow = false;
			mob4.isFollow = false;
		}
		if (key == 'o'){
			if (boss.isFollow == true)
				boss.isFollow = false;
			else{
				boss.isFollow = true;
			}

		}
	}
	if (page == LEVEL2)
	{
		if (key == 'l')
		{
			tager1.isFollow = true;
			tager2.isFollow = true;
			tager3.isFollow = true;



		}
		if (key == 'p')
		{
			tager1.isFollow = false;
			tager2.isFollow = false;
			tager3.isFollow = false;
		}

	}
	if (page == LEVEL3)
	{
		if (key == 'l')
		{
			tager.isFollow = true;
			tager4.isFollow = true;

			mob.isFollow = true;
			mob1.isFollow = true;

		}
		if (key == 'p')
		{
			tager.isFollow = false;
			tager4.isFollow = false;

			mob.isFollow = false;
			mob1.isFollow = false;

		}

	}

	if (page == LEVELPAGE){
		if (key == '9'){
			page = LEVEL3;
		}
	}



	if (hero.alive)
	{
		if (key == 'x' || key == 'X')
		{
			if (hero.modelState == STAND || hero.modelState == WALK)
			{
				hero.modelState = THRUST;
				playSound('x'); // Play sound for thrust
			}

			if (hero.modelState == STAND_B || hero.modelState == WALK_B)
			{
				hero.modelState = THRUST_B;
				playSound('x'); // Play sound for thrust
			}
		}

		if (key == 'a' || key == 'A')
		{
			if (hero.modelState == STAND || hero.modelState == WALK)
			{
				hero.modelState = KICK;
				playSound('a'); // Play sound for kick
			}

			if (hero.modelState == STAND_B || hero.modelState == WALK_B)
			{
				hero.modelState = KICK_B;
				playSound('a'); // Play sound for kick
			}
		}

		if (key == 'c' || key == 'C')
		{
			if (hero.modelState == STAND || hero.modelState == WALK)
			{
				hero.modelState = SWING;
				playSound('c'); // Play sound for swing
			}

			if (hero.modelState == STAND_B || hero.modelState == WALK_B)
			{
				hero.modelState = SWING_B;
				playSound('c'); // Play sound for swing
			}
		}

		if (key == 's' || key == 'S')
		{
			if (hero.modelState == STAND || hero.modelState == WALK)
			{
				hero.modelState = SLASH;
				playSound('s'); // Play sound for slash
			}

			if (hero.modelState == STAND_B || hero.modelState == WALK_B)
			{
				hero.modelState = SLASH_B;
				playSound('s'); // Play sound for slash
			}
		}

		if (key == 'z' || key == 'Z')
		{
			if (hero.modelState == STAND || hero.modelState == WALK)
			{
				hero.modelState = DASH;
				playSound('z'); // Play sound for dash
			}

			if (hero.modelState == STAND_B || hero.modelState == WALK_B)
			{
				hero.modelState = DASH_B;
				playSound('z'); // Play sound for dash
			}
		}

		if (key == 'r')
		{
			hero.hp = 1000;
			boss.hp = 1000;
		}
	}


	if (key =='n')
	{
		if (mangashift<35)
		{
			mangashift++;
		}

		if (mangashift>=35)
		{
			page = LEVELPAGE;
			showSlides = false;

		}
	}

	if (key == 'f')
	{
		showSlides = true;
		level2Unlocked = true;
	}
	if (key == 'k')
	{
		cout << "file io write" << endl;
		writeValuesToFile(showSlides, level2Unlocked, level3Unlocked);

	}





}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/


void iSpecialKeyboard(unsigned char key)
{
	if (hero.alive)
	{

		if (key == GLUT_KEY_RIGHT)
		{

			if (hero.moveX < bgWidth - screenW)
			{
				hero.modelState = WALK_B;
				hero.moveX += 2;
			}
		}


		if (key == GLUT_KEY_LEFT)
		{
			if (hero.moveX > 0)
			{
				hero.modelState = WALK;
				hero.moveX -= 2;
			}

			cout << "this is the x of hero: " << hero.moveX << endl;
		}

		if (hero.moveX >= 0 && hero.moveX < 1900)
		{
			if (hero.moveX >= 800 && bgx > -1400 && hero.modelState == WALK_B)
			{
				bgx -= 5;
				/*
				
				if (mob2.hp == 0)
				{
					mob2.moveX -= 5;
				}
				if (mob3.hp == 0)
				{
					mob3.moveX -= 5;
				}
				if (mob4.hp == 0)
				{
					mob4.moveX -= 5;
				}
				*/
			}
			else if (hero.moveX < 800 && bgx < 0 && hero.modelState == WALK)
			{
				bgx += 5;
				/*
					if (mob2.hp == 0)
					{
						mob2.moveX += 5;
					}
					if (mob3.hp == 0)
					{
						mob3.moveX += 5;
					}
					if (mob4.hp == 0)
					{
						mob4.moveX += 5;
					}
				
				*/
			}


		}

		// Prevent hero from going off-screen
		if (hero.moveX < 0)
		{
			hero.moveX = 0; // Prevent moving past the left edge
		}
		if (hero.moveX > bgWidth - screenW)  // Prevent hero from moving past the right edge
		{
			hero.moveX = bgWidth - screenW;
		}

		// Ensure background doesn't go past the end of the image
		if (bgx < -1400)
		{
			bgx = -1400;
		}

		// Output current bgx for debugging
		cout << "the bgx is " << bgx << endl;
	}
}




void animate()
{
	animateChar(hero);
	if (levelPic == 1)
		animateBoss(boss);

	animateMobs(mob4);
	animateMobs(mob2);
	animateMobs(mob3);

	animateTagerBoss(tager1);
	animateTagerBoss(tager2);
	animateTagerBoss(tager3);

	animateRagnaBoss(ragna);

	//level 3
	animateArakune(arak);
	animateMedusa(medusa);
	animateTagerBoss(tager);
	animateTagerBoss(tager4);
	animateMobs(mob);
	animateMobs(mob1);




}
void animateFollow(){
	if (levelPic == 1)
		follow(hero, boss);
	if (page == LEVEL1){

		mob_follow(hero, mob4);

		mob_follow(hero, mob2);

		mob_follow(hero, mob3);
	}

	if (page == LEVEL2){
		followTager(hero, tager1);
		followTager(hero, tager2);
		followTager(hero, tager3);

	}
	

	if (level2Pic == 3)
		followRagna(hero, ragna);

	if (page == LEVEL3){
		arakunefollow(hero, arak);
		followMedusa(hero, medusa);

		followTager(hero, tager);
		followTager(hero, tager4);

		mob_follow(hero, mob);
		mob_follow(hero, mob1);


	}


}





#pragma comment(lib, "winmm.lib")

void playBackgroundMusic() {
	// Stop and close any existing music
	mciSendString("stop bgm", NULL, 0, NULL);
	mciSendString("close bgm", NULL, 0, NULL);

	// Open the background music file
	int result = mciSendString("open \"resources\\music\\genkai.wav\" type waveaudio alias bgm", NULL, 0, NULL);
	if (result != 0) {
		char errorText[128];
		mciGetErrorString(result, errorText, sizeof(errorText));
		MessageBox(NULL, errorText, "Error: Failed to open background music!", MB_OK | MB_ICONERROR);
		return;
	}

	while (true) {
		// Play the music from the beginning
		result = mciSendString("play bgm from 0", NULL, 0, NULL);
		if (result != 0) {
			char errorText[128];
			mciGetErrorString(result, errorText, sizeof(errorText));
			MessageBox(NULL, errorText, "Error: Failed to play background music!", MB_OK | MB_ICONERROR);
			return;
		}

		// Wait for the music to finish before replaying
		DWORD length = 0;
		mciSendString("status bgm length", NULL, 0, NULL);
		MCI_STATUS_PARMS mciStatus;
		mciStatus.dwItem = MCI_STATUS_LENGTH;
		mciSendCommand((MCIDEVICEID)mciGetDeviceID("bgm"), MCI_STATUS, MCI_STATUS_ITEM, (DWORD_PTR)&mciStatus);
		length = mciStatus.dwReturn;

		if (length > 0) {
			std::this_thread::sleep_for(std::chrono::milliseconds(length));
		}
		else {
			std::this_thread::sleep_for(std::chrono::seconds(5)); // Fallback delay if length retrieval fails
		}
	}
}













int main()
{
	//writeValuesToFile(showSlides, level2Unlocked, level3Unlocked);


	readValuesFromFile(showSlides, level2Unlocked, level3Unlocked);





	std::thread musicThread(playBackgroundMusic);
	musicThread.detach();

	iSetTimer(100, animate);
	iSetTimer(1, animateFollow);
	iSetTimer(150, animateUI);
	///srand((unsigned)time(NULL));

	

	iInitialize(1900, 1000, "Ashura: The Sanguine Blade");

	// edited now

	loadMangaResources();
	loadHpBars();

	// edit end

	loadCharacterResources(hero.model, hero.modelIndex);
	loadBossResources(boss.model, boss.modelIndex);
	loadMobResources(mob4.model, mob4.modelIndex);
	loadMobResources(mob2.model, mob2.modelIndex);
	loadMobResources(mob3.model, mob3.modelIndex);
	loadTagerResources(tager1.model, tager1.modelIndex);
	loadTagerResources(tager2.model, tager2.modelIndex);
	loadTagerResources(tager3.model, tager3.modelIndex);
	loadRagnaResources(ragna.model, ragna.modelIndex);


	//level 3 exclusive
	loadArakuneResources(arak.model, arak.modelIndex);

	loadMedusaResources(medusa.model, medusa.modelIndex);
	loadTagerResources(tager.model, tager.modelIndex);
	loadTagerResources(tager4.model, tager4.modelIndex);

	loadMobResources(mob.model, mob.modelIndex);
	loadMobResources(mob1.model, mob1.modelIndex);


	loadImgResources();



	///updated see the documentations
	iStart();
	return 0;
}