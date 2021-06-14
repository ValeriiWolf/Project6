
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <clocale>
#include <string>

using namespace std;

string StringInit(string name);
void EnterArray1(int n);
void InitArray(int* arr, size_t n);
void PrintArray1(int *arr, size_t n);
void EnterArray2(size_t m, size_t k);
void PrintTwoMerArray(size_t m, size_t k, int** arr);
void Stringname(string name);
void StringCopyTwo(string name1, string name2, string name3);

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "WorkItem1"<< endl; 
    int n;  // Количество элементов
    cout << "Enter size(integer) of your array: ";
    cin >> n;
    EnterArray1(n);

    cout << "WorkItem2" << endl;
    const size_t goriz = 4; // Количество элементов m x n
    const size_t vert = 4;
    EnterArray2(goriz, vert);

    cout << "WorkItem3" << std::endl;    
    string name1, name2; 
    cout << "Enter the file1 name ";
    cin >> name1;
    Stringname(name1);
    cout << "Enter the file2 name ";
    cin >> name2;
    Stringname(name2);
    
    cout << "WorkItem4" << std::endl;
    cout << "Enter the file3 name ";
    string name3;
    cin >> name3;
    StringCopyTwo(name1, name2, name3);

    cout << "WorkItem5" << std::endl;
    cout << "Enter the serchfile name ";
    string name4;
    cin >> name4;
    cout << "Enter a word string ";
    string keystring;
    cin >> keystring;


    return 0;
}


void EnterArray1(int n)
{
    int *ptrArr;
    if (n > 0)
    {
        ptrArr = new(nothrow) int[n];
        if (ptrArr != nullptr)
        {
            InitArray(ptrArr,n);
            PrintArray1(ptrArr,n);
            delete[]ptrArr;
            ptrArr = nullptr;
        }
        else
        {
            cout << "Error! Can not allocate memory!";
        }
    }
}



void InitArray(int  *arr, size_t n)
{
    const unsigned int Two = 2;
    int nach= 1;

    for (size_t i = 0; i < n; i++)
    {
        if (i == 0)
        {    
            nach;
            arr[i] = { nach };
        }
        else
        {
            nach = nach * Two;
            arr[i] = { nach };
            
        }
    }
}
void PrintArray1(int *arr, size_t n)
{
    
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
   }
    cout << endl;
}


void EnterArray2(size_t m, size_t k)
{
    int** ptrArr;  
    ptrArr = new int* [m]; 
    for (size_t i = 0; i < m; i++)
    {
        ptrArr[i] = new int[k]; 
    }
    
    PrintTwoMerArray( m,  k, ptrArr);
        for (size_t i = 0; i < m; i++) 
        {
        delete[]ptrArr[i];
        }
    delete[]ptrArr;
    ptrArr = nullptr;
}

void PrintTwoMerArray(size_t m, size_t k, int** arr)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < k; j++)
        {   
            arr[i][j] = rand() % 100;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
string StringInit(string name)
{
    setlocale(LC_ALL, "Russian");
    string stringname = name +"Для генерации файла напишем вспомогательную программу, заполняющую файл";
    return stringname;
}


void Stringname(string name)
{
    setlocale(LC_ALL, "Russian");
    
    ofstream fout(name+".txt");
    fout << name << endl;
    
    string stringname = StringInit(name);
    for (const auto& a : stringname)
    {
        fout << a;
    }
    fout.close();
}

void StringCopyTwo(string name1, string name2, string name3)
{
    ofstream fout(name3+".txt");
    ifstream fin1(name1+".txt"); 
    string buf;
    if (fin1.is_open())
    {
        while (!fin1.eof());
        getline(fin1,buf);
        fin1.close();
    }
    else
    {
        cout << "Error. Can not open file1.";  // Сообщение об ошибке
    }
    fout << buf << endl;
    ifstream fin2(name2 + ".txt");
    if (fin2.is_open())
    {
        while (!fin2.eof());
        getline(fin2, buf);
        fin2.close();
    }
    else
    {
        cout << "Error. Can not open file2.";  // Сообщение об ошибке
    }
    fout << buf;
    fout.close();
}
