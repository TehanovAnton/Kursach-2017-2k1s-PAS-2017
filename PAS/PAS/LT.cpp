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

namespace LT
{
	LexTable Create(int size)
	{
		LexTable *p = new LexTable;					//�������� ���������� ������� ������
		p->maxize = size;							//������� ������������ �������
		p->size = 0;								//��������� ������ ����� ����
		p->table = new Entry[size];					//�������� �������� ����� ������� ������
		memset(p->table, 255, 255);					//���������� ����������� ������� ����� �� 255
		return *p;
	}
	Entry Add(LexTable& lextable, Entry entry)
	{
		return(lextable.table[lextable.size++] = entry);			//��������� �� ������� �������� ������� ������� ������ �������� ������� ����� ������
	}
	Entry GetEtry(LexTable& lextable, int n)
	{
		return (lextable.table[n]);
	}
	void Delete(LexTable& lextable)
	{
		delete[] lextable.table;
	}
}