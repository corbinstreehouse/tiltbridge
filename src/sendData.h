//
// Created by John Beeler on 2/18/19.
//

#ifndef TILTBRIDGE_SENDDATA_H
#define TILTBRIDGE_SENDDATA_H

#include <cstdint>


// USE_SECURE_GSCRIPTS is disabled due to memory requirements. For more info, see
// https://github.com/thorrak/tiltbridge/issues/2
// #define USE_SECURE_GSCRIPTS 1  // Allow for direct posting to Google Scripts via HTTPS



#define GSCRIPTS_DELAY (15 * 60 * 1000)  // 15 minute delay between pushes to Google Sheets
#define BREWERS_FRIEND_DELAY (15 * 60 * 1000)  // 15 minute delay between pushes to Brewer's Friend & Brewfather



class dataSendHandler {

public:
    dataSendHandler();
    void init();
    void process();


private:
    uint64_t send_to_fermentrack_at;
    uint64_t send_to_brewers_friend_at;
    uint64_t send_to_google_at;
    uint64_t send_to_brewfather_at;

#ifdef USE_SECURE_GSCRIPTS
    // This is necessary for HTTPS support (which is useless until ESP32 bluetooth support is improved)
    void setClock();
    void prep_send_secure();
#endif

    void send_to_fermentrack();
    void send_to_google();
    void send_to_brewers_friend();
    bool send_to_url(const char *url, const char *apiKey);

};

extern dataSendHandler data_sender;
extern const char *g_brewfatherKey;


#endif //TILTBRIDGE_SENDDATA_H
