load("//:gomoku.bzl", "gomoku_copts")

cc_library(
    name = "main",
    srcs = ["main.cc"],
    deps = ["//source/gomoku:game"],
    copts = gomoku_copts()
)

cc_binary(
    name = "app",
    deps = [":main"]
)
