#include "BlackJack.h"
#define Player_Number (2)

//----------�R���X�g���N�^�̒�`----------
BlackJack::BlackJack() {}

//----------�f�X�g���N�^�̒�`----------
BlackJack::~BlackJack() {}

//----------�����o���\�b�h�̒�`----------
//�Q�[���I�����\�b�h
bool BlackJack::Start() {

	//�C���X�^���X�錾
	Player player;
	CardData card;

	player.NameInput();		//���O����
	bool end = true;
	while (end)
	{
		player.DrawCard(card);
		//�݂��̃J�[�h��\��
		player.CardConfirmation(true);

		//�h���[or�X�^���h�I��
		if (!player.DrawOrStand(card)) 
		{
			//false�ŋ����I��
			player.BurstDeclaration();
			end = false;
		}
		else 
		{
			//�݂��̃J�[�h��\�����ď���
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

//�I�����ɌĂяo������
bool BlackJack:: End() {
	int end;
	printf_s("\n�I������ɂ�0����͂��Ă�������:");
	scanf_s("%d", &end);
	if (end == 0)
	{
		printf_s("BJ���I��\n");
		return false;
	}
	else 
	{
		printf_s("\n--------------------------------------------------\n");
		printf_s("\n\n������x���܂�\n");
		return true;
	}
	return true;
}
