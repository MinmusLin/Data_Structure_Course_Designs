/****************************************************************
 * Project Name:  N_Queens_Problem
 * File Name:     n_queens_problem.cpp
 * File Function: N�ʺ������ʵ��
 * Author:        Jishen Lin (�ּ���)
 * Update Date:   2023/10/27
 ****************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>
#include <limits>

/* Macro definition */
#define MEMORY_ALLOCATION_ERROR -1

/* Define N_Queens class */
class N_Queens {
private:
    int size;
    int count;
    int* array;
public:
    N_Queens(int n);
    ~N_Queens();
    bool isSafeToPlace(int n);
    void findRecursively(int n);
    void printChessboard(void);
    void solve(void);
};

/*
 * Function Name:    N_Queens
 * Function:         Constructed function
 * Input Parameters: int n
 * Notes:            Class external implementation of member functions
 */
N_Queens::N_Queens(int n)
{
    size = n;
    count = 0;
    array = new(std::nothrow) int[size];
    if (array == NULL) {
        std::cerr << "Error: Memory allocation failed." << std::endl;
        exit(MEMORY_ALLOCATION_ERROR);
    }
    for (int i = 0; i < size; i++)
        array[i] = -1;
}

/*
 * Function Name:    ~N_Queens
 * Function:         Destructor
 * Notes:            Class external implementation of member functions
 */
N_Queens::~N_Queens()
{
    delete[] array;
}

/*
 * Function Name:    isSafeToPlace
 * Function:         Check if it is safe to place a queen
 * Input Parameters: int n
 * Return Value:     true / false
 * Notes:            Class external implementation of member functions
 */
bool N_Queens::isSafeToPlace(int n)
{
    for (int i = 0; i < n; i++)
        if (array[n] == array[i] || std::abs(n - i) == std::abs(array[n] - array[i]))
            return false;
    return true;
}

/*
 * Function Name:    findRecursively
 * Function:         Recursively find solutions to the N-Queens problem
 * Input Parameters: int n
 * Return Value:     void
 * Notes:            Class external implementation of member functions
 */
void N_Queens::findRecursively(int n)
{
    if (n == size) {
        printChessboard();
        count++;
    }
    else {
        for (int i = 0; i < size; i++) {
            array[n] = i;
            if (isSafeToPlace(n))
                findRecursively(n + 1);
        }
    }
}

/*
 * Function Name:    printChessboard
 * Function:         Print the chessboard state for one solution
 * Input Parameters: void
 * Return Value:     void
 * Notes:            Class external implementation of member functions
 */
void N_Queens::printChessboard(void)
{
    std::cout << std::endl << ">>> �ⷨ " << count + 1 << std::endl << std::endl << "   ";
    for (int i = 0; i < size; i++)
        std::cout << std::setw(2) << i + 1;
    std::cout << std::endl << "  +" << std::setfill('-') << std::setw(2 * size) << "-" << std::setfill(' ') << "+" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << std::setw(2) << i + 1 << "|";
        for (int j = 0; j < size; j++)
            std::cout << (j == array[i] ? "��" : "  ");
        std::cout << "|" << std::endl;
    }
    std::cout << "  +" << std::setfill('-') << std::setw(2 * size) << "-" << std::setfill(' ') << "+" << std::endl;
}

/*
 * Function Name:    solve
 * Function:         Solve N-Queens problem
 * Input Parameters: void
 * Return Value:     void
 * Notes:            Class external implementation of member functions
 */
void N_Queens::solve(void)
{
    findRecursively(0);
    std::cout << std::endl << ">>> " << size << " �ʺ������� " << count << " �ֽⷨ" << std::endl << std::endl;
}

/*
 * Function Name:    inputInteger
 * Function:         Input an integer
 * Input Parameters: int lowerLimit
 *                   int upperLimit
 *                   const char* prompt
 * Return Value:     an integer
 */
int inputInteger(int lowerLimit, int upperLimit, const char* prompt)
{
    while (true) {
        std::cout << "������" << prompt << " [������Χ: " << lowerLimit << "~" << upperLimit << "]: ";
        double tempInput;
        std::cin >> tempInput;
        if (std::cin.good() && tempInput == static_cast<int>(tempInput) && tempInput >= lowerLimit && tempInput <= upperLimit) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return static_cast<int>(tempInput);
        }
        else {
            std::cerr << std::endl << ">>> " << prompt << " ���벻�Ϸ�������������" << prompt << " ��" << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

/*
 * Function Name:    main
 * Function:         Main function
 * Return Value:     0
 */
int main()
{
    /* System entry prompt */
    std::cout << "+--------------------+" << std::endl;
    std::cout << "|     N�ʺ�����      |" << std::endl;
    std::cout << "|  N Queens Problem  |" << std::endl;
    std::cout << "+--------------------+" << std::endl << std::endl;

    /* Problem description */
    std::cout << ">>> ��������" << std::endl << std::endl;
    std::cout << "    ��һ�� N �� N �������ϣ����� N ���ʺ�ʹ�以����" << std::endl;
    std::cout << "������û�����������ʺ���ͬһ�С�ͬһ�л�ͬһ�Խ����ϡ�" << std::endl << std::endl;

    /* Input N and initialize n_queens object */
    N_Queens n_queens(inputInteger(1, 99, "�ʺ���� N"));

    /* Solve N-Queens Problem */
    n_queens.solve();

    /* Wait for enter to quit */
    std::cout << "Press Enter to Quit" << std::endl;
    while (_getch() != '\r')
        continue;

    /* Program ends */
    return 0;
}