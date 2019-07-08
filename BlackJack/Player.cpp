#include "Player.h"
#define Player_Number (2)

//----------コンストラクタの定義----------
Player::Player() {
	pPlayerData = new playerData_st[Player_Number];
	InitializeData();
}
//----------デストラクタの定義----------
Player::~Player() {
	delete[] pPlayerData;
}

//----------メンバメソッドの定義----------
//構造体初期化処理
void Player::InitializeData() {
	for (int i = 0; i < Player_Number; i++)
	{
		pPlayerData[i]._haveCard.clear();
		pPlayerData[i]._aCount = 0;
		pPlayerData[i]._cardSum = 0;
		pPlayerData[i]._numCount = 0;
		pPlayerData[i]._idNumber = i;
		pPlayerData[i]._burst = true;
		rand();
	}
}

//名前入力
bool Player::NameInput() {
	pPlayerData[0]._name = "ディーラー";
	std::cout << "ディーラー「名前を教えてください」：";
	std::cin >> pPlayerData[1]._name;
	std::cout << pPlayerData[0]._name << "「" << pPlayerData[1]._name << "」さん、よろしくお願いします。」\n";
	return true;
}

//カードをドローする
void Player::DrawCard(CardData &card) {
	printf_s("\nカードを配ります\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < Player_Number; j++)
		{
			pPlayerData[j]._haveCard.push_back(card.GetCard());
		}
	}
}

//PlayerとNPCのカードを表示
void Player::CardConfirmation(bool truth) {
	std::cout << "\n互いのカードを表示します\n";
	Sleep(1000);

	for (int num = 0; num < Player_Number; num++)
	{
		int once = 0;
		std::cout << "\n" << pPlayerData[num]._name << "のカード";
		UiRe::Partition();

		for (int i = 0; i < (int)pPlayerData[num]._haveCard.size(); i++)
		{
			int remainder = (int)pPlayerData[num]._haveCard[i] % 13;	//余り算出
			int quotient = (int)pPlayerData[num]._haveCard[i] / 13;		//商算出

			if (pPlayerData[num]._idNumber == 0 && once == 0 && truth)
			{
				std::cout << "[?] ";							//ディーラーの1枚目
				once++;
			}
			else
			{
				CardData::ConversionCard(remainder, quotient);
			}
			//enumでプレイヤー名の時とで分岐するといい
		}
		if (pPlayerData[num]._idNumber == 1 || !truth)
		{
			printf_s(" = %d", CardSum(num));
		}
		UiRe::Partition();
	}
	Sleep(500);
}

//ドロー後にカードを表示
void Player::CardConfirmation(int num)
{
	UiRe::Partition();
	int once = 0;
	for (int i = 0; i < (int)pPlayerData[num]._haveCard.size(); i++)
	{
		int remainder = (int)pPlayerData[num]._haveCard[i] % 13;	//余り算出
		int quotient = (int)pPlayerData[num]._haveCard[i] / 13;		//商算出

		if (pPlayerData[num]._idNumber == 0 && pPlayerData[num]._burst && once == 0)
		{
			std::cout << "[?] ";									//ディーラーの1枚目
			once++;
		}
		else
		{
			CardData::ConversionCard(remainder, quotient);
		}
		//enumでプレイヤー名の時とで分岐するといい
	}
	if (pPlayerData[num]._idNumber == 1 || !pPlayerData[num]._burst)
	{
		printf_s(" = %d", CardSum(num));
	}
	Sleep(1000);
	UiRe::Partition();
}

//カードの合計値算出
int Player::CardSum(int num)
{
	if (pPlayerData[num]._numCount < (int)pPlayerData[num]._haveCard.size())
	{
		for (int i = pPlayerData[num]._numCount; i < (int)pPlayerData[num]._haveCard.size(); i++) 
		{
			int remainder = (int)pPlayerData[num]._haveCard[i] % 13;		//余り算出
			//10以上
			if (remainder > 8)
			{
				pPlayerData[num]._cardSum += 10;
			}
			//Aの時
			else if (remainder == 0)
			{
				pPlayerData[num]._aCount++;
				pPlayerData[num]._cardSum += 11;
			}
			//10以下
			else
			{
				pPlayerData[num]._cardSum += (remainder + 1);
			}
			pPlayerData[num]._numCount++;

			//A持ってる状態でバーストした時
			if (pPlayerData[num]._cardSum > 21 && pPlayerData[num]._aCount > 0)
			{
				pPlayerData[num]._cardSum -= 10;
				pPlayerData[num]._aCount--;
			}
		}
	}
	return pPlayerData[num]._cardSum;
}

//カードをドローするかスタンドするか選択
bool Player::DrawOrStand(CardData &card) {
	for (int num = Player_Number - 1; num >= 0; num--)
	{
		std::string choice1;
		int choice = 1;

		while (choice == 1)
		{
			//プレイヤー：ドローorスタンド選択
			if (num == 1)
			{
				int input;
				std::cout << "\nドロー：0 スタンド：1を選択：";
				scanf_s("%d", &input);
				//1枚ドロー用のメソッドを用意するべき？
				if (input == 0)
				{
					//ドローをする
					DrawCardDeclaration(card, num);
					//バースト検知
					if (!Judge::BurstJudge(CardSum(num)))
					{
						BurstFlag(num);
						CardConfirmation(num);
						return false;
					}
				}
				else
				{
					//スタンドする
					StandDeclaration(num);
					choice = 0;
				}
			}
			//NPC：ドローorスタンド選択
			else if (num == 0 && pPlayerData[num]._cardSum < 17)
			{
				//ドローをする
				DrawCardDeclaration(card, num);
				//バースト検知
				if (!Judge::BurstJudge(CardSum(num)))
				{
					BurstFlag(num);
					CardConfirmation(num);
					return false;
				}
			}
			else
			{
				//スタンドする
				StandDeclaration(num);
				choice = 0;
			}
			//カードを表示
			CardConfirmation(num);
		}
	}
	return true;
}

//１枚カードドロー宣言
void Player::DrawCardDeclaration(CardData &card,int num) {
	std::cout << "\n" << pPlayerData[num]._name << "「カードをドローします」";
	pPlayerData[num]._haveCard.push_back(card.GetCard());
	Sleep(1000);
}

//スタンド宣言
void Player::StandDeclaration(int num) {
	std::cout << "\n" << pPlayerData[num]._name << "「スタンドします」";
	Sleep(1000);
}

//バースト宣言
void Player::BurstDeclaration() {
	for (int num = 0; num < Player_Number; num++) {
		if (num == 0 && pPlayerData[num]._burst == false)
		{
			std::cout << "\n" << pPlayerData[num]._name << "がバーストしたので「" << pPlayerData[1]._name << "」の勝ちです\n";
		}
		else if (num == 1 && pPlayerData[num]._burst == false)
		{
			std::cout << "\nバーストしたので「" << pPlayerData[1]._name << "」の負けです\n";
		}
	}
}

//勝利or引き分け宣言
void Player::VictoryDeclaration(int judge) {
	if (judge >= 0)
	{
		std::cout <<"\n「" << pPlayerData[judge]._name << "」の勝利です\n";
	}
	else if (judge < 0)
	{
		std::cout << "\n引き分けです\n";
	}
	else 
	{
		std::cout << "\n無効な値デス\n";
	}
}