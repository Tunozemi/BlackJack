#ifndef CARDDATA_HPP
#define CARDDATA_HPP
#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#include <iostream>

//----------クラスの定義----------
//カード情報
class CardData {
public:	
	CardData();										//コンストラクタの宣言
	~CardData();									//デストラクタの宣言

	void	CardShuffle();									//カードをシャッフルする
	void	SetCard(int card) { _deckCard.push_back(card); }//山札にカードをセット
	int		GetCard();										//山札のカードを取り出す

	static void	ConversionCard(int remainder, int quotient);//0～51のカードを実際のカードに割当
	int		RandomCard(int min, int max);					//0～51のランダムな数値を取得

private:
	const static char _cardSymbol[5];			//カード記号 スペード、ハート、ダイア、クローバー
	const static char _cardNum[14];			//カード番号
	std::vector<int> _deckCard;			//山札のカード
};
#endif