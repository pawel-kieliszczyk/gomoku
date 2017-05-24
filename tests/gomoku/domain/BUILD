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
    copts = COPTS
)

cc_library(
    name = "domain",
    deps = [":board_test"],
    copts = COPTS,
    visibility = ["//tests:__pkg__"]
)
