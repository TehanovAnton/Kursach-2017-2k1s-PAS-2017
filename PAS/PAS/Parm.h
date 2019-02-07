#pragma once
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
#include "PolishNotation.h"
#include "SemA.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <queue>
#include<iomanip>
#include <stack>

#define PARM_IN  L"-in:"				//���� ��� ����� ��������� ����
#define PARM_OUT L"-out:"				//���� ��� ����� ���������� ����
#define PARM_LOG L"-log:"				//���� ��� ����� �������
#define PARM_lex L"-lex"
#define PARM_ID  L"-id"
#define PARM_TREE L"-tree"
#define PARM_MAX_SIZE 300				//������������ ����� ������ ���������
#define PARM_OUT_DEFAULT_EXT L".out"	//���������� ����� ���������� ���� �� ���������
#define PARM_LOG_DEFAULT_EXT L".log"	//���������� ����� ��������� �� ���������

namespace Parm		//��������� ������� ����������
{
	struct PARM		//������� ���������
	{
		wchar_t in[PARM_MAX_SIZE];		//-in:  ��� ����� ��������� ����
		wchar_t out[PARM_MAX_SIZE];		//-out: ��� ����� ���������� ����
		wchar_t log[PARM_MAX_SIZE];		//-lig: ��� ����� ���������

		bool lex = false;
		bool id = false;
		bool tree = false;
	};
	PARM getparm(int argc, _TCHAR* argv[]);	//������������ struct PARM �� ������ ���������� ������� main
}