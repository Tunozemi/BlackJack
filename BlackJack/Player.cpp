#include "Player.h"
#define Player_Number (2)

//----------�R���X�g���N�^�̒�`----------
Player::Player() {
	pPlayerData = new playerData_st[Player_Number];
	InitializeData();
}
//----------�f�X�g���N�^�̒�`----------
Player::~Player() {
	delete[] pPlayerData;
}

//----------�����o���\�b�h�̒�`----------
//�\���̏���������
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

//���O����
bool Player::NameInput() {
	pPlayerData[0]._name = "�f�B�[���[";
	std::cout << "�f�B�[���[�u���O�������Ă��������v�F";
	std::cin >> pPlayerData[1]._name;
	std::cout << pPlayerData[0]._name << "�u" << pPlayerData[1]._name << "�v����A��낵�����肢���܂��B�v\n";
	return true;
}

//�J�[�h���h���[����
void Player::DrawCard(CardData &card) {
	printf_s("\n�J�[�h��z��܂�\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < Player_Number; j++)
		{
			pPlayerData[j]._haveCard.push_back(card.GetCard());
		}
	}
}

//Player��NPC�̃J�[�h��\��
void Player::CardConfirmation(bool truth) {
	std::cout << "\n�݂��̃J�[�h��\�����܂�\n";
	Sleep(1000);

	for (int num = 0; num < Player_Number; num++)
	{
		int once = 0;
		std::cout << "\n" << pPlayerData[num]._name << "�̃J�[�h";
		UiRe::Partition();

		for (int i = 0; i < (int)pPlayerData[num]._haveCard.size(); i++)
		{
			int remainder = (int)pPlayerData[num]._haveCard[i] % 13;	//�]��Z�o
			int quotient = (int)pPlayerData[num]._haveCard[i] / 13;		//���Z�o

			if (pPlayerData[num]._idNumber == 0 && once == 0 && truth)
			{
				std::cout << "[?] ";							//�f�B�[���[��1����
				once++;
			}
			else
			{
				CardData::ConversionCard(remainder, quotient);
			}
			//enum�Ńv���C���[���̎��Ƃŕ��򂷂�Ƃ���
		}
		if (pPlayerData[num]._idNumber == 1 || !truth)
		{
			printf_s(" = %d", CardSum(num));
		}
		UiRe::Partition();
	}
	Sleep(500);
}

//�h���[��ɃJ�[�h��\��
void Player::CardConfirmation(int num)
{
	UiRe::Partition();
	int once = 0;
	for (int i = 0; i < (int)pPlayerData[num]._haveCard.size(); i++)
	{
		int remainder = (int)pPlayerData[num]._haveCard[i] % 13;	//�]��Z�o
		int quotient = (int)pPlayerData[num]._haveCard[i] / 13;		//���Z�o

		if (pPlayerData[num]._idNumber == 0 && pPlayerData[num]._burst && once == 0)
		{
			std::cout << "[?] ";									//�f�B�[���[��1����
			once++;
		}
		else
		{
			CardData::ConversionCard(remainder, quotient);
		}
		//enum�Ńv���C���[���̎��Ƃŕ��򂷂�Ƃ���
	}
	if (pPlayerData[num]._idNumber == 1 || !pPlayerData[num]._burst)
	{
		printf_s(" = %d", CardSum(num));
	}
	Sleep(1000);
	UiRe::Partition();
}

//�J�[�h�̍��v�l�Z�o
int Player::CardSum(int num)
{
	if (pPlayerData[num]._numCount < (int)pPlayerData[num]._haveCard.size())
	{
		for (int i = pPlayerData[num]._numCount; i < (int)pPlayerData[num]._haveCard.size(); i++) 
		{
			int remainder = (int)pPlayerData[num]._haveCard[i] % 13;		//�]��Z�o
			//10�ȏ�
			if (remainder > 8)
			{
				pPlayerData[num]._cardSum += 10;
			}
			//A�̎�
			else if (remainder == 0)
			{
				pPlayerData[num]._aCount++;
				pPlayerData[num]._cardSum += 11;
			}
			//10�ȉ�
			else
			{
				pPlayerData[num]._cardSum += (remainder + 1);
			}
			pPlayerData[num]._numCount++;

			//A�����Ă��ԂŃo�[�X�g������
			if (pPlayerData[num]._cardSum > 21 && pPlayerData[num]._aCount > 0)
			{
				pPlayerData[num]._cardSum -= 10;
				pPlayerData[num]._aCount--;
			}
		}
	}
	return pPlayerData[num]._cardSum;
}

//�J�[�h���h���[���邩�X�^���h���邩�I��
bool Player::DrawOrStand(CardData &card) {
	for (int num = Player_Number - 1; num >= 0; num--)
	{
		std::string choice1;
		int choice = 1;

		while (choice == 1)
		{
			//�v���C���[�F�h���[or�X�^���h�I��
			if (num == 1)
			{
				int input;
				std::cout << "\n�h���[�F0 �X�^���h�F1��I���F";
				scanf_s("%d", &input);
				//1���h���[�p�̃��\�b�h��p�ӂ���ׂ��H
				if (input == 0)
				{
					//�h���[������
					DrawCardDeclaration(card, num);
					//�o�[�X�g���m
					if (!Judge::BurstJudge(CardSum(num)))
					{
						BurstFlag(num);
						CardConfirmation(num);
						return false;
					}
				}
				else
				{
					//�X�^���h����
					StandDeclaration(num);
					choice = 0;
				}
			}
			//NPC�F�h���[or�X�^���h�I��
			else if (num == 0 && pPlayerData[num]._cardSum < 17)
			{
				//�h���[������
				DrawCardDeclaration(card, num);
				//�o�[�X�g���m
				if (!Judge::BurstJudge(CardSum(num)))
				{
					BurstFlag(num);
					CardConfirmation(num);
					return false;
				}
			}
			else
			{
				//�X�^���h����
				StandDeclaration(num);
				choice = 0;
			}
			//�J�[�h��\��
			CardConfirmation(num);
		}
	}
	return true;
}

//�P���J�[�h�h���[�錾
void Player::DrawCardDeclaration(CardData &card,int num) {
	std::cout << "\n" << pPlayerData[num]._name << "�u�J�[�h���h���[���܂��v";
	pPlayerData[num]._haveCard.push_back(card.GetCard());
	Sleep(1000);
}

//�X�^���h�錾
void Player::StandDeclaration(int num) {
	std::cout << "\n" << pPlayerData[num]._name << "�u�X�^���h���܂��v";
	Sleep(1000);
}

//�o�[�X�g�錾
void Player::BurstDeclaration() {
	for (int num = 0; num < Player_Number; num++) {
		if (num == 0 && pPlayerData[num]._burst == false)
		{
			std::cout << "\n" << pPlayerData[num]._name << "���o�[�X�g�����̂Łu" << pPlayerData[1]._name << "�v�̏����ł�\n";
		}
		else if (num == 1 && pPlayerData[num]._burst == false)
		{
			std::cout << "\n�o�[�X�g�����̂Łu" << pPlayerData[1]._name << "�v�̕����ł�\n";
		}
	}
}

//����or���������錾
void Player::VictoryDeclaration(int judge) {
	if (judge >= 0)
	{
		std::cout <<"\n�u" << pPlayerData[judge]._name << "�v�̏����ł�\n";
	}
	else if (judge < 0)
	{
		std::cout << "\n���������ł�\n";
	}
	else 
	{
		std::cout << "\n�����Ȓl�f�X\n";
	}
}