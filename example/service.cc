// Copyright 2010 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you
// may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
// implied. See the License for the specific language governing
// permissions and limitations under the License.

#include "../protobuf_for_node.h"
#include "service.pb.h"
#include "v8.h"

extern "C" void init(v8::Handle<v8::Object> target) {
  // look ma - no v8 api
  protobuf_for_node::ExportService(target, "service", new (class : public service::Service {
    virtual void Len(google::protobuf::RpcController* controller,
		     const service::Request* request,
		     service::Response* response,
		     google::protobuf::Closure* done) {
      response->set_len(request->msg().length());
      // just to prove we're not blocking
      sleep(1);
    }
  }));
}
