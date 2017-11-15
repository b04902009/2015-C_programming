#include <stdio.h>
#include <string.h>
enum Type {NOVEL, COMICS, MANUAL, TEXTBOOK};
struct Book {
    char title[128];
    enum Type type;
    char ISBN[128];
    char authors[128];
    unsigned int importance;
};
struct Date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
};
unsigned int library_fine(struct Book book, struct Date borrow, struct Date back)
{
    int Day[14] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int value = -1,day = back.day-borrow.day+1,borrow_m = borrow.month,back_m = back.month;
    if(borrow.year == back.year)
        for(int i = borrow_m;i < back_m;i ++)    day += Day[i];
    else{
        for(int i = borrow_m;i <= 12;i ++)    day += Day[i];
        for(int i = 1;i < back_m;i ++)    day += Day[i];
        if(back.year - borrow.year > 1)
            day += (back.year-borrow.year-1) * 365;
    }
    for(int i = borrow.year+1;i < back.year;i ++)
        if((i % 100 !=0 && i % 4 == 0) || i % 400 == 0)    day ++;
    if(borrow_m <= 2 && ((borrow.year % 100 !=0 && borrow.year % 4 == 0) || borrow.year % 400 == 0))    day ++;
    else if(back_m > 2 && ((back.year % 100 !=0 && back.year % 4 == 0) || back.year % 400 == 0))    day ++;
    switch(book.type){
        case 0: day -= 90; break;
        case 1: day -= 10; break;
        case 2: day -= 100; break;
        case 3: day -= 5; break;
    }
    if(day < 0)    day = 0;
    for(int i = 0;i < 32;i ++)
        if((book.importance>>i) & 1)    value = i - value;
    return value * day;
}
 
int main(){
    struct Book book = {
        "Neon Genesis Evangelion",
        COMICS,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        17
    };
    struct Date date_borrowed, date_returned;
    date_borrowed.year  = 1800;
    date_borrowed.month = 1;
    date_borrowed.day   = 1;
    date_returned.year  = 1900;
    date_returned.month = 1;
    date_returned.day   = 1;
    printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
    return 0;
}