#pragma once

#ifndef _DL_List
#define _DL_List
struct dl_List
{
	double field; // ���� ������
	struct dl_List* next; // ��������� �� ��������� �������
	struct dl_List* prev; // ��������� �� ���������� �������
};

#endif // !_DL_List
