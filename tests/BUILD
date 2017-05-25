load("//:gomoku.bzl", "gomoku_tests_copts")

cc_library(
    name = "main",
    srcs = ["main.cc"],
    deps = ["@gtest//:gtest"],
    copts = gomoku_tests_copts()
)

cc_test(
    name = "tests",
    deps = [
        ":main",
        "//tests/gomoku/application",
        "//tests/gomoku/domain"],
    size = "small",
    copts = gomoku_tests_copts()
)
