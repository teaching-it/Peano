# Introduzione allo Scripting Bash su Linux

Lo scripting Bash fornisce un potente strumento per automatizzare le attività sul sistema operativo Linux. Bash (Bourne Again SHell) è una shell di comando e un linguaggio di scripting che consente di eseguire comandi, leggere e assegnare valori alle variabili, controllare il flusso di un programma con costrutti condizionali e cicli, e molto altro.

### Hello World!

Un semplice script Bash che stampa "Hello World!" sul terminale può essere creato come segue:

```bash
#!/bin/bash
echo "Hello World!"
```

Per eseguire questo script:

1. Salvare il testo in un file, ad esempio `01_hello-world.sh`
2. Rendere lo script eseguibile con il comando `chmod +x 01_hello-world.sh`
3. Eseguirlo con `./01_hello-world.sh`

Rispetto al punto 1, come creare/salvare un file di testo direttamente da linea di comando?

**Nano** è un editor di testo leggero e facile da usare disponibile su molti sistemi Linux. 

    user@linux:~$ nano 01_hello-world.txt

Questo comando apre l'editor Nano con un nuovo file chiamato `01_hello-world.sh` all'interno del percorso corrente.

Dopo aver inserito il testo desiderato, premi `Ctrl + O` per salvare il file. Premi `Invio` per confermare il nome del file. Successivamente, premi `Ctrl + X` per uscire da Nano.zz

### Redirezione in Bash: `>` *vs* `>>`

Nel contesto dello scripting e dell'uso della shell Bash in Linux, le redirezioni `>` e `>>` sono strumenti potenti per controllare il flusso dell'output dei comandi.

#### Redirezione `>`

La redirezione `>` viene utilizzata per sovrascrivere il contenuto di un file con l'output di un comando. Se il file specificato non esiste, viene creato. Se il file esiste già, il suo contenuto precedente viene eliminato.

    echo "Hello World!" > file.txt

Questo comando scrive la stringa "Hello World!" in `file.txt`, sovrascrivendo qualsiasi contenuto esistente.

#### Redirezione `>>`

La redirezione `>>` è utilizzata per aggiungere l'output di un comando alla fine di un file esistente, mantenendo il contenuto originale. Se il file non esiste, viene creato.

    echo "Hello Italy!" >> file.txt

Questo comando aggiunge il testo "Hello Italy!" alla fine di file.txt, preservando il contenuto già presente.

### Variabili

Le variabili in Bash permettono di memorizzare e utilizzare valori. Ecco un esempio di come assegnare un valore a una variabile e stamparlo:

```bash
# !/bin/bash
msg="Hello World!"
echo $msg
```

### Costrutti Condizionali
Gli script Bash possono eseguire comandi basati su condizioni utilizzando if-else:

```bash
# !/bin/bash
num=10
if [ $num -eq 10 ]; then
    echo "Il numero è 10."
else
    echo "Il numero non è 10."
fi
```
