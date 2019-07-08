#include "Judge.h"

//----------コンストラクタの定義----------
Judge::Judge() {}
//----------デストラクタの定義----------
Judge::~Judge() {}

//----------メンバメソッドの定義----------
//バースト判定
bool Judge::BurstJudge(int cardsum){
	bool truth;
	if (cardsum > 21)
	{
		truth = false;
	}
	else { truth = true; }
	return truth;
}

//勝利判定：ここはenumを使って名前でも返すべきだろうか数字じゃわからんし
int Judge::VictoryJudge(int cardsum1, int cardsum2){
	int win = 0;
	if (cardsum1 < cardsum2)
	{
		win = 1;
	}
	else if (cardsum1 == cardsum2)
	{
		win = -1;
	}
	return win;
}