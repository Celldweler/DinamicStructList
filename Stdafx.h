#pragma once
#include <iostream>
#include <string>
#include<algorithm>
#include<ctime>
#include <Windows.h>
#define TRUE 1
#pragma warning(disable : 4996)

#include"ListDLC.h"
///Func List
struct list* init(int a);  
struct list* addelem(list* lst, int number);
struct list* deletelem(list* lst);
void listprint(list* lst);
void listprintreverse(list* lst);
list* swap(list* firstelem, list* secelem, list* head);
///
#include"DL_List.h"
dl_List* create_list_dl(double a);
dl_List* push_back(dl_List* lst, double number);
dl_List* remove_elem(dl_List* lst);
dl_List* remove_head(dl_List* root);
void show_list_dl(dl_List* lst);
void show_reverse_list_dl(dl_List* lst);


struct List; 
int WorkFunc(List* Begin);
List* CreateList(void);
void DisplayList(List* Begin);
///void RemoveTermBegin(List** Begin);Нерабочая функция
List* deletehead(List* root);
void RemoveTermTag(List* Begin);
void RemoveTermEnd(List* Begin);
void AddTermBegin(List** Begin);
void AddTermEnd(List* Begin);
void AddTermTag(List* Begin);
void FreeList(List** Begin);
