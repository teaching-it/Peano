# **Storage (SSD/HDD)**

Lo storage è uno dei componenti più importanti per le prestazioni complessive di un sistema, influenzando direttamente la velocità di caricamento del sistema operativo, dei programmi e dei dati. Ecco un approfondimento sui principali aspetti da considerare.

---

## **Tipologie di Storage**

1. **HDD (Hard Disk Drive):**
   - **Caratteristiche:**
     - Dispositivi di archiviazione meccanici con piatti magnetici.
     - Capacità elevate a costi ridotti.
     - Velocità di lettura/scrittura relativamente bassa (tipicamente 100-150 MB/s).
   - **Ideale per:**
     - Archiviazione di grandi quantità di dati (film, foto, backup).
     - Applicazioni non critiche in termini di velocità.

2. **SSD (Solid State Drive):**
   - **Caratteristiche:**
     - Dispositivi di archiviazione elettronici senza parti mobili.
     - Velocità di lettura/scrittura molto più alte rispetto agli HDD.
   - **Tipologie comuni:**
     - **SATA SSD:** Collegati tramite interfaccia SATA, con velocità fino a **550 MB/s**.
     - **NVMe SSD (M.2):** Collegati tramite interfaccia PCIe, con velocità fino a **7000 MB/s** (a seconda della generazione PCIe).
   - **Ideale per:**
     - Sistema operativo e programmi.
     - Applicazioni che richiedono alte prestazioni (es. editing video, gaming).

---

## **Interfaccia**

- **SATA:**
  - Standard utilizzato per HDD e SSD tradizionali.
  - Velocità massima teorica: **6 Gbps** (~550 MB/s).
  - Supportato dalla maggior parte delle schede madri.

- **NVMe (M.2):**
  - Utilizza l'interfaccia PCIe (fino a PCIe 5.0) per trasferimenti ultraveloci.
  - Velocità teorica:
    - PCIe 3.0: Fino a **3500 MB/s**.
    - PCIe 4.0: Fino a **7000 MB/s**.
    - PCIe 5.0: Fino a **12.000 MB/s** (supporto limitato a hardware di ultima generazione).
  - Compatibilità: Verifica che la scheda madre abbia slot M.2 disponibili e supporti l'interfaccia NVMe.

---

## **Capacità**

- **HDD:** Disponibili in tagli da **500 GB** fino a **20 TB** o più.
- **SSD:**
  - SATA SSD: Capacità tipiche da **120 GB** a **4 TB**.
  - NVMe SSD: Capacità tipiche da **256 GB** a **8 TB**.

- **Consigli di Capacità:**
  - **Sistema operativo:** Minimo 256 GB (preferibilmente un SSD NVMe).
  - **Gaming:** Almeno 1 TB (ideale combinazione di SSD per giochi principali e HDD per backup).
  - **Editing/Rendering:** Almeno 2 TB (possibilmente NVMe per velocità elevate).

---

## **Slot disponibili**

- **SATA Ports:**
  - Verifica che ci siano abbastanza porte SATA libere sulla scheda madre.
  - Ogni porta SATA può supportare un dispositivo (HDD o SSD).

- **Slot M.2:**
  - Le schede madri moderne hanno da 1 a 4 slot M.2.
  - Gli slot possono supportare NVMe, SATA, o entrambi: verifica le specifiche nel manuale della scheda madre.

---

### **Compatibilità dimensionale per M.2**

- Gli SSD M.2 sono disponibili in diverse lunghezze standard:
  - **2280:** Il formato più comune (22 mm di larghezza, 80 mm di lunghezza).
  - **22110:** Più lungo (110 mm), usato raramente in applicazioni desktop.
- Verifica che lo slot M.2 sulla scheda madre supporti la lunghezza dell’SSD scelto.

---

### **Velocità e Prestazioni**

1. **Velocità sequenziali:**
   - Importanti per operazioni come il trasferimento di file di grandi dimensioni.
   - Gli SSD NVMe PCIe 4.0 e 5.0 offrono le velocità sequenziali più alte.

2. **Velocità casuali (IOPS):**
   - Misurano il numero di operazioni di input/output al secondo.
   - Cruciali per il caricamento di piccoli file, come durante l’avvio del sistema operativo o l’apertura di programmi.

3. **Durabilità (TBW):**
   - **TBW (Terabytes Written):** Indica quanti dati possono essere scritti sull’unità prima che inizi a degradarsi.
   - Gli SSD di fascia alta hanno TBW più elevati, garantendo maggiore durata.

---

### **Esempio Pratico**

Supponiamo di configurare un sistema per uso gaming e produttività:

- **Configurazione consigliata:**
  - **1x NVMe SSD (1 TB):** Per il sistema operativo e i giochi principali (es. PCIe 4.0).
  - **1x HDD (2 TB):** Per archiviazione di file, backup e contenuti multimediali.
- **Verifica:**
  - La scheda madre ha almeno 1 slot M.2 compatibile con NVMe PCIe 4.0.
  - Ci sono almeno 2 porte SATA libere per aggiungere HDD o SSD SATA.
