/****************************************************************
 * Project Name:  N_Queens_Problem
 * File Name:     n_queens_problem.cpp
 * File Function: N�ʺ������ʵ��
 * Author:        Jishen Lin (�ּ���)
 * Update Date:   2023/10/26
 ****************************************************************/

#include <iostream>
#include <cmath>

class N_Queens {
private:
    int max;
    int* array;
    int count;
public:
    N_Queens(int size)
    {
        max = size;
        array = new int[max];
        count = 0;
        for (int i = 0; i < max; i++)
            array[i] = -1;
    }
    ~N_Queens()
    {
        delete[] array;
    }
    bool isSafeToPlace(int n)
    {
        for (int i = 0; i < n; i++)
            if (array[n] == array[i] || std::abs(n - i) == std::abs(array[n] - array[i]))
                return false;
        return true;
    }
    void findRecursively(int n)
    {
        if (n == max) {
            printChessboard();
            count++;
            return;
        }
        for (int i = 0; i < max; i++) {
            array[n] = i;
            if (isSafeToPlace(n))
                findRecursively(n + 1);
        }
    }
    void printChessboard(void)
    {
        for (int i = 0; i < max; i++)
            std::cout << array[i] << " ";
        std::cout << std::endl;
    }
    void solve(void)
    {
        findRecursively(0);
        std::cout << max << " �ʺ�����Ľⷨ�� " << count << " ��" << std::endl;
    }
};

int main() {

    /* System entry prompt */
    std::cout << "+--------------------+" << std::endl;
    std::cout << "|     N�ʺ�����      |" << std::endl;
    std::cout << "|  N Queens Problem  |" << std::endl;
    std::cout << "+--------------------+" << std::endl << std::endl;


    int size = 6; // ����N��ֵ
    N_Queens queens(size);


    queens.solve();



    return 0;
}