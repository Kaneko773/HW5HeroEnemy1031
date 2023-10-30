#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HEclass.h"
using namespace std;

//コンストラクタ
Hero::Hero(char* pName, int hp) {
	//名前をコピー
	_nameSize = strlen(pName);
	_pName = new char[_nameSize + 1];
	for (int i = 0; i < _nameSize; ++i) {
		_pName[i] = pName[i];
	}
	_pName[_nameSize] = '\0';

	//他のパラメーターを初期化
	_hp = hp;
	_attack = 75;
	_diffence = 20;
}

//デストラクタ
Hero::~Hero() {
	if (_pName != NULL) {
		delete[] _pName;
		_pName = NULL;
	}
}

//コピーコンストラクタ
Hero::Hero(const Hero& other) {
	_nameSize = other._nameSize;
	_pName = new char[_nameSize + 1];
	strcpy(_pName, other._pName);
	_pName[_nameSize] = '\0';

	_hp = other._hp;
	_attack = other._attack;
	_diffence = other._diffence;
}

//パラメーター上昇
void Hero::operator*(const int i)
{
	_attack *= i;
	_diffence *= i;
}
//パラメーター減少
void Hero::operator/(const int i)
{
	_attack /= i;
	_diffence /= i;
}

//初期ステータス表示
void Hero::show() const {
	printf("\n名前：%s\n", _pName);
	printf("体力：%d\n", _hp);
	printf("攻撃力：%d,", _attack);
	printf("防御力：%d\n\n", _diffence);
}

//攻撃
void Hero::attack(Enemy* enemy) {
	int deffence = enemy->getDiffence();
	int damage = 0;
	damage = _attack - deffence;
	printf("\n%sの攻撃！\n%sに%dのダメージ！\n", _pName, enemy->getName(), damage);

	int hp = enemy->getHp();
	enemy->setHp(hp - damage);
	printf("%sの残りHP：%d\n\n", enemy->getName(), enemy->getHp());
}

//回復
void Hero::heal() {
	int healHp = 0;
	printf("\nどのくらい回復しますか　＞　");
	cin >> healHp;
	_hp += healHp;

	printf("%sの残りHP：%d\n\n", _pName, _hp);
}

//コンストラクタ
Enemy::Enemy(char* pName, int hp) {
	_nameSize = strlen(pName);
	_pName = new char[_nameSize + 1];
	for (int i = 0; i < _nameSize; ++i) {
		_pName[i] = pName[i];
	}
	_pName[_nameSize] = '\0';

	_hp = hp;
	_attack = 75;
	_diffence = 20;
}

//デストラクタ
Enemy::~Enemy() {
	if (_pName != NULL) {
		delete[] _pName;
		_pName = NULL;
	}
}

//コピーコンストラクタ
Enemy::Enemy(const Enemy& other) {
	_nameSize = other._nameSize;
	_pName = new char[_nameSize + 1];
	strcpy(_pName, other._pName);
	_pName[_nameSize] = '\0';

	_hp = other._hp;
	_attack = other._attack;
	_diffence = other._diffence;
}

//パラメーター上昇
void Enemy::operator*(const int i)
{
	_attack *= i;
	_diffence *= i;
}
//パラメーター減少
void Enemy::operator/(const int i)
{
	_attack /= i;
	_diffence /= i;
}

//初期ステータス表示
void Enemy::show() const {
	printf("\n名前：%s\n", _pName);
	printf("体力：%d\n", _hp);
	printf("攻撃力：%d,", _attack);
	printf("防御力：%d\n\n", _diffence);
}

//攻撃
void Enemy::attack(Hero* hero){
	int deffence = hero->getDiffence();
	int damage = 0;
	damage = _attack - deffence;
	printf("%sの攻撃！\n%sに%dのダメージ！\n", _pName, hero->getName(), damage);

	int hp = hero->getHp();
	hero->setHp(hp - damage);
	printf("%sの残りHP：%d\n\n", hero->getName(), hero->getHp());
}

//回復
void Enemy::heal(int healHp) {
	printf("%sのHPが%d回復", _pName, healHp);
	_hp += healHp;

	printf("\n%sの残りHP：%d\n\n", _pName, _hp);
}