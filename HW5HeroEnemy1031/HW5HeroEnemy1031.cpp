// HW5HeroEnemy1031.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "HEclass.h"
using namespace std;

void showStatus(Hero hero, Enemy enemy);

const int MAX_NAME = 16;

int main()
{
	srand((unsigned)time(NULL));
	bool conti = true;
	char name[MAX_NAME] = { "" };
	int hp = 0;

	printf("ヒーロー名を入力\n > ");
	cin >> name;
	printf("HPを入力\n > ");
	cin >> hp;

	Hero hero(&name[0], hp);

	// ステータス表示
	hero.show();

	printf("エネミー名を入力\n > ");
	cin >> name;
	printf("HPを入力\n > ");
	cin >> hp;
	int healHp = hp / 5;//回復はHPの2割

	Enemy enemy(&name[0], hp);

	// ステータス表示
	enemy.show();


	int select = 0;
	bool heroEnhance = false;
	int heroEnhaLimit = 2;
	bool enemyEnhance = false;
	int enemyEnhaLimit = 2;

	while (conti) {
		if (heroEnhaLimit <= 0) {
			printf("%sのステータスが戻りました\n\n", hero.getName());
			hero / 2;
			heroEnhaLimit = 2;
			heroEnhance = false;
		}
		if (enemyEnhaLimit <= 0) {
			printf("%sのステータスが戻りました\n\n", enemy.getName());
			enemy / 2;
			enemyEnhaLimit = 2;
			enemyEnhance = false;
		}
		if (!heroEnhance) {
			do {
				// プレイヤーターン
				cout << hero.getName() << "のターン";
				printf("\n 攻撃 : 1　, 回復 : 2　, 現在の%sと%sの状態を見る : 3, 次のターンまでステータスを２倍にする : 4\n  > ", hero.getName(), enemy.getName());
				cin >> select;
			} while (select < 1 || 4 < select);
		}
		if (heroEnhance) {
			do {
				// プレイヤーターン
				cout << hero.getName() << "のターン";
				printf("\n 攻撃 : 1　, 回復 : 2　, 現在の%sと%sの状態を見る : 3\n  > ", hero.getName(), enemy.getName());
				cin >> select;
			} while (select < 1 || 3 < select);
		}

		switch (select)
		{
		case 1:
			hero.attack(&enemy);
			break;
		case 2:
			hero.heal();
			break;
		case 3:
			showStatus(hero, enemy); continue;
			break;
		case 4:
			printf("\n%sのステータスが２倍になった\n\n", hero.getName());
			heroEnhance = true;
			hero * 2;
			break;
		}
		if (enemy.getHp() <= 0) { conti = false; continue; }

		// エネミーターン
		printf("%sの行動\n", enemy.getName());
		if (!enemyEnhance)select = rand() % 4 + 1;
		if (enemyEnhance)select = rand() % 3 + 1;

		switch (select)
		{
		case 1:
		case 2:
			enemy.attack(&hero);
			break;
		case 3:
			enemy.heal(healHp);
			break;
		case 4:
			printf("%sのステータスが２倍になった\n\n", enemy.getName());
			enemyEnhance = true;
			enemy * 2;
			break;
		}
		if (hero.getHp() <= 0) { conti = false; }

		if(heroEnhance)--heroEnhaLimit;
		if(enemyEnhance)--enemyEnhaLimit;
	}
}

//ステータス表示
void showStatus(Hero hero, Enemy enemy) {
	cout << endl << endl;
	hero.show();
	enemy.show();
	cout << endl << endl;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
