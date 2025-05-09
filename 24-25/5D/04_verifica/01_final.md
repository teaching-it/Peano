# Verifica di Laboratorio – Sistemi e Reti - 09/05/2025

## Esercizio 1: analisi del traffico ARP

1. Apri un terminale e diventa utente privilegiato.

2. Visualizza le interfacce di rete disponibili e prendi nota:  
   - del **nome dell’interfaccia di rete attiva**  
   - del **tuo IP locale**

3. Visualizza la tabella ARP corrente del tuo sistema con il comando ``arp -a``, sincerandoti che non esista alcuna corrispondenza per l'indirizzo IP ``10.0.22.253``.

4. Avvia il comando ``tcpdump`` per intercettare solo le richieste ARP originate dal tuo host:
   ``tcpdump -i nome-interfaccia arp and src host IP-locale``

5. In un’altra finestra, esegui il comando ``ping -c 4 10.0.22.253``

6. Analizza:
   - La richiesta ARP (``Request who-has...``)
   - L’eventuale risposta ARP (``Reply...is at``)
   - Quali MAC address sono coinvolti
   - Il ruolo dell’ARP nella risoluzione degli indirizzi IP

7. Dopo la comunicazione, esegui nuovamente ``arp -a``  
   per **verificare che l’indirizzo IP pingato sia ora presente nella tabella** con il MAC associato. È coerente con quanto intercettato con tcpdump?

8. Inserisci **screenshot** significativi e il risultato del comando ``arp -a`` prima e dopo il ping.

## Esercizio 2: scansione di un host remoto esposto

1. Utilizza l’host ``scanme.nmap.org`` messo a disposizione dal sito ufficiale di Nmap per scopi didattici e di test.  
   IP associato: ``45.33.32.156``

2. Lancia una **scansione completa** dell’host remoto con il comando:
   ``nmap -sS -sV -O 45.33.32.156``

3. Analizza e commenta in modo completo l’output della scansione.  
   In particolare:
   - Elenca e descrivi le **porte aperte** e i relativi **servizi rilevati**
   - Riporta il **sistema operativo stimato**
   - Specifica i **protocolli e i livelli della pila OSI** coinvolti
   - Per ciascun servizio individuato, spiega brevemente a cosa serve, dove si usa e se può presentare **criticità o rischi di sicurezza**
   - Rifletti sul significato di queste informazioni sia dal punto di vista di un **amministratore di rete**, sia di un **potenziale attaccante**
   - **Inserisci almeno uno screenshot** significativo dell’output ottenuto

## Esercizio 3: analisi del traffico HTTP

1. Assicurati che il tool ``curl`` sia installato nel sistema. In caso contrario, installalo con il comando:
   ``apt-get install curl``

2. Avvia **Wireshark** e, dopo esserti messo in ascolto sull'interfaccia opportuna, imposta il filtro di cattura:
   ``http``

3. In un terminale, esegui la seguente richiesta HTTP:
   ``curl http://example.com``

4. Analizza attentamente la comunicazione HTTP intercettata da Wireshark.  
   Commenta:
   - Il **metodo** HTTP utilizzato (es. ``GET``, ``POST``)
   - Gli **header** principali e il **corpo** del messaggio (se presente)
   - Il **codice di stato** restituito dal server (es. ``200 OK``, ``404 Not Found``)
   - I **layer coinvolti** nella comunicazione (Applicazione, Trasporto, Rete, Collegamento dati) e i rispettivi **PDU** (es. HTTP message, Segmento TCP, Pacchetto IP, Frame Ethernet)
   - **Inserisci almeno uno screenshot** significativo che evidenzi la comunicazione HTTP e i dettagli analizzati.

## Esercizio 4: traceroute e analisi dei router intermedi

1. Dal terminale, esegui il comando:
   ``traceroute example.com``

2. In parallelo, avvia **Wireshark** e imposta il filtro di cattura:
   ``icmp``

3. Osserva il comportamento del TTL (Time To Live) e analizza le risposte ICMP di tipo **"Time Exceeded"** generate dai router intermedi lungo il percorso.

4. Commenta:
   - **Quanti router** hai attraversato prima di raggiungere ``example.com``
   - **Dove si trova il primo punto di uscita** dalla rete locale (es. dopo quanti hop o quale indirizzo IP rappresenta la transizione)
   - **Cosa accade se un router non risponde**: come viene visualizzato nel risultato di `traceroute` e come si comporta Wireshark

5. **Inserisci uno o più screenshot** significativi che mostrino i pacchetti ICMP intercettati durante il traceroute.

## Esercizio 5: connessione e analisi FTP con autenticazione (modalità passive)

1. Assicurati che il client ``lftp`` sia installato nel sistema. In caso contrario, installalo con:
   ``apt-get install lftp``

2. Avvia **Wireshark** e imposta il filtro:
   ``ftp``

3. Connettiti al server FTP pubblico di test con:
   ``lftp -u demo,password test.rebex.net``

4. All’interno della sessione FTP, esegui:
   - ``ls`` per elencare i file disponibili
   - ``get readme.txt`` per scaricare un file di test

5. In **Wireshark**, analizza la comunicazione:
   - Come avviene l’autenticazione
   - Quali comandi vengono usati
   - Quali porte vengono utilizzate per **canale di controllo** e **canale dati**
   - Se username e password sono visibili in chiaro

6. Commenta i **rischi di sicurezza** dell’uso di FTP non cifrato e suggerisci alternative più sicure.

7. **Inserisci uno o più screenshot** che mostrino la sessione FTP, i comandi catturati, elementi significativi osservati in Wireshark.

---

## Consegna

In Google Classroom, consegna una relazione digitale in formato ``.pdf`` o ``.odt``, nominata: 
``Cognome-Nome_Verifica-SistemiReti.pdf``