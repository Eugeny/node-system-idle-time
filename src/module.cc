#include "napi.h"
#include "idle.h"

Napi::Number GetIdleTime(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  uint32_t idle;
  idle = SystemIdleTime();
  return Napi::Number::New(env, idle);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "getIdleTime"),
              Napi::Function::New(env, GetIdleTime));
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
