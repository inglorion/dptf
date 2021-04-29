/******************************************************************************
** Copyright (c) 2013-2021 Intel Corporation All Rights Reserved
**
** Licensed under the Apache License, Version 2.0 (the "License"); you may not
** use this file except in compliance with the License.
**
** You may obtain a copy of the License at
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
** WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**
** See the License for the specific language governing permissions and
** limitations under the License.
**
******************************************************************************/

#include "ParticipantSetSpecificInfoFactory.h"
#include "ParticipantSetSpecificInfo_000.h"
#include "ParticipantSetSpecificInfo_001.h"

ControlBase* ParticipantSetSpecificInfoFactory::make(
	UIntN participantIndex,
	UIntN domainIndex,
	UIntN version,
	std::shared_ptr<ParticipantServicesInterface> participantServicesInterface)
{
	switch (version)
	{
	case 0:
		return new ParticipantSetSpecificInfo_000(participantIndex, domainIndex, participantServicesInterface);
		break;
	case 1:
		return new ParticipantSetSpecificInfo_001(participantIndex, domainIndex, participantServicesInterface);
		break;
	default:
		std::stringstream message;
		message << "Received request for ParticipantSetSpecificInfo version that isn't defined: " << version;
		throw dptf_exception(message.str());
		break;
	}
}
