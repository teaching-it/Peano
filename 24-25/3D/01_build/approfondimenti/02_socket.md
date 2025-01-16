# Cos'è il Socket?

Il **socket** è il connettore fisico sulla scheda madre che collega la CPU (processore) alla scheda madre stessa. Ogni tipo di socket è progettato per essere compatibile con un insieme specifico di CPU, in base al produttore (Intel o AMD), alla generazione e al modello.

---

## **Caratteristiche principali del socket**

1. **Forma e design:**
   - Il socket definisce la **forma fisica** e il **layout dei pin** o contatti che collegano il processore alla scheda madre.
   - Esistono due tipi principali:
     - **LGA (Land Grid Array):** I pin si trovano sulla scheda madre e la CPU ha contatti piatti. Utilizzato da Intel.
     - **PGA (Pin Grid Array):** I pin si trovano sul processore e la scheda madre ha fori corrispondenti. Utilizzato da AMD fino alla serie Ryzen AM4.
     - **BGA (Ball Grid Array):** Socket in cui la CPU è saldata alla scheda madre (non sostituibile, usato in sistemi integrati).

2. **Compatibilità:**
   - Il socket è specifico per una generazione e un'architettura di CPU. Ad esempio:
     - **Intel LGA1700:** Compatibile con processori Intel Core di 12ª e 13ª generazione.
     - **AMD AM4:** Compatibile con processori Ryzen di prima, seconda, terza e quarta generazione (con limitazioni su alcune schede madri).
   - Anche CPU della stessa serie potrebbero richiedere un socket diverso tra generazioni (es. Intel cambia socket più frequentemente rispetto ad AMD).

3. **Installazione del processore:**
   - Il socket è progettato per mantenere la CPU in posizione e assicurare una connessione stabile.
   - Spesso include un **meccanismo di blocco** per proteggere la CPU e garantire un buon contatto.

4. **Compatibilità con il dissipatore:**
   - Il socket determina anche il tipo di **dissipatore** che puoi installare. Alcuni socket richiedono dissipatori con design specifici o staffe aggiuntive.

---

## **Perché è importante il socket?**

1. **Scelta della CPU:** Non tutte le CPU funzionano su tutte le schede madri. Devi assicurarti che il socket della scheda madre sia compatibile con il tuo processore.
2. **Upgrade futuro:** La scelta di un socket diffuso e supportato a lungo (es. AMD AM4) può facilitare gli aggiornamenti del processore senza dover cambiare scheda madre.
3. **Efficienza termica:** Un socket ben progettato consente una corretta dissipazione del calore attraverso un dissipatore adeguato.

---

## **Esempi di socket popolari**

### Intel

- **LGA1700:** Utilizzato per processori Intel Core di 12ª e 13ª generazione (Alder Lake, Raptor Lake).
- **LGA1200:** Utilizzato per processori Intel Core di 10ª e 11ª generazione (Comet Lake, Rocket Lake).

### AMD

- **AM4:** Utilizzato per processori Ryzen di prima fino alla quarta generazione.
- **AM5:** Nuovo socket per processori Ryzen di ultima generazione con supporto DDR5 e PCIe 5.0.

---

## **Esempio pratico**

Supponiamo di voler acquistare un **Intel Core i7-13700K**:

- Questa CPU richiede un socket **LGA1700**.
- Se la scheda madre ha un socket diverso (es. LGA1200), non sarà compatibile, anche se la CPU e la scheda madre sono entrambe Intel.
