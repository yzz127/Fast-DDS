/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima RTPS is licensed to you under the terms described in the
 * EPROSIMARTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file ThreadSend.h
 *   ThreadSend class.
 *  Created on: Feb 25, 2014
 *      Author: Gonzalo Rodriguez Canosa
 *      email:  gonzalorodriguez@eprosima.com
 *      		grcanosa@gmail.com
 */
#include <boost/asio.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/udp.hpp>


#include "rtps_all.h"

#ifndef THREADSEND_H_
#define THREADSEND_H_

namespace eprosima {
namespace rtps {

/**
 * Class ThreadSend, used to manage the send operation. In future version it will contain the grouping
 *  logic for merge different CDRMessages into a single RTPSMessages (HB piggybacking, for example).
 * @ingroup COMMONMODULE
 */
class ThreadSend {
public:
	ThreadSend();
	virtual ~ThreadSend();
	Locator_t sendLocator;
	boost::mutex sendMutex;
	boost::asio::io_service sendService;
	boost::asio::ip::udp::socket send_socket;
	/**
	 * Send a CDR message syncrhonously. No waiting is required.
	 * @param msg Pointer to the message.
	 * @param loc Locator where to send the message.
	 */
	void sendSync(CDRMessage_t* msg,Locator_t loc);

	/**
	 * Initialize the sending socket.
	 * @param loc Locator of hte address from where to start the sending socket.
	 * @return True if correct
	 */
	bool initSend(Locator_t loc);

};

} /* namespace rtps */
} /* namespace eprosima */

#endif /* THREADSEND_H_ */
