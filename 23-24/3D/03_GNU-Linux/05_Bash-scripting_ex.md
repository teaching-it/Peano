## Ex 1

Creare un file vuoto dal nome pippo.txt all'interno della propria home directory. Copiare il file pippo.txt all’interno della cartella Desktop.

### Soluzione 1

```bash
# Mi posiziono all'interno della home directory.
cd
# Creo il file vuoto
touch pippo.txt
# Copio il file all'interno della sottocartella Desktop
cp pippo.txt Desktop/
```

### Soluzione 2

```bash
# Mi posiziono all'interno della home directory.
cd
# Creo il file vuoto
touch pippo.txt
# Copio il file all'interno della sottocartella Desktop
if [ -d "Desktop/" ]; then 
    cp pippo.txt Desktop/; 
else 
    echo "La cartella Desktop non esiste.";
fi
```

## Ex 2

Creare un file contenente il testo "Hello World!" all'interno della cartella /tmp. 

Creare una nuova cartella dal nome "Pippo" all’interno del percorso /home/nomeutente/Desktop. 

Copiare il file creato all’interno di quest’ultimo percorso avendo cura di verificare che il percorso esista.

```bash
#!/bin/bash
echo "Hello World!" > /tmp/hello.txt

# L'opzione -p assicura che vengano create anche le cartelle padre, se non esistono.
mkdir -p /home/nomeutente/Desktop/Pippo

if [ -d "/home/nomeutente/Desktop/Pippo" ]; then
    cp /tmp/hello.txt /home/nomeutente/Desktop/Pippo/
else
    echo "La cartella di destinazione non esiste."
fi
```

## Ex 3

Creare le cartelle *files* e *backup*  all'interno della propria home directory.

All'interno della cartella *files*, mediante un ciclo for, creare 10 file aventi per nome *"file-k"*, dove *k* è il valore incrementale della variabile di controllo.

Copiare tutti i file creati dalla cartella *files* alla cartella *backup*.

```bash
#!/bin/bash

# Mi posiziono all'interno della home directory.
cd 

# Crea le cartelle 'files' e 'backup'.
mkdir -p files
mkdir -p backup

# Entra nella cartella 'files'.
cd files

# Genera 10 file vuoti denominati 'file-1' fino a 'file-10'.
for k in {1..10}; do
    touch "file-$k"
done

# Ritorna alla home directory dell'utente.
cd

# Copia tutti i file dalla cartella 'files' alla cartella 'backup'.
cp ./files/* ./backup/

# Messaggio di fine operazioni.
echo "File copiati con successo dalla cartella 'files' alla cartella 'backup'."
```

## Ex 4

Script per il monitoraggio delle risorse del sistema.

Il comando `free` mostra il quantitativo di memoria RAM usata e disponibile.

Il comando `df -h` mostra lo spazio su disco assegnato e disponibile per ciascuna partizione.

L'obiettivo dello script è visualizzare a schermo due informazioni: RAM disponibile, spazio su disco disponibile all'interno della partizione `/`.

### Tips and tricks

#### Tip 1

Per salvare l'output di un comando in una variabile in Bash, si utilizza la sintassi seguente:

```bash
output_cmd=$(comando)
```

Ad esempio, per memorizzare all'interno di una variabile l'esito del comando `ls` e stamparlo a video referenziando il contenuto della variabile stessa (occhio all'uso del carattere `$`):

```bash
output_ls=$(ls)
echo $output_ls
```

#### Tip 2

Il pipe, indicato dal simbolo `|`, è un operatore molto potente nei sistemi operativi Unix e Linux che permette di dirigere l'output  di un comando come input per un altro comando. 

Un esempio classico di utilizzo del pipe è il filtraggio dell'output di un comando attraverso il comando `grep`:

```bash
ls -al | grep "testo"
```

In questo esempio, l'output del comando `ls -al` , viene passato a `grep`, che filtra e mostra solo le righe che contengono la parola `testo`.

Tornando all'esercizio, potrebbe valer la pena filtrare l'output dei comandi `free` e `df -h` prima di memorizzare ciascun output all'interno di una variabile, al fine di selezionare unicamente la riga di interesse.

#### Tip 3

Adesso che potenzialmente dispongo di due variabili con il contenuto di interesse, non mi resta che applicare un ulteriore filtro al fine di estrarre precisamente il dato richiesto.

`awk` è un potente linguaggio di programmazione utilizzato per la manipolazione dei dati in Linux. Una delle operazioni più comuni in `awk` è stampare specifiche colonne/parole/token di un testo in input. Ad esempio, il seguente script stamperà a video `token-1 token-2 bla`, ovvero la prima, la seconda e la quinta parola.

```bash
text="token-1 token-2 token-3 token-4 bla bla"
echo $text | awk '{print $1, $5}'
```
