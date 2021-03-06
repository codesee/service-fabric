// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#include "stdafx.h"
#include "ManagedPerformanceCounterSetWrapper.h"

using namespace Common;


ManagedPerformanceCounterSetWrapper::ManagedPerformanceCounterSetWrapper(std::shared_ptr<PerformanceCounterSet> perfCounterSet) :
perfCounterSet_(perfCounterSet)
{
}

ManagedPerformanceCounterSetWrapper::~ManagedPerformanceCounterSetWrapper(void)
{
}
