# Linux - comandi fondamentali di networking

---

## 1. Configurazione delle interfacce di rete

Per visualizzare le interfacce di rete:

```bash
/sbin/ifconfig
```

oppure, se `/sbin` è presente nel `PATH`:

```bash
ifconfig
```

Una tipica interfaccia Ethernet della VM VirtualBox può essere:

```text
enp0s3
```

Esempio:

```text
enp0s3: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 10.0.22.45  netmask 255.255.255.0  broadcast 10.0.22.255
        inet6 fe80::a00:27ff:fe12:3456  prefixlen 64
        ether 08:00:27:12:34:56
```

Le informazioni principali sono:

```text
enp0s3
```

nome dell'interfaccia.

```text
inet 10.0.22.45
```

indirizzo IPv4 assegnato all'host.

```text
netmask 255.255.255.0
```

maschera di rete.

Nel nostro caso:

```text
10.0.22.45/24
```

appartiene alla rete:

```text
10.0.22.0/24
```

```text
broadcast 10.0.22.255
```

indirizzo broadcast della rete.

```text
ether 08:00:27:12:34:56
```

indirizzo MAC dell'interfaccia.

---

## 2. `ip addr`

Il comando moderno equivalente è:

```bash
ip addr
```

forma abbreviata:

```bash
ip a
```

Esempio:

```text
2: enp0s3: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500
    link/ether 08:00:27:12:34:56
    inet 10.0.22.45/24 brd 10.0.22.255 scope global enp0s3
```

Le informazioni principali sono le stesse mostrate da `ifconfig`:

- nome dell'interfaccia;
- indirizzo MAC;
- indirizzo IPv4;
- prefisso di rete;
- indirizzo broadcast;
- stato dell'interfaccia.

Per visualizzare solamente l'interfaccia `enp0s3`:

```bash
ip addr show enp0s3
```

oppure:

```bash
ip a show enp0s3
```

---

## 3. Indirizzi IP dell'host

Per ottenere rapidamente gli indirizzi IP assegnati al computer:

```bash
hostname -I
```

Esempio:

```text
10.0.22.45
```

È utile quando interessa conoscere rapidamente l'indirizzo IP senza analizzare tutto l'output di `ifconfig` o `ip a`.

---

## 4. Tabella di routing

Per visualizzare la tabella di routing:

```bash
ip route
```

forma abbreviata:

```bash
ip ro
```

Esempio:

```text
default via 10.0.22.254 dev enp0s3
10.0.22.0/24 dev enp0s3 proto kernel scope link src 10.0.22.45
```

La prima riga:

```text
default via 10.0.22.254 dev enp0s3
```

indica la **default route**.

Il gateway predefinito è:

```text
10.0.22.254
```

e viene raggiunto tramite:

```text
enp0s3
```

La seconda riga:

```text
10.0.22.0/24 dev enp0s3
```

indica che la rete:

```text
10.0.22.0/24
```

è direttamente collegata all'interfaccia `enp0s3`.

In pratica:

```text
destinazione nella 10.0.22.0/24
        ↓
invio diretto tramite enp0s3
```

mentre:

```text
destinazione fuori dalla 10.0.22.0/24
        ↓
gateway 10.0.22.254
```

---

## 5. `route`

Il comando tradizionale equivalente è:

```bash
route -n
```

Esempio:

```text
Kernel IP routing table
Destination     Gateway         Genmask         Flags Iface
0.0.0.0         10.0.22.254     0.0.0.0         UG    enp0s3
10.0.22.0       0.0.0.0         255.255.255.0   U     enp0s3
```

La riga:

```text
0.0.0.0    10.0.22.254
```

rappresenta la default route.

`route` fa parte di `net-tools`; nei sistemi Linux moderni è normalmente preferibile:

```bash
ip route
```

---

## 6. Server DNS

Per visualizzare la configurazione DNS:

```bash
cat /etc/resolv.conf
```

Esempio:

```text
nameserver 10.0.22.254
nameserver 8.8.8.8
```

Le righe:

```text
nameserver ...
```

indicano i server DNS utilizzati dal sistema.

Il DNS permette di tradurre nomi come:

```text
www.debian.org
```

in indirizzi IP.

### Attenzione

Su alcuni sistemi `/etc/resolv.conf` può essere generato automaticamente da NetworkManager, systemd-resolved o altri servizi.

È quindi possibile trovare, ad esempio:

```text
nameserver 127.0.0.53
```

In questo caso il sistema utilizza un resolver DNS locale che inoltra successivamente le richieste ai DNS configurati.

---

## 7. Verifica della connettività con `ping`

Per verificare il gateway:

```bash
ping 10.0.22.254
```

Per verificare la connettività IP verso Internet:

```bash
ping 8.8.8.8
```

Per verificare anche la risoluzione DNS:

```bash
ping www.debian.org
```

Interrompere:

```text
CTRL+C
```

Questi tre test permettono di verificare aspetti differenti.

### Gateway

```bash
ping 10.0.22.254
```

verifica la comunicazione con il router della rete locale.

### Internet tramite indirizzo IP

```bash
ping 8.8.8.8
```

verifica che esista una connettività IP verso l'esterno.

### Internet tramite hostname

```bash
ping www.debian.org
```

richiede anche il corretto funzionamento del DNS.

Una possibile sequenza di verifica è:

```text
ping gateway
      ↓
ping IP Internet
      ↓
ping hostname Internet
```

---

## 8. Risoluzione DNS

### `nslookup`

Per interrogare il DNS:

```bash
nslookup www.debian.org
```

Mostra il server DNS utilizzato e gli indirizzi restituiti.

Esempio:

```text
Server:  10.0.22.254

Name:    www.debian.org
Address: 151.101.x.x
```

### `dig`

Un comando più completo è:

```bash
dig www.debian.org
```

Per ottenere solamente gli indirizzi:

```bash
dig +short www.debian.org
```

Se il comando non è disponibile:

```bash
apt install dnsutils
```

---

## 9. Percorso dei pacchetti

Per osservare attraverso quali router passa il traffico:

```bash
traceroute www.debian.org
```

Se non presente:

```bash
apt install traceroute
```

Un'alternativa è:

```bash
tracepath www.debian.org
```

L'output mostra progressivamente i router attraversati:

```text
host Linux
    ↓
gateway 10.0.22.254
    ↓
router successivi
    ↓
destinazione
```

---

## 10. Tabella dei vicini

Per visualizzare gli host della rete locale di cui Linux conosce l'indirizzo MAC:

```bash
ip neigh
```

Esempio:

```text
10.0.22.254 dev enp0s3 lladdr aa:bb:cc:dd:ee:ff REACHABLE
```

Sono visibili:

```text
10.0.22.254
```

indirizzo IP.

```text
aa:bb:cc:dd:ee:ff
```

indirizzo MAC.

```text
enp0s3
```

interfaccia utilizzata.

Il comando permette quindi di osservare l'associazione:

```text
indirizzo IPv4 ↔ indirizzo MAC
```

per gli host conosciuti nella rete locale.

---

## 11. `arp`

Il comando tradizionale è:

```bash
arp -n
```

Esempio:

```text
Address       HWaddress            Iface
10.0.22.254   aa:bb:cc:dd:ee:ff   enp0s3
```

`arp` appartiene al pacchetto `net-tools`.

Il comando moderno equivalente è:

```bash
ip neigh
```

---

## 12. Installazione e utilizzo di `curl`

`curl` è un client da riga di comando che permette di effettuare richieste utilizzando diversi protocolli applicativi, tra cui HTTP e HTTPS.

Installarlo:

```bash
apt install curl
```

Effettuare una richiesta HTTP:

```bash
curl http://example.com
```

Il comando apre una connessione verso il server HTTP e visualizza il contenuto restituito.

HTTP utilizza normalmente:

```text
TCP 80
```

Per visualizzare maggiori informazioni sulla connessione:

```bash
curl -v http://example.com
```

L'opzione:

```text
-v
```

attiva la modalità **verbose**.

Nell'output è possibile osservare informazioni come:

```text
Trying ...
Connected to example.com (...) port 80
```

e la richiesta HTTP:

```text
GET / HTTP/1.1
Host: example.com
```

seguita dalla risposta del server.

Per visualizzare solamente gli header HTTP:

```bash
curl -I http://example.com
```

È possibile trovare, ad esempio:

```text
HTTP/1.1 200 OK
```

oppure un redirect:

```text
HTTP/1.1 301 Moved Permanently
```

### Test esplicito della porta 80

È anche possibile indicare esplicitamente la porta:

```bash
curl http://example.com:80
```

oppure:

```bash
curl -v http://example.com:80
```

---

## 13. Verifica di una porta TCP con Netcat

Per verificare direttamente se una determinata porta TCP è raggiungibile è possibile utilizzare `nc`, Netcat.

Per esempio:

```bash
nc -vz example.com 80
```

Le opzioni:

```text
-v    output dettagliato
-z    verifica la porta senza inviare dati applicativi
```

Il comando verifica quindi la possibilità di stabilire una connessione TCP verso:

```text
example.com:80
```

Il test è diverso da:

```bash
ping example.com
```

`ping` verifica la raggiungibilità IP.

`nc` permette invece di verificare una **porta TCP specifica**.

`curl`, infine, utilizza realmente il protocollo applicativo HTTP.

In forma semplificata:

```text
ping
 ↓
host raggiungibile?

nc -vz host 80
 ↓
porta TCP 80 raggiungibile?

curl http://host
 ↓
servizio HTTP funzionante?
```

---

## 14. Porte e servizi in ascolto con `netstat`

Per visualizzare le porte sulle quali il computer locale è in ascolto:

```bash
netstat -tulpn
```

Le opzioni sono:

```text
-t    TCP
-u    UDP
-l    socket in ascolto
-p    processo associato
-n    indirizzi e porte numerici
```

Un possibile output può essere:

```text
tcp   0   0   0.0.0.0:22   0.0.0.0:*   LISTEN   650/sshd
```

Significa che il processo:

```text
sshd
```

è in ascolto sulla porta:

```text
TCP 22
```

Per cercare una porta specifica, ad esempio la porta 80:

```bash
netstat -tulpn | grep :80
```

### Attenzione

Il comando:

```bash
curl http://example.com
```

crea una connessione **in uscita** dalla macchina Linux verso la porta `80` del server remoto.

Non significa quindi che il computer Linux debba avere una propria porta 80 in ascolto.

---

## 15. `ss`

L'alternativa moderna a `netstat` è:

```bash
ss -tulpn
```

Per cercare una porta specifica:

```bash
ss -tulpn | grep :80
```

`netstat -tulpn` e `ss -tulpn` sono utili soprattutto per individuare i **servizi locali che aspettano connessioni**.

---

## 16. Connessioni TCP attive

Per visualizzare le connessioni TCP:

```bash
netstat -tn
```

oppure:

```bash
ss -tn
```

Prima di eseguire il comando, in un altro terminale è possibile generare traffico HTTP:

```bash
curl -v http://example.com
```

Durante la connessione potrebbe comparire una riga simile a:

```text
Local Address          Foreign Address        State
10.0.22.45:52314       93.184.216.34:80        ESTABLISHED
```

È possibile leggere:

```text
10.0.22.45:52314
```

socket locale: indirizzo IP della macchina e porta temporanea scelta dal client.

```text
93.184.216.34:80
```

socket remoto: indirizzo del server HTTP e porta `80`.

```text
ESTABLISHED
```

stato della connessione TCP.

Si può quindi osservare concretamente:

```text
CLIENT LINUX                         SERVER HTTP

10.0.22.45:52314  ───────────────>  x.x.x.x:80
 porta temporanea                     porta HTTP
```

---

## 17. Nome dell'host

Per visualizzare il nome del computer:

```bash
hostname
```

Per visualizzare informazioni più complete:

```bash
hostnamectl
```

Esempio:

```text
Static hostname: debian13
Operating System: Debian GNU/Linux 13
```

Per visualizzare gli indirizzi IP assegnati all'host:

```bash
hostname -I
```

---

## 18. Stato del link

Per visualizzare le interfacce e il loro stato:

```bash
ip link
```

oppure:

```bash
ip link show
```

Esempio:

```text
2: enp0s3: <BROADCAST,MULTICAST,UP,LOWER_UP>
```

Le indicazioni:

```text
UP
LOWER_UP
```

indicano che l'interfaccia è attiva e che il collegamento è presente.

Per una singola interfaccia:

```bash
ip link show enp0s3
```

---

## 19. Informazioni sull'interfaccia Ethernet

Per ottenere informazioni più specifiche sul collegamento Ethernet:

```bash
ethtool enp0s3
```

Se non installato:

```bash
apt install ethtool
```

Può mostrare informazioni come:

```text
Speed: 1000Mb/s
Duplex: Full
Link detected: yes
```

Permette quindi di controllare:

- velocità del link;
- half/full duplex;
- presenza del collegamento;
- caratteristiche dell'interfaccia.

Su una VM alcune informazioni dipendono dalla scheda virtuale utilizzata da VirtualBox.

---

## 20. Tabella riepilogativa

| Comando | Informazione principale |
|---|---|
| `/sbin/ifconfig` | configurazione delle interfacce |
| `ip a` | indirizzi e interfacce |
| `hostname -I` | indirizzi IP dell'host |
| `ip ro` | tabella di routing e default gateway |
| `route -n` | tabella di routing, comando tradizionale |
| `cat /etc/resolv.conf` | configurazione DNS |
| `ping` | raggiungibilità IP |
| `nslookup` | interrogazione DNS |
| `dig` | interrogazione DNS dettagliata |
| `traceroute` | percorso verso una destinazione |
| `tracepath` | percorso verso una destinazione |
| `ip neigh` | associazioni IP/MAC conosciute |
| `arp -n` | tabella ARP tradizionale |
| `curl http://host` | richiesta HTTP |
| `curl -v http://host` | richiesta HTTP con dettagli della connessione |
| `curl -I http://host` | header della risposta HTTP |
| `nc -vz host 80` | verifica della raggiungibilità della porta TCP 80 |
| `netstat -tulpn` | porte e servizi locali in ascolto |
| `ss -tulpn` | porte e servizi locali in ascolto |
| `netstat -tn` | connessioni TCP attive |
| `ss -tn` | connessioni TCP attive |
| `hostname` | nome dell'host |
| `hostnamectl` | informazioni sull'host |
| `ip link` | stato delle interfacce |
| `ethtool` | caratteristiche del link Ethernet |