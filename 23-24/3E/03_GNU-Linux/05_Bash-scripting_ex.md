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

### Soluzione (elaborata durante la lezione di laboratorio del 09/03/24)

```bash
# !/bin/bash

# 1. Creare un file contenente il testo "Hello World!" all'interno della cartella /tmp
cd /tmp
echo "Hello World" >> file-testo

# Posso verificare il contenuto del file con il comando cat
cat file-testo

# 2. Creare una nuova cartella dal nome "Pippo" all'interno del percorso /home/nomeutente/Desktop

# Per tornare rapidamente alla propria home directory mi è sufficiente impartire il comando "cd"
cd

# Oppure, posso "sfogliare" l'intero percorso, sino a giungere alla home directory
cd ..
cd home
cd nomeutente
cd Desktop

# Oppure, in un sol colpo, posso approdare ad un percorso espresso in formato "assoluto"
cd /home/nomeutente/Desktop

# Creazione cartella
mkdir pippo

# 3. Copiare il file creato all'interno di quest'ultimo percorso avendo cura di verificare che il percorso esista

if [ -d /home/nomeutente/Desktop/pippo ]; then
    # Opzione 1.
    cp /tmp/file-testo /home/nomeutente/Desktop/pippo
    # Opzione 2.
    cp /tmp/file-testo pippo/
else
    echo "Il percorso non esiste!"
fi
```

## Ex 3

1. Creare un file vuoto denominato empty-file all'interno del percorso /tmp.
2. Inserire il testo "Hello" all'interno del file precedentemente creato.
3. Elencare tutti i files all'interno del percorso corrente.

## Ex 4

1. Accedere alla cartella Desktop.
2. Verifica l'esistenza della cartella "esercizio" all'interno del percorso corrente: qualora la cartella NON esista procedere alla sua creazione; altrimenti stampare a video "Hello".
3. Accedere alla cartella precedentemente creata ed elencarne il contenuto (con dettagli).
4. Dichiarare la variabile "pippo" con contenuto "pluto" e stamparla a video.

## Ex 5

Nella propria home directory, creare una cartella denominata Progetti.
All'interno di Progetti, creare due file: progettoA.txt e progettoB.txt, inserendo rispettivamente i testi "Sviluppo Progetto A" e "Sviluppo Progetto B". Creare una sottocartella all'interno di Progetti chiamata Archivio.
Spostare progettoB.txt dentro Archivio.
Elencare il contenuto di Progetti mostrando i dettagli.

## Ex 6

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

Ad esempio, per memorizzare all'interno di una variabile l'esito del comando `ls` e successivamente stamparlo a video (occhio all'uso del carattere `$`):

```bash
output_ls=$(ls)
echo $output_ls
```

#### Tip 2

Il pipe, indicato dal simbolo `|`, è un operatore molto potente nei sistemi operativi  Linux che permette di dirigere l'output  di un comando come input per un altro comando.

Un esempio classico di utilizzo del pipe è il filtraggio dell'output di un comando attraverso il comando `grep`:

```bash
ls -al | grep "testo"
```

In questo esempio, l'output del comando `ls -al` , viene passato a `grep`, che filtra e mostra solo le righe che contengono la parola `testo`.

Tornando all'esercizio, potrebbe valer la pena filtrare l'output dei comandi `free` e `df -h` prima di memorizzare ciascun output all'interno di una variabile, al fine di selezionare unicamente la riga di interesse.

#### Tip 3

Adesso che potenzialmente dispongo di due variabili con il contenuto di interesse, non mi resta che applicare un ulteriore filtro.

`awk` è un potente linguaggio di programmazione utilizzato per la manipolazione dei dati in Linux. Una delle operazioni più comuni in `awk` è stampare specifiche colonne/parole/token di un testo in input. Ad esempio, il seguente script avrà come esito la stampa a video di `token-1 token-2 bla`, ovvero la prima, la seconda e la quinta parola del testo.

```bash
text="token-1 token-2 token-3 token-4 bla bla"
echo $text | awk '{print $1, $2, $5}'
```

## Ex 7

Modificare/ampliare l'esercizio precedente aggiungendo:

1. Monitoraggio dell'utilizzo della CPU. Utilizza il comando `top` per ottenere le statistiche correnti dell'uso della CPU. Filtra l'output per ottenere solo la linea che mostra l'uso della CPU, poi usa il comando `awk` per estrarre il valore percentuale dell'uso della CPU.

2. Tempo di uptime del sistema, utilizzando il comando `uptime`.

### Tips and tricks

#### Tip 1

Per recuperare dettagli sull'utilizzo di un comando all'interno della command line abbiamo 2 possibilità:

##### 1. --help

```bash
comando --help
```

Ad esempio:

```bash
uptime --help
```

##### 2. man

```bash
man comando
```

Ad esempio:

```bash
man uptime
```

All'interno di man, utlizzare le freccette direzionali (up/down) per *scrollare* il contenuto; il carattere `q` permette di uscire dalla pagina di lettura del manuale.

#### Tip 2

Monitoraggio dell'utilizzo della CPU: comando `top`. Ovviamente l'output deve essere opportunamente filtrato (grep, awk, *..altro?*).

```bash
# Nota: top -bn1 esegue top in batch mode per un'iterazione

cpu_usage=$(top -bn1)
echo $cpu_usage
```

Il valore numerico che è necessario isolare è il primo (il valore che precede *us*), che rappresenta la percentuale di utilizzo della CPU per processi utente. Questo valore indica quanto della capacità della CPU è utilizzata da processi avviati da utenti, escludendo i processi di sistema.

#### Tip 3

Il comando `uptime` mostra da quanto tempo il sistema è acceso, insieme ad altre informazioni come il numero di utenti attualmente loggati e il carico medio del sistema negli ultimi 1, 5 e 15 minuti. L'output tipico di uptime potrebbe assomigliare a questo:

```bash
uptime_info=$(uptime)
echo "Tempo di uptime del sistema: $uptime_info"
```

Anche in questo caso è necessario filtrare opportunamente l'output del comando.

#### Tip 4

Il comando `uptime` può mostrare un output più user-friendly:

```bash
uptime --pretty
```

#### Tip 5

Qualora l'output del comando `uptime` sia così articolato:

```bash
09:36:17 up 10 days, 2:00,  1 user,  load average: 0.00, 0.01, 0.05
```

potrebbe risultare complesso isolare `up 10 days`.

In questo caso `cut` può essere utile nella definizione della soluzione.

`cut -d',' -f1` specifica di usare la virgola `,` come delimitatore (con l'opzione `-d`), e di estrarre il primo campo con `-f1`.

Quindi, questo comando estrarrà la parte dell'output fino alla prima virgola, che tipicamente include l'ora corrente e da quanto tempo il sistema è acceso senza includere il numero di giorni.

```bash
uptime | cut -d',' -f1
12:14:17 up 7 days
```
