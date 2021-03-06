/*
 * MessageWorker.h
 *
 *  Created on: Aug 3, 2013
 *      Author: joe
 */

#ifndef MESSAGEWORKER_H_
#define MESSAGEWORKER_H_

#include "MessageStore.h"
#include <QString>

namespace mixpanel {
namespace details {

class MessageWorker{
public:
    MessageWorker();
    ~MessageWorker();
    void message(enum mixpanel_endpoint endpoint, const QString &message);
    void flush(int connect_timeout);
private:
    MessageWorker(const MessageWorker&);
    MessageWorker& operator=(const MessageWorker&);
    void flushEndpoint(enum mixpanel_endpoint endpoint, int connect_timeout);
    bool sendData(const char *endpoint_url, const QString &json, int connect_timeout);
    void prepareStore();
    MessageStore m_store;
    bool m_store_is_prepared;
    static const char* EVENTS_ENDPOINT_URL; // TODO move to endpoints.h
    static const char* PEOPLE_ENDPOINT_URL;
};

} /* namespace details */
} /* namespace mixpanel */
#endif /* MESSAGEWORKER_H_ */
