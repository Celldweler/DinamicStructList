#include"Stdafx.h"

///<Инициализация ДЦС>
 list* init(int a)  // а- значение первого узла
{

    struct list* lst;
    // выделение памяти под корень списка
    lst = (struct list*)malloc(sizeof(struct list));
    lst->field = a;
    lst->next = lst; // указатель на следующий узел
    lst->prev = lst; // указатель на предыдущий узел
    return(lst);
}
///<\Инициализация ДЦС>

///<Добавление узла в ДЦС>
 list* addelem(list* lst, int number)
{     list* temp, * p;
    temp = ( list*)malloc(sizeof(list));
    p = lst->next; // сохранение указателя на следующий узел
    lst->next = temp; // предыдущий узел указывает на создаваемый
    temp->field = number; // сохранение поля данных добавляемого узла
    temp->next = p; // созданный узел указывает на следующий узел
    temp->prev = lst; // созданный узел указывает на предыдущий узел
    p->prev = temp;
    return(temp);
}
///<\Добавление узла в ДЦС>

///<Удаление узла ДЦС>
 list*  deletelem(list* lst)
{
     list* prev, * next;
    prev = lst->prev; // узел, предшествующий lst
    next = lst->next; // узел, следующий за lst
    prev->next = lst->next; // переставляем указатель
    next->prev = lst->prev; // переставляем указатель
    free(lst); // освобождаем память удаляемого элемента
    return(prev);
}
///<\Удаление узла ДЦС>

///<Вывод элементов ДЦС>
void listprint(list* lst)
{
     list* p;
    p = lst;
    do {
        printf("%d ", p->field); // вывод значения элемента p
        p = p->next; // переход к следующему узлу
    } while (p != lst); // условие окончания обхода
}
///<\Вывод элементов ДЦС>

///< Вывод элементов ДЦС в обратном порядке>
void listprintreverse(list* lst)
{
    struct list* p;
    p = lst;
    do {
        p = p->prev;  // переход к предыдущему узлу
        printf("%d ", p->field); // вывод значения элемента p
    } while (p != lst); // условие окончания обхода
}
///<\Вывод элементов ДЦС в обратном порядке>


///<Взаимообмен узлов ДЦС( Swap() )>
 list* swap( list *firstelem,  list* secelem,  list* head)
{
    // Возвращает новый корень списка
    struct list* prev1, * prev2, * next1, * next2;
    prev1 = firstelem->prev; // узел предшествующий lst1
    prev2 = secelem->prev; // узел предшествующий lst2
    next1 = firstelem->next; // узел следующий за lst1
    next2 = secelem->next; // узел следующий за lst2
    if (secelem == next1)  // обмениваются соседние узлы
    {
        secelem->next = firstelem;
        secelem->prev = prev1;
        firstelem->next = next2;
        firstelem->prev = secelem;
        next2->prev = firstelem;
        prev1->next = secelem;
    }
    else if (firstelem == next2)  // обмениваются соседние узлы
    {
        firstelem->next = secelem;
        firstelem->prev = prev2;
        secelem->next = next1;
        secelem->prev = firstelem;
        next1->prev = secelem;
        prev2->next = firstelem;
    }
    else  // обмениваются отстоящие узлы
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
///<\Взаимообмен узлов ДЦС( Swap() )>


