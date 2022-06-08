// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "Customizations/SESubsystemClassFilterCustomization.h"
#include "PropertyHandle.h"

#define LOCTEXT_NAMESPACE "FSESubsystemClassFilterCustomization"


TSharedPtr<IPropertyHandle> FSESubsystemClassFilterCustomization::GetFilterHandle(TSharedRef<IPropertyHandle> StructPropertyHandle)
{
	return StructHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FSESubsystemClassFilter, ClassFilter));;
}

#undef LOCTEXT_NAMESPACE
