# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_library(
    name = "insertionsort",
    srcs = ["insertionsort.cc"],
    hdrs = ["insertionsort.h"],
    deps = ["//src/sorts/selection_sort:selectionsort"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "insertionsortbinary",
    srcs = ["insertionsort_algobook.cc"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "insertionsort_vector",
    srcs = ["insertionsort_vector.cc"],
)