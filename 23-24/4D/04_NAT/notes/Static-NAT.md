# Static NAT translation

La tecnica di Static NAT è utilizzata a fine di attivare un one-to-one-mapping (mappatura uno ad uno) tra un indirizzo interno (inside, ovvero facente parte il lato LAN) ed un indirizzo esterno (outside, ovvero facente parte il lato generalmente connesso al Public Internet) e quindi, più genericamente, di consentire il raggiungimento di una macchina interna dall'esterno.

Nell'esempio visto in classe lo Static NAT attiva un *one-to-one mapping* tra uno degli indirizzi IP pubblici disponibili (disponibili sul lato outside, il 195.191.53.66) ed uno degli indirizzi ip privati afferenti alla LAN (quindi disponibile sul lato inside, il 192.168.1.2).

Lo static NAT attiva quindi una corrispondenza permanente tra 195.191.53.66 e 192.168.1.2

## Step 0

Prima di iniziare, ricorda di accedere alla modalità di configurazione globale (configure terminal) dopo aver attivato la modalità Privileged EXEC (enable).

    Router>enable
    Router#configure terminal
    Enter configuration commands, one per line.  End with CNTL/Z.

## Step 1

Come prima cosa è necessario definire quale delle interfacce disponibili sul router è effettivamente connessa alla LAN, ovvero al lato inside.
Nel nostro caso, il router Cisco 1941 offre di default 2 interfacce GbE (GigabitEthernet) di cui la 0/0 è connessa sul lato inside.

    Router(config)#interface GigabitEthernet0/0
    Router(config-if)#ip nat ?
    inside   Inside interface for address translation
    outside  Outside interface for address translation
    Router(config-if)#ip nat inside
    Router(config-if)#exit

## Step 2

Successivamente, è necessario definire quale delle interfacce disponibili sul router è effettivamente connessa al lato Public, ovvero al lato ouside. Nel caso specifico abbiamo scelto la Serial0/1/0.

    Router(config)#interface Serial0/1/0
    Router(config-if)#ip nat ?
    inside   Inside interface for address translation
    outside  Outside interface for address translation
    Router(config-if)#ip nat outside
    Router(config-if)#exit

## Step 3: Regola di traduzione/traslazione

A questo punto non ci rimane che definire la regola di traduzione (anche detta di traslazione) al fine di *mappare* l'indirizzo IP pubblico 195.191.53.66 su di uno specifico indirizzo IP privato 192.168.1.2.

Il comando, in generale, è il seguente.

    Router(config)#ip nat inside source static [inside local ip address] [outside global ip address]

Il comando parametrizzato rispetto alla nostra specifica configurazione è:

    Router(config)#ip nat inside source static 192.168.1.2 195.191.53.66

## Step 4: Diagnostica

    Router#show ip nat translations
    Pro  Inside global     Inside local       Outside local      Outside global
    ---  195.191.53.66     192.168.1.2        ---                ---

Particolare è la terminologia utilizzata da Cisco rispetto al NAT. Come abbiamo visto in precedenza, le interfacce debbono essere esplicitamente contrassegnate come inside ed outside e, per tale motivo, la lettura della translations table potrebbe quindi risultare fuorviante. Ciò che abbiamo precedentemente considerato come interfaccia outside (che si affaccia quindi sull'Internet) all'interno della translations table è altresì definita Inside global. L'interfaccia precedentemente contrassegnata come inside, prende invece il nome di Inside local.

## Step 5: Salvataggio del file di configurazione

    Router#copy running-config startup-config
    Destination filename [startup-config]?
    Building configuration...
    [OK]

