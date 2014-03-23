#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

struct competition
{
    int number;
    char name[20];
    int result = -1;
};

int countItems(competition *resultList);
void openFBinary(competition *resultlist);
void saveFBinary(competition *resultlist);
void showF(competition *resultList);
void openF(competition *resultList);
void saveF(competition *resultList);
void addItem(competition *resultList);
void deleteItem(competition *resultList);
int numberCompare(competition list1, competition list2);
int nameCompare(competition list1, competition list2);
int resultCompare(competition list1, competition list2);
void mergeSortAscend(competition *ar,int first,int last, int (*fptr)(competition,competition));
void mergeSortDescend(competition *ar,int first,int last, int (*fptr)(competition,competition));
void mySort(competition *ar,int first,int last, int (*fptr)(competition,competition),bool direction);
#endif
