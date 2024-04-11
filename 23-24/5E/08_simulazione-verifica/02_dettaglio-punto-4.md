# Processo di Comunicazione in Rete: Dal Browser al Web Server

Il processo di comunicazione in rete tra un client che apre un browser per accedere a una risorsa su un web server remoto, passando per la risoluzione DNS, coinvolge una serie di passaggi tecnici dettagliati e meccanismi che operano all'interno dello stack protocollare TCP/IP.

## 1. Apertura del Browser e Digitazione dell'URL

Quando l'utente apre il browser e digita un URL (Uniform Resource Locator), il browser interpreta l'URL per determinare il protocollo da usare (tipicamente HTTP o HTTPS) e l'hostname della risorsa da richiedere.

## 2. Risoluzione DNS

Il browser inizia il processo di risoluzione DNS per tradurre l'hostname in un indirizzo IP. Questo processo si avvale del Domain Name System (DNS), un sistema distribuito utilizzato per risolvere i nomi degli host in indirizzi IP e viceversa. La richiesta inizia con una query DNS che viene formulata dal browser e inviata al resolver DNS configurato sul sistema dell'utente, generalmente specificato nel file `/etc/resolv.conf` su sistemi Linux.

Se l'indirizzo IP non è già presente nella cache locale del resolver, la richiesta DNS viene inviata attraverso la rete Internet. Le richieste DNS sono generalmente incapsulate in datagrammi UDP (User Datagram Protocol) per la trasmissione. UDP è scelto per la sua efficienza e la sua natura senza connessione, ideale per le brevi richieste e risposte che caratterizzano la risoluzione DNS.

Il messaggio DNS incapsulato in UDP contiene vari campi, tra cui il tipo di richiesta (ad esempio, una query per un indirizzo IPv4 è indicata come tipo A), il nome dell'host di destinazione, e potenzialmente delle opzioni avanzate per il controllo del comportamento della query. Questo datagramma UDP è poi incapsulato in un pacchetto IP, specificando gli indirizzi IP di origine e destinazione, e trasmesso sulla rete.

Il datagramma raggiunge il server DNS configurato o un server successivo nella catena di risoluzione, che elabora la richiesta. Se il server DNS non conosce direttamente l'indirizzo IP richiesto, può inoltrare la richiesta ad altri server DNS in una ricerca ricorsiva o iterativa fino a quando non viene trovata una risposta. Una volta ottenuta la risposta, questa viene inviata al client mediante un processo inverso di incapsulamento e trasmissione, completando così la risoluzione DNS.

## 3. Stabilimento della Connessione TCP

Una volta ottenuto l'indirizzo IP, il browser avvia una connessione TCP con il web server. Questo processo inizia con il three-way handshake di TCP:

1. Il client invia un segmento TCP con il flag SYN attivato al server per iniziare la connessione.
2. Il server risponde con un segmento TCP contenente i flag SYN e ACK attivati, indicando l'accettazione della connessione.
3. Il client risponde con un segmento TCP con il flag ACK attivato, completando il processo di handshake.

## 4. Incapsulamento dei Dati e Invio della Richiesta HTTP

Con la connessione TCP stabilita, il browser può inviare la richiesta HTTP al web server. Questo processo coinvolge l'incapsulamento dei dati a diversi livelli dello stack protocollare:

- **Livello Applicazione**: La richiesta HTTP viene creata, includendo metodi, header, e possibili dati del corpo della richiesta.
- **Livello Trasporto (TCP)**: La richiesta HTTP viene suddivisa in segmenti TCP, ognuno con un proprio header che include numeri di sequenza, ACK, e altri controlli.
- **Livello Rete (IP)**: Ogni segmento TCP viene incapsulato in un pacchetto IP, con un header che include l'indirizzo IP di origine e destinazione.
- **Livello Collegamento Dati**: Il pacchetto IP viene ulteriormente incapsulato in un frame del livello di collegamento dati, ad esempio Ethernet, che include indirizzi MAC di origine e destinazione (tipicamente il MAC address del default gateway/router).

## 5. Trasmissione dei Dati e Ricezione della Risposta

Il frame viene trasmesso attraverso la rete al server. Al ricevimento, il server deincapsula i dati seguendo il processo inverso, elabora la richiesta HTTP, e prepara una risposta che viene inviata indietro al client seguendo gli stessi passaggi di incapsulamento e trasmissione.

## 6. Visualizzazione della Risorsa

Una volta che il browser riceve la risposta HTTP dal server, la elabora e visualizza la risorsa richiesta (ad esempio, una pagina web) all'utente.