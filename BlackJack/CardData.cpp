#include "CardData.h"
#define CARD (52)

//----------コンストラクタの定義----------
//オブジェクトが生成された時に自動的に呼び出されるメソッド
CardData::CardData() {
	srand((unsigned int)time(NULL));		//ランダム処理
	CardShuffle();
}
//----------デストラクタの定義----------
//オブジェクトが役目を終えた時に自動的に呼び出されるメソッド
CardData::~CardData() {}

//----------メンバメソッドの定義----------
//----------カード情報----------
void CardData::CardShuffle() {
	_deckCard.clear();
	int i = 0;
	while (i < CARD) 
	{
		bool flag = true;
		int card = RandomCard(0, 51);		//カードシャッフル

		for (int j = 0; j < (int)_deckCard.size(); j++)
		{
			//既に場にあるカードと照らし合わせる
			if (card == (int)_deckCard[j]) 
			{
				flag = false;
				break;
			}
		}
		if (flag) 
		{
			SetCard(card);
			i++;
		}
	}
}

//min～maxのランダムな数字を返す
int CardData::RandomCard(int min, int max){
	return min + (int)(rand()*(max - min + 1.0) / (1.0 + RAND_MAX));
}

//山札からカードを取り出す
int CardData::GetCard() {
	int drawCard = _deckCard.back();
	_deckCard.pop_back();
	return drawCard;
}

//0～51のカードをトランプに割り当てる
void CardData::ConversionCard(int remainder, int quotient) {

	//10をドロー
	if (remainder == 9) 
	{
		std::cout << "[" << CardData::_cardSymbol[quotient] << "10" << "] ";
	}
	else 
	{
		std::cout << "[" << CardData::_cardSymbol[quotient] << CardData::_cardNum[remainder] << "] ";
	}
}

//static変数初期化
const char CardData::_cardSymbol[5] = { "SHDC" };
const char CardData::_cardNum[14] = { "A23456789XJQK" };
