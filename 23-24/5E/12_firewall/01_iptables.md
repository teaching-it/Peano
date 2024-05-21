# GNU/Linux firewall: iptables

Innanzi tutto, una breve ma efficace definizione (Wikipedia):

*iptables is a user-space utility program that allows a system administrator to configure the IP packet filter rules of the Linux kernel firewall, implemented as different Netfilter modules. The filters are organized in different tables, which contain chains of rules for how to treat network traffic packets. Different kernel modules and programs are currently used for different protocols; iptables applies to IPv4, ip6tables to IPv6, arptables to ARP, and ebtables to Ethernet frames.*

Dunque, `iptables` è un tool da command line che dialoga direttamente con `Netfilter`, la componente fondamentale del Kernel Linux che, a sua volta, offre numerose operazioni e funzioni di packet filtering e manipolazione del traffico di rete (ad esempio: NAPT, port-forwarding).

## Chains

iptables è strutturato in **chains**, di cui le 3 principali sono: input, forward, output.

1. Input: è utilizzata per il controllo delle connessioni in ingresso. Ad esempio: se un un client tenta di connettersi alla macchina via SSH, a seconda del comportamento definito iptables potrebbe decidere di accettare o scartare la richieta di connessione.

2. Forward: questa *chain* si occupa di filtrare il traffico di rete che non è direttamente destinato alla macchina. Ad esempio: è abbastanza comune che una macchina GNU/Linux venga impiegata come router. Spesso il traffico di rete *transita* dal router e più difficilmente è destinato al router stesso: il traffico di rete è dunque instradato verso la destinazione (o ad un altro nodo intermedio lungo il percorso).

3. Output: si occupa di filtrare le richieste di connessione in uscita. Ad esempio: se viene generato un semplice ping, iptables ispezionerà il contenuto del pacchetto e, a seconda delle regole definite, deciderà se lasciar transitare o meno la richiesta.

Per visualizzare lo stato delle *chain* iptables:

```bash
root@peano:~# iptables -L -v
```

## Policy

Prima di procedere alla configurazione delle regole di firewalling, potrebbe essere conveniente definire il comportamento di default delle 3 *chains*.

Ovvero: che tipo di decisione deve intraprendere iptables, qualora per il pacchetto ispezionato non vi sia alcuna corrispondenza nell'elenco delle regole definite?

Il seguente comando consente di ispezionare la *default policy* per ciascuna *chain*:

```bash
root@peano:~# iptables -L | grep policy
```

Com'è possibile intuire dall'output del comando, la policy di default, per ciascuna delle 3 *chain* è quella di accettare qualsiasi tipo di richiesta.

È pratica comune modificare le *default policy* come segue:

```bash
root@peano:~# iptables --policy INPUT DROP
root@peano:~# iptables --policy OUTPUT DROP
root@peano:~# iptables --policy FORWARD DROP
```

In questo modo verranno rifiutati tutti i tentativi di connessione, in ingresso, in uscita o in transito.

Prova quindi ad effettuare un semplice `ping 1.1.1.1` per renderti conto di quanto fatto.

Per ripristinare le policy di default:

```bash
iptables --policy INPUT ACCEPT
iptables --policy FORWARD ACCEPT
iptables --policy OUTPUT ACCEPT
```

Riprenderemo il tema successivamente, con ulteriori esempi e dettagli.

## Rule processing

Iptables processa le regole in ordine sequenziale, dalla prima all'ultima, come appaiono in ogni chain.

**Questo è cruciale perché il primo match determina l'azione applicata al pacchetto.**

Se non viene trovato alcun match, la default policy della chain viene applicata. È importante ordinare le regole in modo che le condizioni più specifiche siano valutate prima di quelle più generali.

## Responses

Un altro aspetto fondamentale sono i comportamenti (le risposte) che è possibile applicare alle richieste di connessione.

1. Accept: acconsente la richiesta di connessione.
2. Drop: rifiuta "brutalmente" la richiesta.
3. Reject: non consente la connessione, e genera un "pacchetto di cortesia" (ICMP) in risposta.

## Esempi pratici

### Esempio 1: bloccare tutto il traffico in ingresso

Come visto in precedenza, è possibile modificare le policy di default al fine di bloccare tutto il traffico in ingresso ed in transito, permettendo invece il traffico in uscita:

```bash
iptables --policy INPUT DROP
iptables --policy OUTPUT ACCEPT
iptables --policy FORWARD DROP
```

#### Cosa significa cambiare la policy di una chain?

Quando cambi la policy di una chain in iptables (come da DROP a ACCEPT o viceversa), stai definendo il comportamento di default per il traffico che non corrisponde a nessuna delle regole specificate nella chain. La policy di default determina cosa accade a questo traffico non corrisposto:

- ACCEPT significa che tutto il traffico che non corrisponde ad altre regole verrà accettato.
- DROP significa che tutto il traffico che non corrisponde ad altre regole verrà scartato silenziosamente.
- REJECT significa che il traffico non corrispondente verrà rifiutato e verrà inviato un messaggio di errore al mittente (di solito un messaggio ICMP).

Per ripristinare le policy di default:

```bash
iptables --policy INPUT ACCEPT
iptables --policy FORWARD ACCEPT
iptables --policy OUTPUT ACCEPT
```

### Esempio 2: consentire il traffico SSH

Per consentire connessioni SSH in ingresso (porta 22) dalla rete esterna:

```bash
iptables -A INPUT -p tcp --dport 22 -j ACCEPT
iptables -A OUTPUT -p tcp --sport 22 -m state --state ESTABLISHED -j ACCEPT
```

Analogamente, qualora il servizio SSH non sia attivo, è possibile agire sul servizio HTTP/HTTPS (apache2) e sulle omologhe porte logiche.

### Esempio 3: bloccare il traffico da un indirizzo IP specifico

Per bloccare tutto il traffico proveniente da un indirizzo IP specifico:

```bash
iptables -A INPUT -s 192.168.1.100 -j DROP
```

Dove 192.168.1.100 è l'indirizzo IP che si desidera bloccare.

### Esempio 4: limitare il *rate* delle Connessioni ICMP (Ping Flood)

Per limitare il rate delle connessioni ICMP per prevenire attacchi di tipo Ping Flood:

```bash
iptables -A INPUT -p icmp -m limit --limit 1/second --limit-burst 10 -j ACCEPT
iptables -A INPUT -p icmp -j DROP
```

### Esempio 5: redirezionare il traffico da una porta logica sorgente ad una porta di destinazione

Per redirezionare tutto il traffico che arriva alla porta 80 (HTTP) verso la porta 8080:

```bash
iptables -t nat -A PREROUTING -p tcp --dport 80 -j REDIRECT --to-port 8080
```

### Esempio 6: consentire il traffico solo se proveniente da una specifica interfaccia di rete

Per consentire il traffico in ingresso sulla porta 80 solo se proveniente da una specifica interfaccia di rete (ad esempio, eth0):

```bash
iptables -A INPUT -i eth0 -p tcp --dport 80 -j ACCEPT
iptables -A INPUT -p tcp --dport 80 -j DROP
```

## Approfondimento

Iptables è uno strumento estremamente potente e versatile per la gestione del firewall e del traffico di rete su sistemi basati su Linux. È importante sottolineare che iptables può operare sia in modalità **stateless** che **stateful**, a seconda di come vengono configurate le regole.

### Stateless vs Stateful Firewalling

Un firewall stateless filtra i pacchetti basandosi esclusivamente sulle informazioni disponibili nel pacchetto stesso, senza tenere conto dello stato della connessione o del contesto storico dei pacchetti.
Quando iptables viene utilizzato come firewall stateless, analizza ogni pacchetto individualmente secondo le regole definite nelle chain di iptables. Non tiene conto se un pacchetto fa parte o meno di una connessione esistente.

Un firewall stateful, invece, tiene traccia dello stato delle connessioni di rete, come TCP streams o sessioni UDP. Questo gli permette di riconoscere pacchetti che sono parte di una connessione esistente.

iptables può funzionare come un firewall stateful utilizzando il modulo **conntrack**, che traccia lo stato delle connessioni. Questo permette a iptables di distinguere tra pacchetti nuovi, esistenti e relativi a connessioni già chiuse, e di applicare regole di firewalling in modo più dinamico e contestuale.

#### Esempi

##### 1. Consentire traffico dipendente

La seguente regola utilizza il modulo **conntrack** per consentire il traffico in ingresso solo se fa parte di una connessione già stabilita o in risposta a pacchetti del server.

```bash
iptables -A INPUT -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT
```

In questo comando, `--ctstate ESTABLISHED` consente pacchetti di connessioni già stabilite, mentre `RELATED` consente pacchetti che sono associati a connessioni già permessi (ad esempio, connessioni FTP passive).

##### 2. Consentire traffico in uscita per connessioni iniziate dal server

Similmente, possiamo consentire il traffico in uscita solo per le connessioni iniziate dal server.

```bash
iptables -A OUTPUT -m conntrack --ctstate NEW,ESTABLISHED -j ACCEPT
```

Qui, `--ctstate` NEW permette l'inizializzazione di nuove connessioni dal server, oltre alle connessioni già stabilite.

### Confronto con altri firewall

#### Windows Firewall

Funzionalità: Windows Firewall è integrato in Windows e offre funzionalità sia stateless che stateful. È progettato per utenti meno tecnici e ha un'interfaccia utente grafica (GUI).

Differenze: A differenza di iptables, Windows Firewall non offre la stessa profondità di configurazione a livello di comando o la flessibilità per gestire complessi scenari di routing e manipolazione dei pacchetti.

#### Cisco ASA

Funzionalità: Cisco ASA è un dispositivo firewall hardware che offre capacità di filtraggio avanzate, VPN, e altre funzionalità di sicurezza.

Differenze: A differenza di iptables, che è un software che può essere eseguito su qualsiasi hardware compatibile con Linux, Cisco ASA è un'apparecchiatura dedicata con un sistema operativo e software specifici. Offre una gestione centralizzata e supporto per configurazioni aziendali complesse.
