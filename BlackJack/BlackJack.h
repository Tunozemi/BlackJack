#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP
#include "Player.h"
#include "Judge.h"

//----------�N���X�̒�`----------
//���̃N���X��BlackJack�̎d�l�Ƃ��������݂����Ȃ���
class BlackJack {
public:
	BlackJack();	//�R���X�g���N�^�̐錾
	~BlackJack();	//�f�X�g���N�^�̐錾

	bool Start();		//���Ԑ�����������
	bool End();			//���Ԑ�����������
};
#endif