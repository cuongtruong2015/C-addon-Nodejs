#include <node.h>
#include <iostream>
#include <stdlib.h>

using namespace v8;
using namespace std;
using namespace node;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(
      String::NewFromUtf8(
      isolate, "world").ToLocalChecked());
}
void Method2(const FunctionCallbackInfo<Value>&args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(
      isolate, "world2").ToLocalChecked());
}

void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "hello", Method);
  NODE_SET_METHOD(exports, "hello2",  Method2);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
