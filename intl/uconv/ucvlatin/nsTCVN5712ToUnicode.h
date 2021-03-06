/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef nsTCVN5712ToUnicode_h___
#define nsTCVN5712ToUnicode_h___

#include "nsISupports.h"

/**
 * A character set converter from TCVN5712 to Unicode.
 *
 * @created         4/26/1999
 * @author  Frank Tang [ftang]
 */
nsresult
nsTCVN5712ToUnicodeConstructor(nsISupports *aOuter, REFNSIID aIID,
                               void **aResult);

#endif /* nsTCVN5712ToUnicode_h___ */
