// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "paddle2onnx/mapper/tensor/cumsum.h"

namespace paddle2onnx {
REGISTER_MAPPER(cumsum, CumsumMapper)

int32_t CumsumMapper::GetMinOpset(bool verbose) { return 11; }

void CumsumMapper::Opset11(OnnxHelper* helper) {
  auto op = parser_->GetOpDesc(block_idx_, op_idx_);
  std::vector<TensorInfo> input_info =
      parser_->GetOpInput(block_idx_, op_idx_, "X");
  std::vector<TensorInfo> output_info =
      parser_->GetOpOutput(block_idx_, op_idx_, "Out");
  std::string axis_node =
      helper->Constant({1}, GetOnnxDtype(P2ODataType::INT64), axis_);
  helper->MakeNode("CumSum", {input_info[0].name, axis_node},
                   {output_info[0].name});
}

}  // namespace paddle2onnx