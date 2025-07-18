/** @file

Copyright (c) 2024, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "PiSmmCpuCommon.h"

BOOLEAN  mIsRestrictedMemoryAccess            = TRUE;
BOOLEAN  mIsRestrictedMemoryAccessInitialized = FALSE;

/**
  Return whether access to non-SMRAM is restricted.

  @retval TRUE  Access to non-SMRAM is restricted.
  @retval FALSE Access to non-SMRAM is not restricted.
**/
BOOLEAN
IsRestrictedMemoryAccess (
  VOID
  )
{
  if (!mIsRestrictedMemoryAccessInitialized) {
    mIsRestrictedMemoryAccess            = PcdGetBool (PcdCpuSmmRestrictedMemoryAccess);
    mIsRestrictedMemoryAccessInitialized = TRUE;
  }

  return mIsRestrictedMemoryAccess;
}
