#pragma once
#include "Player.h"
#include <string>


//----------�N���X�̒�`----------
//���̃N���X��BlackJack�̎d�l�Ƃ��������݂����Ȃ���
class Table {
public:
	void CardSumConfirmation();			//���v�l�\��
	void Partition();					//�d�؂�

private:
	Table();	//�R���X�g���N�^�̐錾
	~Table();	//�f�X�g���N�^�̐錾

};