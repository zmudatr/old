#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>



struct wezel
{
    wezel* nastepny;
    char znak;

    wezel()  // zainicjowanie struktury
    {
        nastepny = NULL;
        znak = '.';
    }
};

void dodaj_element(char v, wezel*& head) // Dodanie litery do ci¹gu, head wskazuje zawsze na ostatnia litere ciagu
{
    if (v != ' ')
    {
        wezel* nowy;  // nowa LITERA
        nowy = new wezel;
        nowy->znak = v;

        if (head)
        {
            nowy->nastepny = head->nastepny;
            head->nastepny = nowy;
        }
        else
        {
            nowy->nastepny = nowy;
        }

        head = nowy;  // elementem biezacym jest teraz nowy
    }
}

void zeruj(wezel*& head)
{
    if (head)
    {
        wezel* temp = head;
        wezel* usuwany;
        do
        {
            usuwany = temp;
            temp = temp->nastepny;
            delete usuwany;
        } while (temp != head);
    }
    head = NULL;
}

void wypisz(wezel*& head)
{
    wezel* temp = head;
    if (temp) // jesli niepusta
    {
        do
        {
            if (temp->nastepny)
            {
                temp = temp->nastepny;
                printf("%c", temp->znak);
            }
        } while (temp != head);
    }
    printf("\n");
}

void odwroc(wezel*& head)
{
    if (head) //  czy nie jest NULLEM ?
    {
        wezel* temp = head;
        wezel* nowy = NULL;
        wezel* temp2 = head;
        if (head->nastepny != head)
        {
            do
            {
                dodaj_element(temp->znak, nowy);
                do
                {
                    temp = temp->nastepny;
                } while (temp->nastepny != temp2);
                temp2 = temp;

            } while (head != temp2);
            zeruj(head);
            head = nowy;
        }
    }
}


void przesun(wezel*& head, int k)
{
    for (int i = 0; i < k; i++)
        head = head->nastepny;
}

void usun(wezel*& head, int k)
{
    wezel* temp = head->nastepny;
    wezel* usuwany = head;

    for (int i = 0; i < k; i++)
    {

        usuwany = temp;
        temp = temp->nastepny;

        if (head->nastepny == head)
        {
            head->nastepny = NULL;
            head = NULL;

        }
        else
        {
            head->nastepny = usuwany->nastepny;
            delete usuwany;
        }

    }
}

void doklej_skopiuj(wezel*& cel, wezel*& zrodlo, bool zerowac)
{
    wezel* temp = zrodlo;
    if (temp)
    {
        do
        {
            temp = temp->nastepny;
            dodaj_element(temp->znak, cel);
        } while (temp != zrodlo);
    }
    if (zerowac) zeruj(zrodlo);
}

void mieszaj(wezel*& cel, wezel*& zrodlo)
{
    bool flagaCel = false;
    bool flagaZrodlo = false;
    bool zakoncz = false;
    wezel* tempCelu = cel->nastepny;
    wezel* tempZrodla = zrodlo->nastepny;
    wezel* nowy = NULL;
    while (!zakoncz)
    {
        if (flagaCel == false)
        {
            if (tempCelu == cel)
            {
                flagaCel = true;
                dodaj_element(tempCelu->znak, nowy);
            }
            else
            {
                dodaj_element(tempCelu->znak, nowy);
                tempCelu = tempCelu->nastepny;
            }
        }
        else
        {
            if (tempZrodla == zrodlo)
            {
                flagaZrodlo = true;
                dodaj_element(tempZrodla->znak, nowy);
            }
            else
            {
                do
                {
                    dodaj_element(tempZrodla->znak, nowy);
                    tempZrodla = tempZrodla->nastepny;
                } while (tempZrodla != zrodlo);
                zakoncz = true;
            }
        }


        //////////////////////////////////////////////


        if (flagaZrodlo == false)
        {
            if (tempZrodla == zrodlo)
            {
                flagaZrodlo = true;
                dodaj_element(tempZrodla->znak, nowy);
            }
            else
            {
                dodaj_element(tempZrodla->znak, nowy);
                tempZrodla = tempZrodla->nastepny;
            }
        }



        if ((flagaCel == true) && (flagaZrodlo == true))
        {
            zakoncz = true;
        }

    }  // END WHILE
    zeruj(cel);
    cel = nowy;
    zeruj(zrodlo);
}

int licz(wezel*& head)
{
    int value = 0;
    int mnoznik = 1;
    wezel* temp = head;
    wezel* temp2 = head;
    int liczba = 0;
    do
    {
        liczba = temp->znak - 48;  // 48 to kod 0 w ASCII
        value = value + mnoznik * liczba;
        do
        {
            temp = temp->nastepny;
        } while (temp->nastepny != temp2);
        temp2 = temp;
        mnoznik = mnoznik * 10;
    } while (head != temp2);

    delete temp;
    return value;
}

int main()
{
    wezel* rejestry[26];
    for (int i = 0; i < 26; i++) rejestry[i] = NULL;
    wezel* wczytany[1];
    wczytany[0] = NULL;

    char operacja[3];
    char ktory_rejestr;
    char c = '.';
    int result = 0;

    do
    {
        operacja[0] = '\0';
        operacja[1] = '\0';
        operacja[2] = '\0';
        wczytany[0] = NULL;
        result = scanf("%c", &operacja[0]);
        if (result != EOF)
        {
            result = scanf("%c", &operacja[1]);

            if (result != EOF)
            {
                result = scanf("%c", &operacja[2]);

                if (result != EOF)
                {
                    while (c != ' ')
                    {
                        result = scanf("%c", &c);
                    };                       // omijam nieistotne litery operacji az do spacji

                    result = scanf("%c", &ktory_rejestr); // zapisuje nr rejestru
                    result = scanf("%c", &c);                    // wczytuuje spacje po rejestrze

                    if (c == ' ')
                    {
                        if (operacja[0] == 'U' && operacja[2] == 'T')
                        {
                            ktory_rejestr = ktory_rejestr - 65;
                            zeruj(rejestry[ktory_rejestr]);

                            while (c != '\n')
                            {
                                result = scanf("%c", &c);
                                if (c == '\n');
                                else
                                {
                                    dodaj_element(c, rejestry[ktory_rejestr]);
                                }
                            }
                        }
                        else
                        {
                            zeruj(wczytany[0]);
                            while (c != '\n')
                            {
                                result = scanf("%c", &c);
                                if (c == '\n');
                                else
                                {
                                    dodaj_element(c, wczytany[0]);
                                }
                            }
                        }
                    }
                }

                switch (operacja[2])
                {

                case 82:     // ZE(R)UJ
                    zeruj(rejestry[ktory_rejestr - 65]);
                    break;

                case 80:     // WY(P)ISZ
                    wypisz(rejestry[ktory_rejestr - 65]);
                    break;
                case 90:         //PR(Z)ESUN
                {
                    int k = licz(wczytany[0]);
                    przesun(rejestry[ktory_rejestr - 65], k);
                }
                break;
                case 85:         // US(U)N
                {
                    int k = licz(wczytany[0]);
                    usun(rejestry[ktory_rejestr - 65], k);
                }
                break;
                case 87:         // OD(W)ROC
                    odwroc(rejestry[ktory_rejestr - 65]);
                    break;
                case 75:             // DO (K) LEJ
                case 79:             // SKO (P) IUJ
                {
                    bool zerowac = false; // zmienna zerujaca zrodlo w operacji doklej
                    int c = wczytany[0]->znak - 65;
                    if (operacja[0] == 'D') zerowac = true;
                    doklej_skopiuj(rejestry[ktory_rejestr - 65], rejestry[c], zerowac);
                }
                break;
                case 69:         // MI(E)SZAJ
                {
                    int c = wczytany[0]->znak - 65;
                    mieszaj(rejestry[ktory_rejestr - 65], rejestry[c]);
                }
                break;

                default:
                    break;
                }
            }
        }
    } while (result != EOF);

    zeruj(wczytany[0]);
    for (int i = 0; i < 26; i++)
    {
        zeruj(rejestry[i]);
    }

    return 0;
}
