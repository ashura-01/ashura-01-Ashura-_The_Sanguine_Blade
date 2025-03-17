#ifndef RESOURCES_H
#define RESOURCES_H

#include "iGraphics.h";
#include <string>;
using namespace std;

int dx = 0, dy = 0;

bool musicOn = false;

bool level2Unlocked = false;
bool level3Unlocked = false;

enum Pages{ STARTPAGE, TAPPAGE, HOMEPAGE, LEVELPAGE, LEVEL1, LEVEL2, LEVEL3, LOADINGSCREEN, INSTRUCTION,CREDIT, LEVELLOADING2, LEVELOADING3, MANGAPAGE };

Pages page = STARTPAGE;

int levelImg[10];
int levelImgIndex;

int startPage[20];
int startPageIndex;

int homePage[20];
int homePageIndex;

int button[20];

int levelNum[3];
int levelNumIndex;

int levelButton[7];

int levelPage;

int tapPage[60];
int tapPageIndex=0;

int loadingScreen[9];
int loadingScreenIndex = 0;


int highlight = 0;
int levelButtonHighlight = 0;


int insPage;
int credPage;

// fahim ///
string levelOneAlloc = "resources\\map\\01.png";
//int levelImg[10];
int pageImg[15];
int buttonImg[15];
int result[3];


int manga[100];
int mangashift = 1; // added now buddy
// fahim ///




//bars
int healthBar[10];


void loadMangaResources(){


	for (int i = 1; i <= 35; i++){
		string str = "resources\\manga\\script";
		str = str + to_string(i + 1) + ".png";
		manga[i] = iLoadImage(const_cast<char*>(str.c_str()));
	}
}


void loadHpBars(){

	string meduBar = "resources\\ui\\medubar.png";
	healthBar[0] = iLoadImage(const_cast<char*>(meduBar.c_str()));

	string araBar = "resources\\ui\\arabar.png";
	healthBar[1] = iLoadImage(const_cast<char*>(araBar.c_str()));

	string mobBar = "resources\\ui\\medumobbar.png";
	healthBar[2] = iLoadImage(const_cast<char*>(mobBar.c_str()));

	string tagerBar = "resources\\ui\\tagerbar.png";
	healthBar[3] = iLoadImage(const_cast<char*>(tagerBar.c_str()));

	



}





void loadImgResources(){


	//fahim//
	string str = "resources\\map\\01.png";
	levelImg[0] = iLoadImage(const_cast<char*>(str.c_str()));
	string str4 = "resources\\map\\02.png";
	levelImg[1] = iLoadImage(const_cast<char*>(str4.c_str()));

	string level2One = "resources\\map\\03.png";
	levelImg[2] = iLoadImage(const_cast<char*>(level2One.c_str()));

	string level2Two = "resources\\map\\04.png";
	levelImg[3] = iLoadImage(const_cast<char*>(level2Two.c_str()));

	string level3One = "resources\\map\\05.png";
	levelImg[4] = iLoadImage(const_cast<char*>(level3One.c_str()));

	string level3Two = "resources\\map\\06.png";
	levelImg[5] = iLoadImage(const_cast<char*>(level3Two.c_str()));



	string str1 = "resources\\result\\r0.png";
	result[0] = iLoadImage(const_cast<char*>(str1.c_str()));

	string str2 = "resources\\result\\r1.png";
	result[1] = iLoadImage(const_cast<char*>(str2.c_str()));
	//fahim//

	string strLevel = "resources\\ui\\levelbg.png";
	levelPage = iLoadImage(const_cast<char*>(strLevel.c_str()));

	string ins = "resources\\ui\\ins.png";
	insPage = iLoadImage(const_cast<char*>(ins.c_str()));

	string cred = "resources\\ui\\cred.png";
	credPage = iLoadImage(const_cast<char*>(cred.c_str()));

	for (int i = 0; i < 6; i++){
		string str = "resources\\ui\\level_button_";
		str = str + to_string(i + 1) + ".png";
		levelButton[i] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i < 19; i++){
		string str = "resources\\ui\\start_frames\\frame0000";
		str = str + to_string(i + 1) + ".png";
		startPage[i] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i < 12; i++){
		string str = "resources\\ui\\buttons\\";
		str = str + to_string(i + 1) + ".png";
		button[i] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	for (int i = 0; i < 20; i++){
		string bgName = "resources\\bg\\frame000";
		bgName = bgName + to_string(i + 1) + ".png";
		homePage[i] = iLoadImage(const_cast<char*>(bgName.c_str()));
	}
	for (int i = 0; i < 8; i++){
		string bgName = "resources\\loadingscreen\\0";
		bgName = bgName + to_string(i + 1) + ".png";
		loadingScreen[i] = iLoadImage(const_cast<char*>(bgName.c_str()));
	}
	for (int i = 0; i < 3; i++){
		string str = "resources\\ui\\level_num\\0";
		str = str + to_string(i + 1) + ".png";
		levelNum[i] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i < 57; i++){
		string str = "resources\\ui\\tap_page\\frame000";
		str = str + to_string(i + 1) + ".png";
		tapPage[i] = iLoadImage(const_cast<char*>(str.c_str()));
	}




}


void showloadingScreen(){
	iShowImage(0, 0, 1900, 1000, loadingScreen[loadingScreenIndex]);
}

void showLevelPage(){
	iShowImage(0, 0, 1900, 1000, levelPage);

}
void showLevelButton(){
	if (levelButtonHighlight == 1)
		iShowImage(250 - 12.5, 80 - 12.5, 360 + 25, 870 + 25, levelButton[0]);
	else
		iShowImage(250, 80, 360, 870, levelButton[0]);
	if (levelButtonHighlight == 2)
	{
		if (level2Unlocked)
			iShowImage(750 - 12.5, 80 - 12.5, 360 + 25, 870 + 25, levelButton[1]);
		else
			iShowImage(750 - 12.5, 80 - 12.5, 360 + 25, 870 + 25, levelButton[4]);
	}
	else{
		if (level2Unlocked)
			iShowImage(750, 80, 360, 870, levelButton[1]);
		else
			iShowImage(750, 80, 360, 870, levelButton[4]);
	}
	if (levelButtonHighlight == 3)
	{
		if (level3Unlocked)
			iShowImage(1250 - 12.5, 80 - 12.5, 360 + 25, 870 + 25, levelButton[2]);
		else
			iShowImage(1250 - 12.5, 80 - 12.5, 360 + 25, 870 + 25, levelButton[5]);
	}
	else{
		if (level3Unlocked)
			iShowImage(1250, 80, 360, 870, levelButton[2]);
		else
			iShowImage(1250, 80, 360, 870, levelButton[5]);

	}

	iShowImage(260, 30, 350, 100, levelNum[0]);
	iShowImage(760, 30, 350, 100, levelNum[1]);
	iShowImage(1260, 30, 350, 100, levelNum[2]);
}


void showButtons()
{
	if (highlight == 1)
		iShowImage(40, 650, 400, 190, button[1]); // Lowered by 100
	else
		iShowImage(40, 650, 400, 190, button[0]); // Lowered by 100

	if (highlight == 2)
		iShowImage(40, 500, 400, 190, button[3]); // Lowered by 100
	else
		iShowImage(40, 500, 400, 190, button[2]); // Lowered by 100

	if (highlight == 3)
		iShowImage(40, 400, 400, 190, button[5]); // Lowered by 100
	else
		iShowImage(40, 400, 400, 190, button[4]); // Lowered by 100

	if (highlight == 4)
		iShowImage(40, 300, 400, 190, button[7]); // Lowered by 100
	else
		iShowImage(40, 300, 400, 190, button[6]); // Lowered by 100

	if (musicOn)
		iShowImage(1700, 50, 100, 72, button[8]);
	else
		iShowImage(1700, 50, 100, 72, button[9]);

	iShowImage(850, 700, 1000, 180, button[11]); // Not lowered
}

void showStartPage(){
	iShowImage(0, 0, 1900, 1000, startPage[startPageIndex]);
}
void showTapPage(){
	iShowImage(0, 0, 1900, 1000, tapPage[tapPageIndex]);
	if (tapPageIndex >= 55){
		iShowImage(550, 40, 800, 200, button[10]);
	}
}
void showHomePage(){
	iShowImage(0, 0, 1900, 1000, homePage[homePageIndex]);

}

void showInstructionPage(){
	iShowImage(0, 0, 1900, 1000, insPage);
}

void showCreditPage(){
	iShowImage(0, 0, 1900, 1000, credPage);
}

/// yoooo here is the manga bang bang ........
void showManga()
{
	iShowImage(650, 80, 600, 900, manga[mangashift]);

}


void showUI(){
	switch (page){
	case STARTPAGE:
		showStartPage();
		break;
	case TAPPAGE:
		showTapPage();
		break;
	case HOMEPAGE:
		showHomePage();
		showButtons();
		break;
	case MANGAPAGE:
		showManga();
		break;
	case LEVELPAGE:
		showLevelPage();
		showLevelButton();
		break;
	case LOADINGSCREEN:
		showloadingScreen();
		break;
	case INSTRUCTION:
		showInstructionPage();
		break;
	case CREDIT:
		showCreditPage();
	}
}
void animateUI(){

	switch (page){
	case STARTPAGE:
		startPageIndex++;
		if (startPageIndex > 18)
			page = TAPPAGE;
		break;
	case TAPPAGE:
		if (tapPageIndex < 56)
			tapPageIndex++;
		
		break;
	case HOMEPAGE:
		homePageIndex++;
		if (homePageIndex > 19)
			homePageIndex = 0;
		break;
	case LOADINGSCREEN:
		loadingScreenIndex++;
		if (loadingScreenIndex > 7){
			loadingScreenIndex = 0;
			page = LEVEL1;
		}

	}

}








void loadCharacterResources(int* characterModel, int& modelCount){
	modelCount = 0;
	for (int i = 0; i <= 9; i++)
	{
		string str = "resources\\mc\\stand\\ha001_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	for (int i = 0; i <= 9; i++)
	{
		string str = "resources\\mc\\bstand\\ha001_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 8; i++)
	{
		string str = "resources\\mc\\bwalk\\ha030_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 8; i++)
	{
		string str = "resources\\mc\\walk\\ha030_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	for (int i = 0; i <= 10; i++)
	{
		string str = "resources\\mc\\bkick\\ha201_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	for (int i = 0; i <= 10; i++)
	{
		string str = "resources\\mc\\kick\\ha201_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	for (int i = 0; i <= 19; i++)
	{
		string str = "resources\\mc\\bslash\\ha212_";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 19; i++)
	{
		string str = "resources\\mc\\slash\\ha212_";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	for (int i = 0; i <= 16; i++)
	{
		string str = "resources\\mc\\bswing\\ha202_";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 16; i++)
	{
		string str = "resources\\mc\\swing\\ha202_";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 7; i++)
	{
		string str = "resources\\mc\\bdash\\ha032_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 7; i++)
	{
		string str = "resources\\mc\\dash\\ha032_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 11; i++)
	{
		string str = "resources\\mc\\dead\\ha070_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 11; i++)
	{
		string str = "resources\\mc\\thrust\\ha214_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 11; i++)
	{
		string str = "resources\\mc\\bthrust\\ha214_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	string str = "resources\\mc\\hp\\bar";
	str = str + ".png";
	characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));



}
void loadBossResources(int* characterModel, int& modelCount){
	modelCount = 0;
	for (int i = 0; i <= 12; i++) {
		string str = "resources\\sus\\walk\\su030_";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Walk: 0–12
	}

	for (int i = 0; i <= 10; i++) {
		string str = "resources\\sus\\tailAttack\\su201_";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Tail Attack: 13–23
	}

	for (int i = 0; i <= 12; i++) {
		string str = "resources\\sus\\bwalk\\su030_";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Backward Walk: 24–36
	}

	for (int i = 0; i <= 9; i++) {
		string str = "resources\\sus\\stand\\su000_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Standing: 37–46
	}

	for (int i = 0; i <= 12; i++) {
		string str = "resources\\sus\\kick\\su202_";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Kick Attack: 47–59
	}

	for (int i = 0; i <= 12; i++) {
		string str = "resources\\sus\\bkick\\su202_";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Backward Kick: 60–72
	}
	for (int i = 0; i <= 9; i++) {
		string str = "resources\\sus\\roar\\su333_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // roar: 73–82
	}

	for (int i = 0; i <= 20; i++) {
		string str = "resources\\sus\\bite\\su400_";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // roar: 83–103
	}

	for (int i = 0; i <= 8; i++) {
		string str = "resources\\sus\\bbite\\su400_";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // roar: 83–103
	}
	for (int i = 0; i <= 10; i++) {
		string str = "resources\\sus\\dead\\su070_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // roar: 83–103
	}

	string str = "resources\\sus\\hp\\bar";
	str = str + ".png";
	characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
}

void loadMobResources(int* characterModel, int& modelCount){
	modelCount = 0;

	for (int i = 0; i <= 11; i++) {
		string str = "resources\\sus_mob\\walk\\Mer400_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Walk: 0–11
	}

	for (int i = 0; i <= 11; i++) {
		string str = "resources\\sus_mob\\bwalk\\Mer400_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Walk: 0–11
	}
	for (int i = 1; i <= 17; i++) {
		string str = "resources\\sus_mob\\stand\\Mer000_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Walk: 0–11
	}

	for (int i = 1; i <= 17; i++) {
		string str = "resources\\sus_mob\\bstand\\Mer000_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Walk: 0–11
	}

	for (int i = 0; i <= 10; i++) {
		string str = "resources\\sus_mob\\bite\\Mer100_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Walk: 0–11
	}
	for (int i = 0; i <= 10; i++) {
		string str = "resources\\sus_mob\\bbite\\Mer100_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Walk: 0–11
	}

	for (int i = 1; i <= 11; i++) {
		string str = "resources\\sus_mob\\handattack\\Mer003_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Walk: 0–11
	}

	for (int i = 1; i <= 11; i++) {
		string str = "resources\\sus_mob\\bhandattack\\Mer003_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Walk: 0–11
	}

	for (int i = 0; i <= 8; i++) {
		string str = "resources\\sus_mob\\punch\\Mer002_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Walk: 0–11
	}
	for (int i = 0; i <= 8; i++) {
		string str = "resources\\sus_mob\\bpunch\\Mer002_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Walk: 0–11
	}

	for (int i = 0; i <= 8; i++) {
		string str = "resources\\sus_mob\\dead\\Mer700_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str())); // Walk: 0–11
	}

	string str = "resources\\sus_mob\\hp\\bar";
	str = str + ".png";
	characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));

}
void loadRagnaResources(int* characterModel, int& modelCount){
	modelCount = 0;

	//stand
	for (int i = 0; i <= 6; i++) {
		string str = "resources\\ragna\\Ragna\\stand\\rg000_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 6; i++) {
		string str = "resources\\ragna\\Flip_Ragna\\stand\\flip_rg000_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	//move
	for (int i = 0; i <= 7; i++) {
		string str = "resources\\ragna\\Ragna\\move\\rg030_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 7; i++) {
		string str = "resources\\ragna\\Flip_Ragna\\move\\flip_rg030_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	//run
	for (int i = 0; i <= 13; i++) {
		string str = "resources\\ragna\\Ragna\\run\\rg032_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 13; i++) {
		string str = "resources\\ragna\\Flip_Ragna\\run\\flip_rg032_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	//swing
	for (int i = 0; i <= 15; i++) {
		string str = "resources\\ragna\\Ragna\\attack1\\rg202_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 15; i++) {
		string str = "resources\\ragna\\Flip_Ragna\\attack1\\flip_rg202_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	//slam
	for (int i = 0; i <= 16; i++) {
		string str = "resources\\ragna\\Ragna\\attack2\\rg203_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 16; i++) {
		string str = "resources\\ragna\\Flip_Ragna\\attack2\\flip_rg203_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	//kick
	for (int i = 0; i <= 16; i++) {
		string str = "resources\\ragna\\Ragna\\attack4\\rg211_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 16; i++) {
		string str = "resources\\ragna\\Flip_Ragna\\attack4\\flip_rg211_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	//death
	for (int i = 0; i <= 11; i++) {
		string str = "resources\\ragna\\Ragna\\death\\rg070_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 6; i++) {
		string str = "resources\\ragna\\Flip_Ragna\\death\\flip_rg060_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	// bar

	string str = "resources\\ragna\\ragnabar";
	str = str + ".png";
	characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));

}
void loadTagerResources(int* characterModel, int& modelCount){

	modelCount = 0;

	//stand
	for (int i = 0; i <= 6; i++) {
		string str = "resources\\tager\\Tager\\stand\\tg000_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 6; i++) {
		string str = "resources\\tager\\Flip_Tager\\flip_stand\\flip_tg000_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	//move
	for (int i = 0; i <= 12; i++) {
		string str = "resources\\tager\\Tager\\move\\tg030_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 12; i++) {
		string str = "resources\\tager\\Flip_Tager\\flip_move\\flip_tg030_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	//attack1
	for (int i = 0; i <= 12; i++) {
		string str = "resources\\tager\\Tager\\attack1\\tg203_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 12; i++) {
		string str = "resources\\tager\\Flip_Tager\\flip_attack1\\flip_tg203_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	//attack2
	for (int i = 0; i <= 14; i++) {
		string str = "resources\\tager\\Tager\\attack2\\tg210_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 14; i++) {
		string str = "resources\\tager\\Flip_Tager\\flip_attack2\\flip_tg210_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	//death
	for (int i = 0; i <= 6; i++) {
		string str = "resources\\tager\\Tager\\death\\tg062_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 6; i++) {
		string str = "resources\\tager\\Flip_Tager\\flip_death\\flip_tg062_0";
		str = str + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	//hp
	string tagerHp = "resources\\ui\\tagerbar.png";
	characterModel[modelCount++] = iLoadImage(const_cast<char*>(tagerHp.c_str()));


}



void loadArakuneResources(int* characterModel, int& modelCount) {
	modelCount = 0;

	// stand (index: 0–27)
	for (int i = 0; i <= 13; i++) {
		string str = "resources\\arakune\\stand\\ar000_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 13; i++) {
		string str = "resources\\arakune\\bstand\\ar000_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	// walk (index: 28–50)
	for (int i = 1; i <= 9; i++) {
		string str = "resources\\arakune\\walk\\ar030_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 1; i <= 9; i++) { // 40–50
		string str = "resources\\arakune\\bwalk\\ar030_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	// attack1 (index: 51–64)
	for (int i = 0; i <= 6; i++) { // 51–57
		string str = "resources\\arakune\\attack1\\ar200_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 6; i++) { // 58–64
		string str = "resources\\arakune\\battack1\\ar200_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	// attack2 (index: 65–90)
	for (int i = 0; i <= 12; i++) { // 65–77
		string str = "resources\\arakune\\attack2\\ar201_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 12; i++) { // 78–90
		string str = "resources\\arakune\\battack2\\ar201_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	// attack3 (index: 91–130)
	for (int i = 0; i <= 19; i++) { // 91–110
		string str = "resources\\arakune\\attack3\\ar203_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 19; i++) { // 111–130
		string str = "resources\\arakune\\battack3\\ar203_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	// attack4 (index: 131–150)
	for (int i = 0; i <= 9; i++) { // 131–140
		string str = "resources\\arakune\\attack4\\ar210_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 9; i++) { // 141–150
		string str = "resources\\arakune\\battack4\\ar210_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	// dead (index: 151–182)
	for (int i = 0; i <= 15; i++) { // 151–166
		string str = "resources\\arakune\\dead\\ar060_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 15; i++) { // 167–182
		string str = "resources\\arakune\\bdead\\ar060_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	// starting (index: 183–208)
	for (int i = 0; i <= 12; i++) { // 183–195
		string str = "resources\\arakune\\starting\\ar024_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 12; i++) { // 196–208
		string str = "resources\\arakune\\bstarting\\ar024_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}



	/*

	string str = "resources\\arakune\\hp\\bar";
	str = str + ".png";
	characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	*/
}



// medusa resources
void loadMedusaResources(int* characterModel, int& modelCount) {
	modelCount = 0;

	// stand (index: 0 17)
	for (int i = 0; i <= 8; i++) { // 0 8
		string str = "resources\\medusa\\Litchi\\stand\\stand_00" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 8; i++) { // 9 17
		string str = "resources\\medusa\\Litchi_Flip\\stand_flip\\standFlip_00" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	// walk (index: 18 45)
	for (int i = 0; i <= 13; i++) { // 18 31
		string str = "resources\\medusa\\Litchi\\walk\\walk_00" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 13; i++) { // 32 45
		string str = "resources\\medusa\\Litchi_Flip\\walk_flip\\walkFlip_00" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	// attack1 (index: 46 75)
	for (int i = 0; i <= 14; i++) { // 46 60
		string str = "resources\\medusa\\Litchi\\attack1\\attack_00" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 14; i++) { // 61 75
		string str = "resources\\medusa\\Litchi_Flip\\attack1_flip\\attackFlip_00" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	// attack2 (index: 76 111)
	for (int i = 0; i <= 17; i++) { // 76 93
		string str = "resources\\medusa\\Litchi\\attack2\\attack2_00" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 17; i++) { // 94 111
		string str = "resources\\medusa\\Litchi_Flip\\attack2_flip\\attack2Flip_00" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	// attack3 (index: 112 177)
	for (int i = 0; i <= 32; i++) { // 112 144
		string str = "resources\\medusa\\Litchi\\attack3\\attack3_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 32; i++) { // 145 177
		string str = "resources\\medusa\\Litchi_Flip\\attack3_flip\\attack3Flip_0" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}

	// dead (index: 178 195)
	for (int i = 0; i <= 8; i++) { // 178 186
		string str = "resources\\medusa\\Litchi\\dead\\dead_00" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
	for (int i = 0; i <= 8; i++) { // 187 195
		string str = "resources\\medusa\\Litchi_Flip\\dead_flip\\deadFlip_00" + to_string(i) + ".png";
		characterModel[modelCount++] = iLoadImage(const_cast<char*>(str.c_str()));
	}
}





















#endif