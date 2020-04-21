#pragma once

#ifndef _DL_List
#define _DL_List
struct dl_List
{
	double field; // поле данных
	struct dl_List* next; // указатель на следующий элемент
	struct dl_List* prev; // указатель на предыдущий элемент
};

#endif // !_DL_List
