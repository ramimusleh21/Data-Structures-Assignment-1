#pragma once
#include "globals.h"
#include "QueueOperations.h"

FACTION ChooseFaction();

string PrintFaction(FACTION faction);

void PrintUser(NODE* node);

void PrintFullQueue(QUEUE* Q);

void PrintUserName(NODE* node);

string ChooseUserName();

string SelectRandomNumber();

int ChooseLvl();

string SelectRandomNamePart(string* list);