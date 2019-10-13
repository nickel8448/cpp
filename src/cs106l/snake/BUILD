cc_binary(
    name = "game",
    srcs = [
    	"game.cc"
    ],
    deps = [":gameutils"],
)

cc_library(
    name = "gameutils",
    srcs = [
        "gameplay.cc",
        "gamemechanics.cc"
    ],
    hdrs = [
        "gameplay.h",
        "gamemechanics.h",
    ],
    deps = ["//src/cs106l/streams:filestream"],
)
