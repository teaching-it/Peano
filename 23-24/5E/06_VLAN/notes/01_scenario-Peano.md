# Scenario Peano

## Analisi preliminare

Durante le attività di laboratorio del 20 febbraio 2024 siamo partiti con l'analisi delle interfacce di rete disponibili nella macchina virtuale Linux

    root@linux:/home/user# /sbin/ifconfig

    lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
        loop  txqueuelen 1000  (Loopback Locale)
        RX packets 12345  bytes 678910 (678.9 KB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 12345  bytes 678910 (678.9 KB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

    enp0s3: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 10.23.56.134  netmask 255.255.0.0  broadcast 10.23.255.255
        inet6 fe80::a00:27ff:fe4e:66a1  prefixlen 64  scopeid 0x20<link>
        ether 08:00:27:4e:66:a1  txqueuelen 1000  (Ethernet)
        RX packets 67890  bytes 12345678 (12.3 MB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 54321  bytes 9876543 (9.8 MB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

**`lo`** è l'interfaccia di loopback, utilizzata per la comunicazione interna al sistema; svolge un ruolo cruciale, permettendo alla macchina di comunicare con se stessa.

**`enp0s3`** è l'interfaccia esposta all'interno della LAN. Nel contesto di una scuola superiore, l'assegnazione di un indirizzo IP con una maschera di sottorete `/16` su questa interfaccia solleva alcune considerazioni peculiari:

1. Nel mondo *classful*, l'indirizzo `10.0.0.0` avrebbe naturalmente una netmask`/8`(`255.0.0.0`), che fa parte della classe A, fornendo fino a 16,777,214 indirizzi IP utilizzabili (`2^24 - 2` host disponibili). Utilizzare una maschera `/16` in questo contesto si discosta dall'approccio classful, indicando una personalizzazione specifica per esigenze particolari. Tuttavia, anche in una prospettiva *classless*, l'allocazione di un blocco `/16` può essere considerata eccessiva per una scuola, poiché fornisce 65,534 indirizzi IP utilizzabili, ben oltre il necessario per la maggior parte delle reti scolastiche.

2. Avere un unico **dominio di broadcast a livello 2** può portare a sfide di gestione della rete, come l'aumento del traffico di broadcast, che potrebbe degradare le prestazioni della rete. In un ambiente scolastico, dove la sicurezza e l'efficienza della rete dovrebbero essere elementi cruciali, implementare una struttura di rete più segmentata, con l'uso di VLAN o subnet più ridotte, potrebbe migliorare notevolmente la gestione della rete e la sua sicurezza.