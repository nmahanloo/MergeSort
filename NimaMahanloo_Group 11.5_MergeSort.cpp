// Nima Mahanlolo
// Merge sort
// CISP 430
#include <iostream>
#include <random>
#include <ctime>
using namespace std;
// A structure as a node
struct node
{
    int num;
    node* next = nullptr;
    node* prev = nullptr;
};
// Make linked list
void listMake(node* (&last), int listSize)
{
    int counter;
    for (counter = 1; counter < listSize; counter++)
    {
        last->next = new node;
        last->next->prev = last;
        last = last->next;
    }
}
// Initialize Linked list
void listInitial(node* (&first))
{
    node* curr = first;
    while (curr != nullptr)
    {
        curr->num = rand() %201 - 100;
        curr = curr->next;
    }
}

void displayList(node* first)
{
    while (first != nullptr)
    {
        cout << first->num << " ";
        first = first->next;
    }
    cout << endl;
}
// Merge Sort
void mergeSort(node*(&first), int &groupPiont, int listSize, bool &sortDone)
{
    node* curr = first;
    node* compare;
    int listCounter, compareCounter, groupCounter, counter, temp;
    if (groupPiont == listSize)
    {
        sortDone = true;
    }
    for (listCounter = 0; listCounter < listSize; listCounter += groupPiont)
    {
        for (groupCounter = listCounter; (groupCounter < (listCounter + groupPiont)) && (groupCounter < listSize) && (curr != nullptr); groupCounter++)
        {
            compare = curr->next;
            for (counter = 1; (groupCounter < (listCounter+groupPiont-counter)) && (compare != nullptr); counter++)
            {
                if (curr->num > compare->num)
                {
                    temp = curr->num;
                    curr->num = compare->num;
                    compare->num = temp;
                }
                compare = compare->next;
                displayList(first);
            }
            curr = curr->next;
        }
    }
    if (sortDone == false)
    {
        groupPiont *= 2;
        if ((groupPiont > listSize) && (listSize > (groupPiont/2)))
        {
            groupPiont = listSize;
        }
        mergeSort(first, groupPiont, listSize, sortDone);
    }
}

int main()
{
    cout << "<Merge sort>" << endl;
    int listSize = 10;
    int groupPoint = 2;
    bool sortDone = false;
    node* linkedList = new node;
    node* first = linkedList;
    node* last = first;
    listMake(last, listSize);
    srand(time(0));
    listInitial(first);
    cout << endl << "Original List :" << endl << endl;
    displayList(first);
    cout << endl << "Sorting Process :" << endl << endl;
    mergeSort(first, groupPoint, listSize, sortDone);
    cout << endl << "Sorted List :" << endl << endl;
    displayList(first);
    return 0;
}
