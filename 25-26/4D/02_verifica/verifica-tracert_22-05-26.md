# Verifica pratica di laboratorio – 4D Inf - 22/04/2026

## Analisi guidata dell’esito di `tracert`

Apri il prompt dei comandi ed esegui i seguenti comandi:

```cmd
tracert www.nossalhs.vic.edu.au
ping www.nossalhs.vic.edu.au
```

Produci uno **screenshot** degli output e rispondi alle domande seguenti.

## Esercizio 1: domande di base

**1.1** Che cosa rappresenta un **hop** nell’output di `tracert`?

**1.2** Trascrivi l'indirizzo IP del primo hop; indica se appartiene alla **rete locale** oppure a una **rete pubblica** e perché.

**1.3** Nel `tracert`, con quale valore di **TTL iniziale** viene inviato il pacchetto che permette di individuare l’**hop 10**? Spiega brevemente il motivo.

---

## Esercizio 2: significatività hostname

Nell'output possono comparire IP numerici oppure nomi host.

**2.1** Riporta almeno due hop in cui compare un nome host significativo. Per ciascuno indica quali informazioni puoi ricavare direttamente dal nome, ad esempio:

- possibile località
- possibile rete / organizzazione / provider

**2.2** In generale, secondo te il percorso attraversa una sola rete oppure più reti/AS differenti? Motiva brevemente senza interrogare RIPE Database (whois).

---

## Esercizio 3: risposte mancanti nel tracciato

Nel tuo output compaiono righe come queste?

- `* * *`
- `Request timed out`

**3.1** Indica in quale o quali hop il `tracert` non riceve risposta.

**3.2** L’assenza di risposta da uno o più hop implica necessariamente che la destinazione non sia raggiungibile? Motiva brevemente con una possibile spiegazione tecnica.

---

## Esercizio 4: analisi latenza/RTT

Osserva con attenzione i tempi RTT lungo il percorso: è possibile osservare una parte iniziale del percorso con RTT più bassi e una parte successiva con RTT molto più alti.

**4.1** Individua e riporta chiaramente un tratto iniziale in cui i tempi sono relativamente bassi o comunque più contenuti.

**4.2** Individua il punto del tracciato in cui compare il salto di latenza più significativo. Indica l’hop o la zona del percorso interessata e descrivi che cosa osservi prima e dopo questo punto.

**4.3** Il tuo output mostra soprattutto una crescita graduale della latenza oppure uno o più salti improvvisi? Motiva la risposta con riferimento ad almeno un hop e formula una breve ipotesi tecnica sul possibile motivo dell’aumento di latenza, in particolare nella parte finale del percorso.

---

## Esercizio 5: ping *vs* tracert

**5.1** Scrivi il tempo medio del `ping` verso `www.nossalhs.vic.edu.au` e confrontalo con l’ultimo hop del `tracert` che ha risposto.

**5.2** I due valori sono coerenti tra loro? Scrivi una breve conclusione.

**5.3** Supponiamo la seguente casistica: l’ultimo host del `tracert` non risponde sempre oppure mostra uno o più `*`, ma il `ping` risponde; come interpreti questa situazione?

---

## Esercizio 6: RIPE Database (whois)

Scegli **2 IP pubblici** del tuo traceroute:

- il **primo IP pubblico**
- un altro IP pubblico collocato **più avanti nel percorso**, preferibilmente vicino al salto di latenza oppure nella parte finale del tracciato

Per ciascun IP, usa il **RIPE Database (whois)** e compila la tabella.

| Hop | IP pubblico | AS number | Organizzazione / rete | Osservazione |
|---|---|---|---|---|
| | | | | |
| | | | | |

Poi rispondi.

**6.1** I due IP appartengono allo stesso AS oppure a AS diversi?

**6.2** Confronta i due punti del percorso dal punto di vista della latenza e spiega brevemente se il cambio di AS può bastare, da solo, a giustificare con certezza l’eventuale salto osservato.
