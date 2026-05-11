# CLIL Activity
## Network Monitoring & Packet Analysis in GNU/Linux
### Cisco Extended ACLs and Linux nftables

___

**Topic:** network filtering, Cisco-like extended ACL syntax, Linux `nftables` / `nf_tables` syntax, defensive cybersecurity lab  
**Target class:** 5th year upper secondary school  
**Suggested duration:** one/two lab sessions  
**Environment:** Debian GNU/Linux virtual machines on Oracle VirtualBox  
**Main artifact:** the local HTML generator “CLIL Generator: Cisco ACL ⇄ nftables”

---

## 1. Learning goals

By the end of the activity, students should be able to:

1. explain the difference between a service being **exposed** and a service being **filtered**;
2. identify basic traffic attributes: source IP, destination IP, protocol, logical port and action;
3. read and generate simple **Cisco extended ACL-like** rules;
4. read and generate equivalent **Linux nftables-like** rules;
5. use `nmap` in a controlled lab to verify which services are reachable;
6. apply a defensive rule and test whether the visible attack surface has changed;

### CLIL language goals

Students should practice the following English terms in context:

| English term | Meaning in this activity |
|---|---|
| source address | the IP address/network that starts the communication |
| destination address | the IP address/network that receives the communication |
| protocol | IP, TCP, UDP, ICMP |
| port | logical service identifier, such as TCP/22 or TCP/80 |
| permit / accept | allow the packet |
| deny / drop | block the packet |
| rule order | rules are evaluated in sequence |
| exposed service | a service visible/reachable from another host |
| filtered port | a port whose probes are blocked or ignored by a firewall |
| attack surface | the set of reachable services that could be attacked |
| hardening | reducing unnecessary exposure and improving security |

---

## 2. Safety and scope

This is a **defensive cybersecurity activity**. Students must scan and test only the lab machines assigned by the teacher.

Allowed:

- scanning your own Debian VM or a VM prepared by the teacher;
- testing SSH/HTTP reachability inside the VirtualBox lab network;
- applying firewall rules to your own VM.

Not allowed:

- scanning school networks without explicit permission;
- scanning public IP addresses;
- trying to bypass authentication;
- using aggressive or disruptive scans.

Suggested safe `nmap` options for this lab:

```bash
nmap -p 22,80 <target-ip>
nmap -sV -p 22,80 <target-ip>
```

---

## 3. Quick overview: Cisco extended ACL-like syntax

A Cisco Access Control List is a sequence of rules used to decide whether traffic should be allowed or denied. In this activity we focus on **extended ACLs**, because they can filter traffic using multiple attributes:

```text
action protocol source destination optional-port-condition
```

Example:

```text
permit tcp 192.168.10.0 0.0.0.255 host 172.16.1.10 eq 443
```

This means:

| Part | Meaning |
|---|---|
| `permit` | allow the matching traffic |
| `tcp` | match TCP traffic |
| `192.168.10.0 0.0.0.255` | source network, Cisco wildcard notation for `/24` |
| `host 172.16.1.10` | destination host |
| `eq 443` | destination port equals 443, HTTPS |

### Wildcard mask reminder

Cisco IPv4 ACLs often use a **wildcard mask**, which is the inverse of the subnet mask.

| CIDR | Subnet mask | Cisco wildcard mask |
|---|---|---|
| `/32` | `255.255.255.255` | `0.0.0.0` |
| `/24` | `255.255.255.0` | `0.0.0.255` |
| `/16` | `255.255.0.0` | `0.0.255.255` |
| `/8` | `255.0.0.0` | `0.255.255.255` |

Example named ACL:

```text
configure terminal
ip access-list extended ALLOW_WEB
 remark Allow HTTPS from LAN to internal web server
 10 permit tcp 192.168.10.0 0.0.0.255 host 172.16.1.10 eq 443
exit
interface GigabitEthernet0/0
 ip access-group ALLOW_WEB in
exit
end
```

Key ideas:

- ACLs are evaluated from top to bottom.
- The first matching rule wins.
- More specific rules should normally be placed before more general rules.
- In real Cisco IOS ACLs, there is an implicit deny at the end, so rule order is very important.

---

## 4. Quick overview: Linux nftables / nf_tables

On Linux, `nftables` is the userspace framework used to configure packet filtering rules. The related kernel subsystem is called `nf_tables`. The command-line tool is `nft`.

The basic structure is:

```text
table → chain → rule
```

Example:

```text
table inet clil_acl {
  chain input {
    type filter hook input priority 0; policy accept;
    ip saddr 192.168.10.0/24 ip daddr 172.16.1.10 tcp dport 443 counter accept
  }
}
```

This means:

| Part | Meaning |
|---|---|
| `table inet clil_acl` | a table that can handle IPv4/IPv6-style filtering rules |
| `chain input` | rules for traffic entering the local machine |
| `hook input` | attach this chain to the input path |
| `policy accept` | default action if no rule matches |
| `ip saddr` | source IPv4 address/network |
| `ip daddr` | destination IPv4 address/network |
| `tcp dport 443` | TCP destination port 443 |
| `counter` | count matching packets/bytes |
| `accept` | allow the packet |

Common chains in this lab:

| Chain | Use it when... |
|---|---|
| `input` | protecting services running on the Debian VM itself |
| `output` | filtering traffic generated by the Debian VM |
| `forward` | filtering traffic passing through a Linux router/firewall VM |

### Important comparison: implicit deny vs explicit drop-rest

In Cisco-like ACL logic, a final **implicit deny all** is normally assumed at the end of the ACL. In the nftables rules used in this lab, this logic is **not automatic** while the chain policy is `accept`.

For classroom safety, the lab keeps `policy accept` and uses an explicit **drop-rest rule** only when the security goal is “allow only this source/service and block everything else for the same case”. In other words: if the Cisco-like rule reads as “allow only the partner”, the nftables output must also include an explicit final drop rule for the remaining matching traffic.

---

## 5. Common vs specific attributes

The HTML generator separates the fields into three categories.

### Common attributes

These describe the traffic and are meaningful in both Cisco ACL-like and nftables-like syntax:

- action: `permit/accept` or `deny/drop`;
- protocol: `tcp`, `udp`, `icmp`, `ip`;
- source address or source network;
- destination address or destination network;
- logical port, when the protocol is TCP or UDP;
- comment/remark.

### Cisco-specific attributes

These are meaningful only in the Cisco ACL-like output:

- ACL name or number;
- named ACL syntax;
- sequence numbers;
- interface name;
- direction: `in` or `out`;
- Cisco logging;
- optional final deny.

### nftables-specific attributes

These are meaningful only in the Linux nftables-like output:

- table name;
- base chain: `input`, `forward`, `output`;
- chain policy;
- packet/byte counter;
- nftables logging;
- explicit drop-rest rule, when an “allow only...” defensive policy must block the remaining matching traffic.

---

## 6. Pair-based lab topology — Computer Lab 2

Students work in pairs. Each pair uses two Debian GNU/Linux virtual machines connected to the **Computer Lab 2** network.

The lab subnet is:

```text
10.0.22.0/24
```

Each student must identify the IP address of their own Debian VM and exchange it only with their partner.

```text
+-----------------------------+          +-----------------------------+
| Student A VM                |          | Student B VM                |
| Debian GNU/Linux            |          | Debian GNU/Linux            |
| IP: 10.0.22.x               |          | IP: 10.0.22.y               |
| Role 1: scanner/verifier    | <------> | Role 1: defender/server     |
| Role 2: defender/server     | <------> | Role 2: scanner/verifier    |
+-----------------------------+          +-----------------------------+
```

### Pair workflow

Each exercise is performed twice:

| Round | Defender/server | Scanner/verifier |
|---|---|---|
| Round 1 | Student A | Student B |
| Round 2 | Student B | Student A |

The defender applies the nftables rules on their own VM. The scanner verifies the effect from the partner VM.

### Addressing table

Each pair should fill in this table before starting the exercises.

| Pair | Student | Role in round 1 | VM IP address |
|---|---|---|---|
|  | Student A | defender/server | `10.0.22.___` |
|  | Student B | scanner/verifier | `10.0.22.___` |

Useful commands:

```bash
ip -4 address
hostname -I
```

For the exercises, use these placeholders:

| Placeholder | Meaning |
|---|---|
| `<my-ip>` | the IP address of the defender VM |
| `<partner-ip>` | the IP address of the scanner/verifier VM |
| `10.0.22.0/24` | the Computer Lab 2 subnet |

Important: students must scan only their assigned partner IP address, not the whole `10.0.22.0/24` subnet, unless the teacher explicitly authorizes a wider scan.

---

## 7. Pair lab preparation

Every Debian VM must be able to act both as a server and as a scanner, because roles are swapped during the activity.

### On each Debian VM

Install the required services and tools:

```bash
sudo apt update
sudo apt install openssh-server apache2 nftables nmap curl openssh-client
```

Start and check the services:

```bash
sudo systemctl enable --now ssh
sudo systemctl enable --now apache2
systemctl status ssh --no-pager
systemctl status apache2 --no-pager
```

Check local listening sockets:

```bash
ss -tulpn
```

Expected services:

| Service | Typical port |
|---|---|
| SSH | TCP/22 |
| HTTP Apache | TCP/80 |

Before starting each new exercise, the defender may reset previous lab rules:

```bash
sudo nft flush ruleset
sudo nft list ruleset
```

Warning: `flush ruleset` removes existing nftables rules. In this classroom lab it is useful for starting from a clean state; on real systems it can remove important protections.

---

## 8. Baseline reconnaissance in pairs: what is exposed?

The scanner/verifier scans only the defender VM.

From the scanner VM:

```bash
nmap -p 22,80 <my-partner-ip>
```

Then detect service versions:

```bash
nmap -sV -p 22,80 <my-partner-ip>
```

Test HTTP:

```bash
curl http://<my-partner-ip>
```

Test SSH reachability:

```bash
ssh <my-partner-ip>
```

The goal is not to log in successfully. The goal is to observe that the SSH service is reachable.

### Evidence table — Round 1

| Test | Command | Expected/observed result |
|---|---|---|
| TCP port scan | `nmap -p 22,80 <defender-ip>` |  |
| Version detection | `nmap -sV -p 22,80 <defender-ip>` |  |
| HTTP access | `curl http://<defender-ip>` |  |
| SSH reachability | `ssh <defender-ip>` |  |

### Evidence table — Round 2

| Test | Command | Expected/observed result |
|---|---|---|
| TCP port scan | `nmap -p 22,80 <defender-ip>` |  |
| Version detection | `nmap -sV -p 22,80 <defender-ip>` |  |
| HTTP access | `curl http://<defender-ip>` |  |
| SSH reachability | `ssh <defender-ip>` |  |

---

## 9. Using the HTML generator in pairs

Open the standalone HTML page locally in the browser.

Recommended workflow for each exercise:

1. Decide who is the defender and who is the scanner.
2. The defender writes down `<my-ip>` and `<partner-ip>`.
3. In the generator, set the **Common attributes** according to the policy.
4. For rules that protect a service running on the defender VM, use nftables chain `input`.
5. Use the Cisco ACL-like output for reading and comparison.
6. If the policy is “allow only...”, enable the nftables **drop-rest** option so the final blocking rule is generated explicitly.
7. Copy the generated nftables copy/paste output to the defender VM.
8. The scanner repeats the `nmap`, `curl`, `ssh` or `ping` test.
9. Swap roles and repeat.

Typical mapping for pair work:

| Security intention | Generator source | Generator destination | nftables chain |
|---|---|---|---|
| Allow only the partner | `<partner-ip>` | `<my-ip>` | `input` |
| Block one partner from one service | `<partner-ip>` | `<my-ip>` | `input` |
| Block the whole lab subnet from one service | `10.0.22.0/24` | `<my-ip>` | `input` |
| Block traffic generated by your own VM | `<my-ip>` or `any` | `any` | `output` |

Important note: when you need more than one defensive rule, generate a single combined ruleset with the HTML generator, or ask the teacher for the required combination. Do not apply unrelated complete rulesets blindly.

---

## 10. Exercise 1 — Allow SSH only from your partner

### Scenario

The defender VM exposes SSH on TCP/22. Only the partner VM should be allowed to reach SSH. Other hosts in the lab subnet should not be able to access SSH.

### Required policy

| Attribute | Value |
|---|---|
| Source allowed | `<partner-ip>` |
| Destination | `<my-ip>` |
| Protocol | TCP |
| Port | 22 |
| Action 1 | accept SSH from partner |
| Action 2 | drop SSH from everyone else |
| nftables chain | `input` |

### Generator work

Use the HTML generator or the dedicated pair preset. The logic must include:

1. **allow SSH from partner to my VM**;
2. an explicit nftables **drop-rest** rule for SSH to my VM.

Compare the Cisco extended ACL-like output with the nftables output. Notice the difference: the Cisco-like ACL relies on the final deny logic, while nftables needs the final drop rule to be generated explicitly. For this first exercise only, the teacher also provides the equivalent direct Bash commands so that students can understand what the generated rules do.

### Example Bash commands on the defender VM

Replace the two variables before running the commands.

```bash
MY_IP="10.0.22.___"
PARTNER_IP="10.0.22.___"

sudo nft flush ruleset
sudo nft add table inet clil_acl
sudo nft 'add chain inet clil_acl input { type filter hook input priority 0; policy accept; }'
sudo nft add rule inet clil_acl input ip saddr $PARTNER_IP ip daddr $MY_IP tcp dport 22 counter accept
sudo nft add rule inet clil_acl input ip daddr $MY_IP tcp dport 22 counter drop
sudo nft list ruleset
```

### Verification from the partner VM

```bash
nmap -p 22 <defender-ip>
ssh <defender-ip>
```

If the teacher authorizes it, another pair may try the same scan against the defender IP. That host should not reach SSH.

### Reflection questions

1. Why is the allow rule placed before the drop rule?
2. What would happen if the drop rule came first?
3. Is SSH still running on the defender VM?
4. Is SSH still exposed to the whole `10.0.22.0/24` subnet?
5. Why does nftables need an explicit final drop rule here?

---

## 11. Exercise 2 — Allow HTTP only from your partner

### Scenario

Apache is running on the defender VM. The web service should be reachable only from the partner VM, not from the rest of the Computer Lab 2 subnet.

### Required policy

| Attribute | Value |
|---|---|
| Source allowed | `<partner-ip>` |
| Source blocked | `10.0.22.0/24` |
| Destination | `<my-ip>` |
| Protocol | TCP |
| Port | 80 |
| Action 1 | accept HTTP from partner |
| Action 2 | drop HTTP from the lab subnet |
| nftables chain | `input` |

### Generator work

Use the HTML generator to create the required nftables output. The defender must:

1. generate the allow rule for HTTP from `<partner-ip>` to `<my-ip>`;
2. enable the nftables **drop-rest** option, because the policy is “HTTP only from the partner”;
3. copy/paste the generated nftables output on the defender VM;
4. list the active ruleset and check that the explicit final drop rule is present.

### Verification from the partner VM

```bash
nmap -p 80 <defender-ip>
curl http://<defender-ip>
```

If the teacher authorizes it, another pair may test HTTP access to the same defender VM. That host should not reach TCP/80.

### Reflection questions

1. Why is the partner-specific allow rule placed before the explicit final drop rule?
2. Does blocking TCP/80 stop Apache from running?
3. What is the difference between disabling a service and filtering access to it?
4. Which approach is safer if the service is not needed at all?

---

## 12. Exercise 3 — Reduce attack surface: keep HTTP, block SSH from the lab subnet

### Scenario

A baseline scan shows that both SSH and HTTP are exposed. The defender decides that Apache must remain reachable, but SSH should not be exposed to the whole lab subnet.

### Required policy

| Attribute | Value |
|---|---|
| Source blocked | `10.0.22.0/24` |
| Destination | `<my-ip>` |
| Protocol | TCP |
| Port | 22 |
| Action | drop |
| nftables chain | `input` |

### Generator work

Use the HTML generator to create the nftables output for this defensive policy. The defender must copy/paste the generated output on their own VM and then list the active ruleset.

### Verification from the partner VM

```bash
nmap -p 22,80 <defender-ip>
ssh <defender-ip>
curl http://<defender-ip>
```

Expected result:

| Port | Expected result |
|---|---|
| TCP/22 SSH | filtered or not reachable |
| TCP/80 HTTP | reachable |

### Reflection questions

1. What changed in the scan after applying the rule?
2. Which service is still running?
3. Which service is still reachable?
4. How does this reduce the visible attack surface?

---

## 13. Exercise 4 — Deny outbound web access from your own VM

### Scenario

This exercise simulates a containment policy: the defender VM should not browse the web using HTTP or HTTPS. This is an `output`-chain exercise because the traffic is generated by the local VM.

### Required policy

| Attribute | Value |
|---|---|
| Source | `<my-ip>` or `any` |
| Destination | `any` |
| Protocol | TCP |
| Ports | 80 and 443 |
| Action | drop |
| nftables chain | `output` |

### Generator work

Use the HTML generator twice:

1. deny TCP/80 from the defender VM to any destination;
2. deny TCP/443 from the defender VM to any destination.

Copy/paste the generated nftables output on the defender VM and list the active ruleset.

### Verification on the defender VM

```bash
curl http://example.com
curl https://example.com
```

Then reset the rules before continuing:

```bash
sudo nft flush ruleset
```

### Reflection questions

1. Why is the `output` chain used here?
2. Is this rule protecting a local service or controlling local outbound traffic?
3. Why should this rule not be made persistent during the lab unless the teacher asks for it?

---

## 14. Exercise 5 — Allow ICMP troubleshooting only from your partner

### Scenario

The partner VM should be allowed to ping the defender VM for troubleshooting. Other hosts in the `10.0.22.0/24` subnet should not be allowed to ping it.

### Required policy

| Attribute | Value |
|---|---|
| Source allowed | `<partner-ip>` |
| Source blocked | `10.0.22.0/24` |
| Destination | `<my-ip>` |
| Protocol | ICMP |
| Action 1 | accept |
| Action 2 | drop |
| nftables chain | `input` |

### Generator work

Use the HTML generator to create the required nftables output. The defender must:

1. generate the allow rule for ICMP from `<partner-ip>` to `<my-ip>`;
2. enable the nftables **drop-rest** option, because the policy is “ICMP only from the partner”;
3. copy/paste the generated nftables output on the defender VM;
4. list the active ruleset and check that the explicit final drop rule is present.

### Verification from the partner VM

```bash
ping -c 4 <defender-ip>
```

If the teacher authorizes it, another pair may try to ping the same defender VM. That host should not receive replies.

### Reflection questions

1. Why are no TCP/UDP ports involved in ICMP?
2. Why should the generator disable port fields when ICMP is selected?
3. Is blocking ICMP always a good idea? Discuss pros and cons.
4. Why does nftables need an explicit final drop rule here?

---

## 15. Applying, listing and resetting nftables rules

List current rules:

```bash
sudo nft list ruleset
```

Apply a file:

```bash
sudo nft -f file-name.nft
```

Flush all nftables rules:

```bash
sudo nft flush ruleset
```

Warning: `flush ruleset` removes existing nftables rules. In this classroom activity it is useful before starting a new exercise, but on a real system it may remove important protections.

Remember: in this lab, `policy accept` does not create a hidden deny-all rule. When the exercise requires an “allow only...” policy, verify with `sudo nft list ruleset` that an explicit final drop-rest rule is present after the allow rule.