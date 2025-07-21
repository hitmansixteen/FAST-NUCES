#include <iostream>
#include <time.h>
#include<cstdlib>
using namespace std;

class IntervalHeap
{
    int hsize;
    int maxsize;
    int** h;
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }
    bool exist(int i) { 
        if (hsize % 2 == 0)
            return i < size(); 
        return i <= size();
    }
    int size() { return hsize / 2;}
    void heapup_min(int curr)
    {
        if (curr == 0)
            return;
        if (h[0][curr] < h[0][parent(curr)])
            swap(h[0][curr], h[0][parent(curr)]);
        heapup_min(parent(curr));
    }
    void heapup_max(int curr)
    {
        if (curr == 0)
            return;
        if (h[1][curr] > h[1][parent(curr)])
            swap(h[1][curr], h[1][parent(curr)]);
        heapup_max(parent(curr));
    }
    void heapdown_min(int curr)
    {
        if (!exist(curr))
            return;
        int min;
        if (exist(right(curr)))
            min = h[0][left(curr)] < h[0][right(curr)] ? left(curr) : right(curr);
        else if (exist(left(curr)))
            min = left(curr);
        else
            return;
        if (h[0][curr] > h[0][min])
            swap(h[0][curr], h[0][min]);
        heapdown_min(min);
    }
    void heapdown_max(int curr)
    {
        if (!exist(curr))
            return;
        int max;
        if (exist(right(curr)))
            max = h[1][left(curr)] > h[1][right(curr)] ? left(curr) : right(curr);
        else if (exist(left(curr)))
            max = left(curr);
        else
            return;
        if (h[1][curr] < h[1][max])
            swap(h[1][curr], h[1][max]);
        heapdown_max(max);
    }

public:
    IntervalHeap(int s = 100)
    {
        maxsize = s;
        hsize = 0;
        h = new int* [2];
        h[0] = new int[maxsize];
        h[1] = new int[maxsize];
    }
    bool isEmpty() { return hsize == 0; }
    bool isFull1() { return size() == maxsize; }
    void insert(int value)
    {
        if (hsize % 2 == 0)
        {
            h[0][size()] = value;
            h[1][size()] = value;
            heapup_max(size());
            heapup_min(size());
            if (h[0][size()] != value)
                h[1][size()] = h[0][size()];
            else if (h[1][size()] != value)
                h[0][size()] = h[1][size()];
        }
        else
        {
            if (h[0][size()] > value)
                h[0][size()] = value;
            else
                h[1][size()] = value;
            heapup_min(size());
            heapup_max(size());
        }
        hsize++;
        cout << "Inserted!\n";
        correct();
    }
    void DeleteMin()
    {
        if (isEmpty())
            return;
        hsize--;
        h[0][0] = h[0][size()];
        heapdown_min(0);
        if (hsize % 2 != 0)
            h[0][size()] = h[1][size()];
    }
    void DeleteMax()
    {
        if (isEmpty())
            return;
        hsize--;
        h[1][0] = h[1][size()];
        heapdown_max(0);
    }
    void Delete()
    {
        if (isEmpty())
        {
            cout << "Empty!\n";
            return;
        }
        DeleteMin();
        DeleteMax();
        correct();
        cout << "Root Deleted!\n";
    }
    void updateMin(int x)
    {
        h[0][0] = x;
        heapdown_min(0);
        cout << "Updated!\n";
    }
    void updateMax(int x)
    {
        h[1][0] = x;
        heapdown_max(0);
        cout << "Updated!\n";
    }
    void correct()
    {
        for (int i = 0; i < size() + (hsize % 2); i++)
            if (h[0][i] > h[1][i])
                swap(h[0][i], h[1][i]);
        heapdown_min(0);
        heapdown_max(0);
    }
    void update()
    {
        if (isEmpty())
        {
            cout << "Empty!\n";
            return;
        }
        int x;
        cout << "Update Minheap: ";
        cin >> x;
        updateMin(x);
        if (hsize > 1)
        {
            cout << "Update Maxheap: ";
            cin >> x;
            updateMax(x);
        }
        correct();
    }
    void print()
    {
        if (isEmpty())
        {
            cout << "=========================================\n";
            cout << "Empty\n";
            cout << "=========================================\n";
            return;
        }
        cout << "=========================================\n";
        for (int i = 0; i < size() + (hsize % 2); i++)
            cout << h[0][i] << "\t";
        cout << endl;
        for (int i = 0; i < size(); i++)
            cout << h[1][i] << "\t";
        cout << endl;
        cout << "=========================================\n";
    }
};

int main()
{
    srand(time(0));
    system("cls");
    IntervalHeap heap;
    int choice = -1;
    while (choice != 0)
    {
        cout << "=========================================\n";
        cout << "1.Insert\n";
        cout << "2.Update\n";
        cout << "3.Delete\n";
        cout << "4. Random Insert\n";
        cout << "0.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "=========================================\n";
        switch (choice)
        {
        case 0:
            break;
        case 1:
            int count;
            cout << "Enter Number of Inputs\n";
            cin >> count;
            for (int i = 0; i < count; i++)
            {
                int x;
                cout << "Input: ";
                cin >> x;
                heap.insert(x);
            }
            heap.print();
            break;
        case 2:
            heap.update();
            heap.print();
            break;
        case 3:
            heap.Delete();
            heap.print();
            break;
        case 4:
            int count1;
            cout << "Enter Number of Inputs\n";
            cin >> count1;
            int x;
            cout << "Enter max Number: ";
            cin >> x;
            for (int i = 0; i < count1; i++)
            {
                heap.insert(rand()%x);
            }
            heap.print();
            break;
        default:
            break;
        }
    }
    return 0;
}