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
#include <stdlib.h>

namespace paddle2onnx {

//
// enum LogLevel {
//  DEBUG,
//  INFO,
//  WRAN,
//  ERROR,
//  FATAL
//};
//
// void Plog(LogLevel l, const char* format, va_list args_list) {
//  char* level = getenv("PLOG_LEVEL");
//  std::
//}
// template<typename... T>
// void Plog(LogLevel l, T... t) {
//  char* level = getenv("PLOG_LEVEL");
//  int default_level = 1;
//  if (nullptr != level) {
//
//  }
//  if constexpr (sizeof...(t) > 0) {
//    std::cerr << t << " ";
//  }
//  std::cerr << std::endl;
//}

void Assert(bool condition, const std::string& message) {
  if (!condition) {
    fprintf(stderr, "[ERROR] %s\n", message.c_str());
    std::abort();
  }
}
}  // namespace paddle2onnx