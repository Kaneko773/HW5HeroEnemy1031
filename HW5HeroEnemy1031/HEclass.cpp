#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HEclass.h"
using namespace std;

//�R���X�g���N�^
Hero::Hero(char* pName, int hp) {
	//���O���R�s�[
	_nameSize = strlen(pName);
	_pName = new char[_nameSize + 1];
	for (int i = 0; i < _nameSize; ++i) {
		_pName[i] = pName[i];
	}
	_pName[_nameSize] = '\0';

	//���̃p�����[�^�[��������
	_hp = hp;
	_attack = 75;
	_diffence = 20;
}

//�f�X�g���N�^
Hero::~Hero() {
	if (_pName != NULL) {
		delete[] _pName;
		_pName = NULL;
	}
}

//�R�s�[�R���X�g���N�^
Hero::Hero(const Hero& other) {
	_nameSize = other._nameSize;
	_pName = new char[_nameSize + 1];
	strcpy(_pName, other._pName);
	_pName[_nameSize] = '\0';

	_hp = other._hp;
	_attack = other._attack;
	_diffence = other._diffence;
}

//�p�����[�^�[�㏸
void Hero::operator*(const int i)
{
	_attack *= i;
	_diffence *= i;
}
//�p�����[�^�[����
void Hero::operator/(const int i)
{
	_attack /= i;
	_diffence /= i;
}

//�����X�e�[�^�X�\��
void Hero::show() const {
	printf("\n���O�F%s\n", _pName);
	printf("�̗́F%d\n", _hp);
	printf("�U���́F%d,", _attack);
	printf("�h��́F%d\n\n", _diffence);
}

//�U��
void Hero::attack(Enemy* enemy) {
	int deffence = enemy->getDiffence();
	int damage = 0;
	damage = _attack - deffence;
	printf("\n%s�̍U���I\n%s��%d�̃_���[�W�I\n", _pName, enemy->getName(), damage);

	int hp = enemy->getHp();
	enemy->setHp(hp - damage);
	printf("%s�̎c��HP�F%d\n\n", enemy->getName(), enemy->getHp());
}

//��
void Hero::heal() {
	int healHp = 0;
	printf("\n�ǂ̂��炢�񕜂��܂����@���@");
	cin >> healHp;
	_hp += healHp;

	printf("%s�̎c��HP�F%d\n\n", _pName, _hp);
}

//�R���X�g���N�^
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

//�f�X�g���N�^
Enemy::~Enemy() {
	if (_pName != NULL) {
		delete[] _pName;
		_pName = NULL;
	}
}

//�R�s�[�R���X�g���N�^
Enemy::Enemy(const Enemy& other) {
	_nameSize = other._nameSize;
	_pName = new char[_nameSize + 1];
	strcpy(_pName, other._pName);
	_pName[_nameSize] = '\0';

	_hp = other._hp;
	_attack = other._attack;
	_diffence = other._diffence;
}

//�p�����[�^�[�㏸
void Enemy::operator*(const int i)
{
	_attack *= i;
	_diffence *= i;
}
//�p�����[�^�[����
void Enemy::operator/(const int i)
{
	_attack /= i;
	_diffence /= i;
}

//�����X�e�[�^�X�\��
void Enemy::show() const {
	printf("\n���O�F%s\n", _pName);
	printf("�̗́F%d\n", _hp);
	printf("�U���́F%d,", _attack);
	printf("�h��́F%d\n\n", _diffence);
}

//�U��
void Enemy::attack(Hero* hero){
	int deffence = hero->getDiffence();
	int damage = 0;
	damage = _attack - deffence;
	printf("%s�̍U���I\n%s��%d�̃_���[�W�I\n", _pName, hero->getName(), damage);

	int hp = hero->getHp();
	hero->setHp(hp - damage);
	printf("%s�̎c��HP�F%d\n\n", hero->getName(), hero->getHp());
}

//��
void Enemy::heal(int healHp) {
	printf("%s��HP��%d��", _pName, healHp);
	_hp += healHp;

	printf("\n%s�̎c��HP�F%d\n\n", _pName, _hp);
}