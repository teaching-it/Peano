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
