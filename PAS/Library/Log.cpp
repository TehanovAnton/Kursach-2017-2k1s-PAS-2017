#include "stdafx.h"
#include "Log.h"
#include <ctime>

namespace Log
{
	LOG GetLog(wchar_t logfile[])
	{
		std::ofstream out(logfile);

		LOG *rc = new LOG;
		rc->stream = new std::ofstream(logfile);
		if (rc->stream->fail())
		{
			throw ERROR_THROW(112);
		}
		wcscpy_s(rc->logfile, logfile);
		return *rc;
	}
	void WriteLine(LOG log, char* c, ...)
	{
		char **p = &c;
		while (strcmp(*p, ""))
		{
			*(log.stream) << *p;
			p++;
		}
	}
	void WriteLine(LOG log, wchar_t* c, ...)
	{
		wchar_t **p = &c;
		char buf[PARM_MAX_SIZE];
		while (wcscmp(*p, L""))
		{
			wcstombs(buf, *p, PARM_MAX_SIZE);
			*(log.stream) << buf;
			p++;
		}
	}
	void WriteLog(LOG log)
	{
		*(log.stream) << "--- �������� ----" << std::endl;
		time_t sec;
		char buf[80];
		time(&sec);
		tm *k = localtime(&sec);
		strftime(buf, 80, " %x %X", k);
		*(log.stream) << "����: " << buf << std::endl;
	}
	void WriteParm(LOG log, Parm::PARM parm)
	{
		char buf[PARM_MAX_SIZE];
		*(log.stream) << "---- ��������� --------" << std::endl;
		wcstombs(buf, parm.log, PARM_MAX_SIZE);
		*(log.stream) << "-log: " << buf << std::endl;
		wcstombs(buf, parm.out, PARM_MAX_SIZE);
		*(log.stream) << "-out: " << buf << std::endl;
		wcstombs(buf, parm.in, PARM_MAX_SIZE);
		*(log.stream) << "-in: " << buf << std::endl;
	}
	void WriteIn(LOG log, In::IN in)
	{
		*(log.stream) << "--- �������� ������ ------" << std::endl;
		*(log.stream) << "���������� ��������: " << in.size << std::endl;
		*(log.stream) << "���������� �����: " << in.lines << std::endl;
	}
	void WriteError(LOG log, Error::ERROR error)
	{
		*(log.stream) << "������ " << error.id << ": " << error.message << std::endl;
		*(log.stream) << "������ " << error.inext.line << " ������� " << error.inext.col << std::endl;
	}
	void WriteLexTable(LOG log, LT::LexTable lexT)
	{
		*(log.stream) << "\n\n-----------������� ������-------------" << std::endl;
		*(log.stream) << "����� | ������� | ������ | ������ � ��  \n";
		for (int i = 0; i < lexT.size; i++)
		{
			if (lexT.table[i].idxTI == (-1))
			{
				*(log.stream) << i << "\t     " << lexT.table[i].lexema << "\t       " << lexT.table[i].sn << "    \t" << "-//-" << std::endl;
			}
			else
			{
				*(log.stream) << i << "\t     " << lexT.table[i].lexema << "\t       " << lexT.table[i].sn << "    \t" <<"-"<< lexT.table[i].idxTI<<"-" << std::endl;
			}
		}
	}
	void WriteIdTable(LOG log, IT::IdTable idT)
	{
		*(log.stream) << "---------------------------------------------------------------------------------" << std::endl;
		*(log.stream) << "--------------------------������� ���������������--------------------------------" << std::endl;
		*(log.stream) << "---------------------------------------------------------------------------------" << std::endl;

		for (int i = 0; i < idT.size; i++)
		{
			if ((idT.table[i].idtype == 1) || (idT.table[i].idtype == 2) || (idT.table[i].idtype == 3) || (idT.table[i].idtype == 4))
			{
				
				if (idT.table[i].iddatatype == 1) 
				{ 
					if (idT.table[i].idtype == 1)
						*(log.stream) <<"�"<< i << ": " << "���������� ���� count " << idT.table[i].id <<" = " << idT.table[i].value.vint << std::endl;
					if (idT.table[i].idtype == 2)
						*(log.stream) << "�" << i << ": " << "������� ���� count " << idT.table[i].id << std::endl;
					if (idT.table[i].idtype == 3)
						*(log.stream) << "�" << i << ": " << "�������� ���� count " << idT.table[i].id << " = " << idT.table[i].value.vint << std::endl;
					if (idT.table[i].idtype == 4)
						*(log.stream) << "�" << i << ": " << "������� ���� count " << idT.table[i].id << " = " << idT.table[i].value.vint << std::endl;
					*(log.stream) << std::endl;
				}
				if (idT.table[i].iddatatype == 2) 
				{ 
					if (idT.table[i].idtype == 1)
						*(log.stream) << "�" << i << ": " << "���������� ���� road " << idT.table[i].id << " = '" << idT.table[i].value.vstr.str << "' (����� = " << idT.table[i].value.vstr.len << ")" << std::endl;
					if (idT.table[i].idtype == 2)
						*(log.stream) << "�" << i << ": " << "������� ���� road " << idT.table[i].id << std::endl;
					if (idT.table[i].idtype == 3)
						*(log.stream) << "�" << i << ": " << "�������� ���� road " << idT.table[i].id << " = '" << idT.table[i].value.vstr.str << "' (����� = " << idT.table[i].value.vstr.len << ")" << std::endl;
					if (idT.table[i].idtype == 4)
						*(log.stream) << "�" << i << ": " << "������� ���� road " << idT.table[i].id << " = " << idT.table[i].value.vstr.str << " (����� = " << idT.table[i].value.vstr.len << ")" << std::endl;
					*(log.stream) << std::endl;
				}
			}
		}
		*(log.stream) << "---------------------------------------------------------------------------------" << std::endl;
		*(log.stream) << "---------------------------------------------------------------------------------" << std::endl;
	}
	
	void Close(LOG log)
	{
		log.stream->close();
	}
}