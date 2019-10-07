# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "insertionSortBinary",
    srcs = ["insertionsort.cc", "insertionsort.h"],
    deps = ["//src/sorts/selection_sort:selectionsort"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "insertionsort",
    srcs = ["insertionsort.cc"],
    hdrs = ["insertionsort.h"],
    deps = ["//src/sorts/selection_sort:selectionsort"],
    visibility = ["//visibility:public"],
)