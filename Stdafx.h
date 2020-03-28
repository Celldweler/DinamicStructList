#pragma once
#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#define TRUE 1
struct List;
List* CreateList(void);
void DisplayList(List* Begin);
void RemoveTermBegin(List** Begin);
void RemoveTermTag(List* Begin);
void RemoveTermEnd(List* Begin);
void AddTermBegin(List** Begin);
void AddTermEnd(List* Begin);
void AddTermTag(List* Begin);
void FreeList(List** Begin);
