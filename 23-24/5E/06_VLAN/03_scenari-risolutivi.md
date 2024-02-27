## Orizzonti progettuali/scenari risolutivi

La segmentazione della rete in ambienti scolastici, come per i laboratori, è cruciale per migliorare la gestione, la sicurezza e le prestazioni della rete. In classe abbiamo discusso tre scenari di risoluzione le loro implicazioni.

### 1. Assegnazione di range di IP all'interno della stessa subet

#### Scenario

Vengono generati *range* di IP da assegnare a diversi laboratori, ad esempio da `10.23.0.1` a `10.23.0.255` per il laboratorio 1, e da `10.23.1.0` a `10.23.1.255` per il laboratorio 2, ma mantenendo una netmask `/16` per l'intera rete.

#### Implicazioni

Questo approccio organizza solo logicamente gli indirizzi IP ma non fornisce una vera segmentazione di rete. Tutti i dispositivi rimangono all'interno dello stesso dominio di broadcast a livello 2 e 3. Questo significa che il traffico broadcast, le politiche di sicurezza e le prestazioni della rete sono gestiti come se tutti i dispositivi fossero in una singola grande rete. La mancanza di isolamento tra i laboratori può portare a problemi di sicurezza e a una gestione del traffico di rete meno efficiente.

### 2. Generazione di subnet Distinte per ogni laboratorio

#### Scenario

Creazione di subnet distinte per ogni laboratorio, ad esempio assegnando `10.23.0.0/24` al laboratorio 1 e `10.23.1.0/24` al laboratorio 2, etc.

#### Implicazioni

Questo approccio migliora la segmentazione a livello di rete (livello 3) creando domini di broadcast IP distinti per ogni laboratorio. Migliora la gestione del traffico, la sicurezza e può aiutare nell'implementazione di politiche di rete specifiche per ogni laboratorio. Tuttavia, senza l'uso di VLAN, tutti i dispositivi fanno ancora parte dello stesso dominio di broadcast a livello 2, il che significa che il traffico generato al livello sottostante, al livello 2, come ad esempio **ARP requests**, può ancora raggiungere tutti i dispositivi, potenzialmente portando a problemi di sicurezza e prestazioni.

### 3. Subnet distinte e attivazione VLAN

#### Scenario

Oltre a creare subnet distinte per ogni laboratorio (così come al precedente punto 2), vengono attivate VLAN specifiche per ciascuna subnet.

#### Implicazioni

Questo è l'approccio più completo per la segmentazione di rete. Le VLAN forniscono isolamento a livello 2, creando domini di broadcast separati per ogni laboratorio. Questo non solo mantiene separati i traffici a livello di rete (livello 3) ma anche a livello data link (livello 2), migliorando significativamente la sicurezza e le prestazioni. Più in generale, le VLAN facilitano anche l'applicazione di politiche di sicurezza specifiche, il controllo degli accessi, e possono ridurre il rischio di attacchi alla rete. Questo approccio richiede switch gestibili che supportino le VLAN e una configurazione di rete più complessa, ma offre i migliori benefici in termini di sicurezza, prestazioni e flessibilità di gestione della rete.
