#include <stdio.h>
#include <stdlib.h>
#include "Stones.h"

int fromChartoInt(char* a)
{
   int b = 0;
   int rank = 10;
   for (int i = 0; a[i] != '\0'; i++)
   {
      if (a[i] >= '0' && a[i] <= '9')
      b = b * rank + a[i] - '0';
   }
   return b;
}

struct Heap_of_the_stones
{
   int Number_of_stones;
   char* Color_of_stones;
   int Operation_with_stones_plus;
   int Operation_with_stones_multy;
};

char* CombitateColor(HeapS* a, HeapS* b)
{
   if (a->Color_of_stones == NULL || b->Color_of_stones == NULL)
   {
      if (a->Color_of_stones != NULL)
         return a->Color_of_stones;
      if (b->Color_of_stones != NULL)
         return b->Color_of_stones;
      return NULL;
   }
   int flag = 0;
   for (int i = 0; a->Color_of_stones[i] != 0 && b->Color_of_stones[i] != 0; i++)
   {
      if (a->Color_of_stones[i] != b->Color_of_stones[i])
         return "black";
   }
   return a->Color_of_stones;
}

void Make_color(HeapS* heap_, char* color_)
{
   int color = fromChartoInt(color_);
   switch (color)
   {
   case(0):
      heap_->Color_of_stones = "black";
      break;
   case(255255255):
      heap_->Color_of_stones = "white";
      break;
   case(128128128):
      heap_->Color_of_stones = "gray";
      break;
   case(128000128):
      heap_->Color_of_stones = "purple";
      break;
   case(255000000):
      heap_->Color_of_stones = "red";
      break;
   case(255255000):
      heap_->Color_of_stones = "yellow";
      break;
   case(128000):
      heap_->Color_of_stones = "green";
      break;
   case(255):
      heap_->Color_of_stones = "blue";
      break;
   default:
      printf("I dont know what is the color");
      break;
   }
}

void Operation(HeapS* heap_, char operator)
{
   switch (operator)
   {
   case(74):
      heap_->Number_of_stones = heap_->Number_of_stones * heap_->Operation_with_stones_multy;
      if (heap_->Number_of_stones < 0)
         heap_->Number_of_stones = 0;
      break;
   case(75):
      heap_->Number_of_stones = heap_->Number_of_stones + heap_->Operation_with_stones_plus;
      if (heap_->Number_of_stones < 0)
         heap_->Number_of_stones = 0;
   default:
      printf("I dont know what is the operator");
   }
}

int Itisthatcolor(HeapS* heap_, char* color_)
{
   char* color = heap_->Color_of_stones;

   for (int i = 0; color[i] != '\0' || color_[i] != '\0'; i++)
      if (color[i] != color_[i])
         return 1;
   return 0;
}

HeapS* CompinateHeap(HeapS* heap1_, HeapS* heap2_)
{
   HeapS* heap3 = (HeapS*)malloc(sizeof(HeapS));
   if (heap3 == NULL)
      return NULL;

   heap3->Number_of_stones = heap1_->Number_of_stones + heap2_->Number_of_stones;
   heap3->Color_of_stones = CombitateColor(heap1_, heap2_);
   heap3->Operation_with_stones_plus = (heap1_->Operation_with_stones_plus + heap2_->Operation_with_stones_plus) / 2;
   heap3->Operation_with_stones_multy = (heap1_->Operation_with_stones_multy + heap2_->Operation_with_stones_multy) / 2;

   free(heap1_);
   free(heap2_);
   return heap3;
}

struct Data_Base
{
   HeapS** Heap;
   size_t size;
}; 

HeapS* Make_heap(unsigned int number_, int operation1_, int operation2_)
{
   HeapS* heap = (HeapS*)malloc(sizeof(HeapS));
   if (heap == NULL)
      return NULL;

   heap->Number_of_stones = number_;
   heap->Operation_with_stones_plus = operation1_;
   heap->Operation_with_stones_multy = operation2_;
   heap->Color_of_stones = NULL;

   return heap;
}

void Del_heap(HeapS* a)
{
   free(a->Number_of_stones);
   free(a->Operation_with_stones_plus);
   free(a->Operation_with_stones_multy);
   free(a->Color_of_stones);
   free(a);
}