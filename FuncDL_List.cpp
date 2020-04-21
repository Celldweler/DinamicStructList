#include"Stdafx.h"

dl_List* create_list_dl(double a) 
{ // �- �������� ������� ����
	struct dl_List* lst;
	// ��������� ������ ��� ������ ������
	lst = ( dl_List*)malloc(sizeof( dl_List));
	lst->field = a;
	lst->next = nullptr; // ��������� �� ��������� ����
	lst->prev = nullptr; // ��������� �� ���������� ����
	return(lst);
}


dl_List* push_back(dl_List* lst, double number)
{
	struct dl_List* temp, * p;
	temp = (struct dl_List*)malloc(sizeof(dl_List));
	p = lst->next; // ���������� ��������� �� ��������� ����
	lst->next = temp; // ���������� ���� ��������� �� �����������
	temp->field = number; // ���������� ���� ������ ������������ ����
	temp->next = p; // ��������� ���� ��������� �� ��������� ����
	temp->prev = lst; // ��������� ���� ��������� �� ���������� ����
	if (p != nullptr)
		p->prev = temp;
	return(temp);
}


 dl_List* remove_elem(dl_List* lst)
{
	struct dl_List* prev, * next;
	prev = lst->prev; // ����, �������������� lst
	next = lst->next; // ����, ��������� �� lst
	if (prev != nullptr)
		prev->next = lst->next; // ������������ ���������
	if (next != NULL)
		next->prev = lst->prev; // ������������ ���������
	free(lst); // ����������� ������ ���������� ��������
	return(prev);
}

 dl_List* remove_head(dl_List* root) 
 {
	struct dl_List* temp;
	temp = root->next;
	temp->prev = nullptr;
	free(root);   // ������������ ������ �������� �����
	return(temp); // ����� ������ ������
}

void show_list_dl(dl_List* lst)
{
	 dl_List* p;
	p = lst;
	do {
		printf("%f ", p->field); // ����� �������� �������� p
		p = p->next; // ������� � ���������� ����
	} while (p != nullptr); // ������� ��������� ������
}
void show_reverse_list_dl(dl_List* lst)
{
	 dl_List* p;
	p = lst;
	while (p->next != nullptr)
		p = p->next;  // ������� � ����� ������
	do {
		printf("%f ", p->field); // ����� �������� �������� p
		p = p->next; // ������� � ���������� ����
	} while (p != nullptr); // ������� ��������� ������
}
