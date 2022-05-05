// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "LatentActions/SaveGameAction.h"
#include "SaveManager.h"
#include "SlotInfo.h"


FSaveGameAction::FSaveGameAction(USaveManager* Manager, FName SlotName, bool bOverrideIfNeeded, bool bScreenshot, const FScreenshotSize Size, ESaveGameResult& OutResult, const FLatentActionInfo& LatentInfo)
	: Result(OutResult)
	, ExecutionFunction(LatentInfo.ExecutionFunction)
	, OutputLink(LatentInfo.Linkage)
	, CallbackTarget(LatentInfo.CallbackTarget)
{
	const bool bStarted = Manager->SaveSlot(SlotName, bOverrideIfNeeded, bScreenshot, Size,FOnGamePostSave::CreateRaw(this, &FSaveGameAction::OnSaveFinished));

	if (!bStarted)
	{
		Result = ESaveGameResult::Failed;
	}
}

void FSaveGameAction::UpdateOperation(FLatentResponse& Response)
{
	Response.FinishAndTriggerIf(Result != ESaveGameResult::Saving, ExecutionFunction, OutputLink, CallbackTarget);
}

void FSaveGameAction::OnSaveFinished(bool bSuccess,USlotInfo* SavedSlot)
{
	Result = SavedSlot ? ESaveGameResult::Continue : ESaveGameResult::Failed;
}
