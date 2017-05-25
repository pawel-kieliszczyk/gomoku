load("//:gomoku.bzl", "gomoku_copts")

cc_library(
    name = "artificial_intelligence_adjacent_move_candidates_selector",
    hdrs = ["artificial_intelligence/adjacent_move_candidates_selector.h"],
    srcs = ["artificial_intelligence/adjacent_move_candidates_selector.cc"],
    deps = [":artificial_intelligence_imove_candidates_selector"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "artificial_intelligence_alpha_beta_player_factory",
    hdrs = ["artificial_intelligence/alpha_beta_player_factory.h"],
    srcs = ["artificial_intelligence/alpha_beta_player_factory.cc"],
    deps = [
        ":iplayer_factory",
        ":artificial_intelligence_adjacent_move_candidates_selector",
        ":artificial_intelligence_alpha_beta_player"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "artificial_intelligence_alpha_beta_player",
    hdrs = ["artificial_intelligence/alpha_beta_player.h"],
    srcs = ["artificial_intelligence/alpha_beta_player.cc"],
    deps = [
        ":iplayer",
        ":artificial_intelligence_board_evaluator",
        ":artificial_intelligence_board_with_undo",
        ":artificial_intelligence_imove_candidates_selector",
        "//source/gomoku/domain:board",
        "//source/gomoku/domain:stone"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "artificial_intelligence_board_evaluator",
    hdrs = ["artificial_intelligence/board_evaluator.h"],
    srcs = ["artificial_intelligence/board_evaluator.cc"],
    deps = [
        "//source/gomoku/domain:iboard",
        "//source/gomoku/domain:stone"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "artificial_intelligence_board_with_undo",
    hdrs = ["artificial_intelligence/board_with_undo.h"],
    srcs = ["artificial_intelligence/board_with_undo.cc"],
    deps = [
        "//source/gomoku/domain:iboard",
        "//source/gomoku/domain:board"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "artificial_intelligence_imove_candidates_selector",
    hdrs = ["artificial_intelligence/imove_candidates_selector.h"],
    deps = ["//source/gomoku/domain:iboard"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "artificial_intelligence_mini_max_player_factory",
    hdrs = ["artificial_intelligence/mini_max_player_factory.h"],
    srcs = ["artificial_intelligence/mini_max_player_factory.cc"],
    deps = [
        ":iplayer_factory",
        ":artificial_intelligence_adjacent_move_candidates_selector",
        ":artificial_intelligence_mini_max_player"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "artificial_intelligence_mini_max_player",
    hdrs = ["artificial_intelligence/mini_max_player.h"],
    srcs = ["artificial_intelligence/mini_max_player.cc"],
    deps = [
        ":iplayer",
        ":artificial_intelligence_board_evaluator",
        ":artificial_intelligence_board_with_undo",
        ":artificial_intelligence_imove_candidates_selector",
        "//source/gomoku/domain:board",
        "//source/gomoku/domain:stone"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "game_controller_factory",
    hdrs = ["game_controller_factory.h"],
    srcs = ["game_controller_factory.cc"],
    deps = [
        ":game_controller",
        ":iplayer_factory",
        ":game_finished_when_five_in_row_policy_factory",
        "//source/gomoku/domain:iboard"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "game_controller",
    hdrs = ["game_controller.h"],
    srcs = ["game_controller.cc"],
    deps = [
        ":iplayer",
        ":iplayer_factory",
        ":igame_finished_policy",
        ":igame_finished_policy_factory",
        "//source/gomoku/domain:iboard"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "game_finished_when_five_in_row_policy_factory",
    hdrs = ["game_finished_when_five_in_row_policy_factory.h"],
    srcs = ["game_finished_when_five_in_row_policy_factory.cc"],
    deps = [
        ":igame_finished_policy_factory",
        ":game_finished_when_five_in_row_policy"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "game_finished_when_five_in_row_policy",
    hdrs = ["game_finished_when_five_in_row_policy.h"],
    srcs = ["game_finished_when_five_in_row_policy.cc"],
    deps = [
        ":igame_finished_policy",
        "//source/gomoku/domain:iboard",
        "//source/gomoku/domain:iboard_observer",
        "//source/gomoku/domain:stone"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "igame_finished_policy_factory",
    hdrs = ["igame_finished_policy_factory.h"],
    deps = [
        ":igame_finished_policy",
        "//source/gomoku/domain:iboard"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "igame_finished_policy",
    hdrs = ["igame_finished_policy.h"],
    deps = ["//source/gomoku/domain:iboard"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "iplayer_factory",
    hdrs = ["iplayer_factory.h"],
    deps = [
        ":iplayer",
        "//source/gomoku/domain:iboard",
        "//source/gomoku/domain:stone"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "iplayer",
    hdrs = ["iplayer.h"],
    copts = gomoku_copts(),
    visibility = [
        "//source/gomoku/interface:__subpackages__",
        "//tests/gomoku:__subpackages__"]
)

cc_library(
    name = "application",
    deps = [
        ":artificial_intelligence_adjacent_move_candidates_selector",
        ":artificial_intelligence_alpha_beta_player_factory",
        ":artificial_intelligence_alpha_beta_player",
        ":artificial_intelligence_board_evaluator",
        ":artificial_intelligence_board_with_undo",
        ":artificial_intelligence_imove_candidates_selector",
        ":artificial_intelligence_mini_max_player_factory",
        ":artificial_intelligence_mini_max_player",
        ":game_controller_factory",
        ":game_controller",
        ":game_finished_when_five_in_row_policy_factory",
        ":game_finished_when_five_in_row_policy",
        ":igame_finished_policy_factory",
        ":igame_finished_policy",
        ":iplayer_factory",
        ":iplayer"]
)
