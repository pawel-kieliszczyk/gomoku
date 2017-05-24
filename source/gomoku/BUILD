COPTS = [
    "-std=c++1z",
    "-Isource"
]

cc_library(
    name = "game",
    hdrs = ["game.h"],
    srcs = ["game.cc"],
    deps = ["//source/gomoku/interface:ui_controller"],
    copts = COPTS,
    visibility = ["//source:__pkg__"]
)

cc_library(
    name = "gomoku",
    deps = [":game"]
)
