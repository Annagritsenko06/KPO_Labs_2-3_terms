
#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{

    argc = 1;
    argv[0] = (_TCHAR*)L"-in:C:\\Users\\admin\\Documents\\SE_Lab14\\SE_Lab14\\in.txt";

    setlocale(LC_ALL, "Rus");

    Log::LOG log = Log::INITLOG;
    Out::OUT out = Out::INITOUT;
    try
    {
        Parm::PARM parm = Parm::getparm(argc, argv);

        log = Log::getlog(parm.log);
        out = Out::getOut(parm.out);

        Log::WriteLog(log);
        Log::WriteParm(log, parm);
        In::IN in = In::getin(parm.in); // возвращает структуру IN с обработанными данными.
    Log:WriteIn(log, in); // протокол
        Out::WriteOut(out, in); // выходной файл

        LT::LexTable lexTable; // экзепл€р таблицы лексем
        IT::IdTable idTable; //экземпл€р таблицы идентификаторов

        LA::LexicalAnalyzer(in, lexTable, idTable);

        lexTable.PrintLexTable(L"TableOfLexems.txt");
        idTable.PrintIdTable(L"TableOfIdentificators.txt");

        LT::Delete(lexTable);
        IT::Delete(idTable);
        Log::Close(log);
        Out::Close(out);
    }
    catch (Error::ERROR e)
    {
        Log::WriteError(log, e);
        Out::WriteError(out, e);
    }

    return 0;
}