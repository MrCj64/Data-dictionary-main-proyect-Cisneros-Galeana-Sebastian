#include "main.h"

int main(int argc, char** argv)
{
  char name[50];

  printf("\nEnter a Data Dictionary Name: ");
  fgets(name, sizeof(name), stdin);

  CreateEntity(dataDictionary);

  ENTITY currentEntity; // = findEntity(dataDictionary,entityName);
  currentEntity.dataPointer=58;
  currentEntity.attributePointer=66;
  currentEntity.nextEntity=74;

  CreateAttribute(dataDictionary,currentEntity);
  CreateAttribute(dataDictionary,currentEntity);

  fclose(dataDictionary);

  return 0;
}

voidCreateEntity(FILE* dataDictionary)
{
  ENTITY newEntity;
  
  printf("\nEnter the Entity name: ");
  
  fgets(newEntity.name,sizeof(newEntity.name),stdin);
  newEntity.dataPointer=EMPTY_POINTER;
  newEntity.attributesPointer=EMPTY_POINTER;
  newEntity.nextEntity=EMPTY_POINTER;

  long entityDirection=appendEntity(dataDictionary,newEntity);
  reorderEntities(dataDictionary,MAIN_ENTITY_POINTER,newEntity.name,entityDirection);
}

void createAttribute(FILE* dataDictionary, ENTITY currentEntity)
{
  ATTRIBUTE newAttribute;

  printf("\nEnter the Attribute name: ");
  fgets(newAttribute.name,sizeof(newAttribute.name),stdin);

  // printf("\n Es clave primaria?: ");
  newAttribute.isPrimary=false;

  // printf("\n Tipo de atributo? 1)int 2)long 3)float 4)char 5)bool : ");
  newAttribute.type=1;
  newAttribute.size=sizeof(int);

  // newAttribute.type=1;
  // newAttribute.size=sizeof(long);

  // newAttribute.type=1;
  // newAttribute.size=sizeof(float);

  // newAttribute.type=1;
  // newAttribute.size=sizeof(char;

  // newAttribute.type=1;
  // newAttribute.size=sizeof(bool);

  newAttribute.nextAttribute=EMPTY_POINTER;

  long attributeDirection=appendAtribute(dataDictionary,newAttriute);
  reorderAttributes(dataDictionary,currentEntity.attributesPointer,newAttribute.name,attributeDirection);
}
