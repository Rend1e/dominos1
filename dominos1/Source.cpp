#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream f1;
    f1.open("input.txt"); //находим файл
    int soed = 0; //число соединений или что там

    if (!f1.is_open())  //проверка открытия файла
    {
        cout << "input not founded" << endl; //если не нашел ошибка
    }
    else
    {
        string k1; //первое число
        getline(f1, k1); //считываем первую строку
        int k = atoi(k1.c_str()); //количество домино или что там
        string* xy = new string[k];

        for (int i = 0; i < k; i++)
        {
            getline(f1, xy[i]); //считываем строку 
        }
        string* x1 = new string[k];  //создаем сначала стринг так как так удобнее
        string* y1 = new string[k];

        int* x = new int[k]; // чтобы работать с числами,  переведем с стринга, а не сразу, чтоб было удобнее
        int* y = new int[k];

        for (int i = 0; i < k; i++) //делим строку на х и у
        {
            int pos = 0;
            pos = xy[i].find(" ");

            x1[i] = xy[i].substr(0, pos);
            y1[i] = xy[i].substr(pos, xy[i].length());
        }
        for (int i = 0; i < k; i++) //переводим из стринга в инт 
        {
            x[i] = atoi(x1[i].c_str());
            y[i] = atoi(y1[i].c_str());
        }

        delete[] x1; //больше не используем
        delete[] y1;

        /*for (int i = 0; i < k; i++)  //вывод домино которую мы посчитали (можешь удалить) ----------------------------------------
        {
            cout << x[i] << " " << y[i] << endl;
        }*/

        int a = 0;
        for (int i = 0; i < k - 1; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                if ((x[i] == x[j]) || (x[i] == y[j]) || (y[i] == x[j]) || (y[i] == y[j]))
                {
                    a++;
                }
            }
        }
    }
}
