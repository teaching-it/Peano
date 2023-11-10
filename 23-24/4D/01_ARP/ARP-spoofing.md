# ARP Spoofing

## Cos'è l'ARP Spoofing?

L'ARP Spoofing, noto anche come ARP Poisoning, è un tipo di attacco di rete in cui un malintenzionato invia messaggi ARP (Address Resolution Protocol) falsificati. Questo attacco è mirato a modificare la tabella ARP di altri dispositivi nella rete, consentendo all'attaccante di intercettare, modificare o bloccare il traffico di rete.

## Come Funziona?

- **Messaggi Falsificati**: L'attaccante invia messaggi ARP falsificati alla rete, affermando di avere l'indirizzo IP di un altro dispositivo (come un gateway).
- **Intercezione Traffico**: I dispositivi nella rete inviano traffico all'attaccante, pensando che sia il dispositivo legittimo.
- **Risultato**: L'attaccante può intercettare, esaminare o modificare i dati, o anche bloccare il traffico.

## Vulnerabilità del Protocollo ARP

- **Natura di Fiducia**: Il protocollo ARP è intrinsecamente vulnerabile agli attacchi di spoofing a causa della sua natura basata sulla fiducia. ARP non prevede un meccanismo di autenticazione per verificare l'identità dei dispositivi che rispondono alle richieste ARP.
- **Implementazione nei Sistemi Operativi**: La maggior parte dei sistemi operativi, inclusi Windows, macOS e Linux, accettano risposte ARP senza verificarne l'autenticità. Questo significa che un dispositivo nella rete può facilmente rispondere a una richiesta ARP con informazioni false, portando alla modifica della tabella ARP del dispositivo che ha effettuato la richiesta.
- **Aggiornamenti Automatici**: I dispositivi aggiornano automaticamente le loro tabelle ARP quando ricevono risposte ARP, anche se non hanno inviato una richiesta ARP. Questo comportamento è sfruttato dagli attacchi di ARP spoofing per forzare i dispositivi a modificare le associazioni IP-MAC nelle loro tabelle ARP.
- **Mancanza di Sicurezza Integrata**: Il protocollo ARP è stato progettato in un'epoca in cui la sicurezza di rete non era una preoccupazione primaria, e di conseguenza, non include misure di sicurezza robuste per prevenire tali attacchi.

## Impatto

- **Violazione della Privacy**: Intercezione di dati sensibili.
- **Attacchi Man-in-the-Middle (MitM)**: Modifica o alterazione dei dati in transito.
- **Denial of Service (DoS)**: Interruzione della comunicazione di rete.

## Scenario Pratico: Impersonificazione del Default Gateway

- **Situazione**: In una rete aziendale, il default gateway ha l'indirizzo IP `192.168.1.1` e l'indirizzo MAC `00:1A:2B:3C:4D:5E`.
- **Attaccante**: L'attaccante si trova sulla stessa rete LAN e ha l'indirizzo MAC `AA:BB:CC:DD:EE:FF`.
- **Attacco**: Utilizzando un tool di ARP spoofing, l'attaccante invia messaggi ARP falsificati a tutti i dispositivi nella rete, affermando che l'indirizzo MAC `AA:BB:CC:DD:EE:FF` corrisponde all'indirizzo IP del gateway `192.168.1.1`.
- **Modifica Tabella ARP**: I dispositivi nella rete aggiornano le loro tabelle ARP, sostituendo l'indirizzo MAC del gateway reale (`00:1A:2B:3C:4D:5E`) con quello dell'attaccante (`AA:BB:CC:DD:EE:FF`).
- **Intercezione Traffico**: Ora, tutto il traffico destinato al gateway `192.168.1.1` viene inviato all'attaccante.
- **Conseguenze**: L'attaccante può leggere, modificare o bloccare il traffico Internet destinato al gateway, accedendo a informazioni sensibili o interrompendo le comunicazioni.

## Strategie di Mitigazione ARP Spoofing

### 1. Static ARP Entries

- **Descrizione**: Impostazione manuale delle associazioni ARP nei dispositivi. Questo processo implica la configurazione manuale dell'associazione tra indirizzi IP e indirizzi MAC nei dispositivi, rendendo le tabelle ARP immuni a modifiche non autorizzate.
- **Benefici**: Previene l'accettazione di risposte ARP non sollecitate e riduce il rischio di attacchi di ARP spoofing, specialmente per dispositivi critici come server e gateway.
- **Limitazioni**: Non scalabile in grandi reti e richiede una gestione manuale.

### 2. VLANs

- **Descrizione**: Utilizzo di Virtual Local Area Networks (VLANs) per segmentare logicamente una rete fisica in più reti separate. Questo limita il traffico di broadcast a una singola VLAN.
- **Benefici**: Riduce l'area di impatto degli attacchi ARP spoofing, poiché un attaccante può influenzare solo i dispositivi nella stessa VLAN.
- **Applicazioni**: Particolarmente utile in ambienti con diversi dipartimenti o gruppi di lavoro, dove il traffico può essere isolato per motivi di sicurezza e organizzazione.

### 3. Security Software and Inspection Tools

- **Descrizione**: Utilizzo di software di sicurezza, come firewall, sistemi di prevenzione delle intrusioni (IPS) e strumenti di monitoraggio della rete, che possono rilevare schemi di traffico anomali o attività sospette legate all'ARP spoofing.
- **Benefici**: Fornisce un livello di difesa automatizzato e proattivo contro gli attacchi ARP spoofing.
- **Esempi**: Strumenti come Wireshark per il monitoraggio del traffico, Snort come IPS, o soluzioni di sicurezza aziendale che includono funzionalità di rilevamento ARP spoofing.

### 4. DHCP Snooping + Dynamic ARP Inspection

- **Descrizione**: Il DHCP snooping è una funzione di sicurezza che crea una tabella di binding affidabile associando gli indirizzi IP agli indirizzi MAC. Il Dynamic ARP Inspection (DAI) utilizza questa tabella per validare le risposte ARP, assicurando che corrispondano alle associazioni conosciute e legittime.
- **Benefici**: Previene efficacemente l'ARP spoofing validando le associazioni ARP contro una fonte affidabile, proteggendo la rete da risposte ARP false o malevole.
- **Configurazione**: Richiede la configurazione su switch di rete che supportano queste funzionalità, ideale per ambienti aziendali o reti di medie/grandi dimensioni.
