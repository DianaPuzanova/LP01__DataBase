#include <iostream>
#include <fstream>
#include <cstring>
#include "myfunctions.h"

using namespace std;

int countItems(competition *resultList)
{
    int i=0;
    while(resultList[i].result!=-1)
    {
        i++;
    }
    return i;
}

void showF(competition *resultList)
{
    for(int i=0; i<countItems(resultList); i++)
    {
        cout<<resultList[i].number<<" "<<resultList[i].name<<" "<<resultList[i].result<<"\n";
    }
}

void saveFBinary(competition *resultList)
{
    ofstream stream("db.txt", ios::binary);
    stream.write((char *) resultList, countItems(resultList)*sizeof(competition));
    stream.close();
}

void openFBinary(competition *resultList)
{
    ifstream stream("db.txt", ios::binary);
    stream.read((char *) resultList, 125*sizeof(competition));
    stream.close();
}

void openF(competition *resultList)
{
    int i=0;
    for (int j=0; j<125; j++)
    {
        resultList[j].result=-1;
    }
    ifstream stream("result.txt");
    while(!stream.eof())
    {
        stream>>resultList[i].number;
        stream>>resultList[i].name;
        stream>>resultList[i].result;
        i++;
    }
    stream.close();
}

void saveF(competition *resultList)
{
    ofstream stream("result.txt", ios::trunc);
    for (int i=0; i<countItems(resultList); i++)
    {
        stream<<resultList[i].number<<" "<<resultList[i].name<<" "<<resultList[i].result<<"\n";
    }
    stream.close();
}

void addItem(competition *resultList)
{
    int kol=countItems(resultList);
    resultList[kol-1].number=resultList[kol-2].number+1;
    cout<<"\nEnter name: ";
    cin>>resultList[kol-1].name;
    cout<<"\nEnter result: ";
    cin>>resultList[kol-1].result;
}

void deleteItem(competition *resultList)
{
    int n;
    cout<<"Enter a number of sportsman ";
    cin>>n;
    int k;
    int kol=countItems(resultList);
    for(int i=0; i<kol; i++)
    {
        if(resultList[i].number==n)
        k=i;
    }
    for(int j=k; j<kol; j++)
    {
        resultList[j]=resultList[j+1];
    }
    resultList[kol-1].result=-1;

}

int numberCompare(competition list1, competition list2)
{
    return list1.number-list2.number;
}

int nameCompare(competition list1, competition list2)
{
    return strcmp(list1.name,list2.name);
}

int resultCompare(competition list1, competition list2)
{
    return list1.result-list2.result;
}

void mergeSortAscend(competition *ar,int first,int last, int (*fptr)(competition,competition))
{
    competition *newAr;
    newAr=new competition[125];
    if(first<last)
    {
        mergeSortAscend(ar,first,(last+first)/2,(*fptr));
        mergeSortAscend(ar,(last+first)/2+1,last,(*fptr));
        int i=first,j=first,k=(last+first)/2+1;
        while((j<=(last+first)/2)&&(k<=last))
        {
            if((*fptr)(ar[j],ar[k])<0)
            {
                newAr[i]=ar[j];
                ++j;
            }
            else
            {
                newAr[i]=ar[k];
                ++k;
            }
            ++i;
        }

        if(j<=(last+first)/2)
        {
            for(int c=j; c<=(last+first)/2; c++)
            {
                newAr[i]=ar[c];
                ++i;
            }

        }
        else
        {
            for(int b=k; b<last+1; b++)
            {
                newAr[i]=ar[b];
                ++i;
            }
        }

        for(int c=first; c<=last; c++)
        {
            ar[c]=newAr[c];
        }

        delete[] newAr;
        newAr=0;
    }
}
void mergeSortDescend(competition *ar,int first,int last, int (*fptr)(competition,competition))
{
    competition *newAr;
    newAr=new competition[125];
    if(first<last)
    {
        mergeSortDescend(ar,first,(last+first)/2,(*fptr));
        mergeSortDescend(ar,(last+first)/2+1,last,(*fptr));
        int i=first,j=first,k=(last+first)/2+1;
        while((j<=(last+first)/2)&&(k<=last))
        {
            if((*fptr)(ar[j],ar[k])>0)
            {
                newAr[i]=ar[j];
                ++j;
            }
            else
            {
                newAr[i]=ar[k];
                ++k;
            }
            ++i;
        }

        if(j<=(last+first)/2)
        {
            for(int c=j; c<=(last+first)/2; c++)
            {
                newAr[i]=ar[c];
                ++i;
            }

        }
        else
        {
            for(int b=k; b<last+1; b++)
            {
                newAr[i]=ar[b];
                ++i;
            }
        }

        for(int c=first; c<=last; c++)
        {
            ar[c]=newAr[c];
        }

        delete[] newAr;
        newAr=0;
    }
}
void mySort(competition *ar,int first,int last, int (*fptr)(competition,competition),bool direction)
{
    if(direction)
    {
        mergeSortAscend(ar,first,last,(*fptr));
    }
    else
    {
        mergeSortDescend(ar,first,last,(*fptr));
    }
}
