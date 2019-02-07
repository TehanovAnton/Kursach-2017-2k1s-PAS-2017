#pragma once
#include "CodeGeneration.h"
#include "Error.h" 
#include "GRB.h"
#include "In.h"
#include "IT.h"
#include "LexicalAnalize.h"
#include "Log.h"
#include "LT.h"
#include "MFST.h"
#include "Parm.h"
#include "PolishNotation.h"
#include "SemA.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <queue>
#include<iomanip>
#include <stack>

#define ARR_FST_SIZE 30
namespace FST
{
	struct RELATION			//�����: ������ -> ������� ����� �������� ��
	{
		char symbol;		//������ ��������
		short nnode;		//����� ������� �������
		RELATION(
			char c = 0x00,	//������ ��������
			short ns = NULL //����� ���������
		);
	};

	struct NODE	//������� ����� ���������
	{
		short n_relation;		//���������� ����������� ����
		RELATION *relations;	//����������� ����
		NODE();
		NODE(
			short n,			//���������� ����������� ����
			RELATION rel, ...	//������ ����
		);
	};

	enum LEXAN
	{
		LEXEMS, TYPE, LIT, ID, LIB, HEAD, OPERATOR
	};
	struct FST	//������������������� �������� �������
	{
		char* string;		//������� (������, ����������� 0�00)
		char  lex;			//�������, ��������������� ��������
		short position;		//������� ������� � �������
		short nstates;		//���������� ��������� ��������
		NODE* nodes;		//���� ���������: [0] -��������� ���������, [nstate-1] -��������
		short* rstates;		//��������� ��������� �������� �� ������ �������
		LEXAN lexsw;
		FST(
			char* s,		//�������(������, ����������� 0�00)
			char  l,		//�������, ��������������� ��������
			LEXAN plexsw,
			short ns,		//���������� ��������� ��������
			NODE  n, ...	//������ ��������� (���� ���������)
		);
		FST();
	};

	bool execute(		//��������� ������������� �������
		FST& fst		//������������������� �������� �������
	);
	NODE AllSymb();
	FST* ArrFst();		//������ ���������
}