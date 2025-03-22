#ifndef CHARACTER_H
#define CHARACTER_H
#include <cstdlib> // For rand()
#include <ctime>   // For srand()
#include <iostream>
using namespace std;

//enum for hero animation states



enum AnimationState {
	MOVE,
	STAND,
	TAIL,
	MOVE_B,
	KICK,
	KICK_B,
	ROAR,
	BITE,
	BITE_B,
	DEAD,
	STAND_B,
	SLASH_B,
	SWING_B,
	DASH_B,
	WALK_B,
	WALK,
	SLASH,
	SWING,
	DASH,
	STOP,


	THRUST,
	THRUST_B,

	PUNCH,
	PUNCH_B,
	HANDATTACK,
	HANDATTACK_B,


	PAUSE,
	//Newly Added
	SWING_ATTACK,
	SWING_ATTACK_B,
	SLAM_ATTACK,
	SLAM_ATTACK_B,
	KICK_ATTACK,
	KICK_ATTACK_B,
	RUN,
	RUN_B,

	DEAD_B,

	ATTACK1,
	ATTACK1_B,

	ATTACK2,
	ATTACK2_B,

	ATTACK3,
	ATTACK3_B,

	ATTACK4,
	ATTACK4_B,

	STARTING,
	STARTING_B,

};



struct Character{
	double hp;
	AnimationState modelState;
	int model[250];
	int modelIndex;
	int moveX, moveY;
	int modelCount;
	bool alive;
	Character() : hp(1000), modelState(STAND_B), modelIndex(0), moveX(100), moveY(0), modelCount(1), alive(true) {}
};

struct Boss{
	double hp;
	AnimationState modelState;
	int model[250];
	int modelIndex;
	int moveX, moveY;
	int modelCount;
	bool alive;
	bool isFollow;
	Boss() : hp(1000), modelState(STAND), modelIndex(1), moveX(2000), moveY(0), modelCount(1), alive(true), isFollow(false){}
};

struct Mobs{
	double hp;
	AnimationState modelState;
	int model[250];
	int modelIndex;
	int moveX, moveY;
	int modelCount;
	bool alive;
	bool isFollow;
	Mobs() : hp(1000), modelState(STAND_B), modelIndex(0), moveX(800), moveY(0), modelCount(1), alive(true), isFollow(true){

	}
	Mobs(int hp, AnimationState modelState, int modelIndex, int moveX, int moveY, int modelCount, bool alive, bool isFollow)
		: hp(hp), modelState(modelState), modelIndex(modelIndex), moveX(moveX), moveY(moveY),
		modelCount(modelCount), alive(alive), isFollow(isFollow) {}

};

struct RagnaBoss{
	double hp;
	AnimationState modelState;
	int model[250];
	int modelIndex;
	int moveX, moveY;
	int modelCount;
	bool alive;
	bool isFollow;
	RagnaBoss() : hp(1000), modelState(STAND_B), modelIndex(0), moveX(2000), moveY(0), modelCount(1), alive(true), isFollow(false){}
};


struct TagerMobs{
	double hp;
	AnimationState modelState;
	int model[250];
	int modelIndex;
	int moveX, moveY;
	int modelCount;
	bool alive;
	bool isFollow;
	TagerMobs() : hp(1000), modelState(STAND_B), modelIndex(0), moveX(800), moveY(0), modelCount(1), alive(true), isFollow(true){

	}
	TagerMobs(int hp, AnimationState modelState, int modelIndex, int moveX, int moveY, int modelCount, bool alive, bool isFollow)
		: hp(hp), modelState(modelState), modelIndex(modelIndex), moveX(moveX), moveY(moveY),
		modelCount(modelCount), alive(alive), isFollow(isFollow) {}

};

struct ArakuneBoss{
	double hp;
	AnimationState modelState;
	int model[250];
	int modelIndex;
	int moveX, moveY;
	int modelCount;
	bool alive;
	bool isFollow;
	ArakuneBoss() : hp(1000), modelState(STAND_B), modelIndex(0), moveX(2100), moveY(0), modelCount(1), alive(true), isFollow(false){}

};

struct MedusaBoss{
	double hp;
	AnimationState modelState;
	int model[250];
	int modelIndex;
	int moveX, moveY;
	int modelCount;
	bool alive;
	bool isFollow;
	MedusaBoss() : hp(1000), modelState(STAND_B), modelIndex(0), moveX(1500), moveY(0), modelCount(1), alive(true), isFollow(true){}

};



//tager animation
void tagerStand(TagerMobs& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 6) { // Stand: 0–6
		boss.modelIndex = 0;
	}
}

void tagerStandB(TagerMobs& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 13) { // Stand_B: 7–13 (Flipped)
		boss.modelIndex = 7;
	}
}

void tagerMove(TagerMobs& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 26) { // Move: 14–26
		boss.modelIndex = 14;
	}
}

void tagerMoveB(TagerMobs& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 39) { // Move_B: 27–39 (Flipped)
		boss.modelIndex = 27;
	}
}

void tagerAttack1(TagerMobs& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 52) { // Attack1: 40–52
		boss.modelIndex = 40;
	}
}

void tagerAttack1B(TagerMobs& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 65) { // Attack1_B: 53–65 (Flipped)
		boss.modelIndex = 53;
	}
}

void tagerAttack2(TagerMobs& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 80) { // Attack2: 66–80
		boss.modelIndex = 66;
	}
}

void tagerAttack2B(TagerMobs& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 95) { // Attack2_B: 81–95 (Flipped)
		boss.modelIndex = 81;
	}
}

void tagerDeath(TagerMobs& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 102) { // Death: 96–102
		boss.modelIndex = 102; // Stop at last frame
	}
}

void tagerDeathB(TagerMobs& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 109) { // Death_B: 103–109 (Flipped)
		boss.modelIndex = 109; // Stop at last frame
	}
}

void tagerStop(TagerMobs& boss) {
	boss.modelIndex = 102; // Stop at last death frame
}

void tagerStopB(TagerMobs& boss) {
	boss.modelIndex = 109; // Stop at last flipped death frame
}



void animateTagerBoss(TagerMobs& boss) {

	switch (boss.modelState) {
	case STAND:
		if (boss.modelIndex < 0 || boss.modelIndex > 6) {
			boss.modelIndex = 0;
		}
		tagerStand(boss);
		break;

	case STAND_B:
		if (boss.modelIndex < 7 || boss.modelIndex > 13) {
			boss.modelIndex = 7;
		}
		tagerStandB(boss);
		break;

	case MOVE:
		if (boss.modelIndex < 14 || boss.modelIndex > 26) {
			boss.modelIndex = 14;
		}
		tagerMove(boss);
		break;

	case MOVE_B:
		if (boss.modelIndex < 27 || boss.modelIndex > 39) {
			boss.modelIndex = 27;
		}
		tagerMoveB(boss);
		break;

	case ATTACK1:
		if (boss.modelIndex < 40 || boss.modelIndex > 52) {
			boss.modelIndex = 40;
		}
		tagerAttack1(boss);
		if (boss.modelIndex == 52) {
			boss.modelState = STAND;
		}
		break;

	case ATTACK1_B:
		if (boss.modelIndex < 53 || boss.modelIndex > 65) {
			boss.modelIndex = 53;
		}
		tagerAttack1B(boss);
		if (boss.modelIndex == 65) {
			boss.modelState = STAND_B;
		}
		break;

	case ATTACK2:
		if (boss.modelIndex < 66 || boss.modelIndex > 80) {
			boss.modelIndex = 66;
		}
		tagerAttack2(boss);
		if (boss.modelIndex == 80) {
			boss.modelState = STAND;
		}
		break;

	case ATTACK2_B:
		if (boss.modelIndex < 81 || boss.modelIndex > 95) {
			boss.modelIndex = 81;
		}
		tagerAttack2B(boss);
		if (boss.modelIndex == 95) {
			boss.modelState = STAND_B;
		}
		break;

	case DEAD:
		if (boss.modelIndex < 96 || boss.modelIndex > 102) {
			boss.modelIndex = 96;
		}
		tagerDeath(boss);
		if (boss.modelIndex == 102) {
			tagerStop(boss);
		}
		break;

	case DEAD_B:
		if (boss.modelIndex < 103 || boss.modelIndex > 109) {
			boss.modelIndex = 103;
		}
		tagerDeathB(boss);
		if (boss.modelIndex == 109) {
			tagerStopB(boss);
		}
		break;

	default:
		break;
	}
}


void followTager(Character& character, TagerMobs& boss) {
	srand(time(0));

	const int attackRange = 120;
	const double moveSpeed = 2;
	static int attackCooldown = 0;  // Cooldown between attacks
	const int maxCooldown = 1;      // Time to wait between attacks
	int distance = character.moveX - boss.moveX;

	if (boss.isFollow && character.alive) {
		// Check if boss is in attack range
		if (abs(distance) <= attackRange) {
			if (attackCooldown <= 0) {
				int randomAttack = rand() % 2;

				if (distance > 0) {
					switch (randomAttack) {
					case 0: boss.modelState = ATTACK1_B; break;
					case 1: boss.modelState = ATTACK2_B; break;
					default: boss.modelState = MOVE_B; break;
					}
				}
				else {
					switch (randomAttack) {
					case 0: boss.modelState = ATTACK1; break;
					case 1: boss.modelState = ATTACK2; break;
					default: boss.modelState = MOVE; break;
					}
				}

				// Set cooldown so attacks don't trigger every frame
				attackCooldown = maxCooldown;
			}
		}
		else {
			// Only move if not attacking
			if (attackCooldown <= 0) {
				if (distance > attackRange) {
					boss.modelState = MOVE_B;
					boss.moveX += moveSpeed;
				}
				else if (distance < -attackRange) {
					boss.modelState = MOVE;
					boss.moveX -= moveSpeed;
				}
			}
		}
	}

	// Handling damage when within attack range
	if (abs(distance) <= attackRange &&
		(boss.modelState == ATTACK1_B || boss.modelState == ATTACK2_B ||
		boss.modelState == ATTACK1 || boss.modelState == ATTACK2) &&
		!(character.modelState == SLASH || character.modelState == SLASH_B ||
		character.modelState == DASH || character.modelState == DASH_B)) {

		if (character.hp > 0) {
			character.hp -= 5;
		}
	}

	// Character dies if HP reaches 0
	if (character.hp <= 0 && character.alive) {
		character.hp = 0;
		character.alive = false;
		character.modelState = DEAD;
		boss.isFollow = false;
	}

	// If character is dead, boss stops attacking/moving and stands still
	if (!character.alive) {
		if (boss.modelState == ATTACK1_B || boss.modelState == ATTACK2_B || boss.modelState == MOVE_B) {
			boss.modelState = STAND_B;
		}
		else if (boss.modelState == ATTACK1 || boss.modelState == ATTACK2 || boss.modelState == MOVE) {
			boss.modelState = STAND;
		}
	}

	// Handling damage when character attacks the boss
	if (abs(distance) <= attackRange &&
		(character.modelState == KICK || character.modelState == KICK_B ||
		character.modelState == SLASH || character.modelState == SLASH_B ||
		character.modelState == SWING || character.modelState == SWING_B ||
		character.modelState == THRUST || character.modelState == THRUST_B)) {

		if (boss.hp > 0) {
			boss.hp -= 10;
		}
	}

	// Boss dies if HP reaches 0
	if (boss.hp <= 0) {
		boss.isFollow = false;
		boss.hp = 0;
		boss.modelState = DEAD;
		boss.alive = false;
	}

	// Decrease attack cooldown each frame
	if (attackCooldown > 0) {
		attackCooldown--;
	}
}
//tager end

//ragna start
void ragnaStand(RagnaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 6) { // Stand: 0–6
		boss.modelIndex = 0;
	}
}

void ragnaStandB(RagnaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 13) { // Stand_B: 7–13 (Flipped)
		boss.modelIndex = 7;
	}
}

void ragnaMove(RagnaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 21) { // Move: 14–21
		boss.modelIndex = 14;
	}
}

void ragnaMoveB(RagnaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 29) {
		boss.modelIndex = 22;
	}
}

void ragnaRun(RagnaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 43) {
		boss.modelIndex = 30;
	}
}

void ragnaRunB(RagnaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 57) {
		boss.modelIndex = 44;
	}
}

void ragnaSwingAttack(RagnaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 73) {
		boss.modelIndex = 58;
	}
}

void ragnaSwingAttackB(RagnaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 89) {
		boss.modelIndex = 74;
	}
}

void ragnaSlamAttack(RagnaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 106) {
		boss.modelIndex = 90;
	}
}

void ragnaSlamAttackB(RagnaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 123) {
		boss.modelIndex = 107;
	}
}

void ragnaKickAttack(RagnaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 140) {
		boss.modelIndex = 124;
	}
}

void ragnaKickAttackB(RagnaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 157) {
		boss.modelIndex = 141;
	}
}



void ragnaStop(RagnaBoss& boss) {
	boss.modelIndex = 169;  // Last frame of normal death animation
}

void ragnaStopB(RagnaBoss& boss) {
	boss.modelIndex = 176;  // Last frame of flipped death animation
}

void ragnaDeath(RagnaBoss& boss) {
	if (boss.modelIndex < 169) { // Only increase if not at the last frame
		boss.modelIndex++;
	}
	else {
		ragnaStop(boss); // Stop at the last frame
	}
}

void ragnaDeathB(RagnaBoss& boss) {
	if (boss.modelIndex < 176) { // Only increase if not at the last frame
		boss.modelIndex++;
	}
	else {
		ragnaStopB(boss); // Stop at the last flipped death frame
	}
}


void animateRagnaBoss(RagnaBoss& boss) {
	switch (boss.modelState) {
	case STAND:
		if (boss.modelIndex < 0 || boss.modelIndex > 6) {
			boss.modelIndex = 0;
		}
		ragnaStand(boss);
		break;

	case STAND_B:
		if (boss.modelIndex < 7 || boss.modelIndex > 13) {
			boss.modelIndex = 7;
		}
		ragnaStandB(boss);
		break;

	case MOVE:
		if (boss.modelIndex < 14 || boss.modelIndex > 21) {
			boss.modelIndex = 14;
		}
		ragnaMove(boss);
		break;

	case MOVE_B:
		if (boss.modelIndex < 22 || boss.modelIndex > 29) {
			boss.modelIndex = 22;
		}
		ragnaMoveB(boss);
		break;

	case RUN:
		if (boss.modelIndex < 30 || boss.modelIndex > 43) {
			boss.modelIndex = 30;
		}
		ragnaRun(boss);
		break;

	case RUN_B:
		if (boss.modelIndex < 44 || boss.modelIndex > 57) {
			boss.modelIndex = 44;
		}
		ragnaRunB(boss);
		break;

	case SWING_ATTACK:
		if (boss.modelIndex < 58 || boss.modelIndex > 73) {
			boss.modelIndex = 58;
		}
		ragnaSwingAttack(boss);
		if (boss.modelIndex == 73) { // Correct transition
			boss.modelState = STAND;
		}
		break;

	case SWING_ATTACK_B:
		if (boss.modelIndex < 74 || boss.modelIndex > 89) {
			boss.modelIndex = 74;
		}
		ragnaSwingAttackB(boss);
		if (boss.modelIndex == 89) {
			boss.modelState = STAND_B;
		}
		break;

	case SLAM_ATTACK:
		if (boss.modelIndex < 90 || boss.modelIndex > 106) {
			boss.modelIndex = 90;
		}
		ragnaSlamAttack(boss);
		if (boss.modelIndex == 106) {
			boss.modelState = STAND;
		}
		break;

	case SLAM_ATTACK_B:
		if (boss.modelIndex < 107 || boss.modelIndex > 123) {
			boss.modelIndex = 107;
		}
		ragnaSlamAttackB(boss);
		if (boss.modelIndex == 123) {
			boss.modelState = STAND_B;
		}
		break;

	case KICK_ATTACK:
		if (boss.modelIndex < 124 || boss.modelIndex > 140) {
			boss.modelIndex = 124;
		}
		ragnaKickAttack(boss);
		if (boss.modelIndex == 140) {
			boss.modelState = STAND;
		}
		break;

	case KICK_ATTACK_B:
		if (boss.modelIndex < 141 || boss.modelIndex > 157) {
			boss.modelIndex = 141;
		}
		ragnaKickAttackB(boss);
		if (boss.modelIndex == 157) {
			boss.modelState = STAND_B;
		}
		break;

	case DEAD:
		if (boss.modelIndex < 158 || boss.modelIndex > 169) {
			boss.modelIndex = 158;
		}
		ragnaDeath(boss);
		if (boss.modelIndex == 169) {
			boss.modelIndex = 169;// Stops at last frame
			ragnaStop(boss);
		}
		break;

	case DEAD_B:
		if (boss.modelIndex < 170 || boss.modelIndex > 176) {
			boss.modelIndex = 170;
		}
		ragnaDeathB(boss);
		if (boss.modelIndex == 176) { // Stops at last frame
			boss.modelIndex = 176;
			ragnaStopB(boss);
		}
		break;

	default:
		break;
	}
}



void followRagna(Character& character, RagnaBoss& boss) {
	srand(time(0));

	const int attackRange = 140; // Matches `follow()` function
	const int moveSpeed = 1;
	static int attackCooldown = 0;
	int distance = character.moveX - boss.moveX;

	if (boss.isFollow) {
		// If within attack range and cooldown allows, perform an attack
		if (abs(distance) <= attackRange && attackCooldown <= 0) {
			int randomAttack = rand() % 3;

			// Attack in appropriate direction
			if (distance > 0) {
				switch (randomAttack) {
				case 0: boss.modelState = KICK_ATTACK_B; break;
				case 1: boss.modelState = SWING_ATTACK_B; break;
				case 2: boss.modelState = SLAM_ATTACK_B; break;
				default: boss.modelState = STAND_B; break;
				}
			}
			else {
				switch (randomAttack) {
				case 0: boss.modelState = KICK_ATTACK; break;
				case 1: boss.modelState = SWING_ATTACK; break;
				case 2: boss.modelState = SLAM_ATTACK; break;
				default: boss.modelState = STAND; break;
				}
			}

			attackCooldown = 250;  // Reset attack cooldown (matches `follow()`)
		}

		// If out of attack range, move towards character
		else {
			if (distance > attackRange) {
				boss.modelState = MOVE_B;
				boss.moveX += moveSpeed;
			}
			else if (distance < -attackRange) {
				boss.modelState = MOVE;
				boss.moveX -= moveSpeed;
			}
		}
	}

	// Damage Handling when the boss successfully hits the character
	if (abs(distance) <= attackRange &&
		(boss.modelState == KICK_ATTACK || boss.modelState == SWING_ATTACK || boss.modelState == SLAM_ATTACK ||
		boss.modelState == KICK_ATTACK_B || boss.modelState == SWING_ATTACK_B || boss.modelState == SLAM_ATTACK_B) &&
		!(character.modelState == SLASH || character.modelState == SLASH_B || character.modelState == DASH || character.modelState == DASH_B)) {

		if (character.hp > 0) {
			character.hp -= 1;
		}
	}

	// Character Death Handling
	if (character.hp <= 0 && character.alive) {
		character.hp = 0;
		character.alive = false;
		character.modelState = DEAD;
	}

	// Boss stops attacking if the character is dead
	if (character.hp == 0) {
		boss.modelState = STAND;
	}

	// Character attacking the boss
	if (abs(distance) <= attackRange &&
		(character.modelState == KICK || character.modelState == KICK_B ||
		character.modelState == SLASH || character.modelState == SLASH_B ||
		character.modelState == SWING || character.modelState == SWING_B ||
		character.modelState == THRUST || character.modelState == THRUST_B)) {

		if (boss.hp > 0) {
			boss.hp -= 1;
		}
		cout << "Boss HP: " << boss.hp << endl;
	}

	// Boss Death Handling
	if (boss.hp <= 0 && (boss.modelState == KICK_ATTACK || boss.modelState == SWING_ATTACK || boss.modelState == SLAM_ATTACK || boss.modelState == STAND || boss.modelState == MOVE)) {
		boss.hp = 0;
		boss.modelState = DEAD;
		boss.isFollow = false;
		boss.alive = false;
	}

	else if (boss.hp <= 0 && (boss.modelState == KICK_ATTACK_B || boss.modelState == SWING_ATTACK_B || boss.modelState == SLAM_ATTACK_B || boss.modelState == STAND_B || boss.modelState == MOVE_B)) {
		boss.hp = 0;
		boss.modelState = DEAD_B;
		boss.isFollow = false;
		boss.alive = false;
	}

	// Reduce attack cooldown over time
	if (attackCooldown > 0) {
		attackCooldown--;
	}
}
//ragna end



void walk_mob(Mobs& mobs) {
	mobs.modelIndex++;
	if (mobs.modelIndex > 11) { // Walk: 0–11
		mobs.modelIndex = 0;
	}
}

void bwalk_mob(Mobs& mobs) {
	mobs.modelIndex++;
	if (mobs.modelIndex > 23) { // Backward Walk: 12–23
		mobs.modelIndex = 12;
	}
}

void stand_mob(Mobs& mobs) {
	mobs.modelIndex++;
	if (mobs.modelIndex > 40) { // Standing: 24–40
		mobs.modelIndex = 24;
	}
}

void bstand_mob(Mobs& mobs) {
	mobs.modelIndex++;
	if (mobs.modelIndex > 57) { // Backward Standing: 41–57
		mobs.modelIndex = 41;
	}
}

void bite_mob(Mobs& mobs) {
	mobs.modelIndex++;
	if (mobs.modelIndex > 68) { // Bite: 58–68
		mobs.modelIndex = 58;
	}
}

void bbite_mob(Mobs& mobs) {
	mobs.modelIndex++;
	if (mobs.modelIndex > 79) { // Backward Bite: 69–79
		mobs.modelIndex = 69;
	}
}

void handattack_mob(Mobs& mobs) {
	mobs.modelIndex++;
	if (mobs.modelIndex > 90) { // Hand Attack: 80–90
		mobs.modelIndex = 80;
	}
}

void bhandattack_mob(Mobs& mobs) {
	mobs.modelIndex++;
	if (mobs.modelIndex > 101) { // Backward Hand Attack: 91–101
		mobs.modelIndex = 91;
	}
}

void punch_mob(Mobs& mobs) {
	mobs.modelIndex++;
	if (mobs.modelIndex > 110) { // Punch: 102–110
		mobs.modelIndex = 102;
	}
}

void bpunch_mob(Mobs& mobs) {
	mobs.modelIndex++;
	if (mobs.modelIndex > 119) { // Backward Punch: 111–119
		mobs.modelIndex = 111;
	}
}

void dead_mob(Mobs& mobs) {
	mobs.modelIndex++;
	if (mobs.modelIndex > 128) { // Death Animation: 120–128
		mobs.modelIndex = 128;
	}
}

void stop_mob(Mobs& mobs) {
	mobs.modelIndex = 128; // Stop at the last frame of the dead animation
}


void animateMobs(Mobs& mobs) {
	switch (mobs.modelState) {
	case MOVE:
		if (mobs.modelIndex < 0 || mobs.modelIndex > 11) {
			mobs.modelIndex = 0;
		}
		walk_mob(mobs);
		break;

	case MOVE_B:
		if (mobs.modelIndex < 12 || mobs.modelIndex > 23) {
			mobs.modelIndex = 12;
		}
		bwalk_mob(mobs);
		break;

	case STAND:
		if (mobs.modelIndex < 24 || mobs.modelIndex > 40) {
			mobs.modelIndex = 24;
		}
		stand_mob(mobs);
		break;

	case STAND_B:
		if (mobs.modelIndex < 41 || mobs.modelIndex > 57) {
			mobs.modelIndex = 41;
		}
		bstand_mob(mobs);
		break;

	case BITE:
		if (mobs.modelIndex < 58 || mobs.modelIndex > 68) {
			mobs.modelIndex = 58;
		}
		bite_mob(mobs);

		break;

	case BITE_B:
		if (mobs.modelIndex < 69 || mobs.modelIndex > 79) {
			mobs.modelIndex = 69;
		}
		bbite_mob(mobs);

		break;

	case HANDATTACK:
		if (mobs.modelIndex < 80 || mobs.modelIndex > 90) {
			mobs.modelIndex = 80;
		}
		handattack_mob(mobs);

		break;

	case HANDATTACK_B:
		if (mobs.modelIndex < 91 || mobs.modelIndex > 101) {
			mobs.modelIndex = 91;
		}
		bhandattack_mob(mobs);

		break;

	case PUNCH:
		if (mobs.modelIndex < 102 || mobs.modelIndex > 110) {
			mobs.modelIndex = 102;
		}
		punch_mob(mobs);

		break;

	case PUNCH_B:
		if (mobs.modelIndex < 111 || mobs.modelIndex > 119) {
			mobs.modelIndex = 111;
		}
		bpunch_mob(mobs);

		break;

	case DEAD:
		if (mobs.modelIndex < 120 || mobs.modelIndex > 128) {
			mobs.modelIndex = 120;
		}
		dead_mob(mobs);
		if (mobs.modelIndex == 128) {
			stop_mob(mobs);
		}
		break;

	default:
		break;
	}
}





void stand(Character& character) {
	character.modelIndex++;
	if (character.modelIndex > 9) {
		character.modelIndex = 1;
	}
}

void standB(Character& character) {
	character.modelIndex++;
	if (character.modelIndex > 19) {
		character.modelIndex = 10;
	}
}

void walkB(Character& character) {
	character.modelIndex++;
	if (character.modelIndex > 28) {
		character.modelIndex = 20;
	}
}

void walk(Character& character) {
	character.modelIndex++;
	if (character.modelIndex > 37) {
		character.modelIndex = 29;
	}
}

void kickB(Character& character) {
	character.modelIndex++;
	if (character.modelIndex > 48) {
		character.modelIndex = 38;
	}
}

void kick(Character& character) {
	character.modelIndex++;
	if (character.modelIndex > 59) {
		character.modelIndex = 49;
	}
}

void slashB(Character& character) {
	character.modelIndex++;
	character.moveX += 30;
	if (character.modelIndex > 79) {
		character.modelIndex = 60;
	}
}

void slash(Character& character) {
	character.modelIndex++;
	character.moveX -= 30;
	if (character.modelIndex > 99) {
		character.modelIndex = 90;
	}
}

void swingB(Character& character) {
	character.modelIndex++;
	if (character.modelIndex > 116) {
		character.modelIndex = 100;
	}
}

void swing(Character& character) {
	character.modelIndex++;
	if (character.modelIndex > 133) {
		character.modelIndex = 117;
	}
}

void dashB(Character& character) {
	character.modelIndex++;
	character.moveX += 60;
	if (character.modelIndex > 141) {
		character.modelIndex = 134;
	}
}

void dash(Character& character) {
	character.modelIndex++;
	character.moveX -= 60;
	if (character.modelIndex > 149) {
		character.modelIndex = 142;
	}
}

void dead(Character& character) {
	character.modelIndex++;
	if (character.modelIndex > 161) {
		character.modelIndex = 150;
	}
}

void stop(Character& character) {
	character.modelIndex = 161;
}

void thrust(Character& character) {
	character.modelIndex++;
	if (character.modelIndex>173)
	{
		character.modelIndex = 162;
	}
}
void thrustB(Character& character) {
	character.modelIndex++;
	if (character.modelIndex>185)
	{
		character.modelIndex = 174;
	}
}



//=============================================


void move(Boss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 12) { // Walk: 0–12
		boss.modelIndex = 1;  // Reset to start index for walk
	}
}

void tailAttack(Boss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 23) { // Tail Attack: 13–23
		boss.modelIndex = 13;  // Reset to start index for tail attack
	}
}

void moveB(Boss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 36) { // Backward Walk: 24–36
		boss.modelIndex = 25;  // Reset to start index for backward walk
	}
}

void standing(Boss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 46) { // Standing: 37–46
		boss.modelIndex = 37;  // Reset to start index for standing
	}
}

void kickAttack(Boss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 59) { // Kick Attack: 47–59
		boss.modelIndex = 47;  // Reset to start index for kick attack
	}
}

void kickAttackB(Boss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 72) { // Backward Kick: 60–72
		boss.modelIndex = 60;  // Reset to start index for backward kick
	}
}

void roarAttack(Boss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 82) {
		boss.modelIndex = 73;
	}
}

void biteAttack(Boss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 103) {
		boss.modelIndex = 83;
	}
}

void biteAttackB(Boss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 112) {
		boss.modelIndex = 104;
	}
}

void dead(Boss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 123) {
		boss.modelIndex = 123;
	}
}

void stop(Boss& boss) {
	boss.modelIndex = 123;
}





void animateChar(Character& character) {
	switch (character.modelState) {
	case STOP:
		stop(character);
		break;

	case STAND:
		if (character.modelIndex > 9) {
			character.modelIndex = 1;
		}
		stand(character);
		break;

	case STAND_B:
		if (character.modelIndex < 10 || character.modelIndex > 19) {
			character.modelIndex = 10;
		}
		standB(character);
		break;

	case WALK_B:
		if (character.modelIndex < 20 || character.modelIndex > 28) {
			character.modelIndex = 20;
		}
		walkB(character);
		if (character.modelIndex == 28) {
			character.modelState = STAND_B;
		}
		break;

	case WALK:
		if (character.modelIndex < 29 || character.modelIndex > 37) {
			character.modelIndex = 29;
		}
		walk(character);
		if (character.modelIndex == 37) {
			character.modelState = STAND;
		}
		break;

	case KICK_B:
		if (character.modelIndex < 38 || character.modelIndex > 48) {
			character.modelIndex = 38;
		}
		kickB(character);
		if (character.modelIndex == 48) {
			character.modelState = STAND_B;
		}
		break;

	case KICK:
		if (character.modelIndex < 49 || character.modelIndex > 59) {
			character.modelIndex = 49;
		}
		kick(character);
		if (character.modelIndex == 59) {
			character.modelState = STAND;
		}
		break;

	case SLASH_B:
		if (character.modelIndex < 60 || character.modelIndex > 79) {
			character.modelIndex = 60;
		}
		slashB(character);
		if (character.modelIndex == 79) {
			character.modelState = STAND_B;
		}
		break;

	case SLASH:
		if (character.modelIndex < 80 || character.modelIndex > 99) {
			character.modelIndex = 80;
		}
		slash(character);
		if (character.modelIndex == 99) {
			character.modelState = STAND;
		}
		break;

	case SWING_B:
		if (character.modelIndex < 100 || character.modelIndex > 116) {
			character.modelIndex = 100;
		}
		swingB(character);
		if (character.modelIndex == 116) {
			character.modelState = STAND_B;
		}
		break;

	case SWING:
		if (character.modelIndex < 117 || character.modelIndex > 133) {
			character.modelIndex = 117;
		}
		swing(character);
		if (character.modelIndex == 133) {
			character.modelState = STAND;
		}
		break;

	case DASH_B:
		if (character.modelIndex < 134 || character.modelIndex > 141) {
			character.modelIndex = 134;
		}
		dashB(character);
		if (character.modelIndex == 141) {
			character.modelState = STAND_B;
		}
		break;

	case DASH:
		if (character.modelIndex < 142 || character.modelIndex > 149) {
			character.modelIndex = 142;
		}
		dash(character);
		if (character.modelIndex == 149) {
			character.modelState = STAND;
		}
		break;


	case DEAD:
		if (character.modelIndex < 150 || character.modelIndex > 161) {
			character.modelIndex = 150;
		}
		dead(character);
		if (character.modelIndex == 161) {
			character.modelState = STOP;
		}
		break;
	case THRUST:
		if (character.modelIndex<162 || character.modelIndex>173)
		{
			character.modelIndex = 162;
		}

		thrust(character);
		if (character.modelIndex == 173)
		{
			character.modelState = STAND;
		}
		break;
	case THRUST_B:
		if (character.modelIndex<174 || character.modelIndex>185)
		{
			character.modelIndex = 174;
		}

		thrustB(character);
		if (character.modelIndex == 185)
		{
			character.modelState = STAND_B;
		}
		break;


	default:
		break;
	}
}
void animateBoss(Boss& boss) {
	switch (boss.modelState) {
	case MOVE:
		if (boss.modelIndex < 0 || boss.modelIndex > 12) {
			boss.modelIndex = 0;
		}
		move(boss);
		break;

	case MOVE_B:
		if (boss.modelIndex < 24 || boss.modelIndex > 36) {
			boss.modelIndex = 24;
		}
		moveB(boss);
		break;

	case STAND:
		if (boss.modelIndex < 37 || boss.modelIndex > 46) {
			boss.modelIndex = 37;
		}
		standing(boss);
		break;

	case TAIL:
		if (boss.modelIndex < 13 || boss.modelIndex > 23) {
			boss.modelIndex = 13;
		}
		tailAttack(boss);
		break;

	case KICK:
		if (boss.modelIndex < 47 || boss.modelIndex > 59) {
			boss.modelIndex = 47;
		}
		kickAttack(boss);
		break;

	case KICK_B:
		if (boss.modelIndex < 60 || boss.modelIndex > 72) {
			boss.modelIndex = 60;
		}
		kickAttackB(boss);
		break;

	case ROAR:
		if (boss.modelIndex < 73 || boss.modelIndex > 82) {
			boss.modelIndex = 73;
		}
		roarAttack(boss);
		break;

	case BITE:
		if (boss.modelIndex < 83 || boss.modelIndex > 103) {
			boss.modelIndex = 83;
		}
		biteAttack(boss);
		break;

	case BITE_B:
		if (boss.modelIndex < 104 || boss.modelIndex > 112) {
			boss.modelIndex = 104;
		}
		biteAttackB(boss);
		break;

	case DEAD:
		if (boss.modelIndex < 113 || boss.modelIndex > 123) {
			boss.modelIndex = 113;
		}
		dead(boss);
		if (boss.modelIndex == 123) {
			stop(boss);
		}
		break;

	default:
		break;
	}
}



void follow(Character& character, Boss& boss) {

	srand(time(0));


	const int attackRange = 120; // previous value was 90
	const int moveSpeed = 2;
	static int attackCooldown = 0;
	int distance = character.moveX - boss.moveX;


	if (boss.isFollow) {

		if (abs(distance) <= attackRange) {
			if (attackCooldown <= 0) {

				int randomAttack = rand() % 3;


				if (distance > 0) {

					switch (randomAttack) {
					case 0:
						boss.modelState = KICK_B;
						break;
					case 1:
						boss.modelState = BITE_B;
						break;
					case 2:
						boss.modelState = ROAR;
						break;
					default:
						boss.modelState = MOVE_B;
						break;
					}
				}
				else {

					switch (randomAttack) {
					case 0:
						boss.modelState = KICK;
						break;
					case 1:
						boss.modelState = BITE;
						break;
					case 2:
						boss.modelState = ROAR;
						break;
					default:
						boss.modelState = MOVE;
						break;
					}
				}


				attackCooldown = 50;
			}
		}
		else {

			if (distance > attackRange) {
				boss.modelState = MOVE_B;
				boss.moveX += moveSpeed;
			}
			else if (distance < -attackRange) {
				boss.modelState = MOVE;
				boss.moveX -= moveSpeed;
			}
		}
	}

	// Handling damage when within attack range
	if (abs(distance) <= attackRange &&
		(boss.modelState == KICK || boss.modelState == BITE || boss.modelState == KICK_B || boss.modelState == BITE_B) &&
		!(character.modelState == SLASH || character.modelState == SLASH_B || character.modelState == DASH || character.modelState == DASH_B)) {

		if (character.hp > 0) {
			character.hp -= 5;
		}

		//cout << "Character HP: " << character.hp << endl;
	}

	// If the character's HP is 0 or below, set character as dead
	if (character.hp <= 0 && character.alive) {
		character.alive = false;
		character.modelState = DEAD;
		character.hp = 0;

	}

	if (character.hp == 0)
	{
		boss.modelState = STAND;
	}

	// Handling damage when the character attacks the boss
	if (abs(distance) <= attackRange &&
		(character.modelState == KICK || character.modelState == KICK_B ||
		character.modelState == SLASH || character.modelState == SLASH_B ||
		character.modelState == SWING || character.modelState == SWING_B || character.modelState == THRUST || character.modelState == THRUST_B)) {

		if (boss.hp > 0) {
			boss.hp -= 1;
		}

		cout << "Boss HP: " << boss.hp << endl;
	}

	// If the boss's HP is 0 or below, set boss as dead and stop following
	if (boss.hp <= 0) {
		boss.isFollow = false;
		boss.alive = false;
		boss.modelState = DEAD;
		boss.hp = 0;

	}

	// Decrease the attack cooldown over time
	if (attackCooldown > 0) {
		attackCooldown--;
	}

	
}


void mob_follow(Character& character, Mobs& mob) {
	srand(time(0));

	const int attackRange = 170;
	const double moveSpeed = 1;
	static int attackCooldown = 0;  // Cooldown between attacks
	const int maxCooldown = 1;     // Time to wait between attacks
	int distance = character.moveX - mob.moveX;




	if (mob.isFollow && character.alive) {
		// Check if mob is in attack range
		if (abs(distance) <= attackRange) {
			if (attackCooldown <= 0) {
				int randomAttack = rand() % 3;

				if (distance > 0) {
					switch (randomAttack) {
					case 0: mob.modelState = PUNCH; break;
					case 1: mob.modelState = HANDATTACK; break;
					case 2: mob.modelState = BITE; break;
					default: mob.modelState = MOVE; break;
					}
				}
				else {
					switch (randomAttack) {
					case 0: mob.modelState = PUNCH_B; break;
					case 1: mob.modelState = HANDATTACK_B; break;
					case 2: mob.modelState = BITE_B; break;
					default: mob.modelState = MOVE_B; break;
					}
				}

				// Set cooldown so attacks don't trigger every frame
				attackCooldown = maxCooldown;
			}
		}
		else {
			// Only move if not attacking
			if (attackCooldown <= 0) {
				if (distance > attackRange) {
					mob.modelState = MOVE;
					mob.moveX += moveSpeed;
				}
				else if (distance < -attackRange) {
					mob.modelState = MOVE_B;
					mob.moveX -= moveSpeed;
				}
			}
		}
	}

	// Handling damage when within attack range
	if (abs(distance) <= attackRange &&
		(mob.modelState == PUNCH_B || mob.modelState == HANDATTACK_B || mob.modelState == PUNCH || mob.modelState == HANDATTACK || mob.modelState == BITE || mob.modelState == BITE_B) &&
		!(character.modelState == SLASH || character.modelState == SLASH_B || character.modelState == DASH || character.modelState == DASH_B)) {

		if (character.hp > 0) {
			character.hp -= 3;
		}
	}

	// Character dies if HP reaches 0
	if (character.hp <= 0 && character.alive) {
		character.hp = 0;
		character.alive = false;
		character.modelState = DEAD;
		mob.isFollow = false;


	}

	if (!(character.alive)) {
		if (mob.modelState == PUNCH_B || mob.modelState == HANDATTACK_B || mob.modelState == BITE_B || mob.modelState == MOVE_B)
		{
			mob.modelState = STAND_B;

		}

		else if (mob.modelState == PUNCH || mob.modelState == HANDATTACK || mob.modelState == BITE || mob.modelState == MOVE)
		{
			mob.modelState = STAND;
		}
	}

	// Handling damage when the character attacks the mob
	if (abs(distance) <= attackRange &&
		(character.modelState == KICK || character.modelState == KICK_B ||
		character.modelState == SLASH || character.modelState == SLASH_B ||
		character.modelState == SWING || character.modelState == SWING_B ||
		character.modelState == THRUST || character.modelState == THRUST_B)) {

		if (mob.hp > 0) {
			mob.hp -= 10;
		}
	}

	// Mob dies if HP reaches 0
	if (mob.hp <= 0) {
		mob.isFollow = false;
		mob.hp = 0;
		mob.modelState = DEAD;
		mob.alive = false;
	}

	// Decrease attack cooldown each frame
	if (attackCooldown > 0) {
		attackCooldown--;
	}
}


void medusaStand(MedusaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 8) { // Stand: 0–8
		boss.modelIndex = 0;
	}
}

void medusaStandB(MedusaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 17) { // Stand Mirrored: 9–17
		boss.modelIndex = 9;
	}
}

void medusaWalk(MedusaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 31) { // Walk: 18–31
		boss.modelIndex = 18;
	}
}

void medusaWalkB(MedusaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 45) { // Walk Mirrored: 32–45
		boss.modelIndex = 32;
	}
}

void medusaAttack1(MedusaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 60) { // Attack 1: 46–60
		boss.modelIndex = 46;
	}
}

void medusaAttack1B(MedusaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 75) { // Attack 1 Mirrored: 61–75
		boss.modelIndex = 61;
	}
}

void medusaAttack2(MedusaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 93) { // Attack 2: 76–93
		boss.modelIndex = 76;
	}
}

void medusaAttack2B(MedusaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 111) { // Attack 2 Mirrored: 94–111
		boss.modelIndex = 94;
	}
}

void medusaAttack3(MedusaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 144) { // Attack 3: 112–144
		boss.modelIndex = 112;
	}
}

void medusaAttack3B(MedusaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 177) { // Attack 3 Mirrored: 145–177
		boss.modelIndex = 145;
	}
}

void medusaDead(MedusaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 186) { // Dead: 178–186
		boss.modelIndex = 178;
	}
}

void medusaDeadB(MedusaBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 195) { // Dead Mirrored: 187–195
		boss.modelIndex = 187;
	}
}

void medusaStop(MedusaBoss& boss) {
	boss.modelIndex = 186;
	//boss.isFollow = false; 
	//boss.alive = false;    
}

void medusaStopB(MedusaBoss& boss) {
	boss.modelIndex = 195;
	//boss.isFollow = false; 
	//boss.alive = false;    
}



void animateMedusa(MedusaBoss& boss) {
	switch (boss.modelState) {
	case MOVE:
		if (boss.modelIndex < 18 || boss.modelIndex > 31) {
			boss.modelIndex = 18;
		}
		medusaWalk(boss);
		break;

	case MOVE_B:
		if (boss.modelIndex < 32 || boss.modelIndex > 45) {
			boss.modelIndex = 32;
		}
		medusaWalkB(boss);
		break;

	case STAND:
		if (boss.modelIndex < 0 || boss.modelIndex > 8) {
			boss.modelIndex = 0;
		}
		medusaStand(boss);
		break;

	case STAND_B:
		if (boss.modelIndex < 9 || boss.modelIndex > 17) {
			boss.modelIndex = 9;
		}
		medusaStandB(boss);
		break;

	case ATTACK1:
		if (boss.modelIndex < 46 || boss.modelIndex > 60) {
			boss.modelIndex = 46;
		}
		medusaAttack1(boss);
		if (boss.modelIndex == 60) {
			boss.modelState = STAND;
		}
		break;

	case ATTACK1_B:
		if (boss.modelIndex < 61 || boss.modelIndex > 75) {
			boss.modelIndex = 61;
		}
		medusaAttack1B(boss);
		if (boss.modelIndex == 75) {
			boss.modelState = STAND_B;
		}
		break;

	case ATTACK2:
		if (boss.modelIndex < 76 || boss.modelIndex > 93) {
			boss.modelIndex = 76;
		}
		medusaAttack2(boss);
		if (boss.modelIndex == 93) {
			boss.modelState = STAND;
		}
		break;

	case ATTACK2_B:
		if (boss.modelIndex < 94 || boss.modelIndex > 111) {
			boss.modelIndex = 94;
		}
		medusaAttack2B(boss);
		if (boss.modelIndex == 111) {
			boss.modelState = STAND_B;
		}
		break;

	case ATTACK3:
		if (boss.modelIndex < 112 || boss.modelIndex > 144) {
			boss.modelIndex = 112;
		}
		medusaAttack3(boss);
		if (boss.modelIndex == 144) {
			boss.modelState = STAND;
		}
		break;

	case ATTACK3_B:
		if (boss.modelIndex < 145 || boss.modelIndex > 177) {
			boss.modelIndex = 145;
		}
		medusaAttack3B(boss);
		if (boss.modelIndex == 177) {
			boss.modelState = STAND_B;
		}
		break;

	case DEAD:
		if (boss.modelIndex == 186) {
			break;
		}
		if (boss.modelIndex < 178 || boss.modelIndex > 186) {
			boss.modelIndex = 178;
		}
		medusaDead(boss);
		if (boss.modelIndex == 186) {
			medusaStop(boss);
			boss.modelIndex = 186;
		}
		break;

	case DEAD_B:
		if (boss.modelIndex == 195) {
			break;
		}
		if (boss.modelIndex < 187 || boss.modelIndex > 195) {
			boss.modelIndex = 187;
		}
		medusaDeadB(boss);
		if (boss.modelIndex == 195) {
			medusaStopB(boss);
		}
		break;

	default:
		break;
	}
}





void followMedusa(Character& character, MedusaBoss& boss) {
	srand(time(0));

	const int attackRange = 140;
	const int moveSpeed = 1;
	static int attackCooldown = 0;
	int distance = character.moveX - boss.moveX;

	if (boss.isFollow && boss.alive) {
		// Attack when in range and cooldown is over
		if (abs(distance) <= attackRange && attackCooldown <= 0) {
			int randomAttack = rand() % 3; // Selects from 3 attacks

			if (distance > 0) { // Character is to the right of Medusa
				switch (randomAttack) {
				case 0: boss.modelState = ATTACK1_B; break;  // Index: 61-75
				case 1: boss.modelState = ATTACK2_B; break;  // Index: 94-111
				case 2: boss.modelState = ATTACK3_B; break;  // Index: 145-177
				default: boss.modelState = STAND_B; break;   // Index: 9-17
				}
			}
			else { // Character is to the left of Medusa
				switch (randomAttack) {
				case 0: boss.modelState = ATTACK1; break;  // Index: 46-60
				case 1: boss.modelState = ATTACK2; break;  // Index: 76-93
				case 2: boss.modelState = ATTACK3; break;  // Index: 112-144
				default: boss.modelState = STAND; break;   // Index: 0-8
				}
			}
			attackCooldown = 220;
		}
		// Move toward the character if not in attack range
		else {
			if (distance > attackRange) {
				boss.modelState = MOVE_B; // Index: 32-45
				boss.moveX += moveSpeed;
			}
			else if (distance < -attackRange) {
				boss.modelState = MOVE; // Index: 18-31
				boss.moveX -= moveSpeed;
			}
		}
	}

	// Damage Handling when Medusa attacks
	if (abs(distance) <= attackRange &&
		(boss.modelState == ATTACK1 || boss.modelState == ATTACK2 || boss.modelState == ATTACK3 ||
		boss.modelState == ATTACK1_B || boss.modelState == ATTACK2_B || boss.modelState == ATTACK3_B) &&
		!(character.modelState == SLASH || character.modelState == SLASH_B || character.modelState == DASH || character.modelState == DASH_B)) {

		if (character.hp > 0) {
			character.hp -= 5;
		}
	}

	// Character Death Handling
	if (character.hp <= 0 && character.alive) {
		character.hp = 0;
		character.alive = false;
		character.modelState = DEAD;
	}

	// If character is dead, Medusa stops attacking
	if (character.hp == 0) {
		boss.modelState = STAND;
	}

	// Character attacking Medusa
	if (abs(distance) <= attackRange &&
		(character.modelState == KICK || character.modelState == KICK_B ||
		character.modelState == SLASH || character.modelState == SLASH_B ||
		character.modelState == SWING || character.modelState == SWING_B ||
		character.modelState == THRUST || character.modelState == THRUST_B)) {

		if (boss.hp > 0) {
			boss.hp -= 1;
		}
		cout << "Boss HP: " << boss.hp << endl;
	}

	// Medusa Death Handling
	if (boss.hp <= 0) {
		boss.hp = 0;
		boss.isFollow = false;
		boss.alive = false;
		boss.modelState = DEAD; // Index: 178-186 (left) or 187-195 (right)
	}

	// Reduce attack cooldown over time
	if (attackCooldown > 0) {
		attackCooldown--;
	}
}


//================================================================================= Medusa end  ==========================================================================================//



//================================================================================= Arakune start ========================================================================================//

//void arakuneStand(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 13) { // Stand: 0–13
//		boss.modelIndex = 0;
//	}
//}
//
//void arakuneWalk(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 39) { // Walk: 28–39
//		boss.modelIndex = 28;
//	}
//}
//
//void arakuneAttack1(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 57) { // Attack 1: 51–57
//		boss.modelIndex = 51;
//	}
//}
//
//void arakuneAttack2(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 77) { // Attack 2: 65–77
//		boss.modelIndex = 65;
//	}
//}
//
//void arakuneAttack3(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 110) { // Attack 3: 91–110
//		boss.modelIndex = 91;
//	}
//}
//
//void arakuneAttack4(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 140) { // Attack 4: 131–140
//		boss.modelIndex = 131;
//	}
//}
//
//void arakuneDead(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 166) { // Dead: 151–166
//		boss.modelIndex = 151;
//	}
//}
//
//void arakuneStarting(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 195) { // Starting: 183–195
//		boss.modelIndex = 183;
//	}
//}
//
//// Mirrored Animations
//
//void arakuneStandB(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 27) { // Stand Mirrored: 14–27
//		boss.modelIndex = 14;
//	}
//}
//
//void arakuneWalkB(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 50) { // Walk Mirrored: 40–50
//		boss.modelIndex = 40;
//	}
//}
//
//void arakuneAttack1B(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 64) { // Attack 1 Mirrored: 58–64
//		boss.modelIndex = 58;
//	}
//}
//
//void arakuneAttack2B(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 90) { // Attack 2 Mirrored: 78–90
//		boss.modelIndex = 78;
//	}
//}
//
//void arakuneAttack3B(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 130) { // Attack 3 Mirrored: 111–130
//		boss.modelIndex = 111;
//	}
//}
//
//void arakuneAttack4B(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 150) { // Attack 4 Mirrored: 141–150
//		boss.modelIndex = 141;
//	}
//}
//
//void arakuneDeadB(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 182) { // Dead Mirrored: 167–182
//		boss.modelIndex = 167;
//	}
//}
//
//void arakuneStartingB(ArakuneBoss& boss) {
//	boss.modelIndex++;
//	if (boss.modelIndex > 208) { // Starting Mirrored: 196–208
//		boss.modelIndex = 196;
//	}
//}

void arakuneStand(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 13) { // Stand: 0–13
		boss.modelIndex = 0;
	}
}

void arakuneWalk(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 36) { // Walk: 28–36
		boss.modelIndex = 28;
	}
}

void arakuneAttack1(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 52) { // Attack 1: 46–52
		boss.modelIndex = 46;
	}
}

void arakuneAttack2(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 72) { // Attack 2: 60–72
		boss.modelIndex = 60;
	}
}

void arakuneAttack3(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 105) { // Attack 3: 86–105
		boss.modelIndex = 86;
	}
}

void arakuneAttack4(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 135) { // Attack 4: 126–135
		boss.modelIndex = 126;
	}
}

void arakuneDead(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 161) { // Dead: 146–161
		boss.modelIndex = 146;
	}
}

void arakuneStarting(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 190) { // Starting: 178–190
		boss.modelIndex = 178;
	}
}

// **Mirrored Animations**

void arakuneStandB(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 27) { // Stand Mirrored: 14–27
		boss.modelIndex = 14;
	}
}

void arakuneWalkB(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 45) { // Walk Mirrored: 37–45
		boss.modelIndex = 37;
	}
}

void arakuneAttack1B(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 59) { // Attack 1 Mirrored: 53–59
		boss.modelIndex = 53;
	}
}

void arakuneAttack2B(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 85) { // Attack 2 Mirrored: 73–85
		boss.modelIndex = 73;
	}
}

void arakuneAttack3B(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 125) { // Attack 3 Mirrored: 106–125
		boss.modelIndex = 106;
	}
}

void arakuneAttack4B(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 145) { // Attack 4 Mirrored: 136–145
		boss.modelIndex = 136;
	}
}

void arakuneDeadB(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 177) { // Dead Mirrored: 162–177
		boss.modelIndex = 162;
	}
}

void arakuneStartingB(ArakuneBoss& boss) {
	boss.modelIndex++;
	if (boss.modelIndex > 203) { // Starting Mirrored: 191–203
		boss.modelIndex = 191;
	}
}

void arakuneStop(ArakuneBoss& boss){
	boss.modelIndex = 161;
}

void arakuneStopB(ArakuneBoss& boss){
	boss.modelIndex = 177;
}



//void animateArakune(ArakuneBoss& boss) {
//	switch (boss.modelState) {
//	case MOVE:
//		if (boss.modelIndex < 28 || boss.modelIndex > 39) {
//			boss.modelIndex = 28;
//		}
//		arakuneWalk(boss);
//		break;
//
//	case MOVE_B:
//		if (boss.modelIndex < 40 || boss.modelIndex > 50) {
//			boss.modelIndex = 40;
//		}
//		arakuneWalkB(boss);
//		break;
//
//	case STAND:
//		if (boss.modelIndex < 0 || boss.modelIndex > 13) {
//			boss.modelIndex = 0;
//		}
//		arakuneStand(boss);
//		break;
//
//	case STAND_B:
//		if (boss.modelIndex < 14 || boss.modelIndex > 27) {
//			boss.modelIndex = 14;
//		}
//		arakuneStandB(boss);
//		break;
//
//	case ATTACK1:
//		if (boss.modelIndex < 51 || boss.modelIndex > 57) {
//			boss.modelIndex = 51;
//		}
//		arakuneAttack1(boss);
//		if (boss.modelIndex == 57) {
//			boss.modelState = STAND;
//		}
//		break;
//
//	case ATTACK1_B:
//		if (boss.modelIndex < 58 || boss.modelIndex > 64) {
//			boss.modelIndex = 58;
//		}
//		arakuneAttack1B(boss);
//		if (boss.modelIndex == 64) {
//			boss.modelState = STAND_B;
//		}
//		break;
//
//	case ATTACK2:
//		if (boss.modelIndex < 65 || boss.modelIndex > 77) {
//			boss.modelIndex = 65;
//		}
//		arakuneAttack2(boss);
//		if (boss.modelIndex == 77) {
//			boss.modelState = STAND;
//		}
//		break;
//
//	case ATTACK2_B:
//		if (boss.modelIndex < 78 || boss.modelIndex > 90) {
//			boss.modelIndex = 78;
//		}
//		arakuneAttack2B(boss);
//		if (boss.modelIndex == 90) {
//			boss.modelState = STAND_B;
//		}
//		break;
//
//	case ATTACK3:
//		if (boss.modelIndex < 91 || boss.modelIndex > 110) {
//			boss.modelIndex = 91;
//		}
//		arakuneAttack3(boss);
//		if (boss.modelIndex == 110) {
//			boss.modelState = STAND;
//		}
//		break;
//
//	case ATTACK3_B:
//		if (boss.modelIndex < 111 || boss.modelIndex > 130) {
//			boss.modelIndex = 111;
//		}
//		arakuneAttack3B(boss);
//		if (boss.modelIndex == 130) {
//			boss.modelState = STAND_B;
//		}
//		break;
//
//	case ATTACK4:
//		if (boss.modelIndex < 131 || boss.modelIndex > 140) {
//			boss.modelIndex = 131;
//		}
//		arakuneAttack4(boss);
//		if (boss.modelIndex == 140) {
//			boss.modelState = STAND;
//		}
//		break;
//
//	case ATTACK4_B:
//		if (boss.modelIndex < 141 || boss.modelIndex > 150) {
//			boss.modelIndex = 141;
//		}
//		arakuneAttack4B(boss);
//		if (boss.modelIndex == 150) {
//			boss.modelState = STAND_B;
//		}
//		break;
//
//	case DEAD:
//		if (boss.modelIndex < 151 || boss.modelIndex > 166) {
//			boss.modelIndex = 151;
//		}
//		arakuneDead(boss);
//		if (boss.modelIndex == 166) {
//			boss.alive = false;
//		}
//		break;
//
//	case DEAD_B:
//		if (boss.modelIndex < 167 || boss.modelIndex > 182) {
//			boss.modelIndex = 167;
//		}
//		arakuneDeadB(boss);
//		if (boss.modelIndex == 182) {
//			boss.alive = false;
//		}
//		break;
//
//	case STARTING:
//		if (boss.modelIndex < 183 || boss.modelIndex > 195) {
//			boss.modelIndex = 183;
//		}
//		arakuneStarting(boss);
//		if (boss.modelIndex == 195) {
//			boss.modelState = STAND;
//		}
//		break;
//
//	case STARTING_B:
//		if (boss.modelIndex < 196 || boss.modelIndex > 208) {
//			boss.modelIndex = 196;
//		}
//		arakuneStartingB(boss);
//		if (boss.modelIndex == 208) {
//			boss.modelState = STAND_B;
//		}
//		break;
//
//	default:
//		break;
//	}
//}


void animateArakune(ArakuneBoss& boss) {
	switch (boss.modelState) {
	case MOVE:
		if (boss.modelIndex < 28 || boss.modelIndex > 36) {
			boss.modelIndex = 28;
		}
		arakuneWalk(boss);
		break;

	case MOVE_B:
		if (boss.modelIndex < 37 || boss.modelIndex > 45) {
			boss.modelIndex = 37;
		}
		arakuneWalkB(boss);
		break;

	case STAND:
		if (boss.modelIndex < 0 || boss.modelIndex > 13) {
			boss.modelIndex = 0;
		}
		arakuneStand(boss);
		break;

	case STAND_B:
		if (boss.modelIndex < 14 || boss.modelIndex > 27) {
			boss.modelIndex = 14;
		}
		arakuneStandB(boss);
		break;

	case ATTACK1:
		if (boss.modelIndex < 46 || boss.modelIndex > 52) {
			boss.modelIndex = 46;
		}
		arakuneAttack1(boss);
		if (boss.modelIndex == 52) {
			boss.modelState = STAND;
		}
		break;

	case ATTACK1_B:
		if (boss.modelIndex < 53 || boss.modelIndex > 59) {
			boss.modelIndex = 53;
		}
		arakuneAttack1B(boss);
		if (boss.modelIndex == 59) {
			boss.modelState = STAND_B;
		}
		break;

	case ATTACK2:
		if (boss.modelIndex < 60 || boss.modelIndex > 72) {
			boss.modelIndex = 60;
		}
		arakuneAttack2(boss);
		if (boss.modelIndex == 72) {
			boss.modelState = STAND;
		}
		break;

	case ATTACK2_B:
		if (boss.modelIndex < 73 || boss.modelIndex > 85) {
			boss.modelIndex = 73;
		}
		arakuneAttack2B(boss);
		if (boss.modelIndex == 85) {
			boss.modelState = STAND_B;
		}
		break;

	case ATTACK3:
		if (boss.modelIndex < 86 || boss.modelIndex > 105) {
			boss.modelIndex = 86;
		}
		arakuneAttack3(boss);
		if (boss.modelIndex == 105) {
			boss.modelState = STAND;
		}
		break;

	case ATTACK3_B:
		if (boss.modelIndex < 106 || boss.modelIndex > 125) {
			boss.modelIndex = 106;
		}
		arakuneAttack3B(boss);
		if (boss.modelIndex == 125) {
			boss.modelState = STAND_B;
		}
		break;

	case ATTACK4:
		if (boss.modelIndex < 126 || boss.modelIndex > 135) {
			boss.modelIndex = 126;
		}
		arakuneAttack4(boss);
		if (boss.modelIndex == 135) {
			boss.modelState = STAND;
		}
		break;

	case ATTACK4_B:
		if (boss.modelIndex < 136 || boss.modelIndex > 145) {
			boss.modelIndex = 136;
		}
		arakuneAttack4B(boss);
		if (boss.modelIndex == 145) {
			boss.modelState = STAND_B;
		}
		break;

	case DEAD:
		if (boss.modelIndex == 161)
		{
			break;
		}
		if (boss.modelIndex < 146 || boss.modelIndex > 161) {
			boss.modelIndex = 146;
		}
		arakuneDead(boss);
		if (boss.modelIndex == 161) {
			arakuneStop(boss);
			boss.modelIndex = 161;

		}
		break;

	case DEAD_B:
		if (boss.modelIndex == 177)
		{
			break;
		}
		if (boss.modelIndex < 162 || boss.modelIndex > 177) {
			boss.modelIndex = 162;
		}
		arakuneDeadB(boss);
		if (boss.modelIndex == 177) {
			arakuneStopB(boss);
		}
		break;


	case STARTING:
		if (boss.modelIndex < 178 || boss.modelIndex > 190) {
			boss.modelIndex = 178;
		}
		arakuneStarting(boss);
		if (boss.modelIndex == 190) {
			boss.modelState = STAND;
		}
		break;

	case STARTING_B:
		if (boss.modelIndex < 191 || boss.modelIndex > 203) {
			boss.modelIndex = 191;
		}
		arakuneStartingB(boss);
		if (boss.modelIndex == 203) {
			boss.modelState = STAND_B;
		}
		break;

	default:
		break;
	}
}
void arakunefollow(Character& character, ArakuneBoss& boss) {
	srand(time(0));

	const int attackRange = 120;
	const int moveSpeed = 1;
	static int attackCooldown = 0;
	int distance = character.moveX - boss.moveX;

	if (boss.isFollow) {
		// If within attack range and cooldown allows, perform an attack
		if (abs(distance) <= attackRange && attackCooldown <= 0) {
			int randomAttack = rand() % 4; // Select from 4 different attacks

			// Attack in the appropriate direction
			if (distance > 0) { // Character is to the right of Arakune
				switch (randomAttack) {
				case 0: boss.modelState = ATTACK1_B; break;
				case 1: boss.modelState = ATTACK2_B; break;
				case 2: boss.modelState = ATTACK3_B; break;
				case 3: boss.modelState = ATTACK4_B; break;
				default: boss.modelState = STAND_B; break;
				}
			}
			else { // Character is to the left of Arakune
				switch (randomAttack) {
				case 0: boss.modelState = ATTACK1; break;
				case 1: boss.modelState = ATTACK2; break;
				case 2: boss.modelState = ATTACK3; break;
				case 3: boss.modelState = ATTACK4; break;
				default: boss.modelState = STAND; break;
				}
			}

			attackCooldown = 210; // Reset attack cooldown
		}

		// If out of attack range, move towards character
		else {
			if (distance > attackRange) {
				boss.modelState = MOVE_B;
				boss.moveX += moveSpeed;
			}
			else if (distance < -attackRange) {
				boss.modelState = MOVE;
				boss.moveX -= moveSpeed;
			}
		}
	}

	// Damage Handling when the boss successfully hits the character
	if (abs(distance) <= attackRange &&
		(boss.modelState == ATTACK1 || boss.modelState == ATTACK2 || boss.modelState == ATTACK3 || boss.modelState == ATTACK4 ||
		boss.modelState == ATTACK1_B || boss.modelState == ATTACK2_B || boss.modelState == ATTACK3_B || boss.modelState == ATTACK4_B) &&
		!(character.modelState == SLASH || character.modelState == SLASH_B || character.modelState == DASH || character.modelState == DASH_B)) {

		if (character.hp > 0) {
			character.hp -= 5;
		}
	}

	// Character Death Handling
	if (character.hp <= 0 && character.alive) {
		character.hp = 0;
		character.alive = false;
		character.modelState = DEAD;
	}

	// Boss stops attacking if the character is dead
	if (character.hp == 0) {
		boss.modelState = STAND;
	}

	// Character attacking the boss
	if (abs(distance) <= attackRange &&
		(character.modelState == KICK || character.modelState == KICK_B ||
		character.modelState == SLASH || character.modelState == SLASH_B ||
		character.modelState == SWING || character.modelState == SWING_B ||
		character.modelState == THRUST || character.modelState == THRUST_B)) {

		if (boss.hp > 0) {
			boss.hp -= 1;
		}
		cout << "Boss HP: " << boss.hp << endl;
	}

	// Boss Death Handling
	if (boss.hp <= 0 && (boss.modelState == ATTACK1 || boss.modelState == ATTACK2 || boss.modelState == ATTACK3 || boss.modelState == ATTACK4 || boss.modelState == STAND || boss.modelState == MOVE)) {
		boss.hp = 0;
		boss.modelState = DEAD;
		boss.isFollow = false;
		boss.alive = false;
	}

	else if (boss.hp <= 0 && (boss.modelState == ATTACK1_B || boss.modelState == ATTACK2_B || boss.modelState == ATTACK3_B || boss.modelState == ATTACK4_B || boss.modelState == STAND_B || boss.modelState == MOVE_B)) {
		boss.hp = 0;
		boss.modelState = DEAD_B;
		boss.isFollow = false;
		boss.alive = false;
	}

	// Reduce attack cooldown over time
	if (attackCooldown > 0) {
		attackCooldown--;
	}
}



//void arakunefollow(Character& character, ArakuneBoss& boss) {
//	srand(time(0));
//
//	const int attackRange = 120;
//	const int moveSpeed = 1;
//	static int attackCooldown = 0;
//	int distance = character.moveX - boss.moveX;
//
//	if (boss.isFollow && boss.alive) {
//		if (abs(distance) <= attackRange) {
//			if (attackCooldown <= 0) {
//				int randomAttack = rand() % 4; // Select from 4 different attacks
//
//				if (distance > 0) { // Character is to the right of Arakune
//					switch (randomAttack) {
//					case 0: boss.modelState = ATTACK1_B; break;
//					case 1: boss.modelState = ATTACK2_B; break;
//					case 2: boss.modelState = ATTACK3_B; break;
//					case 3: boss.modelState = ATTACK4_B; break;
//					default: boss.modelState = MOVE_B; break;
//					}
//				}
//				else { // Character is to the left of Arakune
//					switch (randomAttack) {
//					case 0: boss.modelState = ATTACK1; break;
//					case 1: boss.modelState = ATTACK2; break;
//					case 2: boss.modelState = ATTACK3; break;
//					case 3: boss.modelState = ATTACK4; break;
//					default: boss.modelState = MOVE; break;
//					}
//				}
//
//				attackCooldown = 210;
//			}
//		}
//		else {
//			// Move towards the character if not in attack range
//			if (distance > attackRange) {
//				boss.modelState = MOVE_B;
//				boss.moveX += moveSpeed;
//			}
//			else if (distance < -attackRange) {
//				boss.modelState = MOVE;
//				boss.moveX -= moveSpeed;
//			}
//		}
//	}
//
//	// Handling damage when the boss attacks
//	if (abs(distance) <= attackRange &&
//		(boss.modelState == ATTACK1 || boss.modelState == ATTACK2 || boss.modelState == ATTACK3 || boss.modelState == ATTACK4 ||
//		boss.modelState == ATTACK1_B || boss.modelState == ATTACK2_B || boss.modelState == ATTACK3_B || boss.modelState == ATTACK4_B) &&
//		!(character.modelState == SLASH || character.modelState == SLASH_B || character.modelState == DASH || character.modelState == DASH_B)) {
//
//		if (character.hp > 0) {
//			character.hp -= 5;
//		}
//	}
//
//	// If the character dies
//	if (character.hp <= 0 && character.alive) {
//		character.hp = 0;
//		character.alive = false;
//		character.modelState = DEAD;
//	}
//
//	if (character.hp == 0) {
//		boss.modelState = STAND;
//	}
//
//	// Handling damage when the character attacks the boss
//	if (abs(distance) <= attackRange &&
//		(character.modelState == KICK || character.modelState == KICK_B ||
//		character.modelState == SLASH || character.modelState == SLASH_B ||
//		character.modelState == SWING || character.modelState == SWING_B ||
//		character.modelState == THRUST || character.modelState == THRUST_B)) {
//
//		if (boss.hp > 0) {
//			boss.hp -= 1;
//		}
//		cout << "Boss HP: " << boss.hp << endl;
//	}
//
//	// If the boss dies
//	if (boss.hp <= 0) {
//		boss.hp = 0;
//		boss.isFollow = false;
//		boss.alive = false;
//		boss.modelState = DEAD;
//
//	}
//
//	// Decrease the attack cooldown over time
//	if (attackCooldown > 0) {
//		attackCooldown--;
//	}
//}




//================================================================================= Arakune end =========================================================================================//

































#endif