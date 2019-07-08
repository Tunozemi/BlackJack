#include "BlackJack.h"
#define Player_Number (2)

//----------コンストラクタの定義----------
BlackJack::BlackJack() {}

//----------デストラクタの定義----------
BlackJack::~BlackJack() {}

//----------メンバメソッドの定義----------
//ゲーム選択メソッド
bool BlackJack::Start() {

	//インスタンス宣言
	Player player;
	CardData card;

	player.NameInput();		//名前入力
	bool end = true;
	while (end)
	{
		player.DrawCard(card);
		//互いのカードを表示
		player.CardConfirmation(true);

		//ドローorスタンド選択
		if (!player.DrawOrStand(card)) 
		{
			//falseで強制終了
			player.BurstDeclaration();
			end = false;
		}
		else 
		{
			//互いのカードを表示して勝負
			player.CardConfirmation(false);
			player.VictoryDeclaration(Judge::VictoryJudge(player.CardSum(0), player.CardSum(1)));
		}
		if (!End())
		{
			return false;
		}
		player.InitializeData();
		end = true;
	}
	return false;
}

//終了時に呼び出す処理
bool BlackJack:: End() {
	int end;
	printf_s("\n終了するには0を入力してください:");
	scanf_s("%d", &end);
	if (end == 0)
	{
		printf_s("BJを終了\n");
		return false;
	}
	else 
	{
		printf_s("\n--------------------------------------------------\n");
		printf_s("\n\nもう一度やります\n");
		return true;
	}
	return true;
}
