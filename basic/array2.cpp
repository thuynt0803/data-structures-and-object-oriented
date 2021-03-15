/*
    Yêu cầu: 
    1. Nhập vào 3 ma trận (nm, nm, mp)
    2. In tổng 2 ma trận? 
    3. In tích 2 ma trận (ma trận tổng * ma trận thứ 3)
    4. Kiểm tra xem ma trận tổng có phải là ma trận đơn vị không?
    5. Kiểm tra xem ma trận tổng có phải là ma trận đối xứng không?
*/

#include <iostream>
#include <stdio.h>
using namespace std;

#define N 50
#define M 50
#define P 50
float matrixA[N][M], matrixB[N][M], matrixSum[N][M], matrixC[M][P], matrixMulti[N][P];

void inputMatrix(int n, int m, int p)
{

    cout << "Nhap cac phan tu ma tran A:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // printf("A[%d][%d] = ", i, j);
            cout << "A[" << i << "][" << j << "] = ";
            cin >> matrixA[i][j];
        }
    }

    cout << "\nNhap cac phan tu ma tran B:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("B[%d][%d] = ", i, j);
            cin >> matrixB[i][j];
        }
    }

    cout << "\nNhap cac phan tu ma tran C:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cout << "C[" << i << "][" << j << "] = ";
            cin >> matrixC[i][j];
        }
    }
}

void sumMatrix(int n, int m, int p) // matrixSum[][] = A[][] + B[][]
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    cout << "\nMa tran tong: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "\t" << matrixSum[i][j] << "\t";
        }
        cout << endl;
    }
}

void multiMatrix(int n, int m, int p) // matrixMulti[][] = matrixSum[][] * C[][]
{
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < p; k++)
        {
            for (int j = 0; j < m; j++)
            {
                matrixMulti[i][k] = matrixSum[i][j] * matrixC[j][k];
            }
        }
    }

    cout << "\nMa tran tich: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cout << "\t" << matrixMulti[i][j] << "\t";
        }
        cout << endl;
    }
}

int unitMatrix(int n, int m, int p) // Kiem tra ma tran don vi
{
    for (int i = 0; i < n; i++)
    {
        if (matrixSum[i][i] != 1)
        {
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((matrixSum[i][j] != 0) || (matrixSum[j][i] != 0))
            {
                return 0;
            }
        }
    }
    return 1;
}

int symmetricMatrix(int n, int m, int p) // Kiem tra ma tran doi xung
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrixSum[i][j] != matrixSum[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n, m, p;
    // Kiem tra neu so dong hoac so cot vuot qua 50
    do
    {
        cout << "Nhap so phan tu N: n = ";
        cin >> n;
        cout << "Nhap so phan tu M: m = ";
        cin >> m;
        cout << "Nhap so phan tu P: p = ";
        cin >> p;

        if (n >= N || m >= M || p >= P)
        {
            cout << "==> 1 trong 3 gia tri duoc nhap qua gioi han (max=50). Vui long nhap lai!" << endl
                 << endl;
        }
        cout << endl;
    } while (n >= N || m >= M || p >= P);

    inputMatrix(n, m, p);
    sumMatrix(n, m, p);
    multiMatrix(n, m, p);

    // Kiem tra ma tran don vi
    if (unitMatrix(n, m, p) == 0)
    {
        cout << "\n==> Ma tran tong khong phai la ma tran don vi." << endl;
    }
    else
    {
        cout << "\n==> Ma tran tong la ma tran don vi." << endl;
    }

    // Kiem tra ma tran doi xung
    if (symmetricMatrix(n, m, p) == 0)
    {
        cout << "\n==> Ma tran tong khong phai la ma tran doi xung." << endl;
    }
    else
    {
        cout << "\n==> Ma tran tong la ma tran doi xung." << endl;
    }

    return 0;
}