# CLI Linux Debian (base)

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

