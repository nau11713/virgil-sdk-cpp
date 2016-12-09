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

#ifndef VIRGIL_SDK_VIRGILSDKEXCEPTION_H
#define VIRGIL_SDK_VIRGILSDKEXCEPTION_H

#include <string>
#include <stdexcept>
#include <system_error>

namespace virgil {
    namespace sdk {

        /**
         * @brief This only exception that sdk can produce.
         *
         * To determine the real exception reason, error codes in conjuction with error category are used.
         * Error codes can be found in the enumeration @link VirgilSDKError @endlink.
         *
         * @ingroup Error
         */
        class VirgilSdkException : public std::exception {
        public:
            /**
             * @brief Initialize Exception with specific error code and correspond error category.
             * @param ev Error value (code).
             * @param ecat Error category.
             */
            VirgilSdkException(int ev, const std::error_category& ecat);

            /**
             * @brief Initialize Exception with specific error code, correspond error category, and error description.
             * @param ev Error value (code).
             * @param ecat Error category.
             * @param what Additional error description.
             */
            VirgilSdkException(int ev, const std::error_category& ecat, const std::string& what);

            /**
             * @brief Initialize Exception with specific error code, correspond error category, and error description.
             * @param ev Error value (code).
             * @param ecat Error category.
             * @param what Additional error description.
             */
            VirgilSdkException(int ev, const std::error_category& ecat, const char* what);

            /**
             * Get string identifying exception.
             *
             * @return null terminated character sequence that may be used to identify the exception.
             */
            const char* what() const noexcept override;
        private:
            std::error_condition condition_;
            std::string what_;
        };

        /**
         * @brief Unwind information about nested excpetions.
         * @param exception - Top level exception.
         * @param level - initial identation level.
         * @return Formatted message of top level exception and all nested exceptions.
         */
        std::string backtrace_exception(const std::exception& exception, size_t level = 0);
    }
}

//! @cond Doxygen_S
// TODO: Remove this when Clang compiler will be used from the Android NDK, possible in the release r13.
#if defined(ANDROID) && defined(__GCC_ATOMIC_INT_LOCK_FREE) && __GCC_ATOMIC_INT_LOCK_FREE < 2
namespace std {
template<typename T>
void throw_with_nested(const T& ex) {
    throw ex;
}
template<typename T>
void rethrow_if_nested(const T&) {
    // Do nothing
}
}
#endif
//! @endconduppress

#endif //VIRGIL_SDK_VIRGILSDKEXCEPTION_H
