#include <iostream>

using namespace std;

int main(void)
{
    int vector_length;

    cout << "Quanti elementi si desidera inserire?"
         << "\n";
    cin >> vector_length;

    int vector[vector_length];

    for (int i = 0; i < vector_length; i++)
    {
        cout << "Inserisci il valore nr. " << (i + 1) << ": ";
        cin >> vector[i];
    }

    for (int i = 0; i < vector_length; i++)
    {
        cout << vector[i] << " ";
    }

    cout << "\n";

    for (int i = 0; i < vector_length; i++)
    {
        if (i == 0)
            continue;

        // Il valore nella posizione precedente rispetto a quella attualmente puntata dall'indice i è pari?
        if (((vector[i - 1] % 2) == 0) && (vector[i - 1] != 0))
        {
            cout << vector[i] << " ";
        }
    }

    cout << "\n";

    return 0;
}