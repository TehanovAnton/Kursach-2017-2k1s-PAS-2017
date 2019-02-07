#include "stdafx.h"

#include "CodeGeneration.h"
#include "Error.h"
#include "FST.h"
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

#define GRB_ERROR_SERIES 600

namespace GRB
{
	Greibach greibach(NS('S'), TS('$'), 6,
		Rule(NS('S'), GRB_ERROR_SERIES, 3,   //  ��������� ���������
			Rule::Chain(10, TS('p'), TS('d'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('}'), NS('S')),
			Rule::Chain(10, TS('p'), TS('s'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('}'), NS('S')),
			Rule::Chain(4, TS('h'), TS('{'), NS('N'), TS('}'))
		),
		Rule(NS('F'), GRB_ERROR_SERIES + 1, 4,  // ��������� �-��
			Rule::Chain(2, TS('d'), TS('i')),
			Rule::Chain(4, TS('d'), TS('i'), TS(','), NS('F')),
			Rule::Chain(2, TS('s'), TS('i')),
			Rule::Chain(4, TS('s'), TS('i'), TS(','), NS('F'))
		),
		Rule(NS('N'), GRB_ERROR_SERIES + 2, 19,  // ��������� ����������� � �-���
			Rule::Chain(5, TS('v'), TS('d'), TS('i'), TS(';'), NS('N')),
			Rule::Chain(5, TS('v'), TS('s'), TS('i'), TS(';'), NS('N')),
			Rule::Chain(5, TS('i'), TS('='), NS('E'), TS(';'), NS('N')),
			Rule::Chain(10, TS('c'), TS('('), TS('i'), TS('<'), TS('i'), TS(')'), TS('['), NS('N'), TS(']'), NS('N')),
			Rule::Chain(10, TS('c'), TS('('), TS('i'), TS('<'), TS('k'), TS(')'), TS('['), NS('N'), TS(']'), NS('N')),
			Rule::Chain(10, TS('c'), TS('('), TS('k'), TS('<'), TS('i'), TS(')'), TS('['), NS('N'), TS(']'), NS('N')),
			Rule::Chain(10, TS('c'), TS('('), TS('k'), TS('<'), TS('k'), TS(')'), TS('['), NS('N'), TS(']'), NS('N')),
			Rule::Chain(5, TS('e'), TS('['), NS('N'), TS(']'), NS('N')),
			Rule::Chain(3, TS('r'), TS('i'), TS(';')),
			Rule::Chain(3, TS('r'), TS('k'), TS(';')),
			Rule::Chain(3, TS('r'), TS('l'), TS(';')),
			Rule::Chain(6, TS('y'), TS('('), TS('i'), TS(')'), TS(';'), NS('N')),
			Rule::Chain(6, TS('y'), TS('('), TS('l'), TS(')'), TS(';'), NS('N')),
			Rule::Chain(5, TS('y'), TS('('), TS('i'), TS(')'), TS(';')),
			Rule::Chain(5, TS('y'), TS('('), TS('l'), TS(')'), TS(';')),
			Rule::Chain(6, TS('x'), TS('('), TS('i'), TS(')'), TS(';'), NS('N')),
			Rule::Chain(6, TS('x'), TS('('), TS('k'), TS(')'), TS(';'), NS('N')),
			Rule::Chain(5, TS('x'), TS('('), TS('i'), TS(')'), TS(';')),
			Rule::Chain(5, TS('x'), TS('('), TS('k'), TS(')'), TS(';'))
		),
		Rule(NS('E'), GRB_ERROR_SERIES + 3, 28, // ���������
			Rule::Chain(1, TS('i')),
			Rule::Chain(2, TS('i'), NS('M')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(2, TS('l'), NS('M')),
			Rule::Chain(1, TS('k')),
			Rule::Chain(2, TS('k'), NS('M')),
			Rule::Chain(6, TS('g'), TS('('), TS('i'), TS(','), TS('i'), TS(')')),
			Rule::Chain(7, TS('g'), TS('('), TS('i'), TS(','), TS('i'), TS(')'), TS('M')),
			Rule::Chain(6, TS('g'), TS('('), TS('k'), TS(','), TS('i'), TS(')')),
			Rule::Chain(7, TS('g'), TS('('), TS('k'), TS(','), TS('i'), TS(')'), TS('M')),
			Rule::Chain(6, TS('g'), TS('('), TS('i'), TS(','), TS('k'), TS(')')),
			Rule::Chain(7, TS('g'), TS('('), TS('i'), TS(','), TS('k'), TS(')'), TS('M')),
			Rule::Chain(6, TS('g'), TS('('), TS('k'), TS(','), TS('k'), TS(')')),
			Rule::Chain(7, TS('g'), TS('('), TS('k'), TS(','), TS('k'), TS(')'), TS('M')),
			Rule::Chain(6, TS('a'), TS('('), TS('i'), TS(','), TS('i'), TS(')')),
			Rule::Chain(7, TS('a'), TS('('), TS('i'), TS(','), TS('i'), TS(')'), TS('M')),
			Rule::Chain(6, TS('a'), TS('('), TS('k'), TS(','), TS('i'), TS(')')),
			Rule::Chain(7, TS('a'), TS('('), TS('k'), TS(','), TS('i'), TS(')'), TS('M')),
			Rule::Chain(6, TS('a'), TS('('), TS('i'), TS(','), TS('k'), TS(')')),
			Rule::Chain(7, TS('a'), TS('('), TS('i'), TS(','), TS('k'), TS(')'), TS('M')),
			Rule::Chain(6, TS('a'), TS('('), TS('k'), TS(','), TS('k'), TS(')')),
			Rule::Chain(7, TS('a'), TS('('), TS('k'), TS(','), TS('k'), TS(')'), TS('M')),
			Rule::Chain(4, TS('z'), TS('('), TS('i'), TS(')')),
			Rule::Chain(5, TS('z'), TS('('), TS('i'), TS(')'), NS('M')),
			Rule::Chain(4, TS('z'), TS('('), TS('l'), TS(')')),
			Rule::Chain(5, TS('z'), TS('('), TS('l'), TS(')'), NS('M')),
			Rule::Chain(4, TS('i'), TS('('), NS('W'), TS(')')),
			Rule::Chain(4, TS('i'), TS('('), NS('W'), TS(')'), NS('M'))
		),
		Rule(NS('W'), GRB_ERROR_SERIES + 4, 6, // ����������� ��������� �-��
			Rule::Chain(3, TS('i'), TS(','), NS('W')),
			Rule::Chain(3, TS('l'), TS(','), NS('W')),
			Rule::Chain(3, TS('k'), TS(','), NS('W')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('k'))
		),
		Rule(NS('M'), GRB_ERROR_SERIES + 5, 16, // �����
			Rule::Chain(2, TS('+'), NS('E')),
			Rule::Chain(4, TS('+'), TS('('), NS('E'), TS(')')),
			Rule::Chain(5, TS('+'), TS('('), NS('E'), TS(')'), NS('M')),
			Rule::Chain(3, TS('+'), NS('E'), NS('M')),
			Rule::Chain(2, TS('-'), NS('E')),
			Rule::Chain(4, TS('-'), TS('('), NS('E'), TS(')')),
			Rule::Chain(5, TS('-'), TS('('), NS('E'), TS(')'), NS('M')),
			Rule::Chain(3, TS('-'), NS('E'), NS('M')),
			Rule::Chain(2, TS('*'), NS('E')),
			Rule::Chain(4, TS('*'), TS('('), NS('E'), TS(')')),
			Rule::Chain(5, TS('*'), TS('('), NS('E'), TS(')'), NS('M')),
			Rule::Chain(3, TS('*'), NS('E'), NS('M')),
			Rule::Chain(2, TS('/'), NS('E')),
			Rule::Chain(4, TS('/'), TS('('), NS('E'), TS(')')),
			Rule::Chain(5, TS('/'), TS('('), NS('E'), TS(')'), NS('M')),
			Rule::Chain(3, TS('/'), NS('E'), NS('M'))
		)
	);

	Rule::Chain::Chain(short psize, GRBALPHABET s, ...)  //����������� ������� - ������ ����� �������(���-�� �������� � �������, �������� ��� ����������...)
	{
		nt = new GRBALPHABET[size = psize];    //������� ����������
		int*p = (int*)&s;                      //����������� ������ ��������� �
		for (short i = 0; i < psize; ++i)
			nt[i] = (GRBALPHABET)p[i]; //��������� ������� ����������
	};
	Rule::Rule(GRBALPHABET pnn, int piderror, short psize, Chain c, ...) //����������� �������
	{															//(����������, ������������� ���������������� ���������, ���������� �������(������ ������ �������), ��������� ������� (������ ������ �������)
		nn = pnn;    //����������
		iderror = piderror; //�������������
		chains = new Chain[size = psize]; //����� ��� �������
		Chain*p = &c;
		for (int i = 0; i < size; i++)
			chains[i] = p[i]; //��������� ��������� �������
	};
	Greibach::Greibach(GRBALPHABET pstartN, GRBALPHABET pstbottom, short psize, Rule r, ...)//����������� ���������� ��������(��������� ������, ��� �����, ���������� ������, �������...)
	{
		startN = pstartN; //��������� ������
		stbottomT = pstbottom;//��� �����
		rules = new Rule[size = psize];//�������� ������
		Rule*p = &r;
		for (int i = 0; i < size; i++) rules[i] = p[i];//��������� �������
	};
	Greibach getGreibach() { return greibach; }; //�������� ����������
	short Greibach::getRule(GRBALPHABET pnn, Rule& prule) //�������� ������� (����� ������ �������, ������������ ������� ����������)
	{
		short rc = -1;
		short k = 0;
		while (k < size&&rules[k].nn != pnn)
			k++;   //���� � ������ ���������� ������ � ���� ����� ������ ������� �� ����� �������� �-���
		if (k < size)
			prule = rules[rc = k];    //������������ ������� ��������� ����� ������� � �������� �
		return rc; //������������ ����� ������� ��� -1
	};
	Rule Greibach::getRule(short n) //�������� ������� �� ������
	{
		Rule rc;      //������ ������� ��
		if (n < size)rc = rules[n];  //����������� ������� �� ������� �
		return rc; //���������� ��������� �������
	};
	char*Rule::getCRule(char*b, short nchain) //�������� ������� � ���� N->������� (�����, ����� �������(������ �����) � �������)
	{
		char bchain[200]; //������
		b[0] = Chain::alphabet_to_char(nn); b[1] = '-'; b[2] = '>'; b[3] = 0x00; //�������� -> 
		chains[nchain].getCChain(bchain); //�������� ������ ������� �������
		strcat_s(b, sizeof(bchain) + 5, bchain);//��������� ������ (����, � ������ ��������, ������)
		return b;
	};
	short Rule::getNextChain(GRBALPHABET t, Rule::Chain& pchain, short j) //�������� ��������� �� j ���������� �������, ������� � ����� ��� -1 
	{                                                                //(������ ������ �������, ������������ �������, ����� �������)
		short rc = -1;
		while (j < size&&chains[j].nt[0] != t)++j;
		rc = (j < size ? j : -1);
		if (rc >= 0)pchain = chains[rc];
		return rc;
	};
	char*Rule::Chain::getCChain(char*b) //�������� ������ ������� �������
	{
		for (int i = 0; i < size; i++)b[i] = Chain::alphabet_to_char(nt[i]);
		b[size] = 0x00;
		return b;
	};
};