# Livelli del modello TCP/IP, Protocolli e PDU

## Livello 5: Applicativo

- **Funzione**: Interfaccia tra l'utente e la rete, gestione delle applicazioni.
- **Protocolli**:
  - HTTP/HTTPS (navigazione web)
  - FTP (trasferimento file)
  - SMTP, POP3, IMAP (email)
  - DNS (risoluzione dei nomi)
  - DHCP (assegnazione dinamica degli IP)
  - Telnet/SSH (accesso remoto)
- **PDU**: **Messaggio**

---

## Livello 4: Trasporto

- **Funzione**: Gestione del trasporto dati end-to-end; affidabilità e controllo degli errori.
- **Protocolli**:
  - TCP (orientato alla connessione, affidabile)
  - UDP (non orientato alla connessione, rapido)
- **PDU**:
  - TCP: **Segmento**
  - UDP: **Datagramma**

---

## Livello 3: Internet (Rete)

- **Funzione**: Instradamento e indirizzamento logico dei pacchetti attraverso la rete.
- **Protocolli**:
  - IPv4, IPv6 (instradamento e indirizzamento)
  - ICMP (gestione degli errori e diagnostica)
  - ARP (risoluzione indirizzi IP in MAC)
  - RARP (risoluzione inversa, MAC in IP)
- **PDU**: **Pacchetto**

---

## Livello 2: Collegamento Dati

- **Funzione**: Trasferimento dei dati tra nodi direttamente connessi; identificazione e correzione degli errori.
- **Protocolli**:
  - Ethernet (IEEE 802.3)
  - Wi-Fi (IEEE 802.11)
  - PPP (connessioni punto-punto)
  - ATM (reti ad alta velocità)
- **PDU**: **Frame**

---

## Livello 1: Fisico

- **Funzione**: Trasmissione dei bit attraverso il mezzo fisico (cavo, fibra ottica, onde radio).
- **Protocolli**:
  - Non ci sono protocolli specifici ma standard fisici (e.g., IEEE 802.3 per Ethernet, IEEE 802.11 per Wi-Fi).
- **PDU**: **Bit**

---

## Riepilogo generale

| **Livello TCP/IP**    | **Funzione**                 | **Protocolli tipici** | **PDU**              |
|------------------------|-----------------------------|------------------------|----------------------|
| **5: Applicativo**     | Interazione con l’utente    | HTTP, FTP, DNS, SMTP   | Messaggio            |
| **4: Trasporto**       | Trasporto end-to-end        | TCP, UDP               | Segmento/Datagramma  |
| **3: Internet**        | Instradamento e indirizzi   | IPv4, IPv6, ICMP, ARP  | Pacchetto            |
| **2: Collegamento Dati** | Trasferimento dati locale   | Ethernet, Wi-Fi, PPP   | Frame                |
| **1: Fisico**          | Trasmissione fisica         | (Standard fisici)      | Bit                  |
