#include "GRB.h"
#include"Rules_GRB.h"
#include "string.h"

namespace GRB
{
	//Структура: представление цепочки – правой стороны правила.
	Rule::Chain::Chain(short psize, GRBALPHABET s, ...)
	{
		
		this->nt = new GRBALPHABET[this->size = psize];
		int* ptr = (int*)&s;
		// Заполняем массив nt элементами из ptr (int-представления переменной s).
		for (int i = 0; i < psize; i++)
			this->nt[i] = (short)ptr[i];
	}

	
	Rule::Rule(GRBALPHABET pnn, int iderroe, short psize, Chain c, ...)
	{
		//сохраняем нетерминал
		this->nn = pnn;
		this->iderror = iderroe;
		
		this->chains = new Chain[this->size = psize];
		
		Chain* ptr = &c;
		
		for (int i = 0; i < psize; i++)
			this->chains[i] = ptr[i];
	}

	Greibach::Greibach(GRBALPHABET pstartN, GRBALPHABET pstbottomT, short psize, Rule r, ...)
	{////создать объект грамматики, содержащий:Начальный символ.Символ дна стека.Список правил.
		
		this->startN = pstartN; // Устанавливаем начальный символ (нетерминал).
		this->stbottomT = pstbottomT; // Устанавливаем символ дна стека (терминал).
		
		this->rules = new Rule[this->size = psize];
		// Присваиваем указатель на объект Rule r указателю ptr.
		Rule* ptr = &r;
		
		for (int i = 0; i < psize; i++)
			rules[i] = ptr[i];
	}

	//метод для поиска правила в массиве
	short Greibach::getRule(GRBALPHABET pnn, Rule& prule)
	{
		short rc = -1; // Инициализируем переменную rc значением -1.
		short k = 0; // Инициализируем переменную k значением 0.
		while (k < this->size && rules[k].nn != pnn)
		{
			k++; 
		}
		if (k < this->size)
		{
			prule = rules[k];
			rc = k;
		}
		return rc; 

	}

	//возвращает правило с индексом n из массива rules
	Rule Greibach::getRule(short n)
	{
		Rule rc; 

		if (n < this->size)
		{
			rc = rules[n];
		}
		return rc;
	}

	//формирования строкового представления правил
	char* Rule::getCRule(char* b, short nchain)
	{
		char buf[200]; // Создаем временный буфер для хранения цепочки.
		b[0] = Chain::alphabet_to_char(this->nn);
		b[1] = '-';
		b[2] = '>';
		b[3] = 0x00;
		// Этот метод копирует содержимое цепочки в буфер `buf`.
		this->chains[nchain].getCChain(buf);
		
		strcat_s(b, sizeof(buf) + 5, buf);
		return b; // Возвращаем указатель на буфер `b`, содержащий строку представления правила.
	}

	//поиск цепочки в массиве,где первый элемент равен значению t, переданному в аргументе.
	short Rule::getNextChain(GRBALPHABET t, Rule::Chain& pchain, short j)
	{
		short rc = -1; 

		while (j < this->size && this->chains[j].nt[0] != t)
		{
			j++;
		}
		if (j < this->size)
		{
			pchain = chains[j];
			rc = j; 
		}
		return rc;
	}

	//позволяет получить строковое представление
	char* Rule::Chain::getCChain(char* b)
	{
		
		for (int i = 0; i < this->size; i++)
		{
			
			b[i] = Chain::alphabet_to_char(this->nt[i]);
		}
		b[this->size] = '\0';
		return b;
	}

	Greibach getGreibach()
	{
		return greibach; 
	}

}