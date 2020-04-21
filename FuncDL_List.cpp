#include"Stdafx.h"

dl_List* create_list_dl(double a) 
{ // а- значение первого узла
	struct dl_List* lst;
	// выделение памяти под корень списка
	lst = ( dl_List*)malloc(sizeof( dl_List));
	lst->field = a;
	lst->next = nullptr; // указатель на следующий узел
	lst->prev = nullptr; // указатель на предыдущий узел
	return(lst);
}


dl_List* push_back(dl_List* lst, double number)
{
	struct dl_List* temp, * p;
	temp = (struct dl_List*)malloc(sizeof(dl_List));
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->field = number; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = lst; // созданный узел указывает на предыдущий узел
	if (p != nullptr)
		p->prev = temp;
	return(temp);
}


 dl_List* remove_elem(dl_List* lst)
{
	struct dl_List* prev, * next;
	prev = lst->prev; // узел, предшествующий lst
	next = lst->next; // узел, следующий за lst
	if (prev != nullptr)
		prev->next = lst->next; // переставляем указатель
	if (next != NULL)
		next->prev = lst->prev; // переставляем указатель
	free(lst); // освобождаем память удаляемого элемента
	return(prev);
}

 dl_List* remove_head(dl_List* root) 
 {
	struct dl_List* temp;
	temp = root->next;
	temp->prev = nullptr;
	free(root);   // освобождение памяти текущего корня
	return(temp); // новый корень списка
}

void show_list_dl(dl_List* lst)
{
	 dl_List* p;
	p = lst;
	do {
		printf("%f ", p->field); // вывод значения элемента p
		p = p->next; // переход к следующему узлу
	} while (p != nullptr); // условие окончания обхода
}
void show_reverse_list_dl(dl_List* lst)
{
	 dl_List* p;
	p = lst;
	while (p->next != nullptr)
		p = p->next;  // переход к концу списка
	do {
		printf("%f ", p->field); // вывод значения элемента p
		p = p->next; // переход к следующему узлу
	} while (p != nullptr); // условие окончания обхода
}
