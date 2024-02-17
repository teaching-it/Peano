## CIDR (Classless Inter-Domain Routing)

CIDR è una metodologia introdotta negli anni '90 per superare le limitazioni dell'originale schema di indirizzamento IP basato su classi (Classful Networking). Invece di dividere l'intero spazio degli indirizzi IP in classi fisse (A, B, C, D, E), CIDR permette una divisione più flessibile dell'indirizzo IP in reti di varie dimensioni.

Il concetto chiave di CIDR è la **notazione prefix/length**, dove:
- **prefix** indica l'indirizzo IP iniziale della rete,
- **length** (lunghezza del prefisso) specifica il numero di bit consecutivi, partendo dal bit più significativo, che compongono la maschera di sottorete. Questo determina la dimensione della rete.

Per esempio, nella notazione CIDR `192.168.0.0/24`, l'indirizzo `192.168.0.0` rappresenta l'indirizzo di rete, e `/24` indica che i primi 24 bit dell'indirizzo sono utilizzati per identificare la rete, lasciando gli ultimi 8 bit per gli host all'interno di quella rete. Ciò permette una granularità molto più fine nella suddivisione dello spazio degli indirizzi IP, consentendo di assegnare blocchi di dimensioni esattamente necessarie anziché adattarsi alle rigide dimensioni delle classi A, B o C.

## Supernetting

Il **supernetting**, talvolta chiamato **aggregazione di indirizzi**, è un processo utilizzato per combinare più reti contigue in una singola rete più grande. È l'opposto del subnetting, che divide una rete in sottoreti più piccole. Il supernetting riduce il numero di voci nelle tabelle di routing combinando molteplici indirizzi IP o reti in un'unica voce di routing, utilizzando una maschera di sottorete meno specifica (cioè, con un prefisso più corto in notazione CIDR).

Per esempio, se hai due reti adiacenti `192.168.0.0/24` e `192.168.1.0/24`, puoi supernetarle in una singola rete `192.168.0.0/23`. Questo è possibile perché la maschera di sottorete `/23` copre entrambi i blocchi di indirizzi originali, combinandoli in una singola rete più grande che può essere gestita come una singola voce nella tabella di routing.

Il supernetting è particolarmente utile per ridurre la complessità delle tabelle di routing nei router Internet e migliorare l'efficienza della gestione del traffico IP. Consentendo di aggregare reti, si riduce il numero di voci necessarie nelle tabelle di routing, semplificando la gestione del traffico su larga scala.

In sintesi, CIDR e il supernetting sono strumenti critici per gli amministratori di rete, permettendo un utilizzo più efficiente e flessibile dello spazio degli indirizzi IP e facilitando la gestione del routing su Internet.

## Esercizio di Supernetting

Immagina di essere un amministratore di rete incaricato di ottimizzare la struttura delle reti di un'organizzazione. L'organizzazione dispone di quattro sottoreti adiacenti che sono state assegnate per diversi dipartimenti, come segue:

- Rete A: 192.168.0.0/24
- Rete B: 192.168.1.0/24
- Rete C: 192.168.2.0/24
- Rete D: 192.168.3.0/24

Ogni sottorete ospita vari dispositivi, ma il crescente numero di voci nelle tabelle di routing sta causando inefficienze. La tua missione è quella di utilizzare il supernetting per combinare queste sottoreti in un numero minore di reti, al fine di semplificare la gestione del routing.

### Obiettivi

Determinare il nuovo indirizzo di rete e la maschera di sottorete dopo aver applicato il supernetting alle quattro reti fornite.
Spiegare il processo utilizzato per determinare il nuovo indirizzo di rete e la maschera di sottorete.

Calcolare il numero di host supportati dalla nuova configurazione di rete.
Suggerimenti:

Ricorda che il supernetting combina più sottoreti in una rete più grande, riducendo la lunghezza del prefisso della maschera di sottorete.
Considera il blocco di indirizzi IP più piccolo che può contenere tutte le sottoreti date.
Verifica che la nuova rete possa supportare tutti gli indirizzi IP delle sottoreti originali.

### Soluzione

Per ottimizzare le voci delle tabelle di routing combinando le quattro reti (`192.168.0.0/24`, `192.168.1.0/24`, `192.168.2.0/24`, `192.168.3.0/24`) in una rete più grande tramite supernetting, seguiamo questi passaggi:

#### 1. Determinazione del nuovo Indirizzo di rete e maschera di sottorete

Le reti date sono tutte adiacenti e cadono nell'intervallo `192.168.0.0` a `192.168.3.255`. Per combinare queste reti in un'unica rete, dobbiamo trovare una maschera di sottorete che copra tutti gli indirizzi IP da `192.168.0.0` a `192.168.3.255`.

- **Indirizzo di partenza (in binario):** `11000000.10101000.00000000.00000000` (192.168.0.0)
- **Indirizzo finale (in binario):** `11000000.10101000.00000011.11111111` (192.168.3.255)

Guardando i bit in comune all'inizio di questi indirizzi, troviamo che i primi 22 bit sono identici. Di conseguenza, possiamo usare una maschera di sottorete `/22` per il supernetting.

- **Nuovo Indirizzo di Rete:** `192.168.0.0/22`

#### 2. Spiegazione del processo

Il processo di supernetting ha combinato le quattro sottoreti `/24` adiacenti in una singola rete `/22`. Questo è stato possibile identificando i bit in comune tra l'indirizzo IP più basso (`192.168.0.0`) e l'indirizzo IP più alto (`192.168.3.255`) delle reti originali. La maschera di sottorete `/22` indica che i primi 22 bit dell'indirizzo IP sono riservati per l'indirizzamento di rete, lasciando 10 bit per gli indirizzi host, che fornisce più spazio di indirizzamento rispetto alle singole sottoreti `/24`.

#### 3. Calcolo del numero di host supportati

Con una maschera di sottorete `/22`, abbiamo 10 bit disponibili per gli indirizzi host. Ciò significa che la rete può supportare:

- **Numero di indirizzi IP totali:** `2^10 = 1024` indirizzi
- **Numero di indirizzi host utilizzabili:** `1024 - 2 = 1022` indirizzi

(Il calcolo esclude l'indirizzo di rete e l'indirizzo di broadcast.)

La nuova configurazione di rete `192.168.0.0/22` supporta quindi fino a 1022 host, unendo efficientemente le voci di routing per le quattro sottoreti originali.