#pragma once
#include "stdafx.h"
#include "CodeGeneration.h"
#include "Error.h"
#include "FST.h"
#include "GRB.h" 
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

#define IN_MAX_LEN_TEXT 1024*1024		//������������ ������� ��������� ���� 1��
#define IN_CODE_ENDL	'\n'			//������ ����� ������
#define STR_NUMB_SEP	'|'				// ��������� ��� ����� ������
#define IN_CODE_SPACE	' '				//�������
#define IN_WORD_MAX_LEN 255				//������������ ������ �����

//������� �������� ������� ����������, ������ = ��� (Windows 1251) �������
//�������� IN::F - ����������� ������, IN::T  - ����������� ������,  IN::I - ������������(�� �������),
//		���� 0<=�������� <256 - �� �������� ������ ��������
#define IN_CODE_TABLE {\
    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::S, IN::S, IN::S, IN::S, IN::S, IN::S, IN::F, IN::F, \
    IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::F, IN::S, IN::S, IN::S, IN::T, IN::F, \
    IN::F, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
    IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::S, IN::F, IN::S, IN::F, IN::F, \
    IN::F, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
    IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::S, IN::F, IN::S, IN::F, IN::F, \
     \
    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
    IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
    IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
    IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, \
    IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T \
    }

//IN::S -- ����������   (  )	*	+	,	-	;	=	{	}
namespace In
{

	struct IN
	{
		enum { T = 1, F = 2, S = 3 };		//� - ����������� ������ F - ������������ S - ��������
		int size;							//������ ��������� ����
		int lines;							//���-�� �����
		std::queue<std::string> Words;
		std::queue<int> Line;
		int code[256] = IN_CODE_TABLE;		//������� �������
	};
	IN getin(wchar_t infile[]);				//������ � �������� ������� �����
};