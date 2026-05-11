# Attività semplice su Command Line Linux Debian

## Titolo
**Organizziamo una cartella scolastica da terminale**

## Comandi utilizzati

```bash
pwd
ls
cd
mkdir
touch
echo
cat
cp
mv
rm
```

---

# Consegna per gli studenti

Apri il terminale e svolgi i seguenti passaggi.

---

## 1. Scopri dove ti trovi

Esegui il comando:

```bash
pwd
```

Poi visualizza il contenuto della cartella corrente:

```bash
ls
```

### Domanda
Che cosa mostra il comando `pwd`?

---

## 2. Crea una cartella per l'attività

Crea una nuova cartella:

```bash
mkdir attivita_linux
```

Entra nella cartella appena creata:

```bash
cd attivita_linux
```

Controlla di essere nella cartella corretta:

```bash
pwd
```

---

## 3. Crea alcune sottocartelle

Crea tre cartelle, una per ogni materia:

```bash
mkdir italiano matematica informatica
```

Visualizza il contenuto della cartella:

```bash
ls
```

Dovresti vedere:

```text
italiano  matematica  informatica
```

---

## 4. Crea un file di appunti

Crea un file vuoto nella cartella `informatica`:

```bash
touch informatica/appunti.txt
```

Scrivi una frase dentro il file:

```bash
echo "Oggi abbiamo imparato alcuni comandi Linux." > informatica/appunti.txt
```

Leggi il contenuto del file:

```bash
cat informatica/appunti.txt
```

---

## 5. Copia il file

Copia il file `appunti.txt` creando una copia chiamata `copia_appunti.txt`:

```bash
cp informatica/appunti.txt informatica/copia_appunti.txt
```

Controlla i file presenti nella cartella `informatica`:

```bash
ls informatica
```

---

## 6. Rinomina un file

Rinomina il file `copia_appunti.txt` in `appunti_backup.txt`:

```bash
mv informatica/copia_appunti.txt informatica/appunti_backup.txt
```

Controlla di nuovo il contenuto della cartella:

```bash
ls informatica
```

---

## 7. Sposta un file in un'altra cartella

Sposta il file `appunti_backup.txt` nella cartella `italiano`:

```bash
mv informatica/appunti_backup.txt italiano/
```

Controlla il contenuto della cartella `italiano`:

```bash
ls italiano
```

---

## 8. Elimina il file spostato

Elimina il file `appunti_backup.txt` dalla cartella `italiano`:

```bash
rm italiano/appunti_backup.txt
```

Controlla che il file sia stato eliminato:

```bash
ls italiano
```

> Attenzione: il comando `rm` elimina i file. Usalo con cura.

---

# Domande finali

Rispondi alle seguenti domande:

1. A cosa serve il comando `pwd`?
2. Qual è la differenza tra `cp` e `mv`?
3. Che cosa fa il comando `mkdir`?
4. A cosa serve il comando `cat`?
5. Perché bisogna fare attenzione con il comando `rm`?

---

# Estensione facoltativa

Crea una struttura di cartelle simile a questa:

```text
scuola/
├── italiano/
├── matematica/
├── informatica/
│   ├── teoria.txt
│   └── esercizi.txt
└── inglese/
```

Poi scrivi almeno una frase dentro ogni file `.txt`.

---

# Sfida extra

Usa il comando:

```bash
ls -R
```

per visualizzare tutte le cartelle e i file creati durante l'attività.

### Domanda
Che differenza noti tra `ls` e `ls -R`?
