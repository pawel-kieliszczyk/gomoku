COPTS = [
    "-std=c++1z",
    "-Isource"
]

cc_library(
    name = "mocks",
    hdrs = [
        "application/game_finished_policy_factory_mock.h",
        "application/game_finished_policy_mock.h",
        "application/player_factory_mock.h",
        "application/player_mock.h",
        "domain/board_mock.h",
        "domain/board_observer_mock.h"],
    deps = ["@gtest//:gtest"],
    copts = COPTS,
    visibility = ["//tests/gomoku:__subpackages__"]
)
