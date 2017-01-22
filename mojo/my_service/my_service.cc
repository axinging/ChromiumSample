#include "services/service_manager/public/cpp/service.h"
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
  return service_manager::ServiceRunner(new MyService).Run(
      service_request_handle);
}

