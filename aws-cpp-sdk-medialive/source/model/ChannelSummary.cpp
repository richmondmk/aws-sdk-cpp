﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/medialive/model/ChannelSummary.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace MediaLive
{
namespace Model
{

ChannelSummary::ChannelSummary() : 
    m_arnHasBeenSet(false),
    m_destinationsHasBeenSet(false),
    m_egressEndpointsHasBeenSet(false),
    m_idHasBeenSet(false),
    m_inputAttachmentsHasBeenSet(false),
    m_nameHasBeenSet(false),
    m_pipelinesRunningCount(0),
    m_pipelinesRunningCountHasBeenSet(false),
    m_roleArnHasBeenSet(false),
    m_state(ChannelState::NOT_SET),
    m_stateHasBeenSet(false)
{
}

ChannelSummary::ChannelSummary(const JsonValue& jsonValue) : 
    m_arnHasBeenSet(false),
    m_destinationsHasBeenSet(false),
    m_egressEndpointsHasBeenSet(false),
    m_idHasBeenSet(false),
    m_inputAttachmentsHasBeenSet(false),
    m_nameHasBeenSet(false),
    m_pipelinesRunningCount(0),
    m_pipelinesRunningCountHasBeenSet(false),
    m_roleArnHasBeenSet(false),
    m_state(ChannelState::NOT_SET),
    m_stateHasBeenSet(false)
{
  *this = jsonValue;
}

ChannelSummary& ChannelSummary::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("arn"))
  {
    m_arn = jsonValue.GetString("arn");

    m_arnHasBeenSet = true;
  }

  if(jsonValue.ValueExists("destinations"))
  {
    Array<JsonValue> destinationsJsonList = jsonValue.GetArray("destinations");
    for(unsigned destinationsIndex = 0; destinationsIndex < destinationsJsonList.GetLength(); ++destinationsIndex)
    {
      m_destinations.push_back(destinationsJsonList[destinationsIndex].AsObject());
    }
    m_destinationsHasBeenSet = true;
  }

  if(jsonValue.ValueExists("egressEndpoints"))
  {
    Array<JsonValue> egressEndpointsJsonList = jsonValue.GetArray("egressEndpoints");
    for(unsigned egressEndpointsIndex = 0; egressEndpointsIndex < egressEndpointsJsonList.GetLength(); ++egressEndpointsIndex)
    {
      m_egressEndpoints.push_back(egressEndpointsJsonList[egressEndpointsIndex].AsObject());
    }
    m_egressEndpointsHasBeenSet = true;
  }

  if(jsonValue.ValueExists("id"))
  {
    m_id = jsonValue.GetString("id");

    m_idHasBeenSet = true;
  }

  if(jsonValue.ValueExists("inputAttachments"))
  {
    Array<JsonValue> inputAttachmentsJsonList = jsonValue.GetArray("inputAttachments");
    for(unsigned inputAttachmentsIndex = 0; inputAttachmentsIndex < inputAttachmentsJsonList.GetLength(); ++inputAttachmentsIndex)
    {
      m_inputAttachments.push_back(inputAttachmentsJsonList[inputAttachmentsIndex].AsObject());
    }
    m_inputAttachmentsHasBeenSet = true;
  }

  if(jsonValue.ValueExists("name"))
  {
    m_name = jsonValue.GetString("name");

    m_nameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("pipelinesRunningCount"))
  {
    m_pipelinesRunningCount = jsonValue.GetInteger("pipelinesRunningCount");

    m_pipelinesRunningCountHasBeenSet = true;
  }

  if(jsonValue.ValueExists("roleArn"))
  {
    m_roleArn = jsonValue.GetString("roleArn");

    m_roleArnHasBeenSet = true;
  }

  if(jsonValue.ValueExists("state"))
  {
    m_state = ChannelStateMapper::GetChannelStateForName(jsonValue.GetString("state"));

    m_stateHasBeenSet = true;
  }

  return *this;
}

JsonValue ChannelSummary::Jsonize() const
{
  JsonValue payload;

  if(m_arnHasBeenSet)
  {
   payload.WithString("arn", m_arn);

  }

  if(m_destinationsHasBeenSet)
  {
   Array<JsonValue> destinationsJsonList(m_destinations.size());
   for(unsigned destinationsIndex = 0; destinationsIndex < destinationsJsonList.GetLength(); ++destinationsIndex)
   {
     destinationsJsonList[destinationsIndex].AsObject(m_destinations[destinationsIndex].Jsonize());
   }
   payload.WithArray("destinations", std::move(destinationsJsonList));

  }

  if(m_egressEndpointsHasBeenSet)
  {
   Array<JsonValue> egressEndpointsJsonList(m_egressEndpoints.size());
   for(unsigned egressEndpointsIndex = 0; egressEndpointsIndex < egressEndpointsJsonList.GetLength(); ++egressEndpointsIndex)
   {
     egressEndpointsJsonList[egressEndpointsIndex].AsObject(m_egressEndpoints[egressEndpointsIndex].Jsonize());
   }
   payload.WithArray("egressEndpoints", std::move(egressEndpointsJsonList));

  }

  if(m_idHasBeenSet)
  {
   payload.WithString("id", m_id);

  }

  if(m_inputAttachmentsHasBeenSet)
  {
   Array<JsonValue> inputAttachmentsJsonList(m_inputAttachments.size());
   for(unsigned inputAttachmentsIndex = 0; inputAttachmentsIndex < inputAttachmentsJsonList.GetLength(); ++inputAttachmentsIndex)
   {
     inputAttachmentsJsonList[inputAttachmentsIndex].AsObject(m_inputAttachments[inputAttachmentsIndex].Jsonize());
   }
   payload.WithArray("inputAttachments", std::move(inputAttachmentsJsonList));

  }

  if(m_nameHasBeenSet)
  {
   payload.WithString("name", m_name);

  }

  if(m_pipelinesRunningCountHasBeenSet)
  {
   payload.WithInteger("pipelinesRunningCount", m_pipelinesRunningCount);

  }

  if(m_roleArnHasBeenSet)
  {
   payload.WithString("roleArn", m_roleArn);

  }

  if(m_stateHasBeenSet)
  {
   payload.WithString("state", ChannelStateMapper::GetNameForChannelState(m_state));
  }

  return payload;
}

} // namespace Model
} // namespace MediaLive
} // namespace Aws
