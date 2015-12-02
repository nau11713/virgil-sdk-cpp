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

#ifndef VIRGIL_SDK_PRIVATE_KEYS_MODEL_PRIVATE_KEY_H
#define VIRGIL_SDK_PRIVATE_KEYS_MODEL_PRIVATE_KEY_H

#include <string>
#include <vector>


namespace virgil { namespace sdk { namespace privatekeys { namespace model {
    /**
     * @brief Data object represent "Virgil Private Key" entity.
     */
    class PrivateKey {
    public:
        /**
         * @brief Set public key UUID, that is related to correspond private key.
         */
        PrivateKey& publicKeyId (const std::string& publicKeyId);
        /**
         * @brief Get public key UUID, that is related to correspond private key.
         */
        std::string publicKeyId () const;
        /**
         * @brief Set private key.
         */
        PrivateKey& key(const std::vector<unsigned char> key);
        /**
         * @brief Get private key.
         */
        std::vector<unsigned char> key() const;
    private:
        std::string publicKeyId_;
        std::vector<unsigned char> key_;
    };
}}}}

#endif /* VIRGIL_SDK_PRIVATE_KEYS_MODEL_PRIVATE_KEY_H */