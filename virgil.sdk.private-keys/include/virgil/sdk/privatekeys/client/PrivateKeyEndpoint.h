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

#ifndef VIRGIL_SDK_PRIVATE_KEYS_PRIVATE_KEY_ENDPOINT_H
#define VIRGIL_SDK_PRIVATE_KEYS_PRIVATE_KEY_ENDPOINT_H

#include <memory>

#include <virgil/sdk/privatekeys/client/KeysClientConnection.h>
#include <virgil/sdk/privatekeys/client/PrivateKeyEndpointBase.h>


namespace virgil { namespace sdk { namespace privatekeys { namespace client {
    /**
    * @brief Default implenetation of class PrivateKeyEndpointBase.
    */
    class PrivateKeyEndpoint final : public PrivateKeyEndpointBase {
    public:
        /**
         * @brief Initialize with HTTP layer connection.
         * @param connection - HTTP layer connection.
         * @throw std::logic_error - if connection is invalid.
         */
        explicit PrivateKeyEndpoint(const std::shared_ptr<KeysClientConnection>& connection);
        /**
         * @name Base class implementation
         */
        //@{
        void add(const virgil::sdk::privatekeys::client::CredentialsExt& credentials,
                const std::string& pass) const override;
        virgil::sdk::privatekeys::model::PrivateKey get(const std::string& publicKeyId,
                const std::string& pass) const override;
        void del(const CredentialsExt &credentials) const override;
        //@}
    private:
        std::shared_ptr<KeysClientConnection> connection_;
    };
}}}}

#endif /* VIRGIL_SDK_PRIVATE_KEYS_PRIVATE_KEY_ENDPOINT_H */