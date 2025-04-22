# ARP & ICMP 실습 과제 제출

## 1. 네트워크 정보

![Image](https://github.com/user-attachments/assets/3a4dde05-ab34-40c5-9495-1d560288c47b)

## 2. ICMP (ping 8.8.8.8) 분석
[ICMP Request]  
- ETH smac: b4:a9:4f:92:53:c3  
- ETH dmac: ac:1e:01:4e:64:fe  
- IP sip: 172.30.1.100  
- IP dip: 8.8.8.8

[ICMP Reply]  
- ETH smac: ac:1e:01:4e:64:fe  
- ETH dmac: b4:a9:4f:92:53:c3  
- IP sip: 8.8.8.8  
- IP dip: 172.30.1.100

![Image](https://github.com/user-attachments/assets/054e6949-4b1e-4332-badd-4c602f0a9836)

## 3. ARP Packet 분석
[ARP Request]  
- ETH smac: b4:a9:4f:92:53:c3  
- ETH dmac: ff:ff:ff:ff:ff:ff  
- ARP smac: b4:a9:4f:92:53:c3  
- ARP sip: 172.30.1.100  
- ARP tmac: 00:00:00:00:00:00  
- ARP tip: 172.30.1.254

[ARP Reply]  
- ETH smac: ac:1e:01:4e:64:fe  
- ETH dmac: b4:a9:4f:92:53:c3  
- ARP smac: ac:1e:01:4e:64:fe  
- ARP sip: 172.30.1.254  
- ARP tmac: b4:a9:4f:92:53:c3  
- ARP tip: 172.30.1.100

![Image](https://github.com/user-attachments/assets/1f244bf8-89f6-40c0-842f-91775f2ab968)

## 4. ARP Request 전송 프로그램 실습

- main.cpp에서 MAC, IP 정보를 수정하여 ARP Request 전송
- Wireshark로 전송 결과 확인
- 예시:
    - Source MAC: b4:a9:4f:92:53:c3
    - Destination MAC: ff:ff:ff:ff:ff:ff
    - Source IP: 172.30.1.100
    - Target IP: 172.30.1.254
  
![Image](https://github.com/user-attachments/assets/efcdc88f-eec7-43f8-8ef8-c309ac0d9204)

## 5.  ARP 감염 실습 (Spoofing)

  
![Image](https://github.com/user-attachments/assets/43b74a46-298e-4e37-a3fb-936a8702110b)
