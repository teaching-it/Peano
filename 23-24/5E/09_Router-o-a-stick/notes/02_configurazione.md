# Configurazione Router on a Stick su Router Cisco

Per implementare una configurazione "router on a stick" su un router Cisco che gestisce 3 VLAN, segui i seguenti passaggi per configurare l'interfaccia del router per operare in modalità trunk e definire le sottointerfacce (interfacce virtuali) per ciascuna VLAN specificata.

## 1. Modalità di configurazione 

Dalla modalità EXEC privilegiata, entra nella modalità di configurazione globale digitando:

    configure terminal

## 2. Configurazione dell'interfaccia fisica in modalità trunk

Assicurati che l'interfaccia `GbE0/0` sia impostata per operare in modalità trunk poiché collegata a uno switch gestito. È importante che lo switch a cui è collegato sia configurato correttamente per permettere il trunking.

## 3. Configurazione delle sottointerfacce (interfacce virtuali)

Configura le sottointerfacce per ogni VLAN come segue:

```plaintext
interface GigabitEthernet0/0.10
zdescription LAB1
 encapsulation dot1Q 10
 ip address 192.168.11.254 255.255.255.0
!
interface GigabitEthernet0/0.11
 description LAB2
 encapsulation dot1Q 11
 ip address 192.168.12.254 255.255.255.0
!
interface GigabitEthernet0/0.12
 description Sala Server
 encapsulation dot1Q 12
 ip address 192.168.10.254 255.255.255.0
```

- `interface GigabitEthernet0/0.X` per entrare nella modalità di configurazione della sottointerfaccia, dove X è il numero della VLAN.

- `description` per assegnare una descrizione leggibile.

- `encapsulation dot1Q Y` specifica il metodo di incapsulamento VLAN e il numero di VLAN `Y`.

- `ip address 192.168.XX.254 255.255.255.0` per impostare l'indirizzo IP della sottointerfaccia.

## 4. Salvataggio del file di configurazione

    copy running-config startup-config

## 5. Configurazione dello switch

Assicurati che lo switch a cui il router è connesso in trunk sia configurato per permettere il traffico delle VLAN 10, 11 e 12 sull'interfaccia collegata al router. Questo include la configurazione delle porte in modalità trunk e l'assegnazione delle VLAN appropriate alle porte specifiche.