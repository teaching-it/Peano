## Dominio di broadcast

I domini di broadcast a livello 2 e a livello 3 rappresentano concetti fondamentali nella segmentazione e nella gestione delle reti.

### 1. Dominio di broadcast di livello 2

#### Definizione

Un dominio di broadcast di livello 2 è l'insieme di tutti i dispositivi in una rete locale (LAN) che possono raggiungersi tramite broadcast Ethernet a livello di indirizzi MAC. In pratica, quando un dispositivo invia un frame di broadcast a livello 2 con l'indirizzo MAC destinazione `FF:FF:FF:FF:FF:FF`, tutti i dispositivi all'interno dello stesso dominio di broadcast di livello 2 ricevono e processano quel frame.

#### Isolamento

L'isolamento tra diversi domini di broadcast di livello 2 può essere ottenuto fisicamente (con dispositivi separati) o logicamente tramite VLAN (Virtual LAN), che segmentano una LAN fisica in più LAN virtuali.

#### Protocolli

Operando al livello Data Link del modello OSI, i domini di broadcast di livello 2 sono influenzati da protocolli come ad esempio ARP (Address Resolution Protocol), che mappa gli indirizzi IP agli indirizzi MAC. Un dominio di broadcast di livello 2 particolarmente esteso vedrà un conseguente aumento del traffico di tal tipo.

### 2. Dominio di broadcast di livello 3

#### Definizione

Un dominio di broadcast di livello 3 corrisponde a una subnet IP, ovvero l'insieme di dispositivi che possono raggiungersi direttamente tramite indirizzi IP senza necessità di routing. Il broadcast a livello 3 utilizza l'indirizzo di broadcast specifico della subnet (ad esempio, `192.168.1.255` in una subnet `192.168.1.0/24`) per inviare pacchetti a tutti i dispositivi nella subnet.

#### Isolamento

L'isolamento a livello 3 viene ottenuto tramite la suddivisione di reti più grandi in subnet più piccole, ciascuna con il proprio dominio di broadcast di livello 3. Il routing tra queste subnet richiede dispositivi di routing che gestiscono il traffico tra subnet diverse.

#### Protocolli

A livello 3, protocolli come ICMP (Internet Control Message Protocol) possono essere utilizzati per inviare messaggi di echo broadcast (ping) a tutti i dispositivi di una subnet.

### Differenze chiave

1. I domini di broadcast di livello 2 sono limitati alla LAN fisica e operano con indirizzi MAC. I domini di broadcast di livello 3 sono definiti da subnet IP e operano con indirizzi IP.
2. L'isolamento in un dominio di broadcast di livello 2 si ottiene principalmente tramite VLAN (o, più "drasticamente", utilizzando dispositivi fisici indipendenti e non interconnessi), mentre a livello 3 l'isolamento si basa sulla suddivisione in subnet.
3. Nei domini di broadcast di livello 2, tutto il traffico broadcast viene ricevuto da tutti i dispositivi nella VLAN o nella LAN fisica. Nei domini di broadcast di livello 3, il traffico broadcast è confinato alla subnet specifica.
4. I domini di broadcast di livello 2 sono cruciali per la risoluzione degli indirizzi e la scoperta dei dispositivi all'interno della stessa rete fisica (protocollo ARP). I domini di broadcast di livello 3 sono importanti per la comunicazione e la gestione del traffico all'interno di reti IP segmentate.
