#include "myfunctions.h"
#include <iostream>

using namespace std;

void menu(competition *resultList)
{
    int choice;
    do
    {
        cout<<" 1 - open file\n";
        cout<<" 2 - save file\n";
        cout<<" 3 - show database\n";
        cout<<" 4 - sort database by number ascending\n";
        cout<<" 5 - sort database by number descending\n";
        cout<<" 6 - sort database by name ascending\n";
        cout<<" 7 - sort database by name descending\n";
        cout<<" 8 - sort database by result ascending\n";
        cout<<" 9 - sort database by result descending\n";
        cout<<"10 - add item\n";
        cout<<"11 - delete item\n";
        cout<<"12 - exit\n";
        cout<<endl;
        cin>>choice;

        switch(choice)
        {
        case 1:
            openF(resultList);
            cout<<"\nFile is opened\n";
            break;
        case 2:
            saveF(resultList);
            cout<<"\nFile is saved\n";
            break;
        case 3:
            showF(resultList);
            cout<<"\n";
            break;
        case 4:
            mySort(resultList,0,countItems(resultList)-1,numberCompare,true);
            cout<<"\nDatabase is sorted\n";
            break;
        case 5:
            mySort(resultList,0,countItems(resultList)-1,numberCompare,false);
            cout<<"\nDatabase is sorted\n";
            break;
        case 6:
            mySort(resultList,0,countItems(resultList)-1,nameCompare,true);
            cout<<"\nDatabase is sorted\n";
            break;
        case 7:
            mySort(resultList,0,countItems(resultList)-1,nameCompare,false);
            cout<<"\nDatabase is sorted\n";
            break;
        case 8:
            mySort(resultList,0,countItems(resultList)-1,resultCompare,true);
            cout<<"\nDatabase is sorted\n";
            break;
        case 9:
            mySort(resultList,0,countItems(resultList)-1,resultCompare,false);
            cout<<"\nDatabase is sorted\n";
            break;
        case 10:
            addItem(resultList);
            cout<<"\nItem is added\n";
            break;
        case 11:
            deleteItem(resultList);
            cout<<"\nItem is deleted\n";
            break;
        case 12:
            cout<<"Bye!\n";
            break;
        default:
            cout<<"\nEnter number between 1 and 12!\n";
            break;
        }
    }
    while(choice!=12);
}

int main()
{
    competition *resultList;
    resultList=new competition[125];
    openFBinary(resultList);
    menu(resultList);
    saveFBinary(resultList);
    delete[] resultList;
    return 0;
}
