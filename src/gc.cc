#define BUILDING_NODE_EXTENSION

#include <node.h>
#include <v8.h>

namespace {
    v8::Handle<v8::Value> Collect(const v8::Arguments& args){
        v8::HandleScope scope;
        while(!v8::V8::IdleNotification()){ };
        return scope.Close(v8::Undefined());
    }

    void Init(v8::Handle<v8::Object> target){
        NODE_SET_METHOD(target, "collect", Collect);
    }
}

NODE_MODULE(gc, Init)
