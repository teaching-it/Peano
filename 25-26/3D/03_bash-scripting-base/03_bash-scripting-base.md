# Esercitazione n. 3 — Bash scripting su Linux Debian

## Titolo
**Creiamo ed eseguiamo semplici script Bash**

---

# Introduzione

Nelle esercitazioni precedenti abbiamo usato il terminale per creare cartelle, gestire file, scrivere testo, cercare parole e visualizzare contenuti.

Con il **Bash scripting** possiamo fare un passo in più: invece di scrivere ogni comando a mano nel terminale, possiamo salvarne una sequenza dentro un file di testo ed eseguirla quando serve.

Uno **script Bash** è quindi un file, di solito con estensione `.sh`, che contiene comandi Linux scritti in ordine. Quando lo eseguiamo, il sistema interpreta quei comandi uno dopo l'altro.

---

# Nuovi comandi e costrutti introdotti

```bash
nano
chmod +x
./nome_script.sh
#!/bin/bash
echo
read
variabili
if
then
else
fi
```

---

# Consegna per gli studenti

Apri il terminale e svolgi i seguenti passaggi.

---

## 1. Crea una cartella di lavoro

Vai nella tua home directory:

```bash
cd
```

Crea una nuova cartella:

```bash
mkdir esercitazione_3_script
```

Entra nella cartella:

```bash
cd esercitazione_3_script
```

Controlla dove ti trovi:

```bash
pwd
```

---

## 2. Crea il primo script con `nano`

Useremo l'editor di testo `nano` per creare e salvare un file `.sh`.

Esegui il comando:

```bash
nano 01_saluto.sh
```

Si aprirà l'editor `nano`.

Scrivi dentro il file:

```bash
#!/bin/bash

echo "Ciao! Questo è il mio primo script Bash."
echo "Sto imparando ad automatizzare comandi Linux."
```

Per salvare il file:

1. Premi `Ctrl + O`
2. Premi `Invio` per confermare il nome del file
3. Premi `Ctrl + X` per uscire da `nano`

Controlla che il file sia stato creato:

```bash
ls
```

---

## 3. Rendi eseguibile lo script

Un file `.sh` contiene comandi, ma per poterlo eseguire direttamente bisogna renderlo **eseguibile**.

Esegui:

```bash
chmod +x 01_saluto.sh
```

Ora avvia lo script:

```bash
./01_saluto.sh
```

Dovresti vedere sul terminale i messaggi scritti con `echo`.

### Domande

1. A cosa serve il comando `chmod +x`?
2. Perché davanti al nome dello script scriviamo `./`?
3. Che cosa stampa il comando `echo`?

---

## 4. Osserva la prima riga dello script

La prima riga:

```bash
#!/bin/bash
```

si chiama **shebang**.

Indica al sistema che lo script deve essere eseguito usando Bash.

> Attenzione: la riga corretta è `#!/bin/bash`, senza spazi tra `#` e `!`.

---

## 5. Crea uno script con una variabile

Crea un nuovo script:

```bash
nano 02_variabile.sh
```

Scrivi:

```bash
#!/bin/bash

materia="informatica"

echo "Oggi studiamo:"
echo $materia
```

Salva ed esci da `nano`.

Rendi eseguibile il file:

```bash
chmod +x 02_variabile.sh
```

Eseguilo:

```bash
./02_variabile.sh
```

### Domanda

Che cosa contiene la variabile `materia`?

---

## 6. Crea uno script che legge un dato da tastiera

Crea un nuovo file:

```bash
nano 03_nome.sh
```

Scrivi:

```bash
#!/bin/bash

echo "Come ti chiami?"
read nome

echo "Ciao $nome, benvenuto nello scripting Bash!"
```

Salva, esci, rendi eseguibile ed esegui:

```bash
chmod +x 03_nome.sh
./03_nome.sh
```

### Domande

1. A cosa serve il comando `read`?
2. Dove viene salvato il nome scritto dall'utente?
3. Perché nello script scriviamo `$nome`?

---

## 7. Introduzione a `if then else`

In Bash possiamo far eseguire comandi diversi in base a una condizione.

La struttura generale è:

```bash
if [ condizione ]; then
    comando_se_vero
else
    comando_se_falso
fi
```

Il blocco termina sempre con:

```bash
fi
```

che è `if` scritto al contrario.

---

## 8. Crea uno script con una condizione semplice

Crea il file:

```bash
nano 04_numero.sh
```

Scrivi:

```bash
#!/bin/bash

numero=10

if [ $numero -eq 10 ]; then
    echo "Il numero è uguale a 10."
else
    echo "Il numero non è uguale a 10."
fi
```

Salva, esci, rendi eseguibile ed esegui:

```bash
chmod +x 04_numero.sh
./04_numero.sh
```

### Domande

1. Che cosa significa `-eq`?
2. Che cosa succede se cambi `numero=10` in `numero=8`?
3. A cosa serve `else`?

---

## 9. Crea uno script che chiede un numero all'utente

Crea il file:

```bash
nano 05_controllo_numero.sh
```

Scrivi:

```bash
#!/bin/bash

echo "Inserisci un numero:"
read numero

if [ $numero -gt 0 ]; then
    echo "Il numero è positivo."
else
    echo "Il numero è zero oppure negativo."
fi
```

Salva, esci, rendi eseguibile ed esegui:

```bash
chmod +x 05_controllo_numero.sh
./05_controllo_numero.sh
```

Prova a inserire numeri diversi.

### Domande

1. Che cosa significa `-gt`?
2. Che risposta ottieni inserendo `5`?
3. Che risposta ottieni inserendo `-3`?

---

## 10. Confronti numerici utili

In Bash, per confrontare numeri interi dentro `[ ]`, si usano spesso questi operatori:

```text
-eq  uguale
-ne  diverso
-gt  maggiore di
-lt  minore di
-ge  maggiore o uguale
-le  minore o uguale
```

Esempio:

```bash
if [ $eta -ge 18 ]; then
    echo "Maggiorenne"
else
    echo "Minorenne"
fi
```

---

## 11. Crea uno script con una condizione su una parola

Crea il file:

```bash
nano 06_password.sh
```

Scrivi:

```bash
#!/bin/bash

echo "Inserisci la password:"
read password

if [ "$password" = "linux" ]; then
    echo "Accesso consentito."
else
    echo "Accesso negato."
fi
```

Salva, esci, rendi eseguibile ed esegui:

```bash
chmod +x 06_password.sh
./06_password.sh
```

### Domande

1. Qual è la password corretta nello script?
2. Che cosa succede se scrivi una parola diversa?
3. Perché la variabile `$password` è scritta tra virgolette?

---

## 12. Controlla se un file esiste

Crea prima un file di prova:

```bash
touch appunti.txt
```

Poi crea lo script:

```bash
nano 07_controlla_file.sh
```

Scrivi:

```bash
#!/bin/bash

if [ -f appunti.txt ]; then
    echo "Il file appunti.txt esiste."
else
    echo "Il file appunti.txt non esiste."
fi
```

Salva, esci, rendi eseguibile ed esegui:

```bash
chmod +x 07_controlla_file.sh
./07_controlla_file.sh
```

Ora elimina il file:

```bash
rm appunti.txt
```

Esegui di nuovo lo script:

```bash
./07_controlla_file.sh
```

### Domanda

Che cosa cambia dopo aver eliminato `appunti.txt`?

---

# Riepilogo

Uno script Bash di base segue spesso questi passaggi:

```bash
#!/bin/bash

# comandi
echo "Messaggio"

# variabile
nome="Mario"
echo $nome

# input
read risposta

# condizione
if [ "$risposta" = "si" ]; then
    echo "Hai risposto sì."
else
    echo "Hai risposto no."
fi
```

---

# Sfida facoltativa

Crea uno script chiamato:

```bash
08_menu.sh
```

Lo script deve:

1. Chiedere il nome dell'utente
2. Mostrare un piccolo menu con due opzioni
3. Leggere la scelta dell'utente
4. Stampare un messaggio diverso in base alla scelta

Esempio di avvio:

```text
Come ti chiami?
Mario

Scegli un'opzione:
1 - Saluto
2 - Informazioni
```

Suggerimento:

```bash
#!/bin/bash

echo "Come ti chiami?"
read nome

echo "Scegli un'opzione:"
echo "1 - Saluto"
echo "2 - Informazioni"
read scelta

if [ "$scelta" = "1" ]; then
    echo "Ciao $nome!"
else
    echo "Stai usando uno script Bash."
fi
```