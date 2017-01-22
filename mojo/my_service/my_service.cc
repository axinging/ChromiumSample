//#include "mojo/public/c/system/main.h"
//#include "services/service_manager/public/cpp/application_runner.h"
#include "mojo/public/cpp/bindings/binding.h"
#include "services/service_manager/public/cpp/service.h"
#include "services/tracing/public/cpp/provider.h"
#include "services/service_manager/public/c/main.h"
#include "services/service_manager/public/cpp/service_runner.h"
class MyService : public service_manager::Service {
 public:
  MyService() {}
  ~MyService() override {}

  // Overridden from service_manager::Service:
  void OnStart( ) override {
  }
  bool OnConnect(const service_manager::ServiceInfo& remote_info,
    service_manager::InterfaceRegistry* registry) override {
    return true;
  }
};

MojoResult ServiceMain(MojoHandle service_request_handle) {
  service_manager::ServiceRunner runner(new MyService);
  return runner.Run(service_request_handle);
}

