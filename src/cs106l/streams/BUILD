# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "ostreaingstream",
    srcs = ["ostringstream.cc"],
    copts = ["-std=c++17"],
)

cc_binary(
    name = "stringToInteger",
    srcs = ["stringToInteger.cc"],
    copts = ["-std=c++17"],
)

cc_library(
    name = "filestream",
    srcs = ["filestream.cc"],
    hdrs = ["filestream.h"],
    copts = ["-std=c++17"],
    deps = ["//src/sorts/sort_utils:sortutil"],
    visibility = ["//visibility:public"],
)
