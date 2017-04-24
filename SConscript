Import('env')
local_env = env.Clone()


local_env.AppendUnique(CPPPATH = ['libraries/googletest/gtest-1.8.0/include'])
local_env.AppendUnique(CPPPATH = ['libraries/googlemock/gmock-1.8.0/include'])
local_env.AppendUnique(CPPPATH = ['../source'])

local_env.AppendUnique(LIBPATH = ['libraries/googletest', 'libraries/googlemock'])

local_env.AppendUnique(LIBS = ['gtest', 'gmock', 'pthread'])


enable_gcov = ARGUMENTS.get('enable_gcov', False)
if enable_gcov:
	local_env.AppendUnique(CXXFLAGS = ['-fprofile-arcs', '-ftest-coverage'])
	local_env.AppendUnique(LINKFLAGS = '-fprofile-arcs')


source_files = ['tests/main.cpp']


target = 'test'

program = local_env.Program(target, source_files)
Default(program)
env.Alias(target, '.')


local_env.Depends(program, env.Alias('gtest'))
local_env.Depends(program, env.Alias('gmock'))