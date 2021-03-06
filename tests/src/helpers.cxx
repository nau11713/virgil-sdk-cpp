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

#include <string>
#include <vector>

#include <helpers.h>

#include <virgil/crypto/VirgilByteArray.h>
#include <virgil/crypto/foundation/VirgilBase64.h>

#include <virgil/sdk/models/IdentityModel.h>

using json = nlohmann::json;

using virgil::crypto::VirgilByteArray;
using virgil::crypto::foundation::VirgilBase64;

using virgil::sdk::models::PublicKeyModel;
using virgil::sdk::models::PrivateKeyModel;
using virgil::sdk::dto::ValidatedIdentity;
using virgil::sdk::dto::Identity;
using virgil::sdk::models::CardModel;
using virgil::sdk::models::IdentityModel;
using virgil::sdk::util::JsonKey;

const std::string kToken = "MIIB5wIBADCCAeAGCSqGSIb3DQEHA6CCAd"
                           "EwggHNAgECMYIBnjCCAZoCAQKgJgQkZTY1ZTljYmEtOTRlZS00ZjI3LWJi"
                           "ZTktNjI2MTg2ZDIyMDI4MBQGByqGSM49AgEGCSskAwMCCAEBDQSCAVUwgg"
                           "FRAgEAMIGbMBQGByqGSM49AgEGCSskAwMCCAEBDQOBggAEZ/IM0sOygWT9"
                           "h9jkugltok1LznnIlvtn4P9vyKB0L64m0huqQKUAV9CU9J1OhM0HntEUQd"
                           "aWP1kUtd8agB7AiXdygNjlE8mo9Eg9Y7qTHUaLpL0EeN4FKRJ5GoS+3f6X"
                           "Xd9z3wR1gySamIk2sDjM9GQr9PKN8dsN829QMxg2CywwGAYHKIGMcQIFAT"
                           "ANBglghkgBZQMEAgIFADBBMA0GCWCGSAFlAwQCAgUABDAKv/eUXcx5k7xr"
                           "dxTdrE9C7uybR4hHTgN7aOoRRpnOmrza1FNrb7jxxQOIkcao1EMwUTAdBg"
                           "lghkgBZQMEASoEEP+aUylfNTMITh5Ea/R2tcQEMDppR5iEvwmedff1jbgG"
                           "2zlE6HjIkar3wGs+MvxkX4gTaHK5ghBtC4pjF+BfDF00xzAmBgkqhkiG9w"
                           "0BBwEwGQYJYIZIAWUDBAEuBAx+e6AMDx4rHQfdEJRvy1T+48cDebA8ZPuW"
                           "U0UIZI4TjgQ6OTBNcHJnjyWnYumXv66tQsrqGaKr01w25g3hutVVZTOeq6"
                           "uMNQlC8OxQnUilmlPB84hqJRfk62TjJ5UGv6dyZF69UpuoTHN6AwYRqG4W"
                           "nQlCwACKlZhMWe3z1Oolkbui6DjiOBdjURIb1IUFblN88sEPG4gW4iOyir"
                           "DBGADE3/0EnkLzkiO99v2tJO9aLtwchmLY7Y3fXLKSU7UStm4hKQGRb4Yr"
                           "mfw4SG6McBEKkHFcjvnQ6Euu8QZEItAdI/tD1j8PkdNpmiqb3YxNgaYY43"
                           "AGnCD43vjJaOYd/oqV";

const std::string kPublicKeyBase64 = "LS0tLS1CRUdJTiBQVUJMSUMgS0VZLS0tLS0KTUl"
                                     "HYk1CUUdCeXFHU000OUFnRUdDU3NrQXdNQ0NBRUJEUU9CZ2dBRUNnL1dp"
                                     "czVtSWx6R3NOKzlFdEFrNEFMRApGRHJXRmVQc0RYRzR2SlI4TTV6MG5Qc"
                                     "XBSSldBQ05yU214WkxubWZhMTROK0MyY3IzbGdEbkVrMFNqMUlEeGttCm"
                                     "9yVWdzWGlMSSswZDFqeWpOcEVpSEQ0VUlQUHA3eVBZZlFUTXRtaFFCNkd"
                                     "IMnkxMGtaczhzSU40MythNGwzZkEKSUU3cnFWd0FXeFpGSG0rQ0JOST0K"
                                     "LS0tLS1FTkQgUFVCTElDIEtFWS0tLS0tCg==";

const std::string kHash = "9U7gpoLjX8MDcC66tF1TPkCSkoidlz6c86t54C"
                          "Bz7U/snzu1k0cDRLLO3+jZsKhzn7T16HWXdYE/KtIiSJ3wZw==";

const std::string kSignedDigest = "MIGZMA0GCWCGSAFlAwQCAgUABIGHMIGEAk"
                                  "AM29/DTFvTTDrab8hH7QDWGR6a5Igq+4Qw39fg3mLXtRWCv2YG2D/fsIn+Cc"
                                  "dtvsDNQT8aWjTBbbY+J0BZQV40AkBElUXjYBZINHiWsC/Q4yhgeRDjip9wGj"
                                  "pXqUH5FU38P8HqPIHCwJE/1ErhQzL6xdiRUWXhXR+1PhNJ1H5DZV7j";

const std::string kPrivateKey = "LS0tLS1CRUdJTiBFTkNSWVBURUQgUFJJVkFU"
                                "RSBLRVktLS0tLQpNSUlCS1RBMEJnb3Foa2lHOXcwQkRBRURNQ1lFSVBNdXA3"
                                "cVRoY0UyWFhNNk5hT0hQZjBsVFYxcE9ySEhTK09wCnZMeUdVbm9EQWdJZ0FB"
                                "U0I4QThNYUZMOWtQYXUyNzFSOTFucjkxemtPODRkZlBFV3h2a095M2xOUmZU"
                                "Y1FHSkkKNS9ibzdWZUt4am9PcTZQOE8yb084UHBEUVlpNHhUVHFNeDFWbWV1"
                                "VXpLRC9YT2ZvQUp5VW1lMVZpK1pnNzNiSAp4U0ZoLzQ5dWlrRURHQkhjUXpL"
                                "WVRCZmVGaHI2dG1VN2t6RWxucE0xdFFCSHRJN2NNcHNaNFBBWjVsNTRTUndw"
                                "CkdydXNKSW9Eam1mNnBIbHg5NmxYWk05bkpVczRwaDErdnNoUVJEbVYzd1k1"
                                "QVp5ZVlXYmp2UEZVTWUwMzRoWFEKeldzOHVGZFhCQm8vcnFMUTF5aUpCeU5p"
                                "cC9YTGU5M3R5MXpUZjVUTHg1S1VhQ3c4RW9rMUtjU1RmTkgvSGFUQQpwRzdy"
                                "YWpBdis2TCt5bmlnc3c9PQotLS0tLUVORCBFTkNSWVBURUQgUFJJVkFURSBL"
                                "RVktLS0tLQo=";

namespace virgil {
namespace test {

    json getJsonValidatedIdentity() {
        return json({{JsonKey::type, "email"},
                     {JsonKey::value, "alice.cpp.virgilsecurity@mailinator.com"},
                     {JsonKey::validationToken, kToken}});
    }

    ValidatedIdentity getValidatedIdentity() {
        return ValidatedIdentity(Identity("alice.cpp.virgilsecurity@mailinator.com", "email"), kToken);
    }

    json getJsonPublicKey() {
        return json({{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                     {JsonKey::id, "ce8abd8c-2ff3-4226-b793-26051aebbda7"},
                     {JsonKey::publicKey, kPublicKeyBase64}});
    }

    PublicKeyModel getPublicKey() {
        return PublicKeyModel("ce8abd8c-2ff3-4226-b793-26051aebbda7", "2016-02-08T14:33:08+0000",
                              VirgilBase64::decode(kPublicKeyBase64));
    }

    json getJsonCard() {
        return json({{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                     {JsonKey::data, {}},
                     {JsonKey::hash, kHash},
                     {JsonKey::id, "ea14f729-676f-47f1-8cc9-8adbf2a66a95"},
                     {JsonKey::authorizedBy, "com.mycompany.myapp"},

                     {JsonKey::identity,
                      {{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                       {JsonKey::id, "cc265059-6f0d-4bd0-945c-0c6e08eb9e0d"},
                       {JsonKey::type, "email"},
                       {JsonKey::value, "alice.cpp.virgilsecurity@mailinator.com"}}},

                     {JsonKey::publicKey,
                      {{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                       {JsonKey::id, "ce8abd8c-2ff3-4226-b793-26051aebbda7"},
                       {JsonKey::publicKey, kPublicKeyBase64}}}});
    }

    CardModel getCard() {
        return CardModel("ea14f729-676f-47f1-8cc9-8adbf2a66a95", "2016-02-08T14:33:08+0000", kHash,
                         IdentityModel(Identity("alice.cpp.virgilsecurity@mailinator.com", "email"),
                                       "cc265059-6f0d-4bd0-945c-0c6e08eb9e0d", "2016-02-08T14:33:08+0000"),
                         std::map<std::string, std::string>(), getPublicKey(), "com.mycompany.myapp");
    }

    json getJsonResponseCards() {
        return json({{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                     {JsonKey::id, "ce8abd8c-2ff3-4226-b793-26051aebbda7"},
                     {JsonKey::publicKey, kPublicKeyBase64},
                     {JsonKey::cards,
                      {{{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                        {JsonKey::data, {}},
                        {JsonKey::hash, kHash},
                        {JsonKey::id, "ea14f729-676f-47f1-8cc9-8adbf2a66a95"},
                        {JsonKey::authorizedBy, "com.mycompany.myapp"},

                        {JsonKey::identity,
                         {{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                          {JsonKey::id, "cc265059-6f0d-4bd0-945c-0c6e08eb9e0d"},
                          {JsonKey::type, "email"},
                          {JsonKey::value, "alice.cpp.virgilsecurity@mailinator.com"}}},
                        {JsonKey::publicKey,
                         {{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                          {JsonKey::id, "ce8abd8c-2ff3-4226-b793-26051aebbda7"},
                          {JsonKey::publicKey, kPublicKeyBase64}}}},

                       {{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                        {JsonKey::data, {{"google", "calendar"}, {"test", "draft1"}}},
                        {JsonKey::hash, kHash},
                        {JsonKey::id, "ea14f729-676f-47f1-8cc9-8adbf2a66a95"},
                        {JsonKey::authorizedBy, "com.mycompany.myapp"},

                        {JsonKey::identity,
                         {{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                          {JsonKey::id, "cc265059-6f0d-4bd0-945c-0c6e08eb9e0d"},
                          {JsonKey::type, "email"},
                          {JsonKey::value, "alice.cpp.virgilsecurity@mailinator.com"}}},
                        {JsonKey::publicKey,
                         {{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                          {JsonKey::id, "ce8abd8c-2ff3-4226-b793-26051aebbda7"},
                          {JsonKey::publicKey, kPublicKeyBase64}}}}}}});
    }

    json getJsonCards() {
        return json({{{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                      {JsonKey::data, {}},
                      {JsonKey::hash, kHash},
                      {JsonKey::id, "ea14f729-676f-47f1-8cc9-8adbf2a66a95"},
                      {JsonKey::authorizedBy, "com.mycompany.myapp"},

                      {JsonKey::identity,
                       {{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                        {JsonKey::id, "cc265059-6f0d-4bd0-945c-0c6e08eb9e0d"},
                        {JsonKey::type, "email"},
                        {JsonKey::value, "alice.cpp.virgilsecurity@mailinator.com"}}},
                      {JsonKey::publicKey,
                       {{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                        {JsonKey::id, "ce8abd8c-2ff3-4226-b793-26051aebbda7"},
                        {JsonKey::publicKey, kPublicKeyBase64}}}},

                     {{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                      {JsonKey::data, {{"google", "calendar"}, {"test", "draft1"}}},
                      {JsonKey::hash, kHash},
                      {JsonKey::id, "ea14f729-676f-47f1-8cc9-8adbf2a66a95"},
                      {JsonKey::authorizedBy, "com.mycompany.myapp"},

                      {JsonKey::identity,
                       {{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                        {JsonKey::id, "cc265059-6f0d-4bd0-945c-0c6e08eb9e0d"},
                        {JsonKey::type, "email"},
                        {JsonKey::value, "alice.cpp.virgilsecurity@mailinator.com"}}},
                      {JsonKey::publicKey,
                       {{JsonKey::createdAt, "2016-02-08T14:33:08+0000"},
                        {JsonKey::id, "ce8abd8c-2ff3-4226-b793-26051aebbda7"},
                        {JsonKey::publicKey, kPublicKeyBase64}}}}});
    }

    std::vector<CardModel> getCards() {
        std::vector<CardModel> cards;
        cards.push_back(getCard());

        CardModel card("ea14f729-676f-47f1-8cc9-8adbf2a66a95", "2016-02-08T14:33:08+0000", kHash,
                       IdentityModel(Identity("alice.cpp.virgilsecurity@mailinator.com", "email"),
                                     "cc265059-6f0d-4bd0-945c-0c6e08eb9e0d", "2016-02-08T14:33:08+0000"),
                       {{"google", "calendar"}, {"test", "draft1"}}, getPublicKey(), "com.mycompany.myapp");

        cards.push_back(card);
        return cards;
    }

    json getJsonPrivateKey() {
        return json({{JsonKey::privateKey, kPrivateKey}, {JsonKey::cardId, "cd4a35f7-6b15-4be4-b1d6-dea44a7af6df"}});
    }

    PrivateKeyModel getPrivateKey() {
        return PrivateKeyModel("cd4a35f7-6b15-4be4-b1d6-dea44a7af6df", VirgilBase64::decode(kPrivateKey));
    }
}
}
