#include <stdio.h>
#include <string.h> 

#define MAX_STUDENTS 200
#define MAX_NAME 100

typedef struct 
{
    int month;
    int date;
} BirthdayType;

typedef struct
{
    char name[MAX_NAME];
    BirthdayType birthday;
} StudentType;

StudentType students[MAX_STUDENTS];

int main()
{
    strcpy(students[0].name, "HongGilDong"); /*홍길동을 students[0].name에 복사*/
    students[0].birthday.month = 10;
    students[0].birthday.date = 23;
    return 0;
}