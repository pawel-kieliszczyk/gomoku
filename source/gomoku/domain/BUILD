COPTS = [
    "-std=c++1z",
    "-Isource"
]

cc_library(
    name = "stone",
    hdrs = ["stone.h"],
    copts = COPTS,
    visibility = [
        "//source/gomoku/application:__subpackages__",
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "iboard_observer",
    hdrs = ["iboard_observer.h"],
    copts = COPTS,
    visibility = [
        "//source/gomoku/application:__subpackages__",
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "iboard",
    hdrs = ["iboard.h"],
    deps = [
        ":stone",
        "iboard_observer"],
    copts = COPTS,
    visibility = [
        "//source/gomoku/application:__subpackages__",
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "board",
    hdrs = ["board.h"],
    srcs = ["board.cc"],
    deps = [":iboard"],
    copts = COPTS,
    visibility = [
        "//source/gomoku/application:__subpackages__",
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "domain",
    deps = [
        ":stone",
        ":iboard_observer",
        ":board"]
)
