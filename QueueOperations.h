#pragma once


Queue* initializeQueue();

void Enqueue(QUEUE* Q);

void Dequeue(QUEUE* Q);

void Peek(NODE* node);

int QueueSize(QUEUE& Q);

bool IsEmpty(QUEUE* Q);

void DeleteQueue(QUEUE* Q);