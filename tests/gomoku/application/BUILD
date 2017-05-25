load("//:gomoku.bzl", "gomoku_tests_copts")

cc_library(
    name = "artificial_intelligence_adjacent_move_candidates_selector_test",
    srcs = ["artificial_intelligence/adjacent_move_candidates_selector_test.cc"],
    deps = [
        "//source/gomoku/application:artificial_intelligence_adjacent_move_candidates_selector",
        "//source/gomoku/domain:board",
        "@gtest//:gtest"],
    copts = gomoku_tests_copts()
)

cc_library(
    name = "game_controller_test",
    srcs = ["game_controller_test.cc"],
    deps = [
        "//source/gomoku/application:game_controller",
        "//tests/gomoku/mocks",
        "@gtest//:gtest"],
    copts = gomoku_tests_copts()
)

cc_library(
    name = "game_finished_when_five_in_row_policy_test",
    srcs = ["game_finished_when_five_in_row_policy_test.cc"],
    deps = [
        "//source/gomoku/application:game_finished_when_five_in_row_policy",
        "//source/gomoku/domain:board",
        "//source/gomoku/domain:stone",
        "@gtest//:gtest"],
    copts = gomoku_tests_copts()
)

cc_library(
    name = "application",
    deps = [
        ":artificial_intelligence_adjacent_move_candidates_selector_test",
        ":game_controller_test",
        ":game_finished_when_five_in_row_policy_test"],
    copts = gomoku_tests_copts(),
    visibility = ["//tests:__pkg__"]
)
