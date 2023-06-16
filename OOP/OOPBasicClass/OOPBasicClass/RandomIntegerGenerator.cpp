#include "RandomIntegerGenerator.h"


RandomIntegerGenerator::RandomIntegerGenerator()
{
    cout << "Ham tao sinh so ngau nhien" << endl;
    srand(time(NULL));
}

RandomIntegerGenerator::~RandomIntegerGenerator() {
    cout << "Ham huy sinh so ngau nhien" << endl;
}

/// <summary>
/// Trả ra số nguyên ngẫu nhiên
/// </summary>
/// <returns>Số nguyên miền giá trị [0, 65535]</returns>
int RandomIntegerGenerator::next() {
    int result = rand();
    return result;
}

/// <summary>
/// Sinh số nguyên ngẫu nhiên
/// </summary>
/// <param name="max">Giá trị tối đa</param>
/// <returns>Số nguyên trong đoạn [0, max)</returns>
int RandomIntegerGenerator::next(int max) {
    int result = rand() % max;
    return result;
}

/// <summary>
/// Sinh số nguyên ngẫu nhiên
/// </summary>
/// <param name="left">Biên trái</param>
/// <param name="right">Biên phải</param>
/// <returns>Số nguyên trong đoạn [left, right]</returns>
int RandomIntegerGenerator::next(int left, int right) {
    int result = rand() % (right - left + 1) + left;
    return result;
}