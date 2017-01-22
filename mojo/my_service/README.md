Reference:
    https://chromium.googlesource.com/chromium/src/+/master/services/service_manager/README.md

Put below files at
    services/my_service.

Build command:
     ninja -C out/Default  services/my_service

Before build:
    diff --git a/chrome/browser/BUILD.gn b/chrome/browser/BUILD.gn
    index 0ff9de1..3c39ba0 100644
    --- a/chrome/browser/BUILD.gn
    +++ b/chrome/browser/BUILD.gn
    @@ -1549,6 +1549,7 @@ split_static_library("browser") {
         "//services/image_decoder/public/cpp",
         "//services/preferences/public/interfaces/",
         "//services/service_manager/public/cpp",
     +    "//services/my_service",
         "//services/shape_detection/public/interfaces",
         "//skia",
         "//sql",
