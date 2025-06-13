#pragma once


Queue* initializeQueue();

bool Enqueue(QUEUE* Q);

void Dequeue(QUEUE* Q, int selection);

void Peek(NODE* node);

void Pop(QUEUE* Q);

int QueueSize(QUEUE& Q);

bool IsEmpty(QUEUE* Q);

void DeleteQueue(QUEUE* Q);