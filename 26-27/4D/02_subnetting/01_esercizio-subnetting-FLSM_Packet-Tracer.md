# Esercizio – Subnetting FLSM (Fixed Length Subnet Mask)

In **Cisco Packet Tracer**, realizzare una rete che rappresenti **almeno 2 delle subnet** richieste, collegando **almeno 2 host per ciascuna subnet** e assegnando correttamente a ogni dispositivo i parametri di configurazione IP (indirizzo IP, subnet mask e gateway predefinito). Verificare la connettività tra gli host.

Data la rete **192.168.0.0/24**, suddividerla in quattro sottoreti (subnet) utilizzando la tecnica **FLSM (Fixed Length Subnet Mask)**: tutte le subnet devono avere la stessa subnet mask e la stessa capienza, cioè lo stesso numero massimo di indirizzi IP assegnabili agli host, anche se le esigenze sono differenti:

- **Subnet 1:** 45 host
- **Subnet 2:** 38 host
- **Subnet 3:** 54 host
- **Subnet 4:** 60 host

Per ciascuna subnet determinare:

1. Indirizzo di rete
2. Subnet mask (notazione decimale e CIDR)
3. Indirizzo di broadcast
4. Intervallo degli indirizzi IP assegnabili agli host
5. Indirizzo IP del gateway (utilizzare il primo indirizzo assegnabile)

## Traccia del processo risolutivo

**1. Individuazione dei bit disponibili**

La rete di partenza ha prefisso `/24`. Poiché un indirizzo IPv4 è composto da 32 bit, disponiamo di:

`32-24=8 bit`

Gli 8 bit disponibili corrispondono esattamente all'ultimo ottetto dell'indirizzo IPv4.

**2. Determinazione dei bit necessari per le subnet**

Dobbiamo rappresentare 4 subnet. Il numero di bit `n` necessari deve soddisfare la disuguaglianza:

`2^n ≥ 4`

Il valore minimo che soddisfa la disuguaglianza è **n = 2**.

Utilizzando 2 bit possiamo rappresentare esattamente quattro combinazioni:

- Subnet 1: `00`
- Subnet 2: `01`
- Subnet 3: `10`
- Subnet 4: `11`

**3. Determinazione dei bit disponibili per gli host**

Degli 8 bit inizialmente disponibili, 2 vengono utilizzati per identificare le subnet. Rimangono quindi:

`8-2=6 bit`

Con 6 bit possiamo rappresentare:

`2^6=64 indirizzi`

Escludendo l'indirizzo di rete e quello di broadcast, ciascuna subnet può contenere:

`2^6-2=62 host assegnabili`

Poiché tutte e quattro le subnet richiedono al massimo 60 host, **6 bit sono sufficienti per soddisfare tutte le richieste**. Nel subnetting **FLSM**, ciascuna subnet dispone della stessa capienza (**62 host assegnabili**), indipendentemente dal numero di host effettivamente richiesti.

**4. Struttura dell'ultimo ottetto**

L'ultimo ottetto sarà quindi suddiviso nel seguente modo:

`[SS][HHHHHH]`

Dove:

- `SS` = 2 bit per identificare la subnet
- `HHHHHH` = 6 bit per identificare gli host

Il nuovo prefisso di rete sarà:

`/24+2=/26`

**5. Completamento dell'esercizio**

A partire dalle quattro combinazioni individuate, determinare per ciascuna subnet l'indirizzo di rete, la subnet mask, l'indirizzo di broadcast, il range degli indirizzi assegnabili e l'indirizzo del gateway.
