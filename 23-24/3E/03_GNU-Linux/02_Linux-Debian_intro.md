# GNU/Linux Debian

Debian è una delle distribuzioni GNU/Linux più antiche e rispettate, nota per la sua stabilità e affidabilità. Fondata da Ian Murdock nel 1993, Debian si impegna a rimanere fedele ai principi del software libero, come definiti dalla Free Software Foundation. Il progetto Debian è completamente gestito da volontari provenienti da tutto il mondo, rendendolo uno degli esempi più puri di collaborazione comunitaria nel mondo del software libero.

## Caratteristiche Principali

### Stabilità

ebian è famoso per la sua stabilità. Questo lo rende una scelta popolare per i server e gli ambienti di produzione. La distribuzione segue un ciclo di rilascio che non è legato a scadenze fisse, ma piuttosto alla prontezza del software. Questo approccio garantisce che ogni versione stabile sia ben testata e affidabile.

### Filosofia del Software Libero

Debian è strettamente aderente ai principi del software libero, fornendo agli utenti la libertà di usare, modificare e distribuire il suo software. Questo impegno è sancito nelle linee guida del software libero di Debian, che assicurano che solo software completamente libero sia incluso nella distribuzione principale.

### Vasta Scelta di Pacchetti

Debian offre uno dei più ampi archivi di pacchetti software disponibili, rendendolo adatto a quasi tutte le esigenze informatiche. Questo vasto repository include applicazioni desktop, software server, strumenti di programmazione, e molto altro.

### Supporto Multi-Architettura

Debian supporta un'ampia gamma di architetture hardware, inclusi PC, Mac, ARM e molti altri. Questo lo rende una scelta versatile per diversi tipi di hardware, dai vecchi computer desktop ai moderni server e dispositivi embedded.

### Comunità e Supporto

La comunità Debian è ampia e attiva, offrendo supporto tramite mailing list, forum, canali IRC e altri mezzi. La documentazione è estensiva e ben mantenuta, rendendo più facile per gli utenti trovare le informazioni di cui hanno bisogno.


## Momenti Chiavi del Processo di Installazione

L'installazione di Debian GNU/Linux è un processo che può variare in complessità a seconda delle esigenze dell'utente, dalla configurazione di un semplice desktop a quella di un server avanzato.

Di seguito si riportano i momenti fondamentali del processo di installazione.

### 1. Utente Root e Utente Non Privilegiato

#### Utente Root

Durante l'installazione viene richiesto di creare una password per l'utente root, che è l'account amministratore del sistema. L'utente root ha accesso illimitato a tutti i comandi e file del sistema.

#### Utente Non Privilegiato

Viene inoltre richiesto di creare un account utente normale (non privilegiato) per le attività quotidiane. Questo è importante per la sicurezza, poiché limita le possibilità di danneggiamento del sistema da parte di software malevolo o errori dell'utente.

### 2. Partizionamento del Disco

Durante l'installazione, è necessario operare sul disco creado una o più partizioni.

#### Spazio Swap

Lo spazio di swap è una parte del disco usata dal sistema come memoria virtuale qualora la memoria RAM sia esaurita. La regola generale per la dimensione dello swap è di avere una quantità pari alla RAM per sistemi con meno di 4GB di RAM, e circa la metà della RAM per sistemi con più di 4GB, ma questo può variare a seconda dell'uso (ad esempio qualora si voglia o meno attivare la modalità di ibernazione).

### 3. Selezione del Software e dell'Ambiente Desktop

Terminate le operazioni di configurazione di base, si giunge alla selezione del software da installare. Per un'installazione desktop, dobbiamo assicurarci di selezionare l'ambiente desktop XFCE, che è noto per essere leggero e veloce, oltre che altamente personalizzabile. Qualora le risorse hardware lo permettano, si potrà altresì optare per soluzioni desktop più evolute, quali GNOME o KDE.
