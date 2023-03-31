
#include "myfunctions.h"

data student[10];


int main()
{

uint8 id,    ID;
uint8 year;
uint8 id_c,  ID_c;
uint8 no_entries;
uint8 grade;



//first get from user the option
  guides_on_screen();


while(1){

char option[1] ;
scanf("%s",&option);   // i used string instead of character to avoid when i write more than letter at same line while program is running

//-------------------------------------------------------------------------
if(strcmp(option,"c")==0)
{

    if(SDB_IsFull())
    {
        printf("data is full\n");
    }
    else
    {
        printf("data isn't full\n");
    }

}
//-------------------------------------------------------------------------
else if(strcmp(option,"n")==0)
{
    printf("number of entries = %d\n",SDB_GetUsedSize());

}
//-------------------------------------------------------------------------
else if(strcmp(option,"a")==0)
{
//*
    uint16_t x;
    printf("add your ID: ");
    scanf( "%d",&x);
    id=x;
    ID=id-1;
    if(id>0&&id<=10) // to check student id range
    {
        printf("add your year: ");
        scanf("%d",&year);

        printf("add your course ID: ");
        scanf("%d",&id_c);
        if(id_c>0 && id_c<=3) // to check course id range
        {
            ID_c=id_c-1;
            student[ID].course[ID_c].ID=id_c;

            printf("add your course grade: ");
            scanf("%d",&student[ID].course[ID_c].grade);


            if(SDB_AddEntry(id ,year ,&student[ID].course[ID_c].ID ,&student[ID].course[ID_c].grade))
            {
             printf("the new entry is successfully added\n");
            }
            else
            {
                printf("please check your course grade range in 0 to 100");
            }

        }
        else
        {
            printf("please check your course id range in 1 to 3");
        }



    }
    else
    {
        printf("please check your student id range in 1 to 10");
    }
//*/
/*
    id=5  , ID=id-1;
    year=2021  ;
    id_c=2  ,ID_c=id_c-1;
    grade= 90;

    student[ID].course[ID_c].ID=id_c;
    student[ID].course[ID_c].grade=grade;
    SDB_AddEntry(id ,year ,&student[ID].course[ID_c].ID ,&student[ID].course[ID_c].grade);
    printf("the new entry is successfully add\n");

*/
}
//-------------------------------------------------------------------------
else if(strcmp(option,"d")==0)
{

    printf("enter ID for deleting: ");
    scanf("%d",&id);
    SDB_DeleteEntry(id);

}
//-------------------------------------------------------------------------
else if(strcmp(option,"r")==0)
{

    printf("enter ID for student: ");
    scanf("%d",&id);
    ID=id-1;

    if (   SDB_ReadEntry(id,&student[ID].year,&student[ID].course,&student[ID].course)  )
    {
        printf("");
    }
    else
    {
        printf("not exist \n");
    }

}
//-------------------------------------------------------------------------
else if(strcmp(option,"g")==0)
{
    no_entries=SDB_GetUsedSize();
    uint8*list;
    SDB_GetIDList(&no_entries ,list );

}
//-------------------------------------------------------------------------
else if(strcmp(option,"l")==0)
{


    printf("enter ID for student: ");
    scanf("%d",&id);

    if (SDB_IsIdExist(id))
    {
        printf("exist\n");
    }
    else
    {
        printf("not exist \n");
    }

}

//-------------------------------------------------------------------------
else if(strcmp(option,"-")==0)
{


    system("cls");
    guides_on_screen();


}
//-------------------------------------------------------------------------

else
{
    printf("\nplease choose one of letters do you have on screen\n");
}

//-------------------------------------------------------------------------

}//bracket of while


return 0;
}






