#pragma once
#include "stdafx.h"
#include "CodeGeneration.h"
#include "Error.h"
#include "FST.h"
#include "GRB.h"
#include "In.h"
#include "IT.h"
#include "LexicalAnalize.h" 
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

namespace Log		//������ � ����������
{
	struct LOG		//��������
	{
		wchar_t logfile[PARM_MAX_SIZE];		//��� ����� ���������
		std::ofstream * stream;				//�������� �����
	};

	static const LOG INITLOG = { L"", NULL };		//��������� ��� ��������� ������������� LOG
	LOG  GetLog(wchar_t logfile[]);					//������������ ��������� LOG
	void WriteLine(LOG log, char* c, ...);			//������� � �������� ������������ �����
	void WriteLine(LOG log, wchar_t* c, ...);		//������� � �������� ������������ �����
	void WriteLog(LOG log);							//������� � �������� ���������
	void WriteParm(LOG log, Parm::PARM parm);		//������� � �������� ���������� � ������� ����������
	void WriteIn(LOG log, In::IN in);				//������� � �������� ���������� � ������� ������
	void WriteError(LOG log, Error::ERROR error);	//������� � ������ ���������� �� ������
	void WriteLexTable(LOG log, LT::LexTable lexT);
	void WriteIdTable(LOG log, IT::IdTable idT);
	void Close(LOG log);							//������� ��������
}