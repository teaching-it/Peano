## Ping in broadcast

Dalla command line di Linux abbiamo effettuato un ping all'indirizzo di broadcast della rete dell'Istituto.

    root@linux:/home/user# ping -b 10.23.255.255

L'invio di un pacchetto ICMP (Internet Control Message Protocol) in modalità broadcast implica diversi passaggi importanti nel processo di incapsulamento e trasmissione del pacchetto all'interno della rete:

### 1. Creazione del pacchetto ICMP

Il dispositivo genera un messaggio ICMP Echo Request destinato all'indirizzo IP di broadcast della subnet, che è `10.23.255.255` per la subnet `10.23.255.255/16`.

### 2. Incapsulamento in un datagramma IP

Il messaggio ICMP viene incapsulato in un datagramme IP con l'indirizzo di destinazione impostato sull'indirizzo di broadcast della subnet, `10.23.255.255`.

### 3. Incapsulamento in un frame Ethernet

Prima di poter inviare il pacchetto sulla rete fisica, il dispositivo deve determinare a quale indirizzo MAC inviare il frame Ethernet. Poiché l'indirizzo IP di destinazione è un indirizzo di broadcast, il pacchetto IP viene incapsulato in un frame Ethernet con l'indirizzo MAC di destinazione impostato sull'indirizzo di broadcast Ethernet, ovvero `FF:FF:FF:FF:FF:FF`.

Il frame Ethernet generato (esito del processo di incapsulamento dei vari PDU) viene quindi inviato sulla rete locale.

### 5. Comportamento dello switch

Quando lo switch riceve il frame Ethernet destinato all'indirizzo MAC di broadcast `FF:FF:FF:FF:FF:FF`, lo "replica" su tutte le porte attive eccetto quella su cui ha ricevuto il frame. Questo significa che il frame viene inviato a tutti i dispositivi collegati alla stessa rete locale (LAN).

Gli switch moderni lavorano a livello 2 (Data Link) e non "comprendono" gli indirizzi IP; la loro decisione di inoltrare il frame a tutte le porte si basa sull'indirizzo MAC di destinazione. Non eseguono una vera e propria "replica" del pacchetto IP a livello di rete; si limitano a inoltrare il frame Ethernet a livello 2 a tutti i dispositivi connessi.

### 6. Ricezione e risposta dei dispositivi

Ogni dispositivo nella LAN riceve il frame Ethernet, estrae il pacchetto IP (deincapsula il PDU del livello superiore) e verifica l'indirizzo IP di destinazione. Poiché si tratta di un indirizzo di broadcast, il dispositivo controlla se deve o meno rispondere a pacchetti ICMP broadcast.

A seconda della configurazione del sistema operativo e delle politiche di sicurezza, alcuni dispositivi possono rispondere con un Echo Reply all'indirizzo IP sorgente del pacchetto ICMP originale. Tuttavia, molti sistemi operativi sono configurati per default per non rispondere ai ping di broadcast per evitare potenziali attacchi di rete e congestioni.

Il comportamento di default di Linux, ad esempio, è quello di rispondere alle richieste pervenute in broadcast. Windows, invece, in genere ignora e quindi scarta richieste di tal tipo.