COPTS = [
    "-std=c++1z",
    "-Isource"
]

cc_library(
    name = "main",
    srcs = ["main.cc"],
    deps = ["//source/gomoku:game"],
    copts = COPTS
)

cc_binary(
    name = "app",
    deps = [":main"]
)
