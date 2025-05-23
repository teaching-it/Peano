# Network Monitoring & Packet Analysis in GNU/Linux  

*A CLIL-oriented, hands-on lesson plan with fully solved lab exercises*  

---

## Part 1 – Command Quick-Reference (Cheat-Sheet)

| Goal | Command | Typical Add-ons | Why / When |
|------|---------|-----------------|------------|
| Install classic tools | `apt-get install net-tools tcpdump nmap traceroute curl wireshark` || One-stop install for every task below |
| List interfaces & IPs | `ifconfig`  *(or)*  `ip -br addr` |   | Discover interface names (`enp0s3`, `wlan0`, `lo` …) and private addresses |
| Show routing table / gateway | `ip route show` |   | Find `default via …` |
| Show ARP cache | `arp -a`  *(modern)*  `ip neigh` |   | Maps IP ↔ MAC already known to the host |
| Live ARP sniff | `tcpdump -i <iface> arp and src host <your-IP>` | `-n` (no DNS), `-vv` (verbose) | Observe who your host is asking for |
| List listening ports | `netstat -tuln`  *(modern)*  `ss -tuln` | `-p` (show process) | Basic local security survey |
| ICMP ping | `ping -c 4 <IP>` |   | Generates ICMP echo requests (useful traffic for Wireshark) |
| Wireshark display filters | `icmp`, `arp`, `tcp.flags.syn == 1`, `dns`, `http` |   | Narrow capture to the protocol you study |
| Stealth + service + OS scan | `nmap -sS -sV -O <target>` | `-p-` (all 65535 ports) | Deep remote host scan |
| HTTP from CLI | `curl http://example.com` | `-I` (only headers) | Lightweight request for capture |
| Trace path | `traceroute example.com` | `-I` (ICMP echo) | Shows hop list & TTL behaviour |

> **Tip:** run Wireshark as non-root via **dumpcap** privileges (launch this command from root): 
> `dpkg-reconfigure wireshark-common` → *Yes*.

---

## Part 2 – Lab Exercises (Solved)

### Exercise 1 – ARP Traffic Analysis

| Step | Command & Sample Output | Explanation |
|------|------------------------|-------------|
| 1. Become root | `su` | Needed for `tcpdump`. |
| 2. Identify interface & IP | `ifconfig` → e.g. `enp0s3 inet 10.0.22.15` | Active NIC = **enp0s3**, local IP = **10.0.22.15** |
| 3. Check ARP cache | `arp -a | grep 10.0.22.253` || echo "Not present"` | Confirm 10.0.22.253 not cached. |
| 4. Start sniff | `tcpdump -i enp0s3 -n arp and src host 10.0.22.15` | Only ARP from your host. |
| 5. Ping target | `ping -c 4 10.0.22.253` | Generates ARP then ICMP. |
| 6. Observe | Request: `12:01:33.941 ARP, Request who-has 10.0.22.253 tell 10.0.22.15`, Reply: `12:01:33.942 ARP, Reply 10.0.22.253 is-at 08:00:27:aa:bb:cc` | Request = broadcast, Reply = unicast |
| 7. Re-check ARP | `arp -a \| grep 10.0.22.253` → `10.0.22.253 at 08:00:27:aa:bb:cc` | Cache now updated. |

**Analysis**

* **MAC addresses** – your NIC vs target’s NIC.  
* **Role of ARP** – Maps Layer-3 IP → Layer-2 MAC before first IPv4 packet.  
* **Coherency** – Cache entry must equal MAC in reply (detect spoofing otherwise).

---

### Exercise 2 – Remote Host Scan (`scanme.nmap.org`)

`nmap -sS -sV -O 45.33.32.156`

```
nmap -sS -sV -O 45.33.32.156

Stats: 0:00:25 elapsed; 0 hosts completed (1 up), 1 undergoing Script Scan
NSE Timing: About 0.00% done
Nmap scan report for scanme.nmap.org (45.33.32.156)
Host is up (0.22s latency).
Not shown: 909 closed ports, 87 filtered ports
PORT      STATE SERVICE    VERSION
22/tcp    open  ssh        OpenSSH 6.6.1p1 Ubuntu 2ubuntu2.13 (Ubuntu Linux; protocol 2.0)
80/tcp    open  http       Apache httpd 2.4.7 ((Ubuntu))
9929/tcp  open  nping-echo Nping echo
31337/tcp open  tcpwrapped
Aggressive OS guesses: Linux 3.4 (92%), Linux 2.6.32 (87%), Linux 2.6.39 (87%), Linux 3.10 - 3.12 (87%), Linux 4.4 (87%), Synology DiskStation Manager 5.1 (87%), WatchGuard Fireware 11.8 (87%), Linux 2.6.35 (86%), Linux 3.10 (86%), Linux 4.9 (86%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 27 hops
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 27.42 seconds
```

| Port | Service / Version | OSI Layer(s) | Use-Case | Security Concerns |
|------|-------------------|--------------|----------|-------------------|
| 22 / tcp | OpenSSH 6.6.1 | L4 TCP / L5 SSH | Remote shell | Brute-force, weak ciphers |
| 80 / tcp | Apache HTTP 2.4.7 | L4 TCP / L5 HTTP | Web hosting | CVEs, clear-text |
| 9929/tcp | nping-echo | L4 TCP | Nmap demo | Fingerprinting |
| 31337/tcp | “Elite?” | L4 TCP | Test / easter egg | Possible back-door |

* **Estimated OS:** Linux kernel 3-4.  
* **Admin view:** Confirms exposed services, patch level.  
* **Attacker view:** Points for brute-force (SSH) or exploits (Apache).

---

#### Variant A – Scan of Default Gateway (`10.0.22.254`)

Run a Nmap scan against your default gateway (commonly a firewall or router):

```bash
nmap -sS -sV -O 10.0.22.254
```

Sample Output (example for a pfSense box):

```
Nmap scan report for 10.0.22.254
Host is up (0.0050s latency).
Not shown: 995 closed ports
PORT     STATE SERVICE    VERSION
22/tcp   open  ssh        OpenSSH 8.4 (protocol 2.0)
80/tcp   open  http       lighttpd 1.4.59
443/tcp  open  https      OpenSSL
1900/tcp open  upnp       Microsoft Windows UPnP
8080/tcp open  http-proxy Squid http proxy 4.13

Aggressive OS guesses: FreeBSD 12.1-RELEASE (93%), pfSense 2.5.x (90%)
OS details: FreeBSD 12.1 or pfSense 2.5

Service Info: OS: FreeBSD; Device Type: firewall

Nmap done: 1 IP address (1 host up) scanned in 12.21 seconds
```

#### Security Analysis

| Port | Service / Version       | Use-Case                      | Risks / Considerations |
|------|-------------------------|-------------------------------|-------------------------|
| 22   | OpenSSH 8.4             | Remote admin (CLI)            | Bruteforce, allow only key-based auth |
| 80   | lighttpd 1.4.59         | Web config GUI (HTTP)         | Transmits credentials in cleartext |
| 443  | HTTPS + OpenSSL         | Secure web GUI / API access   | Outdated OpenSSL can expose to CVEs |
| 8080 | Squid proxy             | Web filtering / caching       | Can be abused if open without auth |

#### Observations

* pfSense or FreeBSD-based firewalls often expose HTTP/HTTPS for local config.
* If HTTP (port 80) is enabled, password interception is possible on unsecured networks.
* UPnP exposed can be a severe issue if allowed from WAN.

#### Admin Perspective

* Disable all web access from WAN.
* Enforce HTTPS only for admin panel.
* Use firewall rules to restrict SSH by IP.
* Regularly patch OpenSSL, web GUI, and proxy services.

#### Attacker Perspective

* HTTP ports open can reveal banners or expose login panels.
* OS fingerprinting reveals it's a firewall → high-value target.

---

### Exercise 3 – HTTP Traffic Dissection

1. Start Wireshark filter `http`.  
2. Run `curl http://www.example.com`.

**Wireshark details**

| Item | Value |
|------|-------|
| Method | **GET** / |
| Headers | `Host`, `User-Agent: curl/8.0.1`, `Accept: */*` |
| Status | **200 OK** |
| Layers | HTTP → TCP → IP → Ethernet |

---

#### Variant A – Basic HTTP with 3-Way Handshake

1. Open **Wireshark** and set display filter:  

   ```
   tcp.flags.syn == 1 || http
   ```

2. In a terminal, run:  

   ```
   curl http://www.example.com
   ```

3. Observe in Wireshark:

    | Item        | Value                              |
    |-------------|------------------------------------|
    | TCP Flags   | SYN → SYN-ACK → ACK                |
    | Method      | **GET** /                          |
    | Headers     | `Host`, `User-Agent`, `Accept`     |
    | Status Code | 200 OK                             |
    | Layers      | HTTP → TCP → IP → Ethernet         |

    > Ensure you capture the initial TCP handshake (3 packets) **before** the GET request is transmitted.

---

#### Variant B – HTTP with DNS Request Capture

1. Open **Wireshark** and set display filter:  

   ```
   dns || http
   ```

2. In a terminal, run:  

   ```
   curl http://www.example.com
   ```

3. Observe in Wireshark:

    | Item         | Value                                 |
    |--------------|---------------------------------------|
    | DNS Protocol | UDP port 53                           |
    | Query        | `A` record for `www.example.com`      |
    | Response     | IP address (e.g., 93.184.216.34)       |
    | HTTP Layer   | Standard GET request after DNS lookup |
    | Stack        | DNS → UDP → IP → Ethernet             |

    > Note: If `example.com` is already cached, the DNS request might not appear. Use a lesser-known domain or flush DNS cache.

---

### Exercise 4 – `traceroute` & ICMP Time-Exceeded

`traceroute example.com`     +   Wireshark filter `icmp`

* Hop count (example): **9**  
* First exit from LAN: **hop 1 (10.0.22.254)**
* ...
* Missing router: shown as `* * *` in traceroute, no ICMP reply captured.

---

**Happy hacking ;-)**

      .-"      "-.
     /            \\
    |              |
    |,  .-.  .-.  ,|
    | )(_o/  \o_)( |
    |/     /\     \|
    (_     ^^     _)
     \__|IIIIII|__/
      | \IIIIII/ |
      \          /
       `--------`

     [*] HACKING INITIATED...
     [*] BYPASSING FIREWALL...
     [!] ACCESS GRANTED!
     --> pwned by h4x0r!
