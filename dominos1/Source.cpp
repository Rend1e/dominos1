#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream f1;
    f1.open("input.txt"); //������� ����
    int soed = 0; //����� ���������� ��� ��� ���

    if (!f1.is_open())  //�������� �������� �����
    {
        cout << "input not founded" << endl; //���� �� ����� ������
    }
    else
    {
        string k1; //������ �����
        getline(f1, k1); //��������� ������ ������
        int k = atoi(k1.c_str()); //���������� ������ ��� ��� ���
        string* xy = new string[k];

        for (int i = 0; i < k; i++)
        {
            getline(f1, xy[i]); //��������� ������ 
        }
        string* x1 = new string[k];  //������� ������� ������ ��� ��� ��� �������
        string* y1 = new string[k];

        int* x = new int[k]; // ����� �������� � �������,  ��������� � �������, � �� �����, ���� ���� �������
        int* y = new int[k];

        for (int i = 0; i < k; i++) //����� ������ �� � � �
        {
            int pos = 0;
            pos = xy[i].find(" ");

            x1[i] = xy[i].substr(0, pos);
            y1[i] = xy[i].substr(pos, xy[i].length());
        }
        for (int i = 0; i < k; i++) //��������� �� ������� � ��� 
        {
            x[i] = atoi(x1[i].c_str());
            y[i] = atoi(y1[i].c_str());
        }

        delete[] x1; //������ �� ����������
        delete[] y1;

        /*for (int i = 0; i < k; i++)  //����� ������ ������� �� ��������� (������ �������) ----------------------------------------
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