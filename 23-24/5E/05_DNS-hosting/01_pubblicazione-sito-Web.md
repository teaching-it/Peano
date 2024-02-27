# Pubblicazione di un sito Web online

...Molte conoscenze/competenze frammentate... Come ricomporle al fine di perseguire uno specifico, *semplice* obiettivo?

Poniamo, dunque, la seguente domanda:

### *Come "pubblicare" un sito Web online?*

## 1 Registrazione di un dominio

### 1.1 Scegliere un fornitore di servizi

La prima cosa da fare è scegliere un fornitore di servizi Internet. Ad esempio, Gandi, OVH, Netsons, Aruba, DigitalOcean, sono tutti fornitori affidabili che offrono sia servizi di registrazione di domini che di hosting Web. Ognuno di questi fornitori ha i suoi punti di forza e piani tariffari, quindi vale la pena confrontarli per trovare quello che meglio si adatta alle specifiche esigenze.

### 1.2 Acquistare un dominio

Un dominio, volgarmente, corrisponde ad un indirizzo testuale univoco su Internet. La scelta di un buon nome di dominio è fondamentale ai fini della riconoscibilità e della competitività online.

### 1.3 Ricerca del nome di dominio

Uno strumento come [questo](https://www.whois.com/whois/) è utile per trovare un nome di dominio disponibile, o per verificarne le informazioni di registrazione.

### 1.4 Registrazione del dominio

Procedere, poi, con l'acquisto seguendo le istruzioni fornite dal fornitore. A seconda della tipologia del dominio, verranno o meno richiesti dettagli anagrafici o ulteriori informazioni.

### 1.5 Gestione delle corrispondenze indirizzo IP <=> dominio

Il passo successivo consiste nel configurare il DNS (Domain Name System) per collegare il dominio a un indirizzo IP specifico. Il DNS funziona come una sorta di *"rubrica telefonica per Internet"*, e si occupa di convertire i nomi dei domini leggibili e più facilmente ricordabili dall'uomo (ad esempio, `www.ultras-compiobbi.com`) in indirizzi IP (ad esempio,`202.0.2.1`).

#### 1.5.1 Configurazione dei record DNS presso il fornitore di servizi

La configurazione dei record DNS è un'operazione che in genere si effettua attraverso un pannello di controllo fornito dal fornitore di servizi. È comune, infatti, operare mediante un'interfaccia grafica che semplifica la gestione dei record DNS, rendendo non necessaria la modifica manuale dei file di configurazione.

Il DNS utilizza questi record per risolvere i nomi dei domini in indirizzi IP, consentendo ai browser di *"localizzare"* i server Web su Internet. Ogni record nel file di configurazione DNS ha un formato specifico e svolge funzioni diverse a seconda del tipo.

#### 1.5.2 Record A (dettaglio tecnico)

Il record A è uno dei tipi di record DNS più fondamentali e utilizzati. Esso mappa direttamente un nome di dominio a un indirizzo IP versione 4 (IPv4), indicando quale server ospita il sito Web associato a quel nome di dominio. La sintassi di un record A è semplice: include il nome di dominio, il tipo di record (in questo caso "A"), e l'indirizzo IP del server di hosting.

    www.ultras-compiobbi.it IN A 202.0.2.1

In questo contesto, "IN" indica che il record è di tipo Internet, e "A" specifica che si tratta di un record di indirizzamento, che collega il nome di dominio a un indirizzo IP.

Questo significa che quando un utente digita `www.ultras-compiobbi.it` nella barra degli indirizzi del proprio browser, il sistema DNS tradurrà questo nome di dominio nell'indirizzo IP specificato, permettendo al browser di connettersi al server dove è ospitato il sito Web.

Bene, osserviamo più nel dettaglio questo processo.

### 1.6 Esempio

#### 1.6.1 Inserimento del nome di dominio

Quando un utente digita un nome di dominio (ad esempio, `www.ultras-compiobbi.it`) nella barra degli indirizzi del browser, egli inizia il processo di risoluzione del nome di dominio.

#### 1.6.2 Controllo della cache locale

Il browser per prima cosa controlla se l'indirizzo IP corrispondente al nome di dominio è già presente nella sua cache locale. I sistemi operativi mantengono anche una cache dei risultati delle recenti risoluzioni DNS. Se l'indirizzo è presente in cache, il processo di risoluzione termina qui, e il browser si connette direttamente all'indirizzo IP trovato.

#### 1.6.3 Richiesta al resolver DNS del sistema

Quando il nome di dominio richiesto non è presente nella cache locale del browser o nella cache del sistema operativo, il processo di risoluzione del nome di dominio procede con una richiesta al resolver DNS configurato sul proprio sistema. L'indirizzo del resolver è spesso fornito dal provider di servizi Internet (ISP) dell'utente, ma può anche essere configurato manualmente per utilizzare server DNS specifici, come Google DNS (`8.8.8.8` e `8.8.4.4`) o Cloudflare DNS (`1.1.1.1`). All'interno di una rete LAN, è pratica comune configurare il server DHCP affinché, oltre ad offrire le specifiche di configurazione IP, offra anche l'indirizzo IP del server DNS.

#### 1.6.4 Inizializzazione della richiesta DNS

Il browser comunica con il sistema operativo per iniziare il processo di risoluzione del nome di dominio. Il sistema operativo, a sua volta, utilizza il resolver DNS configurato per gestire la richiesta.

#### 1.6.5 Comunicazione tra client e server 

Il resolver DNS del sistema operativo funge da client nel processo di comunicazione con il server DNS. Questa comunicazione avviene tipicamente su UDP (User Datagram Protocol), protocollo di livello 4 (trasporto) nel modello OSI. UDP è scelto per la sua efficienza e la sua natura senza connessione, ideale per le brevi richieste e risposte DNS.

#### 1.6.6 Incapsulamento della richiesta DNS in UDP

La richiesta DNS, che è a livello applicazione (livello 5 nel modello OSI), viene incapsulata in un datagramma UDP. Il datagramma contiene l'indirizzo IP del server DNS di destinazione  e il numero di porta standard per DNS, la porta `53`.

#### 1.6.7 Invio della richiesta al server DNS

Il datagramma UDP, contenente la richiesta DNS, viene trasmesso attraverso la rete Internet verso il server DNS specificato.

#### 1.6.8 Ricezione e elaborazione della richiesta dal Server DNS

Il server DNS riceve la richiesta, elabora l'interrogazione per il nome di dominio specificato, e cerca la corrispondenza con l'indirizzo IP nel suo database: *caso scarsamente probabile!*. Altrimenti, inoltra la richiesta ad altri server DNS se non dispone dell'informazione richiesta.

#### 1.6.9 Ricezione della risposta e conclusione del processo

Il resolver DNS (client) riceve la risposta, estrae l'indirizzo IP dal pacchetto di risposta e lo fornisce al browser. A questo punto, il browser può stabilire una connessione al server Web indicato per richiedere e recuperare il contenuto web.

## 2. Acquisto servizio di hosting

TODO.