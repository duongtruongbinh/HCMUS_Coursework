#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

// Để đơn giản nên em xin tạo ma trận n x n
vector<vector<int>> createRandomMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 10; // Giả sử giá trị từ 0 đến 9
        }
    }
    return matrix;
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    int m = A[0].size();
    int p = B[0].size();
    vector<vector<int>> result(n, vector<int>(p, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < m; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    vector<int> sizes = {50,100,300,500,700,1000,1500,2000};

    ofstream timeFile("21127229.txt");
    for (int size : sizes)
    {
        auto matrixA = createRandomMatrix(size);
        auto matrixB = createRandomMatrix(size);

        auto start = high_resolution_clock::now();
        auto result = multiplyMatrices(matrixA, matrixB);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        double seconds = double(duration.count()) / 1000000; // Đổi ra giây
        timeFile << seconds;
        if (size != sizes.back())
        {
            timeFile << endl;
        }
    }
    timeFile.close();

    return 0;
}