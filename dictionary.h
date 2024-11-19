#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAIN_ENTITY_POINTER 0
#define EMPTY_POINTER -1
#define DATA_BLOCK_SIZE 0

typedef struct Entity
{
  char name[DATA_BLOCK_SIZE];
  long dataPointer;
  long attributesPointer;
  long nextEntity;
} ENTITY;

typedef struct Attribute
{
  char name[DATA_BLOCK_SIZE];
  bool isPrimary;
  int type;
  int size;
  long nextAttribute;
}

FILE* initializeDataDictionary(cosnt char *dictionaryName);

int appendEntity(FILE* dataDictionary, ENTITY newEntity);
void reorderEntity(FILE *dataDictionary, long currentEntityPointer, const char* newEntityName, long newEntityDirection);

int appendAttribute(FILE *dataDictionary, ATRIBUTE newAttribute);
void reorderAttribute(FILE *dataDictionary, long currentttributePointer, const char* newAttributeName, long newAttributeDirection);
#endif
