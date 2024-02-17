# CLI Linux Debian (base)

    user@linux:~$

Questo prompt indica che l'utente `user` è loggato sul sistema `linux` e si trova nella sua home directory, rappresentata dal simbolo `~`. Il simbolo `$` suggerisce che si tratta di un utente standard (non privilegiato). La home directory è lo spazio personale dell'utente sul sistema, utilizzato per memorizzare file personali, documenti, configurazioni di sistema e altro.

    user@linux:/tmp$

Questo prompt indica che l'utente corrente, identificato come `user`, è loggato su un sistema con nome `linux` e si trova nella directory `/tmp`. La presenza del simbolo `$` alla fine del prompt suggerisce che si tratta di una sessione utente standard, non di root. La directory `/tmp` è comunemente utilizzata per memorizzare file temporanei che possono essere necessari durante l'esecuzione di programmi o script.

    user@linux:~$ pwd

**`pwd`** stampa il percorso della directory corrente. All'avvio del terminale, in genere l'utente si trova nella propria home directory `/home/user`.

    user@linux:~$ id

**`id`** mostra l'ID utente (uid), l'ID gruppo (gid) e i gruppi ai quali l'utente appartiene.

    user@linux:~$ su
    Password:
    root@linux:/home/user#

 **`su`** (substitute user) permette di cambiare l'identità utente; senza argomenti, passa all'utente root. Dopo l'inserimento della password, il prompt cambia per indicare che ora sei root.

    root@linux:/home/user# id

**`id`** eseguito come root mostra che l'uid e il gid sono 0, che corrispondono all'utente root, con pieni privilegi sul sistema.

    root@linux:/home/user# apt-get update

**`apt-get update`** aggiorna l'indice dei pacchetti e delle versioni disponibili dai repository configurati. Questo è essenziale per assicurarsi che gli aggiornamenti dei pacchetti siano all'ultima versione disponibile.

    root@linux:/home/user# apt-get install nome_del_pacchetto

**`apt-get install nome_del_pacchetto`** installa un nuovo pacchetto. Sostituisci `nome_del_pacchetto` con il nome effettivo del software che desideri installare. Questo comando necessita dei permessi di root per essere eseguito, motivo per cui è stato preceduto da `su`.

Ricorda che, quando si installa un pacchetto software su Linux, spesso ha bisogno di altre librerie o programmi per funzionare. Linux semplifica questo processo attraverso un sistema automatico che identifica, reperisce e installa queste "dipendenze" in maniera automatica, evitando l'oneroso compito di doverle cercare e installare manualmente.

    root@linux:/home/user# exit
    exit
    user@linux:~$

**`exit`** termina la sessione dell'utente corrente o esce dalla shell. Se eseguito come root dopo `su`, ti riporta all'utente normale.

    user@linux:/tmp$ cd /home/nomeutente

Questo comando conduce alla directory specificata, in questo caso `/home/nomeutente`. Il percorso è espresso in termini *assoluti*, ovvero a partire dalla directory radice `/`.

    user@linux:~$ cd Desktop
    
Il comando permette di accede alla directory Desktop contenuta nel percorso corrente. In questo caso, il percorso è espresso in termini *relativi*, partendo dalla directory in cui ci si trova (ovvero la home directory dell'utente corrente, identificata dal simbolo `~`)

    user@linux:~/Desktop$ cd ..

Con `cd ..`, si risale alla directory superiore, ovvero se si parte da `/home/nomeutente/Desktop`, si verrà portati a `/home/nomeutente`. Eseguire `cd ..` in `/home/nomeutente` porta a `/home`, che è la directory genitore delle home degli utenti.

    user@linux:~$ ls

Elenca i file e le directory nella home directory dell'utente corrente. Il comando mostra solo i nomi dei file e delle directory, senza fornire dettagli aggiuntivi come dimensioni, permessi o date di modifica.

    user@linux:~$ ls -al

Il comando `ls -al` estende la funzionalità di `ls`, fornendo un elenco dettagliato (opzione `-l`) di tutti i file e le directory, inclusi quelli nascosti (opzione `-a`). Questo elenco include informazioni come i permessi di accesso, il numero di link, il proprietario, il gruppo, la dimensione dei file, e la data e l'ora dell'ultima modifica.

    user@linux:~$ cat file.txt

Il comando `cat` (abbreviazione di *concatenate*) è utilizzato in Linux per visualizzare il contenuto di uno o più file.

    user@linux:~$ touch file.txt

`touch` è comunemente usato per creare rapidamente un nuovo file vuoto. Il comando creare un file denominato `file.txt` all'interno del percorso corrente.

    user@linux:~$ cp file.txt /tmp

Il comando permette di copiare il file `file.txt` in un'altra directory (`/tmp` in questo caso).

    user@linux:~$ cp -r dir /tmp

Affinché sia possibile copiare un'intera directory è necessario utilizzare l'opzione `/-r`. Il comando copierà la cartella `dir` (posizionata nel percorso corrente) all'interno della cartella `/tmp`.

### Breve inciso sull'organizzazione del File System in Linux

L'organizzazione del file system in Linux segue una struttura gerarchica, iniziando dalla directory radice **/**. Questa struttura permette di organizzare e separare i file in diverse directory per una gestione più intuitiva e sicura del sistema. Alcune delle directory più comuni includono:

- **`/bin`**: Contiene eseguibili essenziali per l'uso dei comandi di base da parte degli utenti e dello stesso sistema operativo.
- **`/etc`**: Ospita file di configurazione del sistema.
- **`/home`**: Directory dove si trovano le home directory di tutti gli utenti normali, fornendo uno spazio personale per file, documenti, e configurazioni.
- **`/usr`**: Include programmi e dati utilizzati dagli utenti, suddivisi in ulteriori sottodirectory come `bin`, `lib`, e `share`.
- **`/var`**: Destinata a file variabili come log di sistema, database, e file temporanei.
- **`/tmp`**: Contiene file temporanei creati dagli utenti o dal sistema.