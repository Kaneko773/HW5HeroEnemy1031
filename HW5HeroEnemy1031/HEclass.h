#pragma once

class Enemy;//ëOï˚êÈåæ

class Hero {
public:
	Hero(char* pName, int hp);
	~Hero();
	Hero(const Hero& other);

	void operator*(const int i);
	void operator/(const int i);

public:
	int getDiffence() const { return _diffence; };
	int getHp() const { return _hp; };
	void setHp(int hp) { _hp = hp; };
	void show() const;
	char* getName() const { return _pName; }

public:
	void attack(Enemy* enemy);
	void heal();

private:
	char* _pName;
	int _nameSize;

private:
	int _hp;
	int _attack;
	int _diffence;
};

class Enemy {
public:
	Enemy(char* pName, int hp);
	~Enemy();
	Enemy(const Enemy& other);

	void operator*(const int i);
	void operator/(const int i);

public:
	int getDiffence() const { return _diffence; };
	int getHp() const { return _hp; };
	void setHp(int hp) { _hp = hp; };
	void show() const;
	char* getName() const { return _pName; }

public:
	void attack(Hero* hero);
	void heal(int healHp);

private:
	char* _pName;
	int _nameSize;

private:
	int _hp;
	int _attack;
	int _diffence;
};