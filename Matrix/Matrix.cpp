#include <ctime>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;


void ExOne();
void ExTwo();
void ExThree();
void ExFour();



int main() {
    setlocale(LC_ALL, "Russian"); //вводим в консоль русский язык

    //ExOne();
    /* Преобразовать матрицу, умножив элементы каждой строки на значение второго
    элемента этой строки.*/

    //ExTwo();
    /*В квадратной матрице найти сумму положительных элементов, лежащих на и выше
    главной диагонали и расположенных в чётных столбцах*/

    //ExThree();
    /*Дана матрица. Элементы первой строки — количество осадков в соответствующий
    день, второй строки — сила ветра в этот день. Найти, был ли в эти дни ураган?
    (ураган — когда самый сильный ветер был в самый дождливый день).*/

    ExFour();
    /*Объявить, реализовать заполнение данными с клавиатуры ИЛИ из файла и вывести
    на экран матрицу, описывающую следующие сущности. Предложите свой вариант.
    b. Состояние робота на шахматной доске. Робот характеризуется уровнем
    заряда, скоростью движения.*/
}

void ExOne() {
    const int rows = 4;  // строки
    const int cols = 4;  // столбцы
    int mat[rows][cols];
    int itog;

   
    cout << "Вывод первоначальной матрицы\n";                   // вывод первоначальной матрицы
    for (int i = 0; i < rows; i++) {                               
        for (int j = 0; j < cols; j++) {
            mat[i][j] = rand() % 21-10;
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "Вывод итоговой матрицы\n";                         //вывод итоговой матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            itog = mat[i][j] * mat[i][1];
            cout << itog << " ";
        }
        cout << "\n";
    }

 

}
void ExTwo() {
    const int rows = 5;  // строки
    const int cols = 5;  // столбцы
    int mat[rows][cols];
    int summ = 0;


    cout << "Вывод первоначальной матрицы\n";                   // вывод первоначальной матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = rand() % 21 - 10;
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";


    for (int i = 0; i < rows; i++) {                            // выбираем те числа, которые И по диогонали и выше, И положительные, И в чётных столбцах
        for (int j = 0; j < cols; j++) {
            if ((j >= i)  && (mat[i][j] > 0) && (j % 2 == 1)){
                summ = summ + mat[i][j];
            }
        }
    }
    cout << "Вывод суммы положительных элементов, лежащих на и выше главной диагонали и расположенных в чётных столбцах\n";
    cout << summ;
    cout << "\n";
}
void ExThree() {
    const int rows = 2;  // строки
    const int cols = 7;  // столбцы
    int mat[rows][cols];
    string itog;
    int maxOsad = 0;
    int maxVeter = 0;


    cout << "Вывод первоначальной матрицы\n";                   // вывод первоначальной матрицы + знаяения Максимума
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i % 2 == 0) {
                mat[i][j] = rand() % 21;
                if (mat[i][j] > maxOsad)
                    maxOsad = mat[i][j];
            }
            else {
                mat[i][j] = rand() % 101;
                if (mat[i][j] > maxVeter)
                    maxVeter = mat[i][j];
            }
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "Вывод\n";                                      //смотрим, есть ли такой день
        for (int j = 0; j < cols; j++) {
            if ((mat[0][j] == maxOsad) && (mat[1][j] == maxVeter))
                itog = "В эти дни был ураган";
             else
                 itog = "В эти дни не было урагана";
        }
    cout << itog;
}
void ExFour() {
    const int rows = 8;  // строки
    const int cols = 8;  // столбцы
    string mat[rows][cols];
    int schet = 0;
    int zaryad = 10;
    string speed = "один ход";
    char kuda;

    int LeftRight = 0;
    int UpDown = 0;


    cout << "Вывод первоначального поля\n";                   // вывод первоначальной матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = "*";
            schet++;
            if (schet % 2 == 0)
                mat[i][j] = "#";
            mat[LeftRight][UpDown] = "$";                   //задаём начальное положение
            cout << mat[i][j] << " ";
        }
        schet++;
        cout << "\n";
    }
    cout << "\n\n"
        << "Осталось заряда = " << zaryad << "\n"
        << "Ваша скорость = " << speed << "\n";             //скорость в матричном передвижении... не понял совсем


tryAgain:                   //значеня, что бы ходить вновь
    cin >> kuda;


    if (kuda == 's') {                   //движение вниз
        zaryad--;
        system("cls");
        LeftRight++;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = "*";
                schet++;
                if (schet % 2 == 0)
                    mat[i][j] = "#";
                mat[LeftRight][UpDown] = "$";
                cout << mat[i][j] << " ";
            }
            schet++;
            cout << "\n";
        }
        cout << "\n\n"
            << "Осталось заряда = " << zaryad << "\n"
            << "Ваша скорость = " << speed << "\n";
    }
    else
        cout << "Вы ввели неправильное направление\n";
    if (kuda == 'd') {                   //движение вправо
        zaryad--;   
        system("cls");
        UpDown++;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = "*";
                schet++;
                if (schet % 2 == 0)
                    mat[i][j] = "#";
                mat[LeftRight][UpDown] = "$";
                cout << mat[i][j] << " ";
            }
            schet++;
            cout << "\n";
        }
        cout << "\n\n"
            << "Осталось заряда = " << zaryad << "\n"
            << "Ваша скорость = " << speed << "\n";
    }
    if (kuda == 'w') {                      //движение вверх
        zaryad--;
        system("cls");
        LeftRight--;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = "*";
                schet++;
                if (schet % 2 == 0)
                    mat[i][j] = "#";
                mat[LeftRight][UpDown] = "$";
                cout << mat[i][j] << " ";
            }
            schet++;
            cout << "\n";
        }
        cout << "\n\n"
            << "Осталось заряда = " << zaryad << "\n"
            << "Ваша скорость = " << speed << "\n";
    }
    if (kuda == 'a') {                       //движение вправо
        zaryad--;
        system("cls");
        UpDown--;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = "*";
                schet++;
                if (schet % 2 == 0)
                    mat[i][j] = "#";
                mat[LeftRight][UpDown] = "$";
                cout << mat[i][j] << " ";
            }
            schet++;
            cout << "\n";
        }
        cout << "\n\n"
            << "Осталось заряда = " << zaryad << "\n"
            << "Ваша скорость = " << speed << "\n";
    }
    

    while (zaryad >= 0)                     //Это всё происходит пока есть заряд (мы вновь возвращаемся к введению направления)
    {
        goto tryAgain;          
    }
}
