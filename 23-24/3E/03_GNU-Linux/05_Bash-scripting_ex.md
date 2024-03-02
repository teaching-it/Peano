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