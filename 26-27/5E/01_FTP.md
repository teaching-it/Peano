# FTP - laboratorio Windows / Debian 13 con vsftpd e Wireshark

---

## 1. Scenario

Il laboratorio utilizza:

```text
WINDOWS
Client FTP
FileZilla opzionale
        │
        │ rete LAN
        │
        │ VirtualBox - scheda con bridge
        │
DEBIAN 13 VM
Server FTP
vsftpd
Wireshark
```

La macchina virtuale Debian 13 utilizza una **scheda di rete con bridge** e riceve quindi un indirizzo IP appartenente alla stessa rete del computer Windows.

---

## 2. Verifica della rete

Su Debian:

```bash
ifconfig
```

Individuare l'indirizzo IPv4 della macchina virtuale.

Esempio:

```text
inet 192.168.1.120
```

Da Windows:

```cmd
ping 192.168.1.120
```

Verificare anche il percorso inverso.

Da Debian:

```bash
ping <IP-Windows>
```

Interrompere con:

```text
CTRL+C
```

Windows e Debian devono potersi raggiungere direttamente sulla LAN.

---

## 3. Installazione di vsftpd

Su Debian:

```bash
sudo apt update
```

Installare il server FTP:

```bash
sudo apt install vsftpd
```

Installare anche `net-tools`:

```bash
sudo apt install net-tools
```

Il pacchetto fornisce, tra gli altri:

```text
ifconfig
netstat
```

---

## 4. Verifica del servizio

Controllare lo stato di `vsftpd`:

```bash
systemctl status vsftpd
```

Il servizio dovrebbe risultare:

```text
active (running)
```

Se necessario:

```bash
sudo systemctl start vsftpd
```

Verificare ora le porte in ascolto.

Con `netstat`:

```bash
sudo netstat -tulpn
```

oppure:

```bash
sudo netstat -tulpn | grep :21
```

In alternativa con `ss`:

```bash
sudo ss -tulpn
```

oppure:

```bash
sudo ss -tulpn | grep :21
```

Dovrebbe comparire `vsftpd` in ascolto sulla porta TCP `21`.

Le opzioni principali utilizzate sono:

```text
-t    TCP
-u    UDP
-l    socket in ascolto
-p    processo associato
-n    indirizzi e porte numerici
```

---

## 5. Creazione di un utente FTP

Creare un utente dedicato:

```bash
sudo adduser ftpuser
```

Accedere come utente:

```bash
su - ftpuser
```

Creare un file:

```bash
echo "File creato sul server Debian" > server.txt
```

Verificare:

```bash
ls -l
```

```bash
cat server.txt
```

Tornare all'utente precedente:

```bash
exit
```

---

## 6. Configurazione di vsftpd

Aprire:

```bash
sudo nano /etc/vsftpd.conf
```

Verificare almeno:

```text
local_enable=YES
write_enable=YES
```

Salvare e riavviare:

```bash
sudo systemctl restart vsftpd
```

Controllare:

```bash
systemctl status vsftpd
```

Dopo ogni modifica al file di configurazione:

```text
modifica vsftpd.conf
        ↓
restart del servizio
        ↓
verifica con systemctl
        ↓
nuovo test dal client
```

---

## 7. Connessione da Windows

Aprire il prompt dei comandi di Windows.

Avviare il client FTP:

```cmd
ftp <IP-server>
```

Per esempio:

```cmd
ftp 192.168.1.120
```

Inserire le credenziali:

```text
User: ftpuser
Password: ********
```

Provare alcuni comandi:

```text
pwd
```

```text
dir
```

```text
ls
```

Per terminare:

```text
quit
```

---

## 8. Trasferimento di file

Sul computer Windows creare un file:

```text
client.txt
```

Collegarsi al server:

```cmd
ftp 192.168.1.120
```

Caricare il file:

```text
put client.txt
```

Verificare:

```text
dir
```

Scaricare il file presente sul server:

```text
get server.txt
```

Terminare:

```text
quit
```

Sul server Debian verificare:

```bash
ls -l /home/ftpuser
```

Dovrebbe essere presente anche:

```text
client.txt
```

---

## 9. Osservazione delle connessioni TCP

Aprire una sessione FTP da Windows e lasciarla attiva.

Su Debian aprire un secondo terminale.

Con `netstat`:

```bash
netstat -tn
```

oppure con `ss`:

```bash
ss -tn
```

Individuare la connessione verso la porta `21`.

Esempio:

```text
192.168.1.120:21    192.168.1.50:51432    ESTABLISHED
```

In questo caso:

```text
server FTP = 192.168.1.120:21
client     = 192.168.1.50:51432
```

La porta `51432` è una porta temporanea scelta dal client.

---

## 10. Prima cattura con Wireshark

Avviare **Wireshark su Debian**.

Selezionare l'interfaccia di rete utilizzata dalla VM.

È possibile individuarla anche tramite:

```bash
ifconfig
```

Avviare la cattura.

Utilizzare come display filter:

```text
tcp.port == 21
```

Da Windows collegarsi al server:

```cmd
ftp 192.168.1.120
```

Effettuare il login e poi uscire.

Interrompere la cattura.

Individuare inizialmente il three-way handshake TCP:

```text
SYN
SYN, ACK
ACK
```

Poi osservare il traffico FTP.

Dovrebbero comparire messaggi simili a:

```text
220
USER ftpuser
PASS ...
230
QUIT
```

---

## 11. Follow TCP Stream

Selezionare uno dei pacchetti della connessione FTP.

In Wireshark:

```text
Follow
→ TCP Stream
```

Osservare il dialogo completo tra client e server.

Dovrebbero essere visibili, tra gli altri:

```text
USER
PASS
PWD
QUIT
```

FTP tradizionale non cifra il canale di controllo.

Username e password possono quindi essere osservati nella cattura.

---

## 12. Connessione di controllo e connessione dati

Avviare una nuova cattura Wireshark su Debian.

Da Windows collegarsi nuovamente:

```cmd
ftp 192.168.1.120
```

Eseguire:

```text
dir
```

oppure:

```text
get server.txt
```

Osservare la cattura.

La connessione verso:

```text
TCP 21
```

rimane la **connessione di controllo**.

Per il listing della directory o per il trasferimento del file viene invece utilizzata una **seconda connessione TCP**.

```text
connessione di controllo
        +
connessione dati
```

Con `netstat`:

```bash
netstat -tn
```

oppure:

```bash
ss -tn
```

è possibile osservare contemporaneamente le connessioni attive.

---

## 13. Modalità FTP passiva

In modalità passiva il **client apre sia la connessione di controllo sia la connessione dati**.

Il server comunica al client una porta TCP sulla quale è pronto a ricevere la connessione dati; il client apre quindi una nuova connessione verso quella porta.

In forma semplificata:

```text
CLIENT                           SERVER

porta casuale ────────────────> TCP 21
       connessione controllo

porta casuale ────────────────> porta dati server
          connessione dati
```

Per osservare più facilmente il comportamento è possibile utilizzare **FileZilla Client su Windows**.

Configurare una connessione FTP verso Debian:

```text
Host:       IP Debian
Protocollo: FTP
Porta:      21
Utente:     ftpuser
Password:   password configurata
```

Impostare la modalità di trasferimento:

```text
Passiva
```

Avviare contemporaneamente Wireshark su Debian.

Eseguire:

- apertura di una directory;
- download di `server.txt`;
- upload di un file.

Nella connessione di controllo cercare:

```text
PASV
```

oppure:

```text
EPSV
```

Il server comunica al client la porta da utilizzare per la connessione dati.

Osservare quindi quale host invia il primo:

```text
SYN
```

della connessione dati.

---

## 14. Configurazione del passive range

Sul server aprire:

```bash
sudo nano /etc/vsftpd.conf
```

Aggiungere:

```text
pasv_enable=YES
pasv_min_port=50000
pasv_max_port=50100
```

Riavviare:

```bash
sudo systemctl restart vsftpd
```

Controllare:

```bash
systemctl status vsftpd
```

Effettuare nuovamente un trasferimento da FileZilla.

Durante il trasferimento:

```bash
netstat -tn
```

oppure:

```bash
ss -tn
```

Individuare la connessione dati.

La porta del server dovrebbe appartenere all'intervallo:

```text
50000-50100
```

Confermare il comportamento anche con Wireshark.

---

## 15. Modalità FTP attiva

In modalità attiva la connessione di controllo viene sempre aperta dal client verso il server, ma la **connessione dati viene aperta dal server verso il client**.

Il client comunica al server l'indirizzo e la porta TCP sulla quale è pronto a ricevere la connessione dati.

In forma semplificata:

```text
CLIENT                           SERVER

porta casuale ────────────────> TCP 21
       connessione controllo

porta dati client <──────────── server
         connessione dati
```

In FileZilla impostare:

```text
Modalità di trasferimento: Attiva
```

Avviare una nuova cattura Wireshark su Debian.

Eseguire nuovamente:

- listing di una directory;
- download;
- upload.

Nella connessione di controllo cercare:

```text
PORT
```

oppure:

```text
EPRT
```

Individuare quindi la connessione dati.

Osservare chi invia il primo:

```text
SYN
```

della connessione dati.

In questo caso il primo `SYN` deve partire dal **server FTP Debian** verso il client Windows.

---

## 16. Porta TCP 20

Nel funzionamento FTP attivo tradizionale la porta TCP `20` può essere utilizzata come porta sorgente della connessione dati del server.

In `vsftpd` è possibile configurare:

```text
connect_from_port_20=YES
```

nel file:

```text
/etc/vsftpd.conf
```

Dopo la modifica:

```bash
sudo systemctl restart vsftpd
```

Ripetere il test in modalità attiva.

Sul server:

```bash
netstat -tn
```

oppure:

```bash
ss -tn
```

Verificare anche con Wireshark quale porta sorgente utilizza il server.

L'affermazione:

```text
FTP usa le porte 20 e 21
```

è una semplificazione.

La porta `21` è normalmente utilizzata per la connessione di controllo.

La connessione dati dipende invece dalla modalità attiva/passiva e dalla configurazione utilizzata.

---

## 17. Arresto del servizio

Sul server:

```bash
sudo systemctl stop vsftpd
```

Controllare:

```bash
systemctl status vsftpd
```

Verificare la porta:

```bash
sudo netstat -tulpn | grep :21
```

oppure:

```bash
sudo ss -tulpn | grep :21
```

Da Windows:

```cmd
ping 192.168.1.120
```

Poi:

```cmd
ftp 192.168.1.120
```

Il ping può continuare a funzionare mentre FTP non è più disponibile.

```text
host raggiungibile
≠
servizio FTP disponibile
```

Riavviare:

```bash
sudo systemctl start vsftpd
```