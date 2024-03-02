# NAT overload

## Alternativamente denominato: PAT / IP Masquerading / IP Overloading / NAPT / NAT-PAT

I vari termini (NAT overload, PAT, ecc.) convergono su di una specifica casistica di NAT, in cui le connessioni generate da un insieme di computer (lato LAN, nel nostro caso) vengono "*presentate"* verso l'esterno con un solo indirizzo IP pubblico.

Tale tecnica viene codificata nella RFC2663, col nome di **Network Address Port Translation (NAPT)**.

## Step 1

Come prima cosa è necessario definire quale delle interfacce disponibili sul router è effettivamente connessa alla LAN, ovvero al lato inside.
Nel nostro caso, il router offre di default 2 interfacce GbE (GigabitEthernet) di cui la 0/0 è connessa sul lato inside.

    Router(config)#interface GigabitEthernet0/0
    Router(config-if)#ip nat ?
    inside   Inside interface for address translation
    outside  Outside interface for address translation
    Router(config-if)#ip nat inside
    Router(config-if)#exit

## Step 2

Successivamente, è necessario definire quale delle interfacce disponibili sul router è effettivamente connessa al lato public, ovvero al lato ouside. Nel caso specifico abbiamo scelto la Serial0/1/0

    Router(config)#interface Serial0/1/0
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

## Step 4: Regola di traslazione

    Router(config)#ip nat inside source list 1 interface Serial0/1/0 overload

Questo comando configura il NAT per consentire a più dispositivi nella rete interna (definiti dalla lista di accesso 1) di accedere a Internet tramite un singolo indirizzo IP pubblico assegnato all'interfaccia Serial0/1/0, utilizzando il PAT per mantenere distinte le sessioni di connessione.

Vediamo il comando nel dettaglio.

#### ip nat inside source list 1

Indica che il router dovrà tradurre gli indirizzi IP interni che corrispondono ai criteri definiti nella lista di accesso 1. La lista di accesso (access list/ACL) determina quali indirizzi IP interni sono soggetti al NAT quando cercano di accedere alla rete esterna.

#### interface Serial0/1/0

Specifica l'interfaccia che verrà utilizzata come riferimento per l'indirizzo IP esterno nel processo di NAT. In questo contesto, l'indirizzo IP configurato sull'interfaccia Serial0/1/0 sarà utilizzato come indirizzo IP pubblico per le sessioni NAT.

#### overload

Questa parte del comando abilita il PAT, una forma di NAT che consente a molteplici dispositivi nella rete interna di condividere un singolo indirizzo IP esterno per tutte le loro comunicazioni verso l'esterno. Nel dettaglio, Il PAT utilizza le porte TCP/UDP uniche per distinguere le sessioni di traffico in uscita, permettendo così a più utenti di connettersi a Internet simultaneamente utilizzando lo stesso indirizzo IP pubblico ma mantenendo le sessioni separate e identificabili.

## Step 5: Salvataggio del file di configurazione

    Router#copy running-config startup-config
    Destination filename [startup-config]?
    Building configuration...
    [OK]
