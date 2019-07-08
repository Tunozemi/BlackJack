#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "CardData.h"
#include "Judge.h"
#include "UiRe.h"
#include <string>
#include <iostream>
#include <random>
#include <time.h>
#include <windows.h>

//----------クラスの定義----------
//プレイヤー情報
class Player {
public:
	Player();									//コンストラクタの宣言
	~Player();									//デストラクタの宣言

	typedef struct playerdata {
		std::string _name;					//名前
		std::vector<int> _haveCard;			//持っているカード
		int		_aCount;					//エースをカウントしておく
		int		_cardSum;					//所持カードの合計値
		int		_numCount;					//足した回数
		int		_idNumber;					//ID割り振り
		bool	_burst;						//バースト
	}playerData_st;

	playerData_st *pPlayerData;				//構造体のポインタ

	//enum PlayerMembers { dealer, player, both};//enumでディーラーだけ表示、プレイヤーだけ表示、両方表示を使い分ける　switch文になる？

	void InitializeData();							//プレイヤーデータの初期化
	bool NameInput();								//名前入力

	void DrawCard(CardData &card);					//カードをドローする
	void CardConfirmation(bool);					//カードを表示

	int CardSum(int);								//合計値算出
	
	bool DrawOrStand(CardData &card);				//ドローorスタンド選択
	void DrawCardDeclaration(CardData &card, int);	//カードをドロー宣言
	void StandDeclaration(int);						//スタンド宣言
	void CardConfirmation(int);				//1回だけカード表示

	void BurstFlag(int num) 
		{ pPlayerData[num]._burst = false; }		//バーストフラグ
	void BurstDeclaration();						//バースト宣言
	void VictoryDeclaration(int);					//勝敗宣言
};
#endif