#include <iostream>
#include <iomanip>
#include <cmath>
#define e 0,3
using namespace std;
class Matr
{
private:
    int size;
    double **mas;
    double *mas1;
public:
    Matr()
    {
        size = 0;
        mas = NULL;
        mas1 = NULL;
    }
    Matr(int l)
    {
        size = l;
        mas = new double*[l];
        for (int i = 0; i < l; i++)
            mas[i] = new double[l];
        mas1 = new double[l];
    }
    void Add()
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                cin >> mas[i][j];
        for (int i = 0; i < size; i++)
        {
            cin >> mas1[i];
        }
 
    }
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << setw(4) << mas[i][j] << " ";
            }
            cout << " " << mas1[i] << endl;
        }
    }
    void Preob()
    {
        double temp = 0;
        for (int k = 0; k < size; k++)
        {
            for (int i = 0; i < size; i++)
            {
                temp = mas[i][i]*(-1);
                mas1[i] /= temp;
                for (int j = 0; j <= size; j++)
                {
                    mas[i][j] /= temp;
                }
            }
        }
            for (int i = 0; i < size; i++)
            {
                mas1[i] *= -1;
                for (int j = 0; j < size; j++)
                    mas[i][i] = 0;
            }
    }
    double Norma()
    {
        double sum = 0, max = 0;
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    sum += fabs(mas[i][j]);
                    if (sum > max) max = sum;
                }
                sum = 0;
            }
            return max;
    }
    double Pogr()
    {
        double eps = 0;
        double norm = Norma();
        if (norm >= 1) cout << "Метод может оказаться несходимым" << endl;
        else eps = ((1 - norm) / norm)*e;
        return eps;
    }
    void Itera()
    {
        double *x = new double[size];
        double *x0 = new double[size];
        double *E = new double[size];
        double max = 0;
        for (int i = 0; i < size; i++)
            x0[i] = mas1[i];
        do
        {
            for (int i = 0; i < size; i++)
            {
                x[i] = 0;
                for (int j = 0; j < size; j++)
                {
                    x[i] += mas[j][i] * mas1[j];
                }
                x[i] += mas1[i];
                E[i] = fabs(x[i] - x0[i]);
            }
            max = 0;
            for (int i = 0; i < size; i++)
            {
                if (max <= E[i]) max = E[i]; x0[i] = x[i];
            }
        } while (max < Pogr());
        for (int i = 0; i < size; i++)
            cout << "x" << i + 1 << "=" << x[i] << " " << endl;
        delete[] x;
        delete[] x0;
        delete[] E;
    }
};
int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите количество уравнений:   ";
    cin >> n;
    Matr a(n);
    cout << "Введите матрицу коэффициентов, потом столбец свободных членов:" << endl;
    a.Add();
    cout << endl << "Расширенная матрица:" << endl;
    a.Print();
    a.Preob();
    cout << endl << "Преображенная матрица" << endl;
    a.Print();
    cout << endl;
    a.Itera();
    cout << endl;
    return 0;
}