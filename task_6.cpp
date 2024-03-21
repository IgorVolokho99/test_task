#include <iostream>
#include <cstdint>
#include <cstring>
#include <netinet/in.h>

const uint32_t COMMON_HEADER_SIZE = 1;
const uint32_t SETUP_REQUEST_MSG_SIZE = 7;
const uint16_t SETUP_REQUEST_MSG_ID = 16;

void init_setup_request_msg(uint8_t *setup_request_msg_p, uint8_t role_id, uint32_t session_id) {
    if (setup_request_msg_p == nullptr) {
        std::cerr << "Error: Not valide pointer." << std::endl;
        return;
    }

    setup_request_msg_p[0] = SETUP_REQUEST_MSG_ID;

    uint16_t msg_size_n = htons(SETUP_REQUEST_MSG_SIZE);
    memcpy(setup_request_msg_p + COMMON_HEADER_SIZE, &msg_size_n, sizeof(msg_size_n));

    setup_request_msg_p[COMMON_HEADER_SIZE + sizeof(msg_size_n)] = role_id;

    uint32_t session_id_n = htonl(session_id);
    memcpy(setup_request_msg_p + COMMON_HEADER_SIZE + sizeof(msg_size_n) + sizeof(role_id), &session_id_n, sizeof(session_id_n));
}

int main() {
    uint8_t setup_msg[COMMON_HEADER_SIZE + SETUP_REQUEST_MSG_SIZE];
    init_setup_request_msg(setup_msg, 10, 100);

    std::cout << "Message:";
    for (size_t i = 0; i < sizeof(setup_msg) / sizeof(setup_msg[0]); ++i) {
        std::cout << " " << std::hex << static_cast<int>(setup_msg[i]);
    }
    std::cout << std::endl;

    return 0;
}
