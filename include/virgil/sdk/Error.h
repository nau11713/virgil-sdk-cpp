/**
 * Copyright (C) 2015 Virgil Security Inc.
 *
 * Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     (1) Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *     (2) Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *
 *     (3) Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef VIRGIL_SDK_ERROR_H
#define VIRGIL_SDK_ERROR_H

#include <stdexcept>
#include <string>

#include <virgil/sdk/http/Response.h>

namespace virgil {
namespace sdk {
    /**
    * @brief Virgil Public Key service exception
    *
    * This class defines the type of objects thrown as exceptions
    *     to report errors that occurs during Virgil Keys Service communication
    */
    class Error final : public std::runtime_error {
    public:
        /**
         * @brief Define constant for undefined error code
         */
        static const unsigned int kUndefinedErrorCode = 0;
        /**
         * @brief Defines which action trigger an error
         */
        enum class Action {
            PUBLIC_KEY_GET_SIGN,   ///< GET  /public-key/{public-key-id} (signed)
            PUBLIC_KEY_GET_UNSIGN, ///< GET /public-key/{public-key-id} (unsigned)
            PUBLIC_KEY_REVOKE,     ///< DELETE /public-key{public-key-id} (unsigned)

            VIRGIL_CARD_CREATE,                 ///< POST /virgil-card
            VIRGIL_CARD_GET,                    ///< GET /virgil-card/{virgil-card-id}
            VIRGIL_CARD_SEARCH,                 ///< POST /virgil-card/actions/search
            VIRGIL_CARD_SEARCH_GLOBAL,          ///< POST /virgil-card/actions/search/app
            VIRGIL_CARD_SEARCH_GLOBAL_BY_EMAIL, ///< POST /virgil-card/actions/search/email
            VIRGIL_CARD_REVOKE,                 ///< DELETE /virgil-card/{virgil-card-id}

            PRIVATE_KEY_ADD, ///< POST /private-key
            PRIVATE_KEY_GET, ///< POST /private-key/actions/grab
            PRIVATE_KEY_DEL, ///< POST /private-key/actions/delete

            IDENTITY_VERIFY,  ///< POST /verify
            IDENTITY_CONFIRM, ///< POST /confirm
            IDENTITY_VALIDATE ///< POST /validate
        };
        /**
         * @brief Initialize exception
         * @param action - defines which action trigger an error
         * @param statusCode - HTTP response status code
         * @param errorCode - specific Virgil Public Key service error code
         */
        Error(Error::Action action, virgil::sdk::http::Response::StatusCode statusCode,
              unsigned int errorCode = kUndefinedErrorCode);

    private:
        /**
         * @brief Create formatted error message
         */
        std::string formatMessage(Error::Action action, virgil::sdk::http::Response::StatusCode statusCode,
                                  unsigned int errorCode) noexcept;
    };
}
}

#endif /* VIRGIL_SDK_ERROR_H */
