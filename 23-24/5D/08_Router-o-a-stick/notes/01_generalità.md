# Router on a Stick

"Router on a stick", in italiano, può essere descritto come "router su un bastone" ed è un termine utilizzato per descrivere una configurazione di rete in cui un'interfaccia singola del router viene utilizzata per instradare il traffico tra più VLAN (Virtual Local Area Network). Questa configurazione utilizza tipicamente uno switch gestito per dirigere il traffico proveniente da più VLAN verso una singola interfaccia sul router. Il router, poi, utilizza sottointerfacce, ognuna configurata per una specifica VLAN, per instradare correttamente il traffico tra queste VLAN. Questa configurazione è spesso impiegata in reti di piccole o medie dimensioni dove l'acquisto di più router o switch di livello 3 (che possono instradare il traffico a livello di switch) sarebbe troppo costoso.

## Funzionamento

### Configurazione VLAN

In una rete tipica, le VLAN sono utilizzate per segmentare il traffico di rete. Ogni VLAN agisce come una rete fisica separata, ma tutte operano sulla stessa infrastruttura fisica. Le VLAN possono separare il traffico per diversi dipartimenti, utenti o tipi di dispositivi, migliorando la sicurezza e l'efficienza della rete.

### Switch Gestito

Uno switch gestito viene configurato per identificare e dirigere il traffico da queste diverse VLAN verso una singola interfaccia fisica sul router. Ciò si ottiene tramite il tagging dei frame di rete con un identificativo di VLAN (un tag VLAN) che indica a quale VLAN appartiene il frame.

### Router

Il router è configurato con una singola interfaccia fisica collegata allo switch. Su questa interfaccia fisica, vengono create diverse sottointerfacce virtuali, ognuna delle quali è configurata per gestire il traffico di una specifica VLAN. Ogni sottointerfaccia ha un proprio indirizzo IP che serve come gateway predefinito per la VLAN corrispondente.

### Inoltro del Traffico

Il router utilizza le sottointerfacce per determinare come instradare il traffico tra le VLAN. Poiché il router conosce l'indirizzo di rete di ogni VLAN, può instradare il traffico tra di esse, consentendo ai dispositivi su VLAN separate di comunicare tra loro secondo le politiche di rete.

Questa configurazione permette di utilizzare un singolo router per gestire il traffico tra VLAN multiple, risparmiando su costi e complessità hardware senza sacrificare la flessibilità e la sicurezza della segmentazione di rete.
