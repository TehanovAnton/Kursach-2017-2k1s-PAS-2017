#pragma once
#include "stdafx.h"
#include "CodeGeneration.h"
#include "Error.h"
#include "FST.h"
#include "GRB.h"
#include "In.h"
#include "IT.h" 
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


namespace Lex
{
	struct TABLES
	{
		IT::IdTable  Id;
		LT::LexTable Lex;
	};

	TABLES Lexic(In::IN in);				//����������� ������
	int  SelectFst(char* word);			//����� ��������
	void AddId(char*, int, int, int);	//���������� ��������������
	void AddLit(char lex, int str, int id);		//���������� ��������
}