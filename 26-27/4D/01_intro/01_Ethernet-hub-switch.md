# 01 - Ethernet: hub, switch e Auto-Negotiation

---

## 1. Velocità Ethernet

Ethernet comprende diverse tecnologie, caratterizzate anche dalla velocità nominale del collegamento.

| Tecnologia | Velocità nominale | Nome comune |
|---|---:|---|
| 10BASE-T | 10 Mbit/s | Ethernet |
| 100BASE-TX | 100 Mbit/s | Fast Ethernet |
| 1000BASE-T | 1 Gbit/s | Gigabit Ethernet |
| 10GBASE-T | 10 Gbit/s | 10 Gigabit Ethernet |

Una scheda di rete indicata come **10/100/1000** può normalmente funzionare a 10, 100 oppure 1000 Mbit/s. La velocità effettiva del collegamento dipende anche dalle capacità dell'altro estremo e dal cablaggio.

> La velocità nominale del link non coincide necessariamente con la velocità utile percepita dall'utente: protocolli, intestazioni, congestione e prestazioni dei dispositivi introducono dei limiti.

---

## 2. Che cos'è un hub

Un hub Ethernet è essenzialmente un **repeater multiporta**, cioè un dispositivo di **livello fisico** del modello OSI. Un repeater riceve un segnale, lo rigenera e lo ritrasmette senza interpretare frame o indirizzi MAC.

Quando riceve un segnale su una porta, lo rigenera e lo ripete verso le altre porte. Non interpreta gli indirizzi MAC e non decide a quale specifico destinatario inoltrare un frame.

### Caratteristiche principali

- lavora al **livello 1** del modello OSI;
- non costruisce una tabella degli indirizzi MAC;
- non filtra il traffico in base al destinatario;
- non effettua il normale buffering dei frame tipico di uno switch;
- tutte le stazioni collegate condividono il mezzo trasmissivo;
- tutte le porte appartengono allo stesso **collision domain**;
- il funzionamento è normalmente **half-duplex**;
- usa il meccanismo **CSMA/CD** per gestire l'accesso al mezzo condiviso.

### Dominio condiviso

```text
PC A ───┐
        │
PC B ───┼── [ HUB ]
        │
PC C ───┘
```

Se A trasmette, il segnale viene ripetuto anche verso B e C. Solo il destinatario indicato nel frame lo accetterà, ma tutti i dispositivi collegati ricevono fisicamente la trasmissione.

Poiché il mezzo è condiviso, due stazioni che trasmettono contemporaneamente possono provocare una **collisione**.

---

## 3. Che cos'è uno switch

Uno switch Ethernet opera principalmente al **livello 2** del modello OSI. Riceve i frame Ethernet e li inoltra usando gli **indirizzi MAC**.

Lo switch apprende quali indirizzi MAC sono raggiungibili attraverso ciascuna porta e costruisce una tabella, chiamata comunemente **MAC address table** o **CAM table**.

### Caratteristiche principali

- ogni porta costituisce un collegamento distinto;
- ogni porta rappresenta un **collision domain separato**;
- le porte possono lavorare a velocità differenti;
- le porte possono normalmente funzionare in **full-duplex**;
- lo switch può memorizzare temporaneamente i frame nei **buffer**;
- inoltra il traffico verso la porta appropriata, quando il destinatario è noto.

```text
PC A ── 1 Gbit/s ── [ SWITCH ] ── 100 Mbit/s ── PC B
                          │
                       buffer
```

Lo switch può ricevere un frame dalla porta di A a 1 Gbit/s e trasmetterlo verso B a 100 Mbit/s. La differenza di velocità viene gestita mediante code e buffer.

Se il traffico diretto verso la porta più lenta resta superiore alla sua capacità per troppo tempo, il buffer può riempirsi. In tal caso possono verificarsi ritardi e, quando la coda è piena, perdita di frame.

---

## 4. Hub e dispositivi con velocità diverse

Consideriamo tre dispositivi:

```text
Dispositivo A: scheda 10/100/1000
Dispositivo B: scheda 10/100
Dispositivo C: scheda 10/100/1000
```

### Hub Fast Ethernet a 100 Mbit/s

Se i tre dispositivi sono collegati a un normale hub 100BASE-TX, le due schede Gigabit usano una modalità compatibile con l'hub:

```text
A ── 100 Mbit/s ──┐
                   │
B ── 100 Mbit/s ── [ HUB 100 Mbit/s ]
                   │
C ── 100 Mbit/s ──┘
```

Il dominio condiviso dell'hub funziona a **100 Mbit/s in half-duplex**. Le schede Gigabit non comunicano con l'hub a 1 Gbit/s.

Non avviene una conversione di questo tipo:

```text
1 Gbit/s → buffer dell'hub → 100 Mbit/s
```

Un vero hub non è uno switch: non riceve e memorizza normalmente un frame completo per ritrasmetterlo a una velocità differente.

### Precisazione sui dual-speed hub

Sono esistiti hub **dual-speed 10/100**. Non facevano funzionare lo stesso dominio condiviso contemporaneamente a due velocità: mantenevano separati il dominio a 10 Mbit/s e quello a 100 Mbit/s e usavano internamente una funzione di collegamento tra i due.

Per questo motivo erano più complessi di un semplice hub a velocità fissa.

---

## 5. Switch e dispositivi con velocità diverse

Con uno switch, ogni porta è un link punto-punto indipendente:

```text
A ── 1 Gbit/s ────┐
                   │
B ── 100 Mbit/s ── [ SWITCH ]
                   │
C ── 1 Gbit/s ────┘
```

Lo switch può quindi avere contemporaneamente:

- porta 1: 1 Gbit/s full-duplex;
- porta 2: 100 Mbit/s full-duplex;
- porta 3: 1 Gbit/s full-duplex.

La comunicazione A↔C può sfruttare link Gigabit, mentre quella A↔B è limitata dal collegamento a 100 Mbit/s di B.

> Lo switch non rende più veloce la scheda di B: permette semplicemente agli altri collegamenti di conservare la propria velocità.

---

## 6. Che cos'è l'Auto-Negotiation

L'**Auto-Negotiation** è un protocollo standardizzato dal gruppo di standard **IEEE 802.3** e opera al livello fisico Ethernet.

I due dispositivi posti agli estremi di un collegamento si comunicano le rispettive capacità e scelgono automaticamente la migliore modalità comune.

Non vengono usati normali frame Ethernet e non servono ancora:

- indirizzi MAC;
- indirizzi IP;
- DHCP;
- TCP o UDP;
- applicazioni di rete.

### Quando avviene

L'Auto-Negotiation si svolge durante l'instaurazione del collegamento fisico, per esempio:

- quando viene collegato il cavo;
- quando si accende uno dei due dispositivi;
- quando una porta viene riabilitata;
- quando il link cade e viene ristabilito.

### Che cosa può negoziare

A seconda della tecnologia, può contribuire a definire:

- velocità del collegamento;
- modalità half-duplex o full-duplex;
- parametri di controllo di flusso;
- per 1000BASE-T, anche l'assegnazione dei ruoli master/slave ai due estremi del collegamento.

Per Ethernet a 10 e 100 Mbit/s su doppino vengono impiegati segnali chiamati **FLP — Fast Link Pulses** per comunicare le capacità.

### Esempio

```text
Scheda di rete: 10 / 100 / 1000, full-duplex
Porta switch:   10 / 100,        full-duplex
------------------------------------------------
Migliore modalità comune: 100 Mbit/s full-duplex
```

Il processo può essere riassunto così:

```text
Collegamento del cavo
        ↓
Scambio delle capacità tra i due dispositivi collegati
        ↓
Scelta della migliore modalità comune
        ↓
Configurazione del link
        ↓
Normale traffico Ethernet
```

---

## 7. Auto-Negotiation con uno switch

Il protocollo non è diverso: è sempre l'Auto-Negotiation definita da IEEE 802.3. Cambia la struttura della rete.

In uno switch, ogni porta negozia indipendentemente con il dispositivo direttamente collegato:

```text
PC A 10/100/1000 ⇄ porta 1 dello switch → 1 Gbit/s full-duplex
PC B 10/100      ⇄ porta 2 dello switch → 100 Mbit/s full-duplex
PC C 10/100/1000 ⇄ porta 3 dello switch → 1 Gbit/s full-duplex
```

La negoziazione riguarda ciascun **singolo link**, non l'intera rete locale.

Con un hub classico non esistono invece porte indipendenti capaci di ricevere e ritrasmettere frame a velocità diverse. Le porte fanno parte dello stesso dominio condiviso e l'hub è progettato per una determinata tecnologia e velocità.

---

## 8. Half-duplex e full-duplex

### Half-duplex

La comunicazione può avvenire in entrambe le direzioni, ma non contemporaneamente.

È paragonabile a una conversazione tramite ricetrasmittente: mentre una persona parla, l'altra ascolta.

Gli hub Ethernet sono associati al funzionamento half-duplex e alle collisioni.

### Full-duplex

I due estremi possono trasmettere e ricevere contemporaneamente.

Su un normale collegamento punto-punto full-duplex tra un dispositivo e una porta di switch non si verificano collisioni e CSMA/CD non è necessario.

---

## 9. Confronto riepilogativo

| Caratteristica | Hub | Switch |
|---|---|---|
| Livello OSI principale | Livello 1 | Livello 2 |
| Unità trattata | Segnali/bit | Frame Ethernet |
| Uso degli indirizzi MAC | No | Sì |
| Inoltro selettivo | No | Sì |
| Collision domain | Uno condiviso | Uno per porta |
| Duplex tipico | Half-duplex | Full-duplex |
| Velocità diverse sulle porte | No, non nello stesso dominio condiviso | Sì |
| Buffer dei frame | No | Sì |
| Collisioni | Possibili | Assenti sui link full-duplex |
| Diffusione del traffico | Ripete il segnale sulle altre porte | Inoltra in base alla tabella MAC; effettua flooding quando necessario |

---

## 10. Errori comuni

### «Il dispositivo più lento fa rallentare automaticamente tutto l'hub»

È una formulazione imprecisa. Un hub opera secondo la tecnologia e la velocità per cui è progettato. I dispositivi devono usare una modalità compatibile; una stazione non modifica dinamicamente la velocità di tutte le altre.

### «L'hub mette in coda i dati del dispositivo Gigabit»

Falso. Il buffering e la conversione tra porte a velocità diverse sono funzioni proprie di bridge e switch, non di un hub.

### «Con uno switch tutti i dispositivi comunicano alla velocità del più lento»

Falso. Ogni porta negozia il proprio link. Solo il traffico che deve attraversare una porta lenta è limitato dalla capacità di quella porta.

### «Auto-Negotiation usa pacchetti IP»

Falso. Avviene al livello fisico prima del normale traffico Ethernet e non richiede configurazione IP.

### «Se il link è full-duplex possono esserci collisioni»

Falso nel normale collegamento punto-punto: i due estremi possono trasmettere contemporaneamente su canali distinti e CSMA/CD non viene usato.

---

## 11. Esempi ragionati

### Esempio 1

Un computer con scheda 10/100/1000 è collegato a una porta Fast Ethernet 10/100 di uno switch.

**Risultato:** il link viene normalmente stabilito a 100 Mbit/s, scegliendo la migliore modalità comune.

### Esempio 2

Un computer Gigabit invia un grande file a un computer Fast Ethernet attraverso uno switch.

**Risultato:** il link del mittente può restare a 1 Gbit/s, ma il flusso diretto al destinatario è limitato dalla porta a 100 Mbit/s. Lo switch usa code e buffer per gestire temporaneamente la differenza.

### Esempio 3

Due computer Gigabit e uno Fast Ethernet sono collegati allo stesso switch Gigabit.

**Risultato:** i due computer Gigabit possono comunicare tra loro attraverso link a 1 Gbit/s; il terzo usa un link a 100 Mbit/s.

### Esempio 4

Una scheda configurata forzatamente a 100 Mbit/s full-duplex viene collegata a un dispositivo che non rileva correttamente la modalità e usa half-duplex.

**Risultato:** può verificarsi un **duplex mismatch**, con prestazioni molto scarse, errori e ritrasmissioni. In generale è preferibile lasciare attiva l'Auto-Negotiation su entrambi gli estremi, salvo precise esigenze amministrative.

---

## 12. Domande di verifica

1. A quale livello OSI opera principalmente un hub?
2. Perché un hub non può normalmente collegare porte che lavorano contemporaneamente a 100 Mbit/s e 1 Gbit/s?
3. A che cosa serve il buffer di uno switch?
4. Perché uno switch crea un collision domain separato per ogni porta?
5. Quando avviene l'Auto-Negotiation?
6. L'Auto-Negotiation usa frame Ethernet o pacchetti IP?
7. Una porta Gigabit e una porta Fast Ethernet dello stesso switch possono funzionare contemporaneamente alle rispettive velocità? Perché?
8. Qual è la differenza tra half-duplex e full-duplex?
9. Che cosa può accadere se il traffico arriva verso una porta dello switch più rapidamente di quanto possa essere trasmesso?
10. Perché l'affermazione «il dispositivo più lento rallenta automaticamente tutto l'hub» è imprecisa?

---

## 13. Sintesi da ricordare

> **Hub:** ripete il segnale, condivide il mezzo, non usa indirizzi MAC, non effettua il normale buffering dei frame e lavora tipicamente in half-duplex.

> **Switch:** inoltra i frame in base agli indirizzi MAC, separa i collision domain, può usare velocità diverse sulle porte e gestisce le differenze mediante buffer.

> **Auto-Negotiation:** protocollo del livello fisico con cui i due estremi di un singolo link scelgono automaticamente la migliore modalità comune prima del normale traffico Ethernet.
