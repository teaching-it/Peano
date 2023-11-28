# NAT overload

## Alternativamente denominato: PAT / IP Masquerading / IP Overloading / NAPT / NAT-PAT

I vari termini (NAT overload, PAT, ecc.) convergono su di una specifica casistica di NAT, in cui le connessioni generate da un insieme di computer (lato LAN, nel nostro caso) vengono *presentate* verso l'esterno con un solo indirizzo IP pubblico.

Tale tecnica viene codificata nella RFC2663, col nome di **Network Address Port Translation (NAPT)**.

## Step 1

Come prima cosa è necessario definire quale delle interfacce disponibili sul router è effettivamente connessa alla LAN, ovvero al lato inside.
Nel nostro caso, il router modello 2901 offre di default 3 interfacce GbE (GigabitEthernet) di cui la 0/0 è connessa sul lato inside.

    Router(config)#interface GigabitEthernet0/0
    Router(config-if)#ip nat ?
    inside   Inside interface for address translation
    outside  Outside interface for address translation
    Router(config-if)#ip nat inside
    Router(config-if)#exit

## Step 2

Successivamente, è necessario definire quale delle interfacce disponibili sul router è effettivamente connessa al lato public, ovvero al lato ouside. Nel caso specifico abbiamo scelto la GigabitEthernet0/1.

    Router(config)#interface Gig0/1
    Router(config-if)#ip nat ?
    inside   Inside interface for address translation
    outside  Outside interface for address translation
    Router(config-if)#ip nat outside
    Router(config-if)#exit

## Step 3: Definizione della access list

192.168.0.0 = indirizzo della rete da "nattare" (inside);
0.0.0.255 = reciproco (wildcard) della maschera di sottorete.

    Router(config)#access-list 1 permit 192.168.0.0 0.0.0.255

Il comando genera la access-list con identificativo 1 e con regola *permit* per l'intera subnet /24 associata alla LAN-1.
(Nb. è possibile creare delle access-list più stringenti con range di indirizzi più piccoli).

## Step 4: Regola di traduzione

    Router(config)#ip nat inside source list 1 interface GigabitEthernet0/1 overload

## Step 5: Salvataggio del file di configurazione

    Router#copy running-config startup-config
    Destination filename [startup-config]?
    Building configuration...
    [OK]
