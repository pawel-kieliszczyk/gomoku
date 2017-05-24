COPTS = [
    "-std=c++1z",
    "-Isource",
    "-Itests",
    "-Iexternal/gtest/include",
    "-Iexternal/gmock/include"
]

cc_library(
    name = "artificial_intelligence_adjacent_move_candidates_selector_test",
    srcs = ["artificial_intelligence/adjacent_move_candidates_selector_test.cc"],
    deps = [
        "//source/gomoku/application:artificial_intelligence_adjacent_move_candidates_selector",
        "//source/gomoku/domain:board",
        "@gtest//:gtest"],
    copts = COPTS
)

cc_library(
    name = "game_controller_test",
    srcs = ["game_controller_test.cc"],
    deps = [
        "//source/gomoku/application:game_controller",
        "//tests/gomoku/mocks",
        "@gtest//:gtest"],
    copts = COPTS
)

cc_library(
    name = "game_finished_when_five_in_row_policy_test",
    srcs = ["game_finished_when_five_in_row_policy_test.cc"],
    deps = [
        "//source/gomoku/application:game_finished_when_five_in_row_policy",
        "//source/gomoku/domain:board",
        "//source/gomoku/domain:stone",
        "@gtest//:gtest"],
    copts = COPTS
)

cc_library(
    name = "application",
    deps = [
        ":artificial_intelligence_adjacent_move_candidates_selector_test",
        ":game_controller_test",
        ":game_finished_when_five_in_row_policy_test"],
    copts = COPTS,
    visibility = ["//tests:__pkg__"]
)
