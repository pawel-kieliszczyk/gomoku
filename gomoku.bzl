def gomoku_copts():
  return ([
      "-std=c++1z",
      "-Isource"
  ])

def gomoku_tests_copts():
  return ([
      "-std=c++1z",
      "-Isource",
      "-Itests",
      "-Iexternal/gtest/include",
      "-Iexternal/gmock/include"
  ])
