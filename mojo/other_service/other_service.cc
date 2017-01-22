#include "mojo/public/cpp/bindings/binding_set.h"
#include "services/service_manager/public/c/main.h"
#include "services/service_manager/public/cpp/service.h"
#include "services/service_manager/public/cpp/service_runner.h"
#include "services/service_manager/public/cpp/interface_factory.h"
#include "services/other_service/public/interfaces/some_interface.mojom.h"
#include "services/service_manager/public/cpp/interface_registry.h"

class OtherService : public service_manager::Service,
                public service_manager::InterfaceFactory<mojom::SomeInterface>,
                public mojom::SomeInterface {
 public:
  // Overridden from service_manager::Service:
  void OnStart() override {
  }

  // Overridden from service_manager::Service:
  bool OnConnect(const service_manager::ServiceInfo& remote_info,
                 service_manager::InterfaceRegistry* registry) override {
    registry->AddInterface<mojom::SomeInterface>(this);
    return true;
  }

  // Overridden from service_manager::InterfaceFactory<mojom::SomeInterface>:
  void Create(const service_manager::Identity& remote_identity,
              mojom::SomeInterfaceRequest request) override {
    bindings_.AddBinding(this, std::move(request));
  }

  // Overridden from mojom::SomeInterface:
  void Foo() override { /* .. */ }

  mojo::BindingSet<mojom::SomeInterface> bindings_;
};

MojoResult ServiceMain(MojoHandle service_request_handle) { 
  return service_manager::ServiceRunner(new OtherService).Run(
      service_request_handle);
}
