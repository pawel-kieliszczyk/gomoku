Import('env')
local_env = env.Clone()


local_env.AppendUnique(CPPPATH = ['Libraries/googletest/gtest-1.8.0/include'])
local_env.AppendUnique(CPPPATH = ['Libraries/googlemock/gmock-1.8.0/include'])
local_env.AppendUnique(CPPPATH = ['../Include'])
local_env.AppendUnique(CPPPATH = ['Tests'])

local_env.AppendUnique(LIBPATH = ['Libraries/googletest', 'Libraries/googlemock'])

local_env.AppendUnique(LIBS = ['gtest', 'gmock', 'pthread'])


enable_gcov = ARGUMENTS.get('enable_gcov', False)
if enable_gcov:
	local_env.AppendUnique(CXXFLAGS = ['-fprofile-arcs', '-ftest-coverage'])
	local_env.AppendUnique(LINKFLAGS = '-fprofile-arcs')


source_files = ['Tests/main.cpp']

source_files += ['Source/Application/GameController.cpp']
source_files += ['Source/Domain/Board.cpp']

source_files += ['Tests/Application/GameControllerTester.cpp']
source_files += ['Tests/Domain/BoardTester.cpp']


target = 'test'

program = local_env.Program(target, source_files)
Default(program)
env.Alias(target, '.')


local_env.Depends(program, env.Alias('gtest'))
local_env.Depends(program, env.Alias('gmock'))