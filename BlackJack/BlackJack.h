#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP
#include "Player.h"
#include "Judge.h"

//----------クラスの定義----------
//このクラスはBlackJackの仕様とか説明書みたいなもの
class BlackJack {
public:
	BlackJack();	//コンストラクタの宣言
	~BlackJack();	//デストラクタの宣言

	bool Start();		//多態性を持たせる
	bool End();			//多態性を持たせる
};
#endif