#ifndef MYFUCNTION_H

#define MYFUCNTION_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

#include <stdint.h>
#include <inttypes.h>


typedef int uint8;

typedef struct student
{
    uint8 ID;
    uint8 year;

    struct Course
    {
        uint8 ID;
        uint8 grade;
    }course[3];

}data;








uint8 SDB_GetUsedSize(void);

bool SDB_IsFull(void);

bool SDB_IsIdExist(uint8 id );

bool SDB_AddEntry(uint8 id ,uint8 year ,uint8*subjects ,uint8*grades);

void SDB_DeleteEntry(uint8 id);

bool SDB_ReadEntry(uint8 id,uint8*year,uint8*subjects,uint8*grades);

void SDB_GetIDList(uint8*count ,uint8*list );

void guides_on_screen(void);





#endif  MYFUCNTION_H
