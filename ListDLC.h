#pragma once
#ifndef _ListDlc
#define _ListDlc
///<Двусвязный циклический список>
struct list
{
    int field; // поле данных
    struct list* next; // указатель на следующий элемент
    struct list* prev; // указатель на предыдущий элемент
   

};///<\Двусвязный циклический список>



#endif // !_ListDlc
