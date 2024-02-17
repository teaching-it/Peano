# CLI Linux Debian (advanced)

    root@linux:/home/user# apt-get install net-tools

**`apt-get install net-tools`** installa il pacchetto `net-tools`, che fornisce importanti strumenti di rete, tra cui `ifconfig`. Questo comando è utilizzato per visualizzare o configurare le interfacce di rete.

    root@linux:/home/user# /sbin/ifconfig

**`/sbin/ifconfig`** mostra lo stato corrente delle interfacce di rete.

#### Breve inciso su interfaccia di loopback

L'interfaccia loopback su Linux è un'interfaccia di rete virtuale che il sistema utilizza per comunicare con se stesso. Questa interfaccia è comunemente usata per test di rete, sviluppo di applicazioni e altre situazioni in cui il traffico di rete non deve uscire dal host. L'indirizzo IP standard assegnato all'interfaccia loopback è 127.0.0.1 per IPv4 e ::1 per IPv6.

    user@linux:~$ ping -c 4 google.com

**`ping`** è utilizzato per testare la connettività di rete verso un host. L'opzione `-c 4` limita il numero di echo requests a 4. Questo comando mostra il tempo di round-trip dei pacchetti inviati a `google.com`.

    root@linux:/home/user# apt-get install tcpdump

**`apt-get install tcpdump`** installa `tcpdump`, uno strumento da riga di comando per catturare e analizzare pacchetti di rete.

    root@linux:/home/user# tcpdump -i enp0s3 icmp

**`tcpdump -i enp0s3 icmp`** avvia `tcpdump` per catturare il traffico ICMP (come ping) sull'interfaccia `enp0s3`.

    root@linux:/home/user# apt-get install apache2

**`apt-get install apache2`** installa il server web Apache2.

    user@linux:~$ systemctl status apache2

**`systemctl status apache2`** verifica lo stato del servizio Apache2, mostrando se è attivo e in esecuzione.

    user@linux:~$ ps aux

**`ps aux`** mostra tutti i processi in esecuzione sul sistema.

    user@linux:~$ ps aux | more

**`ps aux | more`** usa il comando `more` per paginare l'output di `ps aux`, rendendolo più leggibile se l'elenco dei processi è lungo.

    user@linux:~$ ps aux | grep apache2

**`ps aux | grep apache2`** filtra l'output di `ps aux` per mostrare solo i processi relativi ad Apache2.

user@linux:~$ netstat -na

**`netstat -na`** mostra tutte le connessioni di rete e le porte in ascolto.

    user@linux:~$ netstat -na | grep 80

**`netstat -na | grep 80`** filtra l'output di `netstat -na` per mostrare solo le connessioni relative alla porta 80 (HTTP).

    user@linux:~$ netstat -nap | grep apache2

**`netstat -nap | grep apache2`** mostra le connessioni di rete associate ad Apache2, inclusi i PID dei processi.

## Wireshark

Wireshark è uno degli strumenti di analisi di rete più noti e utilizzati. Fornisce la capacità di catturare e ispezionare in dettaglio i pacchetti che transitano su una rete in tempo reale. Wireshark è utilizzato sia da professionisti della sicurezza per analizzare il traffico sospetto e identificare tentativi di intrusione, sia da amministratori di rete per risolvere problemi di rete e ottimizzare le prestazioni. Con una interfaccia grafica intuitiva e la capacità di filtrare e analizzare il traffico secondo vari protocolli, Wireshark è uno strumento indispensabile per chi lavora nel campo IT.

    root@linux:/home/user# apt-get install wireshark

**Installazione di Wireshark**: Il comando installa Wireshark e tutte le dipendenze necessarie. Durante l'installazione, potrebbe chiedere se si desidera consentire agli utenti non privilegiati di catturare pacchetti. Selezionare la propria preferenza in base alle proprie esigenze di sicurezza e utilizzo.