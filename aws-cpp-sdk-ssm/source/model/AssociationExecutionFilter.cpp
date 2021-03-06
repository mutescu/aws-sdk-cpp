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

#include <aws/ssm/model/AssociationExecutionFilter.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace SSM
{
namespace Model
{

AssociationExecutionFilter::AssociationExecutionFilter() : 
    m_key(AssociationExecutionFilterKey::NOT_SET),
    m_keyHasBeenSet(false),
    m_valueHasBeenSet(false),
    m_type(AssociationFilterOperatorType::NOT_SET),
    m_typeHasBeenSet(false)
{
}

AssociationExecutionFilter::AssociationExecutionFilter(const JsonValue& jsonValue) : 
    m_key(AssociationExecutionFilterKey::NOT_SET),
    m_keyHasBeenSet(false),
    m_valueHasBeenSet(false),
    m_type(AssociationFilterOperatorType::NOT_SET),
    m_typeHasBeenSet(false)
{
  *this = jsonValue;
}

AssociationExecutionFilter& AssociationExecutionFilter::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("Key"))
  {
    m_key = AssociationExecutionFilterKeyMapper::GetAssociationExecutionFilterKeyForName(jsonValue.GetString("Key"));

    m_keyHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Value"))
  {
    m_value = jsonValue.GetString("Value");

    m_valueHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Type"))
  {
    m_type = AssociationFilterOperatorTypeMapper::GetAssociationFilterOperatorTypeForName(jsonValue.GetString("Type"));

    m_typeHasBeenSet = true;
  }

  return *this;
}

JsonValue AssociationExecutionFilter::Jsonize() const
{
  JsonValue payload;

  if(m_keyHasBeenSet)
  {
   payload.WithString("Key", AssociationExecutionFilterKeyMapper::GetNameForAssociationExecutionFilterKey(m_key));
  }

  if(m_valueHasBeenSet)
  {
   payload.WithString("Value", m_value);

  }

  if(m_typeHasBeenSet)
  {
   payload.WithString("Type", AssociationFilterOperatorTypeMapper::GetNameForAssociationFilterOperatorType(m_type));
  }

  return payload;
}

} // namespace Model
} // namespace SSM
} // namespace Aws
