# Traceroute

Il comando `tracert` (abbreviazione di "traceroute" su sistemi Windows) è uno strumento di diagnostica di rete che consente di determinare il percorso attraversato dai pacchetti per raggiungere un host di destinazione specifico. `tracert` è ampiamente utilizzato per identificare il percorso e misurare il ritardo dei pacchetti attraverso una rete IP.

## Funzionamento di tracert

`tracert` invia una serie di pacchetti di messaggi Echo Request ICMP (Internet Control Message Protocol) all'indirizzo di destinazione, incrementando il valore del campo TTL (Time To Live) di ciascun pacchetto inviato, partendo da 1. Il TTL di un pacchetto IP determina quanti hop (router) può attraversare prima di essere scartato. L'obiettivo è di scoprire ogni router lungo il percorso verso la destinazione finale.

### Passaggi chiave

1. Invio del primo pacchetto. tracert inizia inviando un pacchetto ICMP Echo Request con un TTL di 1. Questo assicura che il primo router nel percorso verso la destinazione scarti il pacchetto e risponda con un messaggio ICMP Time Exceeded.

2. Incremento del TTL. Dopo aver ricevuto il messaggio Time Exceeded, tracert invia un altro pacchetto, questa volta con un TTL di 2. Questo processo viene ripetuto, incrementando il TTL di 1 ogni volta, finché i pacchetti non raggiungono l'host di destinazione o fino a un massimo predefinito di hop.

3. Raccolta delle risposte. Ogni volta che un router lungo il percorso scarta un pacchetto a causa del TTL esaurito, invia indietro al mittente un messaggio ICMP Time Exceeded, che tracert utilizza per registrare l'indirizzo IP del router.

4. Identificazione della destinazione. Il processo continua fino a quando i pacchetti non raggiungono l'host di destinazione, che risponde con un messaggio ICMP Echo Reply, indicando che il percorso è stato completato.

5. misurazione del ritardo. tracert misura il tempo impiegato per ricevere una risposta da ciascun router lungo il percorso. Di solito, invia più pacchetti per ogni valore di TTL per ottenere una stima più precisa del ritardo.

### Output di tracert

L'output del comando tracert mostra una lista di hop (router) che i pacchetti hanno attraversato per raggiungere la destinazione. Per ogni hop, tracert mostra l'indirizzo IP, il nome host (se disponibile) e il tempo impiegato per ricevere una risposta, tipicamente espresso in millisecondi. Se un hop non risponde entro un timeout predefinito, tracert mostra un asterisco (*) per indicare la perdita di pacchetti o la mancata risposta.

### Diagnostica

Quando si utilizzano gli strumenti come tracepath o traceroute per analizzare il percorso dei pacchetti attraverso la rete fino a un host di destinazione, potresti talvolta non ricevere risposta da uno o più router lungo il percorso. Questo fenomeno può verificarsi per vari motivi.

### 1. Filtri ICMP

Molti router e firewall sono configurati per bloccare o limitare i messaggi ICMP (Internet Control Message Protocol), che sono utilizzati da tracepath e traceroute per ricevere notifiche di "Time Exceeded" o "Destination Unreachable". Questi filtri sono spesso implementati per motivi di sicurezza, per prevenire attacchi di tipo DoS (Denial of Service) o per limitare la scoperta di informazioni sulla rete da parte di potenziali aggressori.

### 2. Politiche di routing o firewall

Alcuni router o firewall possono essere configurati con politiche che impediscono loro di rispondere a pacchetti con TTL scaduto o di trasmettere ulteriormente i messaggi di errore generati. Questo può essere fatto per ridurre il carico sul dispositivo o per nascondere la struttura interna della rete.

### 3. Rate limiting

Per proteggersi da sovraccarichi e potenziali abusi, alcuni router implementano il rate limiting sui messaggi ICMP che generano. Se un router ha raggiunto il suo limite massimo di messaggi ICMP che può inviare in un dato intervallo di tempo, potrebbe non rispondere alle ulteriori richieste fino al prossimo intervallo.

### 4. Percorsi asimmetrici

Il percorso di andata dei pacchetti nella rete potrebbe differire dal percorso di ritorno. Se il pacchetto di risposta segue un percorso diverso che non include il router in questione, non vedrai una risposta da quel router specifico. Questo è più comune in reti complesse con molteplici percorsi di routing disponibili.

### 5. Problemi di connettività o configurazione

Infine, un mancato riscontro può semplicemente indicare un problema di connettività o una configurazione errata lungo il percorso. Ciò potrebbe includere interfacce disabilitate, guasti hardware, o problemi di configurazione del routing che impediscono al router di trasmettere o ricevere pacchetti correttamente.
