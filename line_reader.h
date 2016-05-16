/*
 * Copyright (C) 2015, The Android Open Source Project
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
 */

#ifndef HIDL_LINE_READER_H_
#define HIDL_LINE_READER_H_

#include <memory>
#include <string>

#include <android-base/macros.h>

namespace android {
namespace hidl {

class LineReader {
 public:
  LineReader() = default;
  virtual ~LineReader() = default;
  virtual bool ReadLine(std::string* Line) = 0;

  static std::unique_ptr<LineReader> ReadFromFile(
      const std::string& file_path);
  static std::unique_ptr<LineReader> ReadFromMemory(
      const std::string& contents);

 private:
  DISALLOW_COPY_AND_ASSIGN(LineReader);
};  // class LineReader

}  // namespace android
}  // namespace hidl

#endif // HIDL_LINE_READER_H_
