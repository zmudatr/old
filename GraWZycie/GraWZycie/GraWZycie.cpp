#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct mapa
{
    char data;
    short ngbr;
    bool visited;

    mapa()
    {
        visited = false;
        data = '.';
        ngbr = 0;
    }
};

unsigned int szukaj_dalej(mapa** komorka, int kolumna, int wiersz, int sze, int wy, int counter);
unsigned int szukaj(mapa** komorka, int kolumna, int wiersz, int sze, int wy, int counter);

int main()
{
    int szer, wys, tura, rekordzista, obecny;
    char bufor;


    scanf("%d%d%d ", &szer, &wys, &tura);

    mapa** cell = new mapa * [szer];

    for (short i = 0; i < szer; i++)
        cell[i] = new mapa[wys];

    short k = 0;
    short m = 0;
    short x = -1;
    short y = -1;

    for (int i = 0; i < szer * wys; i++)
    {
        do
        {
            scanf("%c", &bufor);
            if (bufor == '.') break;
        } while (bufor == '\n');
        if (k >= szer) k = 0, m++;
        cell[k][m].data = bufor;
        k++;
    }


    //KOLEJNE TURY



    for (short a = 0; a < tura; a++)
    {

        k = 0;
        m = 0;

        short ile;

        for (int i = 0; i < szer * wys; i++)
        {
            ile = 0;
            if (k >= szer) k = 0, m++;
            x = -1;
            y = -1;

            for (short l = 0; l <= 8; l++)
            {
                if (x > 1) x = -1, y++;
                if (k + x >= szer || k + x < 0 || m + y >= wys || m + y < 0 || (k + x == k && m + y == m))
                {
                    x++;
                    continue;
                }
                if (cell[k + x][m + y].data == '#')
                {
                    ile++;
                }
                x++;
            }
            cell[k][m].ngbr = ile;
            k++;
        }

        k = 0;
        m = 0;

        for (int i = 0; i < szer * wys; i++)
        {
            if (k >= szer) k = 0, m++;

            switch (cell[k][m].ngbr)
            {
            case 3:
                cell[k][m].data = '#';
                break;
            case 2:
                break;
            default:
                cell[k][m].data = '.';
                break;
            }

            k++;
        }
    }

    // KONIEC TUR



    k = 0;
    m = 0;
    rekordzista = 0;
    obecny = 0;


    // SZUKANIE SĄSIADÓW
    for (int i = 0; i < szer * wys; i++)
    {
        if (k >= szer) k = 0, m++;
        if (cell[k][m].data == '.' || cell[k][m].visited == true)
        {

            cell[k][m].visited = true;
            k++;
            continue;
        }
        else
        {
            obecny = szukaj(cell, k, m, szer, wys, obecny);
            if (obecny > rekordzista)
            {
                rekordzista = obecny;
            }
            obecny = 0;
        }


        k++;

    }

    printf("%d", rekordzista);

    /* //##### WYGLAD MAPY #####
         printf("\n");
         for (short j = 0; j<wys; j++)
         {
             for (short i = 0; i<szer; i++)
             {
                 printf("%c", cell[i][j].data);
             }
             printf("\n");
         }*/



    for (short i = 0; i < szer; i++)  // Zwolnienie pamieci
        delete[] cell[i];

    delete[] cell;

    return 0;
}

unsigned int szukaj_dalej(mapa** komorka, int kolumna, int wiersz, int sze, int wy, int counter)
{
    komorka[kolumna][wiersz].visited = true;
    int x = -1;
    int y = -1;
    for (short l = 0; l <= 8; l++)
    {
        if (x > 1) x = -1, y++;
        if (kolumna + x >= sze || kolumna + x < 0 || wiersz + y >= wy || wiersz + y < 0 || (kolumna + x == kolumna && wiersz + y == wiersz))
        {
            x++;
            continue;
        }
        else
        {
            if (komorka[kolumna + x][wiersz + y].visited == true)
            {
                x++;
                continue;
            }
            if (komorka[kolumna + x][wiersz + y].data == '#')
            {
                counter = szukaj(komorka, kolumna + x, wiersz + y, sze, wy, counter);
            }
            else
            {
                //komorka[kolumna+x][wiersz+y].visited = true;
                x++; //counter = szukaj_dalej(komorka, kolumna+x, wiersz+y, sze, wy, counter);
                continue;
            }
        }
        x++;
    }



    return counter;
}


unsigned int szukaj(mapa** komorka, int kolumna, int wiersz, int sze, int wy, int counter)
{
    komorka[kolumna][wiersz].visited = true;
    if (komorka[kolumna][wiersz].data == '#') counter++;
    int x = -1;
    int y = -1;
    for (short l = 0; l <= 8; l++)
    {
        if (x > 1) x = -1, y++;
        if (kolumna + x >= sze || kolumna + x < 0 || wiersz + y >= wy || wiersz + y < 0 || (kolumna + x == kolumna && wiersz + y == wiersz))
        {
            x++;
            continue;
        }
        else
        {
            if (komorka[kolumna + x][wiersz + y].visited == true)
            {
                x++;
                continue;
            }
            if (komorka[kolumna + x][wiersz + y].data == '#')
            {
                counter = szukaj(komorka, kolumna + x, wiersz + y, sze, wy, counter);
            }
            else counter = szukaj_dalej(komorka, kolumna + x, wiersz + y, sze, wy, counter);

        }
        x++;
    }


    return counter;
}
