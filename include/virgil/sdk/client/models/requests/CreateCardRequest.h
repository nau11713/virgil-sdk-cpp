/**
 * Copyright (C) 2016 Virgil Security Inc.
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


#ifndef VIRGIL_SDK_CREATECARDREQUEST_H
#define VIRGIL_SDK_CREATECARDREQUEST_H

#include <virgil/sdk/client/models/requests/SignableRequest.h>
#include <virgil/sdk/client/models/snapshotmodels/CreateCardSnapshotModel.h>

#include <string>
#include <unordered_map>

namespace virgil {
namespace sdk {
namespace client {
namespace models {
    namespace requests {
        class CreateCardRequest final : public SignableRequest<snapshotmodels::CreateCardSnapshotModel, CreateCardRequest> {
        public:
            static CreateCardRequest createRequest(const std::string &identity,
                                                   const std::string &identityType,
                                                   const VirgilByteArray &publicKeyData,
                                                   const std::unordered_map<std::string, std::string> &data = {},
                                                   const std::string& device = "",
                                                   const std::string& deviceName = "");

            CreateCardRequest(const VirgilByteArray &snapshot,
                              const std::unordered_map<std::string, VirgilByteArray> &signatures = {});

        private:
            CreateCardRequest(const std::string &identity,
                              const std::string &identityType,
                              const VirgilByteArray &publicKeyData,
                              const std::unordered_map<std::string, std::string> &data,
                              CardScope scope,
                              const std::unordered_map<std::string, std::string> &info);

            CreateCardRequest(const snapshotmodels::CreateCardSnapshotModel &model,
                              const std::unordered_map<std::string, VirgilByteArray> &signatures = {});
        };
    }
}
}
}
}

#endif //VIRGIL_SDK_CREATECARDREQUEST_H
