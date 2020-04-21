#include"Stdafx.h"

///<������������� ���>
 list* init(int a)  // �- �������� ������� ����
{

    struct list* lst;
    // ��������� ������ ��� ������ ������
    lst = (struct list*)malloc(sizeof(struct list));
    lst->field = a;
    lst->next = lst; // ��������� �� ��������� ����
    lst->prev = lst; // ��������� �� ���������� ����
    return(lst);
}
///<\������������� ���>

///<���������� ���� � ���>
 list* addelem(list* lst, int number)
{     list* temp, * p;
    temp = ( list*)malloc(sizeof(list));
    p = lst->next; // ���������� ��������� �� ��������� ����
    lst->next = temp; // ���������� ���� ��������� �� �����������
    temp->field = number; // ���������� ���� ������ ������������ ����
    temp->next = p; // ��������� ���� ��������� �� ��������� ����
    temp->prev = lst; // ��������� ���� ��������� �� ���������� ����
    p->prev = temp;
    return(temp);
}
///<\���������� ���� � ���>

///<�������� ���� ���>
 list*  deletelem(list* lst)
{
     list* prev, * next;
    prev = lst->prev; // ����, �������������� lst
    next = lst->next; // ����, ��������� �� lst
    prev->next = lst->next; // ������������ ���������
    next->prev = lst->prev; // ������������ ���������
    free(lst); // ����������� ������ ���������� ��������
    return(prev);
}
///<\�������� ���� ���>

///<����� ��������� ���>
void listprint(list* lst)
{
     list* p;
    p = lst;
    do {
        printf("%d ", p->field); // ����� �������� �������� p
        p = p->next; // ������� � ���������� ����
    } while (p != lst); // ������� ��������� ������
}
///<\����� ��������� ���>

///< ����� ��������� ��� � �������� �������>
void listprintreverse(list* lst)
{
    struct list* p;
    p = lst;
    do {
        p = p->prev;  // ������� � ����������� ����
        printf("%d ", p->field); // ����� �������� �������� p
    } while (p != lst); // ������� ��������� ������
}
///<\����� ��������� ��� � �������� �������>


///<����������� ����� ���( Swap() )>
 list* swap( list *firstelem,  list* secelem,  list* head)
{
    // ���������� ����� ������ ������
    struct list* prev1, * prev2, * next1, * next2;
    prev1 = firstelem->prev; // ���� �������������� lst1
    prev2 = secelem->prev; // ���� �������������� lst2
    next1 = firstelem->next; // ���� ��������� �� lst1
    next2 = secelem->next; // ���� ��������� �� lst2
    if (secelem == next1)  // ������������ �������� ����
    {
        secelem->next = firstelem;
        secelem->prev = prev1;
        firstelem->next = next2;
        firstelem->prev = secelem;
        next2->prev = firstelem;
        prev1->next = secelem;
    }
    else if (firstelem == next2)  // ������������ �������� ����
    {
        firstelem->next = secelem;
        firstelem->prev = prev2;
        secelem->next = next1;
        secelem->prev = firstelem;
        next1->prev = secelem;
        prev2->next = firstelem;
    }
    else  // ������������ ��������� ����
    {
        prev1->next = secelem;
        secelem->next = next1;
        prev2->next = firstelem;
        firstelem->next = next2;
        secelem->prev = prev1;
        next2->prev = firstelem;
        firstelem->prev = prev2;
        next1->prev = secelem;
    }
    if (firstelem == head)
        return(secelem);
    if (secelem == head)
        return(firstelem);
    return(head);
}
///<\����������� ����� ���( Swap() )>


