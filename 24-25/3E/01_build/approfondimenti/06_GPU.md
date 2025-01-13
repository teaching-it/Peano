# Scheda Grafica (GPU)**

La GPU (Graphics Processing Unit) è uno dei componenti più importanti in un computer, soprattutto per gaming, rendering, machine learning e altre applicazioni che richiedono calcoli grafici complessi. Ecco un approfondimento sui parametri prestazionali tipici da considerare.

---

## **Compatibilità e Installazione**

1. **Compatibilità PCIe:**
   - La GPU deve essere compatibile con lo slot PCIe della scheda madre. Le versioni comuni sono:
     - **PCIe 3.0, 4.0, 5.0:** Ogni generazione raddoppia la larghezza di banda rispetto alla precedente.
     - Le GPU moderne sono retrocompatibili con versioni precedenti dello slot PCIe, ma la velocità sarà limitata dallo standard più vecchio.

2. **Dimensioni fisiche:**
   - **Lunghezza:** Assicurarsi che il case possa ospitare la lunghezza della GPU.
   - **Altezza:** Alcune GPU possono occupare più spazio in altezza, interferendo con altri componenti.
   - **Spessore:** Le GPU possono occupare 2, 2.5 o 3 slot PCIe sul case.

3. **Alimentazione:**
   - La GPU richiede connettori di alimentazione dedicati dall'alimentatore (es. 6-pin, 8-pin, 12-pin).
   - Verifica il consumo di energia (TDP) della GPU e assicurati che l'alimentatore abbia sufficiente potenza residua per il resto del sistema.

4. **Raffreddamento:**
   - Verifica che ci sia sufficiente spazio per la ventilazione.
   - Le GPU moderne possono utilizzare sistemi di raffreddamento a ventola, blower o persino raffreddamento a liquido.

---

## **Parametri Prestazionali delle GPU**

1. **VRAM (Video RAM):**
   - La quantità di memoria video determina quanto la GPU può gestire texture, modelli 3D e altri dati grafici.
   - Tipologie comuni:
     - **GDDR5, GDDR6, GDDR6X:** Le più diffuse per gaming e grafica.
     - **HBM2 (High Bandwidth Memory):** Utilizzata in GPU professionali per applicazioni come il deep learning.
   - Capacità consigliata:
     - **4-6 GB:** Gaming 1080p.
     - **8-12 GB:** Gaming 1440p o 4K, rendering leggero.
     - **16+ GB:** Applicazioni professionali, rendering pesante, machine learning.

2. **CUDA Cores / Stream Processors:**
   - **CUDA Cores (NVIDIA)** e **Stream Processors (AMD)** rappresentano le unità di calcolo parallelo della GPU.
   - Più core generalmente equivalgono a migliori prestazioni, ma il confronto diretto è valido solo all'interno della stessa architettura.

3. **Frequenza di Clock:**
   - La velocità operativa della GPU, misurata in **MHz** o **GHz**.
   - **Base Clock:** La frequenza standard della GPU.
   - **Boost Clock:** La frequenza massima raggiungibile sotto carico pesante (se le condizioni termiche ed energetiche lo permettono).

4. **TDP (Thermal Design Power):**
   - Indica il calore generato dalla GPU sotto carico massimo, misurato in **Watt**.
   - Aiuta a determinare il tipo di raffreddamento necessario e il consumo energetico.

5. **Larghezza del Bus di Memoria:**
   - Misurata in **bit** (es. 128 bit, 256 bit).
   - Un bus più largo consente una maggiore larghezza di banda della memoria, migliorando le prestazioni nei carichi pesanti.

6. **Bit della GPU:**
   - **Definizione:** I "bit" della GPU rappresentano la larghezza dei dati che possono essere trasferiti contemporaneamente tra il chip grafico e i registri interni della GPU.
   - **Importanza:** Questo parametro è correlato alla complessità dell'elaborazione che la GPU può gestire in un singolo ciclo di clock.
   - **Confronto con altri parametri:**
     - Le GPU a 64 bit o 128 bit sono generalmente destinate a sistemi entry-level o portatili.
     - Le GPU a 256 bit o superiori sono progettate per carichi di lavoro pesanti come il gaming ad alta risoluzione, il rendering o il machine learning.

7. **Larghezza di Banda della Memoria:**
   - Misurata in **GB/s**, calcolata in base alla velocità della memoria e alla larghezza del bus:
     - **Formula:** Larghezza di banda = Larghezza del bus × Velocità della memoria ÷ 8.
   - Una maggiore larghezza di banda migliora le prestazioni in giochi e applicazioni con texture complesse.

8. **Ray Tracing e Tensor Cores:**
   - **Ray Tracing Cores:** Core dedicati (NVIDIA RTX, AMD RDNA 2/3) per il rendering realistico della luce e delle ombre.
   - **Tensor Cores (NVIDIA):** Core progettati per applicazioni di AI, machine learning e DLSS (Deep Learning Super Sampling).

9. **DirectX / Vulkan / OpenGL Support:**
   - Determinano quali librerie grafiche e tecnologie la GPU può utilizzare.
   - **DirectX 12 Ultimate** e **Vulkan** sono standard moderni per il gaming e il rendering.

---

## **Benchmark delle GPU**

1. **FPS (Frame Per Second):**
   - La misura più importante per il gaming: indica il numero di fotogrammi renderizzati al secondo.
   - Benchmark popolari: 3DMark, Unigine Heaven.

2. **TFLOPS / GFLOPS:**
   - **TFLOPS (Tera Floating Point Operations Per Second):** Indica la capacità di calcolo teorica della GPU.
   - Più TFLOPS generalmente significano prestazioni superiori, ma il valore reale dipende anche dall'architettura.

3. **Temperatura:**
   - Monitorare le temperature massime durante i carichi di lavoro è cruciale per stabilità e durata:
     - **70-85°C:** Range tipico sotto carico.
     - **90°C+:** Può indicare problemi di raffreddamento.

---

## **Esempio Pratico**

Supponiamo di voler acquistare una GPU per gaming a 1440p:

- **Scelta:** NVIDIA RTX 3060 Ti o AMD RX 6700 XT.
- **Parametri principali:**
  - **VRAM:** 8-12 GB (GDDR6).
  - **TDP:** ~200-250W, richiede un alimentatore da almeno 650W.
  - **Bus di memoria:** 256 bit (RTX 3060 Ti), 192 bit (RX 6700 XT).
  - **Larghezza di banda:** 448 GB/s (RTX 3060 Ti), 384 GB/s (RX 6700 XT).
  - **Ray Tracing:** Supportato da entrambe, ma NVIDIA ha vantaggi grazie ai Tensor Cores per DLSS.
- **Prestazioni:** Entrambe sono in grado di raggiungere 60+ FPS a 1440p in giochi moderni con impostazioni alte.
