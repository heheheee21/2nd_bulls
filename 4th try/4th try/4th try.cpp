#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int MegaRandom(int SIZE)
{
    int full = 0;
    int* A = new int[SIZE];
    bool alreadylol;
    for (int i = 0; i < SIZE;)
    {
        alreadylol = false;// не знаем еще есть похожая или нет
        int newRand = rand() % 10; //создали случайную переменную
        for (int j = 0; j < i; j++) // проверка на уникальность нового числа
        {
            if (A[0] == 0)//обхожу нули на первой позиции
            {
                alreadylol = true;
                break;
            }
            if (A[j] == newRand) //равно ли новое значение уже существующему
            {
                alreadylol = true;
                break; // выбегаем тк уже мимо
            }
        }
        if (!alreadylol)
        {
            A[i] = newRand;
            i++;// продолжаем заполнять массив только после того, как убедились в уникальности 
        }
    }
    for (int i = 0; i < SIZE; i++)
        full = full * 10 + A[i];

    return full;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");

    int SIZE, O, G;

    cout << "Если вы хотите угадать число, то введите 1, если вы хотите, чтобы я угадал число, то введите 2: ";
    cin >> O;
    if (O == 1)
    {
        cout << endl << "Выберите уровень сложности: - Easy (компьютер один раз генерирует число, а вы угадываете)" << endl;
        cout << "                            - TryHard (каждый раз, когда вы не угадываете компьютер генерирует случайное число)" << endl;
        cout << "Если хотите поиграть в режим Easy, введите 1, если хотите поиграть в режим TryHard введите 2: ";
        cin >> G;

    }//описание к выобру режима
    if (O == 1 && G == 1)
    {//режим классика
        cout << "Введите длину числа: ";
        cin >> SIZE;
        int MyN = MegaRandom(SIZE);//генерим число
        if (SIZE <= 10)
        {
            int* A = new int[SIZE];//массив сгенерированного, для удобства сравнивния
            int kor = 0, bik = 0, k = 1;
            bool ura = true; //переменная для выхода из цикла
            cout << "Число сгенерировано, игра началась...)" << endl;
            while (ura)
            {
                int* B = new int[SIZE];//массив вводимого числа 
                int number;
                cout << endl << "Введите ваш вариант: ";
                cin >> number;
                for (int i = SIZE - 1; i >= 0 && number > 0; i--)
                {
                    B[i] = number % 10;
                    number = number / 10;
                }
                for (int j = SIZE - 1; j >= 0 && MyN > 0; j--)
                {
                    A[j] = MyN % 10;
                    MyN = MyN / 10;
                }
                //читы
                /*
                for (int i = 0; i < SIZE; i++)
                {
                    cout << B[i];
                }
                cout << endl;
                for (int j = 0; j < SIZE; j++)
                {
                    cout << A[j];
                }*/
                for (int i = 0; i < SIZE; i++)//проверка на коров/быков
                {
                    if (A[i] == B[i])
                    {
                        bik++;
                    }
                    else
                        for (int j = 0; j < SIZE; j++)
                        {
                            if (A[i] == B[j])
                                kor++;
                        }
                }
                if (bik == SIZE)
                {
                    ura = false;
                }
                cout << endl << "Быков: " << bik << endl << "Коров: " << kor << endl;
                kor = 0;
                bik = 0;
                k++;
                delete[] B;
            }
            cout << endl << "Вы угадали за " << k << " раз!" << endl;
            delete[] A;
        }
        if (SIZE > 10)
            cout << "Невозможно запустить игру с более, чем десятью символами =(";

    }
    if (O == 2)
    {//угадывает ПК
        cout << "Введите длину числа: ";

        cin >> SIZE;

        cout << "Введите число: ";
        int* A1 = new int[SIZE];//массив вводимого числа 
        int* B1 = new int[SIZE];//массив с числами, которые будет постепенно перебирать ПК
        int number;
        int cheats = 1 * (pow(10, SIZE - 1));
        int ch = 1, k = 0, bik = 0;
        cin >> number; //загадываем
        for (int i = SIZE - 1; i >= 0 && number > 0; i--)
        {
            A1[i] = number % 10;
            number = number / 10;
        }
        for (int i = SIZE - 1; i >= 0 && cheats > 0; i--)
        {
            B1[i] = cheats % 10;
            cheats = cheats / 10;
        }
        for (int i = 0; i < SIZE;)
        {
            if (A1[i] == B1[i])
            {
                bik++;
            }
            cout << "Быков: " << bik << endl;
            k++;
            cout << "Попытка " << k << endl;
            if (bik == i)
            {
                B1[i] += 1;
                /*
                for (int j = 0; j < i; j++)
                {
                    if (B1[i-1] == A1[j])
                        continue;
                }
                */
                //НАДО ДОДЕЛАТЬ (замутить условие, с помощью которого можно замутить адекватный перебор.
            }
            else
            {
                i++;
            }
            for (int l = 0; l < SIZE; l++)
                cout << B1[l];
            cout << endl;
        }
        cout << endl << "Я угадал за " << k << " раз!" << endl;
        delete[] A1;
        delete[] B1;
    }
    if (O == 1 && G == 2)
    {//режим трайхард
        bool ashalet = false;
        cout << "Введите длину числа: ";

        cin >> SIZE;

        if (SIZE <= 10)
        {
            int k = 1;
            while (ashalet = true)
            {
                int MyN = MegaRandom(SIZE);
                int* B = new int[SIZE];//массив с числом пользователя
                int* A = new int[SIZE];//массив с всегда новыми числами
                int number;

                for (int i = SIZE - 1; i >= 0 && MyN > 0; i--)//раскидываем на массив для удобства
                {
                    A[i] = MyN % 10;
                    MyN = MyN / 10;
                }
                int kor = 0, bik = 0, k1 = 0;
                /*for (int i = 0; i < SIZE; i++)
                {
                    cout << A[i];
                }*/
                cout << endl << "Новое число сгенерировано" << endl;
                while (bik != SIZE)
                {
                    cout << endl << "Введите ваш вариант: ";
                    cin >> number;//вводим новый вариант числа
                    for (int i = SIZE - 1; i >= 0 && number > 0; i--)
                    {
                        B[i] = number % 10;
                        number = number / 10;
                    }
                    for (int i = 0; i < SIZE; i++)
                    {
                        if (A[i] == B[i])
                        {
                            bik++;
                        }
                        else
                            for (int j = 0; j < SIZE; j++)
                            {
                                if (A[i] == B[j])
                                    kor++;
                            }
                    }
                    if (bik == SIZE)
                        break;
                    cout << endl << "Быков: " << bik << endl << "Коров: " << kor << endl;
                    kor = 0;
                    bik = 0;
                    k++;
                    break;
                }
                for (int i = 0; i < SIZE; i++)
                {
                    if (A[i] == B[i])
                        k1++;
                }
                if (k1 == SIZE)
                {
                    ashalet = true;
                    cout << endl << "Вы угадали за " << k << " раз, ашалеть!" << endl;
                    break;
                }
                delete[] A;
                delete[] B;
            }
        }
        if (SIZE > 10)
            cout << "Невозможно запустить игру с более, чем десятью символами =(";

    }
    return 0;
}