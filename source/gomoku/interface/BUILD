COPTS = [
    "-std=c++1z",
    "-Isource"
]

cc_library(
    name = "board_drawer",
    hdrs = ["board_drawer.h"],
    srcs = ["board_drawer.cc"],
    deps = [
        "//source/gomoku/domain:iboard",
        "//source/gomoku/domain:iboard_observer"],
    copts = COPTS
)

cc_library(
    name = "human_player_factory",
    hdrs = ["human_player_factory.h"],
    srcs = ["human_player_factory.cc"],
    deps = [
        ":human_player",
        "//source/gomoku/application:iplayer_factory"],
    copts = COPTS
)

cc_library(
    name = "human_player",
    hdrs = ["human_player.h"],
    srcs = ["human_player.cc"],
    deps = [
        "//source/gomoku/application:iplayer",
        "//source/gomoku/domain:iboard",
        "//source/gomoku/domain:stone"],
    copts = COPTS
)

cc_library(
    name = "ui_controller",
    hdrs = ["ui_controller.h"],
    srcs = ["ui_controller.cc"],
    deps = [
        ":board_drawer",
        ":human_player_factory",
        "//source/gomoku/application:artificial_intelligence_alpha_beta_player_factory",
        "//source/gomoku/application:artificial_intelligence_mini_max_player_factory",
        "//source/gomoku/application:game_controller_factory",
        "//source/gomoku/application:iplayer_factory",
        "//source/gomoku/domain:board"],
    copts = COPTS,
    visibility = ["//source/gomoku:__pkg__"]
)

cc_library(
    name = "interface",
    deps = [
        ":board_drawer",
        ":human_player_factory",
        ":human_player",
        ":ui_controller"]
)