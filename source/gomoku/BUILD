load("//source:gomoku.bzl", "gomoku_copts")

cc_library(
    name = "game",
    hdrs = ["game.h"],
    srcs = ["game.cc"],
    deps = ["//source/gomoku/interface:ui_controller"],
    copts = gomoku_copts(),
    visibility = ["//source:__pkg__"]
)

cc_library(
    name = "gomoku",
    deps = [":game"]
)
