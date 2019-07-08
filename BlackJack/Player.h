#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "CardData.h"
#include "Judge.h"
#include "UiRe.h"
#include <string>
#include <iostream>
#include <random>
#include <time.h>
#include <windows.h>

//----------�N���X�̒�`----------
//�v���C���[���
class Player {
public:
	Player();									//�R���X�g���N�^�̐錾
	~Player();									//�f�X�g���N�^�̐錾

	typedef struct playerdata {
		std::string _name;					//���O
		std::vector<int> _haveCard;			//�����Ă���J�[�h
		int		_aCount;					//�G�[�X���J�E���g���Ă���
		int		_cardSum;					//�����J�[�h�̍��v�l
		int		_numCount;					//��������
		int		_idNumber;					//ID����U��
		bool	_burst;						//�o�[�X�g
	}playerData_st;

	playerData_st *pPlayerData;				//�\���̂̃|�C���^

	//enum PlayerMembers { dealer, player, both};//enum�Ńf�B�[���[�����\���A�v���C���[�����\���A�����\�����g��������@switch���ɂȂ�H

	void InitializeData();							//�v���C���[�f�[�^�̏�����
	bool NameInput();								//���O����

	void DrawCard(CardData &card);					//�J�[�h���h���[����
	void CardConfirmation(bool);					//�J�[�h��\��

	int CardSum(int);								//���v�l�Z�o
	
	bool DrawOrStand(CardData &card);				//�h���[or�X�^���h�I��
	void DrawCardDeclaration(CardData &card, int);	//�J�[�h���h���[�錾
	void StandDeclaration(int);						//�X�^���h�錾
	void CardConfirmation(int);				//1�񂾂��J�[�h�\��

	void BurstFlag(int num) 
		{ pPlayerData[num]._burst = false; }		//�o�[�X�g�t���O
	void BurstDeclaration();						//�o�[�X�g�錾
	void VictoryDeclaration(int);					//���s�錾
};
#endif