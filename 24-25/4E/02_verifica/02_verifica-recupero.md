# Verifica Sistemi e Reti - Classe IVE Informatico - Recupero

## Esercizio 1 [30 punti]: esecuzione e analisi output comando `ping`

Dal prompt dei comandi di Windows, esegui il seguente comando:

```batch
ping 8.8.8.8
```

**Domande:**

1. **[12 punti]**  
   Descrivi brevemente il funzionamento del comando `ping`, il protocollo utilizzato, il processo di incapsulamento/decapsulamento che coinvolge il messaggio.

2. **[8 punti]**  
   Quali informazioni puoi estrarre dall'output del comando? Commenta quelle più significative.

3. **[10 punti]**  
   Esegui un ping verso l'indirizzo IP privato del gateway della tua rete locale.  
   - Confronta i tempi di risposta rispetto a quelli dell’indirizzo pubblico `8.8.8.8`.  
   - Spiega quali fattori influenzano la differenza di latenza tra rete locale e rete esterna.  

---

## Esercizio 2 [35 punti]: esecuzione e analisi output comando `tracert`

Dal prompt dei comandi di Windows, esegui il seguente comando:

```batch
tracert google.it
```

**Domande:**

1. **[15 punti]**  
   Descrivi brevemente il funzionamento del comando `tracert`.

2. **[10 punti]**  
   Supponiamo che il comando `tracert` stia dialogando con il 3° hop. Riporta gli attributi fondamentali del datagramma IP prodotto da tale hop in cui è incapsulato il messaggio ICMP "Time Exceeded".

3. **[10 punti]**  
   Analizza un punto del tracciato `tracert` in cui si nota un aumento significativo della latenza rispetto agli hop precedenti:  
   - Quali potrebbero essere le cause di questo incremento improvviso?  
   - Spiega come si potrebbero eseguire ulteriori analisi per individuare la causa del problema.  

---

## Esercizio 3 [35 punti]: rappresentazione in Cisco Packet Tracer

Dall'output del comando `tracert google.it` ottenuto nell'Esercizio 2, seleziona:  

- L'**host sorgente** (PC locale).  
- I **primi 3 router** visualizzati nel tracciato.  

### Obiettivi  

1. **[10 punti]** Realizza uno schema di rete in **Cisco Packet Tracer** rappresentando correttamente l'host sorgente e i primi 3 router.  
   - Configura l'indirizzo IP dell'host sorgente.  
   - Inserisci correttamente i router in base alla topologia osservata.  

2. **[10 punti]** Assegna gli indirizzi IP alle interfacce dei router in base all'output del comando `tracert`.  
   - Non è necessario assegnare l'indirizzo IP anche alla seconda interfaccia coinvolta nel collegamento Point-to-Point.
   - Fai attenzione a utilizzare gli stessi indirizzi IP che hai visualizzato nell'output.

3. **[15 punti]** Definisci le rotte statiche sui router per garantire la raggiungibilità dell'indirizzo IP di destinazione (indirizzo IP di **google.it**).  
   - Nota: Il comando `tracert google.it` fornisce l'indirizzo IP di destinazione. Usa questo valore per configurare correttamente le rotte statiche.  

---

## Consegna finale della verifica [eventuali penalità fino a -5 punti]

Al termine dell'esercizio, procedi alla consegna nel seguente modo:

- Produci un documento di testo (`.docx`, `.odt` o `.pdf`) contenente:
  - il risultato completo (screenshot) dei comandi `ping` e `tracert` eseguiti.
  - le risposte chiare e numerate alle domande poste.
  - il file **Cisco Packet Tracer** (`.pkt`) con lo schema di rete configurato.

- Inserisci i file in una cartella denominata `Cognome-Nome`. Comprimi la cartella generando un unico archivio ZIP denominato `Cognome-Nome.zip`.

**Buon lavoro!**

---

## Valutazione

### Esercizio 1 [30 punti]: esecuzione e analisi output comando `ping`

| Domanda | Punteggio |
|--------|-----------|
| 1      | 12 punti   |
| 2      | 8 punti    |
| 3      | 10 punti   |
| **Totale** | **30 punti** |

### Esercizio 2 [35 punti]: esecuzione e analisi output comando `tracert`

| Domanda | Punteggio |
|--------|-----------|
| 1      | 15 punti   |
| 2      | 10 punti   |
| 3      | 10 punti   |
| **Totale** | **35 punti** |

### Esercizio 3 [35 punti]: rappresentazione in Cisco Packet Tracer

| Descrizione | Punteggio |
|------------|-----------|
| Rappresentazione dell'host sorgente e dei primi 3 router | 10 punti |
| Configurazione corretta degli indirizzi IP delle interfacce | 10 punti |
| Definizione corretta delle rotte statiche | 15 punti |
| **Totale** | **35 punti** |

### Penalità sulla consegna (max -5 punti)

| Descrizione | Penalità |
|------------|----------|
| Mancato rispetto delle prescrizioni di consegna (formato file, denominazione archivio ZIP, ecc.) | fino a -5 punti |
