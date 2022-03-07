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

#pragma once
#include <string>
#include <vector>
#include "paddle2onnx/mapper/mapper.h"

namespace paddle2onnx {

class MatmulV2Mapper : public Mapper {
 public:
  MatmulV2Mapper(const PaddleParser& p, int64_t block_id, int64_t op_id)
      : Mapper(p, block_id, op_id) {
    auto op = parser_->GetOpDesc(block_idx_, op_idx_);
    parser_->GetOpAttr(op, "trans_x", &trans_x_);
    parser_->GetOpAttr(op, "trans_y", &trans_y_);
  }

  void Opset7(OnnxHelper* helper);

 private:
  std::string GetTrans(std::vector<TensorInfo>& input_info, OnnxHelper* helper);
  bool trans_x_ = false;
  bool trans_y_ = false;
};

}  // namespace paddle2onnx