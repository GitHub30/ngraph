/*******************************************************************************
* Copyright 2017-2018 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#pragma once

#include "ngraph/codegen/code_writer.hpp"
#include "ngraph/node.hpp"
#include "ngraph/runtime/gpu/gpu_external_function.hpp"
#include "ngraph/runtime/gpu/gpu_tensor_view_wrapper.hpp"

namespace ngraph
{
    namespace op
    {
        namespace gpu
        {
            class RequiresEmitter : public Node
            {
            public:
                RequiresEmitter(std::string node_type, const NodeVector& args)
                    : Node(node_type, args)
                {
                }

                virtual ~RequiresEmitter() = default;
                virtual void emit(runtime::gpu::GPU_ExternalFunction* external_function,
                                  codegen::CodeWriter& writer,
                                  const std::vector<runtime::gpu::GPU_TensorViewWrapper>& args,
                                  const std::vector<runtime::gpu::GPU_TensorViewWrapper>& out) = 0;
            };
        }
    }
}