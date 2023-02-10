/*
    Scrivere un programma in C++ capace di generare una "board" per il gioco della battaglia navale,
    avente i seguenti vincoli:

    - dimensione: 10x10 caselle
    - in ciascuna casella sono ammessi unicamente 2 valori:
        * '0' acqua
        * '1' nave
    - una nave deve essere di dimensione almeno pari a 3 caselle
    - sono ammesse unicamente navi orizzontali
*/

#include <iostream>

using namespace std;

int main(void)
{
    // http: // www.math.uaa.alaska.edu/~afkjm/csce211/handouts/RandomFunctions.pdf
    srand(time(NULL));

    const int SIZE = 10;
    int board[SIZE][SIZE];
    int elm;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            elm = (rand() % 2);

            // È stata generata una nave.
            if (elm == 1)
            {
                // Sono in prossimità del bordo? Forzo il valore a '0', poiché non potrei soddisfare il vincolo
                // "navi di lunghezza pari ad almeno 3".
                if (j >= SIZE - 2)
                {
                    elm = 0;
                }

                // Nelle 3 caselle immediatamente superiori sono già presenti '1'?
                // Forzo '0', poiché non possono esistere navi verticali.
                else if ((i > 0) && (board[i - 1][j] == 1) || (board[i - 1][j + 1] == 1) || (board[i - 1][j + 2] == 1))
                {
                    elm = 0;
                }

                board[i][j] = elm;

                // Il valore '1' generato NON è stato "rettificato" in uno '0'
                if (elm == 1)
                {
                    board[i][j + 1] = 1;
                    board[i][j + 2] = 1;

                    if (j + 2 < SIZE)
                    {
                        j = j + 2;
                    }
                    else
                    {
                        j = SIZE - 1;
                    }
                }
            }
            else
            {
                // È stata generata acqua.
                board[i][j] = elm;
            }
        }
    }

    // Stampa a video la board completa.
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}