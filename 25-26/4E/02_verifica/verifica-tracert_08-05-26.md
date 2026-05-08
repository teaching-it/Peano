# Verifica pratica di laboratorio – 4E Inf – 08/05/2026

Apri il prompt dei comandi ed esegui i seguenti comandi:

```cmd id="hp0nka"
tracert english.wuhan.gov.cn
```

Produci uno **screenshot leggibile** degli output e rispondi alle domande seguenti.

---

# Esercizio 1 – Domande di base

**1.1** Spiega che cosa restituisce il comando `tracert` e quale informazione permette di ricostruire (NB: ti è richiesto di spiegare **cosa** fa, **non come** lo fa).

**1.2** Quanti hop compaiono nel tuo tracciato? Indica anche qual è l’ultimo hop che ha risposto correttamente.

**1.3** Perché in ogni riga del `tracert` compaiono normalmente tre valori di tempo? Che cosa rappresentano?

**1.4** Osserva il primo hop. Riporta il suo indirizzo IP e stabilisci se si tratta di un indirizzo privato o pubblico e motiva la risposta.

---

# Esercizio 2 – Funzionamento di tracert

**2.1** Spiega il ruolo del campo **TTL** nel funzionamento di `tracert` (NB: bene, adesso concentrati su **come** funziona tracert).

**2.2** Con quale valore di TTL iniziale viene inviato il pacchetto che permette di individuare l’hop n. 7? Motiva la risposta.

**2.3** Se un pacchetto raggiunge un router con TTL pari a 1, che cosa succede?

---

# Esercizio 3 – Percorso

**3.1** Secondo te il percorso attraversa una sola rete (un unico Autonomous System) oppure più reti differenti? Motiva la risposta usando usando alcuni indizi presenti nel tracciato.

**4.2** Individua il primo hop che, secondo te, appartiene al 2° AS attraversato dai datagrammi IP.

**4.3** Osservando nomi host e indirizzi IP, riesci a individuare un possibile passaggio da un provider/rete a un altro? Indica la zona del tracciato in cui avviene e motiva brevemente.

---

# Esercizio 4 – Risposte mancanti e timeout

Nel tuo output possono comparire righe come:

```text id="xejl9u"
* * *
Request timed out
```

oppure uno o due asterischi nella stessa riga.

**4.1** Riporta gli hop in cui compaiono uno o più asterischi.

**4.2** Qual è la differenza tra una riga con tre asterischi e una riga con un solo asterisco?

**4.3** L’assenza di risposta da parte di un hop significa necessariamente che quel router sia spento o non funzionante? Spiega una possibile causa tecnica.

**4.4** Se dopo un hop con `Request timed out` gli hop successivi continuano a rispondere, che conclusione puoi trarre sulla raggiungibilità della destinazione?

---

# Esercizio 5 – Analisi della latenza

Osserva i tempi RTT presenti nel tracciato.

**5.1** Individua un tratto iniziale del percorso in cui i tempi sono bassi o comunque abbastanza stabili. 

**5.2** Individua il punto in cui si verifica il salto di latenza più evidente. Indica:

- hop prima del salto;
- hop dopo il salto;
- valori RTT prima e dopo;
- possibile spiegazione tecnica.

**5.3** Secondo te l’aumento di latenza è più probabilmente dovuto a congestione, distanza geografica, cambio di rete/provider oppure a un insieme di fattori? Motiva brevemente.
