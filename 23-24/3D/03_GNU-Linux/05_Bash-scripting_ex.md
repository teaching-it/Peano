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

### Una possibile soluzione (svolta in classe in data 09/03/24, aggiornata il 15/03/24)

```bash
# !/bin/bash

# Il comando free mostra il quantitativo di memoria RAM usata e disponibile

# Comando originale
free --mega

# Salva l'output del comando free --mega all'interno della variabile output_cmd

# output_cmd=$(free --mega)
# echo $output_cmd

# Filtra l'output del comando rispetto ad una determinata keyword

echo
free --mega | grep "Mem"

# Di nuovo il comando precedente, ma con l'aggiunta di un ulteriore elemento alla "pipeline": awk seleziona e visualizza oil 4° token della stringa di testo

echo
free --mega | grep "Mem" | awk '{print $4}'

# Posso adesso inserire l'intero comando di outout all'interno di una variabile
mem_value=$(free --mega | grep "Mem" | awk '{print $4}')

echo
echo "Il quantitativo di memoria RAM disponibile è (in MB): $mem_value"

# Comando per lo spazio su disco disponibile nella partizione /
disk_space=$(df -h / | grep "/" | awk '{print $4}')

echo
echo "Lo spazio su disco disponibile nella partizione / è (in MB): $disk_space"
```

## Ex 5

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

## Ex 6

Modificare/ampliare l'esercizio precedente aggiungendo un sistema di *alert* qualora le risorse del sistema superino una determinata soglia di utilizzo.

### Tips and tricks

#### Tip 1

Innanzitutto, ricorda che possiamo valorizzare variabili con l'output generato da un comando. Ad esempio:

```bash
mem_usage=$(free --mega | grep "Mem" | awk '{print $4}')
```

#### Tip 2

Come hai giustamente intuito dobbiamo scomodare l'istruzione condizione `if`.

Ad esempio:

```bash
if [$mem_usage -lt 100]; then
    echo "ATTENZIONE! La memoria RAM disponibile è inferiore a 100M!"
fi```
```

Più nel dettaglio, per utilizzare le istruzioni condizionali in Bash che confrontano si utilizzano gli operatori di confronto come `-gt`(greater than, maggiore di), `-lt` (less than, minore di), e `-eq` (equals, uguale a). Questi confronti sono utilizzati principalmente per numeri interi. Ecco una breve sintassi per ciascuno:

```bash
# Dichiarazione di due variabili
a=5
b=10

# Esecuzione dei confronti

# Greather than
if [ $a -gt $b ]; then
    echo "$a è maggiore di $b"
fi

# Less than
if [ $a -lt $b ]; then
    echo "$a è minore di $b"
fi

# Equals
if [ $a -eq $b ]; then
    echo "$a è uguale a $b"
fi

# Non equals
if [ $a -ne $b ]; then
    echo "$a non è uguale a $b"
fi

# Greather or equals
if [ $a -ge $b ]; then
    echo "$a è maggiore o uguale a $b"
fi

# Less or equals
if [ $a -le $b ]; then
     echo "$a è minore o uguale a $b"
fi
```

## Ex 7

Completa l'esercizio precedente migliorando la formattazione dell'output.

### Tips and tricks

#### Tip 1

In Bash Script è possibile modificare il colore di output del testo visualizzato con il comando `echo`:

```bash
# Dichiarazione di costanti contenenti colori
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo -e "${GREEN}Hello World${NC}"
```

#### Tip 2

Inoltre, è possibile utilizzare semplici funzioni da utilizzare come *shortcut* per la stampa a video di testo formattato; ad esempio:

```bash
# Funzione per stampare i titoli
print_title() {
    echo -e "${GREEN}$1${NC}"
}

# Funzione per stampare il testo normale
print_info() {
    echo -e "${RED}$1${NC}"
}
```

### Tip 1+2

Mettendo assieme entrambi i *tips*, ecco un possibile output:

```bash
# Header dello script
echo -e "${GREEN}======================================${NC}"
echo -e "${GREEN} Report sulle risorse di sistema ${NC}"
echo -e "${GREEN}======================================${NC}\n"

# Memoria RAM disponibile
mem_value=$(free --mega | grep "Mem" | awk '{print $4}')
print_title "Memoria RAM Disponibile:"
print_info "$mem_value MB"

# TO BE CONTINUED...
```
