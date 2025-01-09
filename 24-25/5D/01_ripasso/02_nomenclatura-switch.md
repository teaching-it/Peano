# **Nomenclatura degli Switch**

### **1. Switch Classico (Unmanaged Switch)**

- **Descrizione**: Switch base non configurabile, noto anche come **switch classico**.
- **Funzionalità**:
  - Plug-and-play.
  - Smistamento dei pacchetti basato sugli indirizzi MAC (bridge).
- **Limiti**:
  - Nessun supporto per VLAN, QoS o altre funzionalità avanzate.
  - Impossibile configurare o monitorare lo switch.
- **Utilizzo**:
  - Reti domestiche o piccole reti dove non servono configurazioni personalizzate.

---

### **2. Switch Managed**

Gli **switch managed** sono configurabili tramite interfacce di gestione (web, CLI, SNMP). Possono offrire funzionalità di Livello 2, Livello 3 o una combinazione di entrambi.

#### **2.1. Layer 2 Switch (L2 Switch)**

- **Descrizione**:  
  Opera esclusivamente al **Livello 2 del modello OSI**, basandosi sugli indirizzi MAC per smistare i dati (switching/bridging).  
  Sebbene sia gestito, non include funzionalità di routing tra VLAN.

- **Principali funzionalità**:
  - **VLAN** (configurazione tramite Access e Trunk port).
  - **STP/RSTP** (Spanning Tree Protocol / Rapid STP) per la prevenzione dei loop.
  - **Port Security** (controllo MAC, limiti di accesso).
  - **QoS (Quality of Service)** per prioritizzare alcuni tipi di traffico.
  - **Link Aggregation** (LACP) per combinare più porte in un'unica interfaccia logica.
  - Riduce il dominio di collisione, ottimizzando il traffico locale.

- **Limiti**:
  - Nessun routing tra VLAN (serve un router o uno switch L3 esterno).
  - Non supporta protocolli di routing dinamico.
  
- **Utilizzo**:
  - Piccole e medie reti dove il routing non è necessario o è demandato ad altri dispositivi.
  - Segmentazione di rete (VLAN) e controllo di base del traffico a livello 2.

---

#### **2.2. Layer 2+ Switch (L2+ Switch)**

- **Descrizione**:  
  Combina le funzionalità di livello 2 con alcune capacità di **Livello 3** limitate, in genere il routing statico e il controllo degli accessi.

- **Principali funzionalità**:
  - Tutte le funzionalità di un L2 Switch.
  - **Routing statico** (ad esempio, tra VLAN) senza bisogno di un router dedicato.
  - **Inter-VLAN routing** per facilitare la comunicazione tra reti logiche diverse.
  - **ACL (Access Control List)** per filtrare il traffico in base a indirizzi IP o MAC.
  - **SNMP** per il monitoraggio e la gestione da remoto.
  - **Monitoraggio delle porte** e **port mirroring** per l’analisi del traffico.

- **Limiti**:
  - Generalmente non supporta routing dinamico (OSPF, RIP, BGP), o lo supporta in modo molto limitato.
  
- **Utilizzo**:
  - Ambienti che richiedono routing base (statico) tra più VLAN.
  - Reti di medie dimensioni che necessitano di un controllo più granulare rispetto a un semplice L2 Switch.

---

#### **2.3. Layer 2+3 Switch (L3 Switch)**

- **Descrizione**:  
  Integrazione completa di funzionalità di Livello 2 e Livello 3. Di fatto, **un L2+L3 Switch è anche chiamato “Layer 3 Switch” o “Multilayer Switch”**, perché può svolgere sia switching a livello MAC sia routing a livello IP.

- **Principali funzionalità**:
  - **Routing dinamico**: supporto per protocolli come **OSPF**, **RIP**, **EIGRP**, e **BGP** (a seconda del vendor e del modello).
  - **DHCP Server/Relay** per la gestione dinamica degli indirizzi IP in LAN.
  - **Multicast Routing** (es. **PIM**) per streaming video e altre applicazioni multicast.
  - Gestione avanzata di **QoS** (es. VoIP, video conferencing).
  - **Firewall integrato** o funzioni di filtraggio (opzionali, dipende dal modello).
  - **NAT (Network Address Translation)** per la traduzione da IP privati a IP pubblici.
  - **IPv6 compatibilità** per reti moderne o ibride (IPv4/IPv6).

- **Utilizzo**:
  - Grandi reti aziendali o infrastrutture complesse che richiedono routing avanzato, alte prestazioni e funzionalità di sicurezza e gestione.
  - Sostituisce o affianca il router tradizionale nella LAN, riducendo la latenza e semplificando l'architettura di rete.

---

## **Riepilogo**

| **Tipo di Switch**       | **Funzionalità Principali**                                                                              | **Utilizzo**                           |
|---------------------------|---------------------------------------------------------------------------------------------------------|----------------------------------------|
| **Switch Classico**       | Plug-and-play, nessuna configurazione                                                                  | Reti domestiche, semplici              |
| **L2 Switch**             | Smistamento MAC, VLAN, STP/RSTP, QoS, Port Security, LACP                                              | Piccole/medie reti, segmentazione L2   |
| **L2+ Switch**            | L2 + routing statico, Inter-VLAN routing, ACL, SNMP, port mirroring                                    | Reti di media complessità, routing base|
| **L3 Switch**             | L2 + routing dinamico (OSPF, RIP, BGP), DHCP, Multicast, QoS avanzato, NAT, VRRP/HSRP, IPv6            | Grandi reti aziendali e complesse      |

> **Nota**: Le funzionalità possono variare a seconda del produttore e del modello. Alcuni L3 Switch non includono tutte le funzioni di sicurezza (es. firewall), mentre altri L2+ potrebbero fornire un supporto parziale a protocolli di routing dinamico. Verificare sempre le specifiche del dispositivo.
