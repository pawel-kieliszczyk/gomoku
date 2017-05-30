load("//:gomoku.bzl", "gomoku_tests_copts")

COPTS = [
    "-std=c++1z",
    "-Isource",
    "-Itests",
    "-Iexternal/gtest/include",
    "-Iexternal/gmock/include"
]

cc_library(
    name = "board_test",
    srcs = ["board_test.cc"],
    deps = [
        "//source/gomoku/domain:board",
        "//source/gomoku/domain:stone",
        "//tests/gomoku/mocks",
        "@gtest//:gtest"],
    copts = gomoku_tests_copts()
)

cc_library(
    name = "domain",
    deps = [":board_test"],
    copts = gomoku_tests_copts(),
    visibility = ["//tests:__pkg__"]
)
