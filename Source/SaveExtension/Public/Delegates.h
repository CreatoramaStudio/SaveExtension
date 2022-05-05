// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "SlotInfo.h"
#include "Delegates.generated.h"


/** Called when game has been saved
 * @param SlotInfo the saved slot. Null if save failed
 */
DECLARE_DELEGATE_TwoParams(FOnGamePostSave, bool, USlotInfo*);

/** Called when game has been loaded
 * @param SlotInfo the loaded slot. Null if load failed
 */
DECLARE_DELEGATE_TwoParams(FOnGamePostLoad, bool, USlotInfo*);


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGamePreSaveMulticast, FName, SlotName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGamePreLoadMulticast, FName, SlotName);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGamePostSaveMulticast, bool, bSuccess, USlotInfo*, SlotInfo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGamePostLoadMulticast, bool, bSuccess, USlotInfo*, SlotInfo);


UENUM()
enum AAAAAA
{
	a
};