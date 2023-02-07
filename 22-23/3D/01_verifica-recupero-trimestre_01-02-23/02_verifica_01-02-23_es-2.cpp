#include <iostream>

using namespace std;

int main(void)
{
    const int string_length = 100;
    char string_1[string_length];
    char string_2[string_length];

    cout << "Inserisci la prima stringa (massimo " << string_length - 1 << " caratteri): ";
    cin >> string_1;

    cout << "Inserisci la seconda stringa (massimo " << string_length - 1 << " caratteri): ";
    cin >> string_2;

    // Estrae il numero effettivo di caratteri inseriti.
    int string_1_length = 0;
    for (int i = 0; i < string_length; i++)
    {
        if (string_1[i] == '\0')
            break;
        string_1_length++;
    }

    int string_2_length = 0;
    for (int i = 0; i < string_length; i++)
    {
        if (string_2[i] == '\0')
            break;
        string_2_length++;
    }

    // Creo un terzo vettore, avente grandezza pari alla somma della lunghezza delle stringhe acquisite.
    int conc_length = string_1_length + string_2_length + 1;
    char conc_string[conc_length];

    for (int i = 0; i < string_1_length; i++)
    {
        conc_string[i] = string_1[i];
    }

    for (int i = 0; i < string_2_length; i++)
    {
        conc_string[i + string_1_length] = string_2[i];
    }

    // Importante: ricordarsi di terminare correttamente la sequenza di caratteri.
    conc_string[conc_length] = '\0';
    cout << "Stringa concatenata: " << conc_string;

    return 0;
}