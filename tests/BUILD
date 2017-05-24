COPTS = [
    "-std=c++1z",
    "-Isource",
    "-Itests",
    "-Iexternal/gtest/include",
    "-Iexternal/gmock/include"
]

cc_library(
    name = "main",
    srcs = ["main.cc"],
    deps = ["@gtest//:gtest"],
    copts = COPTS
)

cc_test(
    name = "tests",
    deps = [
        ":main",
        "//tests/gomoku/application",
        "//tests/gomoku/domain"],
    copts = COPTS
)
