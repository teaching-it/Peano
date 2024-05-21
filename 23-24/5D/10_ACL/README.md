# ACL

## Definizione ACL standard

Le ACL (Access Control Lists) standard, nel range [1,99], sono utilizzate per filtrare il traffico di rete basandosi esclusivamente sull'indirizzo IP sorgente, permettendo o bloccando il transito dei dati da un host o un gruppo di host.

Ecco un esempio pratico:

```bash
R2(config)#access-list 10 permit host 192.168.2.1
```

Gli elementi coinvolti nel comando sono:

- **10**: identificativo numerico univoco, nel range [1,99];
- **permit**: indica l'azione di permettere il traffico;
- **host 192.168.2.1**: specifica l'indirizzo IP sorgente da cui è permesso il traffico.

Implicitamente, Cisco IOS aggiunge anche la seguente regola di negazione a tutte le ACL:

```bash
R2(config)#access-list 10 deny any
```

Questo significa che tutto il traffico non corrispondente all'indirizzo IP definito nella regola precedente verrà bloccato.

Quindi, l'ACL completa avrà questa configurazione:

```bash
access-list 10 permit host 192.168.2.1
access-list 10 deny any
```

## Ordine e matching delle ACL

ACL processa le regole in ordine sequenziale dall'alto verso il basso come sono inserite nella configurazione. Non appena una regola corrisponde al traffico in esame, l'azione corrispondente (permit o deny) viene eseguita, e nessuna ulteriore regola viene considerata. Pertanto, l'ordine delle regole è critico e può influenzare significativamente il comportamento del traffico di rete. Se nessuna regola corrisponde, il traffico viene trattato secondo la regola implicita di "deny any", che blocca ogni altro traffico.

## Definizione ACL estese

Le ACL estese, identificate da numeri nel range [100,199], offrono una granularità maggiore nel controllo del traffico, permettendo di filtrare basandosi su vari attributi del livello di rete e di trasporto.

Ad esempio, la regola seguente permette solo il traffico TCP proveniente da 1.1.1.1 diretto alla porta 80 di 2.2.2.1:

```bash
R2(config)#access-list 110 permit tcp host 1.1.1.1 host 2.2.2.1 eq www
```

Come per le ACL standard, Cisco IOS definisce implicitamente la seguente regola di negazione:

```bash
R2(config)#access-list 110 deny ip any any
```

È consigliabile esplicitare questa regola per chiarezza.

Pertanto, l'ACL definitiva sarà configurata come segue:

```bash
access-list 110 permit tcp host 1.1.1.1 host 2.2.2.1 eq www
access-list 110 deny ip any any
```

## Applicazione

Per applicare un'ACL a una specifica interfaccia, utilizza il seguente comando:

```bash
ip access-group acl-number in [out]
```

Ad esempio, per associare l'ACL numero 10 all'interfaccia GigabitEthernet0/0 e filtrare il traffico in ingresso:

```bash
R(config)#interface GigabitEthernet0/0
R(config-if)#ip access-group 10 in
```

Questo configura l'interfaccia per permettere il traffico da 192.168.2.1 e bloccare tutto il resto in ingresso.

Per rimuovere l'associazione:

```bash
R(config)#interface GigabitEthernet0/0
R(config-if)#no ip access-group 10 in
```

## Visualizzazione

Per visualizzare i dettagli e le statistiche di una specifica ACL, inclusi i pacchetti bloccati o permessi:

```bash
R#show access-lists 110
```

Per vedere tutte le ACL configurate sul dispositivo:

```bash
R#show access-lists
```
