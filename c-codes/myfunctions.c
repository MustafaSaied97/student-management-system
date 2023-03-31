
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

#include <stdint.h>
#include <inttypes.h>

typedef int uint8;


//__________________________________________________________________________________________________________________________________________________________________________________________
//                                                        Data base

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
data student[10];


//note that the range of student id is from 0 to 9
//__________________________________________________________________________________________________________________________________________________________________________________________
//                                              number of entries in the database

uint8 SDB_GetUsedSize(void)
{
    uint8 no_entries=0;  //number of entries
    uint8 i;



    for (i=0; i<10 ;i++)
    {

        if (student[i].ID != 0 )
        {
          //printf("full\n");
          no_entries++;

        }
    }

return no_entries;
}

//__________________________________________________________________________________________________________________________________________________________________________________________
//                                              check if the data is full

bool SDB_IsFull(void)
{

    if(SDB_GetUsedSize()==10)
    {
        //printf("full\n");
        return true;
    }
    else
    {
        //printf("not full\n");
        return false;
    }

}


//__________________________________________________________________________________________________________________________________________________________________________________________
//                                              check if the provided student ID exists

bool SDB_IsIdExist(uint8 id )
{

    uint8 i=0;
    for (i=0; i<10;i++)
    {
        if (student[i].ID == id)
        {
            return 1;
        }



    }


    return 0;

}

//__________________________________________________________________________________________________________________________________________________________________________________________
//                                                   add new entry to the database

bool SDB_AddEntry(uint8 id ,uint8 year ,uint8*subjects ,uint8*grades)
{


    uint8 ID=id-1;


    //check if grade at range 0 to 100
    if ( (*grades>=0) && (*grades<=100) )
    {
       // printf("ok\n");

        //then add the rest of data
        student[ID].ID= id;
        student[ID].year= year;
        //then return 1 to tell the caller that the new entry is successfully added
        return 1;

    }
    else
    {
        //printf("not ok\n");
        return 0;
    }

}

//__________________________________________________________________________________________________________________________________________________________________________________________
//                                                   delete the entry with the given ID

void SDB_DeleteEntry(uint8 id)
{
    uint8 ID=id-1;
    uint8 i;

    if(SDB_IsIdExist(id) )
    {
        student[ID].ID = 0;
        student[ID].year = 0;
        for (i=0;i<3;i++)
        {
            student[ID].course[i].ID = 0;
            student[ID].course[i].grade = 0;
        }
        printf("Deleted\n");
    }
    else
    {
        printf("the ID entry  doesn't exist for deleting \n");
    }





}
//__________________________________________________________________________________________________________________________________________________________________________________________
//                                              read an entry matching the provided ID


bool SDB_ReadEntry(uint8 id,uint8*year,uint8*subjects,uint8*grades)
{
    uint8 ID=id-1;
    if (SDB_IsIdExist(id))
    {
        //-----print student----------
        printf("student ID = %d\n",student[ID].ID);
        printf("student Year = %d\n",*year);

        //-----print course in student   with pointer----------



        uint8 i;
        for (i=0; i<3;i++)
        {

            printf("---course %d----\n  ID = %d ",i+1,*subjects );

            grades=subjects+1;
            printf(" , Grade = %d\n" , *grades);

            subjects+=2;//to point to ID in the next array of course


        }


        //return 1 if   the entry exist
        return 1;
    }
    else
    {
        //other wise return 0
        return 0;
    }
}

//__________________________________________________________________________________________________________________________________________________________________________________________
//                                                   get the list of IDs of the students

void SDB_GetIDList(uint8*count ,uint8*list )
{
    uint8 no_entries=SDB_GetUsedSize();
    //to make count points to number of entries
    count=&no_entries;
    uint8 check=0;

    //to make list points to each entries that was filled with ID
    uint8 i;
    for (i=0;i<10;i++)
    {
        if (student[i].ID != 0)
        {
            list=&student[i].ID;
            printf("the list of IDs of the students :\n student_ID = %d\n",*list );

            ++list;
            check++;
        }
    }


    if (check == 0)
    {
        printf("not found the list of IDs of the students \n please add the entry first");
    }


}


//__________________________________________________________________________________________________________________________________________________________________________________________

void guides_on_screen(void)
{
   printf("chose your option \n\n");
   printf("(c) check if the data is full \n");
   printf("(n) number of entries in the database\n");
   printf("(a) add new entry to the database \n");
   printf("(d) delete the entry with the given ID \n");
   printf("(r) read an entry matching the provided ID  \n");
   printf("(g) get the list of IDs of the students \n");
   printf("(l) check if the provided student ID exists \n");
   printf("(-) for clean screen \n");

   printf("                                                         note : *student ID range from 1 to 10*\n                                                                 *course ID range from 1 to 3*\n                                                                 *grade range from 0 to 100*\n");


};
//__________________________________________________________________________________________________________________________________________________________________________________________
