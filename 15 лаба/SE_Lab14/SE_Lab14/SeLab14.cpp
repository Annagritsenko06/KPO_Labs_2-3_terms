
#include "stdafx.h"  // Включение стандартных заголовочных файлов

int _tmain(int argc, _TCHAR* argv[])
{
    // Инициализация аргументов командной строки
    argc = 1;
    argv[0] = (_TCHAR*)L"-in:C:\\Users\\admin\\Documents\\уник\\3 СЕМ\\КПО\\15 лаба\\SE_Lab14\\SE_Lab14\\in.txt";

    setlocale(LC_ALL, "Rus");  // Установка локали на русскую для корректного отображения русских символов

    // Инициализация логирования и выходных данных
    Log::LOG log = Log::INITLOG;
    Out::OUT out = Out::INITOUT;

    try
    {
        // Получение параметров из аргументов командной строки
        Parm::PARM parm = Parm::getparm(argc, argv);

        // Инициализация логирования и выходных данных на основе полученных параметров
        log = Log::getlog(parm.log);
        out = Out::getOut(parm.out);

        // Запись начальной информации в лог
        Log::WriteLog(log);
        Log::WriteParm(log, parm);

        // Чтение входного файла и обработка данных
        In::IN in = In::getin(parm.in); // возвращает структуру IN с обработанными данными.
        Log::WriteIn(log, in); // Запись обработанных данных во входной лог
        Out::WriteOut(out, in); // Запись обработанных данных в выходной файл

        // Закрытие логирования и выходных данных
        Log::Close(log);
        Out::Close(out);
    }
    catch (Error::ERROR e)
    {
        // Обработка ошибок: запись ошибки в лог и выходной файл
        Log::WriteError(log, e);
        Out::WriteError(out, e);
    }

    return 0;
}