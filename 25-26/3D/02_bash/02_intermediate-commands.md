# Esercitazione n. 2 — Linux Debian da riga di comando

## Titolo
**Gestione di file, cartelle e ricerca da terminale**

---

# Nuovi comandi introdotti

```bash
tree
ls -l
ls -a
echo >>
head
tail
grep
find
wc
clear
```

> Se il comando `tree` non è disponibile, si può usare `ls -R`, oppure è possibile installarlo.

---

# Consegna per gli studenti

## 1. Crea una nuova cartella di lavoro

Vai nella tua home directory:

```bash
cd
```

Crea una nuova cartella:

```bash
mkdir esercitazione_2_linux
```

Entra nella cartella:

```bash
cd esercitazione_2_linux
```

Controlla dove ti trovi:

```bash
pwd
```

---

## 2. Crea una struttura di cartelle

Crea le seguenti cartelle:

```bash
mkdir scuola documenti immagini backup
```

Dentro `scuola`, crea tre sottocartelle:

```bash
mkdir scuola/italiano scuola/informatica scuola/matematica
```

Controlla la struttura:

```bash
ls -R
```

Oppure, se disponibile:

```bash
tree
```

---

## 3. Crea file di testo

Crea tre file:

```bash
touch scuola/informatica/comandi.txt
touch scuola/italiano/appunti.txt
touch scuola/matematica/esercizi.txt
```

Scrivi una prima riga nel file `comandi.txt`:

```bash
echo "Il comando pwd mostra la cartella corrente." > scuola/informatica/comandi.txt
```

Aggiungi altre righe senza cancellare la precedente:

```bash
echo "Il comando ls mostra il contenuto di una cartella." >> scuola/informatica/comandi.txt
echo "Il comando mkdir crea una nuova cartella." >> scuola/informatica/comandi.txt
echo "Il comando cat mostra il contenuto di un file." >> scuola/informatica/comandi.txt
```

---

## 4. Visualizza il contenuto del file

Mostra tutto il contenuto:

```bash
cat scuola/informatica/comandi.txt
```

Mostra solo le prime righe:

```bash
head scuola/informatica/comandi.txt
```

Mostra solo le ultime righe:

```bash
tail scuola/informatica/comandi.txt
```

---

## 5. Usa `ls` con opzioni

Visualizza i file in formato dettagliato:

```bash
ls -l scuola/informatica
```

Visualizza anche eventuali file nascosti:

```bash
ls -a scuola/informatica
```

### Domanda

Quale differenza noti tra `ls`, `ls -l` e `ls -a`?

---

## 6. Cerca una parola dentro un file

Cerca la parola `mkdir` nel file `comandi.txt`:

```bash
grep mkdir scuola/informatica/comandi.txt
```

Cerca la parola `comando`:

```bash
grep comando scuola/informatica/comandi.txt
```

### Domanda

Che cosa restituisce il comando `grep`?

---

## 7. Conta righe, parole e caratteri

Usa il comando:

```bash
wc scuola/informatica/comandi.txt
```

Poi prova:

```bash
wc -l scuola/informatica/comandi.txt
wc -w scuola/informatica/comandi.txt
wc -c scuola/informatica/comandi.txt
```

### Domande

1. Che cosa indica `wc -l`?
2. Che cosa indica `wc -w`?
3. Che cosa indica `wc -c`?

---

## 8. Cerca file nel progetto

Cerca tutti i file `.txt`:

```bash
find . -name "*.txt"
```

Cerca il file `comandi.txt`:

```bash
find . -name "comandi.txt"
```

### Domanda

A cosa serve il punto `.` nel comando `find`?

---

## 9. Copia la cartella di informatica nel backup

Copia la cartella `informatica` dentro `backup`:

```bash
cp -r scuola/informatica backup/
```

Controlla il risultato:

```bash
ls -R backup
```

### Domanda

Perché in questo caso serve l’opzione `-r`?

---

## 10. Rinomina un file nel backup

Rinomina il file copiato:

```bash
mv backup/informatica/comandi.txt backup/informatica/comandi_backup.txt
```

Controlla:

```bash
ls backup/informatica
```

---

# Domande finali

Rispondi sul quaderno o in un file di testo.

1. Qual è la differenza tra `>` e `>>`?
2. A cosa serve il comando `grep`?
3. A cosa serve il comando `find`?
4. Che cosa fa il comando `wc`?
5. Perché per copiare una cartella si usa `cp -r`?
6. Quale comando useresti per cercare tutti i file `.txt`?

---

# Sfida facoltativa

Crea un file chiamato:

```bash
scuola/informatica/riepilogo.txt
```

Dentro il file scrivi almeno 5 righe, ognuna con un comando Linux e la sua funzione.

Esempio:

```text
pwd - mostra la cartella corrente
ls - mostra il contenuto di una cartella
cd - permette di cambiare cartella
mkdir - crea una nuova cartella
rm - elimina un file
```

Poi usa:

```bash
grep cartella scuola/informatica/riepilogo.txt
```

e spiega il risultato ottenuto.
