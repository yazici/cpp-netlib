#ifndef BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_MODIFIERS_STATUS_MESSAGE_HPP_20100608
#define BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_MODIFIERS_STATUS_MESSAGE_HPP_20100608

// Copyright 2010 (c) Dean Michael Berris
// Copyright 2010 (c) Sinefunc, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/network/support/is_async.hpp>
#include <boost/thread/future.hpp>

namespace boost { namespace network { namespace http {

    template <class Tag>
    struct basic_response;

    namespace impl {

        template <class Tag, class T>
        void status_message(basic_response<Tag> & response, T const & value, mpl::false_ const &) {
            response << boost::network::http::status_message(value);
        }

        template <class Tag, class T>
        void status_message(basic_response<Tag> & response, boost::shared_future<T> future, mpl::true_ const &) {
            response.status_message() = future;
        }

    } // namespace impl

    template <class Tag, class T>
    void status_message(basic_response<Tag> & response, T const & value) {
        impl::status_message(response, value, is_async<Tag>());
    }

} // namespace http

} // namespace network

} // namespace boost

#endif // BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_MODIFIERS_STATUS_MESSAGE_HPP_20100608
